/*
 * master_send_data.c
 *
 * Created: 12/1/2019 6:42:22 PM
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "I2C.h"
int main(void)
{
	unsigned char counter=0;
	I2C_Master_init(50000);
	while(counter<10)
	{
		_delay_ms(500);
		I2C_start(); // transmit start condition
		I2C_write_address(0b11100000); // transmit SLA+W
		I2C_write_data(counter+48); // transmit data
		I2C_stop(); // transmit stop condition 
		counter++;
	}
}