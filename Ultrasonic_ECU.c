/*
 * Ultrasonic_ECU.c
 *
 *  Author: Mahmoud Ayman
 */ 
#include "Ultasonic_ECU.h"
#define F_CPU 8000000UL
#include <util/delay.h>
void US_Get_Configuration (u8 TRIGGER_Port , u8 TRIGGER_Pin , u8 ECHO_Port , u8 ECHO_Pin){
	US_Config.Trigger_Port = TRIGGER_Port;
	US_Config.Trigger_Pin = TRIGGER_Pin;
	US_Config.Echo_Port = ECHO_Port;
	US_Config.Echo_Pin = ECHO_Pin;
}

void US_vInit (void){
/******************Adjust Trigger pin as Output*****************************/
	GPIO_vsetPIN_DIR(US_Config.Trigger_Port,US_Config.Trigger_Pin,1);
/***************************************************************************/
/**********************Adjust Echo pin as Input*****************************/
	GPIO_vsetPIN_DIR(US_Config.Echo_Port,US_Config.Echo_Pin,0);
/***************************************************************************/
}

u16 US_Read_Distance_cm (void){
	u16 distance , On_Time ;
	u16 a, b , c  ;
	SET_BIT(myTIFR,myICF1);
	myTCCR1A=0;
	myTCCR1B=0xc1;  //1100 0001 (Enable for ICU , detect rising edge , No prescaling)
	while(READ_BIT(myTIFR,myICF1)==0);
	a=ICR1;
	SET_BIT(myTIFR,myICF1);
	myTCCR1B=0x81;  //1000 0001 (Enable for ICU , detect falling edge , No prescaling)
	while(READ_BIT(myTIFR,myICF1)==0);
	b=ICR1;
	
	SET_BIT(myTIFR,myICF1);
	myTCCR1B=0xc1;  //1100 0001 (Enable for ICU , detect rising edge , No prescaling)
	while(READ_BIT(myTIFR,myICF1)==0);
	c=ICR1;
	SET_BIT(myTIFR,myICF1);
	myTCCR1B=0;
	if ((a<b) && (b<c)){
		On_Time = b - a;
		
	}
	
	
	distance = (((f32)On_Time) * 34300) / (F_CPU * 2) ;
	return distance;
}