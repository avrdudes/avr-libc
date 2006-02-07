/* -*- Mode: Asm -*-
   Copyright (c) 2002, 2006 Reiner Patommel
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
/* ----------------------------------------------------------------------------------
   dtostrf.S

   Contributors:
     Created by Reiner Patommel

   $Id$

*-----------------------------------------------------------------------------------
* A = *dtostrf(double num, char width, char precision, char *str)
* Converts a double (float) to a string in the printf f format.
* This is a substitute for printf("%width.precisionf", num,)
* Width is the minimum width of the output string including '.' and possible sign.
* Precision is the number of digits required after the decimal point.
* If precision is < 0, the string is left adjusted with leading spaces.
* If precision is > 0, the string is right adjusted with trailing spaces.
* The number will be rounded based on precision.
*----------------------------------------------------------------------------------*/

#if !defined(__DOXYGEN__)

#include "gasava.inc"
#include "fplib.inc"
#include "macros.inc"

#define p_num_hi_hi	r25
#define p_num_hi_lo	r24
#define p_num_lo_hi	r23
#define p_num_lo_lo	r22
#define p_width		r20
#define p_prec		r18
#define p_str_hi	r17
#define p_str_lo	r16	/* parameters	*/

#define ret_hi		r25
#define ret_lo		r24	/* return value	*/

				/*
				 * NB: r16 and r17 must not be
				 * clobbered, but we can easily
				 * restore them at return time since
				 * we are going to return the string
				 * pointer anyway.
				 */
#define r_count   	r17	/* exponent and loop counter */
#define r_dp      	r16	/* position of decimal point */

    TEXT_SEG(fplib, dtostrf)
    FUNCTION(dtostrf)

GLOBAL(dtostrf)
	push	YH
	push	YL		; save frame pointer
	push	p_str_hi
	push	p_str_lo	; save &string
	X_movw	YL, p_str_lo	; Y points to string
	X_movw	r16, p_num_hi_lo
	add	r16, r16
	adc	r17, r17
	cpi	r17, 0xff	; NAN ?
	brne	1f
	ldi	rA3, 'N'
	ldi	rA2, 'A'
	st	Y+, rA3		; 'N'
	st	Y+, rA2		; 'A'
	st	Y+, rA3		; 'N'
	rjmp	10f
1:				; if (num < 0) {num = -num; *string = '-';}
	push	p_width		; save width
	tst	p_num_hi_hi	; num < 0?
	brpl	1f
	ldi	r16, '-'	; num is negative
	st	Y+, r16		;  write '-' sign
	andi	rA3, 0x7F	;  make num positive
1:				; num += (0.5 * 10^-p_precision);
	mov	r_dp, p_prec	; decimal point is at precision + 1
	inc	r_dp		;  when counting down to 0
	push	p_num_hi_hi
	push	p_num_hi_lo
	push	p_num_lo_hi
	push	p_num_lo_lo	; save num
	mov	rA0, p_prec
	clr	rA1
	clr	rA2
	clr	rA3		; A = precision
	XCALL   __floatsisf ; now A = (float)precision
	ori	rA3, 0x80	; now A = (float) -precision
	X_movw	rB2, rA2
	X_movw	rB0, rA0
	ldi	rA3, 0x41
	ldi	rA2, 0x20
	clr	rA1
	clr	rA0		; A = 10.0
	RCALL	_U(pow)		; now A = 10^ -precision
	ldi	rB3, 0xff
	ldi	rB2, 0xff	; rB3:rB2 = -1
	RCALL	_U(ldexp)	; now A = (0.5 * 10^-precision)
	pop	rB0
	pop	rB1
	pop	rB2
	pop	rB3		; B = num
	XCALL	__addsf3	; now A = num + (0.5 * 10^-precision)
	mov	r_count, r_dp	; count becomes power10 + dp.
	cpi	r_dp, 1		; force dp to 0 if dp = 1 i.e. precision = 0
	brne	1f
	clr	r_dp
1:			   ; while (num >= 10.0) {num /= 10; count++;}
	ldi	rB3, 0x41
	ldi	rB2, 0x20
	clr	rB1
	clr	rB0		; B = 10.0
	cp	rA0, rB0
	cpc	rA1, rB1
	cpc	rA2, rB2
	cpc	rA3, rB3	; num >= 10.0?
	brlt	2f
	XCALL	__divsf3	; num /= 10.0
	inc	r_count		; count++
	rjmp	1b
2:				; for (i = count; i > 0; count--;)
	push	rA3		;  {n = num; n += '0'; *string++ = n; num -= n;
	push	rA2		;   num *= 10; if (i == dp) *string = '.';}
	push	rA1
	push	rA0
	XCALL   __fixsfsi   ; convert num to long ( =n)
	mov	r21, rA0 	; n = num
	subi	r21, -'0'	; n += '0'
	st	Y+, r21		; *string++ = n
	XCALL	__floatsisf	; convert n to float
	pop	rB0
	pop	rB1
	pop	rB2
	pop	rB3		; B = num
	XCALL	__subsf3	; A = (A - B)
	subi	rA3, 0x80	; A = -(A - B) = B - A  -> num -= n
	ldi	rB3, 0x41
	ldi	rB2, 0x20
	clr	rB1
	clr	rB0		; B = 10.0
	XCALL	__mulsf3	; num *= 10
	cp	r_count, r_dp	; decimal point here?
	brne	3f
	ldi	r21 , '.'
	st	Y+, r21		; write decimal point
3:
	dec	r_count
	brne	2b

				; adjust result

	st	Y, __zero_reg__	; terminate string
	pop	r21		; get width again
	pop	ZL		; Y points to end of string
	pop	ZH		; Z points to start of string
	push	ZH
	push	ZL		; save &string again
	mov	p_width, r21
	tst	p_width		; width < 0?
	brpl	1f
	com	p_width		; make width positive
	inc	p_width
				; Need // in next line to stop doxygen
				; from thinking strlen is a variable.
1:				; // strlen = Y - Z
	X_movw	rA2, YL
	X_movw	rA0, ZL
	sub	rA2, rA0
	sbc	rA3, rA1	; rA2 = strlen
	mov	r_count, p_width
	sub	r_count, rA2	; r_count = # of leading/trailing spaces
	ldi	rA3, ' '
	cp	rA2, p_width	; if (strlen >= abs(width)) exit
	brge	11f
	tst	r21		; width < 0?
	brmi	4f
				; right adjust with leading spaces
	adiw	YL, 1		; now Y points to end+1 of string
	adiw	ZL, 1
	add	ZL, p_width
	adc	ZH, __zero_reg__ ; now Z points to end+1 of final string
	inc	rA2		; rA2 = strlen+1
2:				; right shift string
	ld	r21, -Y
	st	-Z, r21
	dec	rA2
	brne	2b
3:				; make leading spaces
	st	-Z, rA3
	dec	r_count
	brne	3b
	rjmp	11f
4:				; left adjust -- make trailing spaces
	st	Y+, rA3
	dec	r_count
	brne	4b
10:
	st	Y, __zero_reg__	; terminate string
11:
	pop	ret_lo
	pop	ret_hi		; restore &string as return address
	X_movw	p_str_lo, ret_lo
	pop	YL
	pop	YH		; restore frame pointer
	ret

	ENDFUNC
;-----------------------------------------------------------------------------------

#endif /* not __DOXYGEN__ */
