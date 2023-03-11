/*
 * ADC_prg.c
 *
 *  Created on: Sep 4, 2022
 *      Author: Mohamed Essam
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "ADC_prv.h"
#include "ADC_int.h"
#include "../GLOBAL_INT/GLOBAL_INT_int.h"


/*
 * Name: ADC_vidConfigure
 * Description: Initialize and configure ADC
 * Arguments:  Arguments:
 * 				first Argument: Copy_u8voltageReference , 			options (ADC_u8_AREF, ADC_u8_AVCC_REFERENCE,
																			ADC_u8_RESERVED, ADC_u8_INTERNAL_REF)
				second Argument: Copy_u8adjustResult , 				options (ADC_u8_LEFT_ADJUST_RESULT, ADC_u8_RIGHT_ADJUST_RESULT)
				third Argument: Copy_u8channel , 					options (ADC_u8_ADC0, ADC_u8_ADC1, ADC_u8_ADC2, ADC_u8_ADC3,
																			ADC_u8_ADC4, ADC_u8_ADC5, ADC_u8_ADC6, ADC_u8_ADC7)
				fourth Argument: Copy_u8prescaler , 					options (ADC_u8_PRESCALER_2, ADC_u8_PRESCALER_4,
 * 																			ADC_u8_PRESCALER_8, ADC_u8_PRESCALER_16,
 * 																			ADC_u8_PRESCALER_32, ADC_u8_PRESCALER_64,
 * 																			ADC_u8_PRESCALER_128)
 * Return:	void
 */
void ADC_vidConfigure (u8 Copy_u8voltageReference, u8 Copy_u8adjustResult, u8 Copy_u8channel, u8 Copy_u8prescaler){
	/* configure voltage reference */
	ADC_u8_ADMUX_REG |= Copy_u8voltageReference;
	/* configure ADC channel */
	ADC_u8_ADMUX_REG |= Copy_u8channel;
	/* enable ADC */
	ADC_u8_ADCSRA_REG |= ADC_u8_ADC_Enable;
	/* configure adjust result */
	if(Copy_u8adjustResult == ADC_u8_LEFT_ADJUST_RESULT){
		ADC_u8_ADMUX_REG |= ADC_u8_LEFT_ADJUST_RESULT;
	}
	/* enable interrupt */
//	ADC_u8_ADCSRA_REG |= ADC_u8_INTERRUPT_ENABLE;
//	GINT_vidEnable();
	/* configure ADC clock */
	ADC_u8_ADCSRA_REG |= Copy_u8prescaler;
}




/* Name: ADC_enuEnableADC
 * Description: enable the ADC and set the conversion, interrupt, and prescaler
 * Arguments: Arguments:
 * 				first Argument: Copy_u8conversionStatus , 			options (ADC_u8_START_CONVERSION, ADC_u8_AUTO_TRIGGER_ENABLE)
 * 				second Argument: Copy_u8interruptStatus , 			options (ADC_u8_INT_ENABLE, ADC_u8_INT_DISABLE)
 * 				third Argument: Copy_u8prescaler , 					options (ADC_u8_PRESCALER_2, ADC_u8_PRESCALER_4,
 * 																			ADC_u8_PRESCALER_8, ADC_u8_PRESCALER_16,
 * 																			ADC_u8_PRESCALER_32, ADC_u8_PRESCALER_64,
 * 																			ADC_u8_PRESCALER_128)
 * Return:	void
 *//*
void ADC_enuEnableADC (u8 Copy_u8conversionStatus, u8 Copy_u8interruptStatus, u8 Copy_u8prescaler){
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADC_Enable);
	SET_BIT(ADC_u8_ADCSRA_REG, Copy_u8conversionStatus);
	if(Copy_u8interruptStatus == ADC_u8_INT_ENABLE){
		SET_BIT(ADC_u8_ADCSRA_REG, Copy_u8interruptStatus);
	} else{
		CLEAR_BIT(ADC_u8_ADCSRA_REG, Copy_u8interruptStatus);
	}
	SET_BIT(ADC_u8_ADCSRA_REG, Copy_u8prescaler);
}
*/


/* Name: ADC_enuConversionResult
 * Description: read the conversion result and store it in a address
 * Arguments: Arguments:
 * 				first Argument: u16 *Add_pu16conversionValue , 			options (variable address to store PORT value)
 * Return:	void
 */
void ADC_enuConversionResult (u16 *Add_pu16conversionValue){
	ADC_u8_ADCSRA_REG |= ADC_u8_START_CONVERSION;
	while(ADC_u8_ADC_FLAG == 1);
	ADC_u8_ADCSRA_REG |= ADC_u8_ADIF;
//	*Add_pu16conversionValue = (u16)((ADC_u8_ADCL_REG) | (ADC_u8_ADCH_REG << 8));
	*Add_pu16conversionValue = ADC_u8_ADCL_REG;
	*Add_pu16conversionValue |= (ADC_u8_ADCH_REG << 8);
}
