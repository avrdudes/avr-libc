#include <avr/io.h>

/* The purpose of this module is to set bit CPUINT_CTRLA.CPUINT_CVT.
   The code will be pulled in by crt<mcu>-cvt.o which is a build
   variant of gcrt1.S with USE_COMPACT_VECTOR_TABLE.  */

#define FUNC_SEGNAME ".init3"
#include "asmdef.h"

/* Referenced by gcrt1.S.  This function must not be called
   because it is naked.  */
ENTRY   _U(__init_cvt)

/* Definitions in avr/io*.h are neglecting assembly, so...  */
#ifndef CCP_IOREG_gc
#define CCP_IOREG_gc    0xD8    /* IO Register Protection */
#endif

/* Only compile if the device has bit CPUINT_CTRLA.CPUINT_CVT.  */
#ifdef CPUINT_CVT_bm

    lds     r18, CPUINT_CTRLA
    ori     r18, CPUINT_CVT_bm
    ldi     r19, CCP_IOREG_gc   ; Load I/O reg change protection signature.
    out     CCP, r19
    sts     CPUINT_CTRLA, r18

#endif  /* Have CPUINT_CTRLA.CPUINT_CVT */

ENDFUNC
