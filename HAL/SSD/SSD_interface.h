/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : SSD_interface.h													*/
/*Layer       : HAL																*/
/*Description : This file contains interfacing paremeters of SSD module			*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_PORTA			0
#define SSD_PORTB			1
#define SSD_PORTC			2
#define SSD_PORTD			3

#define COM_ANODE			1
#define COM_CATHOD		0

#define SSD_COM_PIN0		0
#define SSD_COM_PIN1		1
#define SSD_COM_PIN2		2
#define SSD_COM_PIN3		3
#define SSD_COM_PIN4		4
#define SSD_COM_PIN5		5
#define SSD_COM_PIN6		6
#define SSD_COM_PIN7		7


#define CATHOD_0			0x3F
#define CATHOD_1			0x06
#define CATHOD_2			0x5B
#define CATHOD_3			0x4F
#define CATHOD_4			0x66
#define CATHOD_5			0x6D
#define CATHOD_6			0x7D
#define CATHOD_7			0x07
#define CATHOD_8			0x7F
#define CATHOD_9			0x6F


#define ANODE_0				0x03
#define ANODE_1				0x9F
#define ANODE_2				0x25
#define ANODE_3				0x0D
#define ANODE_4				0x99
#define ANODE_5				0x49
#define ANODE_6				0x41
#define ANODE_7				0x1F
#define ANODE_8				0x01
#define ANODE_9				0x09


/*************************************************************************/
/*************************Functions' Prototypes***************************/
/*************************************************************************/

void SSD_void_Init(u8 Copy_u8Connection , u8 SSD_PORT , u8 COM_PORT , u8 COM_PIN);

void SSD_void_ON(u8 Copy_u8Connection , u8 COM_PORT , u8 COM_PIN);

void SSD_void_DISPLAY_NUMBER(u8 SSD_PORT , u8 SSD_Value);

void SSD_void_OFF(u8 Copy_u8Connection , u8 COM_PORT , u8 COM_PIN);

#endif /* SSD_INTERFACE_H_ */
