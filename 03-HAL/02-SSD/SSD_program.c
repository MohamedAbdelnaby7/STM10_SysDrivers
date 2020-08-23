/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 23 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h" 


u8 SSD_Pins[7]  = {SSD_A, SSD_B, SSD_C, SSD_D, SSD_E, SSD_F, SSD_G};
void SSD_voidInit()
{
	switch(SSD_PORT)
	{
		case GPIOA:	RCC_voidEnableClock(APB2, PIOA);	break;
		case GPIOB: RCC_voidEnableClock(APB2, PIOB);	break;
		case GPIOC: RCC_voidEnableClock(APB2, PIOC);	break;
		default:										break;
		
	}
	
	for(u8 i = 0; i < 8; i++)
	{
		MGPIO_VoidSetPinDirection(SSD_PORT, SSD_Pins[i], SSD_OUTPUT_MODE);
	}
}

void SSD_voidDisplayNumber(u8 copy_u8Number)
{
	//Representing the seven segment number in hex decimal
	u8 SSD_NumRep[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
	
	u8 A_Val = (SSD_NumRep[copy_u8Number] & 0x01);
	u8 B_Val = (SSD_NumRep[copy_u8Number] & 0x02) >> 1;
	u8 C_Val = (SSD_NumRep[copy_u8Number] & 0x04) >> 2;
	u8 D_Val = (SSD_NumRep[copy_u8Number] & 0x08) >> 3;
	u8 E_Val = (SSD_NumRep[copy_u8Number] & 0x10) >> 4;
	u8 F_Val = (SSD_NumRep[copy_u8Number] & 0x20) >> 5;
	u8 G_Val = (SSD_NumRep[copy_u8Number] & 0x40) >> 6;
	
	u8 SSD_Values[7] ={A_Val, B_Val, C_Val, D_Val, E_Val, F_Val, G_Val};
	#if SSD_MODE == COM_ANOD
		for(u8 i = 0; i < 8; i++)
		{
			MGPIO_VoidSetPinValue(SSD_PORT, SSD_PIN[i], ~(SSD_Values[i]));
		}
	#elif SSD_MODE == COM_CATHOD
		for(u8 i = 0; i < 8; i++)
		{
			MGPIO_VoidSetPinValue(SSD_PORT, SSD_PIN[i], SSD_Values[i]);
		}
}