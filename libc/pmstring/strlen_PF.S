/* Copyright (c) 2006, Carlos Lamas

   based on libc/pmstring/strlen_P.S which is
   Copyright (c) 2002, Marek Michalkiewicz

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

#if !defined(__AVR_TINY__)

#include "asmdef.h"

#define src_b3 r25	/* MSB, ignored */
#define src_b2 r24
#define src_b1 r23
#define src_b0 r22

ENTRY _U(strlen_PF)

#ifndef __AVR_HAVE_ELPM__
	X_movw	src_b2, src_b0
	XJMP	_U(strlen_P)
#else /* Have ELPM */

	LPM_R0_ZPLUS_INIT src_b2
	X_movw	ZL, src_b0

.L_strlen_PF_loop:

	LPM_R0_ZPLUS_NEXT src_b2
	tst	r0
	brne	.L_strlen_PF_loop

; return RAMPZ:Z - 1 - src = (-1 - src) + RAMPZ:Z = ~src + RAMPZ:Z

	com	src_b0
	com	src_b1
	add	src_b0, ZL
	adc	src_b1, ZH
	X_movw	src_b2, src_b0	; size_t is 16 bits
	LPM_R0_ZPLUS_FINI
	ret
#endif /* Have ELPM */

ENDFUNC

#endif /* !defined(__AVR_TINY__) */
