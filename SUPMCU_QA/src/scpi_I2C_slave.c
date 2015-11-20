/******************************************************************************

(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source:
$Author: aek $
$Revision: 3.0 $
$Date: 2014-06-01 16:22:37-07 $

******************************************************************************/

#include "scpi_I2C_slave.h"
#include "salvo.h"
#include <main.h>


#define USE_AND_OR
#include <i2c.h>
#include <stdlib.h>

#include "p24fxxxx.h"

//GLOBAL VARIABLES
int	 			I2C1_Msgs_Pending;
long			I2C1_Msgs_Received;

//LOCAL VARIABLES
static char 	I2C1_Buffer[I2C1_NUM_BUFS][I2C1_BUF_LEN];
static char* 	I2C1_inPtr;
static char* 	I2C1_endPtr;
static int		I2C1_Out_Index;
static int		I2C1_In_Index;	

#define I2C1_CLOCK_STRETCH



/**************************************************************//**
* Init I2C1 Bus-
* This function runs in main()
*****************************************************************/
void i2c1_init() {

	_SI2C1IE = 0;				//DISABLE I2C1 INTERRUPTS
	
	I2C1_Msgs_Pending = 0;
	//I2C1_Msgs_Received = 0;
	//I2C1_Out_Index 	  =	0;
	//I2C1_In_Index	      = 0;
	
	#ifdef I2C1_CLOCK_STRETCH
		I2C1CON = 0x9040;		//ENABLE I2C1 WITH CLOCK STRETCHING
	#else
		I2C1CON = 0x8000;		//ENABLE I2C1, NO CLOCK STRETCHING
	#endif

	I2C1ADD = i2c1_addr();		//7-BIT I2C SLAVE ADDRESS
        
	I2C1STATbits.I2COV = 0;		//CLEAR OVERFLOW STATUS BIT
	_SI2C1IF = 0;				//NO I2C SLAVE INTERRUPTS PENDING
	_SI2C1IP = 6;				//INTERRUPT PRIORITY = 6
	
	_SI2C1IE = 1;				//ENABLE I2C1 INTERRUPTS
	
}

/*******************************************************//**
* Function Name	:	SI2C1Interrupt
* Description 	:	This is the ISR for I2C1 Slave interrupt
* Arguments	 	:	None
*********************************************************/

void __attribute__((interrupt,no_auto_psv)) _SI2C1Interrupt(void)
{   
	
	static char inChar;
	
	inChar = (char)I2C1RCV;

	if(I2C1STATbits.R_W == 0){
	//BYTE INCOMING
		if (I2C1STATbits.D_A == 1){
		//BYTE IS DATA
			if (I2C1_inPtr < I2C1_endPtr){
			//BUFFER NOT FULL -> ADD CHAR TO BUFFER & ADVANCE
				*I2C1_inPtr = inChar;
				if (inChar == 0x0A){
				//MESSAGE COMPLETE -> SIGNAL FOR SCPI TO PARSE
					*(++I2C1_inPtr) = '\0';		//ADD TERM CHAR TO MESSAGE
					I2C1_Msgs_Pending++;
					I2C1_In_Index++;
					if (I2C1_In_Index >= I2C1_NUM_BUFS){
						I2C1_In_Index = 0;
					}
				}else{
				//MESSAGE INCOMPLETE -> ADVANCE INCOMING POINTER
					I2C1_inPtr++;
				}		
			}
		}else{
		//BYTE IS ADDRESS (NEW MESSAGE)
			I2C1_Msgs_Received++;
			if (I2C1_Msgs_Pending < I2C1_NUM_BUFS){
			//BUFFERS NOT FULL -> ADVANCE TO NEXT BUFFER
				I2C1_inPtr = &I2C1_Buffer[I2C1_In_Index][0];
				I2C1_endPtr = I2C1_inPtr + I2C1_BUF_LEN - 2;
			}else{
			//BUFFERS FULL -> IGNORE INCOMING CHARS
				I2C1_inPtr = &inChar;
				I2C1_endPtr = I2C1_inPtr;
			}		
		}	
	}else{
	//DATA REQUESTED -- RETURN REQUESTED DATA FIELD
		if (telem_avail) {
			I2C1TRN = (unsigned char) *telem_request_ptr;
			if (telem_request_count++ < telem_request_len){
				telem_request_ptr++;
			}else{
				telem_avail = 0;
			}	
			I2C1CONbits.SCLREL = 1;	//Release SCL1 line
		}else{
			I2C1TRN = (unsigned char) 0;
			I2C1CONbits.SCLREL = 1;	//Release SCL1 line
		}	
	}/*if-else*/
	
	_SI2C1IF = 0;	//CLEAR I2C1 SLAVE INTERRUPT FLAG
	
	#ifdef I2C1_CLOCK_STRETCH
		I2C1CONbits.SCLREL = 1;	//Release SCL1 line
	#endif
}

/**********************************************************//**
****                                                     ****
**                                                         **
i2c1_SCPI_str()

Return the oldest I2C string buffer & advance 
output buffer index if successful.

I2C strings are not checked for validity (e.g. the
checksums have not been verified). They end in [<CR>],
<LF>, NULL.

IMPORTANT NOTE: There is no attempt to guarantee that the
value returned is not the buffer that is _currently_ being
updated. So a user should verify the correctness of the
returned string via a checksum check, etc.

**                                                         **
****                                                     ****
************************************************************/

void i2c1_read_buffer(char* strP){
	
	if (strncpy(strP, &I2C1_Buffer[I2C1_Out_Index][0], SCPI_CMD_BUFFER_LEN)){
		
		I2C1_Msgs_Pending--;
		I2C1_Out_Index++;
		if (I2C1_Out_Index >= I2C1_NUM_BUFS){	
			I2C1_Out_Index = 0;
		}
		//return 0;
	}else{
	;
		//return 1;
	}
				
} /*i2c1_SCPI_str */

/**********************************************************//**
****                                                     
**                                                        
i2c1_addr()

Return the I2C slave address.

Future versions may read value from hardware 
configuration memory.

**                                                       
****                                                     
************************************************************/
unsigned char i2c1_addr(void){
	
	return I2C_ADDRESS;
	
}	/* i2c1_addr */
