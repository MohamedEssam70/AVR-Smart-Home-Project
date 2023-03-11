/*
 * owner.c
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohamed Essam
 */





#include <util/delay.h>
#include <avr/interrupt.h>
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
#include "ownerUser.h"
#include "MACROS_SPI.h"


/**************** GLOBAL VARIABLE ****************/
u8 u8SPIrequest = DONT_CARE;	//create a variable to get the data send by SPI from the slave
u8 u8keyPressed = WAITING_PRESS_KEY;	//create a variable to store the pressed key
u8 u8MinuteEnd = TRUE;	//create a variable to check if the timer count a full 60 seconds
u8 u8PartyDuration;	//create a variable carry the party mode time in minutes



/* Name: OWNER_vidUserOptions
 * Description: main function of the owner
 * Arguments: void
 * Return:	void
 */
void OWNER_vidUserOptions(void){
	/* local variable */
	u8 Local_u8selectedOption = NO_OPTION;	//create a variable carry the value that refer to the selected option .. initialize on option selected
	u8 Local_u8maxTemperature;		//create a variable carry the max temperature entered by user
	u8 Local_u8minTemperature;		//create a variable carry the min temperature entered by user
	u8 Local_au8CustomCharacterParty[BLOCK_SIZE] = {0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18}; //party pattern --> CGRAM_BLOCK_2
	u8 Local_au8CustomCharacterTemperature[BLOCK_SIZE] = {0x04, 0x0A, 0x0A, 0x0E, 0x0E, 0x1F, 0x1F, 0x0E}; //temperature pattern --> CGRAM_BLOCK_3
	/* select option from list */
	while(Local_u8selectedOption == NO_OPTION){	//still display option list until user
	//	SPI_vidTransceive(ACTIVE_TEMP_SYSTEM);		//Activate the temperature control system
		LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);		//clear LCD screen
		LCD_enuSendString("1.Modes  2.Rooms");		//print the available options
		LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);
		LCD_enuSendString("3.Garage  4.Temp");
		u8keyPressed = WAITING_PRESS_KEY;	//assign the initial value refer to the application waiting the user to enter a value
		while(u8keyPressed == WAITING_PRESS_KEY){//loop until user select option
			KEYPAD_vidGetPressedKey(&u8keyPressed);	//get the pressed key value
			switch(u8keyPressed){	//compare the value of pressed key with the available options
			/* first option: change operating mode
			 * have internal options --> normal mode, party mode
			 * */
				case CHANGE_MODE:
					/* let user select one from the available modes */
					LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);		//clear LCD screen
					LCD_enuSendString("1.Normal Mode");		//print the available options
					LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);
					LCD_enuSendString("2.Party Mode");
					u8keyPressed = WAITING_PRESS_KEY;	//assign the initial value refer to the application waiting the user to enter a value
					while(u8keyPressed == WAITING_PRESS_KEY){//loop until user select option
						KEYPAD_vidGetPressedKey(&u8keyPressed);	//get the pressed key value
						switch(u8keyPressed){
						/* first mode: normal mode is the stander mode system operating with ..
							so pass this iteration and return to the main menu again */
							case NORMAL_MODE:
								continue;
						/* second mode: party mode activate for specific minutes user set it by the keypad
							can't cancel this mode after active it and LCD show a timer count the
							activate time then return to the normal after it*/
							case PARTY_MODE:
								LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);		//clear LCD screen
								LCD_enuSendString("Set Reservation Time (M)");
								LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);
								LCD_enuSendString("Time (Min): ");
								LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_ON);  //appear the LCD cursor
								u8keyPressed = WAITING_PRESS_KEY;		//assign the initial value .. no pressed key
								while((u8keyPressed == WAITING_PRESS_KEY) || (u8keyPressed == HASH_SIGN) || (u8keyPressed == ASTERISK_SIGN) || (u8keyPressed == ZERO_ASCII)){
									//can't enter #, *, or 0 ... must be a number 1 --> 9
									KEYPAD_vidGetPressedKey(&u8keyPressed);
								}
								u8PartyDuration = u8keyPressed - ASCII_DEFERANT;	//store the time in its specific variable
								LCD_enuSendCharacter(u8keyPressed);	//show the pressed key value on the LCD
								_delay_ms(30);	//stand up the system for a few ms
								LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_OFF);  //disappear the LCD cursor
								LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);	//clear the LCD screen
								LCD_enuSendCustomCharacter(Local_au8CustomCharacterParty, LCD_u8_CGRAM_BLOCK_2, LCD_u8_ROW0, LCD_u8_COLUMN8);
								LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN3); //move the cursor to the middle of second row
								LCD_enuSendString("PARTY START");	//print start party on the screen
								_delay_ms(100);	//stand the system up to display start party message for 100 ms
								SPI_vidTransceive(PARTY_MODE_ACTIVE); //send to the slave a flag to party mode activate
								OWNER_vidcounterDown(u8PartyDuration);
								_delay_ms(100);
								SPI_vidTransceive(PARTY_TIME_OUT); //send party time out flag
					//			LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);	//clear the LCD screen
					//			LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN5); //move the cursor to the middle of first row
					//			LCD_enuSendString(" PARTY TIME OUT ");
					//			LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN3); //move the cursor to the middle of second row
					//			LCD_enuSendString("");
								_delay_ms(100);
								LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);	//clear the LCD screen
								LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN5); //move the cursor to the middle of first row
								LCD_enuSendString("RETURN");
								LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN2); //move the cursor to the middle of second row
								LCD_enuSendString("NORMAL MODE");
								_delay_ms(100);
								break;
						/* in case user press on a key have a value not refer to available option
						   assign the initial value in the pressed key variable to act like no pressed key case */
							default:
								u8keyPressed = WAITING_PRESS_KEY;
								break;
						}//end of #switch case
					}//end of #while loop
					break;
			/* second option: control rooms
			 * have internal options --> master room, tenant room
			 * use external function for each internal option
			 * */
				case ROOMS_CONTROL:
					/* let user select one room */
					LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);		//clear LCD screen
					LCD_enuSendString("1.Master");		//print the available options
					LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);
					LCD_enuSendString("2.Tenant  0:BACK");
					u8keyPressed = WAITING_PRESS_KEY;		//assign the initial value .. no pressed key
					while(u8keyPressed == WAITING_PRESS_KEY){//loop until user select option
						KEYPAD_vidGetPressedKey(&u8keyPressed);	 //get the pressed key value
						switch(u8keyPressed){
						/* if user select the master room .. call the concerned function */
							case MASTER_ROOM:
								OWNER_vidMasterRoom();
								break;
						/* if user select the tenant room .. call the concerned function */
							case TENENT_ROOM:
								OWNER_vidTenantRoom();
								break;
						/* back option to pass this iteration and return to the main menu again */
							case BACK:
								continue;
						/* in case user press on a key have a value not refer to available option
					   assign the initial value in the pressed key variable to act like no pressed key case */
							default:
								u8keyPressed = WAITING_PRESS_KEY;
								break;
						}//end of #switch case
					}//end of #while loop
					break;
			/* third option: control garage
			 * use external function to drive this module
			 * */
				case GARAGE_CONTROL:
					/* call the garage module concerned function  */
					OWNER_vidGarageControl();
					break;
			/* fourth option: control temperature
			 * use external function to set the temperature
			 * */
				case TEMPERATURE_CONTROL:
					LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
					LCD_enuSendCustomCharacter(Local_au8CustomCharacterTemperature, LCD_u8_CGRAM_BLOCK_3, LCD_u8_ROW0, LCD_u8_COLUMN0);
					LCD_enuSendString(" Temperature");
					LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN2);
					LCD_enuSendString("Setting");
					_delay_ms(150);
					LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
					LCD_enuSendString("Set Min Temp:__");
					LCD_enuSendCharacter(DEGREE_SIGN);
					/* get the minimum temperature from the user by calling the concerned function */
					Local_u8minTemperature = OWNER_u8getTemperature(MIN_TEMP);
					SPI_vidTransceive(SEND_TEMP_MIN);
					_delay_ms(100);
					SPI_vidTransceive(Local_u8minTemperature + ASCII_DEFERANT);
					_delay_ms(100);
					LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);
					LCD_enuSendString("Set Max Temp:__");
					LCD_enuSendCharacter(DEGREE_SIGN);
					Local_u8maxTemperature = OWNER_u8getTemperature(MAX_TEMP);
					SPI_vidTransceive(SEND_TEP_MAX);
					_delay_ms(100);
					SPI_vidTransceive(Local_u8maxTemperature + ASCII_DEFERANT);
					_delay_ms(100);
					break;
			/* in case user press on a key have a value not refer to available option
			 * assign the initial value in the pressed key variable to act like no pressed key case
			 * */
				default:
					u8keyPressed = WAITING_PRESS_KEY;	//assign the initial value
					break;
			}//end of #switch case# --> compare the value of pressed key with the available options
		}//end of #while loop# --> looping on the value of pressed key
	}//end of #while loop# --> looping on the selected option from the main menu
	/*	while(1){
		}*/
}//end of OWNER_vidUserOptions()





