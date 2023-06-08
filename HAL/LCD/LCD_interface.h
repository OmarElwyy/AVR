/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : LCD_interface.h													*/
/*Layer       : HAL																*/
/*Description : This file contains interfacing paremeters of LCD module			*/
/*Date        : 22 March 2023													*/
/********************************************************************************/


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define FUNCTION_SET			0x3C
#define DISPLAY_ON_OFF			0x0F
#define CLEAR_LCD				0x01




/*************************************************************************/
/*************************Functions' Prototypes***************************/
/*************************************************************************/

/*This Function is to initialize the LCD*/
void LCD_voidLCDInit(void);

/*This Function is to Send Command to LCD*/
void LCD_voidSendCommand(u8 CMD);

/*This Function is to Send Character to LCD*/
void LCD_voidSendCharacter(u8 Character);

/*This Function is to send String to LCD*/
void LCD_voidSendSting(u8 * ARRAY);

/*This Function Shall go to Certain Grid in the LCD
 * Copy_u8Row : 0 -> 1 & Copy_u8Column ; 0 -> 15
 * Return : Error State in case on Invalid Input */
u8 LCD_voidGoToRowCol(u8 Copy_u8Row , u8 Copy_u8Column);

/*This Function shall display a Special Character on a Specific cell on the LCD*/
void LCD_voidSendSpecialCharacter(u8 * Copy_u8Pattern , u8 Copy_u8Location , u8 Copy_u8Row , u8 Copy_u8Column);

/*This Function is to Send Number To LCD*/
void LCD_voidSendNum(u32 Copy_u32Number);

#endif /* LCD_INTERFACE_H_ */
