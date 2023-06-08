/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : STPR_cfg.h														*/
/*Layer       : HAL																*/
/*Description : This file contains configurable paremeters of STPR module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef HAL_STEPPER_MOTOR_STPR_MOTOR_CONFG_H_
#define HAL_STEPPER_MOTOR_STPR_MOTOR_CONFG_H_


#define STPR_PORT 	DIO_PORTA

#define STPR_PIN0 	DIO_PIN3
#define STPR_PIN1 	DIO_PIN4
#define STPR_PIN2	DIO_PIN5
#define STPR_PIN3 	DIO_PIN6

#define STPR_HIGH		1
#define STPR_Low  		0

#define Forward_value {STPR_PIN0,STPR_PIN1,STPR_PIN2,STPR_PIN3}
#define Backward_value {STPR_PIN3,STPR_PIN2,STPR_PIN1,STPR_PIN0}


#endif /* HAL_STEPPER_MOTOR_STPR_MOTOR_CONFG_H_ */
