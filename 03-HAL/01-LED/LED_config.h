/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 22 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/


#ifndef LED_CONFIG_H
#define LED_CONFIG_H

/*CHOOSE WIRING TYPE OF THE LED:
							REVERSED
							FORWARD
							*/
#define LED_CONNECTION  FORWARD
	
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
#define LED_OUTPUT_MODE 	OUTPUT_SPEED_10MHZ_PP

#endif