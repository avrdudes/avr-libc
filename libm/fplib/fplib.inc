
/*------------------------------------------------------------------------------------------

    This file is part of     FPlib V 0.3.0       Floating point library for Atmel AVR uC

    Copyright (c) Michael Stumpf   <Michael.Stumpf@t-online.de>
    ported to avr-as by Michael Rickmann      <mrickma@gwdg.de>

    for details see readme.fplib

 *------------------------------------------------------------------------------------------
 */

#ifndef __FPLIB_INC
#define __FPLIB_INC

;--------------------------------------------------------------------
; fp lib register nicknames

#define rA3      rP0
#define rA2      rP1
#define rA1      rP2
#define rA0      rP3
#define rAE      rTI2

#define rB3      rP4
#define rB2      rP5
#define rB1      rP6
#define rB0      rP7
#define rBE      rTI3

#define rPH      rP4            /* pointer argument */
#define rPL      rP5

#define rT0      __tmp_reg__    /* first temporary */
#define rT1c     __zero_reg__   /* 2nd temporary, clear after use */

/*--------------------------------------------------------------------------
 * Library shapening :
 */

#define __OPTIMIZE__
/* #define __SIMPLE__NaNs simple NaNs implemented now */
/* #define __COMPLEX__NaNs */ /* not yet tested (and discarded anyway) */
/* #define __ERRNO__ */ /* not yet fully implemented */

#define EDOM   33
#define ERANGE 34

/*--------------------------------------------------------------------------
 * math function macro
 */

	.macro	mLPMRdZpp rr
#ifdef __AVR_ENHANCED__
	lpm	\rr, Z+
#else
	lpm
	mov	\rr, r0
	adiw	ZL, 1
#endif
	.endm

#define LPMRdZpp(Rd) mLPMRdZpp Rd

/*--------------------------------------------------------------------------
 * avr-as specific definitions for segments, functions and labels.
 */

#define LOW(x)	lo8(x)
#define HIGH(x)	hi8(x)
#define DCB	.byte

#define ACCURACY	7	/* decimal digits */
#define retByte	rByte		/* FIXME: why has this been renamed ?  */

/* Put constant tables at low addresses in program memory, so they are
   reachable for "lpm" without using RAMPZ on >64K devices.  */

#define PGM_SECTION .section .progmem.gcc_fplib,"a",@progbits

#endif

