/*
 * modules.h
 *
 *  Created on: Sep 20, 2022
 *      Author: Mohamed Essam
 */

#ifndef APP_MODULES_H_
#define APP_MODULES_H_








#define GARAGE_CLOSE									0
#define GARAGE_OPEN										1
#define GARAGE_DONT_CARE								2

#define GARAGE_MANUAL									0
#define GARAGE_AUTO										1





/*
 * Name: MODULE_vidGarageDoor
 * Description: setting garage door control method
 * Arguments:	first argument:  Copy_u8ControlMethod  ---->  options(GARAGE_MANUAL, GARAGE_AUTO)
 * 				second argument: Copy_u8DoorState  ---->  options(GARAGE_CLOSE, GARAGE_OPEN, GARAGE_DONT_CARE)
 * Return:	void
*/
void MODULE_vidGarageDoor(u8 Copy_u8ControlMethod, u8 Copy_u8DoorState);





void MODULE_vidTemperatureInit(u8 Copy_u8ADC_read, u8 Copy_u8InstantinusDegree);

#endif /* APP_MODULES_H_ */
