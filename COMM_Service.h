/*
 * COMM_Service.h
 *
 * Created: 7/21/2020 6:17:24 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef COMM_SERVICE_H_
#define COMM_SERVICE_H_
#include "USART_driver.h"
#include "SPI_driver.h"
#include "I2C.h"
#include "Data_type.h"
#include "stdmacros.h"
typedef enum{
	UART0_CHANNEL,
	SPI0_CHANNEL,
	I2C0_CHANNEL
	}Comm_channel_t;

typedef void (*Call_back_t)();

typedef struct {
	Call_back_t commTX_commplete;
	u8 *ptr_Data2Sent;
	u16 NUM_bytes_2Sent;
	Comm_channel_t Channel_Select;
	}CommTX_DataCFGType;
	
void Comm_TXInit(CommTX_DataCFGType *ptr_struct);

void Comm_TxDispatcher();

void COMM_TXReset();

#endif /* COMM_SERVICE_H_ */