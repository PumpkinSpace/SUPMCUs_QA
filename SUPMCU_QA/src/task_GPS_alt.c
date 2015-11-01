#include "task_GPS.h"
#include "TAP.h"
#include "mailman.h"
#include "UART_CONFIG.h"
#include "io.h"
//#include "usci_a_uart.h"
typedef struct 
{
    uint8_t message_class;
    uint8_t message_id;
    uint16_t size;
} head_type;

head_type header;

void task_GPS(void) {
  user_debug_msg(DBG_MSG, STR_TASK_GPS ": Starting.");


  // With GPS silent, now it's time to initialize the NMEA buffer handler.
  gps_open();

  // Init all the variables we'll be reading from the GPS (e.g. longitude).
  gps_init();


  while (1) {
    gps_update();

    //Display current latitude, longitude, velocity and heading
    #if 1 
    sprintf(str_tmp, STR_TASK_GPS ": %09.2f,%9.4f,%10.4f,%6.1f,%6.1f,%4.1f,%7.3f,%7.2f,%7.2f,%u,%u,%u,%2X,%u,%u,%u,%u", 
                                  gps_read().time,gps_read().latitude,gps_read().longitude,gps_read().altitude,gps_read().geoid,
                                  gps_read().hdop,gps_read().speed,gps_read().heading,gps_read().mag_var,gps_read().num_sat,
                                  gps_read().stationID,gps_read().date,gps_read().fixflag,
                                  gps_read().rmc_update,gps_read().gga_update,gps_read().rmc_count,gps_read().gga_count);
    user_debug_msg(DBG_MSG, str_tmp);
    #endif 


    // Note that this is not in keeping with all the other TAPS -- this should be driven by TAP_delay, etc.
    OS_Delay(500);
  }
}
