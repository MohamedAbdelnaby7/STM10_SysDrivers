/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 22 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"

void LED_voidInit(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	MGPIO_voidSetPinDirection(copy_u8PORT, copy_u8PIN, LED_OUTPUT_MODE);
}

void LED_voidOn(u8 copy_u8PORT, u8 copy_u8PIN)
{
	MGPIO_voidSetPinValue(copy_u8PORT, copy_u8PIN, HIGH); 
}

void LED_voidOff(u8 copy_u8PORT, u8 copy_u8PIN)
{
	MGPIO_voidSetPinValue(copy_u8PORT, copy_u8PIN, LOW); 
}

void LED_voidTog(u8 copy_u8PORT, u8 copy_u8PIN)
{
	MGPIO_VoidTogPin(copy_u8PORT, copy_u8PIN); 
}



