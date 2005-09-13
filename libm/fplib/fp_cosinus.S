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
    fp_cosinus.S is part of     FPlib V 0.3.0       ported to avr-as
    for details see readme.fplib

 *----------------------------------------------------------------------------------------
 *
 * A = cosinus(A) with A = [0...2PI[
 *
 *  _           _         _           _             _      _
 *  |\         /           \    |    /        |    /       |\           ;
 *  |a\ b   c / d         a \ b | c /d        |   /        | \          ;
 *  +--\-----/-------- => ---\--+--/---  =>   +--/---   => +--X---      ;
 * 0    \   /    2pi     -pi  \ | /   pi     0| /    pi    | / pi/2     ;
 *       \_/                   \_/            _/           _/           ;
 *                        cos(x-PI) =         cos(x) =     cos(x)       ;
 *                       -cos(x)              cos(-x)
 *  section sign
 *  a b c d              a b c d              a b c d      a b c d
 *  + - - +              - + + -              - + + -      + + + +
 * sign complement for sections b + c
 */

#if !defined(__DOXYGEN__)

#include "gasava.inc"
#include "macros.inc"
#include "fplib.inc"

          TEXT_SEG(fplib, __fp_cosinus)
          FUNCTION(__fp_cosinus)

GLOBAL(__fp_cosinus)		; input A = [-2PI...2PI[
       PUSH    rSI0
       ANDI    rA3,0x7F		; input A = [0...2PI[

       LDI     rB3,0xC0
       LDI     rB2,0x49
       LDI     rB1,0x0F
       LDI     rB0,0xDB		; load -PI
       RCALL   _U(__addsf3)	; now   A = [-PI..+PI[
       LDI     rSI0,0x80	; assume sign complement (b,c)
       ANDI    rA3,0x7F		; positive     cos(x-PI) = cos(-(x-PI)) = -cos(x)
       LDI     rB3,0x3F
       LDI     rB2,0xC9
       LDI     rB1,0x0F
       LDI     rB0,0xDB		; load PI/2
       CP      rA0,rB0		;
       CPC     rA1,rB1		;
       CPC     rA2,rB2
       CPC     rA3,rB3		; cmp A to PI/2
       BRCS    1f		; branch if lower
			; now (A = x) > PI/2, B = PI/2
       LDI     rB3,0xC0
       LDI     rB2,0x49		; B = -PI
       RCALL   _U(__addsf3)	; PI-A = -(A+-PI)
       CLR     rSI0		; no sign complement (a,d)
1:
       RCALL   _U(square)		; xý
       ORI     rA3,0x80 		; -xý
					;
       LDI     ZL,LOW(table_cos)	;
       LDI     ZH,HIGH(table_cos)	;
       RCALL   _U(__fp_powerseries)	;

       EOR     rA3,rSI0		; complement sign
       POP     rSI0
       RET

          ENDFUNC

	PGM_SECTION

  /* cos(x) =    ( 1 - xý(1/2! - xý(1/4! - xý(1/6! - xý(1/8! - xý(1/10! - xý(1/12!  - xý(1/14!))

	 * these constants are *no* IEEE float values: exponet unpacked allready
	 *                                             first byte : exponent
	 *                                             2nd byte   : msb of mantissa with sign as bit 7
	 *                                             3rd & 4th byte : mantissa
   */
table_cos:
             DCB 8  ; no of table entries - 1 (preload value)
             ; looks like 6 steps are sufficient
             ;            7 steps for sin(pi) == 0
             ;;DCB 0x4A, 0x34, 0x13, 0xC3 ;, 0x1E     ; 1/18!
             DCB 0x52, 0x57, 0x3F, 0x9F ;, 0x3A     ; 1/16!
             DCB 0x5A, 0x49, 0xCB, 0xA5 ;, 0x46     ; 1/14!
             DCB 0x62, 0x0F, 0x76, 0xC7 ;, 0x80 ;C6 ; 1/12!
             DCB 0x69, 0x13, 0xF2, 0x7E ;, 0xBC     ; 1/10!
             DCB 0x6F, 0x50, 0x0D, 0x01 ;, 0xD0     ; 1/8!
             DCB 0x75, 0x36, 0x0B, 0x61 ;, 0xB6     ; 1/6!
             DCB 0x7A, 0x2A, 0xAA, 0xAB ;, 0xAB     ; 1/4! = 1/24
             DCB 0x7E, 0x00, 0x00, 0x00 ;, 0x00     ; 1/2!
             DCB 0x7F, 0x00, 0x00, 0x00 ;, 0x00     ; 1.0
             DCB 0x00

#endif /* not __DOXYGEN__ */
