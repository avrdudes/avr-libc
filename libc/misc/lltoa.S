#ifndef __AVR_TINY__

#include "asmdef.h"

#define Radix   r14
#define Sign    r27
#define A7      r25

;;; char*  lltoa (int64_t val, char* s,   int radix)
;;; r24  = lltoa (int64_t R18, char* R16, int R14)
ENTRY __lltoa
    mov     r31, Radix
    cpi     r31, 10
    brne 9f
    ;; Decimal.
    tst     A7
    brpl 9f
    ;; Negative Decimal.
    XCALL   _U(__negdi2)        ; libgcc
    ldi     Sign, '-'
    XJMP    _U(__ulltoa.sign)
9:  XJMP    _U(__ulltoa)

ENDFUNC

#endif /* __AVR_TINY__ */
