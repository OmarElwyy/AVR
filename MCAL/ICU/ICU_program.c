/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : ICU_program.c													*/
/*Layer       : MCAL															*/
/*Description : This file contains functions' implemetation of ICU module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "../DIO/DIO_interface.h"
#include "../TIMER_0/TIMER0_interface.h"
#include "../GIE/GIE_interface.h"
#include "../EXTI/EXTI_interface.h"
#include "../EXTI/EXTI_cfg.h"
#include "ICU_interface.h"
#include "ICU_private.h"
#include "ICU_cfg.h"

void (*Global_PtrToFunc)(void) = NULL;

void TMR1NormalMode(void(*PtrToFunc)(void))
{

	/*Set Sense Signal to High*/
	SET_BIT(TCCR1B,ICES1);

	/*This Bits is to Start Normal Mode*/
	CLR_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);

	CLR_BIT(TCCR1A , 7);
	CLR_BIT(TCCR1A , 6);
	CLR_BIT(TCCR1A , 5);
	CLR_BIT(TCCR1A , 4);

	/*Enable ICU Interrupt*/
	SET_BIT(TIMSK,TICIE1);

	if(PtrToFunc != NULL)
	{
		Global_PtrToFunc = PtrToFunc;
	}

	/*Prescaler 8*/
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);

}

void TMR0_voidRunTimer0PWM(void)
{
	/*Fast PWM*/
	SET_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);

	/*NON-Inverting*/
	SET_BIT(TCCR0 , COM01);
	CLR_BIT(TCCR0 , COM00);

	OCR0 = 128;

	/*Prescaler 8*/
	CLR_BIT(TCCR0 , CS02);
	SET_BIT(TCCR0 , CS01);
	CLR_BIT(TCCR0 , CS00);

}

void __vector_6(void)__attribute__((signal));
void __vector_6(void)
{
	if (Global_PtrToFunc != NULL)
	{
		Global_PtrToFunc();
	}
	else
	{

	}
}







