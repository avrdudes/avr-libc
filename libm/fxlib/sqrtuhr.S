; Square root of unsigned short fract.

#include "asmdef.h"

#define res_hi r25
#define res_lo r24

ENTRY   __sqrtuhr
	mov  res_hi, res_lo     ; unsigned short fract as uint16_t
	clr  res_lo
	XCALL _U(__sqrthi)      ; take integer square root;
	clr  res_hi             ; msb of the result is always zero
	ret                     ; return low 8 bits as unsigned fract
ENDFUNC
