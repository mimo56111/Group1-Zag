/*
 * slave_receive_string.c
 *
 * Created: 10/31/2019 12:22:00 PM
 */ 


#include <avr/io.h>
#include "spi_driver.h"
#include "LCD.h"
#define DUMMY_DATA 0xff
int main(void)
{
	LCD_vInit();
	SPI_SlaveInit();
	unsigned char x;
    while(1)
    {
        x=SPI_SlaveReceivechar(DUMMY_DATA);
		LCD_vSend_char(x);
    }
}
