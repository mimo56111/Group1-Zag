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

/*********************************************Timer0******************************************************/
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


/***********************************************Timer0*************************************/
struct TMR0_Config{
	u8 Mode;
	u8 TMR0_OVF_Interrupt ;
	u8 TMR0_CTC_Interrupt ;
	u8 Prescalar ;
}confiuration;	
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
		
/*********************************************************************************************************/
		
		
/*********************************************Timer2******************************************************/
/***********************Modes*********************/
#define TMR2_NORMAL_Mode         0
#define TMR2_CTC_Mode            1
#define TMR2_OCM_Non_PWM_Mode    2
#define TMR2_Fast_PWM_Mode       3
#define TMR2_Phase_Correct_PWM   4
/*************************************************/
/**********Timer2 Over flow Interrupt*************/
#define TOIE2_enable  0
#define TOIE2_disable 1
/*************************************************/
/**********Timer2 CTC Interrupt*******************/
#define OCIE2_enable   0
#define OCIE2_disable  1
/*************************************************/

/**********Timer2 Prescalar***********************/
#define TMR2_NO_CLK_SRC           0
#define TMR2_NO_PRESCALING        1
#define TMR2_PRESCALING_CLK8      2
#define TMR2_PRESCALING_CLK32     3
#define TMR2_PRESCALING_CLK64     4
#define TMR2_PRESCALING_CLK128    5
#define TMR2_PRESCALING_CLK256    6
#define TMR2_PRESCALING_CLK1024   7
/*************************************************/
struct TMR2_Config{
	u8 Mode;
	u8 TMR2_OVF_Interrupt ;
	u8 TMR2_CTC_Interrupt ;
	u8 Prescalar ;
}TMR2_Configuration;
	/*
	Function Name        : TMR2_Get_Configuration
	Function Returns     : void
	Function Arguments   : unsigned char Mode,unsigned char Over flow interrupt , unsigned char CTC interrupt,unsigned char Prescalar
	Function Description : Get configuration for Timer0 from user
	*/
		void TMR2_Get_Configuration(u8 waveform , u8 TMR2_OVFI , u8 TMR2_CTCI , u8 clk_Selcet);
	/*
	Function Name        : TMR2_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize Timer2 .
	*/
		void TMR2_vInit(void);
	/*
	Function Name        : TMR2_Set_Compare_Value
	Function Returns     : void
	Function Arguments   : unsigned char val
	Function Description : assign value in OCR2 .
	*/	
		void TMR2_Set_Compare_Value(u8 u8Val);
	/*
	Function Name        : TMR2_Read_count
	Function Returns     : unsigned char value of register
	Function Arguments   : void
	Function Description : Return TCNT2 value .
	*/
		u8 TMR2_Read_count(void);
	/*
	Function Name        : TMR2_Set_Counter_Value
	Function Returns     : void
	Function Arguments   : unsigned char val
	Function Description : assign value in TCNT2 .
	*/	
		void TMR2_Set_Counter_Value(u8 u8Val);
/*************************************** Wave Generation*************************************/
		
	/*
	Function Name        : TMR2_COM_Non_PWM_Gen
	Function Returns     : void
	Function Arguments   : unsigned  duty_cycle
	Function Description : Generate wave form with duty cycle user entered .
	*/
		void TMR2_COM_Non_PWM_Gen(u8 duty_cycle);
	/*	
	Function Name        : TMR0_Fast_PWM_Gen
	Function Returns     : void
	Function Arguments   : unsigned  duty_cycle
	Function Description : Generate wave form with duty cycle user entered .
	*/
		void TMR2_Fast_PWM_Gen(u8 duty_cycle);
	/*	
	Function Name        : TMR0_Phase_Correct_PWM_Gen
	Function Returns     : void
	Function Arguments   : unsigned  duty_cycle
	Function Description : Generate wave form with duty cycle user entered .
	*/
		void TMR2_Phase_Correct_PWM_Gen(u8 duty_cycle);
