/*
 * ADC_MCAL.c
 *
 *  Author: Mahmoud Ayman
 */ 
#include "stdmacros.h"
#include "Register.h"
#include "Data_type.h"
void ADC_vInit(){
	/* Configure Vref (Vcc on AVCC with external capacitor at Vref pin)*/
	SET_BIT(myADMUX,myREFS0);
	CLR_BIT(myADMUX,myREFS1);
	/* Enable ADC */
	SET_BIT(myADCSRA,myADEN);
	/* Adjust ADC Clock make the division factor 64 because we use freq. 8M so 8M/64=125KHz */
	SET_BIT(myADCSRA,myADPS2);
	SET_BIT(myADCSRA,myADPS1);
	CLR_BIT(myADCSRA,myADPS0);
}

u16 ADC_u16Read_Single_Endded(u8 channel_number){
	u16 read_value ;
	/* Must be from 0>>7 to select one of these pin ADC0,1,2 */
	channel_number &=0x07;
	/* Clear from MUX4 to MUX0 before set the required bit */
	myADMUX &=0xE0;
	/* Choose the correct channel by setting the channel number in MUX4:0 bits */
	myADMUX = myADMUX | channel_number;
	/* Start the conversion by set Bit (ADSC) */
	SET_BIT(myADCSRA,myADSC);
	/*Wait for the conversion to complete and ADIF(Bit 4) become 1 */
	while(IS_BIT_CLR(myADCSRA,myADIF));
	/* Clear ADIF by write'1' to it */
	SET_BIT(myADCSRA,myADIF);
	/* Combine ADCL +ADCH */
	read_value = myADCL;
	read_value |= (myADCH<<8);
	/* Return value*/
	return read_value;
}