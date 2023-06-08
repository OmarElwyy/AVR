/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : TIMER0_program.c												*/
/*Layer       : MCAL															*/
/*Description : This file contains functions' implemetation of TIMER0 module	*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"


#include "../DIO/DIO_interface.h"
#include "../GIE/GIE_interface.h"

#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_cfg.h"

void(*Global_pfCTCcallback)(void) = NULL;

void TMR0_voidRunTimer0CTCAsync(void(*Copy_pfComparMatchInterrupt)(void))
{
	/*Set timer0 mode to CTC*/
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);

	/*Disconnect OC0 pin*/
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);

	/*setting compare match value to be 250
	 *Compare match interrupt every 125 microsec
	 */
	OCR0 = 0;
	/*Enable compare match interrupt*/
	CLR_BIT(TIMSK,OCIE0);

	/*Enable Global Interrupt
	 *GIE_voidEnable();
	 */
	SET_BIT(SREG , SREG_I);

	if(Copy_pfComparMatchInterrupt != NULL)
	{
		Global_pfCTCcallback = Copy_pfComparMatchInterrupt ;
	}

	/*Setting Prescaler -> 8*/
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= TMR0_PRESCALER_64;

}

void TMR0_voidRunPWMFastNonInterted(void)
{
	/*Set Timer0 mode to be PWM*/
	SET_BIT(TCCR0, WGM01);
	SET_BIT(TCCR0, WGM00);

	/*Disconnecting OC0 pin*/
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);

	/*Setting prescaler*/
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= TMR0_PRESCALER_64;
}

void TMR0_voidSetOCR0Value(u8 Copy_u8OCR0Value)
{
	OCR0 = Copy_u8OCR0Value;
}


void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	if(Global_pfCTCcallback != NULL)
	{
		Global_pfCTCcallback();
	}
	else
	{

	}
}
