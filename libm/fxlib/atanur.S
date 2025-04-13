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
   POSSIBILITY OF SUCH DAMAGE.  */

;; atan(x) over [0, 1)  ->  [0, pi/4]

/*
    unsigned fract R24 = atanur (unsigned fract R24);

    We use 4 cubic MiniMax polynomials over [0, 1) that approximate

        atan((x + n) / 4),   n = 0..3

    Bits x.15 and x.14 determine n.

    The previous implementation of atanur used one MiniMax polynomial of
    degree 5 over [0, 1), which lead to an absolute error of E ≈ 4.5e-5.
    Increasing the polynomial degree doesn't work since discretization
    noise increases.  Introducing zeros at 0 and 1 similar to what is
    done for exp2m1ur does decrease noise, but also moves the result too
    far away from MiniMax (presumably due to the singularities at ±i).

    What also doesn't work well are cubic splines.  Four splines yield
    an E similar to that above.  One reason for the noise is that cubic
    splines use 6 multiplications, which is noisy and expensive.

    CORDIC has not been tried yet.

    The implementation below uses 4 cubic MiniMax polynomials and
    yields E < 2.7e-5.

    In order to get the coefficients:
    1. Determine the respective cubic MiniMax polynomial P over [0, 1)
       using the Rémez algorithm for example.
    2. Rewrite P such that all coefficients become non-negative.
    3. When there are coefficients greater than 1, or when not all
       intermediate values are in [0, 1), then abort.  The current
       representation cannot handle that.  (It is possible though
       to compensate for coefficients > 1 and for intermediate values
       not in [0, 1), but the implementation below doesn't do that.)
    4. Post-process P in order to descrease E.  E can be improved since
       coefficients and calculations suffer from discretization, and
       hence P isn't a true MiniMax for the used fixed-point type.
*/

#include "asmdef.h"

#define ArgTab0     r20
#define ArgTab1     r21
#ifdef __AVR_HAVE_ELPM__
#define ArgTab2     22
#endif

#define ArgX0   r24
#define ArgX1   r25

#define Idx     r23

#ifdef __AVR_TINY__
#define PM_OFFSET 0x4000
#else
#define PM_OFFSET 0
#endif

#define SIZEOF_POLY(Deg) (1 + 2 * (1 + Deg))

#define TABL __atanur_4cubics

;;; unsigned fract R24 = atanur (unsigned fract R24)

ENTRY atanur

    ;; Compute index into TABL, which is ArgX(15..14) * SIZEOF_CUBIC.
    clr     Idx
    sbrc    ArgX1, 7    $  subi    Idx, -(2 * SIZEOF_POLY(3))
    sbrc    ArgX1, 6    $  subi    Idx, -(1 * SIZEOF_POLY(3))

    ldi     ArgTab0, lo8(TABL + PM_OFFSET)  $   add  ArgTab0, Idx
    ldi     ArgTab1, hi8(TABL + PM_OFFSET)  $   adc  ArgTab1, __zero_reg__
#ifdef __AVR_HAVE_ELPM__
    ldi     ArgTab2, hh8(TABL + PM_OFFSET)  $   adc  ArgTab2, __zero_reg__
#endif

    ;; x <<= 2
    lsl     ArgX0   $  rol     ArgX1
    lsl     ArgX0   $  rol     ArgX1

    ;; unsigned fract R24 = cubic (unsigned fract R24, uint_farptr_t R20)
    XJMP    _U(__horner_ur)

ENDFUNC

/*
    typedef struct
    {
       uint8_t signs;
       unsigned fract a3, a2, a1, a0;
    } cubic_t;

    cubic(x) = a0 ± x * (a1 ± x * (a2 ± x * a3))
*/

#define CUBIC(s, a0, a1, a2, a3)   \
    $ .byte (s << 5) | (1 << 4)    \
    $ .2byte a3, a2, a1, a0

.section .progmemx.data.TABL, "a", "progbits"
.type TABL, "object"
.size TABL, 4 * SIZEOF_POLY(3)
TABL:
    CUBIC (0b010, 0x0000, 0x4006, 0x0020, 0x012f)
    CUBIC (0b010, 0x3eb7, 0x3c47, 0x03cb, 0x0081)
    CUBIC (0b110, 0x76b1, 0x333a, 0x053f, 0x0010)
    CUBIC (0b110, 0xa4bc, 0x28f7, 0x04f2, 0x004f)
