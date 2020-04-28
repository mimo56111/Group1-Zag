/*
 * Relay_ECU.c
 *
 *  Author: Mahmoud Ayman
 */ 
#include "Relay_ECU.h"

void Relay_vintialize(u8 port , u8 pin){
	GPIO_vsetPIN_DIR(port, pin, 1);
}

void Relay_vTurnon(u8 port, u8 pin){
	GPIO_vwrite_PIN(port,pin,1);
}

void Relay_vTurnoff(u8 port, u8 pin){
	GPIO_vwrite_PIN(port,pin,0);
}