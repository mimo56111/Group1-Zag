/*
 * receive_string_using_USART.c
 *
 */ 

#include "USART.h"
#include "LCD.h"
int main(void)
{
	LCD_vInit();
	UART_vInit(9600);
	char x;
    while(1)
    {
       x=UART_u8ReceiveData();
	   LCD_vSend_char(x);
    }
}

