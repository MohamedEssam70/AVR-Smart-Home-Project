/*
 * LCD_prg.c
 *
 *  Created on: Aug 25, 2022
 *      Author: Mohamed Essam
 */

#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LCD_int.h"
#include "LCD_cfg.h"
#include "LCD_prv.h"

/******Static Functions ProtoType******/
static void LCD_SendEnable(void);



/*****FUNCTIONS*******/

/*
 * Name: LCD_vidInit
 * Description: Initialize the LCD ... According to DATASHEET instruction
 * Arguments: void
 * Return:	void
 */
void LCD_vidInit(void){
	DIO_vidInit();

	_delay_ms(32);
	/*Function Set*/
	LCD_enuSendInstruction(LCD_u8_FUNCTION_SET);

	_delay_ms(1);

	/*Display Control*/
	LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURRSOR_ON);

	_delay_ms(1);

	/*Display Clear*/
	LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);

	_delay_ms(2);

	/*Entry Mode Set*/
	LCD_enuSendInstruction(LCD_u8_CURSOR_INC_SHIFT_OFF);
}






/*
 * Name: LCD_enuSendInstruction
 * Description: Display Control Instructions According to the LCD DataSheet
 * Arguments:	Copy_u8Instruction				OPTIONS --> (LCD_u8_CLEAR_DISPLAY, LCD_u8_RETURN_HOME, LCD_u8_CURSOR_INC_SHIFT_OFF,
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 LCD_u8_CURSOR_DEC_SHIFT_OFF, LCD_u8_CURSOR_INC_SHIFT_ON,
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 LCD_u8_CURSOR_DEC_SHIFT_ON, LCD_u8_DISPLAY_OFF,
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 LCD_u8_DISPLAY_ON_CURRSOR_OFF, LCD_u8_DISPLAY_ON_CURRSOR_ON
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 LCD_u8_DISPLAY_ON_CURRSOR_BINK_ON, LCD_u8_SHIFT_CURSOR_LEFT,
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 LCD_u8_SHIFT_CURSOR_RIGHT, LCD_u8_SHIFT_DISPLAY_LEFT,
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 LCD_u8_SHIFT_DISPLAY_RIGHT, LCD_u8_FUNCTION_SET,
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 LCD_u8_FIRST_CGRAM_ADDRESS, LCD_u8_FIRST_DDRAM_ADDRESS)
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus LCD_enuSendInstruction(u8 Copy_u8Instruction){
	LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;

	/*check arguments*/
	if(0) {
		Local_enuErrorStatus = LCD_NOK;
	} else {
	/*****IMPLEMENTATION*****/
		/*RS PIN --------> low*/
		DIO_enuSetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8_LOW);

		/*RW PIN --------> low*/
		DIO_enuSetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

		/*Send instruction*/		// set port()*1 OR set pin()*8
		DIO_enuSetPortValue(LCD_u8_DATA_PORT, Copy_u8Instruction);

		/*Send enable*/
		LCD_SendEnable();
	}

	return Local_enuErrorStatus;
}







/*
 * Name: LCD_enuSendCharacter
 * Description: Send a character to display on the LCD
 * Arguments:	Copy_u8Character				OPTIONS --> (Any character its ascii code exist in the CG ROM)
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus LCD_enuSendCharacter(u8 Copy_u8Character){
	LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;

	/*****IMPLEMENTATION*****/
	/*RS PIN --------> low*/
	DIO_enuSetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8_HIGH);

	/*RW PIN --------> high*/
	DIO_enuSetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

	/*Send Data*/
	DIO_enuSetPortValue(LCD_u8_DATA_PORT, Copy_u8Character);

	/*Send enable*/
	LCD_SendEnable();

	return Local_enuErrorStatus;
}






/*
 * Name: LCD_enuSendString
 * Description: Send a string to display it on the LCD
 * Arguments: Add_pu8String	--------> pointer refer to the first address of the string array
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus LCD_enuSendString(u8* Add_pu8String){
	LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;

	/*check arguments*/
	if(Add_pu8String == NULL){
		Local_enuErrorStatus = LCD_NOK;
	} else {
	/*****IMPLEMENTATION*****/
		while (*Add_pu8String != '\0'){
			LCD_enuSendCharacter(*Add_pu8String);
			Add_pu8String++;
		}
	}

	return Local_enuErrorStatus;
}





