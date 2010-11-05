/* Copyright (c) 2007  Dmitry Xmelkov
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

/** \file */

/** \ingroup avr_string
    \fn void *memmem(const void *s1, size_t len1, const void *s2, size_t len2)

    The memmem() function finds the start of the first occurrence of the
    substring \p s2 of length \p len2 in the memory area \p s1 of length
    \p len1.

    \return The memmem() function returns a pointer to the beginning of
    the substring, or \c NULL if the substring is not found. If \p len2
    is zero, the function returns \p s1.	*/

/** \ingroup avr_pgmspace
    \fn void *memmem_P(const void *s1, size_t len1, PGM_VOID_P s2, size_t len2)
    
    The memmem_P() function is similar to memmem() except that \p s2 is
    pointer to a string in program space.	*/

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "asmdef.h"

#define s1_hi	r25
#define s1_lo	r24
#define	len1_hi	r23
#define	len1_lo	r22
#define s2_hi	r21
#define s2_lo	r20
#define	len2_hi	r19
#define	len2_lo	r18

#define beg2	r17	/* begin of s2: s2[0]	*/
#define c1	r16	/* char from s1[]	*/
#define	c2	r0	/* char from s2[]: tuned for classic lpm instr.	*/

#ifdef	Lprogmem
# define memmem  memmem_P
# define LOAD	 X_lpm
#else
# define LOAD	 ld
#endif

ENTRY memmem
	cp	len2_lo, __zero_reg__
	cpc	len2_hi, __zero_reg__
	breq	.L_ret			; s2[] is empty
	
	push	beg2
	push	c1

	add	len2_lo, s2_lo		; len2 = &(s2[len2])
	adc	len2_hi, s2_hi
	add	len1_lo, s1_lo		; len1 = &(s1[len1])
	adc	len1_hi, s1_hi

	X_movw	ZL, s2_lo
	LOAD	beg2, Z+		; beg2 = s2[0]
	X_movw	s2_lo, ZL		; save: address of s2[1]
	
1:	X_movw	XL, s1_lo		; goto to begin of s1[]

2:	cp	XL, len1_lo		; find first char that is matched
	cpc	XH, len1_hi
	brsh	.L_nomatch
	ld	c1, X+
	cp	c1, beg2
	brne	2b

	X_movw	s1_lo, XL		; store address

	X_movw	ZL, s2_lo
3:	cp	ZL, len2_lo		; compare strings
	cpc	ZH, len2_hi
	brsh	.L_match		; end of s2[] --> OK
	cp	XL, len1_lo
	cpc	XH, len1_hi
	brsh	.L_nomatch		; s1[] tail is too short
	ld	c1, X+
	LOAD	c2, Z+
	cp	c1, c2
	breq	3b
	rjmp	1b			; no equal
	
.L_nomatch:
	ldi	s1_lo, lo8(1)
	ldi	s1_hi, hi8(1)
.L_match:
	sbiw	s1_lo, 1		; restore after post-increment
	pop	c1
	pop	beg2
.L_ret:
	ret

ENDFUNC

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
