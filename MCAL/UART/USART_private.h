/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : UART_private.h													*/
/*Layer       : MCAL															*/
/*Description : This file contains private paremeters of UART module			*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


/******************PreBuild Configurations*******************/

/*USART Modes*/
#define USART_ASYNCHORONOUS 0
#define USART_SYNCHORONOUS  1

/*Parity Selections*/
#define USART_NO_PARITY   0
#define USART_EVEN_PARITY 1
#define USART_ODD_PARITY  2

/*STOP bit Mode*/
#define USART_1_STOP 0
#define USART_2_STOP 1

/*Character Size Selections*/
#define USART_8_BIT 0
#define USART_7_BIT 1
#define USART_6_BIT 2
#define USART_5_BIT 3

/*****************Private bits*****************/

#define USART_UDR        *((volatile u8*)(0x2C))

#define USART_UCSRA      *((volatile u8*)(0x2B))
#define UCSRA_RXC      		  7
#define UCSRA_TXC      		  6
#define UCSRA_UDRE      	  5
#define UCSRA_FE      		  4
#define UCSRA_DOR      		  3
#define UCSRA_PE      		  2
#define UCSRA_U2X      		  1
#define UCSRA_MPCM     		  0

#define USART_UCSRB      *((volatile u8*)(0x2A))
#define UCSRB_RXCIE      	  7
#define UCSRB_TXCIE     	  6
#define UCSRB_UDRIE      	  5
#define UCSRB_RXEN      	  4
#define UCSRB_TXEN      	  3
#define UCSRB_UCSZ2     	  2
#define UCSRB_RXB8      	  1
#define UCSRB_TXB8     		  0

#define USART_UCSRC      *((volatile u8*)(0x40))
#define UCSRC_URSEL      	  7
#define UCSRC_UMSEL     	  6
#define UCSRC_UPM1      	  5
#define UCSRC_UPM0      	  4
#define UCSRC_USBS      	  3
#define UCSRC_UCSZ1     	  2
#define UCSRC_UCSZ0      	  1
#define UCSRC_UCPOL     	  0

#define USART_UBRRL        *((volatile u8*)(0x29))

#endif /* USART_PRIVATE_H_ */
