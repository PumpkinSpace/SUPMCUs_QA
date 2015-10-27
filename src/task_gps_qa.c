/******************************************************************************
(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Author: SB
$Revision: 0.1 $
$Date: 2015-10-26 17:05:02-08 $

******************************************************************************/
#include "main.h"
#include "events.h"
#include "task_gps_qa.h"
#include "task_supmcu_qa.h"
// Pumpkin CubeSat Kit headers
//#include "csk_hw.h"
//#include "csk_serial.h"
#include "csk_uart.h"

// Pumpkin PIC24 Library.
#include "pic24_i2c.h"

// Pumpkin Salvo RTOS.
#include "salvo.h"
#include "tasks.h"


// Note that we only send the string up to the LF (and not the terminating NULL), 
//  therefore the -1 adjust to sizeof(string).
// GPS MCU LED command strings
unsigned char STR_LED_GPS[] =   {"SUP:LED GPS\n"};

// GPS (i.e., OEM615) receiver power command strings
unsigned char STR_POW_OFF[] =   {"GPS:POWer OFF\n"};
unsigned char STR_POW_ON[]  =   {"GPS:POWer ON\n"};

// GPS (i.e., OEM615) receiver reset command strings
unsigned char STR_RES_OFF[] =   {"GPS:RESet OFF\n"};
unsigned char STR_RES_ON[]  =   {"GPS:RESet ON\n"};

// GPS (i.e., OEM615) receiver passthrough command strings
unsigned char STR_PASS_OFF[] =  {"GPS:PASS OFF\n"};
unsigned char STR_PASS_ON[]  =  {"GPS:PASS ON\n"};

//GPS (i.e., OEM615) receiver log position command
unsigned char STR_LOG_BESTPOS[]  =   {"GPS:LOGPOS 1,BESTPOS\n"};
unsigned char STR_LOG_BESTXYZA[] =   {"GPS:LOGPOS 1,BESTXYZA\n"};
unsigned char STR_LOG_BESTXYZB[] =   {"GPS:LOGPOS 1,BESTXYZB\n"};

// GPS (i.e., OEM615) receiver logging command strings
unsigned char STR_LOG_OFF[] =   {"GPS:LOG OFF\n"};
unsigned char STR_LOG_GGA[] =   {"GPS:LOG GGA\n"};
unsigned char str_log_gsa[] =   {"GPS:LOG GSA\n"};
unsigned char str_log_gsv[] =   {"GPS:LOG GSV\n"};
unsigned char str_log_rmc[] =   {"GPS:LOG RMC\n"};
unsigned char str_log_vtg[] =   {"GPS:LOG VTG\n"};
unsigned char str_log_zda[] =   {"GPS:LOG ZDA\n"};


/******************************************************************************
****                                                                       ****
**                                                                           **
gps_led_off()
gps_led_on()
gps_led_flash()

**                                                                           **
****                                                                       ****
******************************************************************************/

void gps_led_gps(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_LED_GPS, sizeof(STR_LED_GPS)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_GPS_QA  "GPSRM LED (D2) now indicates power to GPS."); 
  }
} /* gps_led_gps() */


/******************************************************************************
****                                                                       ****
**                                                                           **
gps_pow_off()
gps_pow_on()

**                                                                           **
****                                                                       ****
******************************************************************************/
void gps_pow_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_POW_OFF, sizeof(STR_POW_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_GPS_QA  "Verify: TP41 (+5V_GPS) is 0V.");
    user_debug_msg(STR_TASK_GPS_QA  "Verify: TP42 (3V3_GPS) is 0V.");
  }
} /* gps_pow_off() */

void gps_pow_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_POW_ON, sizeof(STR_POW_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_GPS_QA  "Verify: TP41 (+5V_GPS) is +5.0V.");
    user_debug_msg(STR_TASK_GPS_QA  "Verify: TP42 (3V3_GPS) is +3.3V.");
  }
} /* gps_pow_on() */


/******************************************************************************
****                                                                       ****
**                                                                           **
gps_res_off()
gps_res_on()

**                                                                           **
****                                                                       ****
******************************************************************************/
void gps_res_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_RES_OFF, sizeof(STR_RES_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_GPS_QA  "OEM615 -RESET is inactive (i.e., HIGH).");
  }
} /* gps_res_off() */

void gps_res_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_RES_ON, sizeof(STR_RES_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_GPS_QA "OEM615 -RESET is active (i.e., LOW).");
  }
} /* gps_res_on() */


/******************************************************************************
****                                                                       ****
**                                                                           **
gps_pass_off()
gps_pass_on()

**                                                                           **
****                                                                       ****
******************************************************************************/
void gps_pass_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_PASS_OFF, sizeof(STR_PASS_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_GPS_QA  "OEM615 passthrough is disabled.");
  }
} /* gps_pass_off() */

