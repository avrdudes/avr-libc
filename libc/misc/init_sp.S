#define FUNC_SEGNAME ".init2"

#include <avr/io.h>
#include "asmdef.h"

/* The purpose of this module is to initialize SP to the value of
   symbol __stack, which defaults to RAMEND.  On devices that have
   SPLIM, initialize it to something more useful than RAMEND.  */

/* Referenced by gcrt1.S.  This function must not be called
   because it is naked.  */

ENTRY _U(__init_sp)

#if defined(CPU_SPLIM)
    ;; Setting SPLIM is a bit tricky, since we don't know the value
    ;; of __heap_start, and we don't know the current value of SP
    ;; in the case of a soft reset.  Hence, set SPLIM = 0 first.
    ;; Since the code runs in .init2 which also does clr __zero_reg__,
    ;; and there is no ordering, don't rely on __zero_reg__ here.
    clr __zero_reg__
    out _SFR_IO_ADDR(CPU_SPLIML), __zero_reg__
    out _SFR_IO_ADDR(CPU_SPLIMH), __zero_reg__
#endif /* Have SPLIM */

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

#if defined(CPU_SPLIM)
    ldi r24, lo8(__heap_start - 1)
    ldi r25, hi8(__heap_start - 1)
    out _SFR_IO_ADDR(CPU_SPLIML), r24
    out _SFR_IO_ADDR(CPU_SPLIMH), r25
#endif /* Have SPLIM */

ENDFUNC
