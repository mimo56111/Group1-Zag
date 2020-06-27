/*
 * TMU.h
 *
 *  Author: Mahmoud Ayman
 */ 


#ifndef TMU_H_
#define TMU_H_
#include "Data_type.h"
#include "Timer_driver_MCAL.h"
#include "Register.h"
#include "GPIO_MCAL.h"
#include <avr/interrupt.h>

/****************************************************************/
#define Timer0          0
#define Timer1          1
#define Timer2          2

#define E_True          1
#define E_False         0

#define NULL            0

#define Periodic        0
#define One_Shot        1
#define INVALID_TYPE    2

#define TMU_Resolution  5

#define Max_Timer_Number  10

typedef enum
{
	NO_ERRORS=0,			//0
	TIMER_NOT_INITIATED,	//1
	INVALID_PARAMS,			//2
	MAX_NO_REACHED,			//3
	
}TMU_ErrorTypes;


typedef struct {
	void (*ptr_Delaycompletefun_User_CBK)(void)	;
	u16 Delay;
	u8 Periodicity;
	s16 Remaining_Time;
	u8 index;
	}Str_TMU_OBJ;

	
	TMU_ErrorTypes TMU_Init(u8 Timer_Channel , u16 Resolution);

	TMU_ErrorTypes TMU_Start_Timer(Str_TMU_OBJ *OBJ , u8 Type , u16 delay ,void (*CB_func)(void));
	
	TMU_ErrorTypes TMU_Stop_Timer(Str_TMU_OBJ *OBJ);
	
	TMU_ErrorTypes TMU_dispatch(void);
	
	TMU_ErrorTypes TMU_DeInit(void);
#endif /* TMU_H_ */