/*
 * PWM_int.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Mustafa
 */

#ifndef MCAL_PWM_PWM_INT_H_
#define MCAL_PWM_PWM_INT_H_



/************************************************************************************
                             	 	 ERROR STATUS
*************************************************************************************/
/*typedef enum
{
	PWM_OK,
	PWM_NOK
}PWM_tenuErrorStatus;
*/




/************************************************************************************
                             	 	 MACROS
*************************************************************************************/
/****** MACROS FOR TIMERS ******/
#define PWM_u8_TIMER0														0
#define PWM_u8_TIMER1														1
#define PWM_u8_TIMER2														2


/****** MACROS FOR OUTPUT COMPARE PINS ******/
#define PWM_u8_OC0															0
#define PWM_u8_OC1A															1
#define PWM_u8_OC1B															2
#define PWM_u8_OC2															3


/****** COMPARE OUTPUT MODE OPTIONS ******/
// macros for Compare Output Mode, Fast PWM Mode (0C0) and (0C2)
#define PWM_u8_DISCONNECTED													0X00
#define PWM_u8_NON_INVERTING_MODE											0X20
#define PWM_u8_INVERTING_MODE												0X30
// macros for Compare Output Mode, Fast PWM (OC1A)
#define PWM_u8_OC1A_DISCONNECTED											0X00
#define PWM_u8_NON_INVERTING_MODE_0C1A										0X80
#define PWM_u8_INVERTING_MODE_OC1A											0XC0
// macros for Compare Output Mode, Fast PWM (OC1B)
#define PWM_u8_OC1B_DISCONNECTED											0X00
#define PWM_u8_NON_INVERTING_MODE_0C1B										0X20
#define PWM_u8_INVERTING_MODE_OC1B											0X30


/****** WAVE GENERATION FORM OPTIONS ******/
// macros for Operation modes for TIMER1
#define PWM_u8_FAST_PWM_ICR1_TOP											0X1A
#define PWM_u8_FAST_PWM_OCR1A_TOP											0x1B
#define PWM_u8_WAVE_FORM_FAST_PWM_8BIT										0x09
#define PWM_u8_WAVE_FORM_FAST_PWM_9BIT										0x0A
#define PWM_u8_WAVE_FORM_FAST_PWM_10BIT										0x0B
#define PWM_u8_WAVE_FORM_PWM_PASE_CORRECT_8BIT								0x01
#define PWM_u8_WAVE_FORM_PWM_PASE_CORRECT_9BIT								0x02
#define PWM_u8_WAVE_FORM_PWM_PASE_CORRECT_10BIT								0x03
#define	PWM_u8_WAVE_FORM_PWM_PASE_AND_FREQUENCY_CORRECT_ICR1_TOP			0x10
#define PWM_u8_WAVE_FORM_PWM_PASE_AND_FREQUENCY_CORRECT_OCR1A_TOP			0x11
#define PWM_u8_WAVE_FORM_PWM_PASE_CORRECT_ICR1_TOP							0x12
#define PWM_u8_WAVE_FORM_PWM_PASE_CORRECT_OCR1A_TOP							0x13
// macros for Operation modes for TIMER0 and TIMER2
#define PWM_u8_Fast_PWM_MODE												0X48
#define PWM_u8_Phase_CORRECT_MODE											0X40


/****** PRESCALER OPTIONS ******/
// macros for prescaler
#define PWM_u8_NO_CLOCK_SOURCE												0X00
#define PWM_u8_NO_PRESCALER_1												0X01
#define PWM_u8_NO_PRESCALER_8												0X02
#define PWM_u8_NO_PRESCALER_64												0X03
#define PWM_u8_NO_PRESCALER_256												0X04
#define PWM_u8_NO_PRESCALER_1024											0X05
#define PWM_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE								0X06
#define PWM_EXTERNAL_CLOCK_SOURCE_RISING_EDGE								0X07


/****** WGM BITS ******/
#define PWM_u8_WGM10														0X01
#define PWM_u8_WGM11														0X01<<1
#define PWM_u8_WGM12														0X01<<3
#define PWM_u8_WGM13														0X01<<4


/****** CLOCK SOURCE ******/
#define PWM_u8_CS0															(1<<0)
#define PWM_u8_CS1															(1<<1)
#define PWM_u8_CS2															(1<<2)


/************************************************************************************
                             FUNCTION DECLARATIONS
*************************************************************************************/
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
void PWM_vidInit(u8 Copy_u8Timer, u8 Copy_u8Mode);




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
						u8 Copy_u8CompareOutputMode, u8 Copy_u8DesiredPin);



/* Name: PWM_vidStop
 * Description: stop PWM signal
 * Arguments:            Copy_u8Timer: The desired Timer  options(PWM_u8_TIMER0, PWM_u8_TIMER1, PWM_u8_TIMER2)
 * Return:	void
 */
void PWM_vidStop(u8 Copy_u8Timer);


#endif /* MCAL_PWM_PWM_INT_H_ */
