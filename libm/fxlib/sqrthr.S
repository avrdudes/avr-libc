; Square root of signed fract.

#include "asmdef.h"

#define res_hi r25
#define res_lo r24

FUNCTION __avr_libc_sqrthr
ENTRY    __avr_libc_sqrthr
	mov  res_hi, res_lo     ; short fract as uint16_t
	lsl  res_hi             ; shift out sign bit
	clr  res_lo             ; clear low 8 bits
	XCALL __avr_libc_sqrthi ; take integer square root
	lsr  res_lo             ; shift sign bit back for signed short fract
	ret
ENDFUNC
