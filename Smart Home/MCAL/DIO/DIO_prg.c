/*
 * DIO_prg.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Mohamed Essam
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "DIO_prv.h"
#include "DIO_int.h"
#include "DIO_cfg.h"






/* Name: DIO_vidInit
 * Description: initialize all the MC pins according to "DIO_cfg.h"
 * Arguments: void
 * Return:	void
 */
void DIO_vidInit(void){

	/*
	 * **OPTIONS START VALUE** *
	 * DIO_u8_OUTPUT_LOW		---------> 1
	 * DIO_u8_OUTPUT_HIGH	 	---------> 1
	 * DIO_u8_INPUT_FLOATING	---------> 0
	 * DIO_u8_INPUT_PULLUP	 	---------> 0
	*/

	/*
	 SETTING DDR OPTIONS:
	 * INPUT  ---> 0
	 * OUTPUT ---> 1
	*/
	// Set DDR values
	DIO_u8_DDRA_REG = CONC(DIO_u8_PORTA_PIN7, DIO_u8_PORTA_PIN6, DIO_u8_PORTA_PIN5
								, DIO_u8_PORTA_PIN4 , DIO_u8_PORTA_PIN3, DIO_u8_PORTA_PIN2
								, DIO_u8_PORTA_PIN1, DIO_u8_PORTA_PIN0);

	DIO_u8_DDRB_REG = CONC(DIO_u8_PORTB_PIN7, DIO_u8_PORTB_PIN6, DIO_u8_PORTB_PIN5
							, DIO_u8_PORTB_PIN4 , DIO_u8_PORTB_PIN3, DIO_u8_PORTB_PIN2
							, DIO_u8_PORTB_PIN1, DIO_u8_PORTB_PIN0);

	DIO_u8_DDRC_REG = CONC(DIO_u8_PORTC_PIN7, DIO_u8_PORTC_PIN6, DIO_u8_PORTC_PIN5
							, DIO_u8_PORTC_PIN4 , DIO_u8_PORTC_PIN3, DIO_u8_PORTC_PIN2
							, DIO_u8_PORTC_PIN1, DIO_u8_PORTC_PIN0);

	DIO_u8_DDRD_REG = CONC(DIO_u8_PORTD_PIN7, DIO_u8_PORTD_PIN6, DIO_u8_PORTD_PIN5
								, DIO_u8_PORTD_PIN4 , DIO_u8_PORTD_PIN3, DIO_u8_PORTD_PIN2
								, DIO_u8_PORTD_PIN1, DIO_u8_PORTD_PIN0);

	/*
	 SETTING PORT OPTIONS:
	 * FOR DDR INPUT
	 	 * FLOATING  -->0
	 	 * PULLUP    -->1
	 * FOR DDR OUTPUT
	 	 * LOW   	 -->0
	 	 * HIGH  	 -->1
	*/
	//Un-define the initial values
	#undef DIO_u8_OUTPUT_LOW
	#undef DIO_u8_OUTPUT_HIGH
	#undef DIO_u8_INPUT_FLOATING
	#undef DIO_u8_INPUT_PULLUP
	//Define the new values
	#define DIO_u8_OUTPUT_LOW				0
	#define DIO_u8_OUTPUT_HIGH				1
	#define DIO_u8_INPUT_FLOATING			0
	#define DIO_u8_INPUT_PULLUP				1
	// Set PORT values
	DIO_u8_PORTA_REG = CONC(DIO_u8_PORTA_PIN7, DIO_u8_PORTA_PIN6, DIO_u8_PORTA_PIN5
								, DIO_u8_PORTA_PIN4 , DIO_u8_PORTA_PIN3, DIO_u8_PORTA_PIN2
								, DIO_u8_PORTA_PIN1, DIO_u8_PORTA_PIN0);

	DIO_u8_PORTB_REG = CONC(DIO_u8_PORTB_PIN7, DIO_u8_PORTB_PIN6, DIO_u8_PORTB_PIN5
							, DIO_u8_PORTB_PIN4 , DIO_u8_PORTB_PIN3, DIO_u8_PORTB_PIN2
							, DIO_u8_PORTB_PIN1, DIO_u8_PORTB_PIN0);

	DIO_u8_PORTC_REG = CONC(DIO_u8_PORTC_PIN7, DIO_u8_PORTC_PIN6, DIO_u8_PORTC_PIN5
							, DIO_u8_PORTC_PIN4 , DIO_u8_PORTC_PIN3, DIO_u8_PORTC_PIN2
							, DIO_u8_PORTC_PIN1, DIO_u8_PORTC_PIN0);

	DIO_u8_PORTD_REG = CONC(DIO_u8_PORTD_PIN7, DIO_u8_PORTD_PIN6, DIO_u8_PORTD_PIN5
							, DIO_u8_PORTD_PIN4 , DIO_u8_PORTD_PIN3, DIO_u8_PORTD_PIN2
							, DIO_u8_PORTD_PIN1, DIO_u8_PORTD_PIN0);


	//Un-define the last values
	#undef DIO_u8_OUTPUT_LOW
	#undef DIO_u8_OUTPUT_HIGH
	#undef DIO_u8_INPUT_FLOATING
	#undef DIO_u8_INPUT_PULLUP
	//Return to the initial values
	#define DIO_u8_OUTPUT_LOW				1
	#define DIO_u8_OUTPUT_HIGH				1
	#define DIO_u8_INPUT_FLOATING			0
	#define DIO_u8_INPUT_PULLUP				0

}




