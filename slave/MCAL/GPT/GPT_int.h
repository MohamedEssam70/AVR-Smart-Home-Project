/*
 * GPT_int.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Mustafa
 */

#ifndef MCAL_GPT_GPT_INT_H_
#define MCAL_GPT_GPT_INT_H_
//timers
#define GPT_u8_TIMER0                   10
#define GPT_u8_TIMER1                   11
#define GPT_u8_TIMER2                   12

//mode interrupt timer2
#define GPT_u8_TIMER2_COMP              0
#define GPT_u8_TIMER2_OVF               1

//mode interrupt timer1
#define GPT_u8_TIMER1_CAPT              3
#define GPT_u8_TIMER1_COMPA             4
#define GPT_u8_TIMER1_COMPB             5
#define GPT_u8_TIMER1_OVF               6

//mode interrupt timer2
#define GPT_u8_TIMER0_COMP              7
#define GPT_u8_TIMER0_OVF               8

//Configure timer register
void GPT_VoidConfigure(u8 Copy_u8timer);

void GPT_VoidStartTimer(u8 Copy_u8timer );

void GPT_VoidEnableCBF(u8 Copy_u8Timer,u8 Copy_u8TimerMode,func_ptr Add_pCBF );

#endif /* MCAL_GPT_GPT_INT_H_ */
