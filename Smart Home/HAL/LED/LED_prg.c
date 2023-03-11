/*
 * LED_prg.c
 *
 *  Created on: Aug 28, 2022
 *      Author: Mohamed Essam
 */

#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LED_int.h"





/*
 * Name: LED_vidInit
 * Description: initialize LEDs status
 * Arguments: void
 * Return:	void
*/
void LED_vidInit(void){
	DIO_vidInit();
}



/*
 * Name: LED_enuTurnOn
 * Description: Turn on a single LED
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (LED_u8_PORTA, LED_u8_PORTB, LED_u8_PORTC, LED_u8_PORTD)
 * 				second Argument: Copy_u8Pin, 			options (from LED_u8_PIN0 to LED_u8_PIN7)
 * Return:	Error Status -----> LED_OK , LED_NOK
*/
LED_tenuErrorStatus LED_enuTurnOn(u8 Copy_u8LEDPort, u8 Copy_u8LEDPin){
	LED_tenuErrorStatus Local_enuErrorStatus = LED_OK;
	/*check arguments*/
	if ((Copy_u8LEDPort > LED_u8_PORTD) || (Copy_u8LEDPin > LED_u8_PIN7)){
		Local_enuErrorStatus = LED_NOK;
	} else {
	/*****IMPLEMENTATION*****/
		DIO_enuSetPinValue(Copy_u8LEDPort, Copy_u8LEDPin, LED_u8_ON);
	}
	return Local_enuErrorStatus;
}





/*
 * Name: LED_enuTurnOff
 * Description: Turn off a single LED
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (LED_u8_PORTA, LED_u8_PORTB, LED_u8_PORTC, LED_u8_PORTD)
 * 				second Argument: Copy_u8Pin, 			options (from LED_u8_PIN0 to LED_u8_PIN7)
 * Return:	Error Status -----> LED_OK , LED_NOK
*/
LED_tenuErrorStatus LED_enuTurnOff(u8 Copy_u8LEDPort, u8 Copy_u8LEDPin){
	LED_tenuErrorStatus Local_enuErrorStatus = LED_OK;
	/*check arguments*/
	if ((Copy_u8LEDPort > LED_u8_PORTD) || (Copy_u8LEDPin > LED_u8_PIN7)){
		Local_enuErrorStatus = LED_NOK;
	} else {
	/*****IMPLEMENTATION*****/
		DIO_enuSetPinValue(Copy_u8LEDPort, Copy_u8LEDPin, LED_u8_OFF);
	}
	return Local_enuErrorStatus;
}





/*
 * Name: LED_enuToggleLED
 * Description: Turn off a single LED
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (LED_u8_PORTA, LED_u8_PORTB, LED_u8_PORTC, LED_u8_PORTD)
 * 				second Argument: Copy_u8Pin, 			options (from LED_u8_PIN0 to LED_u8_PIN7)
 * Return:	Error Status -----> LED_OK , LED_NOK
*/
LED_tenuErrorStatus LED_enuToggleLED(u8 Copy_u8LEDPort, u8 Copy_u8LEDPin){
	LED_tenuErrorStatus Local_enuErrorStatus = LED_OK;
	u8 Local_u8LEDstatus;
	/*check arguments*/
	if ((Copy_u8LEDPort > LED_u8_PORTD) || (Copy_u8LEDPin > LED_u8_PIN7)){
		Local_enuErrorStatus = LED_NOK;
	} else {
	/*****IMPLEMENTATION*****/
		DIO_enuGetPinValue(Copy_u8LEDPort, Copy_u8LEDPin, &Local_u8LEDstatus);
		switch(Local_u8LEDstatus){
		case LED_u8_OFF:
			DIO_enuSetPinValue(Copy_u8LEDPort, Copy_u8LEDPin, LED_u8_ON);
			break;
		case LED_u8_ON:
			DIO_enuSetPinValue(Copy_u8LEDPort, Copy_u8LEDPin, LED_u8_OFF);
			break;
		default:
			break;
		}
	}
	return Local_enuErrorStatus;
}



