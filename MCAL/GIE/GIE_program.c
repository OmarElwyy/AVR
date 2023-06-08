/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : GIE_program.c													*/
/*Layer       : MCAL															*/
/*Description : This file contains functions' implemetation of GIE module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/


#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "../DIO/DIO_interface.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_cfg.h"

/*This function is to enable general interrupt*/
void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
/*This function is to disable general interrupt*/
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
