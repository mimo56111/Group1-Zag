/*
 * Relay_ECU.h
 *
 *  Author: Mahmoud Ayman
 */ 


#ifndef RELAY_ECU_H_
#define RELAY_ECU_H_
#include "GPIO_MCAL.h"
#include "stdmacros.h"
#include "Register.h"
/*
Function Name        : Relay_vinitialize
Function Returns     : void
Function Arguments   : unsigned char port name,unsigned char pin number
Function Description : Initialize the pin as an output pin to connect the Relay.
*/
	void Relay_vintialize(u8 port , u8 pin);
/*
Function Name        : Relay_vTurnOn
Function Returns     : void
Function Arguments   : unsigned char port name,unsigned char pin number
Function Description : Turn on the Relay connected to the given pin and port.
*/
	void Relay_vTurnon(u8 port, u8 pin);
/*
Function Name        : Relay_vTurnOff
Function Returns     : void
Function Arguments   : unsigned char port name,unsigned char pin number
Function Description : Turn off the Relay connected to the given pin and port.
*/
	void Relay_vTurnoff(u8 port, u8 pin);


#endif /* RELAY_ECU_H_ */