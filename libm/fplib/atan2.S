/* Copyright (c) 2002, Reiner Patommel
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

/* ---------------------------------------------------------------------------------------
   atan2.S

   Contributors:
     Created by Reiner Patommel
     Changed by Reiner Patommel 31 August 2002
     Changes: swapped arguments x and y

 -*- Mode: Asm -*-

*----------------------------------------------------------------------------------------
* A = atan2(float A, float B) = atan2(float y, float x)
*---------------------------------------------------------------------------------------*/

#include "gasava.inc"
#include "fplib.inc"
#include "macros.inc"
#define Y_hi    r25                 /* rA3 */
#define Y_lo    r24                 /* rA2 */
#define X_hi    r23                 /* rA1 */
#define X_lo    r22                 /* rA0 */
#define Z_hi    r21                 /* rB3 */
#define Z_lo    r20                 /* rB2 */
#define tmp_hi  r19                 /* rB1 */
#define tmp_lo  r18                 /* rB0 */
#define sign    r26
#define lcount  r26

TEXT_SEG(fplib, atan2)
FUNCTION(atan2)

GLOBAL(atan2)
    CP      rA3, __zero_reg__       ; if (y != 0)
    BRNE    _atan2_normalize        ;   calculate
    CP      rB3, __zero_reg__       ; if (y == 0 && x == 0)
    BREQ    _atan2_NAN              ;   return Argument Error
    SBRC    rB3, 7                  ; if (y == 0 && x < 0)
    RJMP    _atan2_PI               ;   return PI
    XJMP    _U(__fp_zero)           ; if (y == 0 && x > 0) return 0

_atan2_PI:
    LDI     rA3, 0x40
    LDI     rA2, 0x49
    LDI     rA1, 0x0F
    LDI     rA0, 0xDB               ; load and return PI
    RET

_atan2_NAN:
    XJMP    _U(__fp_nanERANGE)

_atan2_normalize:                   ; normalize x and y to be LESS or EQUAL 1
    CLR     sign
    SBRC    rB3, 7
    ORI     sign, 1                 ; remember sign of x (bit 0 set: x < 0)
    SBRC    rA3, 7
    ORI     sign, 2                 ; remember sign of y (bit 1 set: y < 0)
    PUSH    sign
    ANDI    rB3, 0x7F               ; make |x|
    ANDI    rA3, 0x7F               ; make |y|
    CP      rB0, rA0
    CPC     rB1, rA1
    CPC     rB2, rA2
    CPC     rB3, rA3                ; |x| >= |y| ?
    BRGE    _atan2_X_GT
    EOR     rA3, rB3
    EOR     rB3, rA3
    EOR     rA3, rB3
    EOR     rA2, rB2
    EOR     rB2, rA2
    EOR     rA2, rB2
    EOR     rA1, rB1
    EOR     rB1, rA1
    EOR     rA1, rB1
    EOR     rA0, rB0
    EOR     rB0, rA0
    EOR     rA0, rB0                ; swap A and B
    RCALL   _atan2_scale            ; rA3:rA2 = int(28140 * x / y)
    MOV     X_hi, rA3
    MOV     X_lo, rA2               ; X = int(28140 * x / y)
    LDI     Y_hi, 0x6D
    LDI     Y_lo, 0xEC              ; Y = 28140
    RJMP    _atan2_cordic_loop_init

_atan2_X_GT:
    RCALL   _atan2_scale            ; Y = rA3:rA2 = int(28140 * y / x)
    LDI     X_hi, 0x6D
    LDI     X_lo, 0xEC              ; X = 28140

_atan2_cordic_loop_init:            ; run cordic in vectoring mode
    CLR     Z_hi                    ;  i.e. drive Y to zero and accumulate Z
    CLR     Z_lo                    ; Z = 0
    CLR     lcount                  ; lcount = 0
    LDI     ZL, LOW(table_atan2)
    LDI     ZH, HIGH(table_atan2)   ; set pointer to table

_atan2_cordic_loop:
    CPI     lcount, 15              ; lcount >= 15 ?
    BRLO    _atan2_cordic_loop_2
    RJMP    _atan2_finish           ; ok done with cordic

_atan2_cordic_loop_2:
    PUSH    Y_hi
    PUSH    Y_lo                    ; save Y
    MOV     rA3, X_hi
    MOV     rA2, X_lo
    CLT                             ; following shift must be "logical shift"
    RCALL   _atan2_shift            ; rA3:rA2 = X >> lcount
    MOV     tmp_hi, rA3
    MOV     tmp_lo, rA2             ; tmp = X >> lcount
    POP     Y_lo
    POP     Y_hi                    ; restore Y
    PUSH    Y_hi
    PUSH    Y_lo                    ; save Y
    BST     rA3, 7                  ; following shift must be "arithmetic shift"
    RCALL   _atan2_shift            ; rA3:rA2 = Y >> lcount
    CP      Y_lo, __zero_reg__
    CPC     Y_hi, __zero_reg__      ; Y < 0 ?
    BRLT    _atan2_Y_neg

