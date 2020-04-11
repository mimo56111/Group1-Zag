/*
 * GPIO.c
 * It has functions that used in set & clear & toggle & read a bit & Port
 * It is in MCAL 
 */


#include "GPIO_MCAL.h"

//================================Initialization=======================================
 void GPIO_voidInit(void){
	 /*Comment!: DDR initialization  */
	myDDRA = Init_direction_default;
	myDDRB = Init_direction_default;
	myDDRC = Init_direction_default;
	myDDRD = Init_direction_default;
 }
//=====================================================================================

//===================================PIN===============================================

void GPIO_vsetPIN_DIR(u8 portnum, u8 pinnum, u8 dir ){
	switch (portnum){
		case 'A' :
		case 'a' :
			if(dir == 1){
				SET_BIT(myDDRA , pinnum);
			}else{
				CLR_BIT(myDDRA , pinnum);
			}
			break;
		case 'b' :
		case 'B' :
			if(dir == 1){
				SET_BIT(myDDRB , pinnum);
			}else{
				CLR_BIT(myDDRB , pinnum);
			}
			break;
		case 'C' :
		case 'c' :
			if(dir == 1){
				SET_BIT(myDDRC , pinnum);
			}else{
				CLR_BIT(myDDRC , pinnum);
			}
			break;
		case 'D' :
		case 'd' :
			if(dir == 1){
				SET_BIT(myDDRD , pinnum);
			}else{
				CLR_BIT(myDDRD , pinnum);
			}
			break;
		default: break;
	}
	
}

void GPIO_vwrite_PIN(u8 portnum , u8 pinnum , u8 value ){
	switch(portnum){
		case 'A':
		case 'a':
			if (value ==1){
				SET_BIT(myPORTA , pinnum);
			}else {
				CLR_BIT(myPORTA , pinnum);
			}
			break;
		case 'b':
		case 'B':
			if (value ==1){
				SET_BIT(myPORTB , pinnum);
			}else {
				CLR_BIT(myPORTB , pinnum);
			}
			break;
		case 'C':
		case 'c':
			if (value ==1){
				SET_BIT(myPORTC , pinnum);
			}else {
				CLR_BIT(myPORTC , pinnum);
			}
			break;
		case 'D':
		case 'd':
			if (value ==1){
				SET_BIT(myPORTD , pinnum);
			}else {
				CLR_BIT(myPORTD , pinnum);
			}
			break;
		default: break;
	}
}

u8 GPIO_u8read_PIN(u8 portnum, u8 pinnum){
	u8 x=0;
	switch (portnum){
		case 'A':
		case 'a':
			x= READ_BIT(myPINA, pinnum);
			break;
		case 'B':
		case 'b':
			x= READ_BIT(myPINB , pinnum);
			break;
		case 'C':
		case 'c':
			x= READ_BIT(myPINC , pinnum);
			break;
		case 'D':
		case 'd':
			x= READ_BIT(myPIND, pinnum);
			break;
		default: break;
	}
	return x;
}

void GPIO_vtoggle_PIN(u8 portnum, u8 pinnum){
	switch (portnum){
		case 'a' :
		case 'A' :
			TOGGLE_BIT(myPORTA, pinnum);
			break;
		case 'b' :
		case 'B' :
			TOGGLE_BIT(myPORTB, pinnum);
			break;
		case 'c' :
		case 'C' :
			TOGGLE_BIT(myPORTC, pinnum);
			break;
		case 'd' :
		case 'D' :
			TOGGLE_BIT(myPORTD, pinnum);
			break;
		default: break;
	}
}

void GPIO_vconnectpullup( u8 port, u8 pin , u8 connect_pullup ){
	switch (port){
		case 'A' :
		case 'a' :
			if (Connect==connect_pullup){
				SET_BIT(myPORTA,pin);
				CLR_BIT(mySFIOR,PUD);
			}else{
				CLR_BIT(myPORTA,pin);
			}
			break;
		case 'B' :
		case 'b' :
			if (Connect==connect_pullup){
				SET_BIT(myPORTB,pin);
				CLR_BIT(mySFIOR,PUD);
			}else{
				CLR_BIT(myPORTB,pin);
			}
			break;
		case 'C' :
		case 'c' :
			if (Connect==connect_pullup){
				SET_BIT(myPORTC,pin);
				CLR_BIT(mySFIOR,PUD);
			}else{
				CLR_BIT(myPORTC,pin);
			}
			break;
		case 'D' :
		case 'd' :
			if (Connect==connect_pullup){
				SET_BIT(myPORTD,pin);
				CLR_BIT(mySFIOR,PUD);
			}else{
				CLR_BIT(myPORTD,pin);
			}
		default:break;
	}
	
}

