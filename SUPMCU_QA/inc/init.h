/******************************************************************************
(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source: C:\\RCS\\D\\Pumpkin\\CubeSatKit\\Example\\PIC24\\PIC24FJ256GA110\\CubeSat_Kit_Dev_Board\\Test\\Test1\\init.h,v $
$Author: aek $
$Revision: 3.2 $
$Date: 2011-09-17 16:24:48-07 $

******************************************************************************/
#ifndef __init_h
#define __init_h


// Function declarations
extern void init (void);

// MPLAB C30's lack of __enable_interrupt() is addressed here ...
#define __enable_interrupt()   do { __asm__ volatile("disi #0x0000"); } while (0)
#define __disable_interrupt()  do { __asm__ volatile("disi #0x3FFF"); } while (0)

// Target-specific symbols, etc. 
#if   defined(__PIC24FJ256GA110__)
#define STR_CSK_TARGET "CubeSat Kit /PIC24 (PPM D1)"
#elif defined(__PIC24FJ256GB210__) || defined(__PIC24FJ256GB110__)
#define STR_CSK_TARGET "CubeSat Kit /PIC24 (PPM E1)"
#else
#error PIC24F device not supported by CubeSat Kit
#endif 


#endif /* __init_h */
