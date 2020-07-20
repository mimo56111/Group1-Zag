/*
 * slave_receive_char.c
 *
 * Created: 10/31/2019 12:11:56 AM
 */ 


#include <avr/io.h>
#include "spi_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	/*Initialize SPI as slave*/
	SPI_SlaveInit();
	LCD_vInit();
	unsigned char x=0x30;
	unsigned char z=0;
    while(z<10)
    {		
	   x= SPI_SlaveReceivechar(x);
	   LCD_vSend_char(x);
	   z++;
    }
}
