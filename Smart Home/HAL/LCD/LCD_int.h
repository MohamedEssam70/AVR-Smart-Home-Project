/*
 * LCD_int.h
 *
 *  Created on: Aug 25, 2022
 *      Author: Mohamed Essam
 */

#ifndef HAL_LCD_INT_H_
#define HAL_LCD_INT_H_


#include "LCD_cfg.h"




typedef enum{
	LCD_OK,
	LCD_NOK
}LCD_tenuErrorStatus;




/****************** macros *****************/


/*** options for function set ***/
/*DATA LENGHT OPTIONS*/

#define LCD_u8_FOUR_BITS_MODE				0x00
#define LCD_u8_Eight_BITS_MODE				0x10


/*NUMBER OF DISPLAY LINES OPTIONS*/
#define LCD_u8_ONE_LINE_MODE				0x00
#define LCD_u8_TWO_LINE_MODE				0x08


/*CHARACTER FONT OPTIONS*/
#define LCD_u8_FONT_5_7						0x00
#define LCD_u8_FONT_5_10					0x04








/*** macros for instructions ***/
/**/
#define LCD_u8_CLEAR_DISPLAY					0x01	// LCD PINS DB0 ---> DB7
#define LCD_u8_RETURN_HOME						0x02	// LCD PINS DB0 ---> DB7
#define LCD_u8_CURSOR_INC_SHIFT_OFF				0x06	// LCD PINS DB0 ---> DB7
#define LCD_u8_CURSOR_DEC_SHIFT_OFF				0x04	// LCD PINS DB0 ---> DB7
#define LCD_u8_CURSOR_INC_SHIFT_ON				0x07	// LCD PINS DB0 ---> DB7
#define LCD_u8_CURSOR_DEC_SHIFT_ON				0x05	// LCD PINS DB0 ---> DB7
#define LCD_u8_DISPLAY_OFF						0x08	// LCD PINS DB0 ---> DB7
#define LCD_u8_DISPLAY_ON_CURRSOR_OFF			0x0C	// LCD PINS DB0 ---> DB7
#define LCD_u8_DISPLAY_ON_CURRSOR_ON			0x0E	// LCD PINS DB0 ---> DB7
#define LCD_u8_DISPLAY_ON_CURRSOR_BINK_ON		0x0F	// LCD PINS DB0 ---> DB7
/*CURSOR OR DISPLAY SHIFT*/
#define LCD_u8_SHIFT_CURSOR_LEFT				0x10	// LCD PINS DB0 ---> DB7
#define LCD_u8_SHIFT_CURSOR_RIGHT				0x14	// LCD PINS DB0 ---> DB7
#define LCD_u8_SHIFT_DISPLAY_LEFT				0x18	// LCD PINS DB0 ---> DB7
#define LCD_u8_SHIFT_DISPLAY_RIGHT				0x1C	// LCD PINS DB0 ---> DB7
/*FUNCTION SET*/
#define LCD_u8_FUNCTION_SET						0x20 | LCD_u8_DATA_LENGTH | LCD_u8_NUMBER_OF_LINES | LCD_u8_CHARACTER_FONT
/*SET CG RAM ADDRESS*/
#define LCD_u8_FIRST_CGRAM_ADDRESS				0x40	// LCD PINS DB0 ---> DB7
/*SET DD RAM ADDRESS*/
#define LCD_u8_FIRST_DDRAM_ADDRESS				0x80	// LCD PINS DB0 ---> DB7






/* macros for row and column*/
#define LCD_u8_ROW0				0x00
#define LCD_u8_ROW1				0x01

