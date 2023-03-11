/*
 * EEPROM_int.h
 *
 *  Created on: Sep 13, 2022
 *      Author: Mohamed Essam
 */

#ifndef MCAL_EEPROM_EEPROM_INT_H_
#define MCAL_EEPROM_EEPROM_INT_H_




/**********************FUNCTIONS**********************/
/* Name: EEPROM_vidwriteByte
 * Description: write to the EEPROM
 * Arguments:
 * 				first Argument: Copy_u16EEPROM_Address, 			options (specify the EEPROM address in the 1024bytes
																			EEPROM space. The EEPROM data bytes are addressed
																			linearly between 0 and 1023)
 * 				second Argument: Copy_u8EEPROM_Data, 				options (any 8-bit data)
 * Return:	void
 */
void EEPROM_vidwriteByte(u16 Copy_u16EEPROM_Address, u8 Copy_u8EEPROM_Data);




/* Name: EEPROM_u8readByte
 * Description: read from the EEPROM
 * Arguments:	first Argument: Copy_u16EEPROM_Address, 			options (specify the EEPROM address in the 1024bytes
																			EEPROM space. The EEPROM data bytes are addressed
																			linearly between 0 and 1023)
 * Return:	u8 -----> return the data stored in the EEDR
 */
u8 EEPROM_u8readByte(u16 Copy_u16EEPROM_Address);



#endif /* MCAL_EEPROM_EEPROM_INT_H_ */