/* Name: OWNER_vidMasterRoom
 * Description: display the action could take place to control the master room door/light
 * 				- check on the room status locked/open (according to door status)
 * 				- send signal to door switch
 * 				- send signal to light switch
 * 				- after each switching recall the function to update the room status
 * 				- back to the previous screen option is available
 * Arguments: void
 * Return:	void
 */
void OWNER_vidMasterRoom(void){
	/* clear the LCD screen */
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
	/* send request to the slave MC to send back the room status */
	SPI_vidTransceive(GET_MASTER_DOOR_STATUS);
	_delay_ms(50);
	u8SPIrequest = SPI_vidTransceive(DONT_CARE);
	if(u8SPIrequest == MASTER_DOOR_CLOSE){
		LCD_enuSendString("DOOR:LOCK ");
	} else if(u8SPIrequest == MASTER_DOOR_OPEN){
		 LCD_enuSendString("DOOR:OPEN ");
	} else { /*.....*/ }
	LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);
	SPI_vidTransceive(GET_MASTER_LIGHT_STATUS);
	_delay_ms(50);
	u8SPIrequest = SPI_vidTransceive(DONT_CARE);
	if(u8SPIrequest == MASTER_LIGHT_OFF){
		LCD_enuSendString("LED:OFF");
	} else if(u8SPIrequest == MASTER_LIGHT_ON){
		 LCD_enuSendString("LED:ON");
	} else { /*.....*/ }
	_delay_ms(100);
	/* list the option available to the user and interact with keypad */
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
	LCD_enuSendString("1:DOOR   2:LIGHT");
	LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN10);
	LCD_enuSendString("0:BACK");
	u8keyPressed = WAITING_PRESS_KEY;
	while(u8keyPressed == WAITING_PRESS_KEY){
		KEYPAD_vidGetPressedKey(&u8keyPressed);
		switch(u8keyPressed){
			case ROOM_DOOR:
				SPI_vidTransceive(MASTER_DOOR_SWITCH_REQUEST);
				_delay_ms(50);
				OWNER_vidMasterRoom();
				break;
			case ROOM_LIGHT:
				SPI_vidTransceive(MASTER_LIGHT_SWITCH_REQUEST);
				_delay_ms(50);
				OWNER_vidMasterRoom();
				break;
			case BACK:
				continue;
			default:
				u8keyPressed = WAITING_PRESS_KEY;
				break;
		}//end of #switch case
	}// end of #while loop
}//end of OWNER_vidMasterRoom()





