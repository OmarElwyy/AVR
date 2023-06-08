/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : LCD_cfg.h														*/
/*Layer       : HAL																*/
/*Description : This file contains configurable paremeters of LCD module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_DATA_PORT			DIO_PORTA
#define LCD_CONTROL_PORT		DIO_PORTC

#define LCD_PIN1				DIO_PIN4
#define LCD_PIN2				DIO_PIN5
#define LCD_PIN3				DIO_PIN6
#define LCD_PIN4				DIO_PIN7

#define LCD_MODE				_4_BIT

#define RS_PIN					DIO_PIN5
#define RW_PIN					DIO_PIN6
#define EN_PIN					DIO_PIN7

#endif /* LCD_CFG_H_ */
