/* Copyright (c) 2002, 2005, 2006, 2007 Reiner Patommel
   Copyright (c) 2007  Dmitry Xmelkov
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

/*
   strcasecmp_P.S
   Case insensitive compare

   Contributors:
     Created by Reiner Patommel
*/


#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "asmdef.h"

#define s1_hi r25
#define s1_lo r24
#define s2_hi r23
#define s2_lo r22

#define ret_hi r25
#define ret_lo r24

#define tmp r22

ENTRY _U(strcasecmp_P)
	X_movw	ZL, s2_lo
	X_movw	XL, s1_lo

1:	ld	ret_lo, X+		; *s1++
	cpi	ret_lo, 'A'		; if in [A-Z] then tolower()
	brlt	2f
	cpi	ret_lo, 'Z'+1
	brge	2f
	subi	ret_lo, 'A'-'a'

2:	X_lpm	tmp, Z+			; *s2++
	cpi	tmp, 'A'		; if in [A-Z] then tolower()
	brlt	3f
	cpi	tmp, 'Z'+1
	brge	3f
	subi	tmp, 'A'-'a'

3:	sub	ret_lo, tmp		; compare
	cpse	tmp, __zero_reg__	; break, if end of string
	breq	1b

	sbc	ret_hi, ret_hi		; sign extension
	ret

ENDFUNC

#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
