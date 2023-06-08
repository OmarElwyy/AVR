/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : STPR_program.c													*/
/*Layer       : HAL																*/
/*Description : This file contains functions' implemetation of STPR module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#include<util/delay.h>

#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "STPR_motor_interface.h"
#include "STPR_motor_private.h"
#include "STPR_motor_cfg.h"


void STPR_voidStprInit()
{
	DIO_voidSetPinDirection(STPR_PORT,STPR_PIN0,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(STPR_PORT,STPR_PIN0,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(STPR_PORT,STPR_PIN0,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(STPR_PORT,STPR_PIN0,DIO_PIN_OUTPUT);
}

void STPR_voidStprMoveingForword()
{

	u8 ARF[4]=Forward_value;

	for(u8 i=0;i<4;i++)
	{
		DIO_voidSetPinValue(STPR_PORT,STPR_PIN0,STPR_HIGH);
		DIO_voidSetPinValue(STPR_PORT,STPR_PIN1,STPR_HIGH);
		DIO_voidSetPinValue(STPR_PORT,STPR_PIN2,STPR_HIGH);
		DIO_voidSetPinValue(STPR_PORT,STPR_PIN3,STPR_HIGH);
		DIO_voidSetPinValue(STPR_PORT,ARF[i],STPR_Low);
		_delay_ms(10);

	}
}

void STPR_voidStprMoveingBackword()
{

	u8 ARB[4]=Backward_value;

	for(u8 i=0;i<4;i++)
	{
		DIO_voidSetPinValue(STPR_PORT,STPR_PIN0,STPR_HIGH);
		DIO_voidSetPinValue(STPR_PORT,STPR_PIN1,STPR_HIGH);
		DIO_voidSetPinValue(STPR_PORT,STPR_PIN2,STPR_HIGH);
		DIO_voidSetPinValue(STPR_PORT,STPR_PIN3,STPR_HIGH);
		DIO_voidSetPinValue(STPR_PORT,ARB[i],STPR_Low);
		_delay_ms(10);
	}
}

void STPR_voidStprRotate_CW_WithAngle(u8 Copy_u8StprAngle)
{

	u8 ARF[4]=Forward_value;
	u8 x=0;

	x=(Copy_u8StprAngle/0.175)/4;

	while(x>0)
	{
		for(u8 i=0;i<4;i++)
		{
			DIO_voidSetPinValue(STPR_PORT,STPR_PIN0,STPR_HIGH);
			DIO_voidSetPinValue(STPR_PORT,STPR_PIN1,STPR_HIGH);
			DIO_voidSetPinValue(STPR_PORT,STPR_PIN2,STPR_HIGH);
			DIO_voidSetPinValue(STPR_PORT,STPR_PIN3,STPR_HIGH);
			DIO_voidSetPinValue(STPR_PORT,ARF[i],STPR_Low);
			_delay_ms(10);
		}
		x--;
	}
}

void STPR_voidStprRotate_CCW_WithAngle(u8 Copy_u8StprAngle)
{

	u8 ARB[4]=Backward_value;
	u8 x=0;

	x=(Copy_u8StprAngle/0.175)/4;

	while(x>0)
	{
		for(u8 i=0;i<4;i++)
		{
			DIO_voidSetPinValue(STPR_PORT,STPR_PIN0,STPR_HIGH);
			DIO_voidSetPinValue(STPR_PORT,STPR_PIN1,STPR_HIGH);
			DIO_voidSetPinValue(STPR_PORT,STPR_PIN2,STPR_HIGH);
			DIO_voidSetPinValue(STPR_PORT,STPR_PIN3,STPR_HIGH);
			DIO_voidSetPinValue(STPR_PORT,ARB[i],STPR_Low);
			_delay_ms(10);
		}
		x--;
	}

}
void STPR_voidStprStop()
{
	DIO_voidSetPinValue(STPR_PORT,STPR_PIN0,STPR_HIGH);
	DIO_voidSetPinValue(STPR_PORT,STPR_PIN1,STPR_HIGH);
	DIO_voidSetPinValue(STPR_PORT,STPR_PIN2,STPR_HIGH);
	DIO_voidSetPinValue(STPR_PORT,STPR_PIN3,STPR_HIGH);
}
