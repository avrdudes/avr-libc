#include "asmdef.h"

;;; short accum R24 = sqrthk (short accum R24);
ENTRY sqrthk
    ;; Return values < 0 unaltered.
    tst     r25
    brmi 0f
    ;; Convert to uhk.
    lsl     r24
    rol     r25
    XCALL   _U(sqrtuhk)
    ;; Convert back to hk.
    lsr     r25
    ror     r24
    ;; Round
    adc     r24, __zero_reg__
    adc     r25, __zero_reg__
0:  ret
ENDFUNC
