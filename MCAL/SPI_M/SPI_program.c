/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : SPI_program.c													*/
/*Layer       : MCAL															*/
/*Description : This file contains functions' implemetation of SPI module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/


#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_cfg.h"

void SPI_voidMasterInit(void)
{
	/*Set the node to be a master*/
	SET_BIT(SPCR, SPCR_MSTR);

	/*Disable interrupt*/
	CLR_BIT(SPCR, SPCR_SPIE);

	/*Enable SPI peripheral*/
	SET_BIT(SPCR ,SPCR_SPE);

	/*Data order -> LSB FIRST*/
	SET_BIT(SPCR , SPCR_DORD);

	/*Clock polarity -> idle state = LOW*/
	CLR_BIT(SPCR ,SPCR_CPOL);

	/*Clock phase -> SAMPLE FIRST*/
	CLR_BIT(SPCR ,SPCR_CPHA);

	/*Prescaler -> 16*/
	SET_BIT(SPCR , SPCR_SPR0);
	CLR_BIT(SPCR , SPCR_SPR1);
}

void SPI_voidSlaveInit(void)
{
	/*Set the node to be a slave*/
	CLR_BIT(SPCR, SPCR_MSTR);

	/*Disable interrupt*/
	CLR_BIT(SPCR, SPCR_SPIE);

	/*Enable SPI peripheral*/
	SET_BIT(SPCR ,SPCR_SPE);

	/*Data order -> LSB FIRST*/
	SET_BIT(SPCR , SPCR_DORD);

	/*Clock polarity -> idle state = LOW*/
	CLR_BIT(SPCR ,SPCR_CPOL);

	/*Clock phase -> SAMPLE FIRST*/
	CLR_BIT(SPCR ,SPCR_CPHA);
}

u8 SPI_u8Transceive(u8 Copy_u8TransmittedByte)
{
	/*Set the data byte to be transmitted*/
	SPDR = Copy_u8TransmittedByte ;

	/*Polling till the end of transfer*/
	while((GET_BIT(SPSR, SPSR_SPIF)) == 0 ) ;

	/*Get the received data byte*/
	return SPDR ;
}





