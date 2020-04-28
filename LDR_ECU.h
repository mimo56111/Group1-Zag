/*
 * LDR_ECU.h
 *
 *  Author: Mahmoud Ayman
 */ 


#ifndef LDR_ECU_H_
#define LDR_ECU_H_
#include "ADC_MCAL.h"
#include "GPIO_MCAL.h"
#include "Data_type.h"
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7
/*
	Function Name        : LDR_sensor_vInit
	Function Returns     : void
	Function Arguments   : unsigned char pin 
    Function Description : Initialize pin which LDR sensor is connected as input 
*/
	void LDR_sensor_vInit(u8 pin);

/*
	Function Name        : LDR_sensor_u16Read
	Function Returns     : unsigned short Light intensity  
	Function Arguments   : unsigned char pin 
    Function Description : Read LDR Sensor value 
*/
	u16 LDR_sensor_u16Read(u8 pin);



#endif /* LDR_ECU_H_ */