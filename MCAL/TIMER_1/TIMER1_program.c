/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : TIMER1_program.c												*/
/*Layer       : MCAL															*/
/*Description : This file contains functions' implemetation of TIMER1 module	*/
/*Date        : 22 March 2023													*/
/********************************************************************************/


#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_cfg.h"


void TMR1_voidInitFastPWM(u8 Copy_u16Channel)
{
	switch(Copy_u16Channel)
	{
	case OUTPUT_COMPARE_A:
#if		(PWM_MODE == NON_INVERTING)

		SET_BIT(TCCR1A , COM1A1);
		CLR_BIT(TCCR1A , COM1A0);

#elif	(PWM_MODE == INVERTING)

		SET_BIT(TCCR1A , COM1A1);
		SET_BIT(TCCR1A , COM1A0);

#endif
		break;

	case OUTPUT_COMPARE_B:
#if		(PWM_MODE == NON_INVERTING)

		SET_BIT(TCCR1A , COM1B1);
		CLR_BIT(TCCR1A , COM1B0);

#elif	(PWM_MODE == INVERTING)

		SET_BIT(TCCR1A , COM1B1);
		SET_BIT(TCCR1A , COM1B0);

#endif
		break;
	}

	SET_BIT(TCCR1B , WGM13);
	SET_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1A , WGM10);

}

void Set_PWM_TMR1_Frequancy(u32 Copy_u32Frequance)
{
	ICR1 = (((CRYSTAL_FREQ * 1000000) / (PRESCALER_VALUE * Copy_u32Frequance)) - 1);
}

void TMR1_voidStartFastPWM(void)
{

	TCCR1B &= BIT_MASK;
	TCCR1B |= PRESCALER_MODE;

}

void Set_Duty_Cycle_PWM_TMR1(u8 Copy_u8Channel , u16 Copy_u16Percent)
{
	u16 T_on = 0;
	T_on = ICR1 - ((100 - Copy_u16Percent) * (ICR1 / 100));

	switch(Copy_u8Channel)
	{
	case	OUTPUT_COMPARE_A :
		OCR1A = T_on;
		break;
	case	OUTPUT_COMPARE_B :
		OCR1B = T_on;
		break;
	}
}


void TMR1_voidICU(void)
{
	CLR_BIT(TCCR1B , WGM13);
	CLR_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1A , WGM10);


}







