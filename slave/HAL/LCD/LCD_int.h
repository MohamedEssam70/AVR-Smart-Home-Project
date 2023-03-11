/*
 * LCD_int.h
 *
 *  Created on: Aug 27, 2022
 *      Author: Mustafa
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

/* error status */
typedef enum
{
	LCD_OK,
	LCD_NOK
}LCD_tenuErrorStatus;


/*********************************** macros **********************************/

/* macros for instructions */
#define LCD_u8_CLEAR_DISPALY				0X01
#define LCD_u8_RETURN_HOME					0X02
#define LCD_u8_CURSOR_INC_SHIFT_OFF			0X06
#define LCD_u8_CURSOR_DEC_SHIFT_OFF			0X04
#define LCD_u8_CURSOR_INC_SHIFT_ON			0X07
#define LCD_u8_CURSOR_DEC_SHIFT_ON			0X05
/* DIPLAY CONTROL  */
#define LCD_u8_DISPLAY_OFF					0X08
#define LCD_u8_DISPLAY_ON_CURSOR_OFF		0X0C
#define LCD_u8_DISPLAY_ON_CURSOR_ON			0X0E
#define LCD_u8_DISPLAY_ON_CURSOR_BINK_ON	0X0F
/* CURSOR OR DIPLAY SHIFT */
#define LCD_u8_SHIFT_CURSOR_LEFT			0X10
#define LCD_u8_SHIFT_CURSOR_RIGHT			0X14
#define LCD_u8_SHIFT_DISPLAY_LEFT			0X18
#define LCD_u8_SHIFT_DISPLAY_RIGTH			0X1C

/* please configure */
#define LCD_u8_FUNCTION_SET			0X20  | LCD_u8_DATA_LENGTH_MODE | LCD_u8_NUMBER_OF_LINES | LCD_u8_FONT_SIZE

#define LCD_u8_FIRST_CGRAM_ADDRESS			0X40
#define LCD_u8_FIRST_DDRAM_ADDRESS			0X80

/* macros for row and column */
#define LCD_u8_ROW0		0X00
#define LCD_u8_ROW1		0X01

#define LCD_u8_COL0		0X00
#define LCD_u8_COL1		0X01
#define LCD_u8_COL2		0X02
#define LCD_u8_COL3		0X03
#define LCD_u8_COL4		0X04
#define LCD_u8_COL5		0X05
#define LCD_u8_COL6		0X06
#define LCD_u8_COL7		0X07
#define LCD_u8_COL8		0X08
#define LCD_u8_COL9		0X09
#define LCD_u8_COL10	0X0A
#define LCD_u8_COL11	0X0B
#define LCD_u8_COL12	0X0C
#define LCD_u8_COL13	0X0D
#define LCD_u8_COL14	0X0E
#define LCD_u8_COL15	0X0F






/*
 *
 *
 */
void LCD_vidInit(void);

/*
 *
	u8 var = 'A';

	print("%d", var);   // print ascii code

*/

/*
 *
 *
 */
LCD_tenuErrorStatus	LCD_enuSendCharacter(u8 Copy_u8Character);



LCD_tenuErrorStatus	LCD_enuSendInstruction(u8 Copy_u8Instruction);



LCD_tenuErrorStatus	LCD_enuSendString(u8* Add_pu8String);



LCD_tenuErrorStatus	LCD_enuGoTo(u8 Copy_u8Row, u8 Copy_u8Column);



LCD_tenuErrorStatus	LCD_enuSendCustomCharacter(u8 *Add_pu8Pattern, u8 Copy_u8NumOfBlock, u8 Copy_u8Row, u8 Copy_u8Column);


void	LCD_enuSendNumber(u32 Copy_u8Number);

#endif /* HAL_LCD_LCD_INT_H_ */
