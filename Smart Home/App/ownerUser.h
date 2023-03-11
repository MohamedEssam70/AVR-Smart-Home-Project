/*
 * owner_int.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Mohamed Essam
 */

#ifndef APP_OWNERUSER_H_
#define APP_OWNERUSER_H_


/***************** MAGIC NUMBER *****************/
#define ZERO										0
#define DIGIT_TWO									2
#define TEN_MULTIPLICANT							10
#define BLOCK_SIZE									8


/********************* ASCII ********************/
#define HASH_SIGN									0x23
#define ASTERISK_SIGN								0x2A
#define ZERO_ASCII									0x30
#define DEGREE_SIGN									0xDF
#define ASCII_DEFERANT								48


/**************** INITIAL VALUES ****************/
#define WAITING_PRESS_KEY							0xFF


/*************** MAIN MENU OPTIONS **************/
#define NO_OPTION									0x00
#define CHANGE_MODE									0x31
#define ROOMS_CONTROL								0x32
#define GARAGE_CONTROL								0x33
#define TEMPERATURE_CONTROL							0x34


/******** SYSTEM OPERATION MODE OPTIONS *********/
#define NORMAL_MODE									0x31
#define PARTY_MODE									0x32


/************* ROOMS LIST OPTIONS **************/
#define MASTER_ROOM									0x31
#define TENENT_ROOM									0x32


/************ ROOMS CONTROL OPTIONS ************/
#define ROOM_DOOR									0x31
#define ROOM_LIGHT									0x32


/********* GARAGE OPERATION MODE OPTIONS ********/
#define GARAGE_AUTO_CONTROL							0x31
#define GARAGE_MANUAL_CONTROL						0x32


/************ GARAGE CONTROL OPTIONS ***********/
#define GARAGE_OPEN									0x31
#define GARAGE_LOCK									0x32


/************ OTHER GENERAL OPTIONS ************/
#define BACK										0x30


/****************** COUNTER *******************/
#define ONE_SECOND									1
#define NO_PRELOAD									0
#define SECONDS_IN_MINUTES							59


/**************** TEMPERATURE *****************/
#define MIN_TEMP									0
#define MAX_TEMP									1


/*******************FUNCTIONS******************/
/* Name: OWNER_vidUserOptions
 * Description: main function of the owner
 * Arguments: void
 * Return:	void
 */
void OWNER_vidUserOptions(void);





/* Name: OWNER_vidMasterRoom
 * Description: display the action could take place to control the master room door/light
 * 				- check on the room status locked/open (according to door status)
 * 				- send signal to door switch
 * 				- send signal to light switch
 * 				- after each switching recall the function to update the room status
 * 				- back to the previous screen option is available
 * Arguments: void
 * Return:	void
 */
void OWNER_vidMasterRoom(void);





/* Name: OWNER_vidTenantRoom
 * Description: display the action could take place to control the tenant room's door/light
 * 				- check on the room status locked/open (according to door status)
 * 				- send signal to door switch
 * 				- send signal to light switch
 * 				- after each switching recall the function to update the room status
 * 				- back to the previous screen option is available
 * Arguments: void
 * Return:	void
 */
void OWNER_vidTenantRoom(void);




/* Name: OWNER_vidGarageControl
 * Description: display the action could take place to control the garage module
 * 				- change operation mode (Auto/Manual)
 * 				- contact with slave MC using SPI protocol
 * 				- after each switching recall the function to update the room status
 * 				- back to the previous screen option is available
 * Arguments: void
 * Return:	void
 */
void OWNER_vidGarageControl(void);




/* Name: OWNER_vidcounterDown
 * Description: implement a down counter for the period of activate party mode
 * Arguments:	Copy_u8timeMinutes  -->  options (pass the value user enter it)
 * Return:	void
 */
void OWNER_vidcounterDown(u8 Copy_u8timeMinutes);





/* Name: OWNER_u8getTemperature
 * Description: function get the temperature degree from the keypad ...
 *				user press two keys sequentially and enter it in the equation to return a number with two digits
 * Arguments:	Copy_u8TempLimit  ------->  options(MAX_TEMP, MIN_TEMP)
 * Return:	u8 ------> temperature degree
 */
u8 OWNER_u8getTemperature(u8 Copy_u8TempLimit);


#endif /* APP_OWNERUSER_H_ */
