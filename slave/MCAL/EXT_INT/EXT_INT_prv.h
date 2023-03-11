/*
 * EXT_INT_prv.h
 *
 *  Created on: Sep 3, 2022
 *      Author: Mohamed Essam
 */

#ifndef MCAL_EXT_INT_EXT_INT_PRV_H_
#define MCAL_EXT_INT_EXT_INT_PRV_H_



/**********REGISTER ADDRESSES************/
/*MCUCR*/
#define EXTI_u8_MCUCR_REG			(*(volatile u8*)0x55)
/*MCUCSR*/
#define EXTI_u8_MCUCSR_REG			(*(volatile u8*)0x54)
/*GICR*/
#define EXTI_u8_GICR_REG			(*(volatile u8*)0x5B)
/*GICR*/
#define EXTI_u8_GIFR_REG			(*(volatile u8*)0x5A)





/**************INT0 SENSE CONTROL (MCUCR REG OPTIONS)***************/
#define EXTI_INT0_LOW_LEVEL						0x00
#define EXTI_INT0_LOGIC_CHANGE					0x01
#define EXTI_INT0_FALLING_EDGE					0x02
#define EXTI_INT0_RISING_EDGE					0x03


/**************INT1 SENSE CONTROL (MCUCR REG OPTIONS)***************/
#define EXTI_INT1_LOW_LEVEL						0x00
#define EXTI_INT1_LOGIC_CHANGE					0x04
#define EXTI_INT1_FALLING_EDGE					0x08
#define EXTI_INT1_RISING_EDGE					0x0C


/**************INT2 SENSE CONTROL (MCUCSR REG OPTIONS)***************/
#define EXTI_INT2_FALLING_EDGE					0x00
#define EXTI_INT2_RISING_EDGE					0x40



/**************ENABLE INTERRUPTS (GICR REG OPTIONS)***************/
#define EXTI_INABLE_INT0_INTERRUPT				0x40
#define EXTI_INABLE_INT1_INTERRUPT				0x80
#define EXTI_INABLE_INT2_INTERRUPT				0x20




#endif /* MCAL_EXT_INT_EXT_INT_PRV_H_ */
