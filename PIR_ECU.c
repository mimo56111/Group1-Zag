/*
 * PIR_ECU.c
 *
 *  Author: Mahmoud Ayman
 */ 
#include "PIR_ECU.h"
void PIR_Init(u8 port , u8 pin){
	GPIO_vsetPIN_DIR(port, pin,0);
}


u8 PIR_u8Read(u8 port, u8 pin){
	u8 x;
	x= GPIO_u8read_PIN(port,pin);

	return x;
}