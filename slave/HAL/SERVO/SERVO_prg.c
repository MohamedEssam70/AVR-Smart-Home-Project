/*
 * SERVO_prg.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Mustafa
 */



#include <util/delay.h>
#include "../../LIB./STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "../../MCAL/PWM/PWM_int.h"
#include "SERVO_int.h"




/*
 * Name: SERVOMOTOR_enuInit
 * Description: initialize the PWM channel
 * Arguments: Copy_u8PWMchannel	---->	options(SERVOMOTOR_u8_OC0, SERVOMOTOR_u8_OC1A, SERVOMOTOR_u8_OC1B, SERVOMOTOR_u8_OC2)
 * Return:	void
 */
void SERVOMOTOR_enuInit(u8 Copy_u8PWMchannel){
	switch(Copy_u8PWMchannel){
			case SERVOMOTOR_u8_OC0:
				break;
			case SERVOMOTOR_u8_OC1A:
				PWM_vidInit(PWM_u8_TIMER1, PWM_u8_FAST_PWM_ICR1_TOP);
				break;
			case SERVOMOTOR_u8_OC1B:
				PWM_vidInit(PWM_u8_TIMER1, PWM_u8_FAST_PWM_ICR1_TOP);
				break;
			case SERVOMOTOR_u8_OC2:
				break;
			default:
				break;
		}
}
/*
 * Name: SERVOMOTOR_enuSetAngle
 * Description: rotate the motor by the angle user passed as argument
 * Arguments:	first Argument: Copy_u8Angle			OPTIONS --> (0 < angle < 180)
				second Argument: Copy_u8DesiredPin		OPTIONS --> (PWM_u8_OC1A , PWM_u8_OC1B)
 * Return:	Error Status -----> ServoMotor_OK , ServoMotor_NOK
 */
SERVOMOTOR_tenuErrorStatus SERVOMOTOR_enuSetAngle(u8 Copy_u8Angle, u8 Copy_u8PWMchannel){
	SERVOMOTOR_tenuErrorStatus Local_enuErrorStatus = SERVOMOTOR_OK;
	if (Copy_u8Angle > 180   || Copy_u8PWMchannel > SERVOMOTOR_u8_OC2){
		Local_enuErrorStatus = SERVOMOTOR_NOK;
	} else{
		/*
		 * the timer will count from 0 to ICR1(TOP Value). The formula for PWM frequency and calculation for TOP value is
		 * Fpwm = Fcpu/N(1+TOP) = 16000000/64(1+TOP) ---> TOP = 4999
		 * So we set up ICR1A=4999, this gives us PWM period of 20ms (50 Hz).
		 *
		 * a positive relationship between the angle and duty cycle... then, the slope is 25/18
		 * so the equation that determine output compare value will be ---> Duty = 250 + (25/18)Angle
		 * */
		u16 Local_u16OCRvalue = ((250) + ((25/18) * (u16)Copy_u8Angle));
		if(Copy_u8PWMchannel == SERVOMOTOR_u8_OC1A){
			//if(Copy_u8Angle == )
		//	PWM_vidStartTimer1(PWM_u8_NO_PRESCALER_64, Local_u16OCRvalue, SERVOMOTOR_u16_TOP_VALUE, PWM_u8_NON_INVERTING_MODE_0C1A, PWM_u8_OC1A);
			switch(Copy_u8Angle){
				case SERVOMOTOR_u8_ZERO_DEGREE:
					PWM_vidStartTimer1(PWM_u8_NO_PRESCALER_64, SERVOMOTOR_u8_OCR_VALUE_FOR_ZERO_DEGREE, SERVOMOTOR_u16_TOP_VALUE, PWM_u8_NON_INVERTING_MODE_0C1A, PWM_u8_OC1A);
					break;
				case SERVOMOTOR_u8_90_DEGREE:
					PWM_vidStartTimer1(PWM_u8_NO_PRESCALER_64, SERVOMOTOR_u8_OCR_VALUE_FOR_90_DEGREE, SERVOMOTOR_u16_TOP_VALUE, PWM_u8_NON_INVERTING_MODE_0C1A, PWM_u8_OC1A);
					break;
				case SERVOMOTOR_u8_180_DEGREE:
					PWM_vidStartTimer1(PWM_u8_NO_PRESCALER_64, SERVOMOTOR_u8_OCR_VALUE_FOR_180_DEGREE, SERVOMOTOR_u16_TOP_VALUE, PWM_u8_NON_INVERTING_MODE_0C1A, PWM_u8_OC1A);
					break;
				default:
					break;
			}

		} else if(Copy_u8PWMchannel == SERVOMOTOR_u8_OC1B){
		//	PWM_vidStartTimer1(PWM_u8_NO_PRESCALER_64, Local_u16OCRvalue, SERVOMOTOR_u16_TOP_VALUE, PWM_u8_NON_INVERTING_MODE_0C1B, PWM_u8_OC1B);
			switch(Copy_u8Angle){
				case SERVOMOTOR_u8_ZERO_DEGREE:
					PWM_vidStartTimer1(PWM_u8_NO_PRESCALER_64, SERVOMOTOR_u8_OCR_VALUE_FOR_ZERO_DEGREE, SERVOMOTOR_u16_TOP_VALUE, PWM_u8_NON_INVERTING_MODE_0C1B, PWM_u8_OC1B);
					break;
				case SERVOMOTOR_u8_90_DEGREE:
					PWM_vidStartTimer1(PWM_u8_NO_PRESCALER_64, SERVOMOTOR_u8_OCR_VALUE_FOR_90_DEGREE, SERVOMOTOR_u16_TOP_VALUE, PWM_u8_NON_INVERTING_MODE_0C1B, PWM_u8_OC1B);
					break;
				case SERVOMOTOR_u8_180_DEGREE:
					PWM_vidStartTimer1(PWM_u8_NO_PRESCALER_64, SERVOMOTOR_u8_OCR_VALUE_FOR_180_DEGREE, SERVOMOTOR_u16_TOP_VALUE, PWM_u8_NON_INVERTING_MODE_0C1B, PWM_u8_OC1B);
					break;
				default:
					break;
			}
		} else{
			Local_enuErrorStatus = SERVOMOTOR_NOK;
		}
	}
	return Local_enuErrorStatus;
}

/*
void SERVO_vidStopMotor(Copy_u8PWMchannel){
	SERVOMOTOR_enuSetAngle(u8 Copy_u8Angle, u8 Copy_u8PWMchannel)
}*/