/* Name: OWNER_vidTenantRoom
 * Description: display the action could take place to control the tenant room's door/light
 * 				- check on the room status locked/open (according to door status)
 * 				- send signal to door switch
 * 				- send signal to light switch
 * 				- after each switching recall the function to update the room status
 * 				- back to the previous screen option is available
 * Arguments: void
 * Return:	void
 */
void OWNER_vidTenantRoom(void){
	/* clear the LCD screen */
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
	/* send request to the slave MC to send back the room status */
	SPI_vidTransceive(GET_TENANT_DOOR_STATUS);
	_delay_ms(50);
	u8SPIrequest = SPI_vidTransceive(DONT_CARE);
	if(u8SPIrequest == TENANT_DOOR_CLOSE){
		LCD_enuSendString("DOOR:LOCK ");
	} else if(u8SPIrequest == TENANT_DOOR_OPEN){
		 LCD_enuSendString("DOOR:OPEN ");
	} else { /*.....*/ }
	LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);
	SPI_vidTransceive(GET_TENANT_LIGHT_STATUS);
	_delay_ms(50);
	u8SPIrequest = SPI_vidTransceive(DONT_CARE);
	if(u8SPIrequest == TENANT_LIGHT_OFF){
		LCD_enuSendString("LED:OFF");
	} else if(u8SPIrequest == TENANT_LIGHT_ON){
		 LCD_enuSendString("LED:ON");
	} else { /*.....*/ }
	_delay_ms(100);
	/* list the option available to the user and interact with keypad */
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
	LCD_enuSendString("1:DOOR   2:LIGHT");
	LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN10);
	LCD_enuSendString("0:BACK");
	u8keyPressed = WAITING_PRESS_KEY;
	while(u8keyPressed == WAITING_PRESS_KEY){
		KEYPAD_vidGetPressedKey(&u8keyPressed);
		switch(u8keyPressed){
			case ROOM_DOOR:
				SPI_vidTransceive(TENANT_DOOR_SWITCH_REQUEST);
				_delay_ms(50);
				OWNER_vidMasterRoom();
				break;
			case ROOM_LIGHT:
				SPI_vidTransceive(TENANT_LIGHT_SWITCH_REQUEST);
				_delay_ms(50);
				OWNER_vidMasterRoom();
				break;
			case BACK:
				continue;
			default:
				u8keyPressed = WAITING_PRESS_KEY;
				break;
		}//end of #switch case
	}// end of #while loop
}//end of OWNER_vidTenantRoom()





