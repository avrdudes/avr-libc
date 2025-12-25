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

#include <avr/io.h>

#if	E2END && __AVR_ARCH__ > 1

#ifdef AVR_TINY
#error AVR_TINY has no EEPROM
#endif

#include <avr/eeprom.h>
#include "asmdef.h"
#include "eedef.h"

/* uint64_t eeprom_read_qword (const uint64_t *addr);
 */

ENTRY	eeprom_read_qword
;;; No ENTRY for [long] double here because this file must not depend
;;; on -m[long-]double=.  This is because avr/devices/<mcu>/Makefile.am
;;; is just copying the main variant to the [long-]double<bits> folders.

#if	__AVR_XMEGA__

    XCALL   eeprom_mapen
    ld      r18, Z
    ldd     r19, Z+1
    ldd     r20, Z+2
    ldd     r21, Z+3
    ldd     r22, Z+4
    ldd     r23, Z+5
    ldd     r24, Z+6
    ldd     r25, Z+7
    ret

#else

    push    addr_lo             ; r24
    push    addr_hi             ; r25
    ;; Read lower bytes to r22..25.
    XCALL   eeprom_read_dword
    pop     ZH
    pop     ZL
    ;; Save lower bytes for later.
    push    r22
    push    r23
    push    r24
    push    r25
    ;; Restore EEPROM address and add 4.
    X_movw  addr_lo,    ZL
    adiw    addr_lo,    4
    ;; Read upper bytes to r22..25
    XCALL   eeprom_read_dword
    ;; Install the lower bytes.
    pop     r21
    pop     r20
    pop     r19
    pop     r18
    ret

#endif /* Xmega ? */

ENDFUNC

#endif	/* E2END && __AVR_ARCH__ > 1 */
