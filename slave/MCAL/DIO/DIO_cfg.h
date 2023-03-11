/*
 * DIO_cfg.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Mohamed Essam
 */

#ifndef MCAL_DIO_CFG_H_
#define MCAL_DIO_CFG_H_

/* macros for options*/
#define DIO_u8_OUTPUT_LOW				1
#define DIO_u8_OUTPUT_HIGH				1
#define DIO_u8_INPUT_FLOATING			0
#define DIO_u8_INPUT_PULLUP				0

/* options:
 * 				1- DIO_u8_OUTPUT_LOW
 * 				2- DIO_u8_OUTPUT_HIGH
 * 				3- DIO_u8_INPUT_FLOATING
 * 				4- DIO_u8_INPUT_PULLUP
 */

/*PORTA Pins*/
#define DIO_u8_PORTA_PIN0				DIO_u8_INPUT_PULLUP      // Connected to:
#define DIO_u8_PORTA_PIN1				DIO_u8_OUTPUT_LOW      // Connected to:
#define DIO_u8_PORTA_PIN2				DIO_u8_OUTPUT_LOW      // Connected to:
#define DIO_u8_PORTA_PIN3				DIO_u8_OUTPUT_LOW      // Connected to:
#define DIO_u8_PORTA_PIN4				DIO_u8_OUTPUT_LOW      // Connected to: Master Room Door
#define DIO_u8_PORTA_PIN5				DIO_u8_OUTPUT_LOW      // Connected to: Master Room LED
#define DIO_u8_PORTA_PIN6				DIO_u8_OUTPUT_LOW      // Connected to: Tenant Room Door
#define DIO_u8_PORTA_PIN7				DIO_u8_OUTPUT_LOW      // Connected to: Tenant Room LED

/*PORTB Pins*/
#define DIO_u8_PORTB_PIN0				DIO_u8_OUTPUT_LOW      // Connected to:
#define DIO_u8_PORTB_PIN1				DIO_u8_OUTPUT_LOW      // Connected to:
#define DIO_u8_PORTB_PIN2				DIO_u8_OUTPUT_LOW      // Connected to:
#define DIO_u8_PORTB_PIN3				DIO_u8_OUTPUT_LOW      // Connected to:
#define DIO_u8_PORTB_PIN4				DIO_u8_OUTPUT_LOW      // Connected to:
#define DIO_u8_PORTB_PIN5				DIO_u8_OUTPUT_LOW      // Connected to:
#define DIO_u8_PORTB_PIN6				DIO_u8_OUTPUT_LOW      // Connected to:
#define DIO_u8_PORTB_PIN7				DIO_u8_OUTPUT_LOW      // Connected to:

/*PORTC Pins*/
#define DIO_u8_PORTC_PIN0				DIO_u8_OUTPUT_HIGH       // Connected to:
#define DIO_u8_PORTC_PIN1				DIO_u8_OUTPUT_HIGH       // Connected to:
#define DIO_u8_PORTC_PIN2				DIO_u8_OUTPUT_HIGH       // Connected to:
#define DIO_u8_PORTC_PIN3				DIO_u8_OUTPUT_HIGH      // Connected to:
#define DIO_u8_PORTC_PIN4				DIO_u8_OUTPUT_HIGH      // Connected to:
#define DIO_u8_PORTC_PIN5				DIO_u8_OUTPUT_HIGH      // Connected to:
#define DIO_u8_PORTC_PIN6				DIO_u8_OUTPUT_HIGH     // Connected to:
#define DIO_u8_PORTC_PIN7				DIO_u8_OUTPUT_HIGH     // Connected to:

/*PORTD Pins*/
#define DIO_u8_PORTD_PIN0				DIO_u8_INPUT_FLOATING		// Connected to:
#define DIO_u8_PORTD_PIN1				DIO_u8_OUTPUT_LOW     	// Connected to:
#define DIO_u8_PORTD_PIN2				DIO_u8_OUTPUT_LOW       // Connected to:
#define DIO_u8_PORTD_PIN3				DIO_u8_INPUT_PULLUP       // Connected to:
#define DIO_u8_PORTD_PIN4				DIO_u8_OUTPUT_LOW       // Connected to:
#define DIO_u8_PORTD_PIN5				DIO_u8_OUTPUT_LOW       // Connected to:
#define DIO_u8_PORTD_PIN6				DIO_u8_OUTPUT_LOW       // Connected to:
#define DIO_u8_PORTD_PIN7				DIO_u8_OUTPUT_LOW       // Connected to:


#endif /* MCAL_DIO_CFG_H_ */
