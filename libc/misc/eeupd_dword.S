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

/* void eeprom_update_dword (uint32_t *addr, uint32 val);
   void eeprom_update_float (float *addr, float val);
 */

ENTRY	eeprom_update_dword
ENTRY	eeprom_update_float

	adiw	addr_lo, 3
	mov	r18, r23		; val_hhi
	XCALL	eeprom_update_r18
	XCALL	eeprom_update_byte	; val_hlo
	mov	r18, r21		; val_hi
	XCALL	eeprom_update_r18
	mov	r18, r20		; val_lo
	XJMP	eeprom_update_r18

ENDFUNC

#endif	/* E2END && __AVR_ARCH__ > 1 */
#endif	/* !__DOXYGEN__ */
