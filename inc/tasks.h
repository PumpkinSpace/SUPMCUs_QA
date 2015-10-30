/******************************************************************************
(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source: C:\\RCS\\D\\Pumpkin\\CubeSatKit\\Example\\all\\all\\CubeSatKit_Dev_Board\\Test\\Test1\\tasks.h,v $
$Author: aek $
$Revision: 3.1 $
$Date: 2010-01-29 20:04:19-08 $

******************************************************************************/
#define TASK_CMD_DO_P                           OSTCBP(1) // needs to be cmd #1 (see task_cmd_do())
#define TASK_5SEC_P                             OSTCBP(2)
#define TASK_SUPMCU_QA_P                        OSTCBP(3)
//#define TASK_GPS_QA_P                           OSTCBP(4)
//#define TASK_BIM_QA_P                           OSTCBP(5)

#if defined(SUPMCU_GPSRM1_REVA) \
   || defined(SUPMCU_GPSRM1_REVB) \
   || defined(SUPMCU_GPSRM1_REVC) 
#define TASK_GPS_QA_P                           OSTCBP(4)


#elif defined(SUPMCU_BIM1_REVA) \
     || defined(SUPMCU_BIM1_REVB)
#define TASK_BIM_QA_P                           OSTCBP(4)

#elif defined(SUPMCU_PIM1_REVA) \
      || defined(SUPMCU_PIM1_REVB)
#define TASK_PIM_QA_P                           OSTCBP(4)

#elif defined(SUPMCU_SIM1_REVA) \
      || defined(SUPMCU_SIM1_REVB)
#define TASK_SIM_QA_P                           OSTCBP(4)

#endif

#define TASK_MONITOR_P                          OSTCBP(5)
#define TASK_NEW_P                              OSTCBP(6)


