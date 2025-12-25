/* Copyright (c) 2009  Dmitry Xmelkov
   Copyright (c) 2025  Georg-Johann Lay
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

#include <avr/io.h>

#if	E2END && __AVR_ARCH__ > 1

#include <avr/eeprom.h>
#include "asmdef.h"
#include "eedef.h"

;;; uint24_t eeprom_read_u24 (const uint24_t *addr);
;;; int24_t  eeprom_read_i24 (const int24_t *addr);

ENTRY	eeprom_read_u24
ENTRY	eeprom_read_i24

#if __AVR_XMEGA__

    XCALL   eeprom_mapen
    ld      r22, Z
    ldd     r23, Z+1
    ldd     r24, Z+2
    ret

#else

    ldi     XL, 22          ; start address to write: r22
# if  RAMEND > 0xFF
    ldi     XH, 0
# endif

    ldi     n_lo, lo8(3)
# if  E2END > 0xFF
    ldi     n_hi, hi8(3)
# endif

    XJMP    eeprom_read_blraw

#endif /* Xmega */

ENDFUNC

#endif	/* E2END && __AVR_ARCH__ > 1 */
