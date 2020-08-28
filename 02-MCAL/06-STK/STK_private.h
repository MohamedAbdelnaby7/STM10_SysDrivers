/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 28 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_CTRL 	*((u32*)E000E010)
#define STK_LOAD 	*((u32*)E000E014)
#define STK_VALUE 	*((u32*)E000E018)

#define COUNTER_ENABLE 	0
#define TICK_INT		1
#define CLKSOURCE		2
#define COUNTER_FLAG	16

u8 Is_Periodic = 0;
void (* CallBack)(void);

#endif