/*
 * send_string_using_USART.c
 *
 */ 


#include "USART.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	UART_vInit(9600);
	_delay_ms(300);
	UART_vSendstring("Zag Group1");
    while(1)
    {
      
    }
}