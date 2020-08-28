/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 28 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_INTERFACE.h"
#include "STK_CONFIG.h"
#include "STK_PRIVATE.h"

void (*CallBack) (void);

void MSTK_voidInit(void)
{
	STK_CTRL = 0x00000000;
	#if(CLK_SOURCE == AHB)
		SET_BIT(STK_CTRL, 2);
	#elif(CLK_SOURCE == AHB_DIV_8)
	{
		CLR_BIT(STK_CTRL, 2);
	}	
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	#if (Copy_u32Ticks <= 0x00FFFFFF)
		STK_LOAD = Copy_u32Ticks;
		SET_BIT(CLK_CTRL, COUNTER_ENABLE);
		while(GETBIT(STK_CTRL, COUNTER_FLAG) == 0);
		CLR_BIT(STK_CTRL, COUNTER_ENABLE);
	#else
		#error "Timer maximum value exceeded."
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void))
{
	#if (Copy_u32Ticks <= 0x00FFFFFF)
		STK_LOAD = Copy_u32Ticks;
		SET_BIT(CLK_CTRL, TICK_INT);
		CallBack = Copy_ptr;
		Is_Periodic = 0;
		SET_BIT(CLK_CTRL, COUNTER_ENABLE);
	#else
		#error "Timer maximum value exceeded."
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr) (void))
{
	#if (Copy_u32Ticks <= 0x00FFFFFF)
		STK_LOAD = Copy_u32Ticks;
		SET_BIT(CLK_CTRL, TICK_INT);
		CallBack = Copy_ptr;
		Is_Periodic = 1;
		SET_BIT(CLK_CTRL, COUNTER_ENABLE);
	#else
		#error "Timer maximum value exceeded."
}

void MSTK_voidStopInterval(void) {
	CLR_BIT(STK_CTRL, 0);
}

u32 MSTIK_u32GetElapsedTime(void)
{
	return STK_VALUE - STK_LOAD;
}


u32 MSTIK_u32GetRemainingTime(void)
{
	return STK_VALUE;
}

void SysTick_Handler (void)
{
	CallBack();
	if(~Is_Periodic)
	{
		STK_LOAD = 0x00000000;
	}
}