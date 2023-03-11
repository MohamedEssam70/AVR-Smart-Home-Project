/*
 * EXT_INT_int.h
 *
 *  Created on: Sep 1, 2022
 *      Author: Mohamed Essam
 */

#ifndef MCAL_EXT_INT_EXT_INT_INT_H_
#define MCAL_EXT_INT_EXT_INT_INT_H_



/**************ERROR STATUS********************/

typedef enum {
	EXTI_OK,
	EXTI_NOK
}EXTI_tenuErrorStatus;




/******************MACROS***********************/
/* macros for interrupts pins options */
#define EXTI_u8_INT0							0
#define EXTI_u8_INT1							1
#define EXTI_u8_INT2							2

/* macros for interrupts sense control options */
#define EXTI_u8_LOW_LEVEL						0
#define EXTI_u8_LOGICAL_CHANGE					1
#define EXTI_u8_FALLING_EDGE					2
#define EXTI_u8_RISING_EDGE						3














/*************NEEDED FUNCTIONS*****************/

/* Name: EXTI_vidEnable
 * Description: activate the interrupt and select the interrupt sense control
 * Arguments: Arguments:
 * 				first Argument: Copy_u8ExtIntPin, 			options (INT0, INT1, INT2)
 * 				second Argument: Copy_u8SenseControl, 		options (EXTI_u8_LOW_LEVEL, EXTI_u8_LOGICAL_CHANGE,
																	EXTI_u8_FALLING_EDGE, EXTI_u8_RISING_EDGE)
 * Return:	void
 */
EXTI_tenuErrorStatus EXTI_vidEnable(u8 Copy_u8ExtIntPin, u8 Copy_u8SenseControl);




/* Name: EXTI_vidDisable
 * Description: activate the interrupt and select the interrupt sense control
 * Arguments: Arguments:
 * 				first Argument: Copy_u8ExtIntPin, 			options (INT0, INT1, INT2)																	EXTI_u8_FALLING_EDGE, EXTI_u8_RISING_EDGE)
 * Return:	void
 */
EXTI_tenuErrorStatus EXTI_vidDisable(u8 Copy_u8ExtIntPin);





#endif /* MCAL_EXT_INT_EXT_INT_INT_H_ */
