/*
 * USART_driver.c
 *
 *  Author: Mahmoud Ayman
 */ 
#include "USART_driver.h"
#include <avr/io.h>
#define F_CPU 8000000UL

USART_Config *OBJECT;
void (*TX_CB_function)(void);
void (*RX_CB_function)(void);
usart_ErrorTypes USART_get_config (USART_Config *obj , u8 Synchronous , u8 Speed , u32 Baud_rate , u8 TX_Enable , u8 RX_Enable , u8 Size , u8 parity , u8 Stop_bit ){
	OBJECT = obj;
	usart_ErrorTypes s_ret_val = NO_USART_ERRORS;
	OBJECT->SYNCH_MODE = Synchronous;
	OBJECT->SPEED_MODE = Speed;
	OBJECT->Baud_Rate =Baud_rate;
	OBJECT->Transmit = TX_Enable;
	OBJECT->Recieve = RX_Enable;
	OBJECT->Char_Size = Size;
	OBJECT->Parity_Mode = parity;
	OBJECT->Stop_Bit = Stop_bit;
	OBJECT->Recieve_INT=RECIEVE_INT_DISABLE;
	OBJECT->Transmit_INT=TRANSMIT_INT_DISABLE;
	return s_ret_val;
}


usart_ErrorTypes USART_get_INT_config (u8 TX_INT,u8 RX_INT, void (*TX_CB_func)(void) , void (*RX_CB_func)(void)){
	usart_ErrorTypes s_ret_val = NO_USART_ERRORS;
	if(OBJECT==0){
		s_ret_val= DEVICE_NOT_INITIATED;
	}else{
		OBJECT->Transmit_INT=TX_INT;
		OBJECT->Recieve_INT = RX_INT;
		if (TX_CB_func==0 || RX_CB_func ==0){
			s_ret_val = INVALID_PARAMS;
		}else{
			OBJECT->USART_Transmit_Complete_User_CBK= TX_CB_func;
			OBJECT->USART_Recieve_Complete_User_CBK = RX_CB_func;
		}
	}
	return s_ret_val;
}

