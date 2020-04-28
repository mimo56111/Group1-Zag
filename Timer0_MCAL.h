/*
 * Timer0_MCAL.h
 *
 *  Author: Mahmoud Ayman
 */ 


#ifndef TIMER0_MCAL_H_
#define TIMER0_MCAL_H_
#include "Data_type.h"
#include "stdmacros.h"
#include "Register.h"
#include <avr/interrupt.h>
/********** USER Configuration **********/
enum WAVE_FORM_GEN { 
	CTC,
	NORMAL,
	Fast_PWM,
	Phase_Correct_PWM,
	COM_Non_PWM
} ;

/*Timer/Counter0 Overflow  Interrupt Enable*/
enum TOVFIE0 {    
	TOIE0_enable,
	TOIE0_disable
} ;

/*Timer/Counter0 Output Compare Match Interrupt Enable*/
enum OCMIE0 {   
	OCIE0_enable ,
	OCIE0_disable
} ;

enum TMR0_PRESCALAR {
	NO_CLK_SRC = 0, //Timer Disable
	NO_PRESCALING = 1,
	PRESCALING_CLK8 = 2,
	PRESCALING_CLK64 = 3,
	PRESCALING_CLK256 = 4,
	PRESCALING_CLK1024 = 5,
	EXT_CLK_FALLING=6,
	EXT_CLK_RISING = 7
} ;

struct STimer0_Settings {
	enum TOVFIE0 Timer0_OVFI ;
	enum OCMIE0 Timer0_OCIE;
	enum WAVE_FORM_GEN Timer0_Mode ;
	enum TMR0_PRESCALAR Timer0_PRESCALAR;
};

/********** Timer0 Interface  **********/
	void TMR0_Init(struct STimer0_Settings Configuration);
	void TMR0_ReadCounterValue(u8* u8NumOfTicks);
	void TMR0_Set_Compare_Value(u8 u8Val);
	void TMR0_Set_OV_Number(u8 u8Val);
	void TMR0_Get_TOV_Number(u8 *u8Val);
	void TMR0_Fast_PWM_Gen(u8 duty_cycle);
	void TMR0_Phase_Correct_PWM_Gen(u8 duty_cycle);
	void TMR0_COM_Non_PWM_Gen(u8 duty_cycle);
	
/********** SW Counter  **********/
	void TMR0_Get_Ticks_of_SWcounter (u32 *u8Val);
	
	
/********** ISR  **********/
	void callback_TMR0_Overflow_Interrupt (void(*Ptr_to_OVI_Function)(void));
	void callback_OCR0_Compare_Match_Interrupt(void(*Ptr_to_OCM_Function)(void));
#endif /* TIMER0_MCAL_H_ */