/* Name: OWNER_vidGarageControl
 * Description: display the action could take place to control the garage module
 * 				- change operation mode (Auto/Manual)
 * 				- contact with slave MC using SPI protocol
 * 				- after each switching recall the function to update the room status
 * 				- back to the previous screen option is available
 * Arguments: void
 * Return:	void
 */
void OWNER_vidGarageControl(void){
	/* clear the LCD screen */
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
	/* list the option available to the user and interact with keypad */
	LCD_enuSendString("1:AUTO  2:MANUAL");
	LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN10);
	LCD_enuSendString("0:BACK");
	u8keyPressed = WAITING_PRESS_KEY;
	while(u8keyPressed == WAITING_PRESS_KEY){
		KEYPAD_vidGetPressedKey(&u8keyPressed);
		switch(u8keyPressed){
			case GARAGE_AUTO_CONTROL:
				SPI_vidTransceive(SET_GARAGE_AUTO);
				_delay_ms(50);
				LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
				LCD_enuSendString("   GARAGE DOOR  ");
				LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN7);
				LCD_enuSendString("AUTO");
				_delay_ms(100);
				break;
			case GARAGE_MANUAL_CONTROL:
				SPI_vidTransceive(SET_GARAGE_MANUAL);
				_delay_ms(50);
				LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
				LCD_enuSendString("1:Open Garage");
				LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);
				LCD_enuSendString("2:Close Garage");
				u8keyPressed = WAITING_PRESS_KEY;
				while(u8keyPressed == WAITING_PRESS_KEY){
					KEYPAD_vidGetPressedKey(&u8keyPressed);
					if(u8keyPressed == GARAGE_OPEN){
						SPI_vidTransceive(OPEN_GARAGE_REQUEST);
						_delay_ms(50);
					}else if(u8keyPressed == GARAGE_LOCK){
						SPI_vidTransceive(LOCK_GARAGE_REQUEST);
						_delay_ms(50);
					}else {
						u8keyPressed = WAITING_PRESS_KEY;
					}
				}//end of #while loop# --> select open/close option
				break;
			case BACK:
				continue;
			default:
				u8keyPressed = WAITING_PRESS_KEY;
				break;
		}//end of #switch case# --> enter operation mode
	}// end of #while loop# --> enter operation mode
}//end of OWNER_vidGarageControl()




