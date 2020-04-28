/*  Author: Mahmoud Ayman*/


#define F_CPU 8000000UL
#include <util/delay.h>
#include "Data_type.h"
#include "LED_driver_ECU.h"
#include "Timer_driver_MCAL.h"
#include <avr/interrupt.h>

void inc (void);
volatile u8 counter1;
volatile u8 counter2;
volatile u16 counter3;
int main(void){
	TMR0_Get_Configuration(CTC_Mode,TOIE0_disable,OCIE0_enable,PRESCALING_CLK1024);
	TMR0_Set_Compare_Value(80); 
	TMR0_vInit();  
	
	sei();
	LED_vintialize('A',0);
	LED_vintialize('A',1);
	LED_vintialize('A',2);
	callback_OCR0_Compare_Match_Interrupt(&inc);
	
	while(1){
		if (counter1 >=100){
			LED_vtoggle('A',0);
			counter1 = 0;
		}
		if (counter2 >=200){
			LED_vtoggle('A',1);
			counter2 = 0;
		}
		if (counter3 >= 300){
			LED_vtoggle('A',2);
			counter3 = 0;
		}
			
	}		
}

void inc (void){
	counter1++;
	counter2++;
	counter3++;
}