/******************************************************************************
(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source: C:\\RCS\\D\\Pumpkin\\CubeSatKit\\Example\\PIC24\\PIC24FJ256GA110\\CubeSat_Kit_Dev_Board\\Test\\Test1\\init.c,v $
$Author: aek $
$Revision: 3.5 $
$Date: 2011-09-17 16:24:44-07 $

******************************************************************************/
#include "main.h"
#include "init.h"
#include "events.h"

// Pumpkin CubeSat Kit headers
#include "csk_hw.h" 
#include "csk_led.h"
#include "csk_mhx.h"
#include "csk_uart.h"
#include "csk_usb.h"
#include "csk_wdt.h"

// Pumpkin PIC24 Library.
#include "pic24_i2c.h"
#include "pic24_uart.h"

// Microchip PIC24F Peripehral Library
#include <pps.h>
#include <pwrmgnt.h>
#include <timer.h>
#include <uart.h>

#include "salvo.h"

//#if defined(SUPMCU_GPSRM1_REVA) \
    ||  defined(SUPMCU_GPSRM1_REVB) \
    ||  defined(SUPMCU_GPSRM1_REVC)
//#include "gps_nmea.h"
//#endif
#include "gps_nmea.h"
// Ensure that correct ICD port is selected.  
_CONFIG1( ICS_PGx1 & JTAGEN_OFF )

// Select primary oscillator in XT mode. 
_CONFIG2( FNOSC_PRI & POSCMOD_XT )