usart_ErrorTypes USART_Init(void){
	usart_ErrorTypes s_ret_val = NO_USART_ERRORS;
	u32 UBRR_Val;
	if (OBJECT ==0){
		s_ret_val = DEVICE_NOT_INITIATED;
	}else{
		if (OBJECT->Transmit == USART_TRANSMIT_ENABLE ){
			/*********Set Baud Rate***********/
				if((OBJECT->SYNCH_MODE==ASYNC_MODE)&&(OBJECT->SPEED_MODE == USART_NORMAL_MODE)){
					UBRR_Val = (u32)(((F_CPU)/(16*OBJECT->Baud_Rate))-1);
				}else if((OBJECT->SYNCH_MODE==ASYNC_MODE)&&(OBJECT->SPEED_MODE == USART_Double_SPEED_MODE)){
					UBRR_Val = (u32)(((F_CPU)/(8*OBJECT->Baud_Rate))-1);
				}else if(OBJECT->SYNCH_MODE==SYNC_MODE){
					UBRR_Val = (u32)(((F_CPU)/(2*OBJECT->Baud_Rate))-1);
				}
				 UBRRH =(u8) (UBRR_Val>>8);
				 UBRRL =(u8) (UBRR_Val);
			/*******************************/
			/************** Enable transmitter **************/
				SET_BIT(UCSRB,TXEN);
			/************************************************/
			/******************Char size*********************/
				switch(OBJECT->Char_Size){
					case (USART_5_BIT_CHAR) :
						CLR_BIT(UCSRB,UCSZ2);
						CLR_BIT(UCSRC,UCSZ1);
						CLR_BIT(UCSRC,UCSZ0);
						break;
					case (USART_6_BIT_CHAR) :
						CLR_BIT(UCSRB,UCSZ2);
						CLR_BIT(UCSRC,UCSZ1);
						SET_BIT(UCSRC,UCSZ0);
						break;
					case (USART_7_BIT_CHAR) :
						CLR_BIT(UCSRB,UCSZ2);
						SET_BIT(UCSRC,UCSZ1);
						CLR_BIT(UCSRC,UCSZ0);
						break;
					case (USART_8_BIT_CHAR) :
						CLR_BIT(UCSRB,UCSZ2);
						SET_BIT(UCSRC,UCSZ1);
						SET_BIT(UCSRC,UCSZ0);
						break;
					case (USART_9_BIT_CHAR) :
						SET_BIT(UCSRB,UCSZ2);
						SET_BIT(UCSRC,UCSZ1);
						SET_BIT(UCSRC,UCSZ0);
						break;
					default: break;
				}
			/************************************************/
			/**************** Set Double speed***************/
				if((OBJECT->SYNCH_MODE==ASYNC_MODE)&&(OBJECT->SPEED_MODE == USART_Double_SPEED_MODE)){
					SET_BIT(UCSRA,U2X);
				}
			/***********************************************/
			/**************** Set Parity Bit***************/
				if (OBJECT->Parity_Mode==NO_PARITY){
					CLR_BIT(UCSRC,UPM0);
					CLR_BIT(UCSRC,UPM1);
				}else if (OBJECT->Parity_Mode==EVEN_PARITY){
					CLR_BIT(UCSRC,UPM0);
					SET_BIT(UCSRC,UPM1);
			    }else if (OBJECT->Parity_Mode==ODD_PARITY){
					SET_BIT(UCSRC,UPM0);
					SET_BIT(UCSRC,UPM1);
				}
			/**********************************************/
			/**************** Set Stop Bit***************/
				if (OBJECT->Stop_Bit==ONE_STOP_BIT){
					CLR_BIT(UCSRC,USBS);
				}else if(OBJECT->Stop_Bit==TWO_STOP_BIT ){
					SET_BIT(UCSRC,USBS);
				}
			/********************************************/
			/***************RECIEVER INT ENABLE**********/
				if (OBJECT->Recieve_INT==RECIEVE_INT_ENABLE){
					SET_BIT(UCSRB,RXCIE);
				}else if (OBJECT->Recieve_INT==RECIEVE_INT_DISABLE){
					CLR_BIT(UCSRB,RXCIE);
				} 
			/********************************************/
			/***************Transmit INT ENABLE**********/
				if (OBJECT->Transmit_INT==TRANSMIT_INT_ENABLE){
					SET_BIT(UCSRB,TXCIE);
				}else if (OBJECT->Transmit_INT==TRANSMIT_INT_DISABLE){
					CLR_BIT(UCSRB,TXCIE);
				}
			/********************************************/
		} 
		else{
			CLR_BIT(UCSRB,TXEN);
		}
		if (OBJECT->Recieve == USART_RECIEVE_ENABLE ){
			/*********Set Baud Rate***********/
			if((OBJECT->SYNCH_MODE==ASYNC_MODE)&&(OBJECT->SPEED_MODE == USART_NORMAL_MODE)){
				UBRR_Val = (u32)(((F_CPU)/(16*OBJECT->Baud_Rate))-1);
			}else if((OBJECT->SYNCH_MODE==ASYNC_MODE)&&(OBJECT->SPEED_MODE == USART_Double_SPEED_MODE)){
				UBRR_Val = (u32)(((F_CPU)/(8*OBJECT->Baud_Rate))-1);
			}else if(OBJECT->SYNCH_MODE==SYNC_MODE){
				UBRR_Val = (u32)(((F_CPU)/(2*OBJECT->Baud_Rate))-1);
			}
			UBRRH =(u8) (UBRR_Val>>8);
			UBRRL =(u8) (UBRR_Val);
			/*******************************/
			/************** Enable Reciver **************/
				SET_BIT(UCSRB,RXEN);
			/************************************************/
			/******************Char size*********************/
			switch(OBJECT->Char_Size){
				case (USART_5_BIT_CHAR) :
				CLR_BIT(UCSRB,UCSZ2);
				CLR_BIT(UCSRC,UCSZ1);
				CLR_BIT(UCSRC,UCSZ0);
				break;
				case (USART_6_BIT_CHAR) :
				CLR_BIT(UCSRB,UCSZ2);
				CLR_BIT(UCSRC,UCSZ1);
				SET_BIT(UCSRC,UCSZ0);
				break;
				case (USART_7_BIT_CHAR) :
				CLR_BIT(UCSRB,UCSZ2);
				SET_BIT(UCSRC,UCSZ1);
				CLR_BIT(UCSRC,UCSZ0);
				break;
				case (USART_8_BIT_CHAR) :
				CLR_BIT(UCSRB,UCSZ2);
				SET_BIT(UCSRC,UCSZ1);
				SET_BIT(UCSRC,UCSZ0);
				break;
				case (USART_9_BIT_CHAR) :
				SET_BIT(UCSRB,UCSZ2);
				SET_BIT(UCSRC,UCSZ1);
				SET_BIT(UCSRC,UCSZ0);
				break;
				default: break;
			}
			/************************************************/
			/**************** Set Double speed***************/
			if((OBJECT->SYNCH_MODE==ASYNC_MODE)&&(OBJECT->SPEED_MODE == USART_Double_SPEED_MODE)){
				SET_BIT(UCSRA,U2X);
			}
			/***********************************************/
			/**************** Set Parity Bit***************/
			if (OBJECT->Parity_Mode==NO_PARITY){
				CLR_BIT(UCSRC,UPM0);
				CLR_BIT(UCSRC,UPM1);
			}else if (OBJECT->Parity_Mode==EVEN_PARITY){
				CLR_BIT(UCSRC,UPM0);
				SET_BIT(UCSRC,UPM1);
			}else if (OBJECT->Parity_Mode==ODD_PARITY){
				SET_BIT(UCSRC,UPM0);
				SET_BIT(UCSRC,UPM1);
			}
			/**********************************************/
			/**************** Set Stop Bit***************/
			if (OBJECT->Stop_Bit==ONE_STOP_BIT){
				CLR_BIT(UCSRC,USBS);
			}else if(OBJECT->Stop_Bit==TWO_STOP_BIT ){
				SET_BIT(UCSRC,USBS);
			}
			/********************************************/
			/***************RECIEVER INT ENABLE**********/
			if (OBJECT->Recieve_INT==RECIEVE_INT_ENABLE){
				SET_BIT(UCSRB,RXCIE);
			}else if (OBJECT->Recieve_INT==RECIEVE_INT_DISABLE){
				CLR_BIT(UCSRB,RXCIE);
			}
			/********************************************/
			/***************Transmit INT ENABLE**********/
			if (OBJECT->Transmit_INT==TRANSMIT_INT_ENABLE){
				SET_BIT(UCSRB,TXCIE);
			}else if (OBJECT->Transmit_INT==TRANSMIT_INT_DISABLE){
				CLR_BIT(UCSRB,TXCIE);
			}
			/********************************************/
		}
		else{
			CLR_BIT(UCSRB,RXEN);
		}
	}
	
	return s_ret_val;
}

