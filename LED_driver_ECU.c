/*
 * LED_driver_ECU.c
 * It has function used in initialize , turn on , turn off & toggle the LED
 * It is in ECU abstraction layer 
 */

#include "GPIO_MCAL.h"
void LED_vintialize(u8 port , u8 pin){
	GPIO_vsetPIN_DIR(port, pin, 1);
}
void LED_vTurnon(u8 port, u8 pin){
	GPIO_vwrite_PIN(port,pin,1);
}
void LED_vTurnoff(u8 port, u8 pin){
	GPIO_vwrite_PIN(port,pin,0);
}
void LED_vtoggle(u8 port, u8 pin){
	GPIO_vtoggle_PIN(port,pin);
}