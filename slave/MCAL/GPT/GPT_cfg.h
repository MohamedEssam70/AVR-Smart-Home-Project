/*
 * GPT_cfg.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Mustafa
 */

#ifndef MCAL_GPT_GPT_CFG_H_
#define MCAL_GPT_GPT_CFG_H_
/////////////    TIMER0           /////////////////

// Waveform Generation Mode  WGM00  WGM01     -->   TCCR0_REG
#define GPT_u8_NORMAL_MODE                   			   0X00
#define GPT_u8_CTC_MODE                      			   0X08

//Compare Output Mode, non-PWM Mode   -->  TCCR0_REG
#define GPT_u8_NORMAL_OPERATION_TIMER0                       0X00
#define GPT_u8_TOGGLE_TIMER0                                 0X10
#define GPT_u8_CLER_TIMER0                                   0X20
#define GPT_u8_SET_TIMER0                                    0X30

//. Clock Select Bit Description   -->     TCCR0_REG
#define GPT_u8_TIMER_STOPPED                                       0X00
#define GPT_u8_NO_PRESCALING                                       0X01
#define GPT_u8_8_PRESCALING                                        0X02
#define GPT_u8_64_PRESCALING                                       0X03
#define GPT_u8_256_PRESCALING                                      0X04
#define GPT_u8_1024_PRESCALING                                     0X05
#define GPT_u8_EXTERNAL_CLOCK_FALLING_EDGE                         0X06
#define GPT_u8_EXTERNAL_CLOCK_RISING_EDGE                          0X07

// Timer/Counter0 Output Compare Match Interrupt Enable   -->   TIMSK_REG
#define GPT_u8_OCIE0_PIN                                      0X80

//Timer/Counter0 Overflow Interrupt Enable   -->   TIMSK_REG
#define GPT_u8_TOIE0_PIN                                      0X01

//////////////////////      TIMER1             /////////////
//  Timer/Counter1 Control Register A  -- > TCCR1A

#define GPT_u8_NORMAL_OPERATION_TIMER1A                       0X00
#define GPT_u8_TOGGLE_TIMER1A                                 0X40
#define GPT_u8_CLER_TIMER1A                                   0X80
#define GPT_u8_SET_TIMER1A                                    0XC0
#define GPT_u8_NORMAL_OPERATION_TIMER1AB                      0X00
#define GPT_u8_TOGGLE_TIMER1B                                 0X10
#define GPT_u8_CLER_TIMER1B                                   0X20
#define GPT_u8_SET_TIMER1B                                    0X30

// Timer/Counter1, Input Capture Interrupt Enable    -->   TIMSK_REG
#define GPT_u8_TICIE1_PIN                          0X20
// Timer/Counter1, Output Compare A Match Interrupt Enable   -->   TIMSK_REG
#define GPT_u8_OCIE1A_PIN                          0X10
//Timer/Counter1, Output Compare B Match Interrupt Enable    -->   TIMSK_REG
#define GPT_u8_OCIE1B_PIN                          0X08
// Timer/Counter1, Overflow Interrupt Enable      -->   TIMSK_REG
#define GPT_u8_TOIE1_PIN                           0X04


//////////////////////      TIMER2              /////////////

// Waveform Generation Mode  WGM00  WGM01     -->   TCCR0_REG
#define GPT_u8_NORMAL_MODE                      0X00
#define GPT_u8_CTC_MODE                         0X08

//Compare Output Mode, non-PWM Mode   -->  TCCR0_REG
#define GPT_u8_NORMAL_OPERATION_TIMER2                       0X00
#define GPT_u8_TOGGLE_TIMER2                                 0X10
#define GPT_u8_CLER_TIMER2                                   0X20
#define GPT_u8_SET_TIMER2                                    0X30

#endif /* MCAL_GPT_GPT_CFG_H_ */
