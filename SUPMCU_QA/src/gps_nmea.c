// C headers
#include <stdint.h>
#include <stdio.h>
#include "main.h"
#include "gps_nmea.h"

// Pumpkin CubeSat Kit headers
//#include "csk_hw.h"
//#include "csk_serial.h"
#include "csk_uart.h"

// Pumpkin PIC24 Library.
#include "pic24_i2c.h"

// Pumpkin Salvo RTOS.
#include "salvo.h"





   

#define NMEA_MAX_LENGTH     82    // 79 + '$', CR & LF
#define NMEA_BUFFERS        3

#define LENGTH              32    // length of binary init string

char NMEAStr[NMEA_BUFFERS][NMEA_MAX_LENGTH];
static char * srcP;




typedef struct {
  unsigned int enabled:1;    // for status
  unsigned int whichBuff:2;  // handle up to NMEA_BUFFERS of length NMEA_MAX_LENGTH
  unsigned int length:7;     // track chars into buffer -- max 128 bytes of NMEA data.
} type_gps_status;

static type_gps_status gps_status;
static type_gps_reading gps_reading;

/************************************************************
****                                                     ****
**                                                         **
gps_open()

Open GPS module.

Note: As of 20080128, The Wi2Wi GPS modules are pre-configured
from the factory as NMEA @ 9600,N,8,1. Therefore we no longer
"talk" to the unit initially, as it's already spitting
out what we want. In the future, we can re-configure the
Wi2Wi units either via NMEA commands or via a re-flashing
via a binary from the factory.


**                                                         **
****                                                     ****
************************************************************/
void gps_open(void) {
  gps_status.length       = 0;  // nothing received yet
  NMEAStr[0][0]           = 0;  // clear rcv arrays
  NMEAStr[1][0]           = 0;  //  ""

  gps_status.whichBuff    = 0;  // start out with buffer 0
  srcP = &NMEAStr[gps_status.whichBuff][0]; // init fill pointer

  gps_status.enabled      = 1;  // we're ready to go!
  user_debug_msg(STR_GPS_OPEN ":\t\tEnabled NMEA-handling code (buffers cleared).");
}


/**
* @brief gps_init() initializes uart0 port and selected GPS unit, then clears
*        gps_reading variable.
* @return none
*/
void gps_init(void) {
  // Initialize GPS reading variables
  gps_reading.time_hh=0;       // UTC Time [hhmmss.tt]
  gps_reading.time_mm=0;   
  gps_reading.time_ss=0;   
  gps_reading.time_tt=0;   
  gps_reading.latitude=0.0;    // Latitude [ddmm.mmmm] (Negative = South)
  gps_reading.NS='z';          // North/South Indicator ['N' or 'S']
  gps_reading.longitude=0.0;   // Longitude [dddmm.mmmm] (Negative = West)
  gps_reading.EW='z';          // East/West Indicator ['E' or 'W']
  gps_reading.fixflag=0x00;    // Position Fix Flag (See table)
  gps_reading.num_sat=0;       // Number of satellites in use
  gps_reading.hdop=0.0;        // Horizontal Dilution of Precision
  gps_reading.altitude=0.0;    // Altitude from Mean Sea Level [meters]
  gps_reading.geoid=0.0;       // Geoidal Height [meters]
  gps_reading.stationID=0;     // Differential Station ID
  gps_reading.speed=0.0;       // Speed over ground [knots]
  gps_reading.heading=0.0;     // heading over ground, true [degrees]
  gps_reading.mag_var=0.0;     // Magnetic Variation [degrees] (Negative = West)
  gps_reading.date=0;          // Date [ddmmyy]
  gps_reading.gga_count=0;
  gps_reading.gga_update=0;

  user_debug_msg(STR_GPS_INIT ":\t\tInitialized GPS reading variables.");
}

#define HOUR_PER_DAY    24
#define MIN_PER_DAY   1440
#define MIN_PER_HOUR    60
#define SEC_PER_DAY  86400UL
#define SEC_PER_HOUR  3600
#define SEC_PER_MIN     60


