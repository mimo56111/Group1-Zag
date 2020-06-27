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
	#define myTCNT1H	 *((volatile unsigned char* const)0x4D)
	#define myTCNT1L	 *((volatile unsigned char* const)0x4C)
	#define myOCR1AH 	 *((volatile unsigned char* const)0x4B)
	#define myOCR1AL 	 *((volatile unsigned char* const)0x4A)
	#define myOCR1BH 	 *((volatile unsigned char* const)0x49)
	#define myOCR1BL 	 *((volatile unsigned char* const)0x48)
	#define myICR1H 	 *((volatile unsigned char* const)0x47)
	#define myICR1L 	 *((volatile unsigned char* const)0x46)
	#define mySFIOR      *((volatile unsigned char* const)0X50)
		#define myPSR10   0
		#define myPSR2    1
		#define PUD       2
		#define myACME    3
		#define myADTS0   5
		#define myADTS1   6
		#define myADTS2   7
	#define myTCCR1A	 *((volatile unsigned char* const)0x4F)
		#define myWGM10   0
		#define myWGM11   1
		#define myFOC1B   2
		#define myFOC1A   3
		#define myCOM1B0  4
		#define myCOM1B1  5
		#define myCOM1A0  6
		#define myCOM1A1  7
	#define myTCCR1B	 *((volatile unsigned char* const)0x4E)	
		#define myCS10    0
		#define myCS11    1
		#define myCS12    2
		#define myWGM12   3
		#define myWGM13   4
		#define myICES1   6
		#define myICNC1   7	
	#define myTIMSK	 *((volatile unsigned char* const)0x59)
		#define myTOIE1   2
		#define myOCIE1B  3
		#define myOCIE1A  4
		#define myTICIE1  5
	#define myTIFR	 *((volatile unsigned char* const)0x58)
		#define myTOV1    2
		#define myOCF1B   3
		#define myOCF1A   4
		#define myICF1    5
		
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
		
	/* Timer 2 */
	#define myTCNT2	 *((volatile unsigned char* const)0x44)
	#define myOCR2 	 *((volatile unsigned char* const)0x43)
	#define myTIMSK	 *((volatile unsigned char* const)0x59)
		#define myTOIE2  6
		#define myOCIE2  7
	#define myTCCR2	 *((volatile unsigned char* const)0x45)
		#define myFOC2 	 7
		#define myWGM20  6
		#define myCOM21  5
		#define myCOM20	 4
		#define myWGM21	 3
		#define myCS22 	 2
		#define myCS21 	 1
		#define myCS10 	 0
	#define myTIFR	 *((volatile unsigned char* const)0x58)
		#define myTOV2   6
		#define myOCF2   7	
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
//=========================USART Registers==========================
	#define myUDR    *((volatile unsigned char* const)0X2C)
	#define myUCSRA  *((volatile unsigned char* const)0X2B)
		#define myRXC      7
		#define myTXC      6
		#define myUDRE     5
		#define myFE       4
		#define myDOR      3
		#define myPE       2
		#define myU2X      1
		#define MPCM       0
	#define myUCSRB  *((volatile unsigned char* const)0X2A)
		#define myRXCIE    7
		#define myTXCIE    6
		#define myUDRIE    5
		#define myRXEN     4
		#define myTXEN     3
		#define myUCSZ2    2
		#define myRXB8     1
		#define myTXB8     0 
	#define myUCSRC  *((volatile unsigned char* const)0X40)
		#define myURSEL    7
		#define myUMSEL    6
		#define myUPM1     5
		#define myUPM0     4
		#define myUSBS     3
		#define myUCSZ1    2
		#define myUCSZ0    1
		#define myUCPOL    0
	#define myUBRRH  *((volatile unsigned char* const)0X40)
		#define myURSEL    7
	#define myUBRRL  *((volatile unsigned char* const)0X29)
//================================================================
#endif /* REGISTER_H_ */