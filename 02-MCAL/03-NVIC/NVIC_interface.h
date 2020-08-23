/***************************************************************/
/*Author	: Mohamed Abdelnaby 							   */
/*Date		: Aug 19 2020									   */
/*Version	: V01											   */
/***************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingInterrupt(u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void MVIC_voidSetPriority(s8 copy_s8IntID, u8 copy_u8GroupPriority, u8 copy_u8SubPriority, u32 copy_u32GROUP);

#define GROUP3	0x05FA0300	//4 bits for group (IPR) => group
#define GROUP4	0x05FA0400	//3 bits for Group and 1 bit for sub
#define GROUP5	0x05FA0500	//2 bits for Group and 2 bit for sub
#define GROUP6	0x05FA0600	//1 bits for Group and 3 bit for sub
#define GROUP7	0x05FA0700	//0 bits for Group and 1 bit for sub

#endif