/******************************************************************************
****                                                                       ****
**                                                                           **
init()

**                                                                           **
****                                                                       ****
******************************************************************************/
void init(void) {

  // Force WDT off for now ... having it on tends to confuse novice
  //   users.
  csk_wdt_off();
  

  // Keep interrupts off for now ...
  __disable_interrupt();

  
  // All CSK control signals are active LOW.
  #if   defined(__PIC24FJ256GA110__) // PSPM D

  // Minimal set of I/O ... only necessary control signals are configured as outputs.
  TRISA = 0xFFFF;
  TRISB = ~( BIT5); // TX3
  TRISC = ~( BIT1); // -OE_USB
  TRISD = ~( BIT8+BIT5+BIT2+BIT1); // HS3, HS4 & HS5, TX2
  TRISE = ~( BIT8+BIT4+BIT3+BIT2); // IO.30, -ON_SD, -ON_MHX & -OE_MHX
  TRISF = ~( BIT5+BIT3); // TX1 & TX0

  PORTA = 0x0000;
  PORTB = 0x0000+BIT5;              // TX3 initially HIGH
  PORTC = 0x0000+BIT1;              // -OE_USB is OFF
  PORTD = 0x0000+BIT8;              // TX2 initially HIGH
  PORTE = 0x0000+BIT4+BIT3+BIT2;   	// -ON_SD, -ON_MHX, -OE_MHX are OFF
  PORTF = 0x0000+BIT3+BIT5;			// TX0 & TX1 initially HIGH.
  PORTG = 0x0000;

  AD1PCFGL = 0xFFFF;

  #elif defined(__PIC24FJ256GB110__) // PSPM E Rev A

  // Minimal set of I/O ... only necessary control signals are configured as outputs.
  TRISA = 0xFFFF;
  TRISB = ~(                                                             BIT5                    ); // TX3
  TRISC = ~(                                                                            BIT1     ); // -OE_USB
  TRISD = ~(                                    BIT9+BIT8+BIT7+          BIT5                    ); // TX0, TX2, HS3, HS5
  TRISE = ~(                                         BIT8+               BIT4+BIT3+BIT2          ); // IO.30, -ON_SD, -ON_MHX & -OE_MHX
  TRISF = ~(                                                        BIT5                         ); // TX1
  TRISG = ~(BIT15                                                                                ); // HS4

  PORTA = 0x0000;
  PORTB = 0x0000+BIT5;           // TX3 initially HIGH
  PORTC = 0x0000+BIT1;           // -OE_USB is OFF
  PORTD = 0x0000+BIT9+BIT8;      // TX0, TX2 initially high
  PORTE = 0x0000+BIT4+BIT3+BIT2; // -ON_SD, -ON_MHX, -OE_MHX are OFF
  PORTF = 0x0000+BIT5;	         // TX1 initially high.
  PORTG = 0x0000;

  #elif defined(__PIC24FJ256GB210__) // PSPM E Rev B
  
  // Minimal set of I/O ... only necessary control signals are configured as outputs.
  TRISA = 0xFFFF;
  TRISB = ~(                                                             BIT5                    ); // TX3
  TRISC = ~(                                                                            BIT1     ); // -OE_USB
  TRISD = ~(                                    BIT9+BIT8+BIT7+          BIT5                    ); // TX0, TX2, HS3, HS5
  TRISE = ~(                                         BIT8+               BIT4+BIT3+BIT2          ); // IO.30, -ON_SD, -ON_MHX & -OE_MHX
  TRISF = ~(                                                        BIT5                         ); // TX1
  TRISG = ~(BIT15                                                                                ); // HS4

  PORTA = 0x0000;
  PORTB = 0x0000+BIT5;           // TX3 initially HIGH
  PORTC = 0x0000+BIT1;           // -OE_USB is OFF
  PORTD = 0x0000+BIT9+BIT8;      // TX0, TX2 initially high
  PORTE = 0x0000+BIT4+BIT3+BIT2; // -ON_SD, -ON_MHX, -OE_MHX are OFF
  PORTF = 0x0000+BIT5;	         // TX1 initially high.
  PORTG = 0x0000;

  ANSA = 0x0000;
  ANSB = 0x0000;
  ANSC = 0x0000;
  ANSD = 0x0000;
  ANSE = 0x0000;
  ANSF = 0x0000;
  ANSG = 0x0000;
  #else
  #error PIC24F device not supported by CubeSat Kit
  #endif 

  // High-level inits (works at any clock speed).
  csk_mhx_close();
  csk_mhx_pwr_off();
  csk_usb_close();
  csk_led_status_close();
  

  // Set up to run with primary oscillator.
  // See _CONFIG2 above. A configuration-word-centric setup of the
  //  oscillator(s) was chosen because of its relative simplicity.
  //  Note e.g. that PwrMgnt_OscSel() returns FALSE if clock switching
  //  (FCKSM) is disabled ...


  // Set up Timer2 to run at system tick rate                
  ConfigIntTimer2(T2_INT_ON & T2_INT_PRIOR_1);   // Timer is configured for 10 msec (100Hz), with interrupts
  OpenTimer2(T2_ON & T2_IDLE_CON & T2_GATE_OFF & T2_PS_1_1 & T2_32BIT_MODE_OFF & T2_SOURCE_INT,
             (MAIN_XTAL_FREQ/(2*100)));        // A prescalar is not required because 8E6/200 < 16 bits.


  #if   defined(__PIC24FJ256GA110__) // PSPM D
  // Configure I/O pins for UARTs via PIC24's PPS system.
  // RP inputs must be configured as inputs!
  // CSK UART0 is used as the terminal, via USB, IO.6(RP17) & IO.7(RP10)
  // CSK UART0 (PIC24 UART1) TX/RX = IO.6/IO.7
  iPPSInput(IN_FN_PPS_U1RX,IN_PIN_PPS_RP10);
  iPPSOutput(OUT_PIN_PPS_RP17,OUT_FN_PPS_U1TX);
  
  // CSK UART1 can talk to GPSRM 1 via IO.4(RP16) & IO.5(RP30)
  // CSK UART1 (PIC24 UART2) TX/RX = IO.4/IO.5
  iPPSInput(IN_FN_PPS_U2RX,IN_PIN_PPS_RP30);
  iPPSOutput(OUT_PIN_PPS_RP16,OUT_FN_PPS_U2TX);

  // CSK UART2 can talk to GPSRM 1 via IO.16(RP2) & IO.17(RP22)
  // CSK UART2 (PIC24 UART3) TX/RX = IO.16/IO.17
  iPPSInput(IN_FN_PPS_U3RX,IN_PIN_PPS_RP22);
  iPPSOutput(OUT_PIN_PPS_RP2,OUT_FN_PPS_U3TX);

  // CSK UART3 can talk to GPSRM 1 via IO.32(RP18) & IO.33(RP28)
  // CSK UART3 (PIC24 UART4) TX/RX = IO.4/IO.5
  iPPSInput(IN_FN_PPS_U4RX,IN_PIN_PPS_RP28);
  iPPSOutput(OUT_PIN_PPS_RP18,OUT_FN_PPS_U4TX);
  #elif defined(__PIC24FJ256GB110__) || defined(__PIC24FJ256GB210__)
  iPPSInput(IN_FN_PPS_U1RX,IN_PIN_PPS_RP10); 	// RF4
  iPPSOutput(OUT_PIN_PPS_RP17,OUT_FN_PPS_U1TX);	// RF5
  iPPSInput(IN_FN_PPS_U2RX,IN_PIN_PPS_RP30);	// RF2
  iPPSOutput(OUT_PIN_PPS_RP4,OUT_FN_PPS_U2TX);	// RD9 
  iPPSInput(IN_FN_PPS_U3RX,IN_PIN_PPS_RP22);	// RD3
  iPPSOutput(OUT_PIN_PPS_RP2,OUT_FN_PPS_U3TX);	// RD8
  iPPSInput(IN_FN_PPS_U4RX,IN_PIN_PPS_RP28);	// RB4
  iPPSOutput(OUT_PIN_PPS_RP18,OUT_FN_PPS_U4TX);	// RB5
  #else
  #error PIC24F device not supported by CubeSat Kit
  #endif 


  // Init UARTs to 9600,N,8,1  
  // UARTs won't transmit until interrupts are enabled ...
  csk_uart0_open(CSK_UART_9600_N81);
  csk_uart1_open(CSK_UART_9600_N81);
  csk_uart2_open(CSK_UART_9600_N81);
  csk_uart3_open(CSK_UART_9600_N81);

  
  
  csk_usb_open();
 
  
  csk_uart0_puts(STR_CRLF STR_CRLF);
  csk_uart0_puts("Pumpkin " STR_CSK_TARGET " " STR_APP_NAME "." STR_CRLF);
  csk_uart0_puts(STR_VERSION "." STR_CRLF);
  csk_uart0_puts(STR_WARNING "." STR_CRLF);
  // Ask the user what board he's like to test and wait for a response
  csk_uart0_puts("Choose the module: " STR_CRLF);
  csk_uart0_puts("Press g to test the GPS board " STR_CRLF);
  csk_uart0_puts("Press b to test the BIM board" STR_CRLF);
  csk_uart0_puts("Press p to test the PIM board" STR_CRLF);

   i2c1_open();
  
  //sprintf(strTmp,"Sending to I2C address 0x%x \n",I2C_ADDR);
 // csk_uart0_puts(strTmp STR_CRLF);
    
} /* init() */


