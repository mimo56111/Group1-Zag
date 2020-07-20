/*
 * I2C_MCAL.c
 *
 * Created: 7/20/2020 1:18:24 PM
 *  Author: Mahmoud Ayman
 */ 
#include "I2C_MCAL.h"
#define I2C_BUSY  (!(myTWCR& (1<<TWINT)))
Call_backTX_t static_callBackTx;
Call_backRX_t static_callBackRX;
I2C_Status_t i2c_status; //static value to check whether it receive or transmit

ISR(TWI_vect){
	if(i2c_status == I2C_TX){
		static_callBackTx();
	}else{
		static_callBackRX(I2C_ReadwithACK_Interrupt());
	}
}
void I2C_Init(I2C_Status_t i2c_passStatus){
	i2c_passStatus = i2c_passStatus;
	myTWBR = 0x02; //bit Rate = 400 KHZ
	myTWSR=0x00; 
	myTWAR=0b11010000; //General call:OFF , TWI address if any master want to call me =0x01
	myTWCR=(1<<TWEN);//enable TWI
}
void I2C_Start(void){
	myTWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while(I2C_BUSY);
}
void I2C_Stop(void){
	myTWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}	
void I2C_Write(u8 data){
	myTWDR = data;
	myTWCR=(1<<TWINT)|(1<<TWEN);
	while(I2C_BUSY);
}
void I2C_TXwithInterrupt(u8 data){
	myTWDR = data;
	myTWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWIE);
}
u8 I2C_ReadwithACK(void){
	myTWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(I2C_BUSY);
	return myTWDR;
}
u8 I2C_ReadwithACK_Interrupt(void){
	myTWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA)|(1<<TWIE);
	return myTWDR;
}
void I2C_AssignCallBack_RX(Call_backRX_t pass_callback){
	static_callBackRX=pass_callback;
	myTWCR |= (1<<TWEN)|(1<<TWEA)|(1<<TWIE);
}
u8 I2C_ReadwithNACK(void){
	myTWCR=(1<<TWINT)|(1<<TWEN);
	while(I2C_BUSY);
	return myTWDR;
}
u8 I2C_GetStatus(void){
	u8 status;
	status = myTWSR & 0xF8; 
	return status;
}
void I2C_AssignCallBack_TX(Call_backTX_t pass_callback_fun){
	static_callBackRX = pass_callback_fun;
}
void I2C_Disable_Interrupt(void){
	myTWCR &= ~(1<<0); 
}