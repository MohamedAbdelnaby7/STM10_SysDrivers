/***************************************************************/
/* Author    : Mohamed Abdelnaby                               */
/* Version   : V01                                             */
/* Date      : 01 OCT 2020                                     */
/***************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/* SPI working clock prescale*/
#define CLK_DIV_2	0b000
#define CLK_DIV_4	0b001
#define CLK_DIV_8	0b010
#define CLK_DIV_16	0b011
#define CLK_DIV_32	0b100
#define CLK_DIV_64	0b101
#define CLK_DIV_128	0b110
#define CLK_DIV_256	0b111

void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive);
void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*CallBack)(u8));

#endif