/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : STPR_interface.h												*/
/*Layer       : HAL																*/
/*Description : This file contains interfacing paremeters of STPR module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef HAL_STEPPER_MOTOR_STPR_MOTOR_INTERFACE_H_
#define HAL_STEPPER_MOTOR_STPR_MOTOR_INTERFACE_H_



void STPR_voidStprInit();

void STPR_voidStprMoveingForword();

void STPR_voidStprMoveingBackword();

void STPR_voidStprRotate_CW_WithAngle(u8 Copy_u8StprAngle);

void STPR_voidStprRotate_CCW_WithAngle(u8 Copy_u8StprAngle);

void STPR_voidStprStop();


#endif /* HAL_STEPPER_MOTOR_STPR_MOTOR_INTERFACE_H_ */