/* Name: DIO_enuSetPinValue
 * Description: assign the desired value to desired pin
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD)
 * 				second Argument: Copy_u8Pin, 			options (from DIO_u8_PIN0 to DIO_u8_PIN7)
 * 				third Argument: Copy_u8Value, 			options (DIO_u8_HIGH, DIO_u8_LOW)
 * Return:	Error Status -----> DIO_OK , DIO_NOK
 */
DIO_tenuErrorStatus DIO_enuSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	/*check arguments*/
	if((Copy_u8Port > DIO_u8_PORTD) || (Copy_u8Pin > DIO_u8_PIN7) || (Copy_u8Value > DIO_u8_HIGH)){
		Local_enuErrorStatus = DIO_NOK;
	}
	else {
	/*set pin value*/
		switch (Copy_u8Port){
			case DIO_u8_PORTA:
				(Copy_u8Value == DIO_u8_HIGH) ? (DIO_u8_PORTA_REG |= (DIO_u8_SET << Copy_u8Pin)) : (DIO_u8_PORTA_REG &= ~(DIO_u8_SET << Copy_u8Pin));
				break;
			case DIO_u8_PORTB:
				(Copy_u8Value == DIO_u8_HIGH) ? (DIO_u8_PORTB_REG |= (DIO_u8_SET << Copy_u8Pin)) : (DIO_u8_PORTB_REG &= ~(DIO_u8_SET << Copy_u8Pin));
				break;
			case DIO_u8_PORTC:
				(Copy_u8Value == DIO_u8_HIGH) ? (DIO_u8_PORTC_REG |= (DIO_u8_SET << Copy_u8Pin)) : (DIO_u8_PORTC_REG &= ~(DIO_u8_SET << Copy_u8Pin));
				break;
			case DIO_u8_PORTD:
				(Copy_u8Value == DIO_u8_HIGH) ? (DIO_u8_PORTD_REG |= (DIO_u8_SET << Copy_u8Pin)) : (DIO_u8_PORTD_REG &= ~(DIO_u8_SET << Copy_u8Pin));
				break;
		}
	}


	return Local_enuErrorStatus;
}



/* Name: DIO_enuSetPortValue
 * Description: assign the desired value to desired port
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD)
 * 				second Argument: Copy_u8Value, 			options (any macro refer to hixa_number)
 * Return:	Error Status -----> DIO_OK , DIO_NOK
 */
DIO_tenuErrorStatus DIO_enuSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value){
	DIO_tenuErrorStatus Local_enumErrorStatus = DIO_OK;
	/*check arguments*/
	/*if((Copy_u8Port > DIO_u8_PORTD) || (Copy_u8Value > DIO_u8_HIGH)){
		Local_enumErrorStatus = DIO_NOK;
	}
	else{*/
		switch (Copy_u8Port){
			case DIO_u8_PORTA:		DIO_u8_PORTA_REG = Copy_u8Value;		break;
			case DIO_u8_PORTB:		DIO_u8_PORTB_REG = Copy_u8Value;		break;
			case DIO_u8_PORTC:		DIO_u8_PORTC_REG = Copy_u8Value;		break;
			case DIO_u8_PORTD:		DIO_u8_PORTD_REG = Copy_u8Value;		break;
		}
	//}
	return Local_enumErrorStatus;
}





/* Name: DIO_enuGetPinValue
 * Description: get the desired pin value
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD)
 * 				second Argument: Copy_u8Pin,			options (from DIO_u8_PIN0 to DIO_u8_PIN7)
 * 				third Argument: variable address to store PIN value
 * Return:	Error Status -----> DIO_OK , DIO_NOK
 */
DIO_tenuErrorStatus DIO_enuGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Add_pu8PinValue) {
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;

	/* check arguments */
	if((Copy_u8Port > DIO_u8_PORTD) || (Copy_u8Pin > DIO_u8_PIN7) || (Add_pu8PinValue  == NULL)) {
		Local_enuErrorStatus = DIO_NOK;
	} else {
		/*implementation */
		switch(Copy_u8Port)
		{
			case DIO_u8_PORTA:
				*Add_pu8PinValue = (DIO_u8_PINA_REG >> Copy_u8Pin) & 0x01;
				break;

			case DIO_u8_PORTB:
				*Add_pu8PinValue = (DIO_u8_PINB_REG >> Copy_u8Pin) & 0x01;
				break;

			case DIO_u8_PORTC:
				*Add_pu8PinValue = (DIO_u8_PINC_REG >> Copy_u8Pin) & 0x01;
				break;

			case DIO_u8_PORTD:
				*Add_pu8PinValue = (DIO_u8_PIND_REG >> Copy_u8Pin) & 0x01;
				break;
		}
	}
	return Local_enuErrorStatus;
}








/* Name: DIO_enuGetPortValue
 * Description: get the desired port value
 * Arguments:
 * 				first Argument: Copy_u8Port, 			options (DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD)
 * 				second Argument: variable address to store PORT value
 * Return:	Error Status -----> DIO_OK , DIO_NOK
 */
DIO_tenuErrorStatus DIO_enuGetPortValue(u8 Copy_u8Port, u8 *Add_pu8PortValue){
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
			switch(Copy_u8Port) {
				case DIO_u8_PORTA:
					*Add_pu8PortValue = DIO_u8_PINA_REG;
					break;

				case DIO_u8_PORTB:
					*Add_pu8PortValue = DIO_u8_PINB_REG;
					break;

				case DIO_u8_PORTC:
					*Add_pu8PortValue = DIO_u8_PINC_REG;
					break;

				case DIO_u8_PORTD:
					*Add_pu8PortValue = DIO_u8_PIND_REG;
					break;
			}
	return Local_enuErrorStatus;
}
