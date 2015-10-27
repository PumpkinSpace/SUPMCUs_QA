#include "main.h"
#include "events.h"


// Pumpkin CubeSat Kit headers
#include "csk_hw.h"
#include "csk_i2c.h"
#include "csk_serial.h"
#include "csk_uart.h"
#include "csk_wdt.h"

//#include "task_test.h"
#include "task_gps_qa.h"
#include "task_bim_qa.h"
#include "task_supmcu_qa.h"


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
  user_debug_msg(STR_CMD_EXPLAIN "Commands: {h|?, f, r, v, t|y|u|i|o|p, 0-9|x}"); 
  printf("\t\t\t\th|?: this help screen.\r\n");
  printf("\t\t\t\tf:   finish test.\r\n");
  printf("\t\t\t\tr:   restart application.\r\n");
  printf("\t\t\t\tv:   display firmware version.\r\n");
  printf("\t\t\t\tt:   disable all OEM615 COM1 logging.\r\n");
  printf("\t\t\t\ty:   enable OEM615 COM1 GGA logging.\r\n");
  printf("\t\t\t\tu:   enable OEM615 COM1 GSA logging.\r\n");
  printf("\t\t\t\ti:   enable OEM615 COM1 GSV logging.\r\n");
  printf("\t\t\t\to:   enable OEM615 COM1 RMC logging.\r\n");
  printf("\t\t\t\tp:   enable OEM615 COM1 VTG logging.\r\n");
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
                         
        default:
          sprintf(strTmp, STR_TASK_CMD_DO "Unknown command: '%c' (0x%X).", cmd, cmd);
		      user_debug_msg(strTmp);
          break;

      }
    }
  }
}

