/*
 * COMM_Service.c
 *
 * Created: 7/21/2020 6:17:53 PM
 *  Author: Mahmoud Ayman
 */ 
#include "COMM_Service.h"
static CommTX_DataCFGType Staticptr_CFGCommTx;

#define SPTR_DATA2SENT      (Staticptr_CFGCommTx.ptr_Data2Sent)
#define S_CHANNEL           (Staticptr_CFGCommTx.Channel_Select)
#define NUM_BYTES           (Staticptr_CFGCommTx.NUM_bytes_2Sent)
#define CallTX_FINISH       (Staticptr_CFGCommTx.commTX_commplete)

static u16 Scounter; //To keep counting the data have been sent
static u8  flag_TX_sending;
static void Hardware_Callback(){
	u8 x;
	if(Scounter<=NUM_BYTES){
		Scounter++;
		switch(S_CHANNEL){
			case UART0_CHANNEL :
				USART_Transmit(SPTR_DATA2SENT[Scounter]);
				break;
			case SPI0_CHANNEL :
				x=SPI_MasterTransmitchar(SPTR_DATA2SENT[Scounter]);
				break;
			case I2C0_CHANNEL : 
				I2C_TXwithInterrupt(SPTR_DATA2SENT[Scounter]);  
				break; 
		}
		Scounter++;
		if(Scounter > NUM_BYTES){
			Scounter--;
		}
	}
	flag_TX_sending =1;
}
void Comm_TXInit(CommTX_DataCFGType *ptr_struct){
	/*
	* Delay to let the Receiver be Ready
	* Check if COMM TX in ideal mode at first
	* Take Configuration to static variable
	* Switch on Channels to INIT the required one 
	*/
	
	//store CFG variables 
	Staticptr_CFGCommTx.Channel_Select= ptr_struct->Channel_Select;
	Staticptr_CFGCommTx.NUM_bytes_2Sent=ptr_struct->NUM_bytes_2Sent;
	Staticptr_CFGCommTx.commTX_commplete=ptr_struct->commTX_commplete;
	Staticptr_CFGCommTx.ptr_Data2Sent=ptr_struct->ptr_Data2Sent;
	//Init Hardware
	switch(S_CHANNEL){
		case UART0_CHANNEL :
		//struct creat 
			USART_Config x;
			USART_get_config(&x,ASYNC_MODE,NORMAL_SPEED,9600,USART_TRANSMIT_ENABLE,USART_RECIEVE_DISABLE,USART_8_BIT_CHAR,EVEN_PARITY,TWO_STOP_BIT);
			USART_get_INT_config(TRANSMIT_INT_ENABLE,RECIEVE_INT_DISABLE,&Hardware_Callback,0);
			USART_Init();
			USART_Transmit(SPTR_DATA2SENT[Scounter]);
			break;
	}
}
static void DISSARM_Hardware_Interrupt(){
	switch(S_CHANNEL){
		case UART0_CHANNEL :
			USART_Config x;
			USART_get_config(&x,ASYNC_MODE,NORMAL_SPEED,9600,USART_TRANSMIT_ENABLE,USART_RECIEVE_DISABLE,USART_8_BIT_CHAR,EVEN_PARITY,TWO_STOP_BIT);
			USART_get_INT_config(TRANSMIT_INT_DISABLE,RECIEVE_INT_DISABLE,0,0);
	}
}	

void Comm_TxDispatcher(){
	if(flag_TX_sending){
		flag_TX_sending=0;
		if(Scounter==NUM_BYTES){
			DISSARM_Hardware_Interrupt();
			CallTX_FINISH();
		}
	}		
}

void COMM_TXReset(){
	/*
	* This Function used to free the COMM_TX
	* To Init new transmition
	*/ 
	Scounter = 0;
	flag_TX_sending = 0;
}