_atan2_Y_pos:
    ADD     X_lo, rA2
    ADC     X_hi, rA3               ; X = X + Y >> lcount
    POP     Y_lo
    POP     Y_hi                    ; restore Y
    SUB     Y_lo, tmp_lo
    SBC     Y_hi, tmp_hi            ; Y = Y - tmp >> lcount
    LPMRdZpp(tmp_lo)                ; tmp = Rad[lcount]
    LPMRdZpp(tmp_hi)
    ADD     Z_lo, tmp_lo
    ADC     Z_hi, tmp_hi            ; Z = Z + Rad[lcount]
    INC     lcount                  ; lcount++
    RJMP    _atan2_cordic_loop

_atan2_Y_neg:
    SUB     X_lo, rA2
    SBC     X_hi, rA3               ; X = X - Y >> lcount
    POP     Y_lo
    POP     Y_hi                    ; restore Y
    ADD     Y_lo, tmp_lo
    ADC     Y_hi, tmp_hi            ; Y = Y + tmp >> lcount
    LPMRdZpp(tmp_lo)
    LPMRdZpp(tmp_hi)                ; tmp = Rad[lcount]
    SUB     Z_lo, tmp_lo
    SBC     Z_hi, tmp_hi            ; Z = Z - Rad[lcount]
    INC     lcount                  ; lcount++
    RJMP    _atan2_cordic_loop

_atan2_shift:                       ; A = A >> lcount
    MOV     __tmp_reg__, lcount     ; get current loop count

_atan2_shift_loop:
    TST     __tmp_reg__
    BREQ    _atan2_shift_done       ; we are done
    LSR     rA3
    ROR     rA2
    BLD     rA3, 7                  ;  LSR for "unsigned" int. ASR for "signed" int
    DEC     __tmp_reg__
    RJMP    _atan2_shift_loop

_atan2_shift_done:
    RET

_atan2_scale:                       ; A = int(28140 * A / B)
    XCALL   _U(__divsf3)            ; A = A / B
    RCALL   _atan2_scale_load       ; B = 28140
    XCALL   _U(__mulsf3)            ; A = 28140 * A / B
    XCALL   _U(__fixsfsi)           ; A = (long int)(28140 * A / B)
    MOV     Y_hi, X_hi              ;  but, we have a short int
    MOV     Y_lo, X_lo
    RET

_atan2_scale_load:                  ; B = 28140.0
    LDI     rB3, 0x46
    LDI     rB2, 0xDB
    LDI     rB1, 0xD8
    CLR     rB0
    RET

_atan2_finish:                      ; convert to float and clean-up
    MOV     rA1, Z_hi
    MOV     rA0, Z_lo
    CLR     rA3
    CLR     rA2
    XCALL   _U(__floatsisf)         ; A = (float)A
    POP     sign
    PUSH    sign
    SBRC    sign, 0                 ; x < 0 ?
    RJMP    _atan2_xneg

_atan2_xpos:                        ; here: x > 0
    RCALL   _atan2_scale_load       ; B = 28140.0
    XCALL   _U(__divsf3)            ; A = A / B
    POP     sign
    SBRC    sign, 1                 ; y < 0 ?
    RJMP    _atan2_yneg
    RET                             ; return (A / B)

_atan2_xneg:                        ; here: x < 0
    LDI     rB3, 0x47
    LDI     rB2, 0xAC
    LDI     rB1, 0xAA
    LDI     rB0, 0x35               ; load M_PI * 28140.0
    ORI     rA3, 0x80               ; negate A
    XCALL   _U(__addsf3)            ; A = -A + B = B - A
    RCALL   _atan2_scale_load       ; B = 28140.0
    XCALL   _U(__divsf3)            ; A = A / B
    POP sign
    SBRC    sign, 1                 ; y < 0 ?
    RJMP    _atan2_yneg
    RET                             ; return (A / B)

_atan2_yneg:                        ; here: y < 0
    ORI     rA3, 0x80               ; negate A
    RET                             ; return -(A / B)
 ENDFUNC

; --------------------------------------------------------------------------------------
table_atan2:
    .word 22101, 13047, 6893, 3499, 1756, 879, 439, 219, 109, 54, 27, 13, 6, 3, 1
; --------------------------------------------------------------------------------------