void USART_Transmit(u16 data){
	/* Wait for empty transmit buffer */
		while(IS_BIT_CLR(UCSRA,UDRE));
	/**********************************/
	/***********if the data to be transmitted is 9 bits, write the MSB first*****************/
		if (OBJECT->Char_Size==USART_9_BIT_CHAR){
			UCSRB |= ((data>>8)&1);
		}
	/***************************************************************************************/
	/* Put data into buffer, sends the data */
		UDR = (u8)data;
	/****************************************/		
}

u8 USART_Receive(u16 *Ptr_To_Val){
	u8 local_ParityError =0 ;// 0 Means Error
	*Ptr_To_Val = 0x00;
	/* Wait for data to be received */
		while(IS_BIT_CLR(UCSRA,RXC));
	/*******************************/
	/****************Check if parity error is not ON********/
		if (READ_BIT(UCSRA,PE) !=1){
			/***********if the data to be recieved is 9 bits, get the MSB first*****************/
				if (OBJECT->Char_Size==USART_9_BIT_CHAR){
					*Ptr_To_Val = (READ_BIT(UCSRB,TXB8)<<8);
				}
			/***********************************************************************************/
			/* Get and return received data from buffer */
				*Ptr_To_Val |=UDR;
				local_ParityError=1;
		}
	return local_ParityError;
}