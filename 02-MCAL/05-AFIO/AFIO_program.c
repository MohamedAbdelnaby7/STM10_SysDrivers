#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"

void MAFIO_voidSetEXTIconfiguration(u8 copy_u8Line, u8 copy_u8PortMap)
{
	u8 Local_u8RegIndex = 0;
	
	Local_u8RegIndex = copy_u8Line / 4;
	copy_u8Line %= 4

	AFIO->EXTICR[Local_u8RegIndex] &~	= ((0b1111) << (copy_u8Line * 4));
	AFIO->EXTICR[Local_u8RegIndex]	|	= ((copy_u8PortMap) << (copy_u8Line * 4));
}