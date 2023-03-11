/*
 * Macros_SPI.h
 *
 *  Created on: Sep 16, 2022
 *      Author: Mohamed Essam
 */

#ifndef APP_MACROS_SPI_H_
#define APP_MACROS_SPI_H_

#define DONT_CARE									0xFF
#define PARTY_MODE_ACTIVE							0x01
#define PARTY_TIME_OUT								0x02
#define GET_MASTER_DOOR_STATUS						0x03
#define MASTER_DOOR_OPEN							0x04
#define MASTER_DOOR_CLOSE							0x05
#define GET_MASTER_LIGHT_STATUS						0x06
#define MASTER_LIGHT_ON								0x07
#define MASTER_LIGHT_OFF							0x08
#define GET_TENANT_DOOR_STATUS						0x09
#define TENANT_DOOR_OPEN							0x0A
#define TENANT_DOOR_CLOSE							0x0B
#define GET_TENANT_LIGHT_STATUS						0x0C
#define TENANT_LIGHT_ON								0x0D
#define TENANT_LIGHT_OFF							0x0E
#define MASTER_DOOR_SWITCH_REQUEST					0x0F
#define MASTER_LIGHT_SWITCH_REQUEST					0x1F
#define TENANT_DOOR_SWITCH_REQUEST					0x2F
#define TENANT_LIGHT_SWITCH_REQUEST					0x3F
#define SET_GARAGE_AUTO								0x4F
#define SET_GARAGE_MANUAL							0x5F
#define OPEN_GARAGE_REQUEST							0x6F
#define LOCK_GARAGE_REQUEST							0x7F
#define SEND_TEMP_MIN								0x8F
#define SEND_TEP_MAX								0X9F
#define ACTIVE_TEMP_SYSTEM							0xA0


#endif /* APP_MACROS_SPI_H_ */
