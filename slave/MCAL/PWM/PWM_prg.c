/*
 * PWM_prg.c
 *
 *    Created on: Sep 15, 2022
 *      Author: Mustafa
 */


#include "../../LIB/STD_Types.h"
#include "PWM_prv.h"
#include "PWM_int.h"




/* Name: PWM_vidInit
 * Description: initialize PWM
 * Arguments:            First argument: The desired Timer   options(PWM_u8_TIMER0,PWM_u8_TIMER1,PWM_u8_TIMER2)
 * 						 Second argument: The desired operation mode (wave generation form)
		  						 		options(
		  						 		1- PWM_u16_WAVE_FORM_FAST_PWM_8BIT
										2- PWM_u16_WAVE_FORM_FAST_PWM_9BIT
										3- PWM_u16_WAVE_FORM_FAST_PWM_10BIT
										4- PWM_u8_FAST_PWM_ICR1_TOP
										5- PWM_u8_FAST_PWM_OCR1A_TOP
										6- PWM_u8_WAVE_FORM_PWM_PASE_CORRECT_8BIT
										7- PWM_u8_WAVE_FORM_PWM_PASE_CORRECT_9BIT
										8- PWM_u8_WAVE_FORM_PWM_PASE_CORRECT_10BIT
										9- PWM_u8_WAVE_FORM_PWM_PASE_AND_FREQUENCY_CORRECT_ICR1_TOP
										10- PWM_u8_WAVE_FORM_PWM_PASE_AND_FREQUENCY_CORRECT_OCR1A_TOP
										11- PWM_u8_WAVE_FORM_PWM_PASE_CORRECT_ICR1_TOP
										12- PWM_u8_WAVE_FORM_PWM_PASE_CORRECT_OCR1A_TOP)
 * Return:	void
 */
void PWM_vidInit(u8 Copy_u8Timer, u8 Copy_u8Mode){
	u8 Local_u8_WGM_BIT = 0;
	switch (Copy_u8Timer){
		case PWM_u8_TIMER0:
			PWM_u8_TCCR0_REG |= Copy_u8Mode;
			break;
		case PWM_u8_TIMER1:
			Local_u8_WGM_BIT = (Copy_u8Mode) & (PWM_u8_WGM10);
			PWM_u8_TCCR1A |= Local_u8_WGM_BIT;
			Local_u8_WGM_BIT = (Copy_u8Mode) & (PWM_u8_WGM11);
			PWM_u8_TCCR1A |= Local_u8_WGM_BIT;
			Local_u8_WGM_BIT = (Copy_u8Mode) & (PWM_u8_WGM12);
			PWM_u8_TCCR1B |= Local_u8_WGM_BIT;
			Local_u8_WGM_BIT = (Copy_u8Mode) & (PWM_u8_WGM13);
			PWM_u8_TCCR1B |= Local_u8_WGM_BIT;
			break;
		 case PWM_u8_TIMER2:
			 PWM_u8_TCCR2_REG  |=0X48;
			 break;
	}
}






/* Name: PWM_vidStartTimer1
 * Description: initialize PWM
 * Arguments:            First argument: selected prescaler
 * 						 					option(
												1- PWM_u8_NO_CLOCK_SOURCE
												2- PWM_u8_NO_PRESCALER_1
												3- PWM_u8_NO_PRESCALER_8
												4- PWM_u8_NO_PRESCALER_64
												5- PWM_u8_NO_PRESCALER_256
												6- PWM_u8_NO_PRESCALER_1024
												7- PWM_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE
												8- PWM_EXTERNAL_CLOCK_SOURCE_RISING_EDGE)
 *						 Second argument: compare Value at which the generated form will change   options( value <= top value )
 *						 Third argument: top Value for Timer1
 *						 Fourth argument: compare output mode for pins OC0, OC1A, OC1B, OC2
 						 					option(
												1- PWM_u8_OC1A_DISCONNECTED
												2- PWM_u8_NON_INVERTING_MODE_0C1A
												3- PWM_u8_INVERTING_MODE_OC1A
												4- PWM_u8_OC1B_DISCONNECTED
												5- PWM_u8_NON_INVERTING_MODE_0C1B
												6- PWM_u8_INVERTING_MODE_OC1B)
 *						Last argument: to choose OC1A or OC1B   options(PWM_u8_OC1A, PWM_u8_OC1B)
 * Return:	void
 */
void PWM_vidStartTimer1(u8 Copy_u8Prescaler, u16 Copy_u16CompareValue, u16 Copy_u16TopValue,
						u8 Copy_u8CompareOutputMode, u8 Copy_u8DesiredPin){
	// set compare output mode
	PWM_u8_TCCR1A  |= Copy_u8CompareOutputMode;
	// check OC used pin and set the compare value in the conceder register
	if(Copy_u8DesiredPin == PWM_u8_OC1A){
		 PWM_u16_OCR1AL |= Copy_u16CompareValue;
	} else if (Copy_u8DesiredPin==PWM_u8_OC1B){
		PWM_u16_OCR1BL |= Copy_u16CompareValue;
	} else{ /*.....*/ }
	// top value to set frequency
	PWM_u16_ICR1L  |= Copy_u16TopValue;
	// set prescaler
	PWM_u8_TCCR1B  |=Copy_u8Prescaler;
}





/* Name: PWM_vidStop
 * Description: stop PWM signal
 * Arguments:            Copy_u8Timer: The desired Timer  options(PWM_u8_TIMER0, PWM_u8_TIMER1, PWM_u8_TIMER2)
 * Return:	void
 */
void PWM_vidStop(u8 Copy_u8Timer){
	switch (Copy_u8Timer){
		case PWM_u8_TIMER0:
			(PWM_u8_TCCR0_REG) &= (~PWM_u8_CS0);
			(PWM_u8_TCCR0_REG) &= (~PWM_u8_CS1);
			(PWM_u8_TCCR0_REG) &= (~PWM_u8_CS2);
			break;
		case PWM_u8_TIMER1:
			(PWM_u8_TCCR1B) &= (~PWM_u8_CS0);
			(PWM_u8_TCCR1B) &= (~PWM_u8_CS1);
			(PWM_u8_TCCR1B) &= (~PWM_u8_CS2);
			break;
		case PWM_u8_TIMER2:
			(PWM_u8_TCCR2_REG) &= (~PWM_u8_CS0);
			(PWM_u8_TCCR2_REG) &= (~PWM_u8_CS1);
			(PWM_u8_TCCR2_REG) &= (~PWM_u8_CS2);
			break;
	}
}
