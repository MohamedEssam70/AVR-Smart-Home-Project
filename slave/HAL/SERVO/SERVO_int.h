/*
 * SERVO_int.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Mustafa
 */

#ifndef HAL_SERVO_SERVO_INT_H_
#define HAL_SERVO_SERVO_INT_H_



/************************************************************************************
                             	 	 ERROR STATUS
*************************************************************************************/
typedef enum
{
	SERVOMOTOR_OK,
	SERVOMOTOR_NOK
}SERVOMOTOR_tenuErrorStatus;



/************************************************************************************
                             	 	 MACROS
*************************************************************************************/
/****** MACROS FOR PWM CHANNELS ******/
#define SERVOMOTOR_u8_OC0															0
#define SERVOMOTOR_u8_OC1A															1
#define SERVOMOTOR_u8_OC1B															2
#define SERVOMOTOR_u8_OC2															3


/****** MACROS FOR TOP & COMPARE VALUES FOR FAMOUS ANGLES ******/
#define SERVOMOTOR_u16_TOP_VALUE													4999
#define SERVOMOTOR_u8_OCR_VALUE_FOR_ZERO_DEGREE										5
#define SERVOMOTOR_u8_OCR_VALUE_FOR_90_DEGREE										31
#define SERVOMOTOR_u8_OCR_VALUE_FOR_180_DEGREE										31
#define SERVOMOTOR_u8_ZERO_DEGREE													0
#define SERVOMOTOR_u8_90_DEGREE														90
#define SERVOMOTOR_u8_180_DEGREE													180





/************************************************************************************
                             FUNCTION DECLARATIONS
*************************************************************************************/
// servo motor set angle  // check if angle >180 , calculation


/*
 * Name: SERVOMOTOR_enuInit
 * Description: initialize the PWM channel
 * Arguments: Copy_u8PWMchannel	---->	options(SERVOMOTOR_u8_OC0, SERVOMOTOR_u8_OC1A, SERVOMOTOR_u8_OC1B, SERVOMOTOR_u8_OC2)
 * Return:	void
 */
void SERVOMOTOR_enuInit(u8 Copy_u8PWMchannel);



/*
 * Name: SERVOMOTOR_enuSetAngle
 * Description: rotate the motor by the angle user passed as argument
 * Arguments:	first Argument: Copy_u8Angle			OPTIONS --> (0 < angle < 180)
				second Argument: Copy_u8DesiredPin		OPTIONS --> (PWM_u8_OC1A , PWM_u8_OC1B)
 * Return:	Error Status -----> ServoMotor_OK , ServoMotor_NOK
 */
SERVOMOTOR_tenuErrorStatus SERVOMOTOR_enuSetAngle(u8 Copy_u8Angle, u8 Copy_u8PWMchannel);





//void SERVO_vidStopMotor(void);


#endif /* HAL_SERVO_SERVO_INT_H_ */
