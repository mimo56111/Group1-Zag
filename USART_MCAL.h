/*
 * USART_MCAL.h
 *  Author: Mahmoud Ayman
 */ 

#ifndef USART_MCAL_H_
#define USART_MCAL_H_
#include "stdmacros.h"
#include "Data_type.h"
#include <avr/io.h>
void UART_vInit(u32 baud);
void UART_vSendData(u8 data);
u8 UART_u8ReceiveData(void);
void UART_vSendstring( u8 *ptr);
#endif /* USART_MCAL_H_ */