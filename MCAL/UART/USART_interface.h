/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : UART_interface.h												*/
/*Layer       : MCAL															*/
/*Description : This file contains interfacing paremeters of UART module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/*************************************************************************/
/*************************Interfacing macros******************************/
/*************************************************************************/

/*************************************************************************/
/*************************Functions' prototypes***************************/
/*************************************************************************/

void USART_voidInit(void);

/*This Function Shall Transmit a Data Type*/
void USART_voidTransmitData(u8 Copy_u8Data);

/*This Function Shall Receive a Data Type*/
u8 USART_u8ReceiveData(void);

/*This Function Shall Transmit a String*/
void USART_voidSendString(u8 Copy_u8Arr[]);

/*This Function Shall Send a String*/
void USART_voidReceiveString(u8 * Copy_u8Arr);

#endif /* USART_INTERFACE_H_ */
