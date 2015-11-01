#ifndef __GPS_NMEA
#define __GPS_NMEA

#include <stdint.h>

#define STR_GPS_OPEN "gps_open"
#define STR_GPS_INIT "gps_init"

  #define STR_NOVATEL_CMD_UNLOGALL_COM1 "unlogall com1\r\n"
  #define STR_NOVATEL_CMD_LOG_COM1_GPRMC_1HZ "log com1 gprmc ontime 1\r\n"






#define GPS_DATA_SIZE      (30) // Define's the size of the buffer used by beacon

typedef enum {
  invalid_data = (0x00),
  valid_data   = (0x01),
  no_fix       = (0x00<<1),
  gps_fix      = (0x01<<1),
  diffgps_fix  = (0x02<<1),
  estimated    = (0x06<<1),
  invalid_lat  = (0x00<<4),
  valid_lat    = (0x01<<4),
  invalid_lng  = (0x00<<5),
  valid_lng    = (0x01<<5)
} type_fixflag;

typedef struct {
  uint16_t time_hh, time_mm, time_ss, time_tt;    // UTC Time ["hhmmss.tt"]
  double latitude;    // Latitude [ddmm.mmmm] (Negative = South)
  char NS;            // North/South Indicator ['N' or 'S']
  double longitude;   // Longitude [dddmm.mmmm] (Negative = West)
  char EW;            // East/West Indicator ['E' or 'W']
  type_fixflag fixflag;   // Position Fix Flag (See table)
  uint8_t num_sat;    // Number of satellites in use
  float hdop;         // Horizontal Dilution of Precision
  float altitude;     // Altitude from Mean Sea Level [meters]
  float geoid;        // Geoidal Height [meters]
  uint8_t stationID;  // Differential Station ID
  float speed;        // Speed over ground [knots]
  float heading;      // Course over ground, true [degrees]
  float mag_var;      // Magnetic Variation [degrees] (Negative = West)
  uint16_t date;      // Date [ddmmyy]
  uint16_t gga_count; // The number of GGA string received
  uint16_t rmc_count; // The number of RMC string received
  uint8_t gga_update; // Flag to indicate if RMC string has been updated (1=updated, 0=not updated)
  uint8_t rmc_update; // Flag to indicate if RMC string has been updated (1=updated, 0=not updated)
} type_gps_reading;

extern void             gps_init(void);
extern void             gps_update ( void );
extern type_gps_reading gps_read ( void );
extern unsigned char    gps_enabled ( void );
extern void             gps_NMEA_rcv ( unsigned char );
extern char *           gps_NMEA_str ( unsigned int );
extern void             gps_open ( void );
extern void             gps_put_init_str ( void );
extern void             gps_send(void);
extern void             gps_On(void) ;
extern void             gps_Off(void) ;
extern void             gps_Log(void) ;
#ifdef UBLOX
extern void             ublox_tx_UBX_packet(unsigned short message_class, unsigned short message_id, unsigned int length, char* payload);
extern void             ublox_poll_msg(unsigned int message_id);
#endif

extern char * gps_NMEA_GMT_time_hhmmss(void);

#endif /* __GPS_NMEA */
