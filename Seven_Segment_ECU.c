/*
 * Seven_Segment_ECU.c
 *

 *  Author: Mahmoud Ayman
 */ 
#include "GPIO_MCAL.h"
#include "Data_type.h"
#define  Four_bit 0
#define  Eight_bit 1
#define  High_Nibble 1
#define  LOW_Nibble 0

void Seven_Segment_Init(u8 Mode,u8 port ,u8 Nibble){
	if (0 == Mode){
		if (0==Nibble){
			GPIO_Low_Nibble_vset_dir(port,1);
		}else if (1==Nibble){
			GPIO_High_Nibble_vset_dir(port,1);
		}
		else{
			
		}
	}else if (1==Mode){
		GPIO_vset_PORT_DIR(port,0xff);
	} 
	else{
		
	}
}


void Seven_segment_Display(u8 Mode,u8 Nibble , u8 port, u8 value){
	if (0 == Mode){
		if (0==Nibble){
			GPIO_Low_Nibble_vwrite(port,value);
		}else if (1==Nibble){
			GPIO_High_Nibble_vwrite(port,value);
		}
		else{
			
		}
	}else if (1==Mode){
		if (value >=0 && value <=9)
		{
			u8 arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
			GPIO_vwrite_PORT(port,arr[value]);
		}else {
			#define A 0
			#define B 1
			#define C 2
			#define D 3
			#define E 4
			#define F 5
			u8 arr1[6]={0x77,0x1f,0x39,0x5E,0x79,0x71};
			GPIO_vwrite_PORT(port,arr1[value]);
		}
	}
	else{
		
	}
}