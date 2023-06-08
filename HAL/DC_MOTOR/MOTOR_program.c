

#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "MOTOR_interface.h"
#include "MOTOR_private.h"
#include "MOTOR_cfg.h"


void MOTOR_voidInit()
{
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN0 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN1 , DIO_PIN_OUTPUT);
}

void MOTOR_voidForward()
{
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN1 ,DIO_LOW_PIN);
}

void MOTOR_voidBackward()
{
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN1 ,DIO_HIGH_PIN);
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 ,DIO_LOW_PIN);
}

void MOTOR_voidStop()
{
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 ,DIO_LOW_PIN);
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN1 ,DIO_LOW_PIN);
}
