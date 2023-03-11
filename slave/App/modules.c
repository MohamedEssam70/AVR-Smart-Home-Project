/*
 * modules.c
 *
 *  Created on: Sep 20, 2022
 *      Author: Mohamed Essam
 */


#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Utils.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXT_INT/EXT_INT_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../HAL/RELAY/RELAY_int.h"
#include "../HAL/STEPPER MOTOR/STEPPER_int.h"
#include "modules.h"



/*
 * Name: MODULE_vidGarageDoor
 * Description: setting garage door control method
 * Arguments:	first argument:  Copy_u8ControlMethod  ---->  options(GARAGE_MANUAL, GARAGE_AUTO)
 * 				second argument: Copy_u8DoorState  ---->  options(GARAGE_CLOSE, GARAGE_OPEN, GARAGE_DONT_CARE)
 * Return:	void
*/
void MODULE_vidGarageDoor(u8 Copy_u8ControlMethod, u8 Copy_u8DoorState){
	switch(Copy_u8ControlMethod){
		case GARAGE_MANUAL:
			RELAY_vidSetNormallyOpen(RELAY_u8_PORTD, RELAY_u8_PIN1);
			if(Copy_u8DoorState == GARAGE_CLOSE){
				DIO_enuSetPinValue(DIO_u8_PORTD,DIO_u8_PIN6,DIO_u8_LOW);
			} else if(Copy_u8DoorState == GARAGE_OPEN){
				DIO_enuSetPinValue(DIO_u8_PORTD,DIO_u8_PIN6,DIO_u8_HIGH);
			} else { /*.....*/ }
			break;
		case GARAGE_AUTO:
			RELAY_vidSetNormallyClose(RELAY_u8_PORTD, RELAY_u8_PIN1);
			break;
	}

}




/*
 * Name: MODULE_vidGarageDoor
 * Description: setting garage door control method
 * Arguments:	first argument:  Copy_u8ControlMethod  ---->  options(GARAGE_MANUAL, GARAGE_AUTO)
 * 				second argument: Copy_u8DoorState  ---->  options(GARAGE_CLOSE, GARAGE_OPEN, GARAGE_DONT_CARE)
 * Return:	void
*/
void MODULE_vidTemperatureInit(u8 Copy_u8ADC_read, u8 Copy_u8InstantinusDegree){
//	ADC_enuEnableADC(ADC_u8_START_CONVERSION, ADC_u8_INT_DISABLE, ADC_u8_PRESCALER_64);
	ADC_enuConversionResult(&Copy_u8ADC_read);
	Copy_u8InstantinusDegree = (Copy_u8ADC_read * 4.88);
	Copy_u8InstantinusDegree = (Copy_u8InstantinusDegree / 10.0);
}

