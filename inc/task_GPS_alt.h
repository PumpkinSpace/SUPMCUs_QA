// MSP430-based project
#include <msp430.h>


// Rowley headers
#include <__cross_studio_io.h>

// C headers
#include <stdint.h>
#include <salvo.h>
//#include <ctype.h>

#include "i2c.h"
#include "UART1.h"



#include "user_debug.h"
#include "gps_nmea.h"
// Symbols, etc.
#define TimerA0_RELOAD        328
#define STR_1TAB              "\t"
#define STR_2TABS             "\t\t"
#define STR_CRLF              "\r\n"

#define   STR_TASK_GPS   "task_gps" 

//static uint8_t message_buffer[255];
static uint8_t nav_msg_count;

void task_GPS( void );
void decom_nav_message(uint8_t ID, uint8_t *message);
void decom_pos_llh( uint8_t *message );
void decom_time_utc(uint8_t *message);

void getPos(int32_t *lat, int32_t *lon, uint32_t *horz);
void getTime(int8_t* year, int8_t* month, int8_t* day, int8_t* hours, int8_t* mins, int8_t* sec);


