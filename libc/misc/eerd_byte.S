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

/* uint8_t eeprom_read_byte (uint8_t EEMEM *addr);
 */

#define ret_lo	r24
#define	ret_hi	r25

ENTRY	eeprom_read_byte

#if	__AVR_XMEGA__	/* --------------------------------------------	*/

	rcall	eeprom_mapen
	ld	ret_lo, Z
	clr	ret_hi
	ret

ENTRY	eeprom_mapen

  ; Load base address of NVM.
	ldi	ZL, lo8(NVM_BASE)
	ldi	ZH, hi8(NVM_BASE)

  ; Wait until NVM is not busy.
1:	ldd	r19, Z + NVM_STATUS - NVM_BASE
	sbrc	r19, NVM_NVMBUSY_bp
	rjmp	1b

  ; Enable EEPROM mapping into data space.
	ldd	r19, Z + NVM_CTRLB - NVM_BASE
	ori	r19, NVM_EEMAPEN_bm
	std	Z + NVM_CTRLB - NVM_BASE, r19

  ; Load Z with correct EEPROM address to read from data space.
	movw	ZL, addr_lo
	subi	ZL, lo8(-MAPPED_EEPROM_START)
	sbci	ZH, hi8(-MAPPED_EEPROM_START)

	ret

#else			/* --------------------------------------------	*/

1:	sbic	_SFR_IO_ADDR (EECR), EEWE
	rjmp	1b
# ifdef	 EEARH
#  if	  E2END > 0xFF
	out	_SFR_IO_ADDR (EEARH), addr_hi
#  else
	; This is for chips like ATmega48: the EEAR8 bit must be cleaned.
	out	_SFR_IO_ADDR (EEARH), __zero_reg__
#  endif
# endif
	out	_SFR_IO_ADDR (EEARL), addr_lo
	sbi	_SFR_IO_ADDR (EECR), EERE
	clr	ret_hi
	in	ret_lo, _SFR_IO_ADDR (EEDR)
	ret

#endif			/* --------------------------------------------	*/

ENDFUNC

#endif	/* E2END && __AVR_ARCH__ > 1 */
#endif	/* !__DOXYGEN__ */
