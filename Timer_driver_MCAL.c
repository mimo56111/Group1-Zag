/*
 * Timer_driver_MCAL.c
 *
 *  Author: Mahmoud Ayman
 */ 

#include "Timer_driver_MCAL.h"
#include "Data_type.h"
#define F_CPU 8000000UL
/*************************************** Timer0 **********************************************/
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
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	u8 val;
	SET_BIT(myDDRB,3);
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	val=(duty_cycle * 256) / 100;
	OCR0 = val;
	CLR_BIT(myTCCR0,myCOM00);
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

/*********************************************************************************************/

/*************************************** Timer2 **********************************************/
static void (*Ptr_To_OVFI2)(void);
static void (*Ptr_To_OCMI2)(void);

void TMR2_Get_Configuration(u8 waveform , u8 TMR2_OVFI , u8 TMR2_CTCI , u8 clk_Selcet){
	TMR2_Configuration.Mode = waveform ;
	TMR2_Configuration.Prescalar = clk_Selcet;
	TMR2_Configuration.TMR2_OVF_Interrupt = TMR2_OVFI;
	TMR2_Configuration.TMR2_CTC_Interrupt = TMR2_CTCI;
}

void TMR2_vInit(void){
	/*********************Adjust Mode*****************************/
	if (TMR2_Configuration.Mode==TMR2_NORMAL_Mode){
		CLR_BIT(myTCCR2,myWGM20);
		CLR_BIT(myTCCR2,myWGM21);
	}else if (TMR2_Configuration.Mode==TMR2_CTC_Mode){
		CLR_BIT(myTCCR2,myWGM20);
		SET_BIT(myTCCR2,myWGM21);
	}else if (TMR2_Configuration.Mode==TMR2_OCM_Non_PWM_Mode){
		CLR_BIT(myTCCR2,myWGM20);
		SET_BIT(myTCCR2,myWGM21);
	}else if (TMR2_Configuration.Mode==TMR2_Fast_PWM_Mode){
		SET_BIT(myTCCR2,myWGM20);
		SET_BIT(myTCCR2,myWGM21);
	}else if (TMR2_Configuration.Mode==TMR2_Phase_Correct_PWM){
		SET_BIT(myTCCR2,myWGM20);
		CLR_BIT(myTCCR2,myWGM21);
	}
	/****************************************************************/
	/************************Adjust prescalar************************/
	myTCCR2 |= TMR2_Configuration.Prescalar;
	/****************************************************************/
	/*************Over flow Interrupt Enable/Disable*****************/
	if (TMR2_Configuration.TMR2_OVF_Interrupt==TOIE2_enable){
		SET_BIT(myTIMSK,myTOIE2);
	}else if (TMR2_Configuration.TMR2_OVF_Interrupt==TOIE2_disable){
		CLR_BIT(myTIMSK,myTOIE2);
	}
	/****************************************************************/
	/******************OCR0 Interrupt Enable/Disable*****************/
	if (TMR2_Configuration.TMR2_CTC_Interrupt==OCIE2_enable){
		SET_BIT(myTIMSK,myOCIE2);
	}else if (TMR2_Configuration.TMR2_CTC_Interrupt==OCIE2_disable){
		CLR_BIT(myTIMSK,myOCIE2);
	}
	/****************************************************************/
}

void TMR2_Set_Compare_Value(u8 u8Val){
	myOCR2 = u8Val;
}

u8 TMR2_Read_count(void){
	return myTCNT2;
}

void TMR2_Set_Counter_Value(u8 u8Val){
	myTCNT2 = u8Val;
}


/*************************************** Wave Generation*************************************/
/*Compare Output Mode , Non PWM mode */
void TMR2_COM_Non_PWM_Gen(u8 duty_cycle){
	u8 val;
	SET_BIT(myDDRD,7);
	val=(duty_cycle * 256) / 100;
	TMR2_Set_Compare_Value(val);
	SET_BIT(myTCCR2,myCOM20);
	CLR_BIT(myTCCR2,myCOM21);
}

