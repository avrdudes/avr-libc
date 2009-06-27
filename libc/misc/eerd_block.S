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

/* void eeprom_read_block (void *sram, const void *eepr, size_t n)
   Input:
	sram	- SRAM address (dst)
	eepr	- EEPROM address (src)
	n	- number of bytes to read

   void eeprom_read_blraw (const void *addr, X-pointer, size_t n)
   This is an internal function to obtain the word/dword reading.
   Input:
	addr <r25.r24>	- EEPROM address
	<XH,XL>		- SRAM (or register) address
	n <r21.r20>	- number of bytes
   This function can write result into r25..r22 with ST command. It is
   absent in case of XMEGA chips.
 */

#define sram_lo	r24	/* SRAM address arg of eeprom_read_block()	*/
#define eepr_lo	r22	/* EEPROM address arg of eeprom_read_block()	*/
#define eepr_hi	r23

ENTRY eeprom_read_block

#if  __AVR_XMEGA__	/* --------------------------------------------	*/

  ; Load base address of NVM.
	ldi	ZL, lo8(NVM_BASE)
	ldi	ZH, hi8(NVM_BASE)

  ; Wait until NVM is not busy.
1:	ldd	XL, Z + NVM_STATUS - NVM_BASE
	sbrc	XL, NVM_NVMBUSY_bp
	rjmp	1b

  ; Enable EEPROM mapping into data space.
	ldd	XL, Z + NVM_CTRLB - NVM_BASE
	ori	XL, NVM_EEMAPEN_bm
	std	Z + NVM_CTRLB - NVM_BASE, XL

  ; Correct EEPROM address to read from data space.
	subi	eepr_lo, lo8(-MAPPED_EEPROM_START)
	sbci	eepr_hi, hi8(-MAPPED_EEPROM_START)

  ; Perform reading.
	XJMP	memcpy

#elif  E2END <= 0xFF	/* --------------------------------------------	*/

# if  RAMEND <= 0xFF
	mov	XL, sram_lo
# else
	X_movw	XL, sram_lo
# endif
	mov	addr_lo, eepr_lo

ENTRY eeprom_read_blraw

	mov	ZL, addr_lo
1:	sbic	_SFR_IO_ADDR (EECR), EEWE
	rjmp	1b
# ifdef	 EEARH
	; This is for chips like ATmega48: the EEAR8 bit must be cleaned.
	out	_SFR_IO_ADDR (EEARH), __zero_reg__
# endif
	rjmp	3f
2:	out	_SFR_IO_ADDR (EEARL), ZL
	sbi	_SFR_IO_ADDR (EECR), EERE
	inc	ZL
	in	__tmp_reg__, _SFR_IO_ADDR (EEDR)
	st	X+, __tmp_reg__
3:	subi	n_lo, lo8(1)
	brsh	2b
	ret

#else	/* ------------------------------------------------------------	*/

ENTRY eeprom_read_block

	X_movw	XL, sram_lo
	X_movw	addr_lo, eepr_lo

ENTRY eeprom_read_blraw
	X_movw	ZL, addr_lo
1:	sbic	_SFR_IO_ADDR (EECR), EEWE
	rjmp	1b
	rjmp	3f
2:	out	_SFR_IO_ADDR (EEARH), ZH
	out	_SFR_IO_ADDR (EEARL), ZL
	sbi	_SFR_IO_ADDR (EECR), EERE
	adiw	ZL, 1
	in	__tmp_reg__, _SFR_IO_ADDR (EEDR)
	st	X+, __tmp_reg__
3:	subi	n_lo, lo8(1)
	sbci	n_hi, hi8(1)
	brsh	2b
	ret

#endif	/* ------------------------------------------------------------	*/

ENDFUNC

#endif	/* E2END && __AVR_ARCH__ > 1 */
#endif	/* !__DOXYGEN__ */
