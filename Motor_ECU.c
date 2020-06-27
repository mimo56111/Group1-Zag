/*
 * Motor_ECU.c
 *
 *  Author: Mahmoud Ayman
 */ 
#include "Motor_ECU.h"
void Motor_get_config(u8 Motor_Type , u8 Motor_Port , u8 Pin1 , u8 Pin2){
	Motor_config.M_Type = Motor_Type ;
	Motor_config.M_Port = Motor_Port ;
	Motor_config.IN1    = Pin1;
	Motor_config.IN2    = Pin2;
}

void DC_Motor_without_PWM_Init(void){
	if (Motor_config.M_Type == DC_Motor){
		GPIO_vsetPIN_DIR(Motor_config.M_Port , Motor_config.IN1 , 1);
		GPIO_vsetPIN_DIR(Motor_config.M_Port , Motor_config.IN2 , 1);
	}else {
		
	}
}

void DC_Motor_without_PWM_Move_Forward(void){
	if (Motor_config.M_Type == DC_Motor){
		GPIO_vwrite_PIN(Motor_config.M_Port , Motor_config.IN1 , 1);
		GPIO_vwrite_PIN(Motor_config.M_Port , Motor_config.IN2 , 0);
	}else {
		
	}
}

void DC_Motor_without_PWM_Move_Backward(void){
	if (Motor_config.M_Type == DC_Motor){
		GPIO_vwrite_PIN(Motor_config.M_Port , Motor_config.IN1 , 0);
		GPIO_vwrite_PIN(Motor_config.M_Port , Motor_config.IN2 , 1);
	}else {
		
	}
}

void DC_Motor_with_PWM_Init(){
	if (Motor_config.M_Type == DC_Motor){
		TMR0_Get_Configuration(Fast_PWM_Mode,TOIE0_disable,OCIE0_disable,NO_PRESCALING);
		GPIO_vsetPIN_DIR('B',3,1);
		GPIO_vsetPIN_DIR(Motor_config.M_Port , Motor_config.IN2 , 1);
	}else {
		
	}
}

void DC_Motor_with_PWM_Move(u8 power){
	if (Motor_config.M_Type == DC_Motor){
		TMR0_Fast_PWM_Gen(power);
		GPIO_vwrite_PIN(Motor_config.M_Port , Motor_config.IN2 , 0);
	}else {
		
	}
}

void Servo_Motor_move(s8 degree){
	f64 Time;
	
	Time = (degree*0.5)/90;
	
	Time = Time + 1.5 ;
	
	
	TMR1_Fast_PWM_Gen(Time);
}