/* Name: OWNER_vidcounterDown
 * Description: implement a down counter for the period of activate party mode
 * Arguments:	Copy_u8timeMinutes  -->  options (pass the value user enter it)
 * Return:	void
 */
void OWNER_vidcounterDown(u8 Copy_u8timeMinutes){
	u8 Local_u8RemainingMinutes = Copy_u8timeMinutes;
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
	LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN4);
	LCD_enuSendString("00:  :");
	LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN7);
	LCD_enuSendNumber(Local_u8RemainingMinutes);
	LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN10);
	LCD_enuSendCharacter('00');
	GPT_vidStartTimer(GPT_u8_TIMER0, SECONDS_IN_MINUTES, NO_PRELOAD);
	while((Local_u8RemainingMinutes <= Copy_u8timeMinutes) && (Local_u8RemainingMinutes != ZERO)){
		u8MinuteEnd = FALSE;
		Local_u8RemainingMinutes --;
		LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN7);
		LCD_enuSendNumber(Local_u8RemainingMinutes);
		while(u8MinuteEnd != TRUE);
	}
	LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0); //move the cursor to the middle of first row
	LCD_enuSendString(" PARTY TIME OUT ");
}

ISR(TIMER0_OVF_vect){
	static u8 sec_counter = ZERO;
	static u8 min_counter = ZERO;
	LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN10);
	LCD_enuSendNumber(SECONDS_IN_MINUTES - sec_counter);
	sec_counter ++;
	if(sec_counter == SECONDS_IN_MINUTES + 1){
		sec_counter = ZERO;
		u8MinuteEnd = TRUE;
		min_counter++;
		if(min_counter == u8PartyDuration){
			GPT_vidStopTimer(GPT_u8_TIMER0);
			min_counter = 0;
		}

	}
}


/* Name: OWNER_u8getTemperature
 * Description: function get the temperature degree from the keypad ...
 *				user press two keys sequentially and enter it in the equation to return a number with two digits
 * Arguments:	Copy_u8TempLimit  ------->  options(MAX_TEMP, MIN_TEMP)
 * Return:	u8 ------> temperature degree
 */
u8 OWNER_u8getTemperature(u8 Copy_u8TempLimit){
	u8 Local_u8tempTens;	// create local variable to store the first digit
	u8 Local_u8tempOnes;	// create local variable to store the second digit
	u8 Local_u8iterator;	// create local count digits
	/* get the pressed key value and store it in the specific local variable */
	u8keyPressed = WAITING_PRESS_KEY;
	if(Copy_u8TempLimit == MIN_TEMP){
		LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN13);
	} else if(Copy_u8TempLimit == MAX_TEMP){
		LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN13);
	} else{ /*.....*/ }
	LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_ON);
	for(Local_u8iterator = ZERO; Local_u8iterator < DIGIT_TWO ; Local_u8iterator++){
		u8keyPressed = WAITING_PRESS_KEY;
		while((u8keyPressed == WAITING_PRESS_KEY) || (u8keyPressed == HASH_SIGN) || (u8keyPressed == ASTERISK_SIGN)){
			KEYPAD_vidGetPressedKey(&u8keyPressed);
		}
		LCD_enuSendCharacter(u8keyPressed);
		_delay_ms(50);
		Local_u8iterator == ZERO ? (Local_u8tempTens = u8keyPressed):(Local_u8tempOnes = u8keyPressed);
	}//end of #for loop
	LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_OFF);
	/* calculate the equation and return its result */
	return ((Local_u8tempTens * TEN_MULTIPLICANT) + Local_u8tempOnes);
}//end of OWNER_u8getTemperature()
