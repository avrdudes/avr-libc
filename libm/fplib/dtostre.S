/*  -*- Mode: Asm -*-  */

/* Copyright (c) 2002  Michael Stumpf  <Michael.Stumpf@t-online.de>

   This file is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 2, or (at your option) any later
   version.

   In addition to the permissions in the GNU General Public License, the
   author gives you unlimited permission to link the compiled version of this
   file into combinations with other programs, and to distribute those
   combinations without any restriction coming from the use of this file.
   (The General Public License restrictions do apply in other respects; for
   example, they cover modification of the file, and distribution when not
   linked into a combine executable.)

   This file is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details. */

/* $Id$ */

/*
    dtostre.S is an addition to     FPlib V 0.3.0       ported to avr-as
    for details see readme.dtostre

  const char * dtostre( double f[rP0::rP3], char * s[rP4:rP5], byte ndig[rP6], byte flags[rP7] )

 *----------------------------------------------------------------------------------------------
 */

#include "gasava.inc"
#include "fplib.inc"

#define bitAlignSign 0x01        /* put '+' or ' ' for positives */
#define bitSign      0x02        /* put '+' rather than ' ' */
#define bitUppercase 0x04        /* put 'E' rather 'e' */

          TEXT_SEG(fplib, dtostre)
          FUNCTION(dtostre)

GLOBAL(dtostre)
/* new call convention, move last two args of type "char" */
	mov	rP6, r18	/* rP6 == r19 */
	mov	rP7, r16	/* rP7 == r18 */

	push	r11
	push	r12
	push	r13
	push	r14
	push	r15
	push	r16
	push	r17
	push	YH
	push	YL
	push	rP4		; return this
	push	rP5
	mov	YH, rP4
	mov	YL, rP5

	mov	rSI0, rA3	; copy sign
	mov	rSI1, rA2	; and ..
	add	rSI1, rSI1
	adc	rSI0, rSI0
	brne	2f		; not zero

	ldi	rSI1, ' '
	sbrc	rP7, 1
	ldi	rSI1, '+'	; rSI1 = (flags&bitSign?'+':' ')
	sbrc	rP7, 0
	st	Y+, rSI1
	dec	rP6
	ldi	rA3, '0'
	ldi	rA2, '.'
	ldi	rA1, 'E'
	sbrs	rP7, 2		; if bitUppercase was set
	ori	rA1, 'E' ^ 'e'
	ldi	rA0, '+'
	st	Y+,rA3
	st	Y+,rA2
1:	st	Y+, rA3
	dec	rP6
	brpl	1b
	st	Y+, rA1		/* 'E' */
	st	Y+, rA0		/* '+' */
	st	Y+, rA3		/* '0' */
	st	Y+, rA3		/* '0' */
	rjmp	99f		; exit

2:
	cpi	rSI0, 0xff
	brne	3f		; check for zero and NaN

	ldi	rA3, 'N'
	ldi	rA2, 'a'
	st	Y+, rA3		/* 'N' */
	st	Y+, rA2		/* 'a' */
	st	Y+, rA3		/* 'N' */
	rjmp	99f		; exit

3:				; not NaN
	tst	rA3
	brpl	4f
	ldi	rSI1, '-'
	andi	rA3, 0x7F	; now f is positive
	rjmp	5f
4:	ldi	rSI1, ' '
	sbrc	rP7, 1
	ldi	rSI1, '+'	; rSI1 = (flags&bitSign?'+':' ')
	sbrc	rP7, 0
5:
	st	Y+, rSI1

	mov	rSI0, rP6	; store ndig
	push	rP7		; and flags

	mov	rS0, rA0	; store dblno
	mov	rS1, rA1
	mov	rS2, rA2
	mov	rS3, rA3

; frexp(dblno, (int*) dest);
	mov	rB2, YL
	mov	rB3, YH
	rcall	_U(frexp)	; destroys argument_1

; iexp = *(int*) dest * log2;
	ldd	rA0, Y+0
	ldd	rA1, Y+1	; exponent
	eor	rA2, rA2	; to longint argument
	sbrc	rA1, 7
	com	rA2
	mov	rA3, rA2
	rcall	_U(__floatsisf)	; to float
	ldi	rB0, 0x9B	; lg(2) is 2nd argument
	ldi	rB1, 0x20	; lg(2) = 0.30103 = 0x3e9a209b
	ldi	rB2, 0x9A
	ldi	rB3, 0x3E
	rcall	_U(__mulsf3)	; multiply
	rcall	_U(__fixsfsi)	; to integer
	mov	rS4, rA0	; save exponent, 1 byte only

; if ( iexp  != 0 )
	tst	rA0
	breq	1f

; dblno *= pow(10.0, -(double) iexp)
	rcall	_U(__floatsisf)	; to float
	rcall	_U(__negsf2)	; negative
	mov	rB0, rA0
	mov	rB1, rA1
	mov	rB2, rA2
	mov	rB3, rA3
	ldi	rA0, 0x00	; argument_1 = 10
	ldi	rA1, 0x00
	ldi	rA2, 0x20
	ldi	rA3, 0x41
	rcall	_U(pow)
	mov	rB0, rS0	; argument_2 = dblno
	mov	rB1, rS1
	mov	rB2, rS2
	mov	rB3, rS3
	rcall	_U(__mulsf3)
	mov	rS0, rA0	; new dblno
	mov	rS1, rA1
	mov	rS2, rA2
	mov	rS3, rA3
