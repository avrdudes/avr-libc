#ifndef __DOXYGEN__

#define FUNC_SEGNAME ".init9"

#include "asmdef.h"

/* The purpose of this module is to call main and exit.  */

/* Referenced by gcrt1.S.  */

ENTRY _U(__call_main)

#ifdef __AVR_ASM_ONLY__
    XJMP    main
#else   /* !__AVR_ASM_ONLY__ */
    XCALL   main
    XJMP    exit
#endif  /* __AVR_ASM_ONLY__ */

ENDFUNC

#endif  /* !__DOXYGEN__ */
