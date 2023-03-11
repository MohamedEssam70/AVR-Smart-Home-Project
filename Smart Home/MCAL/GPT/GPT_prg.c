/*
 * GPT_prg.c
 *
 *  Created on: Sep 5, 2022
 *      Author: Mohamed Essam
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "../GLOBAL_INT/GLOBAL_INT_int.h"
#include "GPT_prv.h"
#include "GPT_int.h"


typedef struct Timer{
	u8 waveFormMode;
	u8 compareMatchOutput;
	u8 clockSelect;
}GPT_timerConfigure;


GPT_timerConfigure timer0Configure = {GPT_u8_WAVE_FORM_NORMAL, GPT_u8_COM_TOGGLE, GPT_u8_PRESCALER1024};

void GPT_vidConfigure(u8 Copy_u8timer){
	if(Copy_u8timer == GPT_u8_TIMER0){
		GPT_u8_TCCR0_REG = (timer0Configure.waveFormMode | timer0Configure.compareMatchOutput | timer0Configure.clockSelect);
		} else if(Copy_u8timer == GPT_u8_TIMER1){

		} else if(Copy_u8timer == GPT_u8_TIMER2){

		}
}


void GPT_vidStartTimer(u8 Copy_u8timer, u8 Copy_u8countOVFtime, u8 Copy_u8preloadValue){
	if(Copy_u8timer == GPT_u8_TIMER0){

		GPT_u8preloadValue = Copy_u8preloadValue;

		GPT_u8_TCNT0_REG = GPT_u8preloadValue;

		GPT_u8countOVFtime = Copy_u8countOVFtime;

		GPT_u8_TIMSK_REG |= GPT_u8_OVERFLOW_INT;

		GINT_vidEnable();

	}
}



void GPT_vidStopTimer(u8 Copy_u8timer){
	CLEAR_BIT(GPT_u8_TIMSK_REG, GPT_u8_OVERFLOW_INT);
	//GPT_u8_TIMSK_REG |= 0x00;
}
