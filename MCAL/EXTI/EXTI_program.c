/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : EXTI_program.c													*/
/*Layer       : MCAL															*/
/*Description : This file contains functions' implemetation of EXTI module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#include <util/delay.h>

#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_cfg.h"
#include "EXTI_private.h"

void (*EXTI_Int0CallBack)(void) = NULL;
void (*EXTI_Int1CallBack)(void) = NULL;
void (*EXTI_Int2CallBack)(void) = NULL;

/******************************************************************************/
/*************************Functions' Implementation****************************/
/******************************************************************************/


void EXTI_voidIntInit(u8 Copy_u8INT_ID)
{
	switch(Copy_u8INT_ID)
	{
	case INT0 :
		SET_BIT(GICR,GICR_INT0);//SIE
		break;
	case INT1 :
		SET_BIT(GICR,GICR_INT1);//SIE
		break;
	case INT2 :
		SET_BIT(GICR,GICR_INT2);//SIE
		break;
	}
}

void EXTI_voidSetCallBackINT0(void(*Copy_ptrToFunc)(void))
{
	if(Copy_ptrToFunc != NULL)
	{
		EXTI_Int0CallBack=Copy_ptrToFunc;
	}
	else
	{

	}
}

void EXTI_voidSetCallBackINT1(void(*Copy_ptrToFunc)(void))
{
	if(Copy_ptrToFunc != NULL)
	{
		EXTI_Int1CallBack=Copy_ptrToFunc;
	}
	else
	{

	}
}

void EXTI_voidSetCallBackINT2(void(*Copy_ptrToFunc)(void))
{
	if(Copy_ptrToFunc != NULL)
	{
		EXTI_Int2CallBack=Copy_ptrToFunc;
	}
	else
	{

	}
}


void EXTI_voidIntDisable(u8 Copy_u8INT_ID)
{
	switch(Copy_u8INT_ID)
	{
	case INT0 :
		CLR_BIT(GICR,6);					//SIE
		break;
	case INT1 :
		CLR_BIT(GICR,7);					//SIE
		break;
	case INT2 :
		CLR_BIT(GICR,5);					//SIE
		break;
	}
}

void EXTI_SetSenseSignal_INT0(u8 Copy_u8Signal)
{
	switch(Copy_u8Signal)
	{
	case LOW_LEVEL :
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case ON_CHANGE :
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case FALLING_EDGE :
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	case RISING_EDGE :
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	}
}

void EXTI_SetSenseSignal_INT1(u8 Copy_u8Signal)
{
    switch(Copy_u8Signal)
    {
    case LOW_LEVEL :
    	CLR_BIT(MCUCR,2);
    	CLR_BIT(MCUCR,3);
        break;
    case ON_CHANGE :
        SET_BIT(MCUCR,2);
        CLR_BIT(MCUCR,3);
        break;
    case FALLING_EDGE :
    	CLR_BIT(MCUCR,2);
        SET_BIT(MCUCR,3);
        break;
    case RISING_EDGE :
        SET_BIT(MCUCR,2);
        SET_BIT(MCUCR,3);
        break;

    }
}

void EXTI_SetSenseSignal_INT2(u8 Copy_u8Signal)
{
    switch(Copy_u8Signal)
    {
    case FALLING_EDGE:
    	CLR_BIT(MCUCSR,6);
        break;
    case RISING_EDGE:
        SET_BIT(MCUCSR,6);
        break;
    }
}

/*ISR for INT0*/
void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{

	if(EXTI_Int0CallBack !=NULL)
	{
		EXTI_Int0CallBack();
	}
	else
	{

	}
}

/*ISR for INT1*/
void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	if(EXTI_Int1CallBack !=NULL)
	{
		EXTI_Int1CallBack();
	}
	else
	{

	}
}

/*ISR for INT2*/
void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	if(EXTI_Int2CallBack !=NULL)
	{
		EXTI_Int2CallBack();
	}
	else
	{

	}
}

void EnableGlobalInt(u8 Copy_u8SREGPIN)
{
 SET_BIT(SREG,SREG_I);
}

void DisableGlobalInt(u8 Copy_u8SREGPIN)
{
 CLR_BIT(SREG,SREG_I);
}