char * gps_NMEA_GMT_time_hhmmss(void) {
  static char str[9];
  

  sprintf(str, "%02d:%02d.%02d", gps_reading.time_hh, gps_reading.time_mm, gps_reading.time_ss);
  return str;
}



/************************************************************
****                                                     ****
**                                                         **
gps_enabled()

Returns TRUE / non-zero if the GPS is enabled.

**                                                         **
****                                                     ****
************************************************************/
unsigned char gps_enabled ( void )
{
  return (unsigned char) gps_status.enabled;
}

/************************************************************
****                                                     ****
**                                                         **
gps_NMEA_str()

Return the NMEA string specified by <buffer>. There are
NMEA_BUFFERS-1 strings available, sarting with #0. Return
NULL if the buffer argument is invalid or the GPS is not
enabled.

#0 is the most recently acquired string. #1 is the next-
most recently acquired string, etc.

NMEA strings are not checked for validity (e.g. the
checksums have not been verified). They end in <CR>,
<LF>, NULL.

IMPORTANT NOTE: There is no attempt to guarantee that the
value returned is not the buffer that is _currently_ being
updated. So a user should verify the correctness of the
returned string via a checksum check, etc.

**                                                         **
****                                                     ****
************************************************************/
char * gps_NMEA_str ( unsigned int buffer )
{
  if (buffer > (NMEA_BUFFERS-2)) {
    return NULL;
  }
  else if (gps_enabled()) {
    return &NMEAStr[((gps_status.whichBuff+3)-1-buffer)%3][0];
  }
  else {
    return NULL;
  }
}


/************************************************************
****                                                     ****
**                                                         **
gps_NMEA_rcv()

This is the NMEA string grabber, and is called whenever a new
character (<newChar>) is received from the GPS module.

Fill the current buffer with the NMEA string ending in <CR>,
<LF>, then move onto the next buffer and start filling it.
Repeat cyclically over all NMEA_BUFFERS worth of buffers.

**                                                         **
****                                                     ****
************************************************************/
void gps_NMEA_rcv(unsigned char newChar) {
  /* as long as we haven't exceeded the max possible NMEA */
  /*  packet length, fill our local string. */
  if (++gps_status.length <= NMEA_MAX_LENGTH) {
    switch(newChar) {
      /* each NMEA string ends in ..., 0x0D, 0x0A, so we look for */
      /*  that final 0x0A and then process the resultant string */
      case 0x0A:
        *srcP++               = newChar;                // copy last char to string
        *srcP                 =       0;                // add a NULL terminator (for strcpy)
        gps_status.length     =       0;                // reset couner
        if (++gps_status.whichBuff >= NMEA_BUFFERS) // advance buffer index w/rollover
          gps_status.whichBuff = 0;                 //  ""
        srcP = &NMEAStr[gps_status.whichBuff][0];   // switch buffers, restart from head
        break;

     default:
        if (newChar < 0x80)
          *srcP++ = newChar;
        else
          ; // this is bad -- all chars should be 7-bit
        break;
    }
  }
  /* otherwise reset */
  else {
    gps_status.length = 0;
    srcP = &NMEAStr[gps_status.whichBuff][0]; // bad -- re-use buffer
  }
}


