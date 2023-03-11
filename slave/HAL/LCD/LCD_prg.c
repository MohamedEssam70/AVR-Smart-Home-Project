/*
 * LCD_prg.c
 *
 *  Created on: Aug 27, 2022
 *      Author: Mustafa
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>
#include "LCD_cfg.h"
#include "LCD_int.h"

static void LCD_vidSendEnable(void);


void LCD_vidInit(void)
{
	/* init the pins */
	DIO_vidInit();

	_delay_ms(32);

	/* function set */
	LCD_enuSendInstruction(LCD_u8_FUNCTION_SET);

	_delay_ms(1);
	/* display control */
	LCD_enuSendInstruction(LCD_u8_DISPLAY_ON_CURSOR_ON	);

	_delay_ms(1);
	/* display control */
	/*LCD_enuSendInstruction(LCD_u8_CLEAR_DISPALY);

	LCD_enuSendInstruction(LCD_u8_RETURN_HOME);*/

	_delay_ms(2);
	/* entry mode */
	LCD_enuSendInstruction(LCD_u8_CURSOR_INC_SHIFT_OFF);


}


LCD_tenuErrorStatus	LCD_enuSendCharacter(u8 Copy_u8Character)
{
	LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;

	/* Rs pin ----> high */
	DIO_enuSetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8_HIGH);

	/* RW pin ----> low */
	DIO_enuSetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

	/* send the data */
	DIO_enuSetPortValue(LCD_u8_D0_TO_D7_CONNECTION, Copy_u8Character);

	/* send enable */
	LCD_vidSendEnable();

	return Local_enuErrorStatus;
}



LCD_tenuErrorStatus	LCD_enuSendInstruction(u8 Copy_u8Instruction)
{
	LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;

	/* check the arguments */
	if(0)
	{
		Local_enuErrorStatus = LCD_NOK;
	}
	else
	{
		/* Rs pin ----> low */
		DIO_enuSetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8_LOW);

		/* RW pin ----> low */
		DIO_enuSetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

		/* send the instruction */
		DIO_enuSetPortValue(LCD_u8_D0_TO_D7_CONNECTION, Copy_u8Instruction);

		/*
		DIO_enuSetPinValue(LCD_u8_D0_PORT, LCD_u8_D0_PIN, (Copy_u8Instruction >> 0) & 0x01);
		DIO_enuSetPinValue(LCD_u8_D1_PORT, LCD_u8_D1_PIN, (Copy_u8Instruction >> 1) & 0x01);
		DIO_enuSetPinValue(LCD_u8_D2_PORT, LCD_u8_D2_PIN, (Copy_u8Instruction >> 2) & 0x01);
		DIO_enuSetPinValue(LCD_u8_D3_PORT, LCD_u8_D3_PIN, (Copy_u8Instruction >> 3) & 0x01);
		DIO_enuSetPinValue(LCD_u8_D4_PORT, LCD_u8_D4_PIN, (Copy_u8Instruction >> 4) & 0x01);
		DIO_enuSetPinValue(LCD_u8_D5_PORT, LCD_u8_D5_PIN, (Copy_u8Instruction >> 5) & 0x01);
		DIO_enuSetPinValue(LCD_u8_D6_PORT, LCD_u8_D6_PIN, (Copy_u8Instruction >> 6) & 0x01);
		DIO_enuSetPinValue(LCD_u8_D7_PORT, LCD_u8_D7_PIN, (Copy_u8Instruction >> 7) & 0x01);
		*/

		/* send enable */
		LCD_vidSendEnable();


	}

	return Local_enuErrorStatus;
}



LCD_tenuErrorStatus	LCD_enuSendString(u8* Add_pu8String)
{
	LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;

	if(Add_pu8String == NULL)
	{
		Local_enuErrorStatus = LCD_NOK;
	}
	else
	{
		while(*Add_pu8String != '\0')
		{
			LCD_enuSendCharacter(*Add_pu8String);
			Add_pu8String++;
		}
	}

	return Local_enuErrorStatus;
}

LCD_tenuErrorStatus	LCD_enuGoTo(u8 Copy_u8Row, u8 Copy_u8Column)
{
	LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;

	if((Copy_u8Row > LCD_u8_ROW1) || (Copy_u8Column > LCD_u8_COL15))
	{
		Local_enuErrorStatus = LCD_NOK;
	}
	else
	{
		switch(Copy_u8Row)
		{
			case LCD_u8_ROW0:
				LCD_enuSendInstruction(LCD_u8_FIRST_DDRAM_ADDRESS + Copy_u8Column);
				break;

			case LCD_u8_ROW1:
				LCD_enuSendInstruction(LCD_u8_FIRST_DDRAM_ADDRESS | (Copy_u8Column + 0x40));
				break;

		}
	}


	return Local_enuErrorStatus;
}


LCD_tenuErrorStatus	LCD_enuSendCustomCharacter(u8 *Add_pu8Pattern, u8 Copy_u8NumOfBlock, u8 Copy_u8Row, u8 Copy_u8Column)
{
	LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;
	u8 Local_u8Iterator;

	if(Add_pu8Pattern == NULL || Copy_u8NumOfBlock > 7|| (Copy_u8Row > LCD_u8_ROW1) || (Copy_u8Column > LCD_u8_COL15))
	{
		Local_enuErrorStatus = LCD_NOK;
	}
	else
	{
		LCD_enuSendInstruction(LCD_u8_FIRST_CGRAM_ADDRESS + (Copy_u8NumOfBlock * 8));

		for(Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
		{
			LCD_enuSendCharacter(Add_pu8Pattern[Local_u8Iterator]);

			_delay_ms(5);
		}

		LCD_enuGoTo(Copy_u8Row, Copy_u8Column);

		LCD_enuSendCharacter(Copy_u8NumOfBlock);
	}

	return Local_enuErrorStatus;
}
void	LCD_enuSendNumber(u32 Copy_u8Number)
{

	if(Copy_u8Number==0)
	{
		LCD_enuSendCharacter(Copy_u8Number+0x30);
	}
u8 Local_u8ArrayNumber [10] ={0};

u8 Local_u8Counter=1 ;
u8 Local_u8CounterLoop=0; // (Copy_u8Number =2019
while(Copy_u8Number!=0)
{
Local_u8ArrayNumber[Local_u8Counter]=  (Copy_u8Number%10); // x=(Copy_u8Number%10)  x= *9
Copy_u8Number=(Copy_u8Number/10);
Local_u8Counter++;
}
Local_u8Counter--;
for(Local_u8CounterLoop=Local_u8Counter;Local_u8CounterLoop>0;Local_u8CounterLoop--)
{
	LCD_enuSendCharacter((Local_u8ArrayNumber[Local_u8CounterLoop]+0x30));

}
}

/* private function */
static void LCD_vidSendEnable(void)
{
	/* send enable */
	DIO_enuSetPinValue(LCD_u8_E_PORT, LCD_u8_E_PIN, DIO_u8_HIGH);

	_delay_ms(1);

	DIO_enuSetPinValue(LCD_u8_E_PORT, LCD_u8_E_PIN, DIO_u8_LOW);
}


