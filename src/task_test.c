/******************************************************************************
(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source: C:\\RCS\\D\\Pumpkin\\CubeSatKit\\Example\\PIC24\\PIC24FJ256GA110\\CubeSat_Kit_Dev_Board\\Test\\Test1\\init.c,v $
$Author: aek $
$Revision: 3.3 $
$Date: 2010-02-19 19:01:02-08 $

******************************************************************************/
#include "main.h"
#include "events.h"
#include "task_test.h"

// Pumpkin CubeSat Kit headers
//#include "csk_hw.h"
//#include "csk_serial.h"
#include "csk_uart.h"

// Pumpkin PIC24 Library.
#include "pic24_i2c.h"

// Pumpkin Salvo RTOS.
#include "salvo.h"
#include "tasks.h"


// GPSRM 1's I2C address 
#define GPS_SMB_ADDR 0x51

// Note that we only send the string up to the LF (and not the terminating NULL), 
//  therefore the -1 adjust to sizeof(string).
// Supervisor MCU LED command strings
unsigned char STR_LED_ON[] =    {"SUP:LED ON\n"};
unsigned char STR_LED_OFF[] =   {"SUP:LED OFF\n"};
unsigned char STR_LED_FLASH[] = {"SUP:LED FLASh\n"};
unsigned char STR_LED_GPS[] =   {"SUP:LED GPS\n"};

// Supervisor MCU CLK Out command strings
// Default (roughly) (Internal) clock speed for PIC24EP256MC206
#define MCLK 7372800L
unsigned char STR_CLK_OFF[] =   {"SUP:CLOCk OFF\n"};
unsigned char STR_CLK_ON[] =    {"SUP:CLOCk ON,  0\n"};

// GPS (i.e., OEM615) receiver power command strings
unsigned char STR_POW_OFF[] =   {"GPS:POWer OFF\n"};
unsigned char STR_POW_ON[] =    {"GPS:POWer ON\n"};

// GPS (i.e., OEM615) receiver reset command strings
unsigned char STR_RES_OFF[] =   {"GPS:RESet OFF\n"};
unsigned char STR_RES_ON[] =    {"GPS:RESet ON\n"};

// GPS (i.e., OEM615) receiver passthrough command strings
unsigned char STR_PASS_OFF[] =  {"GPS:PASS OFF\n"};
unsigned char STR_PASS_ON[] =   {"GPS:PASS ON\n"};

// GPS (i.e., OEM615) receiver logging command strings
unsigned char STR_LOG_OFF[] =   {"GPS:LOG OFF\n"};
unsigned char STR_LOG_GGA[] =   {"GPS:LOG GGA\n"};
unsigned char str_log_gsa[] =   {"GPS:LOG GSA\n"};
unsigned char str_log_gsv[] =   {"GPS:LOG GSV\n"};
unsigned char str_log_rmc[] =   {"GPS:LOG RMC\n"};
unsigned char str_log_vtg[] =   {"GPS:LOG VTG\n"};


/******************************************************************************
****                                                                       ****
**                                                                           **
recursive unsigned integer exponentiation (i.e., power) function.

From http://stackoverflow.com/questions/213042/how-do-you-do-exponentiation-in-c

**                                                                           **
****                                                                       ****
******************************************************************************/
unsigned int power(unsigned int x, unsigned int y){
  if(y == 0)
    return 1;
  return (x * power(x,y-1) );
}

/******************************************************************************
****                                                                       ****
**                                                                           **
gps_led_off()
gps_led_on()
gps_led_flash()

**                                                                           **
****                                                                       ****
******************************************************************************/
void gps_led_off(unsigned int show) {
  i2c1_write(GPS_SMB_ADDR, STR_LED_OFF, sizeof(STR_LED_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_TEST "Verify: Status LED (D2) is OFF."); 
  }
} /* gps_led_off() */

void gps_led_on(unsigned int show) {
  i2c1_write(GPS_SMB_ADDR, STR_LED_ON, sizeof(STR_LED_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_TEST "Verify: Status LED (D2) is ON.");
  }
} /* gps_led_on() */

