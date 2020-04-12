/*  Author: Mahmoud Ayman*/

#include "LCD_ECU.h"
#include "LCD_ECU.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Data_type.h"
#include "EEPROM_MCAL.h"
#include "Keypad_ECU.h"
#include <avr/interrupt.h>
int main(void){
	
	LCD_vInit(Eight_bit,High_Nibble,'A','B',2,'B',3,'B',4);
	keypad_vInit('D');	
	u8 x ;
	x=keypad_u8check_press('D');
	
	
	while(1){
		while (x==NOTPRESSED){               
			x=keypad_u8check_press('D');
		}
		
		
		LCD_vsend_char(Eight_bit,High_Nibble,'A','B',2,'B',4,x);
		x = NOTPRESSED;
		_delay_ms(300);
		}		
		
}
