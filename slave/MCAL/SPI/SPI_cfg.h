/*
 * SPI_cfg.h
 *
 *  Created on: Sep 11, 2022
 *      Author: Mohamed Essam
 */

#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_


/****DATA ORDER CONFIG.******/
#define SPI_u8_DATA_ORDER									SPI_u8_TRANSMITTE_LSB

/******CLOCK POLARITY CONFIG.******/
#define SPI_u8_CLOCK_POLARITY								SPI_u8_RISING_LEADING_EDGE

/******CLOCK PHASE CONFIG.******/
#define SPI_u8_CLOCK_PHASE									SPI_u8_SETUP_FIRST

/******CLOCK RATE CONFIG.******/
#define SPI_u8_CLOCK_RATE									SPI_u8_PRESCALER_16

/******SPI INTERRUPT CONFIG.******/
#define SPI_u8_INTERRUPT_STATUS								SPI_u8_INTERRUPT_ENABLE



#endif /* MCAL_SPI_SPI_CFG_H_ */
