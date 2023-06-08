/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : LCD_program.c													*/
/*Layer       : HAL																*/
/*Description : This file contains functions' implemetation of LCD module		*/
/*Date        : 22 March 2023													*/
/********************************************************************************/

#include <util/delay.h>
#include <stdlib.h>

#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_cfg.h"


/******************************************************************************/
/*************************Functions' implementation****************************/
/******************************************************************************/

static u8 i = 0;

/*This Function is to initialize the LCD*/
void LCD_voidLCDInit(void)
{
	i = 0;
#if (LCD_MODE == _8_BIT)

	DIO_voidSetPortDirection(LCD_DATA_PORT , DIO_OUTPUT_Port);						//DATA
	DIO_voidSetPinDirection(LCD_CONTROL_PORT , RS_PIN , DIO_PIN_OUTPUT);			//RS
	DIO_voidSetPinDirection(LCD_CONTROL_PORT , RW_PIN , DIO_PIN_OUTPUT);			// R/W
	DIO_voidSetPinDirection(LCD_CONTROL_PORT , EN_PIN , DIO_PIN_OUTPUT);			// Enable

	_delay_ms(30);
	LCD_voidSendCommand(0x3C);				// Function Set
	_delay_us(50);
	LCD_voidSendCommand(0x0C);				// Display ON / OFF
	_delay_us(50);
	LCD_voidSendCommand(0x01);				// Display Clear

#elif (LCD_MODE == _4_BIT)
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_PIN3, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_PIN4, DIO_PIN_OUTPUT);

	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RW_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_OUTPUT);
	_delay_ms(40);

	LCD_voidSendCommand(0x20);
	LCD_voidSendCommand(0x20);
	LCD_voidSendCommand(0xC0);

	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(0xC0);

	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(0x10);

	i = 1;
#endif

}

/*This Function is to Send Command to LCD*/
void LCD_voidSendCommand(u8 CMD)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT , RS_PIN , DIO_LOW_PIN);				// RS
	DIO_voidSetPinValue(LCD_CONTROL_PORT , RW_PIN , DIO_LOW_PIN);				// R/W

#if (LCD_MODE == _8_BIT)

	DIO_u8SetPortValue(LCD_DATA_PORT , CMD);
	DIO_voidSetPinValue(LCD_CONTROL_PORT , EN_PIN , DIO_HIGH_PIN);
	_delay_ms(10);
	DIO_voidSetPinValue(LCD_CONTROL_PORT , EN_PIN , DIO_LOW_PIN);

#elif (LCD_MODE == _4_BIT)

	u8 CMD1 = CMD;
	CMD = 0xF0 & CMD;
	DIO_u8SetPortValue(LCD_DATA_PORT, CMD);


	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_HIGH_PIN);
	_delay_ms(10);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_LOW_PIN);

	if(i)
	{
		CMD1 = 0xF0 & (CMD1 << 4);
		DIO_u8SetPortValue(LCD_DATA_PORT, CMD1);

		DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_HIGH_PIN);
		_delay_ms(30);
		DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_LOW_PIN);
	}

#endif

}

/*This Function is to Send Character to LCD*/
void LCD_voidSendCharacter(u8 Character)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT , RS_PIN , DIO_HIGH_PIN);				// RS
	DIO_voidSetPinValue(LCD_CONTROL_PORT , EN_PIN , DIO_LOW_PIN);				// R/W

#if (LCD_MODE == _8_BIT)

	DIO_u8SetPortValue(LCD_DATA_PORT , Character);
	DIO_voidSetPinValue(LCD_CONTROL_PORT , EN_PIN , DIO_HIGH_PIN);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT , EN_PIN , DIO_LOW_PIN);

#elif (LCD_MODE == _4_BIT)

	u8 Local_u8Character;
	Local_u8Character = Character;

	Local_u8Character = 0xF0 & Local_u8Character;
	DIO_u8SetPortValue(LCD_DATA_PORT, Local_u8Character);

	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_HIGH_PIN);
	_delay_ms(5);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_LOW_PIN);

	Character = 0xF0 & (Character << 4);
	DIO_u8SetPortValue(LCD_DATA_PORT, Character);

	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_HIGH_PIN);
	_delay_ms(5);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_LOW_PIN);

#endif
}

/*This Function is to send String to LCD*/
void LCD_voidSendSting(u8 * ARRAY)
{
	u8 i = 0;
	while (ARRAY[i] != '\0')
	{
		LCD_voidSendCharacter(ARRAY[i]);
		i++;
	}
}


u8 LCD_voidGoToRowCol(u8 Copy_u8Row , u8 Copy_u8Column)
{
	u8 Local_u8ErrorState = 0;

	u8 Local_u8DDRAMAdress;

	/*In Case Of Valid Input Arguments Range*/
	if((Copy_u8Row == 0 || Copy_u8Row) == 1 && ( Copy_u8Column >= 0 && Copy_u8Column < 16))
	{
		/*In Case Of Writing in the First Row*/
		if(Copy_u8Row == 0)
		{
			Local_u8DDRAMAdress = Copy_u8Column;
		}

		/*In Case Of Writing in the Second Row*/
		else if (Copy_u8Row == 1)
		{
			Local_u8DDRAMAdress = Copy_u8Column + 0x40;
		}
	}

	/*In Case of Invalid Input Arguments*/
	else
	{
		Local_u8ErrorState = 1;
	}

	/*Setting the MSB to be HIGH*/
	SET_BIT(Local_u8DDRAMAdress , 7);

	/*Send Command : Set DDRAM Address*/
	LCD_voidSendCommand(Local_u8DDRAMAdress);

	return Local_u8ErrorState ;
}

void LCD_voidSendSpecialCharacter(u8 * Copy_u8Pattern , u8 Copy_u8Location , u8 Copy_u8Row , u8 Copy_u8Column)
{
	/*local variable to calculate the Address of the CGRAM location*/
	u8 Local_u8CGRAMAddress;

	/*Local Variable for Iterator on bytes of Patterns*/
	u8 Local_u8PatternIterator;

	Local_u8CGRAMAddress = Copy_u8Location *8 ;

	SET_BIT(Local_u8CGRAMAddress , 6);

	/*Setting Address Counter to the target Location of the CGRAM*/
	LCD_voidSendCommand(Local_u8CGRAMAddress);

	/*Sending the pattern to the target location in CGRAM*/
	for(Local_u8PatternIterator = 0 ; Local_u8PatternIterator < 8 ; Local_u8PatternIterator++)
	{
		LCD_voidSendCharacter(Copy_u8Pattern[Local_u8PatternIterator]);
	}

	/*Turning Back to DDRAM*/
	LCD_voidGoToRowCol(Copy_u8Row , Copy_u8Column);

	/*Displaying Special character
	 * DDRAM jumps to the location of CGRAM to display the Pattern*/
	LCD_voidSendCharacter(Copy_u8Location);
}


void LCD_voidSendNum(u32 Copy_u32Number)
{
	u8 Local_u8Array[16];

	itoa(Copy_u32Number,Local_u8Array,10);
	LCD_voidSendSting(Local_u8Array);
}

