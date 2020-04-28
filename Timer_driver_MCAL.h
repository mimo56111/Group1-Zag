/*
 * Timer_driver_MCAL.h
 *
 *  Author: Mahmoud Ayman
 */ 


#ifndef TIMER_DRIVER_MCAL_H_
#define TIMER_DRIVER_MCAL_H_
#include "Register.h"
#include "Data_type.h"
#include "stdmacros.h"
#include <avr/interrupt.h>
/***********************Modes*********************/
#define NORMAL_Mode       0
#define CTC_Mode          1
#define OCM_Non_PWM_Mode  2
#define Fast_PWM_Mode     3
#define Phase_Correct_PWM 4
/*************************************************/
/**********Timer0 Over flow Interrupt*************/
#define TOIE0_enable  0
#define TOIE0_disable 1
/*************************************************/
/**********Timer0 CTC Interrupt*******************/
#define OCIE0_enable   0
#define OCIE0_disable  1
/*************************************************/

/**********Timer0 Prescalar***********************/
#define NO_CLK_SRC           0
#define NO_PRESCALING        1
#define PRESCALING_CLK8      2
#define PRESCALING_CLK64     3
#define PRESCALING_CLK256    4
#define PRESCALING_CLK1024   5
#define EXT_CLK_FALLING      6  
#define EXT_CLK_RISING       7
/*************************************************/
u8 Mode;
u8 TMR0_OVF_Interrupt ;
u8 TMR0_CTC_Interrupt ;
u8 Prescalar ;

struct TMR0_Config{
	u8 Mode;
	u8 TMR0_OVF_Interrupt ;
	u8 TMR0_CTC_Interrupt ;
	u8 Prescalar ;
	}confiuration;
/***********************************************Timer0*************************************/	
	/*
	Function Name        : TMR0_Get_Configuration
	Function Returns     : void
	Function Arguments   : unsigned char Mode,unsigned char Over flow interrupt , unsigned char CTC interrupt,unsigned char Prescalar
	Function Description : Get configuration for Timer0 from user
	*/
		void TMR0_Get_Configuration(u8 waveform , u8 TMR0_OVFI , u8 TMR0_CTCI , u8 clk_Selcet);
		
	/*
	Function Name        : TMR0_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize Timer0 .
	*/
		void TMR0_vInit(void);
	/*
	Function Name        : TMR0_Set_Compare_Value
	Function Returns     : void
	Function Arguments   : unsigned char val
	Function Description : assign value in OCR0 .
	*/	
		
		void TMR0_Set_Compare_Value(u8 u8Val);
	/*
	Function Name        : TMR0_Read_count
	Function Returns     : unsigned char value of register
	Function Arguments   : void
	Function Description : Return TCNT0 value .
	*/
		u8 TMR0_Read_count(void);
	/*
	Function Name        : TMR0_Set_Counter_Value
	Function Returns     : void
	Function Arguments   : unsigned char val
	Function Description : assign value in TCNT0 .
	*/	
		
		void TMR0_Set_Counter_Value(u8 u8Val);
/*************************************** Wave Generation*************************************/
		
	/*
	Function Name        : TMR0_COM_Non_PWM_Gen
	Function Returns     : void
	Function Arguments   : unsigned  duty_cycle
	Function Description : Generate wave form with duty cycle user entered .
	*/
		void TMR0_COM_Non_PWM_Gen(u8 duty_cycle);
	/*	
	Function Name        : TMR0_Fast_PWM_Gen
	Function Returns     : void
	Function Arguments   : unsigned  duty_cycle
	Function Description : Generate wave form with duty cycle user entered .
	*/
		void TMR0_Fast_PWM_Gen(u8 duty_cycle);
	/*	
	Function Name        : TMR0_Phase_Correct_PWM_Gen
	Function Returns     : void
	Function Arguments   : unsigned  duty_cycle
	Function Description : Generate wave form with duty cycle user entered .
	*/
		void TMR0_Phase_Correct_PWM_Gen(u8 duty_cycle);
/********************************************************************************************/

	/*
	Function Name        : callback_TMR0_Overflow_Interrupt
	Function Returns     : void
	Function Arguments   : Address of of Function 
	Function Description : Execute a function in Higher layer in ISR .
	*/	
		void callback_TMR0_Overflow_Interrupt (void(*Ptr_to_OVI_Function)(void));
		
	/*
	Function Name        : callback_OCR0_Compare_Match_Interrupt
	Function Returns     : void
	Function Arguments   : Address of of Function 
	Function Description : Execute a function in Higher layer in ISR .
	*/
		void callback_OCR0_Compare_Match_Interrupt(void(*Ptr_to_OCM_Function)(void));
	
#endif /* TIMER_DRIVER_MCAL_H_ */