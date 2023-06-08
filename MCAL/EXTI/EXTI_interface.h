/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : EXTI_interface.h												*/
/*Layer       : MCAL															*/
/*Description : This file contains interfacing paremeters of EXTI module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*************************************************************************/
/*************************Functions' Prototypes***************************/
/*************************************************************************/


void EXTI_voidIntInit(u8 Copy_u8INT_ID);

void EXTI_voidSetCallBackINT0(void(*Copy_ptrToFunc)(void));

void EXTI_voidSetCallBackINT1(void(*Copy_ptrToFunc)(void));

void EXTI_voidSetCallBackINT2(void(*Copy_ptrToFunc)(void));

void EXTI_SetSenseSignal_INT0(u8 Copy_u8Signal);

void EXTI_SetSenseSignal_INT1(u8 Copy_u8Signal);

void EXTI_SetSenseSignal_INT2(u8 Copy_u8Signal);

void EnableGlobalInt(u8 Copy_u8SREGPIN);

void DisableGlobalInt(u8 Copy_u8SREGPIN);


#endif /* EXTI_INTERFACE_H_ */
