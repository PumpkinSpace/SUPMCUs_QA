#include <stdio.h>
#include <stdint.h>

#include "telemetry.h"

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


// enough to hold the largest telemetry data
#define SCPI_CMD_BUFFER_LEN     256
static unsigned char TEL_DATA[SCPI_CMD_BUFFER_LEN];
//OS_WaitBinSem(BINSEM_SCPI_RCVD_P, OSNO_TIMEOUT); 
/************* Send telemetry requests and read the data***********/

// request selftest results
unsigned char STR_SELFTEST_TEL  []      =   {"SUP:TEL? 4,data\n"};
unsigned char STR_SELFTEST_START[]      =   {"SUP:SELF START\n"};



void supmcu_selftest_start(unsigned int show) {
  i2c1_write(I2C_ADDR.g, STR_SELFTEST_START, sizeof(STR_SELFTEST_START)-1); 
  if(show) { 
    user_debug_msg(STR_TELEMETRY_QA  "Starting selftests. Please wait until all 6 tests are run."); 
  }
} 

void supmcu_selftest_tel(unsigned int show) {
  i2c1_write(I2C_ADDR.g, STR_SELFTEST_TEL, sizeof(STR_SELFTEST_TEL)-1); 
  if(show) { 
    user_debug_msg(STR_TELEMETRY_QA  "Getting Selftest results."); 
  }
} 


void task_telemetry(void){
    OS_Stop();
   user_debug_msg(STR_TELEMETRY_QA  "Starting.");
   
   #if 1
  OS_Delay(250);
    // structure that will contain the results
    typedef struct{
        uint64_t passed;    
        uint64_t failed;
        uint16_t test_num;      // Last test number 
        uint16_t failed_num;        
        uint16_t failed_res; // Non-zero when/if test fails
    }selftest_res_t;

    selftest_res_t test;

    //unsigned char TestData[sizeof(selftest_res)+13];
    
    supmcu_selftest_start(TRUE);
    OS_Delay(250); 
    
    supmcu_selftest_tel(TRUE);
    
    i2c1_read(I2C_ADDR.g, &TEL_DATA[0], sizeof(test)+13);
    memcpy(&test.passed, &TEL_DATA[5],sizeof(uint64_t));
    memcpy(&test.failed, &TEL_DATA[5+8],sizeof(uint64_t));
    memcpy(&test.test_num, &TEL_DATA[5+8+8],sizeof(uint16_t));
    memcpy(&test.failed_num, &TEL_DATA[5+8+8+2],sizeof(uint16_t));
    memcpy(&test.failed_res, &TEL_DATA[5+8+8+2+2],sizeof(uint16_t));   
    //sprintf(strTmp,"pass %llu ; fail %llu; num %u; num_fail %u; res_fail %u",test.passed,test.failed, test.test_num, test.failed_num,test.failed_res);
    //user_debug_msg(strTmp);
    
    if(test.failed == 0){
        sprintf(strTmp,"All selftests passed");
        user_debug_msg(STR_TELEMETRY_QA "All selftests passed");
    }
    else{
        sprintf(strTmp,STR_TELEMETRY_QA "Failed %llu tests, last failed %u",test.failed,test.failed_num);
        user_debug_msg(strTmp);
    }
 
 while(1) { 
    OS_Delay(250);
 }
#endif
    
}