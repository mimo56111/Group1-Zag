/*
 *  GPIO.h
 *
 *  It has functions that used in set & clear & toggle & read a bit & Port
 *  It is in MCAL
 */
#define u8_Direction_input 0x00
//choose the default initialization for GPIO
#define Init_direction_default  u8_Direction_input


#include "Data_type.h"
#include "Register.h"
#include "stdmacros.h"
#define Connect  1
#define NotConnected 0
#ifndef GPIO_H_
#define GPIO_H_
//================================Initialization=======================================

/*Comment!: Initialization ports */
	void GPIO_voidInit(void);
//=====================================================================================

//===================================PIN===============================================
	/*
	Function Name        : GPIO_vsetPIN_Dir
	Function Returns     : void
	Function Arguments   : unsigned char port name,unsigned char pin number,unsigned char direction
	Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
	*/
		void GPIO_vsetPIN_DIR(u8 portnum, u8 pinnum, u8 dir );
	
	/*
	Function Name        : GPIO_vwrite_PIN
	Function Returns     : void
	Function Arguments   : unsigned char port name,unsigned char pin number,unsigned char output value
	Function Description : Set the value of the given pin in the given port (output value 0 = low : 1 = high)
	*/
		void GPIO_vwrite_PIN(u8 portnum , u8 pinnum , u8 value );
	/*
	Function Name        : GPIO_u8read_PIN
	Function Returns     : unsigned char
	Function Arguments   : unsigned char port name,unsigned char pin number
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
	*/
		u8 GPIO_u8read_PIN(u8 portnum, u8 pinnum);
	/*
	Function Name        : GPIO_vtoggle_PIN
	Function Returns     : void
	Function Arguments   : unsigned char port name,unsigned char pin number
	Function Description : Reverse the value of the given pin in the given port.
	*/
		void GPIO_vtoggle_PIN(u8 portnum, u8 pinnum);
		
	/*
	Function Name        : GPIO_vconnectpullup
	Function Returns     : void
	Function Arguments   : char port name ,char pin number, char connect_pullup
    Function Description : Connect and disconnect pull up resistor to the given pin at the given port 
	*/
		void GPIO_vconnectpullup(u8 port, u8 pin , u8 connect_pullup);	
//===================================================================================

//==================================PORT=============================================

/*
Function Name        : GPIO_vset_PORT_DIR
Function Returns     : void
Function Arguments   : unsigned char port name,unsigned char direction
Function Description : set the direction of whole port .
*/
	void GPIO_vset_PORT_DIR(u8 portnum, u8 dir);

/*
Function Name        : GPIO_vwrite_PORT
Function Returns     : void
Function Arguments   : unsigned char port name,unsigned char port value
Function Description : Write the value to all port pins.
*/
	void GPIO_vwrite_PORT(u8 portnum, u8 portvalue);

/*
Function Name        : GPIO_vtoggle_PORT
Function Returns     : void
Function Arguments   : unsigned char port name
Function Description : Reverse the value of the given port.
*/
	void GPIO_vtoggle_PORT(u8 portnum);

/*
Function Name        : GPIO_read_PORT
Function Returns     : unsigned char
Function Arguments   : unsigned char port name
Function Description : read the value of the port .
*/
	u8 GPIO_read_PORT(u8 portnum);


	
	
	
//=====================================================================================

//==================================Nibble=============================================

//==================================High Nibble========================================
/*
Function Name        : GPIO_High_Nibble_vset_dir
Function Returns     : void
Function Arguments   : unsigned char port name
Function Description : Set the direction of the highest four bins of the given port as output to connect 7segment
*/
	void GPIO_High_Nibble_vset_dir(u8 port,u8 dir);
	
/*
Function Name        : GPIO_High_Nibble_vwrite
Function Returns     : void
Function Arguments   : unsigned char port name , unsigned char output value
Function Description : Set the value in the highest four bit in the given port (output value 0 = low : 1 = high)
*/
	void GPIO_High_Nibble_vwrite(u8 port , u8 value);
	
	
//==================================Low Nibble========================================
/*
Function Name        : GPIO_Low_Nibble_vset_dir
Function Returns     : void
Function Arguments   : unsigned char port name
Function Description : Set the direction of the lowest four bins of the given port as output to connect the 7segment
*/
	void GPIO_Low_Nibble_vset_dir(u8 port,u8 dir);
/*
Function Name        : GPIO_Low_Nibble_vwrite
Function Returns     : void
Function Arguments   : unsigned char port name , unsigned char output value
Function Description : Set the value in the lowest four bit in the given port (output value 0 = low : 1 = high)
*/
	void GPIO_Low_Nibble_vwrite(u8 port , u8 value);

#endif /* GPIO_H_ */