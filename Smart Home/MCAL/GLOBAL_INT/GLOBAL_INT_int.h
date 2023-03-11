/*
 * GLOBAL_INT_int.h
 *
 *  Created on: Sep 3, 2022
 *      Author: Mohamed Essam
 */

#ifndef MCAL_GLOBAL_INT_GLOBAL_INT_INT_H_
#define MCAL_GLOBAL_INT_GLOBAL_INT_INT_H_



/**************ERROR STATUS********************/
typedef enum {
	GINT_OK,
	GINT_NOK
}GINT_tenuErrorStatus;




/******************MACROS***********************/
#define SREG_BIT_I				0x80







/*************FUNCTIONS*****************/
/* Name: GINT_vidEnable
 * Description: set bit 7 in the SREG
 * Arguments: void
 * Return:	void
 */
void GINT_vidEnable(void);




/* Name: GINT_vidDisable
 * Description: clear bit 7 in the SREG
 * Arguments: void
 * Return:	void
 */
void GINT_vidDisable(void);



#endif /* MCAL_GLOBAL_INT_GLOBAL_INT_INT_H_ */
