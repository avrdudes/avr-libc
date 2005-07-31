/* Copyright (c) 2002, Marek Michalkiewicz
   Copyright (c) 2005, Bjoern Haase
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
     eeprom_write_word and eeprom_write_block added by Artur Lipowski
     <LAL@pro.onet.pl>
     Complete rewrite using the original interface by Bjoern Haase
     <bjoern.haase@de.bosch.com>.
 */

#include "macros.inc"
#include "ctoasm.inc"
#include "avr/io.h"
#ifndef __EEPROM_REG_LOCATIONS__
/* 6-byte string denoting where to find the EEPROM registers in memory space.
   Adresses denoted in hex syntax with uppercase letters. Used by the EEPROM
   subroutines.
   First two letters:  EECR address.
   Second two letters: EEDR address.
   Last two letters:   EEAR address.  */
#define __EEPROM_REG_LOCATIONS__ 1C1D1E
#endif

/* As long as we don't have a proper multilib environment: Let's make it
   possible to override the locations defined in the io headers.  */
#ifdef EEPROM_REG_LOCATIONS_OVERRIDE

#undef  __EEPROM_REG_LOCATIONS__
#define __EEPROM_REG_LOCATIONS__ EEPROM_REG_LOCATIONS_OVERRIDE

#define HEXNR CONCAT1(0x , EEPROM_REG_LOCATIONS_OVERRIDE)

#ifdef EECR
#undef EECR
#define EECR _SFR_IO8((HEXNR >> 16) & 0xFF)
#endif

#ifdef EEDR
#undef EEDR
#define EEDR _SFR_IO8((HEXNR >> 8) & 0xFF )
#endif

#ifdef EEAR
#undef EEAR
#define EEAR _SFR_IO8(HEXNR & 0xFF)
#endif

#ifdef EEARH
#undef EEARH
#endif

#ifdef EEARL
#undef EEARL
#define EEARL EEAR
#endif

#endif

#define _EELABEL(x) CONCAT1(__,CONCAT1(x, CONCAT1 (_,__EEPROM_REG_LOCATIONS__)))

/* the same library is used for 2313 and 8515 for now -
   I hope writing 0 to non-existent EEARH doesn't hurt... */
#ifndef EEARH
#define EEARH (EEARL+1)
#endif


#ifdef L_eeprom_read_byte
/* read one byte from EEPROM.
   addr = r26:r27, result = __tmp_reg__ 
   Post increment r26:r27.  */

	.section .text.eeprom, "ax", @progbits
	.global _EELABEL(eeprom_read_byte)

_EELABEL(eeprom_read_byte):
	sbic	_SFR_IO_ADDR(EECR), EEWE
	rjmp	_EELABEL(eeprom_read_byte)	/* make sure EEPROM is ready */
#ifdef EEARH
	out	_SFR_IO_ADDR(EEARH),r27
#endif
	out	_SFR_IO_ADDR(EEARL),r26
	sbi	_SFR_IO_ADDR(EECR), EERE
	adiw	r26,1 /* Increment x register */
	in	__tmp_reg__, _SFR_IO_ADDR(EEDR)
	ret
#endif /* L_eeprom_read_byte */

#ifdef L_eeprom_read_word
/* read one word from EEPROM.
   addr = r26:r27, result = r30:r31
   Post increment r26:r27.  */

	.section .text.eeprom, "ax", @progbits
	.global _EELABEL(eeprom_read_word)

_EELABEL(eeprom_read_word):
	rcall _EELABEL(eeprom_read_byte)
	mov r30,__tmp_reg__
	rcall _EELABEL(eeprom_read_byte)
	mov r31,__tmp_reg__
	ret
#endif

#ifdef L_eeprom_write_byte
/* write a byte to EEPROM
   Address in r26:r27, value in __tmp_reg__
   Post increment r26:r27.  */

	.section .text.eeprom, "ax", @progbits
	.global _EELABEL(eeprom_write_byte)

_EELABEL(eeprom_write_byte):
	sbic	_SFR_IO_ADDR(EECR), EEWE
	rjmp	_EELABEL(eeprom_write_byte)	/* make sure EEPROM is ready */
#ifdef EEARH
	out	_SFR_IO_ADDR(EEARH), r27
#endif
	out	_SFR_IO_ADDR(EEARL), r26
	out	_SFR_IO_ADDR(EEDR),__tmp_reg__
	adiw	r26,1 /* Increment x register */
	in	__tmp_reg__, _SFR_IO_ADDR(SREG)
	cli			; /* no ints between setting EEMWE and EEWE */
	sbi	_SFR_IO_ADDR(EECR), EEMWE
	sbi	_SFR_IO_ADDR(EECR), EEWE
	out	_SFR_IO_ADDR(SREG), __tmp_reg__
	ret
#undef val
#endif /* L_eeprom_write_byte */

#ifdef L_eeprom_write_word
/* write a word to EEPROM
   Address in r26:r27, value in __tmp_reg__ (LSB) and __zero_reg__ (MSB)
   Post increment r26:r27.  */

	.section .text.eeprom, "ax", @progbits
	.global _EELABEL(eeprom_write_word)

_EELABEL(eeprom_write_word):
	rcall _EELABEL(eeprom_write_byte)
	mov __tmp_reg__,__zero_reg__
	rcall _EELABEL(eeprom_write_byte)
	clr __zero_reg__
	ret
#endif

#ifdef L_eeprom_read_block
/* read a block of n (maximum 256) bytes from EEPROM 
   ram_buffer = r30:r31, eeprom_addr = r26:r27, n = __zero_reg__
   an initial value of 0 in __zero_reg__ corresponds to a value of n == 256. */

	.section .text.eeprom, "ax", @progbits
	.global _EELABEL(eeprom_read_block)
	.global _EELABEL(eeprom_read_byte)

_EELABEL(eeprom_read_block):
	rcall _EELABEL(eeprom_read_byte)
	st z+,__tmp_reg__
	dec __zero_reg__
	brne _EELABEL(eeprom_read_block)
	ret
#endif /* L_eeprom_read_block */

#ifdef L_eeprom_write_block
/* Write a block of n (maximum 256) bytes to EEPROM 
   ram_pointer = r30:r31, eeprom_addr = r26:r27, n = __zero_reg__
   an initial value of 0 in __zero_reg__ correspond to a value of n == 256. */

	.section .text.eeprom, "ax", @progbits
	.global _EELABEL(eeprom_write_block)
	.global _EELABEL(eeprom_write_byte)

_EELABEL(eeprom_write_block):
	ld __tmp_reg__,z+
	rcall _EELABEL(eeprom_write_byte)
	dec __zero_reg__
	brne _EELABEL(eeprom_write_block)
	ret
#endif /* L_eeprom_write_block */

.end
