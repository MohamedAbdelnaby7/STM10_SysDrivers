/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 23 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef SSD_CONFIG_H
#define SSD_CONFIG_H

/*Way of connecting the Seven Segment:
									COM_ANOD
									COM_CATHOD
									*/
#define SSD_MODE	COM_ANOD

/*choose LED output Mode:
						OUTPUT_SPEED_10MHZ_PP	
						OUTPUT_SPEED_10MHZ_OD		
                        OUTPUT_SPEED_10MHZ_AFPP	
                        OUTPUT_SPEED_10MHZ_AFOD	
                        
                        OUTPUT_SPEED_2MHZ_PP	
                        OUTPUT_SPEED_2MHZ_OD	
                        OUTPUT_SPEED_2MHZ_AFPP	
                        OUTPUT_SPEED_2MHZ_AFOD	
                        
                        OUTPUT_SPEED_50MHZ_PP	
                        OUTPUT_SPEED_50MHZ_OD	
						OUTPUT_SPEED_50MHZ_AFPP	
                        OUTPUT_SPEED_50MHZ_AFOD	
						*/
#define SSD_OUTPUT_MODE 	OUTPUT_SPEED_10MHZ_PP

//Choose the port to work on
#define SSD_PORT 	GPIOA

//SSD pins
#define SSD_A	PIN0
#define SSD_B	PIN1
#define SSD_C	PIN2
#define SSD_D	PIN3
#define SSD_E	PIN4
#define SSD_F	PIN5
#define SSD_G	PIN6

#endif