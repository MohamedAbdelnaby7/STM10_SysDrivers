/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 05 Sep 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"


//Array of Tasks(structs)
static Task OS_Tasks[NUM_OF_TASKS] = {NULL};

void OS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Periodicity, void (*ptr) (void), u16 Copy_u8FirstDelay)
{
	OS_Tasks[Copy_u8ID].Periodicity = Copy_u16Periodicity ;
	OS_Tasks[Copy_u8ID].Fn_ptr		= ptr				  ;
	OS_Tasks[Copy_u8ID].First_Delay	= Copy_u8FirstDelay	  ;
}

void OS_voidStart(void)
{
	/*Intialization SysTick*/
	MSTK_voidInit();
	/*Tick Time => 1msec*/ 
	/* HSE 8MHz/8 */
	MSTK_voidSetIntervalPeriodic(TICK_TIME, Scheduler);
}


void Scheduler(void)
{
	for(u8 i = 0; i < NUM_OF_TASKS; i++)
	{
		if( (OS_Tasks[i].Fn_ptr != NULL) && (OS_Tasks[i].Status == READY) )
		{
			if( OS_Tasks[i].First_Delay == 0)
			{
				OS_Tasks[i].First_Delay = OS_Tasks[i].Periodicity - 1;
				OS_Tasks[i].Fn_ptr();
			}
			else
			{
				OS_Tasks[i].First_Delay--;
			}
		}
	}
}

void OS_voidStopTask(u8 Copy_u8ID)
{
	OS_Tasks[Copy_u8ID].Status = SUSPEND;
}

void OS_voidResumeTask(u8 Copy_u8ID)
{
	OS_Tasks[Copy_u8ID].Status = READY;
}

void OS_voidDeleteTask(u8 Copy_u8ID)
{

}
