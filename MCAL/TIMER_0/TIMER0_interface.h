/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : TIMER0_interface.h												*/
/*Layer       : MCAL															*/
/*Description : This file contains interfacing paremeters of TIMER0 module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#define TMR0_PRESCALER_8		2
#define TMR0_PRESCALER_64		3
#define TMR0_PRESCALER_256		4

/*This function shall start timer0*/
void TMR0_voidRunTimer0CTCAsync(void(*Copy_pfComparMatchInterrupt)(void));

/*this function shall generate a non inverted fast pwm signal from timer0*/
void TMR0_voidRunPWMFastNonInterted(void);

/*this function shall set OCR0 register value to adjust dusty cycle*/
void TMR0_voidSetOCR0Value(u8 Copy_u8OCR0Value);

#endif /* TIMER0_INTERFACE_H_ */
