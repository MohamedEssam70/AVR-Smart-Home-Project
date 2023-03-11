/*
 * STEPPER_prg.c
 *
 *  Created on: Aug 31, 2022
 *      Author: Mohamed Essam
 */


#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "STEPPER_int.h"


/*
 * Name: STEPPER_vidInit
 * Description: initialize the stepper motor pins
 * Arguments: void
 * Return:	void
 */
void STEPPER_vidInit(void){
	DIO_vidInit();
}




/*
 * Name: STEPPER_enuFullStep
 * Description: rotate the stepper motor to the desert angle
 * 				F(stepper) = 100 Hz
 * 				T(stepper) = 10 ms
 * 				Step angel set in config file
 * 				Number of steps in full cycle = max angle / step angle = 360 /
 * 				Number of steps in the required angle:				Max angle   ------> 	No. of steps in full cycle
 * 																	Angle 		------> 	No. of steps
 * 																	No. of steps = (Angle*No. of steps in full cycle)/Max angle
 * Arguments:	first argument: Copy_f32Angle	---->  options( min angle < desert angle < max angle )
 * 				second argument: Copy_u8Direction  --->  options(STEPPER_u8_CLOCKWISE, STEPPER_u8_ANTI_CLOCKWISE)
 * 				third argument: Copy_u8BluePort  --->  options(DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD)
 * 				fourth argument: Copy_u8BluePin  --->  options(DIO_u8_PIN0, DIO_u8_PIN1, DIO_u8_PIN2, DIO_u8_PIN3, DIO_u8_PIN4, DIO_u8_PIN5, DIO_u8_PIN6, DIO_u8_PIN7)
 * 				fifth argument: Copy_u8PinkPort  --->  options(DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD)
 * 				fourth argument: Copy_u8PinkPin  --->  options(DIO_u8_PIN0, DIO_u8_PIN1, DIO_u8_PIN2, DIO_u8_PIN3, DIO_u8_PIN4, DIO_u8_PIN5, DIO_u8_PIN6, DIO_u8_PIN7)
 * 				seventh argument: Copy_u8YellowPort  --->  options(DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD)
 * 				eighth argument: Copy_u8YellowPin  --->  options(DIO_u8_PIN0, DIO_u8_PIN1, DIO_u8_PIN2, DIO_u8_PIN3, DIO_u8_PIN4, DIO_u8_PIN5, DIO_u8_PIN6, DIO_u8_PIN7)
 * 				ninth argument: Copy_u8OrangePort  --->  options(DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD)
 * 				last argument: Copy_u8OrangePin  --->  options(DIO_u8_PIN0, DIO_u8_PIN1, DIO_u8_PIN2, DIO_u8_PIN3, DIO_u8_PIN4, DIO_u8_PIN5, DIO_u8_PIN6, DIO_u8_PIN7)
 * Return:	STEPPER_tenuErrorStatus		----->   STEPPER_OK, STEPPER_NOK
 * */


STEPPER_tenuErrorStatus STEPPER_enuFullStep(f32 Copy_f32Angle, u8 Copy_u8Direction,
											u8 Copy_u8BluePort, u8 Copy_u8BluePin, u8 Copy_u8PinkPort, u8 Copy_u8PinkPin,
											u8 Copy_u8YellowPort, u8 Copy_u8YellowPin, u8 Copy_u8OrangePort, u8 Copy_u8OrangePin){

	STEPPER_tenuErrorStatus Local_enuErrorStatus = STEPPER_OK;

	switch(Copy_u8Direction){
		case STEPPER_u8_CLOCKWISE:
			if(Copy_f32Angle == STEPPER_f32_0DEGREE){
				DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_HIGH);
				DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_HIGH);
				DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_LOW);
			} else if(Copy_f32Angle == STEPPER_f32_90DEGREE){
				DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_HIGH);
				DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_HIGH);
			} else if(Copy_f32Angle == STEPPER_f32_180DEGREE){
				DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_HIGH);
				DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_HIGH);
				_delay_ms(10);
				DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_HIGH);
				DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_HIGH);
			} else{ /*......*/ }
			break;
		case STEPPER_u8_ANTI_CLOCKWISE:
			if(Copy_f32Angle == STEPPER_f32_0DEGREE){
				DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_HIGH);
				DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_HIGH);
				DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_LOW);
			} else if(Copy_f32Angle == STEPPER_f32_90DEGREE){
				DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_HIGH);
				DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_HIGH);
			} else if(Copy_f32Angle == STEPPER_f32_180DEGREE){
				DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_HIGH);
				DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_HIGH);
				_delay_ms(10);
				DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_HIGH);
				DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_LOW);
				DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_HIGH);
			} else{ /*......*/ }
			break;
		}
/*
	f32 Local_f32Iteration;
	f32 Local_f32Steps = 0.0;
	// check arguments
	if((Copy_f32Angle < STEPPER_f32_MIN_ANGLE) || (Copy_u8Direction > STEPPER_u8_ANTI_CLOCKWISE)){
		Local_enuErrorStatus = STEPPER_NOK;
	} else{
	// Implementation
		Local_f32Steps = ((Copy_f32Angle * STEPPER_f32_FULL_CYCLE_STEPS) / STEPPER_f32_MAX_ANGLE);
		switch(Copy_u8Direction){
			case STEPPER_u8_CLOCKWISE:
				for(Local_f32Iteration = 0.0; Local_f32Iteration < (Local_f32Steps / 4); Local_f32Iteration ++){
					DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_HIGH);
					DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_LOW);
					_delay_ms(10);
					DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_HIGH);
					DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_LOW);
					_delay_ms(10);
					DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_HIGH);
					DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_LOW);
					_delay_ms(10);
					DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_HIGH);
					_delay_ms(10);
				}
				break;
			case STEPPER_u8_ANTI_CLOCKWISE:
				for(Local_f32Iteration = 0.0; Local_f32Iteration < (Local_f32Steps / 4); Local_f32Iteration ++){
					DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_HIGH);
					DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_LOW);
					_delay_ms(10);
					DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_HIGH);
					DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_LOW);
					_delay_ms(10);
					DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_HIGH);
					DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_LOW);
					_delay_ms(10);
					DIO_enuSetPinValue(Copy_u8OrangePort, Copy_u8OrangePin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8YellowPort, Copy_u8YellowPin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8PinkPort, Copy_u8PinkPin, DIO_u8_LOW);
					DIO_enuSetPinValue(Copy_u8BluePort, Copy_u8BluePin, DIO_u8_HIGH);
					_delay_ms(10);
				}
				break;
			default:
				break;
		}
	}*/
	return Local_enuErrorStatus;
}







