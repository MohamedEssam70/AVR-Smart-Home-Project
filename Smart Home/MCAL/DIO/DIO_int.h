/*
 * DIO_int.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Mohamed Essam
 */

#ifndef MCAL_DIO_INT_H_
#define MCAL_DIO_INT_H_


#include "DIO_cfg.h"


/**************ERROR STATUS********************/

typedef enum {
	DIO_OK,
	DIO_NOK
}DIO_tenuErrorStatus;




/******************MACROS***********************/

/* macros for ports */
#define DIO_u8_PORTA		0
#define DIO_u8_PORTB		1
#define DIO_u8_PORTC		2
#define DIO_u8_PORTD		3

/* macros for pins */
#define DIO_u8_PIN0			0
#define DIO_u8_PIN1			1
#define DIO_u8_PIN2			2
#define DIO_u8_PIN3			3
#define DIO_u8_PIN4			4
#define DIO_u8_PIN5			5
#define DIO_u8_PIN6			6
#define DIO_u8_PIN7			7

/* macros for value */
#define DIO_u8_LOW			0
#define DIO_u8_HIGH			1











/*************NEEDED FUNCTIONS*****************/

/* Name: DIO_vidInit
 * Description: initialize all the MC pins according to "DIO_cfg.h"
 * Arguments: void
 * Return:	void
 */
void DIO_vidInit(void);




/* Name: DIO_enuSetPinValue
 * Description: assign the desired value to desired pin
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD)
 * 				second Argument: Copy_u8Pin, 			options (from DIO_u8_PIN0 to DIO_u8_PIN7)
 * 				third Argument: Copy_u8Value, 			options (DIO_u8_HIGH, DIO_u8_LOW)
 * Return:	Error Status -----> DIO_OK , DIO_NOK
 */
DIO_tenuErrorStatus DIO_enuSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);



/* Name: DIO_enuSetPortValue
 * Description: assign the desired value to desired port
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD)
 * 				second Argument: Copy_u8Value, 			options (any macro refer to hixa_number)
 * Return:	Error Status -----> DIO_OK , DIO_NOK
 */
DIO_tenuErrorStatus DIO_enuSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);




/* Name: DIO_enuGetPinValue
 * Description: get the desired pin value
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD)
 * 				second Argument: Copy_u8Pin,			options (from DIO_u8_PIN0 to DIO_u8_PIN7)
 * 				third Argument: variable address to store PORT value
 * Return:	Error Status -----> DIO_OK , DIO_NOK
 */
DIO_tenuErrorStatus DIO_enuGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Add_pu8PinValue);




/* Name: DIO_enuGetPortValue
 * Description: get the desired port value
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD)
 * 				second Argument: variable address to store PORT value
 * Return:	Error Status -----> DIO_OK , DIO_NOK
 */
DIO_tenuErrorStatus DIO_enuGetPortValue(u8 Copy_u8Port, u8 *Add_pu8PortValue);



#endif /* MCAL_DIO_INT_H_ */
