/******************************************************************************
(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source: C:\\RCS\\D\\Pumpkin\\CubeSatKit\\Example\\all\\all\\CubeSatKit_Dev_Board\\Test\\Test1\\task_5sec.c,v $
$Author: aek $
$Revision: 3.1 $
$Date: 2009-11-02 00:45:07-08 $

******************************************************************************/
#include "main.h"
#include "task_new.h"
//#include "task_test.h"
#include "task_supmcu_qa.h"
#include "task_gps_qa.h"


// Pumpkin CubeSat Kit headers
#include "csk_uart.h"

// Pumpkin Salvo headers
#include "salvo.h"

// Pumpkin PIC24 Library.
#include "pic24_i2c.h"

// GPSRM 1's I2C address 
#define GPS_SMB_ADDR 0x51

#if 1
unsigned char STR_PROP_VINTI[] =   {"GPS:PROP V,0.0,86400.0,-18982.9116920829,-25047.1371788540,-173.044152439773,2.96990008479315,0.329975213844251,0.265794505165530\n"};
#else
unsigned char STR_PROP_VINTI[] =   {"GPS:PROP V,0.0,86400.0,18982.9,25047,173,2,0,0\n"};
//unsigned char STR_PROP_VINTI[] =   {"GPS:PROP V, 0,0,1,1,2,2,3,3\n"};
#endif


/******************************************************************************
****                                                                       ****
**                                                                           **
new_prop_Vinti()


**                                                                           **
****                                                                       ****
******************************************************************************/
void new_prop_Vinti(unsigned int show) {
  i2c1_write(GPS_SMB_ADDR, STR_PROP_VINTI, sizeof(STR_PROP_VINTI)-1);  
  if(show) { 
    user_debug_msg("new_prop_Vinti:" " Told GPSRM1 to propagate using Vinti."); 
  }
} /* new_prop_Vinti() */


/******************************************************************************
****                                                                       ****
**                                                                           **
task_5sec()

Simple task that runs every 5s.

**                                                                           **
****                                                                       ****
******************************************************************************/
void task_new(void) {
  #if 0
  static unsigned int i;
  #endif

  user_debug_msg(STR_TASK_NEW "Starting.");
  
  #if 0
  // wait 2min until we're into the NMEA-scanning portion of the test code ... 
  for(i=0;i<120;i++) {
    OS_Delay(100);
  }
  #endif

  while (1) {

    // Alternate GPS LED ON, GPS LED blinking, every 10s
    OS_Delay(250);    
    OS_Delay(250);
    OS_Delay(250);    
    OS_Delay(250);
    sup_led_on(FALSE);
    user_debug_msg(STR_TASK_NEW "GPS LED should be ON.");
    OS_Delay(250);
	OS_Delay(250);
    OS_Delay(250);    
    OS_Delay(250);
	sup_led_flash(FALSE);
    user_debug_msg(STR_TASK_NEW "GPS LED should be blinking.");

    new_prop_Vinti(TRUE);


  } /* while */

} /* task_new() */


