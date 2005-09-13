/*  -*- Mode: Asm -*-  */

/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
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
   POSSIBILITY OF SUCH DAMAGE. 
*/

/* $Id$ */

/*
    mulsf3x.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 *--- multiplication kernel : used by other high level functions
 * multiply two extended numbers RX = AX * BX
 * sign not considered, resulting stored in T by ___mulsf3
 * AX  rA3 : rA2:rA1:rA0:rAE
 * BX  rB3 : rB2:rB1:rB0:rBE
 * RX  rA3 : rA2:rA1:rA0:rAE
 */

#if !defined(__DOXYGEN__)

#include "gasava.inc"
#include "macros.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __mulsf3x)
          FUNCTION(__mulsf3x)

GLOBAL(__mulsf3x)
    TST     rA3
    BREQ    2f

    TST     rB3
    BREQ    2f

     SUBI    rA3,0x7F          ; exp(A) now signed char
     SUBI    rB3,0x7F          ; exp(B) now signed char

     ADD     rA3,rB3           ; add two signed registers
     BRVC    1f                ; no signed overflow
     BRMI    100f              ; signed overflow : if now negative -> positive overflow
2:
     RJMP    _U(__fp_zerox)

1:
     SUBI    rA3,0x81          ; = ADI,0x7F
     CPI     rA3,0xFF
     BREQ    2b                ; no (unsigned overflow) -> signed underflow

    ; now multiply mantissa A[rA2:rA1:rA0] * B[rb5:rb4:rb3:rB2:rB1:rB0]
    ; result : [rr5:rr4:rr3:rr2:rr1:rr0]
    #define loop rTI0
    #define rr5 rA2  /* push rA2 before */
    #define rr4 rA1  /* push rA1 before */
    #define rr3 rA0  /* push rA0 before */
    #define rr2 rAE  /* not used, but right position later on */
    #define rr1 rT1c /* free to use, needed after pop */
    #define rr0 rT0  /* scratch register, needed after pop */
    #define rb5 rTI1 /*  */
    #define rb4 rBE /* not used */
    #define rb3 rB3 /* no longer used */

    MOV     rb4,rA0          ; rB4 not yet needed
    CLR     rr0
    CLR     rr1              ; not conclusive zero for high level function
    CLR     rr2
    CLR     rr3
    CLR     rb3

    LDI     loop,8           ; loop counter
1:
    LSR     rb4
    BRCC    2f
    ADD     rr0,rB0
    adc     rr1,rB1
    adc     rr2,rB2
    adc     rr3,rb3
2:
    ADD     rB0,rB0
    adc     rB1,rB1
    adc     rB2,rB2
    adc     rb3,rb3
    DEC     loop
    BRNE    1b
    LDI     loop,8           ; loop counter

    MOV     rb5,rA1          ; rb5 not yet needed
    CLR     rr4              ; rb4 is allready clear
    LDI     loop,8           ; loop counter
1:
    LSR     rb5
    BRCC    2f
    ADD     rr1,rB1
    adc     rr2,rB2
    adc     rr3,rb3
    adc     rr4,rb4
2:
    ADD     rB1,rB1
    adc     rB2,rB2
    adc     rb3,rb3
    adc     rb4,rb4
    DEC     loop
    BRNE    1b

    MOV     loop,rA2          ; loop no longer needed, check
    CLR     rr5               ; rb5 is allready clear
1:
    LSR     loop
    BRCC    2f
    ADD     rr2,rB2
    adc     rr3,rb3
    adc     rr4,rb4
    adc     rr5,rb5
2:
    ADD     rB2,rB2
    adc     rb3,rb3
    adc     rb4,rb4
    adc     rb5,rb5
    TST     loop
    BRNE    1b

    ; multiplication done : result in rr5:rr4:rr3:rr2:rr1:rr0
    ;                              =  rA2:rA1:rA0:rAE:rr1:rr0
    ;  normalize  1.0 * 1.0      = 1.0
    ;                          0x800000 * 0x800000 = 0x40 00 00 00 00 00
    ;                          1.999999 * 1.999999 = 3.99999 ~ 4.0
    ;                          0xFFFFFF * 0xFFFFFF = 0xFF FF FE 00 00 01

    TST     rA2
    BRPL    1f                ; if MSB erg is clr
    INC     rA3               ;
    BRNE    2f
100:
    RJMP    _U(__fp_nanx)     ; returns to ___mulsf3 or a high level function : rT1c ok
1:
    ADD     rr0,rr0
    adc     rr1,rr1
    adc     rAE,rAE
    adc     rA0,rA0
    adc     rA1,rA1
    adc     rA2,rA2

2:
    OR    rr0,rr1             ; rr0 = rT0 which holds the mantissae extension beyond rAE
    RET

          ENDFUNC

#endif /* not __DOXYGEN__ */