#define LCD_u8_COLUMN0			0x00
#define LCD_u8_COLUMN1			0x01
#define LCD_u8_COLUMN2			0x02
#define LCD_u8_COLUMN3			0x03
#define LCD_u8_COLUMN4			0x04
#define LCD_u8_COLUMN5			0x05
#define LCD_u8_COLUMN6			0x06
#define LCD_u8_COLUMN7			0x07
#define LCD_u8_COLUMN8			0x08
#define LCD_u8_COLUMN9			0x09
#define LCD_u8_COLUMN10			0x0A
#define LCD_u8_COLUMN11			0x0B
#define LCD_u8_COLUMN12			0x0C
#define LCD_u8_COLUMN13			0x0D
#define LCD_u8_COLUMN14			0x0E
#define LCD_u8_COLUMN15			0x0F

#define LCD_u8_COLUMN_IN_ROW1	0x40





/* macros for CGRAM blocks */
#define LCD_u8_BYTES_IN_BLOCK		8

#define LCD_u8_CGRAM_BLOCK_1		0
#define LCD_u8_CGRAM_BLOCK_2		1
#define LCD_u8_CGRAM_BLOCK_3		2
#define LCD_u8_CGRAM_BLOCK_4		3
#define LCD_u8_CGRAM_BLOCK_5		4
#define LCD_u8_CGRAM_BLOCK_6		5
#define LCD_u8_CGRAM_BLOCK_7		6
#define LCD_u8_CGRAM_BLOCK_8		7









/*
 * Name: DIO_vidInit
 * Description: initialize ...
 * Arguments: void
 * Return:	void
 */
void LCD_vidInit(void);






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
LCD_tenuErrorStatus LCD_enuSendInstruction(u8 Copy_u8Instruction);






/*
 * Name: LCD_enuSendCharacter
 * Description: Send a character to display on the LCD
 * Arguments:	Copy_u8Character				OPTIONS --> (Any character its ascii code exist in the CG ROM)
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus LCD_enuSendCharacter(u8 Copy_u8Character);







/*
 * Name: LCD_enuSendString
 * Description: Send a string to display it on the LCD
 * Arguments: Add_pu8String	--------> pointer refer to the first address of the string array
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus LCD_enuSendString(u8* Add_pu8String);






/*
 * Name: LCD_enuGoTo
 * Description: Make the AC point to specific address
 * Arguments:	first Argument:		Copy_u8Row,				options (LCD_u8_ROW0, LCD_u8_ROW1)
 * 				second Argument: 	Copy_u8Column, 			options (LCD_u8_COLUMN0 : LCD_u8_COLUMN15)
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus LCD_enuGoTo(u8 Copy_u8Row, u8 Copy_u8Column);




/*
 * Name: LCD_enuSendCustomCharacter
 * Description: Send a pattern to display it on the LCD
 * Arguments:	first Argument:		*Add_pu8Pattern,				options (pointer refer to the array of pattern)
 * 				second Argument: 	Copy_u8NumOfBlock, 				options (0 : 7)
 * 				third Argument: 	Copy_u8Row, 					options (LCD_u8_ROW0, LCD_u8_ROW1)
 * 				fourth Argument: 	Copy_u8Column, 					options (LCD_u8_COLUMN0 : LCD_u8_COLUMN15)
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus	LCD_enuSendCustomCharacter(u8 *Add_pu8Pattern, u8 Copy_u8NumOfBlock, u8 Copy_u8Row, u8 Copy_u8Column);



/*
 * Name: LCD_enuSendNumber
 * Description: Send a number to display on the LCD
 * Arguments:	Copy_u8Number				OPTIONS --> (Any integer number)
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus	LCD_enuSendNumber(u8 Copy_u8Number);






/*
 * Name: LCD_enuSendSinusoidalString
 * Description: Clear a line or row in the LCD display screen
 * Arguments: Copy_u8Row,				options (LCD_u8_ROW0, LCD_u8_ROW1)
 * Return:	Error Status -----> LCD_OK , LCD_NOK
 */
LCD_tenuErrorStatus LCD_enuClearLine(u8 Copy_u8Row);






#endif /* HAL_LCD_INT_H_ */