void gps_led_flash(unsigned int show) {
  i2c1_write(GPS_SMB_ADDR, STR_LED_FLASH, sizeof(STR_LED_FLASH)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_TEST "Verify: Status LED (D2) is flashing."); 
  }
} /* gps_led_flash() */

void gps_led_gps(unsigned int show) {
  i2c1_write(GPS_SMB_ADDR, STR_LED_GPS, sizeof(STR_LED_GPS)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_TEST "Status LED (D2) now indicates power to GPS."); 
  }
} /* gps_led_gps() */


/******************************************************************************
****                                                                       ****
**                                                                           **
gps_sup_clk_off()
gps_sup_clk_on(divider)

**                                                                           **
****                                                                       ****
******************************************************************************/
void gps_sup_clk_off(unsigned int show) {
  i2c1_write(GPS_SMB_ADDR, STR_CLK_OFF, sizeof(STR_CLK_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_TEST "Verify: CLK Out (J6) is at        0Hz (off)");
  }
} /* gps_sup_clk_off() */

void gps_sup_clk_on(unsigned int show, unsigned int divider) {
  sprintf(STR_CLK_ON+14, "%2d\n", divider);
  i2c1_write(GPS_SMB_ADDR, STR_CLK_ON, sizeof(STR_CLK_ON)-1);
  if(show) { 
    sprintf(strTmp, STR_TASK_TEST "Verify: CLK Out (J6) at ca. %7ldHz (div=%2d)", MCLK/power(2,divider), divider);  
    user_debug_msg(strTmp);
  }
} /* gps_sup_clk_on() */


/******************************************************************************
****                                                                       ****
**                                                                           **
gps_pow_off()
gps_pow_on()

**                                                                           **
****                                                                       ****
******************************************************************************/
void gps_pow_off(unsigned int show) {
  i2c1_write(GPS_SMB_ADDR, STR_POW_OFF, sizeof(STR_POW_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_TEST "Verify: TP41 (+5V_GPS) is 0V.");
    user_debug_msg(STR_TASK_TEST "Verify: TP42 (3V3_GPS) is 0V.");
  }
} /* gps_pow_off() */

