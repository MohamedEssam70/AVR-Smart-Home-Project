/*
 * GPT_prg.c
 *
 *  Created on: Sep 6, 2022
 *      Author: Mustafa
 */
#include "../../LIB./STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "GPT_prv.h"
#include "GPT_int.h"
#include "GPT_cfg.h"

struct
{
func_ptr GPT_TIMER2_COMP;
func_ptr GPT_TIMER2_OVF;
func_ptr GPT_TIMER1_CAPT;
func_ptr GPT_TIMER1_COMPA;
func_ptr GPT_TIMER1_COMPB;
func_ptr GPT_TIMER1_OVF;
func_ptr GPT_TIMER0_COMP;
func_ptr GPT_TIMER0_OVF;
}TIMER;
u8 GPT_u8NumberOfOVF = 0;
void GPT_VoidConfigure(u8 Copy_u8timer)
{
	switch(Copy_u8timer)
	{
	case  GPT_u8_TIMER0 :
		TCCR0_REG|=GPT_u8_64_PRESCALING;
		TCCR0_REG|=GPT_u8_NORMAL_OPERATION_TIMER0;
		//TIMSK_REG|=GPT_u8_TOIE0_PIN ;
	    //TIMSK_REG|=GPT_u8_TOGGLE_TIMER0 ;
		//OCR0_REG=150;
		break;
	case  GPT_u8_TIMER1 :

			break;
	case  GPT_u8_TIMER2 :

			break;


	}

}

void GPT_VoidStartTimer(u8 Copy_u8timer)
{
	switch(Copy_u8timer)
	{
	case  GPT_u8_TIMER0 :

		TIMSK_REG|=GPT_u8_TOIE0_PIN ;
		//TIMSK_REG|=GPT_u8_OCIE0_PIN;
		//GPT_u8NumberOfOVF =Copy_u8OVF;
		break;
	case  GPT_u8_TIMER1 :
		TIMSK_REG|=GPT_u8_TOIE0_PIN ;
			break;
	case  GPT_u8_TIMER2 :
		TIMSK_REG|=GPT_u8_TOIE0_PIN ;
			break;


	}

}

void GPT_VoidEnableCBF(u8 Copy_u8Timer,u8 Copy_u8TimerMode,func_ptr Add_pCBF )
{
	//implementation
switch(Copy_u8Timer)
{
case  GPT_u8_TIMER0  :
	switch(Copy_u8TimerMode)
	{
	case  GPT_u8_TIMER0_COMP  :
		TIMER.GPT_TIMER0_COMP=Add_pCBF;
		break;
	case  GPT_u8_TIMER0_OVF  :
		TIMER.GPT_TIMER0_OVF=Add_pCBF;
		break;
	}
	break;



case  GPT_u8_TIMER1  :
	switch(Copy_u8TimerMode)
		{
		case  GPT_u8_TIMER1_CAPT  :
			TIMER.GPT_TIMER1_CAPT=Add_pCBF;
			break;
		case  GPT_u8_TIMER1_COMPA  :
			TIMER.GPT_TIMER1_COMPA=Add_pCBF;
			break;
		case  GPT_u8_TIMER1_COMPB  :
			TIMER.GPT_TIMER1_COMPB=Add_pCBF;
			break;
		case  GPT_u8_TIMER1_OVF  :
			TIMER.GPT_TIMER0_OVF=Add_pCBF;
			break;
		}
	break;

case  GPT_u8_TIMER2 :
	switch(Copy_u8TimerMode)
	{
	case  GPT_u8_TIMER2_COMP  :
		TIMER.GPT_TIMER2_COMP=Add_pCBF;
		break;
	case  GPT_u8_TIMER2_OVF  :
		TIMER.GPT_TIMER2_OVF=Add_pCBF;
		break;
	}
	break;

}
}

//Timer/Counter2 Compare Match
void __vector_4(void)     __attribute__((signal,used));
void __vector_4(void)
{
	//implementation
	if(TIMER.GPT_TIMER2_COMP!=NULL)
		{
		TIMER.GPT_TIMER2_COMP();
		}

}

//Timer/Counter2 Overflow
void __vector_5(void)     __attribute__((signal,used));
void __vector_5(void)
{
	//implementation

	if(TIMER.GPT_TIMER2_OVF!=NULL)
		{
		TIMER.GPT_TIMER2_OVF();
		}

}
/*
//Timer/Counter1 Capture Event
void __vector_6(void)     __attribute__((signal,used));
void __vector_6(void)
{
	//implementation

	if(TIMER.GPT_TIMER1_CAPT!=NULL)
			{
			TIMER.GPT_TIMER1_CAPT();
			}
}*/

//Timer/Counter1 Compare Match A
void __vector_7(void)     __attribute__((signal,used));
void __vector_7(void)
{
	//implementation
	if(TIMER.GPT_TIMER1_COMPA!=NULL)
				{
				TIMER.GPT_TIMER1_COMPA();
				}

}

//Timer/Counter1 Compare Match B
void __vector_8(void)     __attribute__((signal,used));
void __vector_8(void)
{
	//implementation
	if(TIMER.GPT_TIMER1_COMPB!=NULL)
				{
				TIMER.GPT_TIMER1_COMPB();
				}

}
/*
// Timer/Counter1 Overflow
void __vector_9(void)     __attribute__((signal,used));
void __vector_9(void)
{
	//implementation
	if(TIMER.GPT_TIMER1_OVF!=NULL)
				{
				TIMER.GPT_TIMER1_OVF();
				}

}*/
// Timer/Counter0 Compare Match
void __vector_10(void)     __attribute__((signal,used));
void __vector_10(void)
{
	//implementation
	if(TIMER.GPT_TIMER0_COMP!=NULL)
			{
			TIMER.GPT_TIMER0_COMP();
			}

}

// Timer/Counter0 Overflow
void __vector_11(void)     __attribute__((signal,used));
void __vector_11(void)
{
	//implementation
	if(TIMER.GPT_TIMER0_OVF!=NULL)
			{
			TIMER.GPT_TIMER0_OVF();
			}

}
