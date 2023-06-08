/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : ICU_interface.h													*/
/*Layer       : MCAL															*/
/*Description : This file contains interfacing paremeters of ICU module			*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#include "ICU_private.h"


#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_



void TMR1NormalMode(void(*PtrToFunc)(void));

void TMR0_voidRunTimer0PWM(void);


#endif /* ICU_INTERFACE_H_ */
