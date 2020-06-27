/*
 * TMU.c
 *
 *  Author: Mahmoud Ayman
 */ 
#include "TMU.h"
static Str_TMU_OBJ * TMU_Internal_Buffer[Max_Timer_Number];
static u8 TMU_Internal_Buffer_Counter =0;
static u16 TMU_Res_MS = 0;
static u8 TMU_initalization = E_False;

TMU_ErrorTypes TMU_Init(u8 Timer_Channel , u16 Resolution){
	u8 i;
	
	for (i=0; i < Max_Timer_Number ; i++){
		TMU_Internal_Buffer[i]= NULL;
	}
	
	TMU_ErrorTypes s_ret_val =NO_ERRORS ;
	TMU_Res_MS = Resolution * TMU_Resolution; 
	TMU_initalization = E_True;
	

	
	return s_ret_val;
}

TMU_ErrorTypes TMU_Start_Timer(Str_TMU_OBJ *OBJ , u8 Type , u16 delay ,void (*CB_func)(void)){
	cli();
	TMU_ErrorTypes S_ret_val = NO_ERRORS;
	if (TMU_initalization=E_True){
		if (TMU_Internal_Buffer_Counter < Max_Timer_Number){
			if ((OBJ!=NULL)&&((Type == Periodic)||(Type == One_Shot)) && (delay !=0)&&(CB_func != NULL)){
				OBJ ->ptr_Delaycompletefun_User_CBK = CB_func;
				OBJ ->Delay = delay;
				OBJ ->Periodicity = Type;
				OBJ ->Remaining_Time = delay;
				OBJ ->index = TMU_Internal_Buffer_Counter;
				TMU_Internal_Buffer[TMU_Internal_Buffer_Counter]=OBJ;
				TMU_Internal_Buffer_Counter++;
			}else{
				S_ret_val = INVALID_PARAMS;
			}
			
		}else{
			S_ret_val = MAX_NO_REACHED;
		}
	}else{
		S_ret_val = TIMER_NOT_INITIATED;
	}
	
	TMR2_Get_Configuration(NORMAL_Mode,TOIE2_enable,OCIE2_disable,NO_PRESCALING);
	TMR2_Set_Counter_Value(55); 
	SET_BIT(myTIFR,myTOV2);
	sei();
	return S_ret_val;
	
}

TMU_ErrorTypes TMU_Stop_Timer(Str_TMU_OBJ *OBJ){
	cli();
		TMU_ErrorTypes S_ret_val = NO_ERRORS;
		if (OBJ != NULL){
			OBJ->ptr_Delaycompletefun_User_CBK = NULL;
			OBJ->Delay = 0;
			OBJ->Remaining_Time=0;
			OBJ->Periodicity = INVALID_TYPE;
			TMU_Internal_Buffer[OBJ->index]=NULL;
			OBJ->index=0;
			TMU_Internal_Buffer_Counter--;
		}else{
			S_ret_val =INVALID_PARAMS;
		}			
	sei();
	return S_ret_val;
}

TMU_ErrorTypes TMU_dispatch(void){
	cli();
		u8 i=0;
		TMU_ErrorTypes S_ret_val = NO_ERRORS;
		if(TMU_initalization==E_True){
			for(i=0;i<Max_Timer_Number;i++){
				if(TMU_Internal_Buffer[i]!=NULL){
					if (TMU_Internal_Buffer[i]->Remaining_Time <= 0){
						TMU_Internal_Buffer[i]->ptr_Delaycompletefun_User_CBK();
						TMU_Internal_Buffer[i]->Remaining_Time += TMU_Internal_Buffer[i]->Delay ;
						if (TMU_Internal_Buffer[i]->Periodicity==One_Shot){
							TMU_Stop_Timer(TMU_Internal_Buffer[i]);
						}
					}
						
				}
			}
		}else{
			S_ret_val = TIMER_NOT_INITIATED;
		}
	sei();
	return S_ret_val;	
}

TMU_ErrorTypes TMU_DeInit(void){
	cli();
		TMU_ErrorTypes S_ret_val = NO_ERRORS;
		myTCCR2=0;
		u8 i;
		for	(i=0; i < Max_Timer_Number;i++){
			TMU_Internal_Buffer[i]=NULL;
		}			
	sei();
	return S_ret_val;
}

u8 Counter = 0 ;
ISR(TIMER2_OVF_vect){
	u8 i;
	Counter ++;
	if (TMU_Res_MS == Counter){
		for (i=0; i <Max_Timer_Number;i++){
			if (TMU_Internal_Buffer[i] != NULL){
				TMU_Internal_Buffer[i]->Remaining_Time--;
				Counter=0;
			}
		}
	
	}
	TMR2_Set_Counter_Value(55);
	sei();
}
