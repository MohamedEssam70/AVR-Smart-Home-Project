/*
 * LCD_cfg.h
 *
 *  Created on: Aug 27, 2022
 *      Author: Mustafa
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_


/* OPTIONS :
 * 		LCD_u8_8_BIT_MODE
 * 		LCD_u8_4_BIT_MODE
 */
#define LCD_u8_DATA_LENGTH_MODE		LCD_u8_8_BIT_MODE

#define LCD_u8_RS_PORT				DIO_u8_PORTD
#define LCD_u8_RS_PIN				DIO_u8_PIN0
#define LCD_u8_RW_PORT				DIO_u8_PORTD
#define LCD_u8_RW_PIN				DIO_u8_PIN1
#define LCD_u8_E_PORT				DIO_u8_PORTD
#define LCD_u8_E_PIN				DIO_u8_PIN2

//PORT D0  TO  D7   CONNECTION
#define LCD_u8_D0_TO_D7_CONNECTION				DIO_u8_PORTC

//#define LCD_u8_D0_PORT				DIO_u8_PORTC
//#define LCD_u8_D0_PIN				DIO_u8_PIN0




/* OPTIONS :
 * 		LCD_u8_2_LINE_MODE
 * 		LCD_u8_1_LINE_MODE
 */
#define LCD_u8_NUMBER_OF_LINES		LCD_u8_2_LINE_MODE


/* OPTIONS :
 * 		LCD_u8_FONT_5_10
 * 		LCD_u8_FONT_5_7
 */
#define LCD_u8_FONT_SIZE		LCD_u8_FONT_5_7






/************************** OPTIONS *****************************/
/*
 * DATA LENGTH OPTIONS
 */
#define LCD_u8_8_BIT_MODE			0X10
#define LCD_u8_4_BIT_MODE			0X00

/*
 * NUMBER OF LINES
 */
#define LCD_u8_1_LINE_MODE			0X00
#define LCD_u8_2_LINE_MODE			0X08

/*
 * CHAR FONT
 */
#define LCD_u8_FONT_5_7			0X00
#define LCD_u8_FONT_5_10		0X04




#endif /* HAL_LCD_LCD_CFG_H_ */
