/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : WDT_program.c													*/
/*Layer       : MCAL															*/
/*Description : This file contains functions' implemetation of WDT module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/


#include "../../Library/BIT_MATHS.h"
#include "../../Library/STD_TYPES.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_cfg.h"


void WDT_voidEnable(void)
{
	SET_BIT(WDTCR , WDE);
}


void WDT_voidSetSleepTimer(u8 Copy_u8SleepTime)
{
	WDTCR &= 0b11111000;
	WDTCR |= Copy_u8SleepTime;

}


void WDT_voidDisable(void)
{
	/*Writing one at bit 3 and 4 at the same operation*/
	WDTCR |= 0b00011000;

	/*writing 1 at bit no.3*/
	WDTCR = 0;
}


