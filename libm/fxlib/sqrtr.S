;;; fract R24 = sqrtr (fract R24)

#include "asmdef.h"

ENTRY sqrtr
    tst     r25
    brmi 0f
    ;; Convert to unsigned fract.
    lsl     r24
    rol     r25
    XCALL   _U(sqrtur)
    ;; Convert back to signed fract.
    lsr     r25
    ror     r24
    ;; Round
    adc     r24, __zero_reg__
    adc     r25, __zero_reg__
    ;; Square root is such that there is no overflow.
0:  ret
ENDFUNC
