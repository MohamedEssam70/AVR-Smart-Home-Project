/*
 * GPT_int.h
 *
 *  Created on: Sep 5, 2022
 *      Author: Mohamed Essam
 */

#ifndef HAL_GPT_GPT_INT_H_
#define HAL_GPT_GPT_INT_H_


#include "GPT_cfg.h"


/********** TIMERS ***********/
#define GPT_u8_TIMER0			0
#define GPT_u8_TIMER1			1
#define GPT_u8_TIMER2			2

/*****************/
u8 GPT_u8countOVFtime;
u8 GPT_u8preloadValue;

void GPT_vidConfigure(u8 Copy_u8timer);

void GPT_vidStartTimer(u8 Copy_u8timer, u8 Copy_u8countOVFtime, u8 Copy_u8preloadValue);

void GPT_vidStopTimer(u8 Copy_u8timer);


#endif /* HAL_GPT_GPT_INT_H_ */
