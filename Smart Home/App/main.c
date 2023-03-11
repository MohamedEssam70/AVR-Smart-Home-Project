/*
 * STD_Types.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Mohamed Essam
 */

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Utils.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EEPROM/EEPROM_int.h"
#include "../MCAL/GLOBAL_INT/GLOBAL_INT_int.h"
#include "../MCAL/GPT/GPT_int.h"
#include "../MCAL/SPI/SPI_int.h"
#include "../HAL/LED/LED_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "main.h"
#include "ownerUser.h"
#include "tenantUser.h"
#include "MACROS_SPI.h"
#include "helper.h"

/**************** GLOBAL Variables ****************/
u8 u8_loginMode = NO_LOGIN;	//create a global variable carry the value that refer to the login state

void main(void) {
/**************** LOCAL VARIABLE ****************/
	u8 Local_u8passCounter;	//create a counter to limit the password character as setting in the main_prv.h file
//	u8 Local_au8password[PASS_SIZE] = {NO_VALUE, NO_VALUE, NO_VALUE, NO_VALUE};	//create an array to store the password in it
	u8 Local_au8ownerPassword[PASS_SIZE] = {NO_VALUE, NO_VALUE, NO_VALUE, NO_VALUE};	//create an array to store the owner password in it
	u8 Local_au8tenantPassword[PASS_SIZE] = {NO_VALUE, NO_VALUE, NO_VALUE, NO_VALUE};	//create an array to store the tenant password in it
	u8 Local_u8keyPressed = WAITING_PRESS_KEY;	//create a variable to store the pressed key
	u8 Local_u8inputPassword;	//create a variable to refer to the input password right or wrong
	u8 Local_au8CustomCharacterSmile[8] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 };

/**************** INITIALIZE ****************/
	SPI_vidSPIInitMaster(); //initialize this MC as a master node
	LCD_vidInit();	//initialize the LCD connected to master MC
	GPT_vidConfigure(GPT_u8_TIMER0);


/**************** START SCREEN ****************/
	DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN6, DIO_u8_HIGH);
	LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_OFF);
	LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN3);	//move the Cursor to the middle of first row in the LCD screen
	LCD_enuSendString("SMART HMOME");	//print in the LCD screen
	LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN5);	//move the Cursor to the middle of second row in the LCD screen
	LCD_enuSendString("SYSTEM");	//print in the LCD screen
	_delay_ms(100);	//stand the system up to display start message for 100 ms
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);	//clear the screen
	LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN0);	//move the Cursor to the first location in the LCD screen
	_delay_ms(100);
/**************** SETTING THE USERS PASSWORD (FIRST TIME RUN THE PROGRAM) ****************/
	/*check if the program already run before and set a password for each user (OWNER/TENANT)
	 * if the application run for the first time and the user complete the registration process execute this code
	 * if user complete the registration process the value stored in EEPROM address that refer to the password status must be 0xFF
	 * if the two user set its password, pass this block of code
	 * */
	if((EEPROM_u8readByte(EEPROM_u16_OWNER_PASSWORD_STATUS) != PASSWORD_SET) || (EEPROM_u8readByte(EEPROM_u16_TENANT_PASSWORD_STATUS) != PASSWORD_SET)){ //start registration
		LCD_enuSendString("Registration ...");	//print screen title
		LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);	//move the cursor to the second line
		_delay_ms(50); //hold the system for a few millisecond

		///SETTING THE PASSWORDS///
		/*setting the owner password*/
		LCD_enuSendString("Owner Pass: ");	//ask the user to enter OWNER password
		LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_ON);
		for(Local_u8passCounter = ZERO; Local_u8passCounter < PASS_SIZE; Local_u8passCounter++){	//loop to get the whole password from the user
			Local_u8keyPressed = WAITING_PRESS_KEY;	//assign the initial value refer to the application waiting the user to enter a value
			while(Local_u8keyPressed == WAITING_PRESS_KEY){	//loop until user enter a new value.... the break condition is the stored value in (Local_u8keyPressed) not equal the initial value
				KEYPAD_vidGetPressedKey(&Local_u8keyPressed);	//store the value of the pressed key in (Local_u8keyPressed)
			}
			LCD_enuSendCharacter(Local_u8keyPressed);	//print the value of the pressed key on the LCD screen
//			Local_au8ownerPassword[Local_u8passCounter] = Local_u8keyPressed;	//store the value of the pressed key in array at index according the iterator value
			_delay_ms(PASSWORD_CHAR_APPEAR_TIME);	//system stand up for the defined time period in millisecond to preview the character before replace by password symbol
			LCD_enuGoTo(LCD_u8_ROW1, (CURSOR_POSITION_SET_PASSWORD + Local_u8passCounter));	//move the cursor to the previous location to write an asterisk symbol instead of the printed character
			LCD_enuSendCharacter(PASSWORD_ASTERISK);	//print asterisk symbol
//			EEPROM_vidwriteByte((EEPROM_u16_OWNER_PASSWORD + Local_u8passCounter), Local_u8keyPressed); //store the password char in a EEPROM address
			eeprom_write_byte((EEPROM_u16_OWNER_PASSWORD + Local_u8passCounter), Local_u8keyPressed);
		}//end of setting the owner password
