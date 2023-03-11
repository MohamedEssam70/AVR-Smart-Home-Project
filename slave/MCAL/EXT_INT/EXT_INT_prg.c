/*
 * EXT_INT_prg.c
 *
 *  Created on: Sep 1, 2022
 *      Author: Mohamed Essam
 */



#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "EXT_INT_prv.h"
#include "EXT_INT_int.h"
#include "../GLOBAL_INT/GLOBAL_INT_int.h"


/* Name: EXTI_vidEnable
 * Description: activate the interrupt and select the interrupt sense control
 * Arguments: Arguments:
 * 				first Argument: Copy_u8ExtIntPin, 			options (INT0, INT1, INT2)
 * 				second Argument: Copy_u8SenseControl, 		options (EXTI_u8_LOW_LEVEL, EXTI_u8_LOGICAL_CHANGE,
																	EXTI_u8_FALLING_EDGE, EXTI_u8_RISING_EDGE)
 * Return:	void
 */
EXTI_tenuErrorStatus EXTI_vidEnable(u8 Copy_u8ExtIntPin, u8 Copy_u8SenseControl){
	EXTI_tenuErrorStatus Local_enuErrorStatus = EXTI_OK;
	/*check arguments*/
	if(Copy_u8ExtIntPin > 2 || Copy_u8SenseControl > 3){
		Local_enuErrorStatus = EXTI_NOK;
	} else{
		switch (Copy_u8ExtIntPin){
			case EXTI_u8_INT0:
				if(Copy_u8SenseControl == EXTI_u8_LOW_LEVEL){
					SET_BIT(EXTI_u8_MCUCR_REG, EXTI_INT0_LOW_LEVEL);
				} else if(Copy_u8SenseControl == EXTI_u8_LOGICAL_CHANGE){
					SET_BIT(EXTI_u8_MCUCR_REG, EXTI_INT0_LOGIC_CHANGE);
				} else if(Copy_u8SenseControl == EXTI_u8_FALLING_EDGE){
					SET_BIT(EXTI_u8_MCUCR_REG, EXTI_INT0_FALLING_EDGE);
				} else if(Copy_u8SenseControl == EXTI_u8_RISING_EDGE){
					SET_BIT(EXTI_u8_MCUCR_REG, EXTI_INT0_RISING_EDGE);
				} else { /*....*/ }
				SET_BIT(EXTI_u8_GICR_REG, EXTI_INABLE_INT0_INTERRUPT);
				break;
			case EXTI_u8_INT1:
				if(Copy_u8SenseControl == EXTI_u8_LOW_LEVEL){
					SET_BIT(EXTI_u8_MCUCR_REG, EXTI_INT1_LOW_LEVEL);
				} else if(Copy_u8SenseControl == EXTI_u8_LOGICAL_CHANGE){
					SET_BIT(EXTI_u8_MCUCR_REG, EXTI_INT1_LOGIC_CHANGE);
				} else if(Copy_u8SenseControl == EXTI_u8_FALLING_EDGE){
					SET_BIT(EXTI_u8_MCUCR_REG, EXTI_INT1_FALLING_EDGE);
				} else if(Copy_u8SenseControl == EXTI_u8_RISING_EDGE){
					SET_BIT(EXTI_u8_MCUCR_REG, EXTI_INT1_RISING_EDGE);
				} else { /*....*/ }
				SET_BIT(EXTI_u8_GICR_REG, EXTI_INABLE_INT1_INTERRUPT);
				break;
			case EXTI_u8_INT2:
				if(Copy_u8SenseControl == EXTI_u8_FALLING_EDGE){
					SET_BIT(EXTI_u8_MCUCR_REG, EXTI_INT2_FALLING_EDGE);
				} else if(Copy_u8SenseControl == EXTI_u8_RISING_EDGE){
					SET_BIT(EXTI_u8_MCUCR_REG, EXTI_INT2_RISING_EDGE);
				} else { /*....*/ }
				SET_BIT(EXTI_u8_GICR_REG, EXTI_INABLE_INT2_INTERRUPT);
				break;
			default:
				break;
		}
		GINT_vidEnable();
	}
	return Local_enuErrorStatus;
}




/* Name: EXTI_vidDisable
 * Description: deactivate the interrupt and select the interrupt sense control
 * Arguments: Arguments:
 * 				first Argument: Copy_u8ExtIntPin, 			options (INT0, INT1, INT2)																	EXTI_u8_FALLING_EDGE, EXTI_u8_RISING_EDGE)
 * Return:	void
 */

EXTI_tenuErrorStatus EXTI_vidDisable(u8 Copy_u8ExtIntPin){
	EXTI_tenuErrorStatus Local_enuErrorStatus = EXTI_OK;

	/*check arguments*/
	if(Copy_u8ExtIntPin > 2){
		Local_enuErrorStatus = EXTI_NOK;
	} else{
		switch(Copy_u8ExtIntPin){
			case EXTI_u8_INT0:
				CLEAR_BIT(EXTI_u8_GICR_REG, EXTI_INABLE_INT0_INTERRUPT);
				break;
			case EXTI_u8_INT1:
				CLEAR_BIT(EXTI_u8_GICR_REG, EXTI_INABLE_INT1_INTERRUPT);
				break;
			case EXTI_u8_INT2:
				CLEAR_BIT(EXTI_u8_GICR_REG, EXTI_INABLE_INT2_INTERRUPT);
				break;
		}
	}

	return Local_enuErrorStatus;
}

