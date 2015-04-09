/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2007  Dmitry Xmelkov
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

/* $Id$ */

#include "fp32def.h"
#include "asmdef.h"

/* unsigned long __fixunssfsi (float A);
     The __fixunssfsi() function converts A to the integer value. No
     rounding, the fractional is losted. The compiler calls this function
     to perform a cast operation from float (i.e. double) to unsigned long.
     No saturation. Negative input is permissable (like GCC/x86). Besides
     a normal 32-bits value __fixunssfsi() returns the extra error flag
     in a call-scratched register. This is used when a caller is the
     __fixsfsi() function.

   Return:
     rA3.rA2.rA1.rA0	- 32-bits integer
     rAE		- flag of error (NaN, overflow or A is too big for
    			signed conversion)

   if (!isnan(A) && fabs(A) <= 0x0.ffffffp+31)
      return [A < 0 ? -(long)(-A) : (long)A, OK_FLAG]
   if (!isnan(A) && fabs(A) <= 0x0.ffffffp+32)
      return [A < 0 ? -(unsigned long)(-A) : (unsigned long)A, ERR_FLAG]
   if (isnan(A) || fabs(A) >= 0x0.800000p+33)
      return [0, ERR_FLAG]

   Why no saturation?
     - GCC on Intel's x86 does not do it
     - with saturation it will be more difficult to check result
     - if cast is to 'int' (16 bits for AVR) then saturation is unusefull
     - in practice saturation is needed with user's desirable limits

   Algorithm roughly:
     - split
     - shift mantissa according to exponent
     - restore the sign
 */

ENTRY __fixunssfsi
	XCALL	_U(__fp_splitA)
	brcs	.L_err
  ; A is finite
	subi	rA3, 127	; exponent field of 1.0
	brlo	.L_zr
  ; fabs(A) >= 1.0
	mov	rAE, rA3
	clr	rA3
	subi	rAE, 23
	brlo	4f		; shift to right
	breq	.L_sign		; no shift
  ; fabs(A) >= 0x0.800000p+25  To reduce code size we will not check
  ; number of shifts. Instead we will check a MSB of result.
1:	lsl	rA0
	rol	rA1
	rol	rA2
	rol	rA3
	brmi	2f		; next shift is impossible: data lost
	dec	rAE
	brne	1b
	rjmp	.L_sign

2:	cpi	rAE, 1
	breq	.L_sign		; rAE: overflow for 'signed long' usage

.L_err:	XCALL	_U(__fp_zero)
	ldi	rAE, 1		; error flag
	ret

.L_zr:	XJMP	_U(__fp_zero)	; return 0x00000000, clear rAE

  ; fabs(A) <= 0x0.ffffffp+23
  ; Shift A to right by 1 (rA3==-1) .. 23 (rA3==-23) positions.
	
3:	mov	rA0, rA1
	mov	rA1, rA2
	clr	rA2
	subi	rAE, -8
	breq	.L_sign

4:	cpi	rAE, -7
	brlt	3b		; quick shift is possible
	
5:	lsr	rA2
	ror	rA1
	ror	rA0
	inc	rAE
	brne	5b

  ; restore the sign and return
.L_sign:
	brtc	6f
	com	rA3
	com	rA2
	com	rA1
	neg	rA0
	sbci	rA1, -1
	sbci	rA2, -1
	sbci	rA3, -1
6:	ret

ENDFUNC