//		EEPROM_vidwriteByte(EEPROM_u16_OWNER_PASSWORD_STATUS, PASSWORD_SET);	//flag to completely save the owner password in EEPROM
		eeprom_write_byte(EEPROM_u16_OWNER_PASSWORD_STATUS, PASSWORD_SET);
		_delay_ms(20);	//waiting a few milliseconds before continue
		LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_OFF);
		LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);	//move the cursor to the first position in the second row
		LCD_enuSendString(" Password Saved ");	//inform the user that the owner password has been saved to the system
		_delay_ms(30);	//waiting a few milliseconds before continue
		/*setting the tenant password*/
		Local_u8passCounter = ZERO;	//reset password character counter to count entered values
		LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);	//move the cursor to the first position in the second row
		LCD_enuSendString("Tenant Pass:    ");	//ask the user to enter the tenant password
		LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_ON);
		for(Local_u8passCounter = ZERO; Local_u8passCounter < PASS_SIZE; Local_u8passCounter++){	//loop to get the whole password from the user
			Local_u8keyPressed = WAITING_PRESS_KEY;	//assign the initial value refer to the application waiting the user to enter a value
			while(Local_u8keyPressed == WAITING_PRESS_KEY){	//loop until user enter a new value.... the break condition is the stored value in (Local_u8keyPressed) not equal the initial value
				KEYPAD_vidGetPressedKey(&Local_u8keyPressed);	//store the value of the pressed key in (Local_u8keyPressed)
			}
			LCD_enuSendCharacter(Local_u8keyPressed);	//print the value of the pressed key on the LCD screen
//			Local_au8tenantPassword[Local_u8passCounter] = Local_u8keyPressed;	//store the value of the pressed key in array at index according the iterator value
			_delay_ms(PASSWORD_CHAR_APPEAR_TIME);	//system stand up for the defined time period in millisecond to preview the character before replace by password symbol
			LCD_enuGoTo(LCD_u8_ROW1, (CURSOR_POSITION_SET_PASSWORD + Local_u8passCounter));	//Move the cursor to the previous location to write an asterisk symbol instead of the printed character
			LCD_enuSendCharacter(PASSWORD_ASTERISK);	//print asterisk symbol
//			EEPROM_vidwriteByte((EEPROM_u16_TENANT_PASSWORD + Local_u8passCounter), Local_u8keyPressed); //store the password char in a EEPROM address
			eeprom_write_byte((EEPROM_u16_TENANT_PASSWORD + Local_u8passCounter), Local_u8keyPressed);
		}//end of setting the tenant password
