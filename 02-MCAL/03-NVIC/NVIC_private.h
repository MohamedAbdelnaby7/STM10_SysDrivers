/***************************************************************/
/*Author	: Mohamed Abdelnaby 							   */
/*Date		: Aug 19 2020									   */
/*Version	: V01											   */
/***************************************************************/

/*00xE000E100  NCIV base address*/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_ISER0		*((u32*)00xE000E100) /*Enable external interrupts 0:31	*/
#define NVIC_ISER1		*((u32*)00xE000E104) /*Enable external interrupts 32:59	*/

#define NVIC_ICER0		*((u32*)00xE000E180) /*Disable external interrupts 0:31	*/
#define NVIC_ICER1		*((u32*)00xE000E184) /*Disable external interrupts 32:59*/

#define NVIC_ISPR0		*((u32*)00xE000E200) /*Set the pending flag 0:31*/
#define NVIC_ISPR1		*((u32*)00xE000E204) /*Set the pending flag 32:59*/

#define NVIC_ICPR0		*((u32*)00xE000E280) /*Clear the pending flag 0:31*/
#define NVIC_ICPR1		*((u32*)00xE000E284) /*Clear the pending flag 32:59*/

#define NVIC_IABR0		*((volatile u32*)00xE000E300)
#define NVIC_IABR1		*((volatile u32*)00xE000E304)

#define NVIC_IPR0		((volatile u8*)0xE000E400)
#define SCB_AIRCR		*((volatile u32*)0xE000ED0C)

#endif