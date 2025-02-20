#ifndef __DOXYGEN__

#include "asmdef.h"

/* The purpose of this module is to call main and exit.  */

/* Referenced by gcrt1.S.  */

.section ".init9", "ax", @progbits
.global _U(__call_main)
.type   _U(__call_main), @function

_U(__call_main):

#ifdef __AVR_ASM_ONLY__
    XJMP    main
#else   /* !__AVR_ASM_ONLY__ */
    XCALL   main
    XJMP    exit
#endif  /* __AVR_ASM_ONLY__ */

.size _U(__call_main), . - _U(__call_main)

#endif  /* !__DOXYGEN__ */
