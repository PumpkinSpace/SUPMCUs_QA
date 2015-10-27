
/******************************************************************************
(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Author: SB
$Revision: 0.1 $
$Date: 2015-10-27 9:46:02-08 $

******************************************************************************/
#include "main.h"
#include "events.h"
#include "task_bim_qa.h"
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

// BIM tini commands
unsigned char STR_TINI_DIS[]    =   {"BIM:TINI DISA\n"};
unsigned char STR_TINI_ENAB[]   =   {"BIM:TINI ENAB\n"};
unsigned char STR_TINI_ARM[]    =   {"BIM:TINI ARM\n"};
unsigned char STR_TINI_UNARM[]  =   {"BIM:TINI UNAR\n"};

// BIM uart commands
unsigned char STR_UART1_ON[]    =   {"BIM:UARTPOW ON,1\n"};
unsigned char STR_UART1_OFF[]   =   {"BIM:UARTPOW OFF,1\n"};
unsigned char STR_UART2_ON[]    =   {"BIM:UARTPOW ON,2\n"};
unsigned char STR_UART2_OFF[]   =   {"BIM:UARTPOW OFF,2\n"};
unsigned char STR_UART3_ON[]    =   {"BIM:UARTPOW ON,3\n"};
unsigned char STR_UART3_OFF[]   =   {"BIM:UARTPOW OFF,3\n"};

// BIM ethernet commands
unsigned char STR_ETH1_ON[]     =   {"BIM:ETH:POW ON,1\n"};
unsigned char STR_ETH1_OFF[]    =   {"BIM:ETH:POW OFF,1\n"};
unsigned char STR_ETH2_ON[]     =   {"BIM:ETH:POW ON,2\n"};
unsigned char STR_ETH2_OFF[]    =   {"BIM:ETH:POW OFF,2\n"};
unsigned char STR_ETH3_ON[]     =   {"BIM:ETH:POW ON,3\n"};
unsigned char STR_ETH3_OFF[]    =   {"BIM:ETH:POW OFF,3\n"};
unsigned char STR_ETH_RES[]     =   {"BIM:ETH:RES ON\n"};
unsigned char STR_ETH_MODEOFF[] =   {"BIM:ETH:MODE OFF\n"};
unsigned char STR_ETH_MODE1[]   =   {"BIM:ETH:MODE 1\n"};
unsigned char STR_ETH_MODE0[]   =   {"BIM:ETH:MODE 0\n"};
unsigned char STR_ETH_MODE2[]   =   {"BIM:ETH:MODE 2\n"};
unsigned char STR_ETH_MODE3[]   =   {"BIM:ETH:MODE 3\n"};
unsigned char STR_ETH_I2CON[]   =   {"BIM:ETH:I2C ENAB\n"};
unsigned char STR_ETH_I2COFF[]  =   {"BIM:ETH:I2C DIS\n"};

// BIM temp sensors commands
unsigned char STR_TEMP_ON[]     =   {"BIM:TEMP:POWer ON\n"};
unsigned char STR_TEMP_OFF[]    =   {"BIM:TEMP:POWer OFF\n"};
unsigned char STR_TTEST_ON[]    =   {"BIM:TEMP:TEST START\n"};
unsigned char STR_TTEST_OFF[]   =   {"BIM:TEMP:TEST STOP\n"};
unsigned char STR_TTEST_RES[]   =   {"BIM:TEMP:TEST RESTART\n"};

// BIM EEPROM commands
unsigned char STR_EE_I2CON[]    =   {"BIM:EEprom:I2C DIS\n"};
unsigned char STR_EE_I2COFF[]   =   {"BIM:EEprom:I2C ENAB\n"};

// BIM SKycube commands
unsigned char STR_SKY_ON[]      =   {"BIM:SKYcube ON\n"};
unsigned char STR_SKY_OFF[]     =   {"BIM:SKYcube OFF\n"};

// BIM IMU commands
unsigned char STR_IMU_ON[]      =   {"BIM:IMU:POWer ON\n"};
unsigned char STR_IMU_OFF[]     =   {"BIM:IMU:POWer OFF\n"};

// BIM watchdog timer reset command
unsigned char STR_WDT_RES[]     =   {"BIM:WDT FORce\n"};


/******************************************************************************
****                                                                       ****
**                                                                           **
bim_tini_dis(unsigned int);
bim_tini_enab(unsigned int);
bim_tini_arm(unsigned int);
bim_tini_unarm(unsigned int);

**                                                                           **
****                                                                       ****
******************************************************************************/

void bim_tini_enab(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_TINI_ENAB, sizeof(STR_TINI_ENAB)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "BIM TiNi enable."); 
  }
} 

void bim_tini_dis(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_TINI_DIS, sizeof(STR_TINI_DIS)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "BIM TiNi disable."); 
  }
} 

void bim_tini_arm(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_TINI_ARM, sizeof(STR_TINI_ARM)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "BIM TiNi arm."); 
  }
} 

void bim_tini_unarm(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_TINI_UNARM, sizeof(STR_TINI_UNARM)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "BIM TiNi unarm."); 
  }
} 

