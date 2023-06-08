/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : SSD_program.c													*/
/*Layer       : HAL																*/
/*Description : This file contains functions' implemetation of SSD module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/


#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_cfg.h"


/******************************************************************************/
/*************************Functions' implementation****************************/
/******************************************************************************/


void SSD_void_Init(u8 Copy_u8Connection , u8 SSD_PORT , u8 COM_PORT , u8 COM_PIN)
{
	switch(Copy_u8Connection)
	{
	case COM_ANODE:
		DIO_voidSetPortDirection(SSD_PORT , DIO_PORT_OUTPUT);
		DIO_voidSetPinDirection(COM_PORT , COM_PIN , DIO_LOW_PIN);
		break;
	case COM_CATHOD:
		DIO_voidSetPortDirection(SSD_PORT , DIO_PORT_OUTPUT);
		DIO_voidSetPinDirection(COM_PORT , COM_PIN , DIO_HIGH_PIN);
		break;
	}
}

void SSD_void_ON(u8 Copy_u8Connection , u8 COM_PORT , u8 COM_PIN)
{
	switch(Copy_u8Connection)
	{
	case COM_ANODE:
		DIO_voidSetPinValue(COM_PORT , COM_PIN , DIO_HIGH_PIN);
		break;
	case COM_CATHOD:
		DIO_voidSetPinValue(COM_PORT , COM_PIN , DIO_LOW_PIN);
		break;
	}
}

void SSD_void_DISPLAY_NUMBER(u8 SSD_PORT , u8 SSD_Value)
{
	DIO_u8SetPortValue(SSD_PORT , SSD_Value);
}


void SSD_void_OFF(u8 Copy_u8Connection , u8 COM_PORT , u8 COM_PIN)
{
	switch(Copy_u8Connection)
	{
	case COM_ANODE:
		DIO_voidSetPinValue(COM_PORT , COM_PIN , DIO_LOW_PIN);
		break;
	case COM_CATHOD:
		DIO_voidSetPinValue(COM_PORT , COM_PIN , DIO_HIGH_PIN);
		break;
	}
}


