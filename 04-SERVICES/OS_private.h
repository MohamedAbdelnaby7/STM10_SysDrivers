/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 05 Sep 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef	OS_PRIVATE_H
#define	OS_PRIVATE_H

#define NULL 	(void *)0
#define READY	1
#define SUSPEND	0

typedef struct
{
	u16 Periodicity;
	void (*Fn_ptr) (void);
	u16 First_Delay;
	u8 Status;
}Task;

#endif
