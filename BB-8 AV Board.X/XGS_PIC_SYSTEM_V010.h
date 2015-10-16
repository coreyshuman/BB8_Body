///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright Nurve Networks LLC 2008
//
// Filename: XGS_PIC_SYSTEM_V010.H
//
// Original Author: Joshua Hintze
//
// Last Modified: 8.31.08
//
// Description: Main system header file, it includes all our common types, macros, functions that are used
//				throughout the XGS PIC library.
//
//
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// INCLUDES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// We'll include the chip header file here just incase we forget it somewhere
#include "p24HJ256GP206.h"

// Include libpic30.h for some useful functions (flash copy, uart simulation files, etc.)
// Most important is the prototype for the __delay32 assembly program automatically linked
#include "libpic30.h"

// watch for multiple inclusions
#ifndef XGS_PIC_SYSTEM
#define XGS_PIC_SYSTEM

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MACROS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// A couple simple delay routines
// Instruction cycles per millisecond
#define CYCLES_PER_MS ((unsigned long)(g_FCY * 0.001))

// Instruction cycles per microsecond
#define CYCLES_PER_US ((unsigned long)(g_FCY * 0.000001))

//__delay32 is provided by the compiler, delay some # of milliseconds
#define DELAY_MS(ms)  __delay32(CYCLES_PER_MS * ((unsigned long) ms))

// Delay some number of microseconds
#define DELAY_US(us)  __delay32(CYCLES_PER_US * ((unsigned long) us))

// Delay some clocks, minimum is 12 clocks
#define DELAY_CLOCKS(clocks) __delay32(clocks)

// Cause a one cycle stall
#define NOP {__asm__ volatile ("nop");}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DEFINES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// The two currently supported clock rates, potentially have PAL in the future
#define FCY_VGA		44073148L	// This is the instruction rate at about 1.75*VGA
#define FCY_NTSC	42954540L	// This is the instruction rate at 12*NTSC


// Pin direction constants. PICs use 0 for output, 1 for input on TRIS registers
#define PIN_DIR_OUTPUT	0
#define PIN_DIR_INPUT	1

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GLOBALS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// EXTERNALS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// The choosen operating clock rate
extern unsigned long g_FCY;
extern int debug;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PROTOTYPES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Configures the clock PLL multiplier, pass in either FCY_VGA or FCY_NTSC
void SYS_ConfigureClock(unsigned long FCY);


// watch for multiple inclusions
#endif




