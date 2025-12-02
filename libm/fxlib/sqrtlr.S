;;; long fract R22 = sqrtlr (long fract radic);

#include "asmdef.h"

ENTRY sqrtlr
    tst     r25
    brmi 0f
    ;; Convert to ulr.
    lsl     r22
    rol     r23
    rol     r24
    rol     r25
    XCALL   _U(sqrtulr)
    ;; Convert back to lr.
    lsr     r25
    ror     r24
    ror     r23
    ror     r22
    ;; Round
    adc     r22, __zero_reg__
    adc     r23, __zero_reg__
    adc     r24, __zero_reg__
    adc     r25, __zero_reg__
    ;; No overflow will occur.
0:  ret
ENDFUNC
