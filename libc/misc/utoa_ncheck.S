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

/* char *__utoa_ncheck (unsigned val, char *s, unsigned char radix)
   This function is the utoa() without checking the radix for 2..36 margins.
 */

#define val_lo	r24
#define val_hi	r25
#define str_lo	r22
#define radix	r20

#define counter	r21
#define digit	r26
#define sign	r27

ENTRY	__utoa_ncheck
	clr	sign

ENTRY	__utoa_common
	X_movw	ZL, str_lo
	clr	counter

1:  ; Vanilla 16:8 quotient and remainder to pop the digit
    ; digit <- val % radix
    ; val   <- val / radix
	clr	digit

2:	lsl	val_lo
	rol	val_hi
	rol	digit
	cp	digit, radix
	brlo	3f
	sub	digit, radix
	inc	val_lo
3:	subi	counter, 16		; 256 / 16 == 16 loops
	brne	2b

    ; Convert the digit to ASCII...
	subi	digit, -'0'
	cpi	digit, '9'+1
	brlo	4f
	subi	digit, '0'-'a'+10
4:  ; ... and store it to the reversed string
	st	Z+, digit

    ; Iterate until all digits are sucked out of VAL.
	sbiw	val_lo, 0
	brne	1b

    ; Store the sign (if any)
	cpse	sign, __zero_reg__
	st	Z+, sign

    ; Terminate the string with '\0'
	st	Z+, __zero_reg__

    ; Reverse the string and return the original string pointer
	X_movw	r24, str_lo
	XJMP	_U(strrev)

ENDFUNC

#endif	/* !__AVR_TINY__ */
#endif	/* !__DOXYGEN__ */
