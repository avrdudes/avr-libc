
/*------------------------------------------------------------------------------------------

   This file is part of     FPlib V 0.3.0       Floating point library for Atmel AVR uC

   Copyright (c) Michael Stumpf   <mistumpf@de.pepperl-fuchs.com>
   All rights reserved.


   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
     
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE. 
    
    
   ported to avr-as by Michael Rickmann      <mrickma@gwdg.de>

   for details see readme.fplib

 *------------------------------------------------------------------------------------------
 */

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

/* Put constant tables at low addresses in program memory, so they are
   reachable for "lpm" without using RAMPZ on >64K devices.  */

#define PGM_SECTION .section .progmem.gcc_fplib,"a",@progbits

/* Unfortunately, we need both an assembler and a C preprocessor macro for
   these.  Assembler macros cannot do string concatenation for macro
   parameters, and cpp macros cannot generate multiple lines.  We need both. */

/* load floating point constant into fp pseudo register reg */
.macro	fpload	reg0, reg1, reg2, reg3, val
	ldi	\reg0, lo8(\val)
	ldi	\reg1, hi8(\val)
	ldi	\reg2, hlo8(\val)
	ldi	\reg3, hhi8(\val)
.endm

#define FPLOAD(reg, val) \
	fpload reg##0, reg##1, reg##2, reg##3, val

/* move fp pseudo register src into dst */
.macro	fpmov	dst0, dst1, dst2, dst3, src0, src1, src2, src3
	mov	\dst0, \src0
	mov	\dst1, \src1
	mov	\dst2, \src2
	mov	\dst3, \src3
.endm

#define FPMOV(dst, src) \
	fpmov	dst##0, dst##1, dst##2, dst##3, \
		src##0, src##1, src##2, src##3

/* push/pop fp pseudo register reg */
.macro	fppush	reg0, reg1, reg2, reg3
	push	\reg0
	push	\reg1
	push	\reg2
	push	\reg3
.endm

#define FPPUSH(reg) \
	fppush reg##0, reg##1, reg##2, reg##3

.macro	fppop	reg3, reg2, reg1, reg0
	pop	\reg3
	pop	\reg2
	pop	\reg1
	pop	\reg0
.endm

#define FPPOP(reg) \
	fppop reg##3, reg##2, reg##1, reg##0

.macro	fpclr	reg0, reg1, reg2, reg3
	clr	\reg0
	clr	\reg1
	clr	\reg2
	clr	\reg3
.endm

#define FPCLR(reg) \
	fpclr reg##0, reg##1, reg##2, reg##3

/* swap fp pseudo registers A and B */
.macro	fpswap
	eor	rA3, rB3
	eor	rB3, rA3
	eor	rA3, rB3
	eor	rA2, rB2
	eor	rB2, rA2
	eor	rA2, rB2
	eor	rA1, rB1
	eor	rB1, rA1
	eor	rA1, rB1
	eor	rA0, rB0
	eor	rB0, rA0
	eor	rA0, rB0
.endm

#define FPSWAP \
	fpswap