//==================================PORT=============================================

void GPIO_vset_PORT_DIR(u8 portnum, u8 dir){
	switch (portnum){
		case 'A' :
		case 'a' :
			myDDRA = dir;
			break;
		case 'b' :
		case 'B' :
			myDDRB = dir;
			break;
		case 'c' :
		case 'C' :
			myDDRC = dir;
			break;
		case 'd' :
		case 'D' :
			myDDRD = dir;
			break;
		default: break;
	}
}

void GPIO_vwrite_PORT(u8 portnum, u8 portvalue){
	switch (portnum){
		case 'A' :
		case 'a' :
			myPORTA = portvalue;
			break;
		case 'B' :
		case 'b' :
			myPORTB = portvalue;
			break;
		case 'C' :
		case 'c' :
			myPORTC = portvalue;
			break;
		case 'D' :
		case 'd' :
			myPORTD = portvalue;
			break;
		default: break;
	}
}

void GPIO_vtoggle_PORT(u8 portnum){
	switch (portnum){
		case 'A' :
		case 'a' :
			myPORTA = ~myPORTA;
			break;
		case 'B' :
		case 'b' :
			myPORTB = ~myPORTB;
			break;
		case 'C' :
		case 'c' :
			myPORTC = ~myPORTC;
			break;
		case 'D' :
		case 'd' :
			myPORTD = ~myPORTD;
			break;
		default: break;
	}
}
u8 GPIO_read_PORT(u8 portnum){
	volatile u8 val=0;
	switch (portnum){
		case 'a' :
		case 'A' :
			val = myPINA;
			break;
		case 'b' :
		case 'B' :
			val = myPINB;
			break;
		case 'c' :
		case 'C' :
			val = myPINC;
			break;
		case 'd' :
		case 'D' :
			val = myPIND;
			break;
		default: break;
	}
}
//=====================================================================================

//==================================Nibble=============================================

//==================================High Nibble========================================
void GPIO_High_Nibble_vset_dir(u8 port,u8 dir){
	if (1==dir){
		GPIO_vsetPIN_DIR(port,4,1);
		GPIO_vsetPIN_DIR(port,5,1);
		GPIO_vsetPIN_DIR(port,6,1);
		GPIO_vsetPIN_DIR(port,7,1);
	}else{
		GPIO_vsetPIN_DIR(port,4,0);
		GPIO_vsetPIN_DIR(port,5,0);
		GPIO_vsetPIN_DIR(port,6,0);
		GPIO_vsetPIN_DIR(port,7,0);
	}
	
}

void GPIO_High_Nibble_vwrite( u8 port , u8 value ){
	value <<= 4;   
	switch (port){    
		case 'A':
		case 'a':			
			myPORTA &=0x0f; 
			myPORTA |=value;
			break;				
		case 'B':
		case 'b':
			myPORTB &=0x0f;
			myPORTB |=value;
			break;
		case 'C':
		case 'c':
			myPORTC &=0x0f;
			myPORTC |=value;
			break;
		case 'D':
		case 'd':
			myPORTD &=0x0f;
			myPORTD |=value;
			break;
		default: break;
	}
}

//==================================Low Nibble========================================
void GPIO_Low_Nibble_vset_dir(u8 port,u8 dir){
	if (1==dir){
		GPIO_vsetPIN_DIR(port,0,1);
		GPIO_vsetPIN_DIR(port,1,1);
		GPIO_vsetPIN_DIR(port,2,1);
		GPIO_vsetPIN_DIR(port,3,1);
	}else{
		GPIO_vsetPIN_DIR(port,0,0);
		GPIO_vsetPIN_DIR(port,1,0);
		GPIO_vsetPIN_DIR(port,2,0);
		GPIO_vsetPIN_DIR(port,3,0);
	}
}

void GPIO_Low_Nibble_vwrite( u8 port , u8 value ){
	value &=0x0f;
	switch (port){
		case 'A':
		case 'a':
			myPORTA &=0xf0;
			myPORTA |=value;
			break;
		case 'B':
		case 'b':
			myPORTB &=0xf0;
			myPORTB |=value;
			break;
		case 'C':
		case 'c':
			myPORTC &=0xf0;
			myPORTC |=value;
			break;
		case 'D':
		case 'd':
			myPORTD &=0xf0;
			myPORTD |=value;
			break;
		default: break;
	}
}