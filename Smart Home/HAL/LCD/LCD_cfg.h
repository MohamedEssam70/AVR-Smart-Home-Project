/*
 * LCD_cfg.h
 *
 *  Created on: Aug 25, 2022
 *      Author: Mohamed Essam
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_



/*
 * OPTIONS:
 * 		1- LCD_u8_Eight_BITS_MODE
 * 		2- LCD_u8_FOUR_BITS_MODE
*/
#define LCD_u8_DATA_LENGTH					LCD_u8_Eight_BITS_MODE


/*
 * OPTIONS:
 * 		1- LCD_u8_ONE_LINE_MODE
 * 		2- LCD_u8_TWO_LINE_MODE
*/
#define LCD_u8_NUMBER_OF_LINES				LCD_u8_TWO_LINE_MODE


/*
 * OPTIONS:
 * 		1- LCD_u8_FONT_5_7
 * 		2- LCD_u8_FONT_5_10
*/
#define LCD_u8_CHARACTER_FONT				LCD_u8_FONT_5_7




/*************** CONFIG PORTS & PINS *********************/
//Control
#define LCD_u8_RS_PORT				DIO_u8_PORTC
#define LCD_u8_RS_PIN				DIO_u8_PIN0

#define LCD_u8_RW_PORT				DIO_u8_PORTC
#define LCD_u8_RW_PIN				DIO_u8_PIN1

#define LCD_u8_ENABLE_PORT			DIO_u8_PORTC
#define LCD_u8_ENABLE_PIN			DIO_u8_PIN2

//DATA
#define LCD_u8_DATA_PORT			DIO_u8_PORTA

#define LCD_u8_D0_PORT				DIO_u8_PORTA
#define LCD_u8_D0_PIN				DIO_u8_PIN0
#define LCD_u8_D1_PORT				DIO_u8_PORTA
#define LCD_u8_D1_PIN				DIO_u8_PIN1
#define LCD_u8_D2_PORT				DIO_u8_PORTA
#define LCD_u8_D2_PIN				DIO_u8_PIN2
#define LCD_u8_D3_PORT				DIO_u8_PORTA
#define LCD_u8_D3_PIN				DIO_u8_PIN3
#define LCD_u8_D4_PORT				DIO_u8_PORTA
#define LCD_u8_D4_PIN				DIO_u8_PIN4
#define LCD_u8_D5_PORT				DIO_u8_PORTA
#define LCD_u8_D5_PIN				DIO_u8_PIN5
#define LCD_u8_D6_PORT				DIO_u8_PORTA
#define LCD_u8_D6_PIN				DIO_u8_PIN6
#define LCD_u8_D7_PORT				DIO_u8_PORTA
#define LCD_u8_D7_PIN				DIO_u8_PIN7



#endif /* HAL_LCD_LCD_CFG_H_ */
