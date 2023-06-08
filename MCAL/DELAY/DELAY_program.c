/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : DIO_program.c													*/
/*Layer       : MCAL															*/
/*Description : This file contains functions' implemetation of DIO module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/GIE/GIE_interface.h"

#include "../../MCAL/TIMER_1/TIMER1_interface.h"
#include "DELAY_interface.h"
#include "DELAY_private.h"
#include "DELAY_cfg.h"

void(*Global_pfCTCcallbackA)(void) = NULL;
void(*Global_pfCTCcallbackB)(void) = NULL;

void TMR1_voidDelayAsyncMS(u8 Copy_u8Channel , u32 Copy_u32Time_in_ms , void(*Copy_pfComparMatchInterrupt)(void))
{
	/*Set Timer1 mode4 */
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM13);

	/*Disconnect OC1A and OC1B pins*/
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);

	switch (Copy_u8Channel)
	{
	case OUTPUT_COMPARE_A :

		/*Set value of OCR1A*/
		OCR1A = ((Copy_u32Time_in_ms * 125UL) /16);

		/*Enable compare match interrupt*/
		SET_BIT(TIMSK,OCIE1A);

		if(Copy_pfComparMatchInterrupt != NULL)
		{
			Global_pfCTCcallbackA = Copy_pfComparMatchInterrupt ;
		}
		break;

	case OUTPUT_COMPARE_B :

		/*Set value of OCR1BL*/
		OCR1B = ((Copy_u32Time_in_ms * 125UL) /16);

		/*Enable compare match interrupt*/
		SET_BIT(TIMSK,OCIE1B);

		if(Copy_pfComparMatchInterrupt != NULL)
		{
			Global_pfCTCcallbackB = Copy_pfComparMatchInterrupt ;
		}
		break;
	}

	/*Setting PreScaler*/
	TCCR1B &=PRESCALER_MASK;
	TCCR1B |=TMR1_PRESCALER_MODE;
}

void TMR1_voidDelaySyncms(u8 Copy_u8Channel , u32 Copy_u32Time_in_ms)
{
	/*Set Timer1 mode4 */
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM13);

	/*Disconnect OC1A and OC1B pins*/
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);

	/*Setting PreScaler*/
	TCCR1B &=PRESCALER_MASK;
	TCCR1B |=TMR1_PRESCALER_MODE;

	switch (Copy_u8Channel)
	{
	case OUTPUT_COMPARE_A :

		/*Set value of OCR1AL*/
		OCR1A = ((Copy_u32Time_in_ms * 125UL) /16);

		/*Polling over flag*/
		while(GET_BIT(TIFR,OCF1A) == 0);
		SET_BIT(TIFR,OCF1A);
		break;
	case OUTPUT_COMPARE_B :

		/*Set value of OCR1BL*/
		OCR1B = ((Copy_u32Time_in_ms * 125UL) /16);

		/*Polling over flag*/
		while(GET_BIT(TIFR,OCF1B) == 0);
		SET_BIT(TIFR,OCF1B);
		break;
	}
}

void __vector_7(void)__attribute__((signal));
void __vector_7(void)
{
	if(Global_pfCTCcallbackA != NULL)
	{
		Global_pfCTCcallbackA();
	}
	else
	{

	}
}

void __vector_8(void)__attribute__((signal));
void __vector_8(void)
{
	if(Global_pfCTCcallbackB != NULL)
	{
		Global_pfCTCcallbackB();
	}
	else
	{

	}
}
