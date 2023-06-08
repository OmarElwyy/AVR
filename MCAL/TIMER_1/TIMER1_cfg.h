/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : TIMER1_cfg.h													*/
/*Layer       : MCAL															*/
/*Description : This file contains configurable paremeters of TIMER1 module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_


#define CRYSTAL_FREQ					8
#define PRESCALER_VALUE					8

#define NON_INVERTING					0
#define INVERTING						1

#define PWM_MODE						NON_INVERTING

#define DIVISON_FACTOR_1024				5
#define DIVISON_FACTOR_256				4
#define DIVISON_FACTOR_64				3
#define DIVISON_FACTOR_8				2
#define DIVISON_FACTOR_1				1

#define PRESCALER_MODE					DIVISON_FACTOR_8
#define BIT_MASK						0xF8


#endif /* TIMER1_CFG_H_ */
