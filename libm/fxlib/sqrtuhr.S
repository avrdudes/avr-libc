; Square root of unsigned short fract.

#include "asmdef.h"

#define res_hi r25
#define res_lo r24

FUNCTION __avr_libc_sqrtuhr
ENTRY    __avr_libc_sqrtuhr
	mov  res_hi, res_lo     ; unsigned short fract as uint16_t
	clr  res_lo
	XCALL __avr_libc_sqrthi ; take integer square root;
	ret                     ; return low 8 bits as unsigned fract
ENDFUNC
