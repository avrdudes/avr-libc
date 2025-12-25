#include "asmdef.h"
#include "sqrtdef.h"

#define size 3  /* number of bytes in the result              */
#define mask 29 /* registers used for rotation mask (3 bytes) */
#define res  26 /* developing square root           (3 bytes) */
#define arg  20 /* provided argument                (6 bytes) */

;;; Integer part of the square root of a 48-bit unsigned integer.
;;; return R22 = (uint32_t) (uint24_t) sqrtpdi (uint48_t R20)
ENTRY __sqrtpdi
    ;; Prologue: Secure some callee-saved regs.
#ifndef __AVR_TINY__
    X_movw  r18, r28
#else
    mov     __tmp_reg__, r28
    push    r29
#endif /* __AVR_TINY__ */

    sqrtengine arg, res, mask, size
    X_movw  r22  res
    mov     r24, res + 2
    ;; Zero-extend to uint32_t.
    clr     r25

    ;; Epilogue
#ifndef __AVR_TINY__
    X_movw  r28, r18
#else
    pop     r29
    mov     r28, __tmp_reg__
#endif /* __AVR_TINY__ */
    ret
ENDFUNC
