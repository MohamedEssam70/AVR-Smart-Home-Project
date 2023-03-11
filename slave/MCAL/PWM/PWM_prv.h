/*
 * PWM_prv.h
 *
 *   Created on: Sep 15, 2022
 *      Author: Mustafa
 */

#ifndef MCAL_PWM_PWM_PRV_H_
#define MCAL_PWM_PWM_PRV_H_




/************** TIMER 0 **************/
#define PWM_u8_TIMSK_REG      				(*(volatile u8*)0X59)
#define PWM_u8_TCCR0_REG      				(*(volatile u8*)0X53)
#define PWM_u8_TCNT0_REG      				(*(volatile u8*)0X52)
#define PWM_u8_OCR0_REG      				(*(volatile u8*)0X5C)


/************** TIMER 1 **************/
#define PWM_u8_TCCR1A      					(*(volatile u8*)0X4F)
#define PWM_u8_TCCR1B     					(*(volatile u8*)0X4E)
#define PWM_u16_TCNT1L						(*(volatile u16*)0x4C)//Timer/Counter1 Counter Register Low Byte
#define PWM_u16_OCR1AL						(*(volatile u16*)0X4A)//Timer/Counter1 Output Compare Register A Low Byte
#define PWM_u16_OCR1BL						(*(volatile u16*)0X48)//Timer/Counter1 Output Compare Register B Low Byte
#define PWM_u16_ICR1L						(*(volatile u16*)0X46)//Timer/Counter1 Input Capture Register Low Byte


/************** TIMER 2 **************/
#define PWM_u8_TCCR2_REG      				(*(volatile u8*)0X45)
#define PWM_u8_TCNT2_REG      				(*(volatile u8*)0X44)
#define PWM_u8_OCR2_REG      				(*(volatile u8*)0X43)







#endif /* MCAL_PWM_PWM_PRV_H_ */
