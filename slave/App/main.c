/*
 * STD_Types.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Mohamed Essam
 */


#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Utils.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/PWM/PWM_int.h"
#include "../MCAL/SPI/SPI_int.h"
#include "../MCAL/EXT_INT/EXT_INT_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/GPT/GPT_int.h"
#include "../HAL/LED/LED_int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "../HAL/SERVO/SERVO_int.h"
#include "../HAL/STEPPER MOTOR/STEPPER_int.h"
#include "../HAL/RELAY/RELAY_int.h"
#include "main.h"
#include "MACROS_SPI.h"
#include "modules.h"


void temperatureActiv(void);

/**************** GLOBAL Variables ****************/
u8 u8SPIrequest = DONT_CARE;	//create a variable to get the data send by SPI from the master
u8 u8InstantinusDegree;
u8 u8ADC_read;
volatile static u8 u8TempMax = 30;
volatile static u8 u8TempMin = 20;
volatile f32 celsius;
volatile u8 Local;

void main(void) {
	/**************** LOCAL VARIABLE ****************/
	u8 Local_u8_MastarDoorStatus = ROOM_DOOR_LOCKED;
	u8 Local_u8_TenantDoorStatus = ROOM_DOOR_LOCKED;
	u8 Local_u8_MastarLightStatus = ROOM_LIHGT_OFF;
	u8 Local_u8_TenantLightStatus = ROOM_LIHGT_OFF;

	/**************** INITIALIZE ****************/
	SPI_vidSPIInitSlave();
	LED_vidInit();
	STEPPER_vidInit();
	ADC_vidConfigure (ADC_u8_AVCC_REFERENCE, ADC_u8_RIGHT_ADJUST_RESULT, ADC_u8_ADC0, ADC_u8_PRESCALER_64);
	GPT_VoidConfigure(GPT_u8_TIMER0);
	GPT_VoidStartTimer(GPT_u8_TIMER0);
	GPT_VoidEnableCBF(GPT_u8_TIMER0, GPT_u8_TIMER0_OVF, temperatureActiv);
//	MODULE_vidTemperatureInit(u8ADC_read, u8InstantinusDegree);

	/**************** INTERRUPTS ENABLE ****************/
	EXTI_vidEnable(EXTI_u8_INT1, EXTI_u8_LOGICAL_CHANGE);


	/**************** SUPER LOOP (START OF THE PERIODIC CODE) ****************/
	while(TRUE){

		u8SPIrequest = SPI_vidTransceive(DONT_CARE);	//receive data from the user and store it in a global variable
		switch(u8SPIrequest){	//switch case checking the data stored in u8SPIrequest to take the suitable action

		case PARTY_MODE_ACTIVE:
			MODULE_vidGarageDoor(GARAGE_MANUAL, GARAGE_OPEN);
			SERVOMOTOR_enuInit(SERVOMOTOR_u8_OC1A);
			SERVOMOTOR_enuSetAngle(SERVOMOTOR_u8_ZERO_DEGREE, SERVOMOTOR_u8_OC1A);
			LED_enuTurnOff(LED_u8_PORTA, LED_u8_PIN5);
			SERVOMOTOR_enuInit(SERVOMOTOR_u8_OC1B);
			SERVOMOTOR_enuSetAngle(SERVOMOTOR_u8_90_DEGREE, SERVOMOTOR_u8_OC1B);
			LED_enuTurnOn(LED_u8_PORTA, LED_u8_PIN7);
			break;

		case PARTY_TIME_OUT:
			MODULE_vidGarageDoor(GARAGE_AUTO, GARAGE_DONT_CARE);
			LED_enuTurnOff(LED_u8_PORTA, LED_u8_PIN7);
			SERVOMOTOR_enuSetAngle(SERVOMOTOR_u8_ZERO_DEGREE, SERVOMOTOR_u8_OC1B);
			break;

		case GET_MASTER_DOOR_STATUS:
			if(Local_u8_MastarDoorStatus == ROOM_DOOR_LOCKED){
				SPI_vidTransceive(MASTER_DOOR_CLOSE);
			} else if(Local_u8_MastarDoorStatus == ROOM_DOOR_OPEN){
				SPI_vidTransceive(MASTER_DOOR_OPEN);
			} else {/*.....*/}
			break;

		case GET_MASTER_LIGHT_STATUS:
			if(Local_u8_MastarLightStatus == ROOM_LIHGT_OFF){
				SPI_vidTransceive(MASTER_LIGHT_OFF);
			} else if(Local_u8_MastarLightStatus == ROOM_LIHGT_ON){
				SPI_vidTransceive(MASTER_LIGHT_ON);
			} else {/*.....*/}
			break;

		case GET_TENANT_DOOR_STATUS:
			if(Local_u8_TenantDoorStatus == ROOM_DOOR_LOCKED){
				SPI_vidTransceive(TENANT_DOOR_CLOSE);
			} else if(Local_u8_TenantDoorStatus == ROOM_DOOR_OPEN){
				SPI_vidTransceive(TENANT_DOOR_OPEN);
			} else {/*.....*/}
			break;

		case GET_TENANT_LIGHT_STATUS:
			if(Local_u8_TenantLightStatus == ROOM_LIHGT_OFF){
				SPI_vidTransceive(TENANT_LIGHT_OFF);
			} else if(Local_u8_TenantLightStatus == ROOM_LIHGT_ON){
				SPI_vidTransceive(TENANT_LIGHT_ON);
			} else {/*.....*/}
			break;

		case MASTER_DOOR_SWITCH_REQUEST:
			if(Local_u8_MastarDoorStatus == ROOM_DOOR_LOCKED){
				SERVOMOTOR_enuSetAngle(SERVOMOTOR_u8_90_DEGREE, SERVOMOTOR_u8_OC1A);
				Local_u8_MastarDoorStatus = ROOM_DOOR_OPEN;
			} else if(Local_u8_MastarDoorStatus == ROOM_DOOR_OPEN){
				SERVOMOTOR_enuSetAngle(SERVOMOTOR_u8_ZERO_DEGREE, SERVOMOTOR_u8_OC1A);
				Local_u8_MastarDoorStatus = ROOM_DOOR_LOCKED;
			} else {/*.....*/}
			break;

		case MASTER_LIGHT_SWITCH_REQUEST:
			LED_enuToggleLED(LED_u8_PORTA, LED_u8_PIN5);
			if(Local_u8_MastarLightStatus == ROOM_LIHGT_OFF){
				Local_u8_MastarLightStatus = ROOM_LIHGT_ON;
			} else if(Local_u8_MastarLightStatus == ROOM_LIHGT_ON){
				Local_u8_MastarLightStatus = ROOM_LIHGT_OFF;
			} else {/*.....*/}
			break;

		case TENANT_DOOR_SWITCH_REQUEST:
			if(Local_u8_TenantDoorStatus == ROOM_DOOR_LOCKED){
				SERVOMOTOR_enuSetAngle(SERVOMOTOR_u8_90_DEGREE, SERVOMOTOR_u8_OC1B);
				Local_u8_TenantDoorStatus = ROOM_DOOR_OPEN;
			} else if(Local_u8_TenantDoorStatus == ROOM_DOOR_OPEN){
				SERVOMOTOR_enuSetAngle(SERVOMOTOR_u8_ZERO_DEGREE, SERVOMOTOR_u8_OC1B);
				Local_u8_TenantDoorStatus = ROOM_DOOR_LOCKED;
			} else {/*.....*/}
			break;

		case TENANT_LIGHT_SWITCH_REQUEST:
			LED_enuToggleLED(LED_u8_PORTA, LED_u8_PIN7);
			if(Local_u8_TenantLightStatus == ROOM_LIHGT_OFF){
				Local_u8_TenantLightStatus = ROOM_LIHGT_ON;
			} else if(Local_u8_TenantLightStatus == ROOM_LIHGT_ON){
				Local_u8_TenantLightStatus = ROOM_LIHGT_OFF;
			} else {/*.....*/}
			break;

		case SET_GARAGE_AUTO:
			MODULE_vidGarageDoor(GARAGE_AUTO, GARAGE_DONT_CARE);
			break;

		case SET_GARAGE_MANUAL:
			MODULE_vidGarageDoor(GARAGE_MANUAL, GARAGE_DONT_CARE);
			break;

		case OPEN_GARAGE_REQUEST:
			MODULE_vidGarageDoor(GARAGE_MANUAL, GARAGE_OPEN);
			break;

		case LOCK_GARAGE_REQUEST:
			MODULE_vidGarageDoor(GARAGE_MANUAL, GARAGE_CLOSE);
			break;

		case SEND_TEMP_MIN:
			u8TempMin = SPI_vidTransceive(DONT_CARE);
			break;

		case SEND_TEP_MAX:
			u8TempMax = SPI_vidTransceive(DONT_CARE);
			break;

		default:
			break;
		}
	}
}


