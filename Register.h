/*
 * Register.h
 *
 * Created: 3/25/2020 8:51:30 PM
 *  Author: 20155
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_
//=========================GPIO Registers====================================
	/* Port A */
	#define myPORTA  *((volatile unsigned char* const)0X3B)
	#define myDDRA   *((volatile unsigned char* const)0X3A)
	#define myPINA   *((volatile unsigned char* const)0X39)
	
	/* Port B */
	#define myPORTB  *((volatile unsigned char* const)0X38)
	#define myDDRB   *((volatile unsigned char* const)0X37)
	#define myPINB   *((volatile unsigned char* const)0X36)
	
	/* Port C */
	#define myPORTC  *((volatile unsigned char* const)0X35)
	#define myDDRC   *((volatile unsigned char* const)0X34)
	#define myPINC   *((volatile unsigned char* const)0X33)
	
	/* Port D */
	#define myPORTD  *((volatile unsigned char* const)0X32)
	#define myDDRD   *((volatile unsigned char* const)0X31)
	#define myPIND   *((volatile unsigned char* const)0X30)
//================================================================

//=========================Timers Registers========================
	/* Timer 1 */
	#define mySFIOR  *((volatile unsigned char* const)0X50)
		#define PUD     2
		#define myADTS0 5
		#define myADTS1 6
		#define myADTS2 7
		
		
	/* Timer 0 */
	#define myTCNT0	 *((volatile unsigned char* const)0x52)
	#define myOCR0 	 *((volatile unsigned char* const)0x5C)
	#define myTIMSK	 *((volatile unsigned char* const)0x59)
		#define myTOIE0  0
		#define myOCIE0  1
	#define myTCCR0	 *((volatile unsigned char* const)0x53)
		#define myFOC0 	 7
		#define myWGM00  6
		#define myCOM01  5
		#define myCOM00	 4
		#define myWGM01	 3
		#define myCS02 	 2
		#define myCS01 	 1
		#define myCS00 	 0
	#define myTIFR	 *((volatile unsigned char* const)0x58)
		#define myTOV0   0
		#define myOCF0   1
//================================================================
	
	
//=========================EEPROM Registers========================
	#define myEEARH  *((volatile unsigned char* const)0X3F)
	#define myEEARL  *((volatile unsigned char* const)0X3E)
	#define myEEDR   *((volatile unsigned char* const)0X3D)
	#define myEECR   *((volatile unsigned char* const)0X3C)
	
	
	
	/* EEPROM Control Register */
	#define myEERIE   3
	#define myEEMWE   2
	#define myEEWE    1
	#define myEERE    0
//================================================================


//=========================ADC Registers==========================
	/* ADC Multiplexer Selection Register */
	#define myADMUX  *((volatile unsigned char* const)0X27)
		#define myMUX0  0
		#define myMUX1  1
		#define myMUX2  2
		#define myMUX3  3
		#define myMUX4  4
		#define myADLAR 5
		#define myREFS0 6
		#define myREFS1 7
	/* ADC Control and status Register A */	
	#define myADCSRA *((volatile unsigned char* const)0X26)
		#define myADPS0  0
		#define myADPS1  1
		#define myADPS2  2
		#define myADIE   3
		#define myADIF   4
		#define myADATE  5
		#define myADSC   6
		#define myADEN   7
	/* ADC Data Registers */		
	#define myADCH   *((volatile unsigned char* const)0X25)
	#define myADCL   *((volatile unsigned char* const)0X24)
//================================================================
#endif /* REGISTER_H_ */