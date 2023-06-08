/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : LED_program.c													*/
/*Layer       : HAL																*/
/*Description : This file contains functions' implemetation of LED module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#include "../../Library/BIT_MATHS.h"
#include "../../Library/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_cfg.h"




/******************************************************************************/
/*************************Functions' implementation****************************/
/******************************************************************************/

void LED_voidLEDinit(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	DIO_voidSetPinDirection(Copy_u8PortID , Copy_u8Pin , LED_ON);
}

void LED_voidLED_ON(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	DIO_voidSetPinValue(Copy_u8PortID , Copy_u8Pin , DIO_HIGH_PIN);
}

void LED_voidLED_OFF(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	DIO_voidSetPinValue(Copy_u8PortID , Copy_u8Pin , DIO_LOW_PIN);
}

void LED_voidLED_TGL(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	DIO_voidTogglePin(Copy_u8PortID , Copy_u8Pin);
}
