/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : LED_interface.h													*/
/*Layer       : HAL																*/
/*Description : This file contains interfacing paremeters of LED module			*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_ON		1

/*************************************************************************/
/*************************Functions' Prototypes***************************/
/*************************************************************************/

void LED_voidLEDinit(u8 Copy_u8PortID , u8 Copy_u8Pin);

void LED_voidLED_ON(u8 Copy_u8PortID , u8 Copy_u8Pin);

void LED_voidLED_OFF(u8 Copy_u8PortID , u8 Copy_u8Pin);

void LED_voidLED_TGL(u8 Copy_u8PortID , u8 Copy_u8Pin);


#endif /* LED_INTERFACE_H_ */
