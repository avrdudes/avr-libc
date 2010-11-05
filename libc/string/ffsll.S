/* Copyright (c) 2005, 2007 Dmitry Xmelkov
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

/** \file */

/** \ingroup avr_string
    \fn int ffsll (long long val);

    \brief Same as ffs(), for an argument of type long long.	*/

#ifndef	__DOXYGEN__

#include "macros.inc"

#define	val_0	r18
#define	val_8	r19
#define	val_16	r20
#define	val_24	r21
#define	val_32	r22
#define	val_40	r23
#define	val_48	r24
#define	val_56	r25

#define	wrd_lo	r30
#define	wrd_hi	r31
#define	cntr	r18

    ASSEMBLY_CLIB_SECTION
    .global	_U(ffsll)
    .type	_U(ffsll), @function
_U(ffsll):

	X_movw	wrd_lo, val_0
	ldi	cntr, 1
	sbiw	wrd_lo, 0
	brne	1f
	X_movw	wrd_lo, val_16
	subi	cntr, -16
	sbiw	wrd_lo, 0
	brne	1f
	X_movw	wrd_lo, val_32
	subi	cntr, -16
	sbiw	wrd_lo, 0
	brne	1f
	X_movw	wrd_lo, val_48
	subi	cntr, -16
	sbiw	wrd_lo, 0
	breq	9f
	
1:	tst	wrd_lo
	brne	3f
	subi	cntr, -7
	mov	wrd_lo, wrd_hi
2:	inc	cntr
3:	ror	wrd_lo
	brcc	2b
	
	mov	r24, cntr
	clr	r25
9:	ret
	
    .size  _U(ffsll), . - _U(ffsll)
    .end

#endif	/* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
