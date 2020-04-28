/*
 * LDR_ECU.c
 *
 *  Author: Mahmoud Ayman
 */ 
#include "LDR_ECU.h"
void LDR_sensor_vInit(u8 pin){
	ADC_vInit();
	switch(pin){		
		case 0 :
		GPIO_vsetPIN_DIR('A',0,0);  
		break;
		case 1 :
		GPIO_vsetPIN_DIR('A',1,0);
		break;
		case 2 :
		GPIO_vsetPIN_DIR('A',2,0);
		break;
		case 3 :
		GPIO_vsetPIN_DIR('A',3,0);
		break;
		case 4 :
		GPIO_vsetPIN_DIR('A',4,0);
		break;
		case 5 :
		GPIO_vsetPIN_DIR('A',5,0);
		break;
		case 6 :
		GPIO_vsetPIN_DIR('A',6,0);
		break;
		case 7 :
		GPIO_vsetPIN_DIR('A',7,0);
		break;
	}
}

u16 LDR_sensor_u16Read(u8 pin){
	u16 intensity ;
	
	intensity = ADC_u16Read_Single_Endded(pin);
	
	return intensity;
}