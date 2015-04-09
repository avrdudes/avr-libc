/* Copyright (c) 2002, Reiner Patommel
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

/* float atan2 (float A, float B);	// A is y coord, B is x coord.
     The atan2() function calculates the arc tangent of the two variables
     A and B. It is similar to calculating the arc tangent of A/B, except
     that the signs of both arguments are used to determine the quadrant
     of the result. The atan2() function returns the result in radians,
     which is between -PI and PI (inclusive).
     
   Note:
     This implementation returns +0.0 in all four cases: +0/+0, +0/-0,
     -0/+0 and -0/-0.  Unlike x86 (GCC/Glibc).

   Algorithm:
	if (x == 0 && y == 0)		// A is y, B is x
	    return 0
	if (x >= 0 && fabs(y) <= x)
	    return atan(y/x)		// -Pi/4 .. +Pi/4
	if (y >= 0 && fabs(x) <= y)
	    return Pi/2 - atan(x/y)	// +Pi/4 .. +3*Pi/4
	if (y <= 0 && fabs(x) <= fabs(y))
	    return -Pi/2 - atan(x/y)	// -Pi/4 .. -3*Pi/4
	if (y >= 0)
	    return Pi + atan(y/x)	// +3*Pi/4 .. Pi
	else
	    return -Pi + atan(y/x)	// -3*Pi/4 .. -Pi
 */


#if !defined(__AVR_TINY__)

#include "fp32def.h"
#include "asmdef.h"

#define PI	0x40490fdb	/* Pi	*/
#define PI_2	0x3fc90fdb	/* Pi/2	*/

#define	disp	ZL		/* displacement high byte	*/

FUNCTION atan2

.L_nf:	XCALL	_U(__fp_pscA)
	brcs	.L_nan
	ldi	rA2, 0x80
	ldi	rA3, 0x01	; replace finite to very small value
	brne	1f
	ldi	rA3, 0xfe	; replace Inf to very big value
1:	XCALL	_U(__fp_pscB)
	brcs	.L_nan
	ldi	rB2, 0x80
	ldi	rB3, 0x01	; replace finite to very small value
	brne	.L_cmp
	ldi	rB3, 0xfe	; replace Inf to very big value
	rjmp	.L_cmp

.L_nan:	XJMP	_U(__fp_nan)
.L_zr:	XJMP	_U(__fp_zero)

ENTRY   atan2
  ; save 'y' sign
	mov	disp, rA3
	andi	disp, 0x80
  ; split
	XCALL	_U(__fp_split3)
	brcs	.L_nf
  ; check the (0,0) case
	mov	r0, rA3
	or	r0, rB3
	breq	.L_zr
  ; compare absolute values
.L_cmp:
	cp	rB0, rA0
	cpc	rB1, rA1
	cpc	rB2, rA2
	cpc	rB3, rA3
	brlo	1f
  ; fabs(A) <= fabs(B), no swapping
	mov	r0, disp	; sign(A)
	bld	r0, 7		; sign(A) ^ sign(B)
	eor	disp, r0	; sign(B)
	breq	2f		; displacement is not needed
	eor	disp, r0	; restore sign(A)
	ori	disp, hhi8(PI)
	rjmp	2f
  ; fabs(A) > fabs(B), swap values and change the atan sign
1:	ori	disp, hhi8(PI_2)
	bld	r0, 7		; inverse division sign
	com	r0
	bst	r0, 7
	X_movw	XL, rA0
	X_movw	rA0, rB0
	X_movw	rB0, XL
	X_movw	XL, rA2
	X_movw	rA2, rB2
	X_movw	rB2, XL
  ; save displacement and calculate atan
2:	push	disp
	XCALL	_U(__divsf3_pse)
	XCALL	_U(__fp_round)
	XCALL	_U(atan)
  ; restore disp and analize
	pop	rB3		; hhi8()
	tst	rB3
	breq	9f
  ; add displacement
	ldi	rB0,  lo8(PI)	; lo8(PI) == lo8(PI_2)
	ldi	rB1,  hi8(PI)	; hi8(PI) == hi8(PI_2)
	ldi	rB2, hlo8(PI)
	sbrc	rB3, 0		; hhi8(PI) == 0x40,  hhi8(PI_2) == 0x3f
	ldi	rB2, hlo8(PI_2)
	XJMP	_U(__addsf3)

9:	ret
ENDFUNC

#endif /* !defined(__AVR_TINY__) */
