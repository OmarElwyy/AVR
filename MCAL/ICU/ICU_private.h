/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : ICU_private.h													*/
/*Layer       : MCAL															*/
/*Description : This file contains private paremeters of ICU module				*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef ICU_PRIVATE_H_
#define ICU_PRIVATE_H_

#define PRESCALER_MASK  				0xF8
#define PRESCALER_8  					2


#define TCCR0   *((volatile u8 *)(0x53))

#define CS00   0
#define CS01   1
#define CS02   2
#define WGM01  3
#define COM00  4
#define COM01  5
#define WGM00  6
#define FOC0   7


#define TCNT0   *((volatile u8 *)(0x52))

#define OCR0    *((volatile u8 *)(0x5c))

#define TIMSK   *((volatile u8 *)(0x59))

#define TOIE0    0
#define OCIE0    1

#define TIFR    *((volatile u8 *)(0x58))

#define TOV0    0
#define OCF0    1

#define SREG    *((volatile u8 *)(0x5f))
#define SREG_I  7

#define TCCR1A  *((volatile u8 *)(0x4f))
#define WGM10  0
#define WGM11  1
#define FOC1B  2
#define FOC1A  3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

#define TCCR1B  *((volatile u8 *)(0x4e))

#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define TCNT1L    *((volatile u16 *)(0x4c))
#define OCR1AL    *((volatile u16 *)(0x4a))
#define OCR1BL    *((volatile u16 *)(0x48))
#define ICR1      *((volatile u16 *)(0x46))

//#define TIMSK     *((volatile u8 *)(0x59))

#define TOIE1     2
#define OCIE1B    3
#define OCIE1A    4
#define TICIE1    5

//#define TIFR      *((volatile u8 *)(0x58))
#define TOV1     2
#define OCF1B    3
#define OCF1A    4
#define ICF1     5
#define TOV0     0

#endif /* ICU_PRIVATE_H_ */