//		EEPROM_vidwriteByte(EEPROM_u16_TENANT_PASSWORD_STATUS, PASSWORD_SET);	//flag to completely save the tenant password in EEPROM
		eeprom_write_byte(EEPROM_u16_TENANT_PASSWORD_STATUS, PASSWORD_SET);
		_delay_ms(20);	//waiting a few milliseconds before continue
		LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_OFF);
		LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);	//move the cursor to the first position in the second row
		LCD_enuSendString(" Password Saved ");	//inform the user that the owner password has been saved to the system
		_delay_ms(30);	//waiting a few milliseconds before continue
		LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);	//clear the screen
		LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN0);	//move the Cursor to the middle of first row in the LCD screen
		LCD_enuSendString("Registrtion Done");	//print message inform user that the registration is done
		LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN3);	//move the Cursor to the middle of second row in the LCD screen
		LCD_enuSendString("Thank You");	//print thanks message
		LCD_enuSendCustomCharacter(Local_au8CustomCharacterSmile, LCD_u8_CGRAM_BLOCK_1, LCD_u8_ROW1, LCD_u8_COLUMN13);	//print a smile icon stored in LCD_CGRAM block 1
		_delay_ms(50);	//system stand up for a few milliseconds before clear the screen
		LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);	//clear the LCD screen
	}//end of registration process


