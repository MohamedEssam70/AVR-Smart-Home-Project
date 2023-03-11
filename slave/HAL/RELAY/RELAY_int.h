/*
 * RELAY_int.h
 *
 *  Created on: Sep 20, 2022
 *      Author: Mohamed Essam
 */


/************************************************************************************
                             	 	 MACROS
*************************************************************************************/
/****** MACROS FOR PORTS ******/
#define RELAY_u8_PORTA								0
#define RELAY_u8_PORTB								1
#define RELAY_u8_PORTC								2
#define RELAY_u8_PORTD								3

/****** MACROS FOR PINS ******/
#define RELAY_u8_PIN0								0
#define RELAY_u8_PIN1								1
#define RELAY_u8_PIN2								2
#define RELAY_u8_PIN3								3
#define RELAY_u8_PIN4								4
#define RELAY_u8_PIN5								5
#define RELAY_u8_PIN6								6
#define RELAY_u8_PIN7								7

/****** MACROS FOR VALUES ******/
#define RELAY_u8_NORMALLY_OPEN						DIO_u8_HIGH
#define RELAY_u8_NORMALLY_CLOSE						DIO_u8_LOW







/************************************************************************************
                             FUNCTION DECLARATIONS
*************************************************************************************/
/*
 * Name: RELAY_vidInit
 * Description: initialize RELAY control pin
 * Arguments: void
 * Return:	void
*/
void RELAY_vidInit(void);



/*
 * Name: RELAY_vidSetNormallyClose
 * Description: relay connected on the normally close switch
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (RELAY_u8_PORTA, RELAY_u8_PORTB, RELAY_u8_PORTC, RELAY_u8_PORTD)
 * 				second Argument: Copy_u8Pin, 			options (from RELAY_u8_PIN0 to RELAY_u8_PIN7)
 * Return:	void
*/
void RELAY_vidSetNormallyClose(u8 Copy_u8ControlPort, u8 Copy_u8ControlPin);



/*
 * Name: RELAY_vidSetNormallyOpen
 * Description: relay connected on the normally open switch
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (RELAY_u8_PORTA, RELAY_u8_PORTB, RELAY_u8_PORTC, RELAY_u8_PORTD)
 * 				second Argument: Copy_u8Pin, 			options (from RELAY_u8_PIN0 to RELAY_u8_PIN7)
 * Return:	void
*/
void RELAY_vidSetNormallyOpen(u8 Copy_u8ControlPort, u8 Copy_u8ControlPin);
