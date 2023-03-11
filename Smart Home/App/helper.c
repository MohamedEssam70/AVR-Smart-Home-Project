/*
 * helper.c
 *
 *  Created on: Sep 17, 2022
 *      Author: Mohamed Essam
 */



#include <util/delay.h>
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Utils.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EEPROM/EEPROM_int.h"
#include "../MCAL/SPI/SPI_int.h"
#include "../HAL/LED/LED_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "helper.h"




/* Name: HELPER_vidSucessLogin
 * Description: block of code needed to exclude every time user login with a correct password
 * Arguments: void
 * Return:	void
 */
void HELPER_vidSucessLogin(void){
	/* local variable */
	u8 Local_au8CustomCharacterUnlock[BLOCK_SIZE] = {0x0E, 0x10, 0x10, 0x1F, 0x1B, 0x1B, 0x1F, 0x00}; //unlock pattern --> CGRAM_BLOCK_1

	/* success login LED */
	DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN7, DIO_u8_HIGH);

	/* success login screen */
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);		//clear LCD screen
	LCD_enuSendCustomCharacter(Local_au8CustomCharacterUnlock, LCD_u8_CGRAM_BLOCK_1, LCD_u8_ROW0, LCD_u8_COLUMN8);
	LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN2); //move the cursor to the middle of second row
	LCD_enuSendString("Success Login");
	_delay_ms(100);	//stand the system up to display success login message for 100 ms
}
