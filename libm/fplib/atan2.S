/* Copyright (c) 2002, Reiner Patommel
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

/* ---------------------------------------------------------------------------
	atan2.S

	Contributors:
	Created by Reiner Patommel 08 December 2002

-*- Mode: Asm -*-
*
* Accuracy:	better than +/-2.5*10^-7 over full range
*
* ----------------------------------------------------------------------------
* A = atan2(float A, float B) = atan2(float y, float x)
* --------------------------------------------------------------------------*/

/* $Id$ */

#if !defined(__DOXYGEN__)

#include "gasava.inc"
#include "fplib.inc"
#include "macros.inc"
#define y3	r25		/* rA3	*/
#define x3	r21		/* rB3	*/
#define flags	r17
#define FP_PI	0x40490FDB	/* PI	*/
#define FP_PI_2 0x3FC90FDB	/* PI/2	*/

	TEXT_SEG(fplib, atan2)
	FUNCTION(atan2)

GLOBAL(atan2)
	TST	x3		; x == 0?
	BREQ	.L_NS		; --> north/south: return ERANGE or +/-PI/2
	TST	y3		; y == 0?
	BREQ	.L_EW		; --> east/west: return ERANGE or 0 or PI
	RJMP	.L_calc		; --> calculate atan2

.L_NS:				; here x == 0
	TST	y3		; y == 0?
	BREQ	.L_ERANGE	; return argument range error
	BST	y3, 7		; keep sign of y
	FPLOAD	(rA, FP_PI_2)	; A = PI/2
	BLD	rA3, 7		; get sign again
	RET			; return +/-PI/2 depending on sign

.L_EW:				; here y == 0
	TST	x3		; x == 0?
	BREQ	.L_ERANGE	; return argument range error
	BRPL	.L_EW_ZERO	; --> return 0
	FPLOAD	(rA, FP_PI)	; A = PI
	RET			; return PI

.L_EW_ZERO:
	FPCLR	(rA)		; A = 0
	RET			; return 0

.L_ERANGE:			; here x ==0 and y == 0
	RJMP	_U(__fp_nanERANGE) ; return argument range error

.L_calc:			; here x != 0 and y != 0
	PUSH	flags
	CLR	flags
	SBRC	y3, 7
	ORI	flags, 0x01	; keep sign of y
	SBRC	x3, 7
	ORI	flags, 0x02	; keep sign of x
	XCALL	__divsf3	; A = y/x
	RCALL	_U(atan)	; A = atan(y/x)
	SBRS	flags, 1	; if x > 0
	RJMP	1f		; return atan(y/x)
	FPLOAD	(rB, FP_PI);	; here x < 0 --> load PI
	SBRC	flags, 0	; if y < 0 return atan(y/x) - PI
	ORI	rB3, 0x80	; if y > 0 return atan(y/x) + PI
	XCALL	__addsf3
1:	POP	flags		; clean-up
	RET

	ENDFUNC

#endif /* not __DOXYGEN__ */
