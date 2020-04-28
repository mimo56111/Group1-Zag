/*
 * Timer0_MCAL.c
 *
 *  Author: Mahmoud Ayman
 */ 
#include "Timer0_MCAL.h"

struct STimer0_Settings Timer0_Configuration;
u8 TOV_Number ;

static void (*Ptr_To_OVFI)(void);
static void (*Ptr_To_OCMI)(void);

void TMR0_Init(struct STimer0_Settings Configuration){
	Timer0_Configuration = Configuration ;
	/*********************Adjust Mode***********************/
	if (Timer0_Configuration.Timer0_Mode == NORMAL ){
		CLR_BIT(myTCCR0,myWGM00);
		CLR_BIT(myTCCR0,myWGM01);
	}	
	
	if (Timer0_Configuration.Timer0_Mode == CTC ){
		CLR_BIT(myTCCR0,myWGM00);
		SET_BIT(myTCCR0,myWGM01);
	}	
	
	if (Timer0_Configuration.Timer0_Mode == COM_Non_PWM ){
		CLR_BIT(myTCCR0,myWGM00);
		SET_BIT(myTCCR0,myWGM01);
	}
	if (Timer0_Configuration.Timer0_Mode == Fast_PWM ){
		SET_BIT(myTCCR0,myWGM00);
		SET_BIT(myTCCR0,myWGM01);
	}
	if (Timer0_Configuration.Timer0_Mode == Phase_Correct_PWM ){
		SET_BIT(myTCCR0,myWGM00);
		CLR_BIT(myTCCR0,myWGM01);
	}
	
	/************************Adjust prescalar************************/
	myTCCR0 = myTCCR0 | Timer0_Configuration.Timer0_PRESCALAR;	
	/**************************Timer0 Interrupt Enable/Disable********************/
	if (Timer0_Configuration.Timer0_OVFI == TOIE0_enable ){
		SET_BIT(myTIMSK,myTOIE0);
	}else if (Timer0_Configuration.Timer0_OVFI == TOIE0_disable){
		CLR_BIT(myTIMSK,myTOIE0);
	}
	/**************************OCR0 Interrupt Enable/Disable********************/
	if (Timer0_Configuration.Timer0_OCIE == OCIE0_enable ){
		SET_BIT(myTIMSK,myOCIE0);
	}else if (Timer0_Configuration.Timer0_OCIE == OCIE0_disable){
		CLR_BIT(myTIMSK,myOCIE0);
	}
}

void TMR0_ReadCounterValue(u8 *u8NumOfTicks){
	*u8NumOfTicks = myTCNT0;
}

void TMR0_Set_Compare_Value(u8 u8Val){
	myOCR0 = u8Val;
}
void TMR0_Set_Counter_Value(u8 u8Val){
	myTCNT0 = u8Val;
}

/*************************************** Wave Generation*************************************/
/*Compare Output Mode , Non PWM mode */
void TMR0_COM_Non_PWM_Gen(u8 duty_cycle){
	SET_BIT(myDDRB,3);
	myOCR0=(duty_cycle * 256) / 100;
	SET_BIT(myTCCR0,myCOM00);
	CLR_BIT(myTCCR0,myCOM01);
}

/*Fast PWM mode */
void TMR0_Fast_PWM_Gen(u8 duty_cycle){
	SET_BIT(myDDRB,3);
	myOCR0=(duty_cycle * 256) / 100;
	SET_BIT(myTCCR0,myCOM00);
	SET_BIT(myTCCR0,myCOM01);
}
/*Phase Correct PWM mode */
void TMR0_Phase_Correct_PWM_Gen(u8 duty_cycle){
	SET_BIT(myDDRB,3);
	myOCR0=(duty_cycle * 256) / 100;
	SET_BIT(myTCCR0,myCOM00);
	SET_BIT(myTCCR0,myCOM01);
}
/********************************************************************************************/
/***used for set the Number of OverFlow (Used for SW Counters)***/

void TMR0_Set_TOV_Number(u8 u8Val){
	TOV_Number = u8Val;
}

void TMR0_Get_TOV_Number(u8 *u8Val){
	*u8Val = TOV_Number ;
}



void TMR0_Get_Ticks_of_SWcounter (u32 *u8Val){
	*u8Val =  256*TOV_Number + myTCNT0;
}

void callback_TMR0_Overflow_Interrupt (void(*Ptr_to_OVI_Function)(void)){
	Ptr_To_OVFI = Ptr_to_OVI_Function ;
}

void callback_OCR0_Compare_Match_Interrupt(void(*Ptr_to_OCM_Function)(void)){
	Ptr_To_OCMI = Ptr_to_OCM_Function ;
}

ISR(__vector_10){
	(*Ptr_To_OCMI)();
}

ISR(__vector_11){
	TOV_Number++;
	(*Ptr_To_OVFI)();
}