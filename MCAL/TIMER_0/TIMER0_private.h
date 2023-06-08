/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : TIMER0_private.h												*/
/*Layer       : MCAL															*/
/*Description : This file contains private paremeters of TIMER0 module			*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define PRESCALER_MASK  		0xF8

#define TCCR0   			*((volatile u8 *)(0x53))

#define CS00   					0
#define CS01   					1
#define CS02   					2
#define WGM01  					3
#define COM00  					4
#define COM01  					5
#define WGM00  					6
#define FOC0   					7


#define TCNT0   			*((volatile u8 *)(0x52))

#define OCR0   				*((volatile u8 *)(0x5c))

#define TIMSK   			*((volatile u8 *)(0x59))

#define TOIE0    				0
#define OCIE0    				1

#define TIFR    			*((volatile u8 *)(0x58))

#define TOV0    				0
#define OCF0    				1

#define SREG    			*((volatile u8 *)(0x5f))
#define SREG_I  				7

#endif /* TIMER0_PRIVATE_H_ */