void __attribute__ ((interrupt,no_auto_psv)) _T2Interrupt (void) {
   T2_Clear_Intr_Status_Bit;
   OSTimer();
}

// UART1 (CSK UART0) is for terminal
void __attribute__ ((interrupt,no_auto_psv)) _U1TXInterrupt(void) {
  csk_uart0_outchar();
}

void __attribute__ ((interrupt,no_auto_psv)) _U1RXInterrupt(void) {
  U1RX_Clear_Intr_Status_Bit;
  csk_uart0_inchar(ReadUART1());
  OSSignalSem(SEM_CMD_CHAR_P); // commands normally come from Rx0 (terminal port on Dev Board)
}


// UART2 (CSK UART1) is first possible way to talk to OEM615 ...
void __attribute__ ((interrupt,no_auto_psv)) _U2TXInterrupt(void) {
  csk_uart1_outchar();
}

/*#if defined(SUPMCU_GPSRM1_REVA) \
    ||  defined(SUPMCU_GPSRM1_REVB) \
    ||  defined(SUPMCU_GPSRM1_REVC)
*/
void __attribute__ ((interrupt,no_auto_psv)) _U2RXInterrupt(void) {
  if(gps_enabled()) {
    // PIC24 requires explicit clear of UART Rx interrupt flag!
    U2RX_Clear_Intr_Status_Bit;
    gps_NMEA_rcv(ReadUART2());
  }
  else {
    csk_uart1_inchar(ReadUART2());
  }
}

void __attribute__ ((interrupt,no_auto_psv)) _U3RXInterrupt(void) {

  if(gps_enabled()) {
    // PIC24 requires explicit clear of UART Rx interrupt flag!
    U3RX_Clear_Intr_Status_Bit;
    gps_NMEA_rcv(ReadUART3());
  }
  else {
    csk_uart2_inchar(ReadUART3());
  }
}


// UART3 (CSK UART2) is second possible way to talk to OEM615  ...
void __attribute__ ((interrupt,no_auto_psv)) _U3TXInterrupt(void) {
  csk_uart2_outchar();
}

// UART4 (CSK UART3) is third possible way to talk to OEM615  ...
void __attribute__ ((interrupt,no_auto_psv)) _U4TXInterrupt(void) {
  csk_uart3_outchar();
}

void __attribute__ ((interrupt,no_auto_psv)) _U4RXInterrupt(void) {

  if(gps_enabled()) {
    // PIC24 requires explicit clear of UART Rx interrupt flag!
    U4RX_Clear_Intr_Status_Bit;
    gps_NMEA_rcv(ReadUART4());
  }
  else {
    csk_uart3_inchar(ReadUART4());
  }
}
/*
#else 
void __attribute__ ((interrupt,no_auto_psv)) _U2RXInterrupt(void) {
    //U2RX_Clear_Intr_Status_Bit;  // sa samo dvojkom primam 1 msg i posle nista
    csk_uart1_inchar(ReadUART2());
}

void __attribute__ ((interrupt,no_auto_psv)) _U3RXInterrupt(void) {
//    U3RX_Clear_Intr_Status_Bit;  //sa samo trojkom primim 1 msg i posle nista
    csk_uart2_inchar(ReadUART3());
}

// UART3 (CSK UART2) is second possible way to talk to OEM615  ...
void __attribute__ ((interrupt,no_auto_psv)) _U3TXInterrupt(void) {
  csk_uart2_outchar();
}

// UART4 (CSK UART3) is third possible way to talk to OEM615  ...
void __attribute__ ((interrupt,no_auto_psv)) _U4TXInterrupt(void) {
  csk_uart3_outchar();
}

void __attribute__ ((interrupt,no_auto_psv)) _U4RXInterrupt(void) {
  //  U4RX_Clear_Intr_Status_Bit;  // sa samo cetvorkom isto kao prethodne dve
    csk_uart3_inchar(ReadUART4());
}
#endif

*/