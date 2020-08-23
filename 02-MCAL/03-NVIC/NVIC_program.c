/***************************************************************/
/*Author	: Mohamed Abdelnaby 							   */
/*Date		: Aug 19 2020									   */
/*Version	: V01											   */
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_NATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		
	}
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		
	}
}

void MNVIC_voidSetPendingInterrupt(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		
	}
}

void MNVIC_voidClearPendingInterrupt(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		
	}
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;
	if ( Copy_u8IntNumber <= 31 )
	{
		Local_u8Result = GET_BIT (NVIC_IABR0, Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT (NVIC_IABR0, Copy_u8IntNumber);
	}
	else
	{
		
	}
	return Local_u8Result;
}

void MVIC_voidSetPriority(s8 copy_s8IntID, u8 copy_u8GroupPriority, u8 copy_u8SubPriority, u32 copy_u32GROUP)
{
	u8 Local_u8Priority = copy_u8SubPriority | copy_u8GroupPriority << ((copy_u32GROUP -  0x05FA0300)/256);
	/*core peripheral*/
	
	/*external peripheral*/
	if(copy_s8IntID >= 0)
	{
		IPR0[copy_s8IntID] = Local_u8Priority << 4;
	}
	SCB_AIRCR = copy_u32GROUP;
}