#ifndef __DOXYGEN__

#include "asmdef.h"

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
    out SPL_IO_ADDR, r28
#ifdef SPH_IO_ADDR
    ldi r29, hi8(__stack)
    out SPH_IO_ADDR, r29
#endif  /* Have SPH */
#else
#ifdef SPH_IO_ADDR
    ldi r29, hi8(__stack)
    out SPH_IO_ADDR, r29
#endif  /* Have SPH */
#ifdef SPL_IO_ADDR
    out SPL_IO_ADDR, r28
#endif  /* Have SPL */
#endif  /* __AVR_XMEGA__ */

.size _U(__init_sp), . - _U(__init_sp)

#endif  /* !__DOXYGEN__ */
