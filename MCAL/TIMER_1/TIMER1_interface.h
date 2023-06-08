/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : TIMER1_cfg.h													*/
/*Layer       : MCAL															*/
/*Description : This file contains configurable paremeters of TIMER1 module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#define OUTPUT_COMPARE_A			0
#define OUTPUT_COMPARE_B			1

void TMR1_voidInitFastPWM(u8 Copy_u16Channel);

void Set_PWM_TMR1_Frequancy(u32 Copy_u32Frequance);

void Set_Duty_Cycle_PWM_TMR1(u8 Copy_u8Channel , u16 Copy_u16Percent);

void TMR1_voidStartFastPWM(void);

void TMR1_voidICU(void);


#endif /* TIMER1_INTERFACE_H_ */
