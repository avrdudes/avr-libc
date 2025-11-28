#include "asmdef.h"
#include "sqrtdef.h"

;;; Argument in R25:R22 compliant with avr-gcc ABI.
#define arg 22

;;; Developing square root in R21:R20.
#define res 20

;;; Rotation mask in R27:R26.
#define msk 26

;;; Number of bytes in the result
#define nbytes 2

;;; Integer part of the square root of a 32-bit unsigned integer.
;;; return (uint16_t) sqrtsi (uint32_t R22);
ENTRY   __sqrtsi
	sqrtengine arg, res, msk, nbytes
	X_movw arg + nbytes, res ; return in R25:R24 for avr-gcc ABI
	ret
ENDFUNC

