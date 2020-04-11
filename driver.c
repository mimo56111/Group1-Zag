/*  Author: Mahmoud Ayman*/

#include "LCD_ECU.h"
#include "LCD_ECU.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Data_type.h"
#include "EEPROM_MCAL.h"
#include <avr/interrupt.h>
int main(void){
	
	LCD_vInit(Eight_bit,High_Nibble,'A','B',2,'B',3,'B',4);
	
	LCD_vsend_cmd(Eight_bit,High_Nibble,'A','B',2,64,'B',4);
	LCD_vsend_char(Eight_bit,High_Nibble,'A','B',2,'B',4,0);
	LCD_vsend_char(Eight_bit,High_Nibble,'A','B',2,'B',4,0);
	LCD_vsend_char(Eight_bit,High_Nibble,'A','B',2,'B',4,10);
	LCD_vsend_char(Eight_bit,High_Nibble,'A','B',2,'B',4,21);
	LCD_vsend_char(Eight_bit,High_Nibble,'A','B',2,'B',4,17);
	LCD_vsend_char(Eight_bit,High_Nibble,'A','B',2,'B',4,10);
	LCD_vsend_char(Eight_bit,High_Nibble,'A','B',2,'B',4,4);
	LCD_vsend_char(Eight_bit,High_Nibble,'A','B',2,'B',4,0);
	
	
	LCD_Move_Cursor(Eight_bit,High_Nibble,'A','B',2,'B',4,1,5);
	
	LCD_vsend_char(Eight_bit,High_Nibble,'A','B',2,'B',4,0);
	
	
	
	LCD_vsend_string(Eight_bit,High_Nibble,'A','B',2,'B',4,"Mahmoud");
	while(1){
		
		}		
		
}
