/*
 * LED_int.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Mohamed Essam
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_



/**************ERROR STATUS********************/
typedef enum {
	LED_OK,
	LED_NOK
}LED_tenuErrorStatus;





/******************MACROS***********************/
/* macros for ports */
#define LED_u8_PORTA		0
#define LED_u8_PORTB		1
#define LED_u8_PORTC		2
#define LED_u8_PORTD		3

/* macros for pins */
#define LED_u8_PIN0			0
#define LED_u8_PIN1			1
#define LED_u8_PIN2			2
#define LED_u8_PIN3			3
#define LED_u8_PIN4			4
#define LED_u8_PIN5			5
#define LED_u8_PIN6			6
#define LED_u8_PIN7			7

/* macros for value */
#define LED_u8_OFF			DIO_u8_LOW
#define LED_u8_ON			DIO_u8_HIGH




/****************FUNCTIONS******************/
/*
 * Name: LED_enuTurnOn
 * Description: Turn on a single LED
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (LED_u8_PORTA, LED_u8_PORTB, LED_u8_PORTC, LED_u8_PORTD)
 * 				second Argument: Copy_u8Pin, 			options (from LED_u8_PIN0 to LED_u8_PIN7)
 * Return:	Error Status -----> LED_OK , LED_NOK
*/
LED_tenuErrorStatus LED_enuTurnOn(u8 Copy_u8LEDPort, u8 Copy_u8LEDPin);



/*
 * Name: LED_enuTurnOff
 * Description: Turn off a single LED
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (LED_u8_PORTA, LED_u8_PORTB, LED_u8_PORTC, LED_u8_PORTD)
 * 				second Argument: Copy_u8Pin, 			options (from LED_u8_PIN0 to LED_u8_PIN7)
 * Return:	Error Status -----> LED_OK , LED_NOK
*/
LED_tenuErrorStatus LED_enuTurnOff(u8 Copy_u8LEDPort, u8 Copy_u8LEDPin);



/*
 * Name: LED_enuToggleLED
 * Description: Turn off a single LED
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (LED_u8_PORTA, LED_u8_PORTB, LED_u8_PORTC, LED_u8_PORTD)
 * 				second Argument: Copy_u8Pin, 			options (from LED_u8_PIN0 to LED_u8_PIN7)
 * Return:	Error Status -----> LED_OK , LED_NOK
*/
LED_tenuErrorStatus LED_enuToggleLED(u8 Copy_u8LEDPort, u8 Copy_u8LEDPin);



#endif /* HAL_LED_LED_INT_H_ */
