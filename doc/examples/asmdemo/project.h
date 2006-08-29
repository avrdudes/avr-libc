/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Joerg Wunsch wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * Demo combining C and assembly source files.
 *
 * $Id$
 */

/*
 * Global register variables.
 */
#ifdef __ASSEMBLER__

#  define sreg_save	r2
#  define flags		r16
#  define counter_hi    r4

#else  /* !ASSEMBLER */

#include <stdint.h>

register uint8_t sreg_save asm("r2");
register uint8_t flags     asm("r16");
register uint8_t counter_hi asm("r4");

#endif /* ASSEMBLER */
