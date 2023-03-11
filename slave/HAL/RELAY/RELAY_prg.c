/*
 * RELAY_prg.c
 *
 *  Created on: Sep 20, 2022
 *      Author: Mohamed Essam
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "RELAY_int.h"



/*
 * Name: RELAY_vidInit
 * Description: initialize RELAY control pin
 * Arguments: void
 * Return:	void
*/
void RELAY_vidInit(void){
	DIO_vidInit();
}




/*
 * Name: RELAY_vidSetNormallyClose
 * Description: relay connected on the normally close switch
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (RELAY_u8_PORTA, RELAY_u8_PORTB, RELAY_u8_PORTC, RELAY_u8_PORTD)
 * 				second Argument: Copy_u8Pin, 			options (from RELAY_u8_PIN0 to RELAY_u8_PIN7)
 * Return:	void
*/
void RELAY_vidSetNormallyClose(u8 Copy_u8ControlPort, u8 Copy_u8ControlPin){
	DIO_enuSetPinValue(Copy_u8ControlPort, Copy_u8ControlPin, RELAY_u8_NORMALLY_CLOSE);
}



/*
 * Name: RELAY_vidSetNormallyOpen
 * Description: relay connected on the normally open switch
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (RELAY_u8_PORTA, RELAY_u8_PORTB, RELAY_u8_PORTC, RELAY_u8_PORTD)
 * 				second Argument: Copy_u8Pin, 			options (from RELAY_u8_PIN0 to RELAY_u8_PIN7)
 * Return:	void
*/
void RELAY_vidSetNormallyOpen(u8 Copy_u8ControlPort, u8 Copy_u8ControlPin){
	DIO_enuSetPinValue(Copy_u8ControlPort, Copy_u8ControlPin, RELAY_u8_NORMALLY_OPEN);
}
