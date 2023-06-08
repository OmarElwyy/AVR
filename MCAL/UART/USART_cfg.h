/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : UART_cfg.h														*/
/*Layer       : MCAL															*/
/*Description : This file contains configurable paremeters of UART module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef USART_CFG_H_
#define USART_CFG_H_

/*USART_ASYNCHORONOUS
 *USART_SYNCHORONOUS */
#define USART_MODE_SELECT USART_ASYNCHORONOUS

/*USART_NO_PARITY
 *USART_EVEN_PARITY
 *USART_ODD_PARITY */
#define USART_PARITY_MODE USART_NO_PARITY

/*USART_1_STOP
 *USART_2_STOP */
#define USART_STOP_BIT USART_1_STOP

/*USART_8_BIT
 *USART_7_BIT
 *USART_6_BIT
 *USART_5_BIT */
#define USART_CHARACTER_SIZE USART_8_BIT

#endif /* USART_CFG_H_ */
