/*  -*- Mode: Asm -*-  */

/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
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

/*
    fmod.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 * A = remainder( A/B )
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, fmod)
          FUNCTION(fmod)

GLOBAL(fmod)
	/* fmod = x % y = x - (floor)(x/y)*y ??
	 *
	 * fmod   x  10.5     -10.5
	 * y   PI    1.075..  -1.075..
	 *    -PI    1.075..  -1.075..
	 */
    ANDI    rB3,0x7F	; fmod(x,y) = sgn(x) * fmod(|x|,|y|)
    TST     rB3		; -0 ?
    BRNE    _fmod_01
    TST     rB2
    BRMI    _fmod_01
    RJMP    _U(__fp_nanERANGE)
 _fmod_01:
    PUSH    rB0
    PUSH    rB1
    PUSH    rB2
    PUSH    rB3
    RCALL   _U(__divsf3)	; A = x/y
    CLR     rP4
    CLR     rP5			; point to NUL
    RCALL   _U(modf)		; A = fraction( x/y )
    POP     rB3
    POP     rB2
    POP     rB1
    POP     rB0			; B = y
    RJMP    _U(__mulsf3)	; A = y * fraction( x/y )

          ENDFUNC

#endif /* not DOXYGEN */
