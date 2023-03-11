/*
 * tenantUser.h
 *
 *  Created on: Sep 17, 2022
 *      Author: Mohamed Essam
 */

#ifndef APP_TENANTUSER_H_
#define APP_TENANTUSER_H_


/**************** INITIAL VALUES ****************/
#define WAITING_PRESS_KEY							0xFF

/***************** MAGIC NUMBER *****************/
#define BLOCK_SIZE									8


/************ ROOMS CONTROL OPTIONS ************/
#define ROOM_DOOR									0x31
#define ROOM_LIGHT									0x32





/*******************FUNCTIONS******************/
/* Name: TENANT_vidRoomControl
 * Description: control options available to the user assign as tenant for its room
 * Arguments: void
 * Return:	void
 */
void TENANT_vidRoomControl(void);



#endif /* APP_TENANTUSER_H_ */