/*			SUPER LOOP (START OF THE PERIODIC CODE)			*/
	while(TRUE){
/**************** LOGIN MENU ****************/
		/*login menu:
		 * user select its role (OWNER/TENANT)
		 * user enter the password
		 * if the password that user enter agree with that stored in EEPROM address user can pass to the system
		 * if the password that user enter disagree with that stored in EEPROM address user can try again (infinity iterations)
		 * */
		while(u8_loginMode == NO_LOGIN){
			LCD_enuSendString("LOGIN MODE:");
			LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);	//move the cursor to the first location at the second row
			LCD_enuSendString("1-OWNER 2-TENANT");	//options available to the user: "1" to login as the owner, "2" to login as a tenant
			Local_u8keyPressed = WAITING_PRESS_KEY;	//assign the initial value refer to the application waiting the user to enter a value
			while(Local_u8keyPressed == WAITING_PRESS_KEY){	//loop until user enter a new value.... the break condition is the stored value in (Local_u8keyPressed) not equal the initial value
				KEYPAD_vidGetPressedKey(&Local_u8keyPressed);	//store the value of the pressed key in (Local_u8keyPressed)
				switch(Local_u8keyPressed){
					case OWNER_OPTION:
						do{
							LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);	//clear the LCD screen
							LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN0);	//move the cursor to the first location at the first row
							LCD_enuSendString("ENTER OWNER");
							LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);	//move the cursor to the first location at the second row
							LCD_enuSendString("PASSWORD: ");
							LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_ON);
							Local_u8inputPassword = PASSWORD_TRUE;	//initialize the value of password user enter as true
							for(Local_u8passCounter = ZERO; Local_u8passCounter < PASS_SIZE; Local_u8passCounter++){ //loop until user enter the password
								Local_u8keyPressed = WAITING_PRESS_KEY;	//assign the initial value refer to the application waiting the user to enter a value
								while(Local_u8keyPressed == WAITING_PRESS_KEY){	//loop until user enter a new value.... the break condition is the stored value in (Local_u8keyPressed) not equal the initial value
									KEYPAD_vidGetPressedKey(&Local_u8keyPressed);	//store the value of the pressed key in (Local_u8keyPressed)
								}
								LCD_enuSendCharacter(Local_u8keyPressed);	//print the value of the pressed key on the LCD screen
								_delay_ms(PASSWORD_CHAR_APPEAR_TIME);	//system stand up for the defined time period in millisecond to preview the character before replace by password symbol
								LCD_enuGoTo(LCD_u8_ROW1, (CURSOR_POSITION_ENTER_PASSWORD + Local_u8passCounter));	//Move the cursor to the previous location to write an asterisk symbol instead of the printed character
								LCD_enuSendCharacter(PASSWORD_ASTERISK);	//print asterisk symbol
								/*checking the password char user enter if it agree with the value of corresponding address in EEPROM*/
//								if(Local_u8keyPressed != Local_au8ownerPassword[Local_u8passCounter]){
//									Local_u8inputPassword = PASSWORD_WRONG;	//assign the input password as wrong password
//								} else{/*....*/}
								if(Local_u8keyPressed != EEPROM_u8readByte(EEPROM_u16_OWNER_PASSWORD + Local_u8passCounter)){
									Local_u8inputPassword = PASSWORD_WRONG;	//assign the input password as wrong password
								} else{/*....*/}
							}//end of writing the password
							LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_OFF);
						} while(Local_u8inputPassword == PASSWORD_WRONG);
						u8_loginMode = OWNER_LOGIN;
						break;
					case TENANT_OPTION:
						do{
							LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);	//clear the LCD screen
							LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN0);	//move the cursor to the first location at the first row
							LCD_enuSendString("ENTER TENANT");
							LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);	//move the cursor to the first location at the second row
							LCD_enuSendString("PASSWORD: ");
							LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_ON);
							Local_u8inputPassword = PASSWORD_TRUE;	//initialize the value of password user enter as true
							for(Local_u8passCounter = ZERO; Local_u8passCounter < PASS_SIZE; Local_u8passCounter++){ //loop until user enter the password
								Local_u8keyPressed = WAITING_PRESS_KEY;	//assign the initial value refer to the application waiting the user to enter a value
								while(Local_u8keyPressed == WAITING_PRESS_KEY){	//loop until user enter a new value.... the break condition is the stored value in (Local_u8keyPressed) not equal the initial value
									KEYPAD_vidGetPressedKey(&Local_u8keyPressed);	//store the value of the pressed key in (Local_u8keyPressed)
								}
								LCD_enuSendCharacter(Local_u8keyPressed);	//print the value of the pressed key on the LCD screen
								_delay_ms(PASSWORD_CHAR_APPEAR_TIME);	//system stand up for the defined time period in millisecond to preview the character before replace by password symbol
								LCD_enuGoTo(LCD_u8_ROW1, (CURSOR_POSITION_ENTER_PASSWORD + Local_u8passCounter));	//Move the cursor to the previous location to write an asterisk symbol instead of the printed character
								LCD_enuSendCharacter(PASSWORD_ASTERISK);	//print asterisk symbol
								/*checking the password char user enter if it agree with the value of corresponding address in EEPROM*/
//								if(Local_u8keyPressed != Local_au8tenantPassword[Local_u8passCounter]){
//									Local_u8inputPassword = PASSWORD_WRONG;	//assign the input password as wrong password
//								} else{/*....*/}
								if(Local_u8keyPressed != EEPROM_u8readByte(EEPROM_u16_OWNER_PASSWORD + Local_u8passCounter)){
									Local_u8inputPassword = PASSWORD_WRONG;	//assign the input password as wrong password
								} else{/*....*/}
							}//end of writing the password
							LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_OFF);
						} while(Local_u8inputPassword == PASSWORD_WRONG);
						u8_loginMode = TENANT_LOGIN;
						break;
					default:
						Local_u8keyPressed = WAITING_PRESS_KEY;
						break;
				}//end of switch case
			}//end of getting pressed key #while loop#
		}//end of select login mode #while loop#


/**************** USER ACTIONS ****************/
		/*owner:
		 * welcome screen appear
		 * OWNER_vidUserOptions() include the options owner have to do
		 * */
		if(u8_loginMode == OWNER_LOGIN){
			HELPER_vidSucessLogin();
			OWNER_vidUserOptions();
		}
		if(u8_loginMode == TENANT_LOGIN){
			HELPER_vidSucessLogin();
			TENANT_vidRoomControl();
		}
		_delay_ms(1000);
	}//end of the while true code
}



