/*
 * I2C.h
 *
 * Created: 11/28/2019 6:09:04 AM

 */ 


#ifndef I2C_H_
#define I2C_H_
void I2C_Master_init(unsigned long SCL_Clock);
void I2C_start(void);
void I2C_write_address(unsigned char address);
void I2C_write_data(unsigned char data);
void I2C_stop(void);
void I2C_set_address(unsigned char address);
unsigned char I2C_slave_read(void);
#endif /* I2C_H_ */