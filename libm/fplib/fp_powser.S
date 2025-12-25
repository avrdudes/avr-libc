/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2006  Dmitry Xmelkov
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
   POSSIBILITY OF SUCH DAMAGE. */

#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

/* flt40_t __fp_powser (float x, [XH.]ZH.ZL);
     The __fp_powser() function calculates the polynomial.

   Input:
     rA3.rA2.rA1.rA0	- an 'x' arg
     ZH.ZL		- table address
     XH			- hh8(table address) on ELPM devices
   Output:
     rA3.rA2.rA1.rA0.rAE - result (is't rounded)

   Table format:
     ; example for 3 power: C0 + x*(C1 + x*(C2 + x*C3))
     ; all floats are little-endian
	.byte	3		; polynomial power
	.byte	   C3,C3,C3,C3	; flt32_t C3
	.byte	C2,C2,C2,C2,C2	; flt40_t C2
	.byte	C1,C1,C1,C1,C1	; flt40_t C1
	.byte	C0,C0,C0,C0,C0	; flt40_t C0
 */

#define	rC3	r17
#define	rC2	r16
#define	rC1	r15
#define	rC0	r14
#define	rcntr	r13


.macro .ELPM_Zplus reg
#ifdef __AVR_HAVE_ELPMX__
	elpm	\reg, Z+
#elif defined(__AVR_HAVE_ELPM__)
        elpm
	mov	\reg, r0
        adiw	r30, 1
        brcc    .Lnoinc.\@
	in	r0, RAMPZ_IO_ADDR
        inc	r0
	out	RAMPZ_IO_ADDR, r0
.Lnoinc.\@:
#else
	X_lpm	\reg, Z+
#endif
.endm


ENTRY __fp_powser
	push	YH
	push	YL
	push	rC3
	push	rC2
	push	rC1
	push	rC0
	push	rcntr
#ifdef __AVR_HAVE_ELPM__
	out	RAMPZ_IO_ADDR, XH
#endif
	X_movw	rC0, rA0
	X_movw	rC2, rA2

	set			; as flag to return
	rjmp	.Load5
1:	mov	rcntr, rBE

.Loop:	X_movw	YL, ZL
	XCALL	_U(__mulsf3x)
	X_movw	ZL, YL

	clt
.Load5:
	.ELPM_Zplus	rBE
	.ELPM_Zplus	rB0
	.ELPM_Zplus	rB1
	.ELPM_Zplus	rB2
	.ELPM_Zplus	rB3
	brts	1b

	X_movw	YL, ZL
	XCALL	_U(__addsf3x)
	X_movw	ZL, YL

	X_movw	rB0, rC0
	X_movw	rB2, rC2
	dec	rcntr
	brne	.Loop

	pop	rcntr
	pop	rC0
	pop	rC1
	pop	rC2
	pop	rC3
	pop	YL
	pop	YH
#if defined(__AVR_HAVE_ELPM__) && defined (__AVR_HAVE_RAMPD__)
	out	RAMPZ_IO_ADDR, r1
#endif
	ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
