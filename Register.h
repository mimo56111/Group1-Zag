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

//=========================Timer Registers========================
	/* Timer 1 */
	#define mySFIOR  *((volatile unsigned char* const)0X50)
	#define PUD 2
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

#endif /* REGISTER_H_ */