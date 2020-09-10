/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 22 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void LED_voidInit(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	MGPIO_voidSetPinDirection(Copy_u8PORT, Copy_u8PIN, LED_OUTPUT_MODE);
}

void LED_voidOn(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	if(LED_MODE == FORWARD)
		MGPIO_voidSetPinValue(Copy_u8PORT, Copy_u8PIN, HIGH);
	else
		MGPIO_voidSetPinValue(Copy_u8PORT, Copy_u8PIN, LOW);
}

void LED_voidOff(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	if(LED_MODE == FORWARD)
		MGPIO_voidSetPinValue(Copy_u8PORT, Copy_u8PIN, LOW);
	else
		MGPIO_voidSetPinValue(Copy_u8PORT, Copy_u8PIN, HIGH); 
}

void LED_voidTog(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	MGPIO_VoidTogPin(Copy_u8PORT, Copy_u8PIN); 
}



