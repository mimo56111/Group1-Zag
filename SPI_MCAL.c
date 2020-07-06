/*
 * SPI_MCAL.c
 *
 * Created: 7/6/2020 4:30:50 PM
 *  Author: Mahmoud Ayman
 */ 

#include "SPI_MCAL.h"
OBJ *Oblect;
void SPI_get_config(OBJ *ob,u8 mode, u8 prescaler, u8 en, u8 Speed,u8 Operating_level, u8 samp_edge, u8 data){
	Oblect = ob;
	Oblect->Mode=mode;
	Oblect->Prescaler=prescaler;
	Oblect->speed=Speed;
	Oblect->operating_level=Operating_level;
	Oblect->sampling_edge=samp_edge;
	Oblect->data_order=data;
}
void SPI_vInit(){
	if(Oblect->data_order== SPI_LSB_First){
		SET_BIT(SPCR,DORD);
	}else if(Oblect->data_order== SPI_MSB_First){
		CLR_BIT(SPCR,DORD);
	}else{
		
	}
	
	if(Oblect->Mode==Master){
		SET_BIT(SPCR,MSTR);
	}else if(Oblect->Mode==Slave){
		CLR_BIT(SPCR,MSTR);
	}else{
		
	}
	
	if(Oblect->operating_level== SPI_Idle_LOW){
		SET_BIT(SPCR,CPOL);
	}else if(Oblect->operating_level== SPI_Idle_HIGH){
		CLR_BIT(SPCR,CPOL);
	}else{
		
	}
	
	if(Oblect->sampling_edge==SPI_RISE){
		SET_BIT(SPCR,CPHA);
	}else if(Oblect->sampling_edge==SPI_Falling){
		CLR_BIT(SPCR,CPHA);
	}else{
		
	}
	
	Oblect->Prescaler &= 0x03;
	SPCR |= Oblect->Prescaler;
	
	if(Oblect->speed==DOUBLE_SPEED){
		SET_BIT(SPSR,SPI2X);
	}else if(Oblect->speed==NORMAL_SPEED){
		CLR_BIT(SPSR,SPI2X);
	}else{
		
	}
	
	if(Oblect->Enable==SPI_EN){
		SET_BIT(SPCR,SPE);
	}else if(Oblect->Enable==SPI_DIS){
		CLR_BIT(SPCR,SPE);
	}else{
		
	}		
}
u8 SPI_send_and_receive(u8 Data){
	SPDR = Data;
	while(READ_BIT(SPSR,SPIF)==0);
	return SPDR;
}
u8 SPI_check_for_collision(void){
	u8 local_collision;
	local_collision= READ_BIT(SPSR,WCOL);
	return local_collision;
}