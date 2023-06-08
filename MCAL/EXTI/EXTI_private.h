/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : EXTI_private.h													*/
/*Layer       : MCAL															*/
/*Description : This file contains private paremeters of EXTI module			*/
/*Date        : 22 March 2023													*/
/********************************************************************************/


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define MCUCR       		 (*(volatile u8 *)(0x55))
#define MCUCR_ISC00				0
#define MCUCR_ISC01				1
#define MCUCR_ISC10				2
#define MCUCR_ISC11				3

#define MCUCSR     		  	(*(volatile u8 *)(0x54))
#define MCUCSR_ISC2				6

#define GICR         		(*(volatile u8 *)(0x5B))			//SIE (Specific interrupt Enable)
#define GICR_INT0				6					//Enable Interrupt 0
#define GICR_INT1				7					//Enable Interrupt 1
#define GICR_INT2				5					//Enable Interrupt 2

#define GIFR        		(*(volatile u8 *)(0x5A))			//Flag
#define GIFR_INTF0				6					//Flag For Interrupt 0
#define GIFR_INTF1				7					//Flag For Interrupt 1
#define GIFR_INTF2				5					//Flag For Interrupt 7

#define SREG         		(*(volatile u8 *)(0x5F))			//GIE (General interrupt Enable)
#define SREG_I					7

#define ISR(INt_vect) void INt_vect(void)__attribute__((signal,used));\
void INt_vect(void)

#define EXTINT_0   			__vector_1
#define EXTINT_1   			__vector_2
#define EXTINT_2   			__vector_3



#endif /* EXTI_PRIVATE_H_ */
