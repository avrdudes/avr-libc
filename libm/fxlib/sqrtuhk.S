#include "asmdef.h"

;;; unsigned short accum R24 = sqrtuhk (unsigned short accum R24);
ENTRY sqrtuhk
    mov     r23, r24
    mov     r24, r25
    clr     r22
    clr     r25
    XJMP    _U(__sqrtsi)
ENDFUNC
