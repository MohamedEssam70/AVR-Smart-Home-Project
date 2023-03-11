/*
 * KEYPAD_cfg.c
 *
 *  Created on: Aug 28, 2022
 *      Author: Mohamed Essam
 */


#include "../../LIB/STD_Types.h"
#include "KEYPAD_cfg.h"
#include "../../MCAL/DIO/DIO_int.h"



const u8 KEYPAD_au8KeyValue [KEYPAD_u8_ROWS_NUM][KEYPAD_u8_COLUMNS_NUM] =
{
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'},
		{'*', '0', '#'}
};


const u8 KEYPAD_au8Rows [KEYPAD_u8_ROWS_NUM][KEYPAD_u8_PORT_PIN] =
{
		{DIO_u8_PORTC, DIO_u8_PIN6},
		{DIO_u8_PORTC, DIO_u8_PIN7},
		{DIO_u8_PORTD, DIO_u8_PIN0},
		{DIO_u8_PORTD, DIO_u8_PIN1}
};


const u8 KEYPAD_au8Columns [KEYPAD_u8_COLUMNS_NUM][KEYPAD_u8_PORT_PIN] =
{
		{DIO_u8_PORTC, DIO_u8_PIN3},
		{DIO_u8_PORTC, DIO_u8_PIN4},
		{DIO_u8_PORTC, DIO_u8_PIN5}
};
