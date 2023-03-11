/*
 * EEPROM_prv.h
 *
 *  Created on: Sep 13, 2022
 *      Author: Mohamed Essam
 */

#ifndef MCAL_EEPROM_EEPROM_PRV_H_
#define MCAL_EEPROM_EEPROM_PRV_H_


/**********************REGISTERS ADDRESS**********************/
#define EEPROM_u16_EEAR_REG							(*(volatile u16*)0x3E)
#define EEPROM_u8_EEDR_REG							(*(volatile u8*)0x3D)
#define EEPROM_u8_EECR_REG							(*(volatile u8*)0x3C)


/**********************BITS LOCATION**********************/
#define EEPROM_u8_EEWE								0x02
#define EEPROM_u8_EERE								0x01
#define EEPROM_u8_EEMWE								0x04


#endif /* MCAL_EEPROM_EEPROM_PRV_H_ */
