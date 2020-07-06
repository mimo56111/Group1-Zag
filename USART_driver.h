/*
 * USART_driver.h
 *
 *  Author: Mahmoud Ayman
 */ 


#ifndef USART_DRIVER_H_
#define USART_DRIVER_H_
#include "Data_type.h"
#include "stdmacros.h"
#include "Register.h"           

/***********Synchronous Mode *****************/
#define SYNC_MODE                   0
#define ASYNC_MODE                  1
/***********************************************/
/*************Speed Mode*************************/
#define USART_NORMAL_MODE           0
#define USART_Double_SPEED_MODE     1
/************************************************/
/************TRANSMIT ***************************/
#define USART_TRANSMIT_ENABLE       0
#define USART_TRANSMIT_DISABLE      1
/************************************************/
/************RECIEVE***************************/
#define USART_RECIEVE_ENABLE        0
#define USART_RECIEVE_DISABLE       1
/************************************************/
/*************USART CHAR SIZE *******************/
#define USART_5_BIT_CHAR            0
#define USART_6_BIT_CHAR            1
#define USART_7_BIT_CHAR            2
#define USART_8_BIT_CHAR            3
#define USART_9_BIT_CHAR            4
/*********************************************/
/***********PARITY MODE***********************/
#define NO_PARITY                   0
#define EVEN_PARITY                 1
#define ODD_PARITY                  2
/*********************************************/
/**********STOP BIT***************************/
#define ONE_STOP_BIT                0
#define TWO_STOP_BIT                1
/*********************************************/
/***********Recieve Interrupt ***************/
#define RECIEVE_INT_ENABLE          0
#define RECIEVE_INT_DISABLE         1
/********************************************/
/***********Transmit Interrupt ***************/
#define TRANSMIT_INT_ENABLE         0
#define TRANSMIT_INT_DISABLE        1
/********************************************/

/****************usart_errors***************/
typedef enum{
	NO_USART_ERRORS,
	INVALID_PARAMS,
	DEVICE_NOT_INITIATED,
	DEVICE_ALREADY_DEINITIATED
}usart_ErrorTypes;
/************************************/
/*************Buffer*****************/
typedef struct {
	u8 SYNCH_MODE;
	u8 SPEED_MODE;
	u8 Transmit;
	u8 Recieve;
	u8 Char_Size;
	u8 Parity_Mode;
	u8 Stop_Bit ;
	u8 Transmit_INT;
	u8 Recieve_INT;
	void (*USART_Recieve_Complete_User_CBK) (void);
	void (*USART_Transmit_Complete_User_CBK) (void);
	u32 Baud_Rate;
	}USART_Config ;
/*************************************************/

usart_ErrorTypes USART_get_config (USART_Config *obj , u8 Synchronous , u8 Speed , u32 Baud_rate , u8 TX_Enable , u8 RX_Enable , u8 Size , u8 parity , u8 Stop_Bit );	
usart_ErrorTypes USART_get_INT_config (u8 TX_INT,u8 RX_INT, void (*TX_CB_func)(void) , void (*RX_CB_func)(void)); 	
usart_ErrorTypes USART_Init(void);

void USART_Transmit(u16 data);
u8 USART_Receive(u16 *Ptr_To_Val);
#endif /* USART_DRIVER_H_ */