void temperatureActiv(void){
	ADC_enuConversionResult(&Local);
	celsius = (Local)*4.88;
	celsius = (celsius/10.0);
	if (celsius < u8TempMin){
		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_LOW);
		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_HIGH);
	} else if(celsius > u8TempMax){
		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_LOW);
		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_HIGH);
	} else{
		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_LOW);
		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_LOW);
	}
}

void __vector_2(void)  __attribute__((signal, used));
void __vector_2(void){
	static u8 Local_u8DoorState;
	_delay_ms(1000);
	DIO_enuGetPinValue(DIO_u8_PORTD, DIO_u8_PIN0, &Local_u8DoorState);
	switch(Local_u8DoorState){
		case DIO_u8_HIGH:
			STEPPER_enuFullStep(GARAGE_OPEN_DOOR_ANGLE, STEPPER_u8_CLOCKWISE, DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_PORTC, DIO_u8_PIN3);
			STEPPER_enuFullStep(GARAGE_OPEN_DOOR_ANGLE, STEPPER_u8_ANTI_CLOCKWISE, DIO_u8_PORTC, DIO_u8_PIN4, DIO_u8_PORTC, DIO_u8_PIN5, DIO_u8_PORTC, DIO_u8_PIN6, DIO_u8_PORTC, DIO_u8_PIN7);
			break;
		case DIO_u8_LOW:
			STEPPER_enuFullStep(GARAGE_CLOSE_DOOR_ANGLE, STEPPER_u8_CLOCKWISE, DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_PORTC, DIO_u8_PIN3);
			STEPPER_enuFullStep(GARAGE_CLOSE_DOOR_ANGLE, STEPPER_u8_ANTI_CLOCKWISE, DIO_u8_PORTC, DIO_u8_PIN4, DIO_u8_PORTC, DIO_u8_PIN5, DIO_u8_PORTC, DIO_u8_PIN6, DIO_u8_PORTC, DIO_u8_PIN7);
			break;
		default:
			LED_enuTurnOn(LED_u8_PORTD, LED_u8_PIN7);

	}
}


/*
void __vector_16(void) __attribute__((signal, used));
void __vector_16(void){
	MODULE_vidTemperatureInit(u8ADC_read, u8InstantinusDegree);
	if (u8InstantinusDegree < u8TempMin){
		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_HIGH);
		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_LOW);
	} else if(u8InstantinusDegree > u8TempMax){
		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_HIGH);
		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_LOW);
	} else{
		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_LOW);
		DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_LOW);
	}
}*/