/******************************************************************************
****                                                                       ****
**                                                                           **
bim_uart1_on(unsigned int);
bim_uart1_off(unsigned int);
bim_uart2_on(unsigned int);
bim_uart2_off(unsigned int);
bim_uart3_on(unsigned int);
bim_uart3_off(unsigned int);
**                                                                           **
****                                                                       ****
******************************************************************************/

void bim_uart1_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_UART1_ON, sizeof(STR_UART1_ON)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "BIM UART 1 turn ON."); 
  }
} 

void bim_uart1_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_UART1_OFF, sizeof(STR_UART1_OFF)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "BIM UART1 turn OFF."); 
  }
} 

void bim_uart2_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_UART2_ON, sizeof(STR_UART2_ON)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "BIM UART 2 turn ON."); 
  }
} 

void bim_uart2_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_UART2_OFF, sizeof(STR_UART2_OFF)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "BIM UART1 turn OFF."); 
  }
} 
void bim_uart3_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_UART3_ON, sizeof(STR_UART3_ON)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "BIM UART 3 turn ON."); 
  }
} 

void bim_uart3_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_UART3_OFF, sizeof(STR_UART3_OFF)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "BIM UART3 turn OFF."); 
  }
} 

/******************************************************************************
****                                                                       ****
**                                                                           **
bim_eth1_on(unsigned int);
bim_eth1_off(unsigned int);
bim_eth2_on(unsigned int);
bim_eth2_off(unsigned int);
bim_eth3_on(unsigned int);
bim_eth3_off(unsigned int);
bim_eth_res(unsigned int);
bim_eth_switch_mode(unsigned int);
bim_eth_i2c_on(unsigned int);
bim_eth_i2c_off(unsigned int);

**                                                                           **
****                                                                       ****
******************************************************************************/
void bim_eth1_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH1_ON, sizeof(STR_ETH1_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet turn on, 1.0V supply.");
  }
} 

void bim_eth1_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH1_OFF, sizeof(STR_ETH1_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet turn off, 1.0V supply.");
  }
} 

void bim_eth2_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH2_ON, sizeof(STR_ETH2_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet turn on, 1.8V supply.");
  }
} 

void bim_eth2_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH2_OFF, sizeof(STR_ETH2_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet turn off, 1.8V supply.");
  }
} 

void bim_eth3_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH3_ON, sizeof(STR_ETH3_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet turn on, 3.3V supply.");
  }
} 

void bim_eth3_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH3_OFF, sizeof(STR_ETH3_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet turn off, 3.3V supply.");
  }
} 

void bim_eth_i2c_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH_I2CON, sizeof(STR_ETH_I2CON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet I2C turn ON.");
  }
} 

void bim_eth_i2c_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH_I2COFF, sizeof(STR_ETH_I2COFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet I2C turn OFF.");
  }
} 

void bim_eth_res(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH_RES, sizeof(STR_ETH_RES)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet resetting now...");
  }
} 

void bim_eth_mode1(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH_MODE1, sizeof(STR_ETH_MODE1)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet mode 1 turn on.");
  }
} 

void bim_eth_mode0(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH_MODE0, sizeof(STR_ETH_MODE0)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet mode 0 turn on.");
  }
} 

void bim_eth_mode2(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH_MODE2, sizeof(STR_ETH_MODE2)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet mode 2 turn on.");
  }
} 

void bim_eth_mode3(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH_MODE3, sizeof(STR_ETH_MODE3)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet mode 3 turn on.");
  }
} 

void bim_eth_mode_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_ETH_MODEOFF, sizeof(STR_ETH_MODEOFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Ethernet modes turned off.");
  }
} 
/******************************************************************************
****                                                                       ****
**                                                                           **
 bim_temp_on(unsigned int);
 bim_temp_off(unsigned int);
 bim_ttest_on(unsigned int);
 bim_ttest_off(unsigned int);

**                                                                           **
****                                                                       ****
******************************************************************************/
void bim_temp_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_TEMP_ON, sizeof(STR_TEMP_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Temperature sensors turning on.");
  }
} 

void bim_temp_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_TEMP_OFF, sizeof(STR_TEMP_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Temperature sensors turning off.");
  }
} 

void bim_ttest_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_TTEST_ON, sizeof(STR_TTEST_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Run temperature test task.");
  }
} 

void bim_ttest_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_TTEST_OFF, sizeof(STR_TTEST_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "End temperature test task.");
  }
} 

/******************************************************************************
****                                                                       ****
**                                                                           **
bim_ee_i2c_on(unsigned int);
bim_ee_i2c_off(unsigned int);
**                                                                           **
****                                                                       ****
******************************************************************************/
void bim_ee_i2c_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_EE_I2CON, sizeof(STR_EE_I2CON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "EEPROM I2C is turning ON.");
  }
} 

void bim_ee_i2c_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_EE_I2COFF, sizeof(STR_EE_I2COFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "EEPROM I2C is turning OFF.");
  }
} 

/******************************************************************************
****                                                                       ****
**                                                                           **
bim_sky_on(unsigned int);
bim_sky_off(unsigned int);
**                                                                           **
****                                                                       ****
******************************************************************************/

