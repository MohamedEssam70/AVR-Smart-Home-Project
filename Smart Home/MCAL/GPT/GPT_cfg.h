/*
 * GPT_cfg.h
 *
 *  Created on: Sep 5, 2022
 *      Author: Mohamed Essam
 */

#ifndef HAL_GPT_GPT_CFG_H_
#define HAL_GPT_GPT_CFG_H_


/*Wave Form Generation Mode Options*/
#define GPT_u8_WAVE_FORM_NORMAL			0x00
#define GPT_u8_WAVE_FORM_PWM			0x40
#define GPT_u8_WAVE_FORM_CTC			0x08
#define GPT_u8_WAVE_FORM_FAST_PWM		0x48

/*Compare Match Output Mode Options*/
#define GPT_u8_COM_NORMAL				0x00
#define GPT_u8_COM_TOGGLE				0x10
#define GPT_u8_COM_CLEAR				0x20
#define GPT_u8_COM_SET					0x30

/*Clock Select Options*/
#define GPT_u8_NO_CLOCK_SOURCE			0x00
#define GPT_u8_NO_PRESCALING			0x01
#define GPT_u8_PRESCALER8				0x02
#define GPT_u8_PRESCALER64				0x03
#define GPT_u8_PRESCALER256				0x04
#define GPT_u8_PRESCALER1024			0x05
#define GPT_u8_EXT_CLOCK_FALLING		0x06
#define GPT_u8_EXT_CLOCK_RISING			0x07

/*Timer Interrupt Mask REG Options*/
#define GPT_u8_OVERFLOW_INT				0x01

/************/
#define GPT_u16_MC_FREQUENCY				16000000
#define GPT_u16_TIMER0_RESLUTION			256






#endif /* HAL_GPT_GPT_CFG_H_ */
