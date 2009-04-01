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

/** \file */

/** \ingroup avr_string
    \fn int ffs (int val);

    \brief This function finds the first (least significant) bit set in the input value.

    \returns The ffs() function returns the position of the first
    (least significant) bit set in the word val, or 0 if no bits are set.
    The least significant bit is position 1.

    \note For expressions that are constant at compile time, consider
    using the \ref _FFS macro instead.
*/

#ifndef	__DOXYGEN__

#include "macros.inc"

#define	val_lo	r24
#define	val_hi	r25
#define	cntr	r30

    ASSEMBLY_CLIB_SECTION
    .global	_U(ffs)
    .type	_U(ffs), @function
_U(ffs):

	ldi	cntr, 1
	tst	val_lo
	brne	2f
	or	val_lo, val_hi
	breq	9f
	ldi	cntr, 8
1:	inc	cntr
2:	ror	val_lo
	brcc	1b
	mov	r24, cntr
	clr	r25
9:	ret

    .size  _U(ffs), . - _U(ffs)
    .end
#endif	/* not __DOXYGEN__ */
