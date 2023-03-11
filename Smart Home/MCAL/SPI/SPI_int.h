/*
 * SPI_int.h
 *
 *  Created on: Sep 11, 2022
 *      Author: Mohamed Essam
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

#include "SPI_cfg.h"

/*******************MACROS************************/
/******ENABLE SPI******/
#define SPI_u8_ENABLE										0x40
#define SPI_u8_DISABLE										~(0x40)

/******MASTER/SLAVE OPTIONS******/
#define SPI_u8_ASSIGN_NODE_AS_MASTER						0x10
#define SPI_u8_ASSIGN_NODE_AS_SLAVE							0x00

/******DATA ORDER OPTIONS******/
#define SPI_u8_TRANSMITTE_LSB								0x20
#define SPI_u8_TRANSMITTE_MSB								0x00

/******CLOCK POLARITY OPTIONS******/
#define SPI_u8_RISING_LEADING_EDGE							0x00
#define SPI_u8_FALLING_LEADING_EDGE							0x08

/******CLOCK PHASE OPTIONS******/
#define SPI_u8_SETUP_FIRST									0x04
#define SPI_u8_SAMPLE_FIRST									0x00

/******CLOCK RATE OPTIONS******/
#define SPI_u8_PRESCALER_4									0x00
#define SPI_u8_PRESCALER_16									0x01
#define SPI_u8_PRESCALER_64									0x02
#define SPI_u8_PRESCALER_128								0x03
#define SPI_u8_PRESCALER_2									0x04
#define SPI_u8_PRESCALER_8									0X05
#define SPI_u8_PRESCALER_32									0x06
#define SPI_u8_PRESCALER_64_								0X07

/******SPI INTERRUPT OPTIONS******/
#define SPI_u8_INTERRUPT_ENABLE								0X80
#define SPI_u8_INTERRUPT_DISABLE							0X00

/******SPI STATUS REG OPTIONS******/
#define SPI_u8_INTERRUPT_FLAG								0x80
#define SPI_u8_INTERRUPT_FLAG_BIT							7

/******PINS******/
#define SPI_u8_SCK											1<<7
#define SPI_u8_MISO											1<<6
#define SPI_u8_MOSI 										1<<5
#define SPI_u8_SS											1<<4

/*******************FUNCTIONS************************/
void SPI_vidSPIInitMaster(void);
void SPI_vidSPIInitSlave(void);


u8 SPI_vidTransceive(u8 Copy_u8Data);

void SPI_vidStopConnection(void);

#endif /* MCAL_SPI_SPI_INT_H_ */
