/*
 * GPT_prv.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Mustafa
 */

#ifndef MCAL_GPT_GPT_PRV_H_
#define MCAL_GPT_GPT_PRV_H_

#define TCCR0_REG		(*(volatile u8*) 0X53)
#define TCNT0_REG		(*(volatile u8*) 0X52)
#define OCR0_REG		(*(volatile u8*) 0X5C)
#define TIMSK_REG		(*(volatile u8*) 0X59)
#define TIFR_REG		(*(volatile u8*) 0X58)

#define TCCR1A_REG		(*(volatile u8*) 0X4F)
#define TCCR1B_REG		(*(volatile u8*) 0X4E)
#define TCNT1_REG		(*(volatile u16*) 0X4C)    //RIGISTER 16 BIT     Timer/Counter1
#define  OCR1A_REG		(*(volatile u16*) 0X4A)    //RIGISTER 16 BIT     Output Compare Register 1 A
#define  OCR1B_REG		(*(volatile u16*) 0X48)    //RIGISTER 16 BIT     Output Compare Register 1 B
#define  ICR1_REG		(*(volatile u16*) 0X46)    //RIGISTER 16 BIT     Input Capture Register 1


#define TCCR2_REG		(*(volatile u8*) 0X45)
#define TCNT2_REG		(*(volatile u8*) 0X44)
#define OCR2_REG		(*(volatile u8*) 0X43)
#define ASSR_REG		(*(volatile u8*) 0X42)


#endif /* MCAL_GPT_GPT_PRV_H_ */
