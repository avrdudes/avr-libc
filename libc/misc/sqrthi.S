#include "asmdef.h"

#define arg_hi 25
#define arg_lo 24
#define res    22
#define mask   20

;;; Integer part of the square root of a 16-bit unsigned integer.
;;; return (uint8_t) sqrt (uint16_t R24);
ENTRY   __sqrthi

#ifdef __AVR_HAVE_MUL__

; "Fast Integer Square Root" algorithm by Ross M. Folsler,
; DS91040A, Microchip Technology (2000).
; https://ww1.microchip.com/downloads/en/AppNotes/91040a.pdf

#define prod_hi __zero_reg__
#define prod_lo __tmp_reg__
	clr  res
	ldi  mask, 0x80      ; set rotation mask
.Lnextbit:
	add  res, mask       ; set current bit in the guess
	mul  res, res        ; take the square of the guess
	cp   arg_lo, prod_lo
	cpc  arg_hi, prod_hi
	brsh 1f              ; if square less than arg, set next bit
	sub  res, mask       ; clear current bit in the guess
1:	lsr  mask            ; shift bit for the next iteration
	brne .Lnextbit
	clr  __zero_reg__
#else /* __AVR_HAVE_MUL__ */

#include "sqrtdef.h"

#define nbytes 1
	sqrtengine arg_lo res mask nbytes

#endif /* __AVR_HAVE_MUL__ */
	mov  arg_lo, res
	ret
ENDFUNC
