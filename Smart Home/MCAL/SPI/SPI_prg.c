/*
 * SPI_prg.c
 *
 *  Created on: Sep 11, 2022
 *      Author: Mohamed Essam
 */
#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "SPI_int.h"
#include "SPI_prv.h"
#include "../DIO/DIO_int.h"
#include <avr/io.h>


void SPI_vidSPIInitMaster (void)
{
	DDRB |= (SPI_u8_MOSI)|(SPI_u8_SS)|(SPI_u8_SCK);
	/*set node as master*/
	SPI_u8_SPCR_REG = SPI_u8_ASSIGN_NODE_AS_MASTER;
	/*set the data order according to confg. file*/
//	SPI_u8_SPCR_REG |= SPI_u8_DATA_ORDER;
	/*set the leading edge according to confg. file*/
//	SPI_u8_SPCR_REG |= SPI_u8_CLOCK_POLARITY;
	/*set the phase at the leading edge according to config. file*/
//	SPI_u8_SPCR_REG |= SPI_u8_CLOCK_PHASE;
	/*set clock prescaler according to config. file*/
	SPI_u8_SPCR_REG |= SPI_u8_CLOCK_RATE;
	/*enable SPI*/
	SPI_u8_SPCR_REG |= SPI_u8_ENABLE;
}

void SPI_vidSPIInitSlave (void)
{
	SPI_u8_DDRB_REG |= (SPI_u8_MISO);
	/*set node as master*/
	SPI_u8_SPCR_REG = SPI_u8_ASSIGN_NODE_AS_SLAVE;
	/*set the data order according to confg. file*/
//	SPI_u8_SPCR_REG |= SPI_u8_DATA_ORDER;
	/*set the leading edge according to confg. file*/
//	SPI_u8_SPCR_REG |= SPI_u8_CLOCK_POLARITY;
	/*set the phase at the leading edge according to config. file*/
//	SPI_u8_SPCR_REG |= SPI_u8_CLOCK_PHASE;
	/*enable SPI*/
	SPI_u8_SPCR_REG |= SPI_u8_ENABLE;
}


u8 SPI_vidTransceive(u8 Copy_u8Data){
	u8 local_u8Temp;
	/*set the data in SPDR in order to transmit it*/
	SPI_u8_SPDR_REG = Copy_u8Data;
	while(!((SPI_u8_SPSR_REG & SPI_u8_INTERRUPT_FLAG) >> SPI_u8_INTERRUPT_FLAG_BIT));
	local_u8Temp = SPI_u8_SPSR_REG;
	return SPI_u8_SPDR_REG;
}


void SPI_vidStopConnection(void){
	/*disable SPI*/
	SPI_u8_SPCR_REG &= (SPI_u8_DISABLE);
}
