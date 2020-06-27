/*
 * Ultasonic.h
 *
 *  Author: Mahmoud Ayman
 */ 


#ifndef ULTASONIC_H_
#define ULTASONIC_H_
#include "Timer_driver_MCAL.h"
#include "Data_type.h"
#include "stdmacros.h"
struct config {
	u8 Trigger_Port;
	u8 Trigger_Pin;
	u8 Echo_Port;
	u8 Echo_Pin;
	}US_Config;
	
#define ICP1 6
#define INT0 2
#define INT1 3

/*
	Function Name        : US_Get_Configuration
	Function Returns     : void
	Function Arguments   : unsigned char Trigger port,unsigned char Trigger Pin , unsigned char Echo Port,unsigned char Echo Pin
	Function Description : Get configuration for Ultrasonic from user.
	*/
		void US_Get_Configuration (u8 TRIGGER_Port , u8 TRIGGER_Pin , u8 ECHO_Port , u8 ECHO_Pin);

	/*
	Function Name        : US_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize Ultrasonic .
	*/
		void US_vInit (void);
		
	/*
	Function Name        : US_Read_Distance_cm
	Function Returns     : unsigned short
	Function Arguments   : void
	Function Description : Calculate distance from sensor to Object .
	*/
		u16 US_Read_Distance_cm (void);

#endif /* ULTASONIC_H_ */