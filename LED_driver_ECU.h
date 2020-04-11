/*
 * LED_driver_ECU.h
 * It has function used in initialize & turn on & turn off the LED
 * It is in ECU	abstraction layer
 */

#include "GPIO_MCAL.h"

#ifndef LED_DRIVER_ECU_H_
#define LED_DRIVER_ECU_H_

/*
Function Name        : LED_vinitialize
Function Returns     : void
Function Arguments   : unsigned char port name,unsigned char pin number
Function Description : Initialize the pin as an output pin to connect the led.
*/
	void LED_vintialize(u8 port , u8 pin);
/*
Function Name        : LED_vTurnOn
Function Returns     : void
Function Arguments   : unsigned char port name,unsigned char pin number
Function Description : Turn on the led connected to the given pin and port.
*/
	void LED_vTurnon(u8 port, u8 pin);
/*
Function Name        : LED_vTurnOff
Function Returns     : void
Function Arguments   : unsigned char port name,unsigned char pin number
Function Description : Turn off the led connected to the given pin and port.
*/
	void LED_vTurnoff(u8 port, u8 pin);
/*
Function Name        : LED_vToggle
Function Returns     : void
Function Arguments   : unsigned char port name,unsigned char pin number
Function Description : Toggle the led connected to the given pin and port.
*/
	void LED_vtoggle(u8 port, u8 pin);



#endif /* LED_DRIVER_ECU_H_ */