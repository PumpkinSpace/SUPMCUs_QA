/******************************************************************************
(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source: C:\\RCS\\D\\Pumpkin\\CubeSatKit\\Example\\PIC24\\PIC24FJ256GA110\\CubeSat_Kit_Dev_Board\\Test\\Test1\\cmd.c,v $
$Author: aek $
$Revision: 3.1 $
$Date: 2010-02-13 13:17:57-08 $

******************************************************************************/
#include "main.h"
#include "cmd.h"

// Pumpkin CubeSat Kit headers
#include "csk_uart.h"


/******************************************************************************
****                                                                       ****
**                                                                           **
cmd_mclk()

**                                                                           **
****                                                                       ****
******************************************************************************/
void cmd_mclk(void) {

  user_debug_msg(STR_CMD_MCLK "m: Command not supported.");
#if 0 // Code below is from MSP430

  unsigned int i;


  switch (csk_status.MCLKOutEnabled) {

    // 0: MCLK out is DCO.
    case 0:
      P5DIR   |=  BIT4;
      P5SEL   |=  BIT4;
      BCSCTL2 &= ~(SELM1+SELM0);
      user_debug_msg(STR_CMD_MCLK "m:MCLK=DCO on P5.4.");
      csk_status.MCLKOutEnabled = 1;
      break;

    // 1: MCLK out is LFXT1CLK. Turn off WDT because
    //  instruction clock is so slow when sourced from LFXT1CLK.
    case 1:
      //WDT_OFF;
      P5DIR   |= BIT4;
      P5SEL   |= BIT4;
      BCSCTL2 |= (SELM1+SELM0);
      user_debug_msg(STR_CMD_MCLK "m: MCLK=LFXT1CLK on P5.4.");
      csk_status.MCLKOutEnabled = 2;
      break;

    // 2: MCLK out is XT2CLK.
    case 2:
      P5DIR |= BIT4;
      P5SEL |= BIT4;
      BCSCTL1 &= ~XT2OFF;
      do  {
        IFG1 &= ~OFIFG;
        for (i = 0xFF; i > 0; i--);
      }
      while ((IFG1 & OFIFG) != 0);
      BCSCTL2 &= ~SELM0;
      BCSCTL2 |=  SELM1;
      //WDT_ON;
      user_debug_msg(STR_CMD_MCLK "m: MCLK=XT2CLK on P5.4.");
      csk_status.MCLKOutEnabled = 3;
      break;

    // 3: MCLK is back to DCO clock, XT2 off, 0V output.
    case 3:
      BCSCTL2 &= ~(SELM1+SELM0);
      BCSCTL1 |=  XT2OFF;
      P5SEL   &= ~BIT4;
      P5DIR   &= ~BIT4;
      user_debug_msg(STR_CMD_MCLK "m: P5.4 reset to GPIO (input).");
      csk_status.MCLKOutEnabled = 0;
      break;

  } /* switch */
#endif  
  
} /* cmd_clck() */
