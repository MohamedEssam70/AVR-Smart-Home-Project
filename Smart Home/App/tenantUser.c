/*
 * tenantUser.c
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
#include "tenantUser.h"
#include "MACROS_SPI.h"




/* Name: TENANT_vidRoomControl
 * Description: control options available to the user assign as tenant for its room
 * Arguments: void
 * Return:	void
 */
void TENANT_vidRoomControl(void){
	/* local variable */
	u8 Local_u8SPIrequest = DONT_CARE;	//create a variable to get the data send by SPI from the slave
	u8 Local_u8keyPressed = WAITING_PRESS_KEY;	//create a variable to store the pressed key

	/* clear the LCD screen */
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
	/* send request to the slave MC to send back the room status */
	SPI_vidTransceive(GET_TENANT_DOOR_STATUS);
	_delay_ms(50);
	Local_u8SPIrequest = SPI_vidTransceive(DONT_CARE);
	if(Local_u8SPIrequest == TENANT_DOOR_CLOSE){
		LCD_enuSendString("DOOR:LOCK ");
	} else if(Local_u8SPIrequest == TENANT_DOOR_OPEN){
		 LCD_enuSendString("DOOR:OPEN ");
	} else { /*.....*/ }
	LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);
	SPI_vidTransceive(GET_TENANT_LIGHT_STATUS);
	_delay_ms(50);
	Local_u8SPIrequest = SPI_vidTransceive(DONT_CARE);
	if(Local_u8SPIrequest == TENANT_LIGHT_OFF){
		LCD_enuSendString("LED:OFF");
	} else if(Local_u8SPIrequest == TENANT_LIGHT_ON){
		 LCD_enuSendString("LED:ON");
	} else { /*.....*/ }
	_delay_ms(100);
	/* list the option available to the user and interact with keypad */
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
	LCD_enuGoTo(LCD_u8_ROW1, LCD_u8_COLUMN0);
	LCD_enuSendString("1:DOOR   2:LIGHT");
	LCD_enuGoTo(LCD_u8_ROW0, LCD_u8_COLUMN10);
	LCD_enuSendString("0:BACK");
	Local_u8keyPressed = WAITING_PRESS_KEY;
	while(Local_u8keyPressed == WAITING_PRESS_KEY){
		KEYPAD_vidGetPressedKey(&Local_u8keyPressed);
		switch(Local_u8keyPressed){
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
			default:
				Local_u8keyPressed = WAITING_PRESS_KEY;
				break;
		}//end of #switch case
	}// end of #while loop


}
