/*
 * PIR_ECU.h
 *
 *  Author: Mahmoud Ayman
 */ 


#ifndef PIR_ECU_H_
#define PIR_ECU_H_

#include "ADC_MCAL.h"
#include "GPIO_MCAL.h"
#include "Data_type.h"
/*
Function Name        : PIR_Init
Function Returns     : void
Function Arguments   : unsigned char port name,unsigned char pin number
Function Description : define the given pin in the given port as input pin
*/
	void PIR_Init(u8 port , u8 pin);
/*
Function Name        : PIR_u8Read
Function Returns     : unsigned char
Function Arguments   : unsigned char port name,unsigned char pin number
Function Description : Returns 0 or 1 depend on the status of the PIR(There is a motion or not) 
*/
	u8 PIR_u8Read(u8 port, u8 pin);

#endif /* PIR_ECU_H_ */