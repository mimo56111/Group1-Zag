/*
 * ADC_MCAL.h
 *
 *  Author: Mahmoud Ayman
 */ 


#ifndef ADC_MCAL_H_
#define ADC_MCAL_H_
#include "Register.h"
#include "stdmacros.h"
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
	Function Name        : ADC_vInit
	Function Returns     : void
	Function Arguments   : void
    Function Description : Initialize ADC to work 
*/
	void ADC_vInit(); 
/*
	Function Name        : ADC_u16Read_Single_Endded
	Function Returns     : unsigned short data
	Function Arguments   : unsigned char channel_number
    Function Description : Read the data after converntion from analog to digital  
*/
	u16 ADC_u16Read_Single_Endded(u8 channel_number);



#endif /* ADC_MCAL_H_ */