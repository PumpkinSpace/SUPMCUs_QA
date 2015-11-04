
/******************************************************************************
(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.
 
$Author: SB $
$Revision: 0.1 $
$Date: 2015-10-26 17:03:02-08 $

******************************************************************************/
#include "main.h"
#include "events.h"
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
// Supervisor MCU LED command strings
unsigned char STR_LED_ON[]      =   {"SUP:LED ON\n"};
unsigned char STR_LED_OFF[]     =   {"SUP:LED OFF\n"};
unsigned char STR_LED_FLASH[]   =   {"SUP:LED FLASh\n"};

// Supervisor MCU CLK Out command strings
// Default (roughly) (Internal) clock speed for PIC24EP256MC206
#define MCLK 7372800L
unsigned char STR_CLK_OFF[]     =    {"SUP:CLOCk OFF\n"};
unsigned char STR_CLK_ON[]      =    {"SUP:CLOCk ON,  0\n"};


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
void sup_led_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_LED_OFF, sizeof(STR_LED_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_SUPMCU_QA "Verify: Status LED (D2) is OFF."); 
  }
} /* gps_led_off() */

void sup_led_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_LED_ON, sizeof(STR_LED_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_SUPMCU_QA "Verify: Status LED (D2) is ON.");
  }
} /* gps_led_on() */

void sup_led_flash(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_LED_FLASH, sizeof(STR_LED_FLASH)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_SUPMCU_QA "Verify: Status LED (D2) is flashing."); 
  }
} /* gps_led_flash() */


/******************************************************************************
****                                                                       ****
**                                                                           **
sup_clk_off()
sup_clk_on(divider)

**                                                                           **
****                                                                       ****
******************************************************************************/
void sup_clk_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_CLK_OFF, sizeof(STR_CLK_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_SUPMCU_QA "Verify: CLK Out (J6) is at        0Hz (off)");
  }
} /* gps_sup_clk_off() */

void sup_clk_on(unsigned int show, unsigned int divider) {
  sprintf(STR_CLK_ON+14, "%2d\n", divider);
  i2c1_write(I2C_ADDR, STR_CLK_ON, sizeof(STR_CLK_ON)-1);
  if(show) { 
    sprintf(strTmp, STR_TASK_SUPMCU_QA "Verify: CLK Out (J6) at ca. %7ldHz (div=%2d)", MCLK/power(2,divider), divider);  
    user_debug_msg(strTmp);
  }
} /* gps_sup_clk_on() */

/******************************************************************************
****                                            
 ****
**                                                                           **
task_supmcu_qa()


**                                                                           **
****                                                                       ****
******************************************************************************/
void task_supmcu_qa(void) {
  static int i;
  //user_debug_msg(STR_TASK_SUPMCU_QA "Stopped.");
  OS_Stop();
  user_debug_msg(STR_TASK_SUPMCU_QA  "Starting.");

  //user_debug_msg(STR_TASK_SUPMCU_QA "Starting.");

#if 1
  // Init -- don't show messages yet
  //sup_led_off(FALSE);
  sup_clk_off(FALSE);

  // Instructions to technician
  user_debug_msg(STR_TASK_SUPMCU_QA "Note: Ref. designators are on GPSRM module!");
  user_debug_msg(STR_TASK_SUPMCU_QA "Remove: All jumpers on Pumpkin USB Debug\r\n\t\t\t\t Adapter.");
  user_debug_msg(STR_TASK_SUPMCU_QA "Monitor: SUPMCU via Pumpkin USB Debug Adapter.");
  user_debug_msg(STR_TASK_SUPMCU_QA "Record: Minimum current from power supply.");

  // Verify Status LED can be OFF
  sup_led_on(TRUE);
  OS_Delay(250); OS_Delay(250);

  // Verify Status LED can flash
  sup_led_flash(TRUE);
  OS_Delay(250); OS_Delay(250);

  // Verify Status LED can be ON
  sup_led_off(TRUE);
  OS_Delay(250); OS_Delay(250);

  sup_led_flash(TRUE);

  // Test CLK Out signal on GPSRM 1.
  // By doing this test now, after all the other stuff is done, it gives the OEM615
  //  a chance to lock to GPS while we're testing the CLK Out functionality ...
  // Verify CLK Out commands all work -- requires a frequency counter attached to J6 (Clk Out).
  OS_Delay(250); OS_Delay(250);

  // Verify that Clk Out is OFF (i.e., 0Hz).
  sup_clk_off(TRUE);
   OS_Delay(150); OS_Delay(200); 

   /***********************************************************************************/
   /**************************************************************************************/
   /***************************************************************************************/
   // CHANGE BACK TO I<16
  // Verify that Clk Out works over the specified ranges.
  for(i=0; i<2; i++) {  //i<16
   sup_clk_on(TRUE, (15-i));
   OS_Delay(150); OS_Delay(200); 
  }
  // Leave clock at div=0 on so that Sup MCU's clock frequency can be recorded.
  #endif


  user_debug_msg(STR_TASK_SUPMCU_QA "Record: Max. frequency of CLK Out (J6).");
  OS_Delay(250);
  
  
if (BOARD == 1)
    OSStartTask( TASK_GPS_QA_P);
else if (BOARD == 2)
    OSStartTask( TASK_BIM_QA_P);
else if (BOARD == 3)
    OSStartTask( TASK_PIM_QA_P);
//else if (BOARD == 4)
  //  OSStartTask( TASK_SIM_QA_P);
else
   user_debug_msg(STR_TASK_SUPMCU_QA "Unrecognized SUPMCU");

  while(1) { 
    OS_Delay(250);
  }
} /* task_supmcu_qa() */

