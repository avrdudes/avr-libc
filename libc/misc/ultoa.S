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

#if	!defined (__DOXYGEN__)

#include "asmdef.h"

/* char *ultoa (unsigned long val, char *s, int radix)	*/

#define val_lo	r22
#define str_lo	r20
#ifdef __AVR_TINY__
#define rdx_lo	r26
#define rdx_hi	r27
#else
#define rdx_lo	r18
#define rdx_hi	r19
#endif


ENTRY	ultoa
ENTRY	__ultoa
#ifdef __AVR_TINY__
        ;; Radix is passed on the stack
	in	ZL, SPL_IO_ADDR
	in	ZH, SPH_IO_ADDR
	X_adiw 	ZL, 1 + 2	; 2 pushed (RET-address).
	ld	rdx_lo, Z+
	ld	rdx_hi, Z+
#endif

    ; Check radix
	cpi	rdx_lo, 37
	cpc	rdx_hi, __zero_reg__
	brsh	1f
	cpi	rdx_lo, 2
	brlo	1f
	XJMP	_U(__ultoa_ncheck)

1:	X_movw	ZL, str_lo
	st	Z, __zero_reg__
	X_movw	r24, str_lo
	ret

ENDFUNC

#endif	/* !__DOXYGEN__ */
