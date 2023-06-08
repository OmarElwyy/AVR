/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : SRVO_interface.h												*/
/*Layer       : HAL																*/
/*Description : This file contains interfacing paremeters of SRVO module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef SRVO_INTERFACE_H_
#define SRVO_INTERFACE_H_

void Set_voidServoInit(u8 Copy_u8Channel);

void SetAngle(u8 Copy_u8Channel , u16 Copy_u16Angle);

#endif /* SRVO_INTERFACE_H_ */
