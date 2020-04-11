/*
 * EEPROM_MCAL.h
 *

 *  Author: Mahmoud Ayman
 */ 


#ifndef EEPROM_MCAL_H_
#define EEPROM_MCAL_H_
/*
Function Name        : EEPROM_Write
Function Returns     : void
Function Arguments   : unsigned short address of the desired location ,unsigned char value 
Function Description : Write the value sent to the desired address 
*/
	void EEPROM_Write(u16 address , u8 value);

/*
Function Name        : EEPROM_Read
Function Returns     : unsigned char of the value 
Function Arguments   : unsigned short address of the desired location
Function Description : Read the value from the desired address
*/
	u8 EEPROM_Read(const u16 address);




#endif /* EEPROM_MCAL_H_ */