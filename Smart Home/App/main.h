/*
 * main_prv.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Mohamed Essam
 */

#ifndef APP_MAIN_PRV_H_
#define APP_MAIN_PRV_H_

/*********************MACROS FOR MAGIC NUMBERS*********************/
#define ZERO										0
#define SET_TEMPERATURE								0x40

/*********************MACROS FOR SETTING PASSWORDS*********************/
#define PASS_SIZE									4
#define NO_VALUE									0xFF
#define WAITING_PRESS_KEY							0xFF
#define PASSWORD_SET								0x00
#define PASSWORD_CHAR_APPEAR_TIME					30
#define CURSOR_POSITION_SET_PASSWORD				12
#define CURSOR_POSITION_ENTER_PASSWORD				10
#define PASSWORD_ASTERISK							'*'
#define PASSWORD_FIRST_CHARACTER					0
#define PASSWORD_SECOND_CHARACTER					1
#define PASSWORD_THIRD_CHARACTER					2
#define PASSWORD_FOURTH_CHARACTER					3
#define OWNER_OPTION								0x31
#define TENANT_OPTION								0x32
#define PASSWORD_TRUE								0xA0
#define PASSWORD_WRONG								0x0A
#define NO_LOGIN									0x00
#define OWNER_LOGIN									0x01
#define TENANT_LOGIN								0x10




/*********************EEPROM ADDRESS*********************/
#define EEPROM_u16_OWNER_PASSWORD					(*(volatile u16*)0x0208)
#define EEPROM_u16_TENANT_PASSWORD					(*(volatile u16*)0x02D0)
#define EEPROM_u16_OWNER_PASSWORD_STATUS			(*(volatile u16*)0x02E0)
#define EEPROM_u16_TENANT_PASSWORD_STATUS			(*(volatile u16*)0x02F0)








#endif /* APP_MAIN_PRV_H_ */
