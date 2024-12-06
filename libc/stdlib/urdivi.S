#include "asmdef.h"

#ifndef UFRACT_MAX
#define UFRACT_MAX 0xffff
#endif

#ifndef FRACT_MAX
#define FRACT_MAX 0x7fff
#endif

#define r_arg1H r25
#define r_arg1L r24
#define r_arg2H r23
#define r_arg2L r22

/** Registers for __udivmodsi4
* dividend 32-bit: r22:r25
* return: remainder
* divisor 32-bit: r18:r21
* return: quotient
*/
#define r_quotHH r21
#define r_quotHL r20
#define r_quotH  r19
#define r_quotL  r18

FUNCTION urdivi
ENTRY urdivi
	; Check if the divisor is less than the dividend.
	cp  r_arg1L, r_arg2L
	cpc r_arg1H, r_arg2H
	brlo 0f    ; branch if numerator < denominator
	; otherwise, return saturated
	ldi r_arg1H, hi8(UFRACT_MAX)
	ldi r_arg1L, lo8(UFRACT_MAX)
	ret
0:
	X_movw r_quotL, r_arg2L
	clr r_quotHL
	clr r_quotHH

	; Second arg is shifted by UFRACT_FBIT=16.
	; Keep r_arg1H:r_arg1L unchanged and
	; clear lower bytes in r_arg2H:r_arg2L.
	clr r_arg2L
	clr r_arg2H

	XCALL __udivmodsi4
	X_movw r_arg1L, r_quotL
	ret
ENDFUNC

#undef r_quotL
#undef r_quotH
#undef r_quotHL
#undef r_quotHH

#undef r_arg2L
#undef r_arg2H
#undef r_arg1L
#undef r_arg1H

#undef UFRACT_MAX
