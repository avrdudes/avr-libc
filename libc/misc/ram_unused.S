/* Copyright (c) 2025  Georg-Johann Lay
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

#if defined(RAMEND) && __AVR_ARCH__ != 1

#include "asmdef.h"

.global __init_ram_color        ; init_ram_color.S colors RAM in .init3.
.global __heap_start            ; ldscript

;;; We cannot  .weak __ram_color_start  and then define this
;;; symbol to __heap_start since __heap_start is not known here.
;;;
;;; What we also don't want is to introduce  __ram_color_start  as
;;; a proper variable and read it from RAM.  So for now, we have to
;;; live with the limitation that the user can't adjust the color
;;; start at link time.
#ifndef __ram_color_start
#define __ram_color_start __heap_start
#endif

.weak  __ram_color_end
__ram_color_end = RAMEND + 1

.weak  __ram_color_value
__ram_color_value = 0xaa

ENTRY _get_ram_unused
    ldi     ZL, lo8 (__ram_color_start)
    ldi     ZH, hi8 (__ram_color_start)
.Loop_probe_color:
    ld      r24, Z+
    cpi     R24, lo8(__ram_color_value)
    breq .Loop_probe_color
    X_movw  r24, ZL
    subi    r24, lo8 (__ram_color_start + 1)
    sbci    r25, hi8 (__ram_color_start + 1)
    ret
ENDFUNC

#endif /* RAMEND && AVR_ARCH != 1 */