void bim_sky_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_SKY_ON, sizeof(STR_SKY_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Skycube is turned ON.");
  }
} 

void bim_sky_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_SKY_OFF, sizeof(STR_SKY_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Skycube is turned OFF.");
  }
} 

/******************************************************************************
****                                                                       ****
**                                                                           **
bim_imu_on(unsigned int);
bim_imu_off(unsigned int);
**                                                                           **
****                                                                       ****
******************************************************************************/
void bim_imu_on(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_IMU_ON, sizeof(STR_IMU_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "IMU is turned ON.");
  }
} 

void bim_imu_off(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_IMU_OFF, sizeof(STR_IMU_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "IMU is turned OFF.");
  }
} 

/******************************************************************************
****                                                                       ****
**                                                                           **
bim_wdt_force(unsigned int);
**                                                                           **
****                                                                       ****
******************************************************************************/

void bim_wdt_force(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_WDT_RES, sizeof(STR_WDT_RES)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_BIM_QA  "Forcing WDT reset...");
  }
} 


/******************************************************************************
****                                                                       ****
**                                                                           **
task_gps()

Interfaces to the GPSRM 1 as part of test.


**                                                                           **
****                                                                       ****
******************************************************************************/
void task_bim_qa(void) {

  user_debug_msg(STR_TASK_BIM_QA  "Starting.");

#if 1
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
 
  // Init everything -- don't show messages yet
  bim_tini_dis(FALSE);
  bim_uart1_off(FALSE);
  bim_uart2_off(FALSE);
  bim_uart3_off(FALSE);
  bim_eth1_off(FALSE);
  bim_eth2_off(FALSE);
  bim_eth3_off(FALSE);
  bim_eth_mode_off(FALSE);
  bim_eth_i2c_off(FALSE);
  bim_temp_off(FALSE);
  bim_ttest_off(FALSE);
  bim_ee_i2c_off(FALSE);
  bim_sky_off(FALSE);
  bim_imu_off(FALSE);
 

  // Instructions to technician
  user_debug_msg(STR_TASK_BIM_QA  "Connect: Skycube, Ethernet switch and temperature sensors to the BIM for verification.");
  user_debug_msg(STR_TASK_BIM_QA  "Monitor: BIM via Pumpkin USB Debug Adapter.");

  // Verify the UART1 connection - 5V supply and LED3
  user_debug_msg(STR_TASK_BIM_QA  "Verify: 5V power supply available.");
  bim_uart1_on(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: LED3 is ON.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: LED3 is OFF.");
  
  // Verify VBATT available as power source and enable through UART2 - check LED2
  user_debug_msg(STR_TASK_BIM_QA  "Verify: VBATT available.");
  bim_uart2_on(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: LED2 is ON.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_uart2_off(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: LED2 is OFF.");
  
    // Verify Skycube (UART3) interface and LED6
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Skycube is connected.");
  bim_sky_on(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Skycube turned ON.");
  bim_uart3_on(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: LED6 is ON.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_uart3_off(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: LED6 is OFF.");
  bim_sky_off(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Skycube turned OFF.");
  
  // Verify temperature sensors
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Temperature sensors are connected.");
  bim_ttest_on(TRUE);
  bim_temp_on(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Task_temp outputs room temperatures.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_temp_off(TRUE);
  bim_ttest_off(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Task_temp stopped.");

  // Verify TiNi
  user_debug_msg(STR_TASK_BIM_QA  "Verify: LED5 is OFF.");
  bim_tini_enab(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: LED5 is orange.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_tini_dis(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: LED5 is OFF.");
  
  // Verify IMU
  user_debug_msg(STR_TASK_BIM_QA  "Verify: IMU is connected.");
  bim_imu_on(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: IMU is on.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_imu_off(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: IMU is off.");
  
  // Verify the ethernet commands
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Ethernet switch is installed.");
  OS_Delay(250); OS_Delay(250);
  bim_eth1_on(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Ethernet powered with 1.0V.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_eth1_off(TRUE);
  bim_eth2_on(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Ethernet powered with 1.8V.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_eth2_off(TRUE);
  bim_eth3_on(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Ethernet powered with 3.3V.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_eth3_off(TRUE);
  
  // switching ethernet modes
  OS_Delay(250); OS_Delay(250);
  bim_eth_mode0(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Ethernet mode0 active.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_eth_mode_off(FALSE);
  bim_eth_mode1(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Ethernet mode1 active.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_eth_mode_off(FALSE);
  bim_eth_mode2(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Ethernet mode2 active.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_eth_mode_off(TRUE);
  bim_eth_mode3(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Ethernet mode3 active.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_eth3_off(TRUE);
  bim_eth_mode_off(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: Ethernet modes OFF.");
  
  
  // Verify EEPROM commands
  bim_ee_i2c_on(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: EEPROM I2C active.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);
  bim_ee_i2c_off(TRUE);
  user_debug_msg(STR_TASK_BIM_QA  "Verify: EEPROM I2C disabled.");
  
#endif
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


