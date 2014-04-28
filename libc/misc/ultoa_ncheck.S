/* Copyright (c) 2012  Georg-Johann Lay
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

/* $Id$	*/

#if	!defined (__DOXYGEN__)
#if	!defined (__AVR_TINY__)

#include "asmdef.h"

/* char *__ultoa_ncheck (unsigned long val, char *s, unsigned char radix)
   This function is the utoa() without checking the radix for 2..36 margins.
 */

#define val_lo	r22
#define val_hi	r23
#define val_hlo	r24
#define val_hhi	r25
#define str_lo	r20
#define radix	r18

#define counter	r19
#define digit	r26
#define sign	r27


ENTRY	__ultoa_ncheck
	clr	sign

ENTRY	__ultoa_common
	X_movw	ZL, str_lo

1:  ; Saves one iteration of the digit-loop:
    ; If val < radix we can use the low byte of val as digit
	mov	digit, val_lo
	cp	val_lo, radix
	cpc	val_hi, __zero_reg__
	cpc	val_hlo, __zero_reg__
	cpc	val_hhi, __zero_reg__
    ; now C is set, if val < radix
	sbc	counter, counter
	bst	counter, 0
	brts	4f
    ; counter == 0 here

    ; If val >= radix, then pop one digit from val
	clr	digit

2:  ; Vanilla 32:8 quotient and remainder to pop the digit
    ; digit <- val % radix
    ; val   <- val / radix
	lsl	val_lo
	rol	val_hi
	rol	val_hlo
	rol	val_hhi
	rol	digit
	cp	digit, radix
	brlo	3f
	sub	digit, radix
    ; val |= 1
	inc	val_lo
3:  ; Loop the 32 bits
	subi	counter, 8		; 256 / 8 == 32 loops
	brne	2b

4:  ; Convert the digit to ASCII...
	subi	digit, -'0'
	cpi	digit, '9'+1
	brlo	5f
	subi	digit, '0'-'a'+10
5:  ; ... and store it to the reversed string
	st	Z+, digit

    ; Popped all digits?
	brtc    1b

    ; Yes:  Store the sign (if any)
	cpse	sign, __zero_reg__
	st	Z+, sign

    ; Terminate the string with '\0'
7:	st	Z, __zero_reg__

    ; Reverse the string and return the original string pointer
	X_movw	r24, str_lo
	XJMP	_U(strrev)

ENDFUNC

#endif	/* !__AVR_TINY__ */
#endif	/* !__DOXYGEN__ */
