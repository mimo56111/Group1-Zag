/*
 * I2C.c
 *  Author: Mahmoud Ayman
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include "I2C.h"
#define prescalar 1
void I2C_Master_init(u32 SCL_Clock){
	TWBR= (u8) (((F_CPU/SCL_Clock)-16) / (2*prescalar));
	if (prescalar==1){
		TWSR=0;
	}else if (prescalar==4){
		TWSR=1;
	}else if (prescalar==16){
		TWSR=2;
	}else if (prescalar==64){
		TWSR=3;
	}
}

void I2C_start(void){
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(READ_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x08); // start condition has been transmitted
}

void I2C_write_address(u8 address){
	TWDR=address;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x18); // SLA+write has been transmitted and ACK has been received
}

void I2C_write_data(u8 data){
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x28); // data has been transmitted and ACK has been received
}

void I2C_stop(void){
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void I2C_set_address(u8 address){
	TWAR=address;
}

u8 I2C_slave_read(void){
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x60); // own SLA+W has been received and ACK has been returned
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x80); // previously addressed with own SLA+W : data has been received : ACK has been returned
	return TWDR ;
}