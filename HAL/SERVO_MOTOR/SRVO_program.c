/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : SRVO_program.c													*/
/*Layer       : HAL																*/
/*Description : This file contains functions' implemetation of SRVO module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#include "../../Library/BIT_MATHS.h"
#include "../../Library/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER_1/TIMER1_interface.h"
#include "../../MCAL/TIMER_1/TIMER1_private.h"
#include "SRVO_interface.h"
#include "SRVO_private.h"
#include "SRVO_cfg.h"


void Set_voidServoInit(u8 Copy_u8Channel)
{
	switch(Copy_u8Channel)
	{
	case OUTPUT_COMPARE_A :
		DIO_voidSetPinDirection(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
		break;
	case OUTPUT_COMPARE_B :
		DIO_voidSetPinDirection(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
		break;
	}
}

void SetAngle(u8 Copy_u8Channel , u16 Copy_u16Angle)
{
	u16 MappingValue = 0 ;
	MappingValue = (750 + ((175 / 18) * Copy_u16Angle));

	if (Copy_u8Channel == OUTPUT_COMPARE_A)
	{
		OCR1A = MappingValue ;
	}
	else if (Copy_u8Channel == OUTPUT_COMPARE_B)
	{
		OCR1B = MappingValue ;
	}
}
