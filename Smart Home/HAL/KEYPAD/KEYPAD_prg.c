/*
 * KEYPAD_prg.c
 *
 *  Created on: Aug 28, 2022
 *      Author: Mohamed Essam
 */


#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "KEYPAD_int.h"

extern const u8 KEYPAD_au8KeyValue [KEYPAD_u8_ROWS_NUM][KEYPAD_u8_COLUMNS_NUM];
extern const u8 KEYPAD_au8Rows[KEYPAD_u8_ROWS_NUM][KEYPAD_u8_PORT_PIN];
extern const u8 KEYPAD_au8Columns[KEYPAD_u8_COLUMNS_NUM][KEYPAD_u8_PORT_PIN];

void KEYPAD_vidTnti(void){
	DIO_vidInit();
}


KEYPAD_tenuErrorStatus KEYPAD_vidGetPressedKey(u8 *Add_pu8KeyValue){
	KEYPAD_tenuErrorStatus Local_enuErrorStatus = KEYPAD_OK;
	u8 Local_u8IteratorRow;
	u8 Local_u8IteratorColumn;
	u8 Local_u8KeyPressedIndicator;
	/* check argument */
	if(Add_pu8KeyValue == NULL){
		Local_enuErrorStatus = KEYPAD_NOK;
	} else {
		for(Local_u8IteratorColumn = 0; Local_u8IteratorColumn < KEYPAD_u8_COLUMNS_NUM; Local_u8IteratorColumn++){
			DIO_enuSetPinValue(KEYPAD_au8Columns[Local_u8IteratorColumn][KEYPAD_u8_PORT],
								KEYPAD_au8Columns[Local_u8IteratorColumn][KEYPAD_u8_PIN], DIO_u8_LOW);
			for(Local_u8IteratorRow = 0; Local_u8IteratorRow < KEYPAD_u8_ROWS_NUM; Local_u8IteratorRow++){
				DIO_enuGetPinValue(KEYPAD_au8Rows[Local_u8IteratorRow][KEYPAD_u8_PORT],
									KEYPAD_au8Rows[Local_u8IteratorRow][KEYPAD_u8_PIN], &Local_u8KeyPressedIndicator);
				if(Local_u8KeyPressedIndicator == 0){	// will be 0 only if any key pressed
					*Add_pu8KeyValue = KEYPAD_au8KeyValue[Local_u8IteratorRow][Local_u8IteratorColumn]; //put the selected pressed key to the retrurnval
					_delay_ms(15);
					break; // break from the loop
				}
			}
			DIO_enuSetPinValue(KEYPAD_au8Columns[Local_u8IteratorColumn][KEYPAD_u8_PORT],
								KEYPAD_au8Columns[Local_u8IteratorColumn][KEYPAD_u8_PIN], DIO_u8_HIGH);
		}
	}
	return Local_enuErrorStatus;
}
