/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 05 Sep 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void OS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Periodicity, void (*ptr) (void), u16 Copy_u8FirstDelay);
void OS_voidStart(void);
void Scheduler(void);
void OS_voidStopTask(u8 Copy_u8ID);
void OS_voidResumeTask(u8 Copy_u8ID);
void OS_voidDeleteTask(u8 Copy_u8ID);

#endif
