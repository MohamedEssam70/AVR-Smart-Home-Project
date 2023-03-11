/*
 * ADC_prv.h
 *
 *  Created on: Sep 4, 2022
 *      Author: Mohamed Essam
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_


/**********REGISTER ADDRESSES************/
/*ADMUX REG*/
#define ADC_u8_ADMUX_REG					(*(volatile u8*)0x27)

/*ADCSRA REG*/
#define ADC_u8_ADCSRA_REG					(*(volatile u8*)0x26)

/*ADCH REG*/
#define ADC_u8_ADCH_REG						(*(volatile u8*)0x25)

/*ADCL REG*/
#define ADC_u8_ADCL_REG						(*(volatile u8*)0x24)





#endif /* MCAL_ADC_ADC_PRV_H_ */