/*Fast PWM mode */
void TMR2_Fast_PWM_Gen(u8 duty_cycle){
	u8 val;
	SET_BIT(myDDRD,7);
	val=(duty_cycle * 256) / 100;
	TMR2_Set_Compare_Value(val);
	SET_BIT(myTCCR2,myCOM20);
	SET_BIT(myTCCR2,myCOM21);
}
/*Phase Correct PWM mode */
void TMR2_Phase_Correct_PWM_Gen(u8 duty_cycle){
	u8 val;
	SET_BIT(myDDRD,7);
	val=(duty_cycle * 256) / 100;
	TMR2_Set_Compare_Value(val);
	SET_BIT(myTCCR2,myCOM20);
	SET_BIT(myTCCR2,myCOM21);
}
/********************************************************************************************/



void callback_TMR2_Overflow_Interrupt(void(*Ptr_to_OVI_Function)(void)){
	Ptr_To_OVFI2 = Ptr_to_OVI_Function ;
}

void callback_OCR2_Compare_Match_Interrupt(void(*Ptr_to_OCM_Function)(void)){
	Ptr_To_OCMI2 = Ptr_to_OCM_Function ;
}



ISR(TIMER2_COMP_vect){
	(*Ptr_To_OCMI2)();
}


/*ISR(TIMER2_OVF_vect){
	(*Ptr_To_OVFI2)();
}*/
/*********************************************************************************************/



