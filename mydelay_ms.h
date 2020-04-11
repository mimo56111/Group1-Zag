/*
 * mydelay_ms.h
 *
 * Created: 3/25/2020 8:50:42 PM
 *  Author: 20155
 */ 
// 1MHz clock means 8000000 cycles per second.
// So 1 cycle equals 1/8000000 seconds or 0.125µs.
// To get 1 second delay, you need 8000000 cycles of 0.125µs,
// so it means that you have to DELAY_MS(1000) which mean number of cycles (8000000/1000)*1000 =8000000 cycles = 1 sec
// the "NOP" takes 1 Cycle only
#include "Data_type.h"
#ifndef MYDELAY_MS_H_
#define MYDELAY_MS_H_
	#define clock   8000000
	#define error_ratio 30
	u32 i;
	u32 n;
	
	DELAY_MS(delay){
		
		n=(delay *clock)/2;
		for(i=1; i<= n; i++){
			
		}
		
	}
	
	

#endif /* MYDELAY_MS_H_ */