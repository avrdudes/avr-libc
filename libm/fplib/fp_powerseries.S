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

/*
    fp_powerseries.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 * A = powerseries(x[A])
 *   = (((Z[0]*(*PXX))+Z[1])*(*PXX)+Z[2])*(*PXX)...
 *      until step counter in (*Z++)
 *   power argument in A
 *   pointer to power factor table at Z  ( PFT[] )
 */

#if !defined(DOXYGEN)

#include "gasava.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __fp_powerseries)
          FUNCTION(__fp_powerseries)

 #define rGrade rS5
 #define rFlags rS4
 #define rArg3  rS3
 #define rArg2  rS2
 #define rArg1  rS1
 #define rArg0  rS0

GLOBAL(__fp_powerseries)
    MOV    rT0,rA3
    RCALL  _U(__fp_split1)	; call fp_split before pushing

    PUSH   rS0
    PUSH   rS1
    PUSH   rS2
    PUSH   rS3
    PUSH   rS4
    PUSH   rS5
    MOV    rFlags,rT0		;

    MOV    rArg3,rA3
    MOV    rArg2,rA2
    MOV    rArg1,rA1
    MOV    rArg0,rA0
    LPMRdZpp(rGrade)		; first entry of fp table is byte with entry count
    RCALL  fp_powerloop

    LPMRdZpp(rGrade)		; increment first (last access or loop counter)
    TST    rGrade
    BREQ   fp_power200		; no dividing

    PUSH   rA3
    PUSH   rA2
    PUSH   rA1
    PUSH   rA0

    MOV    rA0,rArg0
    MOV    rA1,rArg1
    MOV    rA2,rArg2
    MOV    rA3,rArg3		; get power series argument again
    RCALL  fp_powerloop

    POP    rB0
    POP    rB1
    POP    rB2
    POP    rB3
    RCALL  _U(__divsf3x)	; this clears rT0

 fp_power200:
    POP    rS5
    POP    rS4
    POP    rS3
    POP    rS2
    POP    rS1
    POP    rS0

	/* rT0 must be cleared : no extended rounding precision
	 * divsf3 clears rT0
	 * if execution path branches directely the LPM did load zero to T0 = rT0
	 * * if ATmega161 (or other enhanced cores used) LPM RX does not clear rT0
	 */
    RJMP   _U(__fp_merge)

 fp_powerloop:
                               ; AX preset with argument, rFlags.7 sign of AX
    RCALL  _U(__fp_flashconst)  ; BX = *array[n]

    BST    rB2,7               ; store sign(B) to T
    ORI    rB2,0x80            ; set implicit one
    RJMP   fp_powerloop11

 fp_powerloop10:
    MOV    rB0,rArg0
    MOV    rB1,rArg1
    MOV    rB2,rArg2
    MOV    rB3,rArg3            ; get power series argument

 fp_powerloop11:

    PUSH   ZL
    PUSH   ZH
    ; CLR    rBE		; __mulsf3x does not use rBE cleared
    RCALL  _U(__mulsf3x)	; AX *= BX, sign T and rFlags stays untouched
    POP    ZH
    POP    ZL
    RCALL  _U(__fp_flashconst)	; BX = *array[n]
    CLR    rBE

	/* now set sign right :
	 * rB2.7 is sign(B)
	 * rFlags.7 is sign of Argument
	 * T is sign of previous addition
	 * -> sign of mul res = rFlags.7 ^ T => rT1c.7
	 * T = (rFlags.7 ^ T) ^ rB2.7
	 */
    BLD    rT0,7		;
    EOR    rT0,rFlags		;
    MOV    rT1c,rT0
    EOR    rT0,rB2
    BST    rT0,7		; T = sign(AX)^sign(BX)
    ORI    rB2,0x80		; set implicit one

    PUSH   ZH
    RCALL  _U(__addsf3x)	; AX += BX
    POP    ZH
				; now normalize and round
    TST    rA3			; exponent == 0
    BREQ   fp_powerloop20	; underflow
 fp_powerloop19:
    TST    rA2
    BRMI   fp_powerloop20	; shift left until MSB set
    DEC    rA3
    ADD    rAE,rAE
    adc    rA0,rA0
    adc    rA1,rA1
    adc    rA2,rA2
    RJMP   fp_powerloop19

 fp_powerloop20:
    DEC    rGrade
    BRNE   fp_powerloop10	;
    RET

          ENDFUNC

#endif /* not DOXYGEN */
