/*
 * STEPPER_int.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Mohamed Essam
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_INT_H_
#define HAL_STEPPER_MOTOR_STEPPER_INT_H_


#include "STEPPER_cfg.h"




/************************************************************************************
                             	 	 ERROR STATUS
*************************************************************************************/
typedef enum{
	STEPPER_OK,
	STEPPER_NOK
}STEPPER_tenuErrorStatus;






/************************************************************************************
                             	 	 MACROS
*************************************************************************************/
/****** MACROS FOR ANGELS LIMITS ******/
#define STEPPER_f32_MIN_ANGLE						(4*STEPPER_f32_STEP_ANGLE)
#define STEPPER_f32_FULL_CYCLE_STEPS				(STEPPER_f32_MAX_ANGLE / STEPPER_f32_STEP_ANGLE)

#define STEPPER_f32_0DEGREE							0.00
#define STEPPER_f32_90DEGREE						90.00
#define STEPPER_f32_180DEGREE						180.00
#define STEPPER_f32_270DEGREE						270.00
#define STEPPER_f32_360DEGREE						360.00

/****** MACROS FOR DIRECTIONS ******/
#define STEPPER_u8_CLOCKWISE						0
#define STEPPER_u8_ANTI_CLOCKWISE					1





/************************************************************************************
                             FUNCTION DECLARATIONS
*************************************************************************************/
/*
 * Name: STEPPER_vidInit
 * Description: initialize the stepper motor pins
 * Arguments: void
 * Return:	void
 */
void STEPPER_vidInit(void);




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
											u8 Copy_u8YellowPort, u8 Copy_u8YellowPin, u8 Copy_u8OrangePort, u8 Copy_u8OrangePin);






/*
 *
*/
//STEPPER_tenuErrorStatus STEPPER_enuHalfStep(u8 Copy_u8Angle);


#endif /* HAL_STEPPER_MOTOR_STEPPER_INT_H_ */
