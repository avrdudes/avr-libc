;;; Square root of unsigned accum.

#ifndef __AVR_TINY__

#include "asmdef.h"

;;; unsigned accum R22 = sqrtuk (unsigned accum R22);

ENTRY sqrtuk
    ;; Reinterpret 32-bit unsigned accum as a 48-bit value
    ;; provided in R25:R20, and use the 48-bit integer square root.
    ;; The result is a 24-bit value in R24:R22 zero-extended to
    ;; a 32-bit value.
    clr     r20
    clr     r21
    XJMP    _U(__sqrtpdi)
ENDFUNC

#endif /* !__AVR_TINY__ */
