/*
 * SPI_driver.c
 *
 *  Author: Mahmoud Ayman
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "GPIO_MCAL.h"
#include "stdmacros.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void SPI_MasterInit(void)
{
	/*Set SS / MOSI / SCK  as output pins for master*/
	GPIO_vsetPIN_DIR('B',4,1);
	GPIO_vsetPIN_DIR('B',5,1);
	GPIO_vsetPIN_DIR('B',7,1);
	/*Enable Master mode*/
	SET_BIT(SPCR,MSTR);
	/*Set clock to fosc/16*/
	SET_BIT(SPCR,SPR0);
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
	/*set SS to high */
	GPIO_vwrite_PIN('B',4,1);
}

void SPI_SlaveInit(void)
{
	CLR_BIT(SPCR,MSTR);
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
	/*Set MISO as output*/
	GPIO_vsetPIN_DIR('B',6,1);
}

unsigned char SPI_MasterTransmitchar(unsigned char Data)
{
	/*Clear SS to send data to slave*/
	GPIO_vwrite_PIN('B',4,0);
	/*Put data on SPDR*/
	SPDR=Data;
	/*Wait until the transmission is finished*/
	while(READ_BIT(SPSR,SPIF)==0);
	/*read SPDR*/
	return SPDR ;
}

unsigned char SPI_SlaveReceivechar(unsigned char Data)
{
	/*Put data on SPDR*/
	SPDR=Data;
	/*Wait until data is received in SPI register*/
	while(READ_BIT(SPSR,SPIF)==0);
	/*read the received data*/
	return SPDR ;
}

void SPI_MasterTransmitstring(unsigned char *ptr)
{
	while((*ptr)!=0)
	{
		SPI_MasterTransmitchar(*ptr);
		_delay_ms(300);
		ptr++;
	}
}