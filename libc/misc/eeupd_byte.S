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

#if !defined(__AVR_TINY__)

#ifndef	__DOXYGEN

#include <avr/io.h>

#if	E2END && __AVR_ARCH__ > 1

#include <avr/eeprom.h>
#include "asmdef.h"
#include "eedef.h"

/* void eeprom_update_byte (unsigned char *eepr, unsigned char val)
   void eeprom_update_r18 (unsigned char *eepr, r18)
 */

ENTRY	eeprom_update_byte
	mov	r18, r22

ENTRY	eeprom_update_r18

#if	__AVR_XMEGA__

	XCALL	eeprom_mapen
	ld	__tmp_reg__, Z
	cp	__tmp_reg__, r18
	breq	1f
	XCALL	eeprom_write_r18
	sbiw	addr_lo, 1		; restore initial value
1:	sbiw	addr_lo, 1
	ret

#else

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

# if	 E2END > 0xFF
	sbiw	addr_lo, 1
# else
	subi	addr_lo, 1
# endif

	in	__tmp_reg__, _SFR_IO_ADDR (EEDR)
	cp	__tmp_reg__, r18
	breq	2f

# if	 defined (EEPM0) && defined (EEPM1)
	; Set programming mode: erase and write.
	out	_SFR_IO_ADDR (EECR), __zero_reg__
# elif	 defined (EEPM0) || defined (EEPM1)
#  error	/* Unknown EECR register.	*/
# endif

	out	_SFR_IO_ADDR (EEDR), r18
	in	__tmp_reg__, _SFR_IO_ADDR (SREG)
	cli
	sbi	_SFR_IO_ADDR (EECR), EEMWE
	sbi	_SFR_IO_ADDR (EECR), EEWE
	out	_SFR_IO_ADDR (SREG), __tmp_reg__
2:	ret

#endif	/* !__AVR_XMEGA__ */

ENDFUNC

#endif	/* E2END && __AVR_ARCH__ > 1 */

#endif	/* !__DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
