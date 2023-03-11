/*
 * ADC_int.h
 *
 *  Created on: Sep 4, 2022
 *      Author: Mohamed Essam
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_



/**************ERROR STATUS********************/

typedef enum {
	ADC_OK,
	ADC_NOK
}ADC_tenuErrorStatus;



/******************MACROS***********************/

#define ADC_u8_INT_ENABLE						0
#define ADC_u8_INT_DISABLE						1



/* macros for ADMUX options */
#define ADC_u8_AREF								0x00
#define ADC_u8_AVCC_REFERENCE					0x40
#define ADC_u8_RESERVED							0x08
#define ADC_u8_INTERNAL_REF						0xC0


/* macros for adjust result options */
#define ADC_u8_LEFT_ADJUST_RESULT				0x20
#define ADC_u8_RIGHT_ADJUST_RESULT				0x00

/* macros for ADC channel options*/
#define ADC_u8_ADC0								0x00
#define ADC_u8_ADC1								0x01
#define ADC_u8_ADC2								0x02
#define ADC_u8_ADC3								0x03
#define ADC_u8_ADC4								0x04
#define ADC_u8_ADC5								0x05
#define ADC_u8_ADC6								0x06
#define ADC_u8_ADC7								0x07


/* macros for ADC control and status register options */
/* ADC Enable */
#define ADC_u8_ADC_Enable						0x80
/* ADC Conversion Status */
#define ADC_u8_START_CONVERSION					0x40
#define ADC_u8_AUTO_TRIGGER_ENABLE				0x20
/* ADC Interrupt */
#define ADC_u8_INTERRUPT_ENABLE					0X08
/* ADC Prescaler Selections */
#define ADC_u8_PRESCALER_2						0X01
#define ADC_u8_PRESCALER_4						0X02
#define ADC_u8_PRESCALER_8						0X03
#define ADC_u8_PRESCALER_16						0X04
#define ADC_u8_PRESCALER_32						0X05
#define ADC_u8_PRESCALER_64						0X06
#define ADC_u8_PRESCALER_128					0X07


/* macros for SFIOR register options */
#define ADC_u8_FREE_RUNNING_MODE				0x00

/**/
#define ADC_u8_ADIF								0x10
#define ADC_u8_ADC_FLAG							((ADC_u8_ADCSRA_REG & 0x10) >> 4)

/*************NEEDED FUNCTIONS*****************/

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
void ADC_vidConfigure (u8 Copy_u8voltageReference, u8 Copy_u8adjustResult, u8 Copy_u8channel, u8 Copy_u8prescaler);



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
 */
//void ADC_enuEnableADC (u8 Copy_u8conversionStatus, u8 Copy_u8interruptStatus, u8 Copy_u8prescaler);


/* Name: ADC_enuConversionResult
 * Description: read the conversion result and store it in a address
 * Arguments: Arguments:
 * 				first Argument: u16 *Add_pu16conversionValue , 			options (variable address to store PORT value)
 * Return:	void
 */
void ADC_enuConversionResult (u16 *Add_pu16conversionValue);



#endif /* MCAL_ADC_ADC_INT_H_ */
