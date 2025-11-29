#ifndef __AVR_TINY__

#include "asmdef.h"
#include "sqrtdef.h"

#define size 3  /* number of bytes in the result              */
#define mask 26 /* registers used for rotation mask (3 bytes) */
#define res  16 /* developing square root           (3 bytes) */
#define arg  20 /* provided argument                (6 bytes) */

;;; Integer part of the square root of a 48-bit unsigned integer.
;;; return R22 = (uint32_t) (uint24_t) sqrtpdi (uint48_t R20)
ENTRY __sqrtpdi
    ;; Prologue: Secure some callee-saved regs.
    X_movw  r30, res
    mov     __tmp_reg__, mask + 2

    sqrtengine arg, res, mask, size
    X_movw  r22  res
    mov     r24, res + 2
    ;; Zero-extend to uint32_t.
    clr     r25
    ;; Epilogue
    mov     mask + 2, __tmp_reg__
    X_movw  res, r30
    ret
ENDFUNC

#endif /* !__AVR_TINY__ */
