/* Copyright (c) 2002, Marek Michalkiewicz
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
   eeprom.S

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
 */

#include "macros.inc"
#include "ctoasm.inc"

/* the same library is used for 2313 and 8515 for now -
   I hope writing 0 to non-existent EEARH doesn't hurt... */
#ifndef EEARH
#define EEARH (EEARL+1)
#endif

#define addr_hi rP0
#define addr_lo rP1
#define res_hi rP0
#define res_lo rP1

#ifdef L_eeprom_read_byte
/* read one byte from EEPROM */
/* uint8_t eeprom_read_byte(uint8_t *addr); */
/* addr = r25:r24, result = r25(=0):r24 */

	.section .text
	.global _U(eeprom_read_byte)

_U(eeprom_read_byte):
	sbic	_SFR_IO_ADDR(EECR), EEWE
	rjmp	_U(eeprom_read_byte)	/* make sure EEPROM is ready */
#ifdef EEARH
	out	_SFR_IO_ADDR(EEARH), addr_hi
#endif
	out	_SFR_IO_ADDR(EEARL), addr_lo
	sbi	_SFR_IO_ADDR(EECR), EERE
	clr	res_hi		/* gcc wants result extended to "int"? */
	in	res_lo, _SFR_IO_ADDR(EEDR)
	ret
#endif /* L_eeprom_read_byte */

#ifdef L_eeprom_read_word
/* read a little endian 16-bit word from EEPROM */
/* uint16_t eeprom_read_word(uint16_t *addr); */
/* addr = r25:r24, result = r25:r24 */

	.global _U(eeprom_read_word)

_U(eeprom_read_word):
	sbic	_SFR_IO_ADDR(EECR), EEWE
	rjmp	_U(eeprom_read_word)	/* make sure EEPROM is ready */
#ifdef EEARH
	out	_SFR_IO_ADDR(EEARH), addr_hi
#endif
	out	_SFR_IO_ADDR(EEARL), addr_lo
	sbi	_SFR_IO_ADDR(EECR), EERE
	adiw	addr_lo, 1
	in	__tmp_reg__, _SFR_IO_ADDR(EEDR)
#ifdef EEARH
	out	_SFR_IO_ADDR(EEARH), addr_hi
#endif
	out	_SFR_IO_ADDR(EEARL), addr_lo
	sbi	_SFR_IO_ADDR(EECR), EERE
	mov	res_lo, __tmp_reg__
	in	res_hi, _SFR_IO_ADDR(EEDR)
	ret
#endif /* L_eeprom_read_word */

#ifdef L_eeprom_write_byte
/* write a byte to EEPROM */
/* void eeprom_write_byte(uint8_t *addr, uint8_t val); */
/* addr = r25:r24, val = r22 */
#define val rP3

	.global _U(eeprom_write_byte)

_U(eeprom_write_byte):
	sbic	_SFR_IO_ADDR(EECR), EEWE
	rjmp	_U(eeprom_write_byte)	/* make sure EEPROM is ready */
#ifdef EEARH
	out	_SFR_IO_ADDR(EEARH), addr_hi
#endif
	out	_SFR_IO_ADDR(EEARL), addr_lo
	out	_SFR_IO_ADDR(EEDR), val
	in	__tmp_reg__, _SFR_IO_ADDR(SREG)
	cli			; /* no ints between setting EEMWE and EEWE */
	sbi	_SFR_IO_ADDR(EECR), EEMWE
	sbi	_SFR_IO_ADDR(EECR), EEWE
	out	_SFR_IO_ADDR(SREG), __tmp_reg__
	ret
#undef val
#endif /* L_eeprom_write_byte */

#undef addr_hi
#undef addr_lo
#undef res_hi
#undef res_lo

#define buf_hi rP0
#define buf_lo rP1
#define addr_hi rP2
#define addr_lo rP3
#define n_hi rP4
#define n_lo rP5

#ifdef L_eeprom_read_block
/* read a block of bytes from EEPROM */
/* void eeprom_read_block(void *buf, void *addr, size_t n); */
/* buf = r25:r24, addr = r23:r22, n = r21:r20 */

	.global _U(eeprom_read_block)

_U(eeprom_read_block):
	cp	n_lo, __zero_reg__
	cpc	n_hi, __zero_reg__
	breq	eeprom_read_block_done
	LOAD_X(buf_lo, buf_hi)
eeprom_read_block_busy:
	sbic	_SFR_IO_ADDR(EECR), EEWE
	rjmp	eeprom_read_block_busy	/* make sure EEPROM is ready */
eeprom_read_block_loop:
#ifdef EEARH
	out	_SFR_IO_ADDR(EEARH), addr_hi
#endif
	out	_SFR_IO_ADDR(EEARL), addr_lo
	sbi	_SFR_IO_ADDR(EECR), EERE
	subi	addr_lo, lo8(-1)
	sbci	addr_hi, hi8(-1)
	in	__tmp_reg__, _SFR_IO_ADDR(EEDR)
	st	X+, __tmp_reg__
	subi	n_lo, lo8(1)
	sbci	n_hi, hi8(1)
	brne	eeprom_read_block_loop
eeprom_read_block_done:
	ret
#endif /* L_eeprom_read_block */

