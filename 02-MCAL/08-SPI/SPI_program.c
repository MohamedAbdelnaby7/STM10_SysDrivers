/***************************************************************/
/* Author    : Mohamed Abdelnaby                               */
/* Version   : V01                                             */
/* Date      : 01 OCT 2020                                     */
/***************************************************************/

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void (*CallBack)(u8);

void MSPI1_voidInit(void)
{
	#if(CRC_MODE == NO_CRC)
		CLR_BIT(MSPI1->CR1, CRCEN); 
		CLR_BIT(MSPI1->CR1, CRCNEXT);
	#elif(CRC_MODE == CRC_NO_PHASE)
		SET_BIT(MSPI1->CR1, CRCEN);
		CLR_BIT(MSPI1->CR1, CRCNEXT);
	#elif(CRC_MODE == CRC_NEXT_PHASE
		SET_BIT(MSPI1->CR1, CRCEN);
		SET_BIT(MSPI1->CR1, CRCNEXT);
	#endif
	
	#if (DATA_SIZE == _8BIT)
		CLR_BIT(MSPI1->CR1, DFF);
	#elif(DATA_SIZE == _16BIT)
		SET_BIT(MSPI1->CR1, DFF);
	#endif
	
	#if(DATA_DIRECTION == SPI_2LINES_FULL_DUPLEX)
		CLR_BIT(MSPI1->CR1, BIDIMODE);
		CLR_BIT(MSPI1->CR1, BIDIOE);
		CLR_BIT(MSPI1->CR1, RXONLY);
	#elif(DATA_DIRECTION == SPI_2LINES_RX_ONLY)
		CLR_BIT(MSPI1->CR1, BIDIMODE);
		CLR_BIT(MSPI1->CR1, BIDIOE);
		SET_BIT(MSPI1->CR1, RXONLY);
	#elif(DATA_DIRECTION == SPI_BIDIRECTIONAL_RX_ONLY)
		SET_BIT(MSPI1->CR1, BIDIMODE);
		CLR_BIT(MSPI1->CR1, BIDIOE);
		SET_BIT(MSPI1->CR1, RXONLY);
	#elif(DATA_DIRECTION == SPI_BIDIRECTIONAL_TX_ONLY)
		SET_BIT(MSPI1->CR1, BIDIMODE);
		SET_BIT(MSPI1->CR1, BIDIOE);
		CLR_BIT(MSPI1->CR1, RXONLY);
	#endif
	
	#if(SPI_NSS == SPI_NSS_SW)
		SET_BIT(MSPI1->CR1, SSM);
		SET_BIT(MSPI1->CR1, SSI);
	#elif(SPI_NSS == SPI_NSS_HW)
		CLR_BIT(MSPI1->CR1, SSM);
		CLR_BIT(MSPI1->CR1, SSI);
	#endif
	
	#if(FIRST_BIT == MSB)
		CLR_BIT(MSPI1->CR1, LSBFIRST);
	#elif(FIRST_BIT == LSB)
		SET_BIT(MSPI1->CR1, LSBFIRST);
	#endif
	
	#if(SPI_MODE == SLAVE_CONFIGURATION)
		CLR_BIT(MSPI1->CR1, MSTP);
	#elif(SPI_MODE == MASTER_CONFIGRATION)
		SET_BIT(MSPI1->CR1, MSTP);
	#endif
	
	#if(CLK_POLARITY == 0)
		CLR_BIT(MSPI1->CR1, CPOL);
	#elif(CLK_POLARITY == 1)
		SET_BIT(MSPI1->CR1, CPOL);
	#endif
	
	#if(CLK_PHASE == 0)
		CLR_BIT(MSPI1->CR1, CPHA);
	#elif(CLK_PHASE == 1)
		SET_BIT(MSPI1->CR1, CPHA);
	#endif
	
	/*Sets the speed of SPI communication*/
	MSPI1_voidSetSpeed(CLK_DIV_64);
	
	/*Enable the SPI*/
	SET_BIT(MSPI1->CR1, SPE);
	
	//MSPI1->CR1 = 0x0347;
}

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive)
{
	/* Clear For Slave Select Pin */
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,LOW);
	
	/* Send Data */
	MSPI1 -> DR = Copy_u8DataToTransmit;
	
	/* Wait Busy Flag to finish */
	while (GET_BIT(MSPI1 -> SR, 7) == 1);

 	/* Return to the received data */
	*Copy_DataToReceive = MSPI1 -> DR;
	
	/* Set Salve Select Pin */
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,HIGH);
}

void MSPI1_voidSetSpeed(u8 Copy_u8Speed)
{
	/*Clear the prescale bits first*/
	MSPI1->CR1 &= ~(0b111 << 4);
	/*Sets the new BR value*/
	MSPI1->CR1 |= (Copy_u8Speed <<4);
}