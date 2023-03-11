/*
 * KEYPAD_int.h
 *
 *  Created on: Aug 28, 2022
 *      Author: Mohamed Essam
 */

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_

#include "KEYPAD_cfg.h"




/* error status*/
typedef enum{
	KEYPAD_OK,
	KEYPAD_NOK
}KEYPAD_tenuErrorStatus;


void KEYPAD_vidTnti(void);




KEYPAD_tenuErrorStatus KEYPAD_vidGetPressedKey(u8 *Add_pu8KeyValue);




#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
