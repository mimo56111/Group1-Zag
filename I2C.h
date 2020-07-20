/*
 * I2C.h
 *  Author: Mahmoud Ayman
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "Data_type.h"
#include "stdmacros.h"
#include "Register.h"

void I2C_Master_init(u32 SCL_Clock);
void I2C_start(void);
void I2C_write_address(u8 address);
void I2C_write_data(u8 data);
void I2C_stop(void);
void I2C_set_address(u8 address);
u8 I2C_slave_read(void);



#endif /* I2C_H_ */