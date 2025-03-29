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

#if !defined(__DOXYGEN__)

#include "asmdef.h"

TINY_WEAK_ALIAS _U(memmem_P) _U(memmem)

#define s1_hi	r25
#define s1_lo	r24
#define	len1_hi	r23
#define	len1_lo	r22
#define s2_hi	r21
#define s2_lo	r20
#define	len2_hi	r19
#define	len2_lo	r18

#ifdef __AVR_TINY__
#define c1    r28           /* char from s1[] */
#else
#define c1    r17           /* char from s1[] */
#endif
#define c2    __tmp_reg__   /* char from s2[]: tuned for classic lpm instr. */
#define beg2  __zero_reg__  /* begin of s2: s2[0] */

#ifdef	Lprogmem
# define memmem  memmem_P
# define LOAD	 X_lpm
#else
# define LOAD	 ld
#endif

ENTRY memmem
#ifdef __AVR_TINY__
	;; r18/r19 are callee-saved.
	push	len2_lo
	push	len2_hi
	;; len is passed on the stack.
	in	ZL, SPL_IO_ADDR
	in	ZH, SPH_IO_ADDR
	X_adiw 	ZL, 1 + 4	; 4 pushed (RET-address and r18/r19).
	ld	len2_lo, Z+     ; r18
	ld	len2_hi, Z+     ; r19
#endif /* AVRrc */

	cpi	len2_lo, 0
	cpc	len2_hi, len2_lo
	breq	.L_ret			; s2[] is empty

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
	X_sbiw	s1_lo, 1		; restore after post-increment
	pop	c1
	clr	__zero_reg__

.L_ret:
#ifdef __AVR_TINY__
	pop	len2_hi
	pop	len2_lo
#endif /* AVRrc */
	ret

ENDFUNC

#endif /* not __DOXYGEN__ */
