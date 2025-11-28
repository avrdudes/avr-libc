#include "asmdef.h"
#include "sqrtdef.h"

#ifndef __AVR_TINY__

#define size 4  /* number of bytes in the result              */
#define mask 26 /* registers used for rotation mask (4 bytes) */
#define res  14 /* developing square root           (4 bytes) */
#define arg  18 /* provided argument                (8 bytes) */

;;; Integer part of the square root of a 64-bit unsigned integer.
;;; (uint32_t) sqrtdi (uint64_t R18)
;;; return R25:R22
ENTRY __sqrtdi
	push res
	push res + 1
	push res + 2
	push res + 3
	push mask + size - 1
	push mask + size / 2
	sqrtengine arg, res, mask, size
	X_movw     arg + size,          res
	X_movw     arg + size + size / 2, res + size / 2
	pop mask + size / 2
	pop mask + size - 1
	pop res + 3
	pop res + 2
	pop res + 1
	pop res
	ret
ENDFUNC

#endif /* !__AVR_TINY__ */
