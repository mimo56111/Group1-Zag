/*
 * Timer_driver_MCAL.c
 *
 *  Author: Mahmoud Ayman
 */ 

#include "Timer_driver_MCAL.h"
#include "Data_type.h"
static void (*Ptr_To_OVFI)(void);
static void (*Ptr_To_OCMI)(void);
void TMR0_Get_Configuration(u8 waveform , u8 TMR0_OVFI , u8 TMR0_CTCI , u8 clk_Selcet){
	confiuration.Mode = waveform ;
	confiuration.Prescalar = clk_Selcet;
	confiuration.TMR0_OVF_Interrupt = TMR0_OVFI;
	confiuration.TMR0_CTC_Interrupt = TMR0_CTCI;
}

void TMR0_vInit(void){
	/*********************Adjust Mode*****************************/
		if (confiuration.Mode==NORMAL_Mode){
			CLR_BIT(myTCCR0,myWGM00);
			CLR_BIT(myTCCR0,myWGM01);
		}else if (confiuration.Mode==CTC_Mode){
			CLR_BIT(myTCCR0,myWGM00);
			SET_BIT(myTCCR0,myWGM01);
		}else if (confiuration.Mode==OCM_Non_PWM_Mode){
			CLR_BIT(myTCCR0,myWGM00);
			SET_BIT(myTCCR0,myWGM01);
		}else if (confiuration.Mode==Fast_PWM_Mode){
			SET_BIT(myTCCR0,myWGM00);
			SET_BIT(myTCCR0,myWGM01);
		}else if (confiuration.Mode==Phase_Correct_PWM){
			SET_BIT(myTCCR0,myWGM00);
			CLR_BIT(myTCCR0,myWGM01);
		}
	/****************************************************************/	
	/************************Adjust prescalar************************/
		myTCCR0 |= confiuration.Prescalar;    
	/****************************************************************/
	/*************Over flow Interrupt Enable/Disable*****************/
		if (confiuration.TMR0_OVF_Interrupt==TOIE0_enable){
			SET_BIT(myTIMSK,myTOIE0);
		}else if (confiuration.TMR0_OVF_Interrupt==TOIE0_disable){
			CLR_BIT(myTIMSK,myTOIE0);
		}
	/****************************************************************/
	/******************OCR0 Interrupt Enable/Disable*****************/
		if (confiuration.TMR0_CTC_Interrupt==OCIE0_enable){
			SET_BIT(myTIMSK,myOCIE0);
		}else if (confiuration.TMR0_CTC_Interrupt==OCIE0_disable){
			CLR_BIT(myTIMSK,myOCIE0);
		}
	/****************************************************************/
}

void TMR0_Set_Compare_Value(u8 u8Val){
	myOCR0 = u8Val;
}
void TMR0_Set_Counter_Value(u8 u8Val){
	myTCNT0 = u8Val;
}

u8 TMR0_Read_count(void){
	return myTCNT0;
}

/*************************************** Wave Generation*************************************/
/*Compare Output Mode , Non PWM mode */
void TMR0_COM_Non_PWM_Gen(u8 duty_cycle){
	u8 val;
	SET_BIT(myDDRB,3);
	val=(duty_cycle * 256) / 100;
	TMR0_Set_Compare_Value(val);
	SET_BIT(myTCCR0,myCOM00);
	CLR_BIT(myTCCR0,myCOM01);
}

/*Fast PWM mode */
void TMR0_Fast_PWM_Gen(u8 duty_cycle){
	u8 val;
	SET_BIT(myDDRB,3);
	val=(duty_cycle * 256) / 100;
	TMR0_Set_Compare_Value(val);
	SET_BIT(myTCCR0,myCOM00);
	SET_BIT(myTCCR0,myCOM01);
}
/*Phase Correct PWM mode */
void TMR0_Phase_Correct_PWM_Gen(u8 duty_cycle){
	u8 val;
	SET_BIT(myDDRB,3);
	val=(duty_cycle * 256) / 100;
	TMR0_Set_Compare_Value(val);
	SET_BIT(myTCCR0,myCOM00);
	SET_BIT(myTCCR0,myCOM01);
}
/********************************************************************************************/



void callback_TMR0_Overflow_Interrupt (void(*Ptr_to_OVI_Function)(void)){
	Ptr_To_OVFI = Ptr_to_OVI_Function ;
}

void callback_OCR0_Compare_Match_Interrupt(void(*Ptr_to_OCM_Function)(void)){
	Ptr_To_OCMI = Ptr_to_OCM_Function ;
}



ISR(TIMER0_COMP_vect){
	(*Ptr_To_OCMI)();
}


ISR(TIMER0_OVF_vect){
	(*Ptr_To_OVFI)();
}