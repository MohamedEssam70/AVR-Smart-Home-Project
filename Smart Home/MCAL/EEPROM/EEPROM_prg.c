/*
 * EEPROM_prg.c
 *
 *  Created on: Sep 13, 2022
 *      Author: Mohamed Essam
 */


#include <avr/io.h>
#include <avr/eeprom.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "EEPROM_prv.h"
#include "EEPROM_int.h"
#include <util/delay.h>
#include "../DIO/DIO_int.h"






/* Name: EEPROM_vidwriteByte
 * Description: write to the EEPROM
 * Arguments:
 * 				first Argument: Copy_u16EEPROM_Address, 			options (specify the EEPROM address in the 1024bytes
																			EEPROM space. The EEPROM data bytes are addressed
																			linearly between 0 and 1023)
 * 				second Argument: Copy_u8EEPROM_Data, 				options (any 8-bit data)
 * Return:	void
 */
void EEPROM_vidwriteByte(u16 Copy_u16EEPROM_Address, u8 Copy_u8EEPROM_Data){
	/* wait for completion of previous write */
	while(EEPROM_u8_EECR_REG & EEPROM_u8_EEWE);
	/* set up address and data registers */
	EEPROM_u16_EEAR_REG = Copy_u16EEPROM_Address;
	EEPROM_u8_EEDR_REG = Copy_u8EEPROM_Data;
	/* write logical one to EEMWE */
	EEPROM_u8_EECR_REG |= EEPROM_u8_EEMWE;
//	sbi(EECR, EEMWE);

//	__asm__ volatile(sbi $1C,2);
/*	asm("sbi %1, %0"
	:"=m"(EECR)
	:"Ir"(EEMWE)
	:"cc");*/
	/* start EEPROM write by setting EEWE */
	EEPROM_u8_EECR_REG |= EEPROM_u8_EEWE;
	//__asm__ volatile("sbi EECR,EEWE");
/*	asm("sbi %1, %0"
		:"=m"(EECR)
		:"Ir"(EEWE)
		:"cc");*/
}


/* Name: EEPROM_u8readByte
 * Description: read from the EEPROM
 * Arguments:	first Argument: Copy_u16EEPROM_Address, 			options (specify the EEPROM address in the 1024bytes
																			EEPROM space. The EEPROM data bytes are addressed
																			linearly between 0 and 1023)
 * Return:	u8 -----> return the data stored in the EEDR
 */
u8 EEPROM_u8readByte(u16 Copy_u16EEPROM_Address){
	/* wait for completion of previous write */
	while(EEPROM_u8_EECR_REG & EEPROM_u8_EEWE);
	/* set up address register */
	EEPROM_u16_EEAR_REG = Copy_u16EEPROM_Address;
	/* start EEPROM read by setting EERE */
	EEPROM_u8_EECR_REG |= EEPROM_u8_EERE;
	/* return data from EEDR */
	return EEPROM_u8_EEDR_REG;
}
