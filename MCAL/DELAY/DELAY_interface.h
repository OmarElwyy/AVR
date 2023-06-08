/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : DELAY_interface.h												*/
/*Layer       : MCAL															*/
/*Description : This file contains interfacing paremeters of DELAY module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef DELAY_INTERFACE_H_
#define DELAY_INTERFACE_H_

void TMR1_voidDelayAsyncMS(u8 Copy_u8Channel , u32 Copy_u32Time_in_ms , void(*Copy_pfComparMatchInterrupt)(void));

void TMR1_voidDelaySyncms(u8 Copy_u8Channel , u32 Copy_u32Time_in_ms);

#endif /* DELAY_INTERFACE_H_ */