void gps_pass_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_PASS_ON, sizeof(STR_PASS_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_GPS_QA "OEM615 passthrough is enabled.");
  }
} /* gps_pass_on() */


/******************************************************************************
****                                                                       ****
**                                                                           **
gps_log_off()
gps_log_gga()

**                                                                           **
****                                                                       ****
******************************************************************************/
void gps_log_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_LOG_OFF, sizeof(STR_LOG_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_GPS_QA  "OEM615 logging is disabled.");
  }
} /* gps_log_off() */

void gps_log_gga(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_LOG_GGA, sizeof(STR_LOG_GGA)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_GPS_QA  "OEM615 logging of GGA is enabled.");
  }
} /* gps_log_gga() */



/******************************************************************************
****                                                                       ****
**                                                                           **
task_gps()

Interfaces to the GPSRM 1 as part of test.


**                                                                           **
****                                                                       ****
******************************************************************************/
void task_gps_qa(void) {

  user_debug_msg(STR_TASK_GPS_QA  "Starting.");

#if 1
  // Init -- don't show messages yet
  gps_res_off(FALSE);
  gps_pow_off(FALSE);
  gps_pass_off(FALSE);
  gps_log_off(FALSE);

  // Instructions to technician
  user_debug_msg(STR_TASK_GPS_QA  "Note: Ref. designators are on GPSRM module!");
  user_debug_msg(STR_TASK_GPS_QA  "Plug: GPS antenna with MCX connector into\r\n\t\t\t\t GPSRM from below.");
  user_debug_msg(STR_TASK_GPS_QA  "Install: +5V_USB Interruptor onto Dev Board.");
  user_debug_msg(STR_TASK_GPS_QA  "Install: GPSRM onto +5V_USB Interruptor.");
  user_debug_msg(STR_TASK_GPS_QA  "Monitor: GPSRM via Pumpkin USB Debug Adapter.");


  // Verify GPS power can be forced ON and OFF. Requires that GPSRM be plugged into the bus such that
  //  it does not receive USB power ... easily done with an H1/H2 connector pair with H1.32 (+5V_USB) 
  //  cut off
  gps_led_gps(FALSE);
  gps_pow_on(TRUE);
  gps_res_off(FALSE);
  user_debug_msg(STR_TASK_GPS_QA  "Verify: GPSRM LED (D2) is ON."); 
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);

  gps_res_on(FALSE);
  gps_pow_off(TRUE);
  user_debug_msg(STR_TASK_GPS_QA  "Verify: GPSRM LED (D2) is OFF."); 
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);

  // OK, done with that, continue with GPS powered and indicated.
  gps_res_off(FALSE);
  gps_pow_on(FALSE);
  gps_led_gps(TRUE);

  // Verify that the -RESET signal can be used to force the OEM615 into reset ...
  //  (Cover must not be on OEM615 during this test).
  gps_res_on(TRUE);
  user_debug_msg(STR_TASK_GPS_QA  "Verify: OEM615 LED is RED.");
  OS_Delay(250); OS_Delay(250);

  gps_res_off(TRUE);
  user_debug_msg(STR_TASK_GPS_QA  "Verify: OEM615 LED is GREEN.");
  OS_Delay(250); OS_Delay(250);

#else
  // bypass for faster debugging
  gps_pow_on(TRUE);
  gps_res_off(TRUE);
  gps_log_off(FALSE);
#endif
  //gps_log_gga(TRUE);

  // Everything looks pretty good -- go ahead and let the OEM615 run without interference,
  //  so that it can acquire a lock. The direct USB connection to the OEM615 can be made at this time ...
  //user_debug_msg(STR_TASK_TEST "OEM615 will now acquire GPS satellites ...");
  //user_debug_msg(STR_TASK_TEST "Connect NovAtel CDU software to GPSRM\r\n\t\t\t\t via GPS (micro) USB connector.");
  gps_pass_on(TRUE);

  user_debug_msg(STR_TASK_GPS_QA  "Connect: CLK Out (J6) to freq. counter.");
  user_debug_msg(STR_TASK_GPS_QA  "Connect: PPS Out (J7) to oscilloscope.");
  user_debug_msg(STR_TASK_GPS_QA  "Connect: VARF Out (J8) to oscilloscope.");


  // Now we're ready to see if GPS is talking ...
  // Firmware update to GPSRM 1 Rev C should allow us to know when lock has been achieved ...
  OSStartTask(TASK_MONITOR_P);

  user_debug_msg(STR_TASK_GPS_QA  "Record: Max. frequency of CLK Out (J6).");

  while(1) { 
    OS_Delay(250);

    // Hit it with a burst of commands, just to exercise the counters ...
    /* aek 20141027
    gps_led_on(FALSE);
    gps_led_gps(FALSE);
    gps_led_on(FALSE);
    gps_led_gps(FALSE);
    */
  }
} /* task_gps_qa() */


