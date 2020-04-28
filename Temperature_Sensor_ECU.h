/*
 * Temperature_Sensor_ECU.h
 *
 * Created: 4/19/2020 8:25:58 AM
 *  Author: Mahmoud Ayman
 */ 


#ifndef TEMPERATURE_SENSOR_ECU_H_
#define TEMPERATURE_SENSOR_ECU_H_
#include "ADC_MCAL.h"
#include "GPIO_MCAL.h"
#include "Register.h"
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
	Function Name        : temp_sensor_vInit
	Function Returns     : void
	Function Arguments   : unsigned char pin 
    Function Description : Initialize pin which temperature sensor is connected as input 
*/
	void temp_sensor_vInit(u8 pin);

/*
	Function Name        : temp_sensor_u16Read
	Function Returns     : unsigned short temperature 
	Function Arguments   : unsigned char pin 
    Function Description : Read temperature Sensor value 
*/
	u16 temp_sensor_u16Read(u8 pin);



#endif /* TEMPERATURE_SENSOR_ECU_H_ */