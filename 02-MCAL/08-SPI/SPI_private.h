/***************************************************************/
/* Author    : Mohamed Abdelnaby                               */
/* Version   : V01                                             */
/* Date      : 01 OCT 2020                                     */
/***************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* Direction Modes */
#define SPI_2LINES_FULL_DUPLEX			0
#define SPI_2LINES_RX_ONLY				1
#define SPI_BIDIRECTIONAL_RX_ONLY		2
#define SPI_BIDIRECTIONAL_TX_ONLY		3

/* CRC options*/
#define NO_CRC			0
#define CRC_NO_PHASE	1
#define CRC_NEXT_PHASE	2

/*DATA FRAME FORMAT 8bit/ 16bit*/
#define _8BIT		0
#define _16BIT		1

/* Slave Select Managment*/
#define SPI_NSS_HW		0
#define SPI_NSS_SW		1 

/*Frame formate LSB/ MSB first*/
#define LSB		1	
#define MSB		0

/* SPI Mode*/
#define SLAVE_CONFIGURATION		0
#define MASTER_CONFIGRATION		1

#define DISABLED	0
#define ENABLED		1

/* bits number*/
#define BIDIMODE	15
#define BIDIOE		14
#define CRCEN		13
#define CRCNEXT		12
#define DFF			11
#define RXONLY		10
#define SSM			9
#define SSI			8
#define LSBFIRST	7
#define SPE			6
#define MSTP		2
#define CPOL		1
#define CPHA		0

typedef struct
{
	volatile u32 CR1    ;
	volatile u32 CR2    ;
	volatile u32 SR     ;
	volatile u32 DR     ;
	volatile u32 CRCPR  ;
	volatile u32 RXCRCR ;
	volatile u32 TXCRCR ;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR  ; 
	
}SPI_Register;


#define MSPI1   ((SPI_Register*)0x40013000)

#endif