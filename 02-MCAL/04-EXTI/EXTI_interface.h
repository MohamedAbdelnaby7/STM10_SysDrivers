#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_voidInit();
void MEXIT_voidEnableEXTI(u8 copy_u8Line);
void MEXIT_voidDisableEXTI(u8 copy_u8Line);
void MEXIT_voidSwTrigger(u8 copy_u8Line);

#endif