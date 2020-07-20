/*
 * slave_receive_data.c
 *
 * Created: 12/1/2019 6:49:21 PM
 *  Author: Mahmoud Ayman
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "I2C.h"
int main(void)
{
	unsigned char x;
	I2C_set_address(0b11100000); // set slave address and don't accept general call
	LCD_vInit();
    while(1)
    {
       x=I2C_slave_read();
	   LCD_vSend_char(x);
    }
}