/*
 * Button_driver_ECU.c
 * It has function used in initialize & read the button
 * It is in ECU abstraction layer
 */ 
#include "GPIO_MCAL.h"
#define F_CPU 8000000UL
#include "util/delay.h"

void button_vInit( u8 port,u8 pin ){
	GPIO_vsetPIN_DIR(port, pin,0);
	
}

u8 button_u8read( u8 port,u8 pin ){
	u8 x;
	x= GPIO_u8read_PIN(port,pin);
	
	return x;
}
