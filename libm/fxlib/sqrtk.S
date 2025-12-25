;;; Square root of signed accum.

#include "asmdef.h"

#define A0  r22
#define A1  r23
#define A2  r24
#define A3  r25

;;; accum R22 = sqrtk (accum R22);

ENTRY sqrtk
    ;; Return negative values unaltered.
    tst     A3
    brmi 0f
    ;; Convert accum = Q-format s16.15 to unsigned accum = Q 16.16.
    lsl     A0
    rol     A1
    rol     A2
    rol     A3
    XCALL   _U(sqrtuk)
    ;; Convert back to accum.
    lsr     A3
    ror     A2
    ror     A1
    ror     A0
    ;; Round
    adc     A0, __zero_reg__
    adc     A1, __zero_reg__
    adc     A2, __zero_reg__
    adc     A3, __zero_reg__
0:  ret
ENDFUNC
