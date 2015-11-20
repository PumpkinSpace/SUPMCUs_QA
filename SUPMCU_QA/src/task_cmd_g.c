#include "main.h"
#include "events.h"


// Pumpkin CubeSat Kit headers
#include "csk_hw.h"
#include "csk_i2c.h"
#include "csk_serial.h"
#include "csk_uart.h"
#include "csk_wdt.h"

#include "task_supmcu_qa.h"
#include "task_gps_qa.h"
#include "task_bim_qa.h"
#include "task_pim_qa.h"

#include "salvo.h"
#include "config.h"
#include "events.h"
#include "tasks.h"
#include "task_cmd.h"

#include <ctype.h>


/************************************************************
****                                                     ****
**                                                         **
void TaskDoCmds()

a: toggle ACLK output (P2.0) on/off
h: help
i: toggle Exercise I/O task on/off
m: cycle between various MCLK output settings
t: display on-chip temperature
z: go to sleep



**                                                         **
****                                                     ****
************************************************************/
void   cmd_explain ( void ) {
  user_debug_msg(STR_CMD_EXPLAIN "Commands: {h|?, f, r, v, b, p ,g, t|y|u|i|o|p, 0-9|x}"); 
  printf("\t\t\t\th|?: this help screen.\r\n");
  printf("\t\t\t\tf:   finish test.\r\n");
  printf("\t\t\t\tr:   restart application.\r\n");
  printf("\t\t\t\tv:   display firmware version.\r\n");
  printf("\t\t\t\tb:   Start QA for all boards simultaneously.\r\n");
  printf("\t\t\t\tb:   Start BIM QA.\r\n");
  printf("\t\t\t\tp:   Start PIM QA.\r\n");
  printf("\t\t\t\tg:   Start GPSRM QA.\r\n");
  printf("\t\t\t\ts:   Start SIM QA.\r\n");
  printf("\t\t\t\tt:   disable all OEM615 COM1 logging.\r\n");
  printf("\t\t\t\ty:   enable OEM615 COM1 GGA logging.\r\n");
  printf("\t\t\t\tu:   enable OEM615 COM1 GSA logging.\r\n");
  printf("\t\t\t\ti:   enable OEM615 COM1 GSV logging.\r\n");
  printf("\t\t\t\to:   enable OEM615 COM1 RMC logging.\r\n");
  printf("\t\t\t\tl:   enable OEM615 COM1 VTG logging.\r\n");
  printf("\t\t\t\t0:   select Sup MCU CLK Out div = 2^0.\r\n");
  printf("\t\t\t\t1:   select Sup MCU CLK Out div = 2^1.\r\n");
  printf("\t\t\t\t2:   select Sup MCU CLK Out div = 2^2.\r\n");
  printf("\t\t\t\t3:   select Sup MCU CLK Out div = 2^3.\r\n");
  printf("\t\t\t\t4:   select Sup MCU CLK Out div = 2^4.\r\n");
  printf("\t\t\t\t5:   select Sup MCU CLK Out div = 2^5.\r\n");
  printf("\t\t\t\t6:   select Sup MCU CLK Out div = 2^6.\r\n");
  printf("\t\t\t\t7:   select Sup MCU CLK Out div = 2^7.\r\n");
  printf("\t\t\t\t8:   select Sup MCU CLK Out div = 2^8.\r\n");
  printf("\t\t\t\t9:   select Sup MCU CLK Out div = 2^9.\r\n");
  printf("\t\t\t\tx:   disable Sup MCU CLK Out.\r\n");
  printf("\r\n");
}

