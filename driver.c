/*  Author: Mahmoud Ayman*/

#define F_CPU 8000000UL
#include <util/delay.h>
#include "Data_type.h"
#include "LED_driver_ECU.h"
#include "Button_driver_ECU.h"

int main(void){
	button_vInit('B',0);
	LED_vintialize('D',2);
	while(1){
		
		if (button_u8read('B',0)==1){
			LED_vTurnon('D',2);
		}else{
			LED_vTurnoff('D',2);
		}
	}
					
}