1:
; The algorithm to determine the decimal exponent above has the
; potential to erroneously return an exponent that might be too
; large.  So we need to give it a try before applying the rounding
; below.  If we find the first digit to become 0, we decrease the
; exponent, and multiply our number again by 10.

	mov	rA0, rS0
	mov	rA1, rS1
	mov	rA2, rS2
	mov	rA3, rS3
	mov	rB2, YL
	mov	rB3, YH
	rcall	_U(modf)
	ldd	rSI1, Y+3	; no need to convert from float to int,
	tst	rSI1		; float 0.0 always has 0 in the MSB
	brne	1f

	dec	rS4		; exp--
	ldi	rB0, 0x00	; argument_2 = 10
	ldi	rB1, 0x00
	ldi	rB2, 0x20
	ldi	rB3, 0x41
	rcall	_U(__mulsf3)
	mov	rS0, rA0	; dblno
	mov	rS1, rA1
	mov	rS2, rA2
	mov	rS3, rA3

1:
; determine rounding:
; if (ndig < ACCURACY) { t = .5; t *= 0.1**ndig; dblno += t; }
	cpi	rSI0, ACCURACY
	brcc	1f
	ldi	rA0, 0x00	; t = 0.5
	ldi	rA1, 0x00
	ldi	rA2, 0x00
	ldi	rA3, 0x3F
	eor	rSI1, rSI1	; for (rSI1 = 0; rSI1 < ndig; rSI1++)
	rjmp	3f
2:	ldi	rB0, 0xCD	; 0.1 => 0x3dcccccd
	ldi	rB1, 0xCC
	ldi	rB2, 0xCC
	ldi	rB3, 0x3D
	rcall	_U(__mulsf3)	; t *= 0.1
	inc	rSI1
3:	cp	rSI1, rSI0
	brlo	2b
	mov	rB0, rS0
	mov	rB1, rS1
	mov	rB2, rS2
	mov	rB3, rS3
	rcall	_U(__addsf3)	; dblno += t
	mov	rS0, rA0	; new dblno
	mov	rS1, rA1
	mov	rS2, rA2
	mov	rS3, rA3
1:
				; for (rSI1 = 0; rSI1 <= ndig; rSI1++)
	eor	rSI1, rSI1
	rjmp	8f
2:
	cpi	rSI1, ACCURACY
	brcc	5f		; more digits than accuracy => pad 0s

; dblno = modf(dblno, (double *) dest) * 10.0;
	mov	rA0, rS0	; next digit
	mov	rA1, rS1
	mov	rA2, rS2
	mov	rA3, rS3
	mov	rB2, YL
	mov	rB3, YH
	rcall	_U(modf)
	ldi	rB0, 0x00	; argument_2 = 10
	ldi	rB1, 0x00
	ldi	rB2, 0x20
	ldi	rB3, 0x41
	rcall	_U(__mulsf3)
	mov	rS0, rA0	; dblno
	mov	rS1, rA1
	mov	rS2, rA2
	mov	rS3, rA3

; *dest++ = '0' + (char)(*(double *) dest);
	ldd	rA0, Y+0
	ldd	rA1, Y+1
	ldd	rA2, Y+2
	ldd     rA3, Y+3
	rcall   _U(__fixsfsi)	; to long int
	mov	rA2, rA0
	subi	rA2, -'0'
	st	Y+, rA2

; if (i == 0)
	tst	rSI1
	brne	7f
	ldi	rA2, '.'
	rjmp	6f
5:				; pad with zeros
	ldi	rA2, '0'
6:	st	Y+, rA2
7:	inc	rSI1		; rSI1++
8:				; loop test rSI1 <= rSI0
	cp	rSI0, rSI1	; compare count - ndig
	brcc	2b

	pop	rA2		; and flags
	ldi	rA1, 'E'
	sbrs	rA2, 2		; if bitUppercase was set
	ori	rA1, 'E' ^ 'e'
	ST	Y+, rA1		; put exponent
	ldi	rA1, '+'	;
	tst	rS4		; exponent
	brpl	1f
	neg	rS4
	ldi	rA1, '-'
1:
	st	Y+, rA1

	; dividend in r24, divisor in r22
	mov	r24, rS4
	ldi	r22, 10		; divisor
	XCALL	_U(__udivmodqi4)
	; quotient in r24, remainder in r25

	subi	rByte, -'0'
	st	Y+, rByte
	subi	r25, -'0'
	st	Y+, r25
99:
	st	Y,__zero_reg__

	pop	rByte		; char *dest
	pop	r25
	pop	YL		; frame pointer
	pop	YH
	pop	r17
	pop	r16
	pop	r15
	pop	r14
	pop	r13
	pop	r12
	pop	r11
	ret

          ENDFUNC

