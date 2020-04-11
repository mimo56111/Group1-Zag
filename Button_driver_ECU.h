/*
* Button_driver_ECU.h
* It has function used in initialize & read the button
* It is in ECU abstraction layer
*/

#include "GPIO_MCAL.h"

#ifndef BUTTON_DRIVER_ECU_H_
#define BUTTON_DRIVER_ECU_H_

/*
Function Name        : button_vInit
Function Returns     : void
Function Arguments   : unsigned char port name,unsigned char pin number
Function Description : define the given pin in the given port as input pin
*/
void button_vInit(u8 port,u8 pin);
/*
Function Name        : button_u8read
Function Returns     : unsigned char
Function Arguments   : unsigned char port name,unsigned char pin number
Function Description : Returns 0 or 1 depend on the status of the button(pressed or not) and the type of connection (pull up or pull down)
*/
u8 button_u8read(u8 port,u8 pin);



#endif /* BUTTON_DRIVER_ECU_H_ */