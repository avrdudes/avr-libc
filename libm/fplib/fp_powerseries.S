/*  -*- Mode: Asm -*-  */

/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2005, 2006  Anatoly Sokolov <aesok@post.ru>
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
    fp_powerseries.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 * A = powerseries(x[A])
 *   = (((Z[0]*(*PXX))+Z[1])*(*PXX)+Z[2])*(*PXX)...
 *      until step counter in (*Z++)
 *   power argument in A
 *   pointer to power factor table at Z  ( PFT[] )
 */

#if !defined(__DOXYGEN__)

#include "gasava.inc"
#include "macros.inc"
#include "fplib.inc"

#define rArg3  rS0
#define rArg2  rS1
#define rArg1  rS2
#define rArg0  rS3
#define rGrade rS4

	TEXT_SEG(fplib, __fp_powerseries)
	FUNCTION(__fp_powerseries)

GLOBAL(__fp_powerseries)
; TODO: exit if argument is NAN

	PUSH	rS0
	PUSH	rS1
	PUSH	rS2
	PUSH	rS3
	PUSH	rS4

	x_movw	rArg0, rA0
	X_movw	rArg2, rA2
	
	X_lpm	rGrade, Z+	; first entry of fp table is byte with entry count
	RCALL  100f

	X_lpm	rGrade, Z+	; increment first (last access or loop counter)
	TST	rGrade
	BREQ	1f		; no dividing

	PUSH	rA3
	PUSH	rA2
	PUSH	rA1
	PUSH	rA0

	X_movw	rA0, rArg0
	X_movw	rA2, rArg2	; get power series argument again
	
	RCALL  100f

	POP	rB0
	POP	rB1
	POP	rB2
	POP	rB3
	XCALL	__divsf3

1:
	POP	rS4
	POP	rS3
	POP	rS2
	POP	rS1
	POP	rS0

	RET


100:
	RCALL	_U(__fp_flashconst)	; BX = *array[n]
	RJMP	2f

1:
	X_movw	rB0, rArg0
	X_movw	rB2, rArg2		; get power series argument

2:
	PUSH	ZL
	PUSH	ZH
	XCALL	__mulsf3		; AX *= BX
	POP	ZH
	POP	ZL
    
	RCALL	_U(__fp_flashconst)	; BX = *array[n]

	PUSH	ZL
	PUSH	ZH
	XCALL	__addsf3		; AX += BX
	POP	ZH
	POP	ZL

4:
	DEC	rGrade
	BRNE	1b
	RET

	ENDFUNC

#endif /* not __DOXYGEN__ */