/********************************************************************************************/
/********************************************************************************************/

	/*
	Function Name        : callback_TMR2_Overflow_Interrupt
	Function Returns     : void
	Function Arguments   : Address of of Function 
	Function Description : Execute a function in Higher layer in ISR .
	*/	
		void callback_TMR2_Overflow_Interrupt (void(*Ptr_to_OVI_Function)(void));
		
	/*
	Function Name        : callback_OCR2_Compare_Match_Interrupt
	Function Returns     : void
	Function Arguments   : Address of of Function 
	Function Description : Execute a function in Higher layer in ISR .
	*/
		void callback_OCR2_Compare_Match_Interrupt(void(*Ptr_to_OCM_Function)(void));
		
/*********************************************************************************************************/
/*********************************************Timer2******************************************************/
/***********************Modes*********************/
#define TMR1_Normal_Mode     0
#define TMR1_PWM_PC_8bit     1
#define TMR1_PWM_PC_9bit     2
#define TMR1_PWM_PC_10bit    3
#define TMR1_CTC_OCR1A_Mode  4
#define TMR1_Fast_PWM_8bit	 5
#define TMR1_Fast_PWM_9bit	 6
#define TMR1_Fast_PWM_10bit	 7	
#define TMR1_PWM_PFC_ICR1    8
#define TMR1_PWM_PFC_OCR1A   9
#define TMR1_PWM_PC_ICR1     10
#define TMR1_PWM_PC_OCR1A    11
#define TMR1_CTC_ICR1_Mode   12
#define TMR1_Fast_PWM_ICR1	 13
#define TMR1_Fast_PWM_OCR1A	 14
/**********Timer1 Prescalar***********************/
#define TMR1_NO_CLK_SRC           0
#define TMR1_NO_PRESCALING        1
#define TMR1_PRESCALING_CLK8      2
#define TMR1_PRESCALING_CLK64     3
#define TMR1_PRESCALING_CLK256    4
#define TMR1_PRESCALING_CLK1024   5
#define TMR1_EXT_CLK_FALLING      6
#define TMR1_EXT_CLK_RISING       7
/*************************************************/
/**********Timer1 Over flow Interrupt*************/
#define TOIE1_enable  0
#define TOIE1_disable 1
/*************************************************/
/**********Timer1 CTC Interrupt*******************/
#define OCIE1A_enable   0
#define OCIE1A_disable  1
#define OCIE1B_enable   2
#define OCIE1B_disable  3
/*************************************************/
/**********Timer1 Input Capture Interrupt*******************/
#define TICIE1_enable   0
#define TICIE1_disable  1
/***********************************************************/

struct TMR1_Config{
	u8 Mode;
	u8 TMR1_OVF_Interrupt ;
	u8 TMR1_OCIE1A_Interrupt ;
	u8 TMR1_OCIE1B_Interrupt ;
	u8 TMR1_TICIE1_Interrupt ;
	u8 Prescalar ;
}TMR1_Configuration;

/*
	Function Name        : TMR1_Get_Configuration
	Function Returns     : void
	Function Arguments   : unsigned char Mode,unsigned char Over flow interrupt , unsigned char OCIE1A interrupt , unsigned char OCIE1B interrupt , unsigned char TICIE1 interrupt ,unsigned char Prescalar
	Function Description : Get configuration for Timer0 from user
	*/
		void TMR1_Get_Configuration(u8 waveform , u8 TMR1_OVFI , u8 TMR1_OCIE1A , u8 TMR1_OCIE1B, u8 TMR1_TICIE1 , u8 clk_Selcet);
	/*
	Function Name        : TMR1_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize Timer1 .
	*/
		void TMR1_vInit(void);
		
	/*
	Function Name        : TMR1_Set_Compare_Value
	Function Returns     : void
	Function Arguments   : unsigned short val
	Function Description : assign value in OCR1A .
	*/	
		void TMR1_Set_Compare_Value(u16 u8Val);
		
	/*
	Function Name        : TMR1_Read_count
	Function Returns     : unsigned short value of register
	Function Arguments   : void
	Function Description : Return TCNT1 value .
	*/
		u16 TMR1_Read_count(void);
		
		
		void TMR1_Set_Input_capture_reg(u16 val);
		
		void TMR1_Fast_PWM_Gen(f64 val);
/*********************************************************************************************************/
	
#endif /* TIMER_DRIVER_MCAL_H_ */