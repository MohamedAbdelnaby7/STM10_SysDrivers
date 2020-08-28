/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 22 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void MEXTI_voidInit()
{
	#if EXTI_MODE == RISING
		SET_BIT(EXTI -> RTSR, EXTI_LINE);
	#elif EXTI_MODE == FALLING 
		SET_BIT(EXTI -> FTSR, EXTI_LINE);
	#elif EXTI_MODE == CHANGING
		SET_BIT(EXTI -> RTSR, EXTI_LINE);
		SET_BIT(EXTI -> FTSR, EXTI_LINE);
	#else
		#error "Wrong Interrupt mode"
	#endif
	/*make sure the interrupt is diable at first*/
	CLR_BIT(EXTI -> IMR, copy_u8Line);
}


void MEXIT_voidEnableEXTI(u8 copy_u8Line)
{
	SET_BIT(EXTI -> IMR, copy_u8Line);
}

void MEXIT_voidDisableEXTI(u8 copy_u8Line)
{
	CLR_BIT(EXTI -> IMR, copy_u8Line);
}

void MEXIT_voidSwTrigger(u8 copy_u8Line)
{
	SET_BIT(EXTI -> SWIER, copy_u8Line);
}

void MEXIT_voidSetSignalLatch(u8 copy_u8Line, u8 copy_u8Mode)
{
	case RISING:	SET_BIT(EXTI -> RTSR, EXTI_LINE); 	break;
	case FALLING:	SET_BIT(EXTI -> FTSR, EXTI_LINE);	break;
	case CHANGING:	SET_BIT(EXTI -> RTSR, EXTI_LINE); 
					SET_BIT(EXTI -> FTSR, EXTI_LINE);	break;
	
}