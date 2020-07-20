/*
 * I2C_MCAL.h
 *
 * Created: 7/20/2020 1:18:11 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef I2C_MCAL_H_
#define I2C_MCAL_H_
#include "Data_type.h"
#include "Register.h"
#include "stdmacros.h"

//=============Status values===================
#define TW_START       0x08 // start has been sent
#define TW_REP_START   0x10 // repeated start has been sent
#define TW_MT_SLA_WACK 0x18 //(slave address + write has been sent) + Ack received from slave
#define TW_MT_SLA_R_ACK 0x40 //(slave address + read has been sent) + Ack received from slave
#define TW_MT_DATA_ACK 0x28 // Data byte has been transmitted and ACK has been received from slave 
#define TW_MR_DATA_ACK 0x50 //Master received data and send ACK
#define TW_MR_DATA_NACK 0x58 // Master received data but don't send ACK

typedef void(*Call_backTX_t)(void);
typedef void(*Call_backRX_t)(u8);


typedef enum{
	I2C_RX,
	I2C_TX
	}I2C_Status_t;
	
void I2C_Init(I2C_Status_t i2c_passStatus);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(u8 data);
void I2C_TXwithInterrupt(u8 data);
u8 I2C_ReadwithACK(void);
u8 I2C_ReadwithACK_Interrupt(void);
void I2C_AssignCallBack_RX(Call_backRX_t pass_callback);
u8 I2C_ReadwithNACK(void);
u8 I2C_GetStatus(void);
void I2C_AssignCallBack_TX(Call_backTX_t pass_callback_fun);
void I2C_Disable_Interrupt(void);


#endif /* I2C_MCAL_H_ */