/*
 * Name: LCD_enuGoTo
 * Description: Make the AC point to specific address
 * Arguments:	first Argument:		Copy_u8Row,				options (LCD_u8_ROW0, LCD_u8_ROW1)
 * 				second Argument: 	Copy_u8Column, 			options (LCD_u8_COLUMN0 : LCD_u8_COLUMN15)
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus LCD_enuGoTo(u8 Copy_u8Row, u8 Copy_u8Column){
	LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;

	/*check arguments*/
	if ((Copy_u8Row > LCD_u8_ROW1) || (Copy_u8Column > LCD_u8_COLUMN15)){
		Local_enuErrorStatus = LCD_NOK;
	} else {
	/*****IMPLEMENTATION*****/
		switch(Copy_u8Row){
		case LCD_u8_ROW0:
			LCD_enuSendInstruction(LCD_u8_FIRST_DDRAM_ADDRESS | Copy_u8Column);
			break;
		case LCD_u8_ROW1:
			LCD_enuSendInstruction(LCD_u8_FIRST_DDRAM_ADDRESS | (Copy_u8Column + LCD_u8_COLUMN_IN_ROW1));
			break;
		}
	}

	return Local_enuErrorStatus;
}







/*
 * Name: LCD_enuSendCustomCharacter
 * Description: Send a pattern to display it on the LCD
 * Arguments:	first Argument:		*Add_pu8Pattern,				options (pointer refer to the array of pattern)
 * 				second Argument: 	Copy_u8NumOfBlock, 				options (0 : 7)
 * 				third Argument: 	Copy_u8Row, 					options (LCD_u8_ROW0, LCD_u8_ROW1)
 * 				fourth Argument: 	Copy_u8Column, 					options (LCD_u8_COLUMN0 : LCD_u8_COLUMN15)
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus	LCD_enuSendCustomCharacter(u8 *Add_pu8Pattern, u8 Copy_u8NumOfBlock, u8 Copy_u8Row, u8 Copy_u8Column){
	LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;
	u8 Local_u8Iterator;

	/*check arguments*/
	if ((Add_pu8Pattern == NULL) || (Copy_u8NumOfBlock > LCD_u8_CGRAM_BLOCK_8) || (Copy_u8Row > LCD_u8_ROW1) || (Copy_u8Column > LCD_u8_COLUMN15)){
		Local_enuErrorStatus = LCD_NOK;
	} else {
	/*****IMPLEMENTATION*****/
		LCD_enuSendInstruction(LCD_u8_FIRST_CGRAM_ADDRESS + (Copy_u8NumOfBlock * LCD_u8_BYTES_IN_BLOCK));
		for (Local_u8Iterator = 0; Local_u8Iterator < LCD_u8_BYTES_IN_BLOCK; Local_u8Iterator++){
			LCD_enuSendCharacter(Add_pu8Pattern[Local_u8Iterator]);
			_delay_ms(5);
		}
		LCD_enuGoTo(Copy_u8Row, Copy_u8Column);
		LCD_enuSendCharacter(Copy_u8NumOfBlock);
	}
	return Local_enuErrorStatus;
}







/*
 * Name: LCD_enuSendNumber
 * Description: Send a number to display on the LCD
 * Arguments:	Copy_u8Number				OPTIONS --> (Any integer number)
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus	LCD_enuSendNumber(u8 Copy_u8Number){
	LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;
	u8 Local_u8Numbers[10] = "0123456789";
//	LCD_enuSendCharacter(Local_u8Numbers[Copy_u8Number/100%10]);
	LCD_enuSendCharacter(Local_u8Numbers[Copy_u8Number/10%10]);
	LCD_enuSendCharacter(Local_u8Numbers[Copy_u8Number%10]);


	return Local_enuErrorStatus;
}





/*
 * Name: LCD_enuSendSinusoidalString
 * Description: Clear a line or row in the LCD display screen
 * Arguments: Copy_u8Row,				options (LCD_u8_ROW0, LCD_u8_ROW1)
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus LCD_enuClearLine(u8 Copy_u8Row){
	LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;

	/*check arguments*/
	if(Copy_u8Row > LCD_u8_ROW1){
		Local_enuErrorStatus = LCD_NOK;
	} else {
	/*****IMPLEMENTATION*****/
	LCD_enuGoTo(Copy_u8Row, LCD_u8_COLUMN0);
	LCD_enuSendString(LCD_u8_FREE_LINE);
	LCD_enuGoTo(Copy_u8Row, LCD_u8_COLUMN0);
	}

	return Local_enuErrorStatus;
}












/******Private Function********/

static void LCD_SendEnable(void){									// Enable write data at the falling edge.
	DIO_enuSetPinValue(LCD_u8_ENABLE_PORT, LCD_u8_ENABLE_PIN, DIO_u8_HIGH);		// select pin of enable and set it to be high.
	_delay_ms(1);													// delay 1ms before the falling.
	DIO_enuSetPinValue(LCD_u8_ENABLE_PORT, LCD_u8_ENABLE_PIN, DIO_u8_LOW);		//select pin of enable and set it to be low.
}
