/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : DELAY_cfg.h														*/
/*Layer       : MCAL															*/
/*Description : This file contains configurable paremeters of DELAY module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef DELAY_CFG_H_
#define DELAY_CFG_H_

#define PRESCALER_MASK_1				1
#define PRESCALER_MASK_8				2
#define PRESCALER_MASK_64				3
#define PRESCALER_MASK_256				4
#define PRESCALER_MASK_1024				5

#define TMR1_PRESCALER_MODE				PRESCALER_MASK_1024
#define PRESCALER_MASK					0xF8

#endif /* DELAY_CFG_H_ */