void task_cmd_do(void) {
  unsigned char cmd;
  
  user_debug_msg(STR_TASK_CMD_DO "Starting.");
  user_debug_msg(STR_CMD_EXPLAIN "Commands: {h|?, f, r, v, t|y|u|i|o|p, 0-9|x}"); 
  
  for (;;) {
  
    OS_WaitSem(SEM_CMD_CHAR_P, OSNO_TIMEOUT);
    
    
    if ((cmd = csk_uart0_getchar())) {
    
      switch (tolower(cmd)){
           
        // Help
        case 'h':
        case '?':
          cmd_explain();
          break;     

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          sup_clk_on(TRUE, tolower(cmd)-'0');
          break;
          
        case 'j':
         //   I2C_ADDR = 0x52;
            MODULE = GPS;
            //sprintf(strTmp, "task_cmd_do:   Sending to I2C addresses: 0x%x, 0x%x, 0x%x, 0x%x", I2C_ADDR.b,I2C_ADDR.g,I2C_ADDR.p,I2C_ADDR.s);
            user_debug_msg(strTmp);
            user_debug_msg(STR_TASK_CMD_DO "s: Selftest telemetry.");
            OS_Delay(150);
            OSStartTask(TASK_TELEMETRY_P);
            break;    
          
        case 'a':
         //   I2C_ADDR = 0x52;
            MODULE = ALL;
            //sprintf(strTmp, "task_cmd_do:   Sending to I2C addresses: 0x%x, 0x%x, 0x%x, 0x%x", I2C_ADDR.b,I2C_ADDR.g,I2C_ADDR.p,I2C_ADDR.s);
            user_debug_msg(strTmp);
            user_debug_msg(STR_TASK_CMD_DO "a: Starting QA.");
            OS_Delay(150);
            OSStartTask(TASK_SUPMCU_QA_P);
            break;  

        case 'b':
         //   I2C_ADDR = 0x52;
            MODULE = BIM;
            //sprintf(strTmp, "task_cmd_do:   Sending to I2C address 0x%x", I2C_ADDR.b);
            user_debug_msg(strTmp);
            user_debug_msg(STR_TASK_CMD_DO "b: Starting BIM QA.");
            OS_Delay(150);
            OSStartTask(TASK_SUPMCU_QA_P);
            break;
        
        case 'g':
           // I2C_ADDR = 0x51;
            MODULE = GPS;
            //sprintf(strTmp,  "task_cmd_do:   Sending to I2C address 0x%x", I2C_ADDR.g);
            user_debug_msg(strTmp);
            user_debug_msg(STR_TASK_CMD_DO "g: Starting GPSRM QA.");
            OS_Delay(150);
            OSStartTask(TASK_SUPMCU_QA_P);
            break;
        
        case 'p':
          //  I2C_ADDR = 0x53;
            MODULE = PIM;
            //sprintf(strTmp, "task_cmd_do:   Sending to I2C address 0x%x", I2C_ADDR.p);
            user_debug_msg(strTmp);
            user_debug_msg(STR_TASK_CMD_DO "p: Starting PIM QA.");
            OS_Delay(150);
            OSStartTask(TASK_SUPMCU_QA_P);
            break;
            
        case 's':
          //  I2C_ADDR = 0x50;
            MODULE = SIM;
            //sprintf(strTmp, "task_cmd_do:   Sending to I2C address 0x%x", I2C_ADDR.s);
            user_debug_msg(strTmp);
            user_debug_msg(STR_TASK_CMD_DO "p: Starting SIM QA.");
            OS_Delay(150);
            OSStartTask(TASK_SUPMCU_QA_P);
            break;
         
        case 'x':
          sup_clk_off(TRUE);
          break;
        
        // Reset via WDT
        case 'r':
          user_debug_msg(STR_TASK_CMD_DO "r: Reset (via WDT) in 1 s.");
          OS_Delay(100);

          csk_wdt_force();
            
          // Avoid uncalled function warning by calling said fns here -- we're dead
          //  anyway (via WDT).
          while(1) { 
            OSSetTicks(0);
          }
          break;      
        
        
        // Display version.
        case 'v':
		  user_debug_msg(STR_TASK_CMD_DO "v: " STR_VERSION);
          break;

        // Finish test.
        // First, shut down the GPS receiver and stop trying to talk to it
       case 'f':
          user_debug_msg(STR_TASK_CMD_DO "f: Stop QA");
          OSStopTask(TASK_SUPMCU_QA_P);
          if (MODULE == 2)
              OSStopTask(TASK_BIM_QA_P);              
              
          else if (MODULE == 0)
              OSStopTask(TASK_SIM_QA_P);  
          
          else if(MODULE==3)
              OSStopTask(TASK_PIM_QA_P);
              
          else if (MODULE==1){
              // Stop all logging (not a bad idea before shutting down the OEM615)
              csk_uart1_puts("UNLOGALL COM1 TRUE\r\n");
              csk_uart2_puts("UNLOGALL COM1 TRUE\r\n");
              csk_uart3_puts("UNLOGALL COM1 TRUE\r\n");
              // Stop the two tasks that are actively engaged with the OEM615.
              OSStopTask(TASK_GPS_QA_P);
              OSStopTask(TASK_MONITOR_P);
              // Shut down power to the OEM615 ... lave the Sup. MCU LED on.
              gps_res_off(FALSE);
              gps_pow_off(FALSE);
              sup_led_off(FALSE);
              gps_pass_off(FALSE);
              gps_log_off(FALSE);
              sup_clk_off(FALSE);
              gps_res_on(FALSE); // This takes -RESET LOW, therefore minimizes
                                 //  voltages at OEM615 pins
                      user_debug_msg(STR_TASK_CMD_DO "f: Powered down OEM615.");
              printf("\t\t\t\tControl: Issue 'z' (sleep) command to GPSRM!\r\n");
              user_debug_msg(STR_TASK_CMD_DO "Record: Current from supply.");
              user_debug_msg(STR_TASK_CMD_DO "Record: GPS data.");
              user_debug_msg(STR_TASK_CMD_DO "Record: Number of commands GPSRM has processed.");
          }
          else
              break;

        // Cancel all OEM615 logging on COM1
        case 't':
          csk_uart1_puts("UNLOGALL COM1 TRUE\r\n");
          csk_uart2_puts("UNLOGALL COM1 TRUE\r\n");
          csk_uart3_puts("UNLOGALL COM1 TRUE\r\n");
          user_debug_msg(STR_TASK_CMD_DO "t: All OEM615 logging canceled.");
          break;

        // Enable OEM615 GPGGA logging on COM1 @ 1Hz
        case 'y':
          csk_uart1_puts("LOG COM1 GPGGA ONTIME 1\r\n");
          csk_uart2_puts("LOG COM1 GPGGA ONTIME 1\r\n");
          csk_uart3_puts("LOG COM1 GPGGA ONTIME 1\r\n");
          user_debug_msg(STR_TASK_CMD_DO "y: OEM615 GGA logging enabled.");
          break;

        // Enable OEM615 GPGSA logging on COM1 @ 1Hz
        case 'u':
          csk_uart1_puts("LOG COM1 GPGSA ONTIME 1\r\n");
          csk_uart2_puts("LOG COM1 GPGSA ONTIME 1\r\n");
          csk_uart3_puts("LOG COM1 GPGSA ONTIME 1\r\n");
          user_debug_msg(STR_TASK_CMD_DO "u: OEM615 GSA logging enabled.");
          break;

        // Enable OEM615 GPGSV logging on COM1 @ 1Hz
        case 'i':
          csk_uart1_puts("LOG COM1 GPGSV ONTIME 1\r\n");
          csk_uart2_puts("LOG COM1 GPGSV ONTIME 1\r\n");
          csk_uart3_puts("LOG COM1 GPGSV ONTIME 1\r\n");
          user_debug_msg(STR_TASK_CMD_DO "i: OEM615 GSV logging enabled.");
          break;

        // Enable OEM615 GPRMC logging on COM1 @ 1Hz
        case 'o':
          csk_uart1_puts("LOG COM1 GPRMC ONTIME 1\r\n");
          csk_uart2_puts("LOG COM1 GPRMC ONTIME 1\r\n");
          csk_uart3_puts("LOG COM1 GPRMC ONTIME 1\r\n");
          user_debug_msg(STR_TASK_CMD_DO "o: OEM615 RMC logging enabled.");
          break;

        // Enable OEM615 GPVTG logging on COM1 @ 1Hz
        case 'l':
          csk_uart1_puts("LOG COM1 GPVTG ONTIME 1\r\n");
          csk_uart2_puts("LOG COM1 GPVTG ONTIME 1\r\n");
          csk_uart3_puts("LOG COM1 GPVTG ONTIME 1\r\n");
          user_debug_msg(STR_TASK_CMD_DO "l: OEM615 VTG logging enabled.");
          break;
               
        default:
          sprintf(strTmp, STR_TASK_CMD_DO "Unknown command: '%c' (0x%X).", cmd, cmd);
		      user_debug_msg(strTmp);
          break;

      }
    }
  }
}