/************************************************************
****                                                     ****
**                                                         **
gps_update()

Notes:  Sample RMC - Recommended Minimum Specific GNSS Data.
         This does _not_match the SiRF documentation!

        $GPRMC,200933.000,A,3743.0333,N,12226.0537,W,0.09,75.04,010108,,,A*44

        No attempt is made to validate data, etc.

**                                                         **
****                                                     ****
************************************************************/
void gps_update ( void )
{
  //type_gps_reading gps_reading; //Moved to static global
  float lat=0.0, lng=0.0, hdop=0.0, altitude=0.0, geoid=0.0;
  uint16_t time_hh=0, time_mm=9, time_ss=0, time_tt=0;
  char NS='Z', EW='Z';
  /* uint8_t */ unsigned int fixflag=0, num_sat=0, stationID=0, cs=0x00;
  //unsigned long time_long=0;
  gps_reading.gga_update=0;


  // Get the various GNSS fields from whichever of the available NMEA strings has
  //  GGA data. Note no checksum checking, etc. Probably because of this, one does
  //  occasionally see 0 values for lat & long.
  if(strncmp("$GPGGA", gps_NMEA_str(0), sizeof("$GPGGA")-1) == 0) {
    sscanf(gps_NMEA_str(0)+sizeof("$GPGGA"), "%2u%2u%2u.%2u,%f,%c,%f,%c,%u,%u,%f,%f,M,%f,M,,%u*%2X\\r\\n",
      &time_hh, &time_mm, &time_ss, &time_tt, &lat, &NS, &lng, &EW, &fixflag, &num_sat, &hdop, &altitude, &geoid, &stationID, &cs);
    gps_reading.gga_update=1;
  }
  else if(strncmp("$GPGGA", gps_NMEA_str(1), sizeof("$GPGGA")-1) == 0) {
    sscanf(gps_NMEA_str(1)+sizeof("$GPGGA"), "%2u%2u%2u.%2u,%f,%c,%f,%c,%u,%u,%f,%f,M,%f,M,,%u*%2X\\r\\n",
      &time_hh, &time_mm, &time_ss, &time_tt, &lat, &NS, &lng, &EW, &fixflag, &num_sat, &hdop, &altitude, &geoid, &stationID, &cs); 
    gps_reading.gga_update=1;
  }
  if(gps_reading.gga_update) {
    // Update local record.
    gps_reading.fixflag   = 0x00; //Initialize
    gps_reading.time_hh = time_hh;
    gps_reading.time_mm = time_mm;
    gps_reading.time_ss = time_ss;
    gps_reading.time_tt = time_tt;
    gps_reading.NS        = NS;
    if(gps_reading.NS == 'N'){
      gps_reading.latitude  =  lat;
      gps_reading.fixflag   |=  valid_lat;
    }
    else if(gps_reading.NS == 'S'){
      gps_reading.latitude  = -lat;
      gps_reading.fixflag   |=  valid_lat;
    }
    else{
      gps_reading.fixflag   |=  invalid_lat;
    }
    gps_reading.EW        = EW;
    if(gps_reading.EW == 'E'){
      gps_reading.longitude = lng;
      gps_reading.fixflag   |=  valid_lng;
    }
    else if(gps_reading.EW == 'W'){
      gps_reading.longitude = -lng;
      gps_reading.fixflag   |=  valid_lng;
    }
    else{
      gps_reading.fixflag   |=  invalid_lng;
    }
    gps_reading.num_sat   = num_sat;
    gps_reading.hdop      = hdop;
    gps_reading.altitude  = altitude;
    gps_reading.geoid     = geoid;
    gps_reading.stationID = stationID;
    if(fixflag == 0){
      gps_reading.fixflag   |=  no_fix;
    }
    else if(fixflag == 1){
      gps_reading.fixflag   |=  gps_fix;
    }
    else if(fixflag == 2){
      gps_reading.fixflag   |=  diffgps_fix;
    }
    else if(fixflag == 6){
      gps_reading.fixflag   |=  estimated;
    }
    else{
      /* Invalid position fix flag */
      /* Should not come here */
    }
    gps_reading.gga_update=0;
    gps_reading.gga_count++;
  }

  else{
    /* Buffer content is NOT a NMEA string */
    /* DO NOTHING */
  }
  //time_long = *(unsigned long*)&gps_reading.time; // Obsolete. Tried to send float in a byte stream
  return;
}

/**
* @brief gps_read() provides access to 
*
* @param[in]  message_class  Pre-defined constant which indicates message class. (See UBX Protocol Definition)
* @param[in]  message_id     Pre-defined constant which indicates message ID. 
* @param[in]  length         The number of bytes to be transmitted.
* @param[in]  payload        The buffer area to transmit from.
* @return     none
*/
type_gps_reading gps_read(void) {
  return gps_reading;
}




