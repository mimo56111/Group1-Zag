/*
 * Motor_ECU.h
 *
 *  Author: Mahmoud Ayman
 */ 


#ifndef MOTOR_ECU_H_
#define MOTOR_ECU_H_
#include "Timer_driver_MCAL.h"
#include "GPIO_MCAL.h"
#include "Data_type.h"
#define DC_Motor       0
#define Servo_Motor    1
#define Stepper_Motor  2

struct motor {
	u8 M_Type ;
	u8 M_Port;
	u8 IN1;
	u8 IN2;
	}Motor_config;


	void Motor_get_config(u8 Motor_Type , u8 Motor_Port , u8 Pin1 , u8 Pin2);
	
	void DC_Motor_without_PWM_Init(void);
	
	void DC_Motor_without_PWM_Move_Forward(void);
	
	void DC_Motor_without_PWM_Move_Backward(void);
	
	void DC_Motor_with_PWM_Init();
	void DC_Motor_with_PWM_Move(u8 power);
	void Servo_Motor_move(s8 degree);
	
#endif /* MOTOR_ECU_H_ */