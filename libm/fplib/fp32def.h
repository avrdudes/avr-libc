/* Interprocedure convensions. In separate file: for math library
   developers.	*/
#ifndef	_FP32DEF_H
#define	_FP32DEF_H

#include "sectionname.h"

#define	rB0	r18
#define	rB1	r19
#define	rB2	r20
#define	rB3	r21

#define	rA0	r22
#define	rA1	r23
#define	rA2	r24
#define	rA3	r25

#define	rBE	r26
#define	rAE	r27

/* Put functions at this section.	*/
#ifdef	FUNCTION
# error	"The FUNCTION macro must be defined after FUNC_SEGNAME"
#endif
#define FUNC_SEGNAME	MLIB_SECTION

/* Put constant tables in .progmemx in program memory, so they
   don't nibble on the lower 64K PROGMEM.  */
#define PGMX_SECTION(x)	.section .progmemx.gcc_fplib##x, "a", @progbits

#ifdef __AVR_HAVE_ELPM__
#  if !defined(AVR_RAMPZ_ADDR)
#  define AVR_RAMPZ_ADDR 0x3b
#  endif
#  define LDI_XH_hh8(sym)	ldi XH, hh8(sym)
#else /* ELPM ? */
#  define LDI_XH_hh8(sym)	/* empty */
#endif /* ELPM ? */

#endif	/* !_FP32DEF_H */
