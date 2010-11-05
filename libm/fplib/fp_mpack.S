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

/* $Id$ */

#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

/* float __fp_mpack (<non_standart>);
     Merge parts of float value.

  Input:
     T                  - sign
     rA3                - exponent
     rA2.rA1.rA0[.rAE]  - mantissa
  Possible input combinations:
     exp==0	-	zero or subnormal, mantissa shift to right is needed
     exp==1,      rA2 < 0x80	     -	subnormal
     exp==1,      rA2 >= 0x80	     -	normal
     exp==2..254, rA2 >= 0x80	     -	normal
     exp==255,    rA2.rA1.rA0 == 0   -	Infinity
     exp==255,    rA2.rA1.rA0 != 0   -	NaN

  The __fp_mpack_finite entry point is intended for case where it is
  known that the A is a finite number.
 */

ENTRY __fp_mpack
	cpi	rA3, 255
	breq	1f

ENTRY __fp_mpack_finite
	subi	rA3, 1
	brsh	1f
	ror	rA2		; rA2.7 := 1 to restore zero rA3
	ror	rA1
	ror	rA0
	ror	rAE

1:	lsl	rA2
	adc	rA3, r1		; switch (A)
				;  zero:      rA3 is restored to 0
				;  subnormal: rA3 is stayed (or restored to) 0
				;  normal:    rA3 is restored to initial
				;  nonfinite: rA3 is stayed 255
	lsr	rA3
	ror	rA2
	bld	rA3, 7		; sign
	ret

ENDFUNC

#endif /* !defined(__AVR_TINY__) */
