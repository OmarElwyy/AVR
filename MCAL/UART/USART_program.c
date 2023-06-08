/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : UART_program.c													*/
/*Layer       : MCAL															*/
/*Description : This file contains functions' implemetation of UART module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_cfg.h"

void USART_voidInit(void)
{
	/*Creating Local Variable to pass the value to UCSRC*/
	u8 Local_u8UCSRCvalue ;

	/*Setting Register Select to UCSRC Register*/
	SET_BIT(Local_u8UCSRCvalue,UCSRC_URSEL);

	/*Setting USART Mode*/
#if	USART_MODE_SELECT == USART_ASYNCHORONOUS
	CLR_BIT(Local_u8UCSRCvalue,UCSRC_UMSEL);

#elif USART_MODE_SELECT == USART_SYNCHORONOUS
	SET_BIT(Local_u8UCSRCvalue,UCSRC_UMSEL);

#endif

	/*Setting Parity Mode*/
#if USART_PARITY_MODE == USART_NO_PARITY
	CLR_BIT(Local_u8UCSRCvalue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRCvalue,UCSRC_UPM0);

#elif USART_PARITY_MODE == USART_EVEN_PARITY
	SET_BIT(Local_u8UCSRCvalue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRCvalue,UCSRC_UPM0);

#elif USART_PARITY_MODE == USART_ODD_PARITY
	SET_BIT(Local_u8UCSRCvalue,UCSRC_UPM1);
	SET_BIT(Local_u8UCSRCvalue,UCSRC_UPM0);

#endif

	/*Setting USART Mode*/
#if USART_STOP_BIT == USART_1_STOP
	CLR_BIT(Local_u8UCSRCvalue,UCSRC_USBS);

#elif USART_STOP_BIT == USART_2_STOP
	SET_BIT(Local_u8UCSRCvalue,UCSRC_USBS);

#endif

	/*Setting Character Size*/
#if USART_CHARACTER_SIZE == USART_8_BIT
	SET_BIT(Local_u8UCSRCvalue,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCvalue,UCSRC_UCSZ0);

#elif USART_CHARACTER_SIZE == USART_7_BIT
	SET_BIT(Local_u8UCSRCvalue,UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCSRCvalue,UCSRC_UCSZ0);

#elif USART_CHARACTER_SIZE == USART_6_BIT
	CLR_BIT(Local_u8UCSRCvalue,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCvalue,UCSRC_UCSZ0);

#elif USART_CHARACTER_SIZE == USART_5_BIT
	CLR_BIT(Local_u8UCSRCvalue,UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCSRCvalue,UCSRC_UCSZ0);

#endif

	/*Assign the Local Variable Containing Configurations to UCSRC*/
	USART_UCSRC = Local_u8UCSRCvalue;

	/*BAUD RATE = 9600*/
	USART_UBRRL  = 51;

	/*Enable Transmitter and receiver --> full duplex operations*/
	SET_BIT(USART_UCSRB,UCSRB_RXEN);
	SET_BIT(USART_UCSRB,UCSRB_TXEN);
}

void USART_voidTransmitData(u8 Copy_u8Data)
{
	/*Make Sure UDR is Empty*/
	while(GET_BIT(USART_UCSRA,UCSRA_UDRE)==0);

	/*Assign the value to get transmitted*/
	USART_UDR = Copy_u8Data;

	/*Polling till the end of transmission*/
	while(GET_BIT(USART_UCSRA,UCSRA_TXC)==0);

	/*Clear Transmission Flag*/
	SET_BIT(USART_UCSRA,UCSRA_TXC);
}

u8 USART_u8ReceiveData(void)
{
	/*Polling till the end of Receive Data*/
	while(GET_BIT(USART_UCSRA,UCSRA_RXC)==0);

	/*Get the received Data*/
	return USART_UDR;
}

void USART_voidSendString(u8 Copy_u8Arr[])
{
	u8 i=0;
	while(Copy_u8Arr[i] != '\0')
	{
		USART_voidTransmitData(Copy_u8Arr[i]);
		i++;
	}
}

void USART_voidReceiveString(u8 * Copy_u8Arr)
{
	u8 i=0;

	Copy_u8Arr[i]=USART_u8ReceiveData();

	while(Copy_u8Arr[i] != '#')
	{
		i++;
		Copy_u8Arr[i]=USART_u8ReceiveData();
	}
	Copy_u8Arr[i] = '\0';
}
