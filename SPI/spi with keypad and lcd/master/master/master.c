/*
 * master.c
 *
 * Created: 10/31/2019 1:01:40 PM
 */ 


#include <avr/io.h>
#include "spi_driver.h"
#include "keypad_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	unsigned char x=0xff;
	keypad_vInit();
	SPI_MasterInit();
    while(1)
    {
       x=keypad_u8check_press();
	   if(x!=0xff)
	   {
		   SPI_MasterTransmitchar(x);
	   }
	   _delay_ms(250);
    }
}