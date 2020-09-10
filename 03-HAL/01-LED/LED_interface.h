/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 22 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

void LED_voidInit(u8 Copy_u8PORT, u8 Copy_u8PIN);
void LED_voidOn(u8 Copy_u8PORT, u8 Copy_u8PIN);
void LED_voidOff(u8 Copy_u8PORT, u8 Copy_u8PIN);
void LED_voidTog(u8 Copy_u8PORT, u8 Copy_u8PIN);

#endif