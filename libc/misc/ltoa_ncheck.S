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

#include "asmdef.h"

/* char *__ltoa_ncheck (long val, char *s, unsigned char radix)	*/

#define val_lo	r22
#define val_hi	r23
#define val_hlo	r24
#define val_hhi	r25
#define str_lo	r20
#ifdef __AVR_TINY__
#define rdx_lo	__tmp_reg__
#else
#define rdx_lo	r18
#endif

#define sign	r27	/* Argument for __ultoa_common()	*/

ENTRY	__ltoa_ncheck
#ifdef __AVR_TINY__
        ;; Radix is passed on the stack
	in	ZL, SPL_IO_ADDR
	in	ZH, SPH_IO_ADDR
	X_adiw 	ZL, 1 + 2	; 2 pushed (RET-address)
	ld	rdx_lo, Z
#endif

	clr	sign
	cpi	rdx_lo, 10
	brne	1f
	tst	val_hhi
	brpl	1f

    ; radix == 10 && val < 0: sign = '-' and val = -val
	ldi	sign, '-'
	XCALL	_U(__negsi2)
1:	XJMP	_U(__ultoa_common)

ENDFUNC

#endif	/* !__DOXYGEN__ */
