/*
 * GLOBAL_INT_prg.c
 *
 *  Created on: Sep 3, 2022
 *      Author: Mohamed Essam
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "GLOBAL_INT_int.h"
#include "GLOBAL_INT_prv.h"



/* Name: GINT_vidEnable
 * Description: set bit 7 in the SREG
 * Arguments: void
 * Return:	void
 */
void GINT_vidEnable(void){
	EXTI_u8_SREG = SREG_BIT_I;
}




/* Name: GINT_vidDisable
 * Description: clear bit 7 in the SREG
 * Arguments: void
 * Return:	void
 */
void GINT_vidDisable(void){
	CLEAR_BIT(EXTI_u8_SREG, SREG_BIT_I);
}

