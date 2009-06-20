/* Copyright (c) 2009  Dmitry Xmelkov
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
   POSSIBILITY OF SUCH DAMAGE.	*/

/* $Id$	*/

#ifndef	__DOXYGEN__

#include <avr/io.h>

#if	E2END && __AVR_ARCH__ > 1

#include <avr/eeprom.h>
#include "asmdef.h"
#include "eedef.h"

/* void eeprom_update_block (const void *sram, void *eepr, size_t n)
 */

#define	sram_lo	r24
#define	eepr_lo	r22

ENTRY	eeprom_update_block

#if	RAMEND > 0xFF  ||  E2END > 0xFF
	X_movw	XL, sram_lo
	add	XL, n_lo
	adc	XH, n_hi
	subi	n_lo, lo8(1)
	sbci	n_hi, hi8(1)
#else
	mov	XL, sram_lo
	add	XL, n_lo
	subi	n_lo, lo8(1)
#endif
	brlo	3f

#if	E2END > 0xFF
	X_movw	addr_lo, eepr_lo
	add	addr_lo, n_lo
	adc	addr_hi, n_hi
#else
	mov	addr_lo, eepr_lo
	add	addr_lo, n_lo
#endif

1:	ld	r18, -X
	XCALL	eeprom_update_r18
2:	subi	n_lo, lo8(1)

#if	RAMEND > 0xFF  ||  E2END > 0xFF
	sbci	n_hi, hi8(1)
#endif

	brsh	1b
3:	ret

ENDFUNC

#endif	/* E2END && __AVR_ARCH__ > 1 */
#endif	/* !__DOXYGEN__ */
