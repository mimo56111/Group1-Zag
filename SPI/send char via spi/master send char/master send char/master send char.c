


#include <avr/io.h>
#include "spi_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	/*Initialize SPI as master*/
	SPI_MasterInit();
	unsigned char counter=0;
    while(counter<10)
    {
		SPI_MasterTransmitchar(counter+48);
		_delay_ms(300);
		counter++;
    }
}