/*************************************** Timer1 **********************************************/
	void TMR1_Get_Configuration(u8 waveform , u8 TMR1_OVFI , u8 TMR1_OCIE1A , u8 TMR1_OCIE1B, u8 TMR1_TICIE1 , u8 clk_Selcet){
		TMR1_Configuration.Mode = waveform;
		TMR1_Configuration.TMR1_OVF_Interrupt = TMR1_OVFI;
		TMR1_Configuration.TMR1_OCIE1A_Interrupt = TMR1_OCIE1A;
		TMR1_Configuration.TMR1_OCIE1B_Interrupt = TMR1_OCIE1B;
		TMR1_Configuration.TMR1_TICIE1_Interrupt = TMR1_TICIE1;
		TMR1_Configuration.Prescalar = clk_Selcet ;	
	}
	
	void TMR1_vInit(void){
		/*********************Adjust Mode*****************************/
			if (TMR1_Configuration.Mode == TMR1_Normal_Mode){
				CLR_BIT(myTCCR1A,myWGM10);
				CLR_BIT(myTCCR1A,myWGM11);
				CLR_BIT(myTCCR1B,myWGM12);
				CLR_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_PWM_PC_8bit){
				SET_BIT(myTCCR1A,myWGM10);
				CLR_BIT(myTCCR1A,myWGM11);
				CLR_BIT(myTCCR1B,myWGM12);
				CLR_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_PWM_PC_9bit){
				CLR_BIT(myTCCR1A,myWGM10);
				SET_BIT(myTCCR1A,myWGM11);
				CLR_BIT(myTCCR1B,myWGM12);
				CLR_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_PWM_PC_10bit){
				SET_BIT(myTCCR1A,myWGM10);
				SET_BIT(myTCCR1A,myWGM11);
				CLR_BIT(myTCCR1B,myWGM12);
				CLR_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_CTC_OCR1A_Mode){
				CLR_BIT(myTCCR1A,myWGM10);
				CLR_BIT(myTCCR1A,myWGM11);
				SET_BIT(myTCCR1B,myWGM12);
				CLR_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_Fast_PWM_8bit){
				SET_BIT(myTCCR1A,myWGM10);
				CLR_BIT(myTCCR1A,myWGM11);
				SET_BIT(myTCCR1B,myWGM12);
				CLR_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_Fast_PWM_9bit){
				CLR_BIT(myTCCR1A,myWGM10);
				SET_BIT(myTCCR1A,myWGM11);
				SET_BIT(myTCCR1B,myWGM12);
				CLR_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_Fast_PWM_10bit){
				SET_BIT(myTCCR1A,myWGM10);
				SET_BIT(myTCCR1A,myWGM11);
				SET_BIT(myTCCR1B,myWGM12);
				CLR_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_PWM_PFC_ICR1){
				CLR_BIT(myTCCR1A,myWGM10);
				CLR_BIT(myTCCR1A,myWGM11);
				CLR_BIT(myTCCR1B,myWGM12);
				SET_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_PWM_PFC_OCR1A){
				SET_BIT(myTCCR1A,myWGM10);
				CLR_BIT(myTCCR1A,myWGM11);
				CLR_BIT(myTCCR1B,myWGM12);
				SET_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_PWM_PC_ICR1){
				CLR_BIT(myTCCR1A,myWGM10);
				SET_BIT(myTCCR1A,myWGM11);
				CLR_BIT(myTCCR1B,myWGM12);
				SET_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_PWM_PC_OCR1A){
				SET_BIT(myTCCR1A,myWGM10);
				SET_BIT(myTCCR1A,myWGM11);
				CLR_BIT(myTCCR1B,myWGM12);
				SET_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_CTC_ICR1_Mode){
				CLR_BIT(myTCCR1A,myWGM10);
				CLR_BIT(myTCCR1A,myWGM11);
				SET_BIT(myTCCR1B,myWGM12);
				SET_BIT(myTCCR1B,myWGM13);
			}else if (TMR1_Configuration.Mode == TMR1_Fast_PWM_ICR1){	
				CLR_BIT(myTCCR1A,myWGM10);
				SET_BIT(myTCCR1A,myWGM11);
				SET_BIT(myTCCR1B,myWGM12);
				SET_BIT(myTCCR1B,myWGM13);					
			}else if (TMR1_Configuration.Mode == TMR1_Fast_PWM_OCR1A){
				SET_BIT(myTCCR1A,myWGM10);
				SET_BIT(myTCCR1A,myWGM11);
				SET_BIT(myTCCR1B,myWGM12);
				SET_BIT(myTCCR1B,myWGM13);
			}
			
		/****************************************************************/
		/************************Adjust prescalar************************/
			myTCCR1B |= TMR1_Configuration.Prescalar;
		/****************************************************************/
		/*************Over flow Interrupt Enable/Disable*****************/
			if (TMR1_Configuration.TMR1_OVF_Interrupt==TOIE1_enable){
				SET_BIT(myTIMSK,myTOIE1);
			}else if (TMR1_Configuration.TMR1_OVF_Interrupt==TOIE1_disable){
				CLR_BIT(myTIMSK,myTOIE1);
			}
		/****************************************************************/
		/******************OCR1 Interrupt Enable/Disable*****************/
			if (TMR1_Configuration.TMR1_OCIE1A_Interrupt==OCIE1A_enable){
				SET_BIT(myTIMSK,myOCIE1A);
			}else if (TMR1_Configuration.TMR1_OCIE1A_Interrupt==OCIE1A_disable){
				CLR_BIT(myTIMSK,myOCIE1A);
			}
			if (TMR1_Configuration.TMR1_OCIE1B_Interrupt==OCIE1B_enable){
				SET_BIT(myTIMSK,myOCIE1B);
			}else if (TMR1_Configuration.TMR1_OCIE1B_Interrupt==OCIE1B_disable){
				CLR_BIT(myTIMSK,myOCIE1B);
			}
		/****************************************************************/
		/******************ICF1 Interrupt Enable/Disable*****************/
			if (TMR1_Configuration.TMR1_TICIE1_Interrupt==TICIE1_enable){
				SET_BIT(myTIMSK,myTICIE1);
			}else if (TMR1_Configuration.TMR1_TICIE1_Interrupt==TICIE1_disable){
				CLR_BIT(myTIMSK,myTICIE1);
			}
		/****************************************************************/							
	}
	
	
	void TMR1_Set_Compare_Value(u16 u8Val){
		myOCR1AL = (u8)u8Val;
		myOCR1AH |=(u8Val<<8);
	}
	
	u16 TMR1_Read_count(void){
		u8 temp1 , temp2 ;
		u16 Result;
		temp1 = myTCNT1L;
		temp2 = myTCNT1H;
		Result = temp1 | (temp2<<8);
		return Result;
	}
	
	void TMR1_Set_Input_capture_reg(u16 val){
		ICR1 = val;
	}
	void TMR1_Fast_PWM_Gen(f64 val){
		/* set OC1A as output pin */
		SET_BIT(DDRD,5);
		/* select fast PWM mode*/
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		/* load a value in OCR1A,ICR1 */
		OCR1A=val*1000;
		ICR1=19999;
		/* select timer clock, no prescaling */ 
		SET_BIT(TCCR1B,CS10);
		/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
		SET_BIT(TCCR1A,COM1A1);
	}
	
	
	



/*********************************************************************************************/