/*
 * SPI_MCAL.h
 *
 * Created: 7/6/2020 4:30:28 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef SPI_MCAL_H_
#define SPI_MCAL_H_
#include "Avr/io.h"
#include "Data_type.h"
#include "stdmacros.h"
#define Master 1 
#define Slave  0

#define FOSC4  0
#define FOSC16 1
#define FOSC64 2
#define FOSC128 3  

#define SPI_EN 1
#define SPI_DIS 0

#define DOUBLE_SPEED 0
#define NORMAL_SPEED 1

#define SPI_RISE 1
#define SPI_Falling 0

#define SPI_Idle_LOW 0
#define SPI_Idle_HIGH 1

#define SPI_LSB_First 1
#define SPI_MSB_First 0

typedef struct{
	u8 Mode;
	u8 Prescaler;
	u8 Enable;
	u8 speed;
	u8 operating_level;
	u8 sampling_edge;
	u8 data_order;
	}OBJ;

void SPI_get_config(OBJ *ob,u8 mode, u8 prescaler, u8 en, u8 Speed,u8 Operating_level, u8 samp_edge, u8 data);
void SPI_vInit();
u8 SPI_send_and_receive(u8 Data);
u8 SPI_check_for_collision(void);


#endif /* SPI_MCAL_H_ */