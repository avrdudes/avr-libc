/*  -*- Mode: Asm -*-  */

/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2005  Anatoly Sokolov <aesok@post.ru>
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
*/

/* $Id$ */

/*
    ldexp.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 * A = 2^exp * x
 * e.g.
 * double y = ldexp( 3.45, 2 ) = 2^2 * 3.45 = 13.8
 */

#if !defined(__DOXYGEN__)

#include "gasava.inc"
#include "macros.inc"
#include "fplib.inc"

#define rExpH	rBE

	TEXT_SEG(fplib, ldexp)
	FUNCTION(ldexp)

GLOBAL(ldexp)
	RCALL	_U(__fp_split_a)	; Non return if NaN; clears rAE

        TST     rA3			;
        BREQ    .L_zero			; 2^x*0 = 0
	
	CLR	rExpH
	ADD	rA3, rPL		; rExpH.rA3 := sum of exponent and arg
	ADC	rExpH, rPH

	BRVS	.L_Inf			; overflow is possible for positive only
	BRMI	.L_zero			; if underflow return 0

	LDI	rPL, lo8(EMAX)
	LDI	rPH, hi8(EMAX)
	CP	rA3, rPL
	CPC	rExpH, rPH
	BRGE	.L_Inf			; if overflow return +/-Inf
	
        RJMP    _U(__fp_merge)		; rT0 must not be cleared : rAE=0 no rounding anyway

.L_zero:
        RJMP    _U(__fp_zero)

.L_Inf:
	BRTS	.L_mInf			; branch if arg negative
        RJMP    _U(__fp_p_inf)
.L_mInf:
        RJMP    _U(__fp_m_inf)

	ENDFUNC

#endif /* not __DOXYGEN__ */
