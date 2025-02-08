#ifndef __DOXYGEN__

#include "macros.inc"

/* The purpose of this module is to initialize SP to the value
   of symbol __stack, which defaults to RAMEND.  */

/* Referenced by gcrt1.S.  This function must not be called
   because it is naked.  */

.section ".init2", "ax", @progbits
.global _U(__init_sp)
.type   _U(__init_sp), @function

_U(__init_sp):

    ldi r28, lo8(__stack)
#ifdef __AVR_XMEGA__
    out AVR_STACK_POINTER_LO_ADDR, r28
#ifdef _HAVE_AVR_STACK_POINTER_HI
    ldi r29, hi8(__stack)
    out AVR_STACK_POINTER_HI_ADDR, r29
#endif  /* _HAVE_AVR_STACK_POINTER_HI */
#else
#ifdef _HAVE_AVR_STACK_POINTER_HI
    ldi r29, hi8(__stack)
    out AVR_STACK_POINTER_HI_ADDR, r29
#endif  /* _HAVE_AVR_STACK_POINTER_HI */
    out AVR_STACK_POINTER_LO_ADDR, r28
#endif  /* __AVR_XMEGA__ */

.size _U(__init_sp), . - _U(__init_sp)

#endif  /* !__DOXYGEN__ */