void gps_pow_on(unsigned int show) {
  i2c1_write(GPS_SMB_ADDR, STR_POW_ON, sizeof(STR_POW_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_TEST "Verify: TP41 (+5V_GPS) is +5.0V.");
    user_debug_msg(STR_TASK_TEST "Verify: TP42 (3V3_GPS) is +3.3V.");
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
  i2c1_write(GPS_SMB_ADDR, STR_RES_OFF, sizeof(STR_RES_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_TEST "OEM615 -RESET is inactive (i.e., HIGH).");
  }
} /* gps_res_off() */

void gps_res_on(unsigned int show) {
  i2c1_write(GPS_SMB_ADDR, STR_RES_ON, sizeof(STR_RES_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_TEST "OEM615 -RESET is active (i.e., LOW).");
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
  i2c1_write(GPS_SMB_ADDR, STR_PASS_OFF, sizeof(STR_PASS_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_TEST "OEM615 passthrough is disabled.");
  }
} /* gps_pass_off() */

void gps_pass_on(unsigned int show) {
  i2c1_write(GPS_SMB_ADDR, STR_PASS_ON, sizeof(STR_PASS_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_TEST "OEM615 passthrough is enabled.");
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
  i2c1_write(GPS_SMB_ADDR, STR_LOG_OFF, sizeof(STR_LOG_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_TEST "OEM615 logging is disabled.");
  }
} /* gps_log_off() */

void gps_log_gga(unsigned int show) {
  i2c1_write(GPS_SMB_ADDR, STR_LOG_GGA, sizeof(STR_LOG_GGA)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_TEST "OEM615 logging of GGA is enabled.");
  }
} /* gps_log_gga() */



/******************************************************************************
****                                                                       ****
**                                                                           **
task_test()

Interfaces to the GPSRM 1 as part of test.


**                                                                           **
****                                                                       ****
******************************************************************************/
void task_test(void) {
  static int i;


  user_debug_msg(STR_TASK_TEST "Starting.");

#if 1
  // Init -- don't show messages yet
  gps_res_off(FALSE);
  gps_pow_off(FALSE);
  gps_led_off(FALSE);
  gps_pass_off(FALSE);
  gps_log_off(FALSE);
  gps_sup_clk_off(FALSE);

  // Instructions to technician
  user_debug_msg(STR_TASK_TEST "Note: Ref. designators are on GPSRM module!");
  user_debug_msg(STR_TASK_TEST "Plug: GPS antenna with MCX connector into\r\n\t\t\t\t GPSRM from below.");
  user_debug_msg(STR_TASK_TEST "Install: +5V_USB Interruptor onto Dev Board.");
  user_debug_msg(STR_TASK_TEST "Install: GPSRM onto +5V_USB Interruptor.");
  user_debug_msg(STR_TASK_TEST "Remove: All jumpers on Pumpkin USB Debug\r\n\t\t\t\t Adapter.");
  user_debug_msg(STR_TASK_TEST "Monitor: GPSRM via Pumpkin USB Debug Adapter.");
  user_debug_msg(STR_TASK_TEST "Record: Minimum current from power supply.");

  // Verify Status LED can be OFF
  gps_led_off(TRUE);
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);

  // Verify Status LED can flash
  gps_led_flash(TRUE);
  OS_Delay(250); OS_Delay(250);

  // Verify Status LED can be ON
  gps_led_on(TRUE);
  OS_Delay(250); OS_Delay(250);


  // Verify GPS power can be forced ON and OFF. Requires that GPSRM be plugged into the bus such that
  //  it does not receive USB power ... easily done with an H1/H2 connector pair with H1.32 (+5V_USB) 
  //  cut off
  gps_led_gps(FALSE);
  gps_pow_on(TRUE);
  gps_res_off(FALSE);
  user_debug_msg(STR_TASK_TEST "Verify: Status LED (D2) is ON."); 
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);

  gps_res_on(FALSE);
  gps_pow_off(TRUE);
  user_debug_msg(STR_TASK_TEST "Verify: Status LED (D2) is OFF."); 
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);

  // OK, done with that, continue with GPS powered and indicated.
  gps_res_off(FALSE);
  gps_pow_on(FALSE);
  gps_led_gps(TRUE);

  // Verify that the -RESET signal can be used to force the OEM615 into reset ...
  //  (Cover must not be on OEM615 during this test).
  gps_res_on(TRUE);
  user_debug_msg(STR_TASK_TEST "Verify: OEM615 LED is RED.");
  OS_Delay(250); OS_Delay(250);

  gps_res_off(TRUE);
  user_debug_msg(STR_TASK_TEST "Verify: OEM615 LED is GREEN.");
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

  user_debug_msg(STR_TASK_TEST "Connect: CLK Out (J6) to freq. counter.");
  user_debug_msg(STR_TASK_TEST "Connect: PPS Out (J7) to oscilloscope.");
  user_debug_msg(STR_TASK_TEST "Connect: VARF Out (J8) to oscilloscope.");

  // Test CLK Out signal on GPSRM 1.
  // By doing this test now, after all the other stuff is done, it gives the OEM615
  //  a chance to lock to GPS while we're testing the CLK Out functionality ...
  #if 1
  // Verify CLK Out commands all work -- requires a frequency counter attached to J6 (Clk Out).
  OS_Delay(250); OS_Delay(250);

  // Verify that Clk Out is OFF (i.e., 0Hz).
  gps_sup_clk_off(TRUE);
   OS_Delay(150); OS_Delay(200); 

  // Verify that Clk Out works over the specified ranges.
  for(i=0; i<16; i++) {
   gps_sup_clk_on(TRUE, (15-i));
   OS_Delay(150); OS_Delay(200); 
  }
  // Leave clock at div=0 on so that Sup MCU's clock frequency can be recorded.
  #endif

  // Now we're ready to see if GPS is talking ...
  // Firmware update to GPSRM 1 Rev C should allow us to know when lock has been achieved ...
  OSStartTask(TASK_MONITOR_P);

  user_debug_msg(STR_TASK_TEST "Record: Max. frequency of CLK Out (J6).");

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
} /* task_test() */

