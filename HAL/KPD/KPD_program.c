/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : KPD_program.c													*/
/*Layer       : HAL																*/
/*Description : This file contains functions' implemetation of KPD module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "../KPD/KPD_cfg.h"
#include "../KPD/KPD_interface.h"
#include "../KPD/KPD_private.h"

void KPD_voidInit (void)
{
	/*1)initialize all rows to be input pull up*/
	DIO_voidSetPinDirection(KPD_PORT , KPD_ROW0 , DIO_PIN_INPUT_PULLUP);
	DIO_voidSetPinDirection(KPD_PORT , KPD_ROW1 , DIO_PIN_INPUT_PULLUP);
	DIO_voidSetPinDirection(KPD_PORT , KPD_ROW2 , DIO_PIN_INPUT_PULLUP);
	DIO_voidSetPinDirection(KPD_PORT , KPD_ROW3 , DIO_PIN_INPUT_PULLUP);


	/*2)initialize all columns to be output*/
	DIO_voidSetPinDirection(KPD_PORT , KPD_COL0 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT , KPD_COL1 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT , KPD_COL2 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT , KPD_COL3 , DIO_PIN_OUTPUT);


	/*3)setting the columns to be high*/
	DIO_voidSetPinValue(KPD_PORT , KPD_COL0 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(KPD_PORT , KPD_COL1 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(KPD_PORT , KPD_COL2 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(KPD_PORT , KPD_COL3 , DIO_HIGH_PIN);
}


u8 KPD_u8GetPressedKey(void)
{
	/*Local Variable to check Whether Switch is Pressed or Not*/
	u8 Local_u8State;

	/*Local Variable to store Value of Pressed Key*/
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;

	/*Local variable to Iterate Over Rows and Columns*/
	u8 Local_u8RowIterator;
	u8 Local_u8ColIterator;

	u8 Local_au8Cols[COL_NUM] = {KPD_COL0 , KPD_COL1 , KPD_COL2 , KPD_COL3};
	u8 Local_au8Rows[COL_NUM] = {KPD_ROW0 , KPD_ROW1 , KPD_ROW2 , KPD_ROW3};

	u8 KPD_ARR[ROW_NUM][COL_NUM] = KPD_VALUES;

	/*loop for Columns to Activate them*/
	for(Local_u8ColIterator = 0 ; Local_u8ColIterator < COL_NUM ; Local_u8ColIterator++)
	{
		/*Activate Columns*/
		DIO_voidSetPinValue(KPD_PORT ,Local_au8Cols[Local_u8ColIterator] , DIO_LOW_PIN );

		/*Loop for Rows to Read Them*/
		for(Local_u8RowIterator = 0 ; Local_u8RowIterator < ROW_NUM ; Local_u8RowIterator++)
		{
			/*Checking Whether Switch is Pressed*/
			Local_u8State = DIO_u8GetPinValue(KPD_PORT , Local_au8Rows[Local_u8RowIterator]);

			if(Local_u8State == 0)
			{
				/*Get The Value of The Pressed Key*/
				Local_u8PressedKey = KPD_ARR[Local_u8RowIterator][Local_u8ColIterator];

				/*Polling till the user release the Switch*/
				while(Local_u8State == 0)
				{
					Local_u8State = DIO_u8GetPinValue(KPD_PORT , Local_au8Rows[Local_u8RowIterator]);
				}
				/*Deactivate the Recent Columns before return*/
				DIO_voidSetPinValue(KPD_PORT ,Local_au8Cols[Local_u8ColIterator] , DIO_HIGH_PIN);

				/*Ending The Loop*/
				return Local_u8PressedKey ;
			}
		}
		/*Deactivate Columns*/
		DIO_voidSetPinValue(KPD_PORT ,Local_au8Cols[Local_u8ColIterator] , DIO_HIGH_PIN);
	}
	return Local_u8PressedKey;
}
