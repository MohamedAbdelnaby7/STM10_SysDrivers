/***************************************************************/
/* Author    : Mohamed Abdelnaby                               */
/* Version   : V01                                             */
/* Date      : 01 OCT 2020                                     */
/***************************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Write it in a pair port,pin */
#define MSPI1_SLAVE_PIN   GPIOA,0

/* CRC Modes
*	Options:
*	NO_CRC			
*	CRC_NO_PHASE	
*	CRC_NEXT_PHASE
*/
#define CRC_MODE	 CRC_NO_PHASE

/* DATA FRAME Options:
*	_8BIT
*   _16BIT
*/
#define DATA_SIZE	_8BIT

/* CLK speed Options:
*	CLK_DIV_2	
*   CLK_DIV_4	
*   CLK_DIV_8	
*   CLK_DIV_16	
*   CLK_DIV_32	
*   CLK_DIV_64	
*	CLK_DIV_128
*   CLK_DIV_256
*/

#define SPI_BR	CLK_DIV_64

/*Chose working mode options:
*	SPI_2LINES_FULL_DUPLEX	
*	SPI_2LINES_RX_ONLY		
*   SPI_BIDIRECTIONAL_RX_ONLY
*   SPI_BIDIRECTIONAL_TX_ONLY
*/
#define DATA_DIRECTION	SPI_2LINES_FULL_DUPLEX

/* Software slave management by HW or SW
*	Options:
*	SPI_NSS_HW
*	SPI_NSS_SW 
*/
#define SPI_NSS		SPI_NSS_SW

/* Sending LSB FIRST or MSB First
*	Options:
*	LSB
*	MSB
*/
#define FIRST_BIT	MSB

/*Choose your mc configuration workin as Master or Slave
*	Options:
*	SLAVE_CONFIGURATION
*	MASTER_CONFIGRATION	
*/
#define SPI_MODE	MASTER_CONFIGRATION	

/*You may chose 0 or 1*/
#define CLK_PHASE		0
/*You may chose 0 or 1*/
#define CLK_POLARITY	0

#endif