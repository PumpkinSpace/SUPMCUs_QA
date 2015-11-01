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
#include "task_monitor.h"

// Pumpkin CubeSat Kit headers.
#include "csk_uart.h"

// Pumpkin Salvo RTOS.
#include "salvo.h"

// GPS-specific.
#include "gps_nmea.h"


/******************************************************************************
****                                                                       ****
**                                                                           **
task_monitor()

This task proves the proper functioning of the passthrough feature of the
GPSRM 1. Passthrough connects the OEM615V's COM1 port to one of three pairs
of IO lines on the CSK bus: IO.[5,4], IO.[17,16] or IO.[33,32]. Which pair
is implemented depends on the GPSRM 1's Assembly Revision (ASSY REV).

task_gps() initially configures the GPSRM 1 with passthrough enabled, but
without any logging active in the OEM615V.

task_monitor() (re-)starts once commanded to by task_gps() ... this happens
after all the basic tests (I2C working, can power OEM615V on and off) are 
concluded, the OEM615V is on and not in reset, and is ready to talk via COM1.

task_monitor() then commands the OEM615V to start logging, and then scans
the resulting NMEA strings from the OEM615V for valid GPS fix and GPS data.

**                                                                           **
****                                                                       ****
******************************************************************************/
void task_monitor(void) {

  // Initially we're stopped, waiting for task_gps to configure the GPSRM1 and OEM615V.
  user_debug_msg(STR_TASK_MONITOR "Stopped.");
  OS_Stop();

  // Eventually task_gps() starts this task.
  user_debug_msg(STR_TASK_MONITOR "Starting.");

  // With GPS silent, now it's time to initialize the NMEA buffer handler.
  gps_open();

  // Init all the variables we'll be reading from the GPS (e.g. longitude).
  gps_init();

  // Now that we're ready for NMEA messages from the OEM615V, tell it to 
  //  start logging them at 1Hz on its COM1.
  // We need to send this out to all three possible paths into the GPSRM 1's
  //  passthrough port.
  // Don't forget to terminate the string with CRLF!
  csk_uart1_puts("LOG COM1 GPGGA ONTIME 1\r\n");
  csk_uart2_puts("LOG COM1 GPGGA ONTIME 1\r\n");
  csk_uart3_puts("LOG COM1 GPGGA ONTIME 1\r\n");

  // Additionally, tell the OEM615V to output a pulsetrain (2ms @ 125kHz) via the VARF output
  csk_uart1_puts("FREQUENCYOUT ENABLE 200 800\r\n");
  csk_uart2_puts("FREQUENCYOUT ENABLE 200 800\r\n");
  csk_uart3_puts("FREQUENCYOUT ENABLE 200 800\r\n");

  // Wait a few seconds for the NMEA buffers to fill ...
  OS_Delay(200);
  OS_Delay(200);


  // We remain here forever, parsing NMEA strings from the OEM615 for GPS status
  //  and data. While this is happening (and after a GPS fix has been achieved),
  //  it's a good time to test disconnecting and reconnecting the GPS antenna from
  //  the OEM615V, to see that its GPS Position Valid LED goes out when the
  //  antenna is disconnected.
  while(1) { 
    // Update gps values from incoming NMEA strings.
    gps_update();

    // Display current sats in view, HDOP, altitude, latitude & longitude if we have a fix.
    if((gps_read().fixflag&gps_fix)||(gps_read().fixflag&diffgps_fix)) {
      sprintf(strTmp, STR_TASK_MONITOR "  GMT    Sat HDOP   Alt.   Latitude   Longitude\r\n" \
                               "\t\t\t\t-----------------------------------------------\r\n" \
                               "\t\t\t\t%s %02u  %3.1f %6.1fm  %8.4f %8.4f\r\n", 
                               gps_NMEA_GMT_time_hhmmss(), gps_read().num_sat, gps_read().hdop, gps_read().altitude, gps_read().latitude, gps_read().longitude);
    } /* if() */ 
    // O/wise indicate that we do not have a fix.   
    else {
      sprintf(strTmp, STR_TASK_MONITOR "No valid GPS position -- check antenna.\r\n");
    } /* else() */
    user_debug_msg(strTmp);

    // Repeat every 5s.
    OS_Delay(250);
    OS_Delay(250);
  } /* while() */

} /* task_monitor() */

