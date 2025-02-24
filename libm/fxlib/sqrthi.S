; Integer part of the square root of a 16-bit unsigned integer.
;
; "Fast Integer Square Root" algorithm by Ross M. Folsler,
; DS91040A, Microchip Technology (2000).
; https://ww1.microchip.com/downloads/en/AppNotes/91040a.pdf

#include "asmdef.h"

#define arg_hi  r25
#define arg_lo  r24
#define res_hi  r23
#define res_lo  r22
#define cbit    r20
#define prod_hi __zero_reg__
#define prod_lo __tmp_reg__

ENTRY   __sqrthi
	ldi  cbit, 0x80      ; set initial msb bit
	clr  res_lo          ; load the initial guess
.Lnextbit:
	or   res_lo, cbit    ; set current bit in the guess
#ifdef __AVR_HAVE_MUL__
	mul  res_lo, res_lo  ; take the square of the guess
#else
	; Call 16 = 8 x 8 libgcc widening multiplication
	push arg_hi
	push arg_lo
	push res_hi
	push res_lo
	mov arg_lo, res_lo
	XCALL _U(__umulqihi3)
	X_movw prod_lo, arg_lo
	pop res_lo
	pop res_hi
	pop arg_lo
	pop arg_hi
#endif /* __AVR_HAVE_MUL__ */
	cp   arg_lo, prod_lo
	cpc  arg_hi, prod_hi
	brsh 1f              ; if square less than arg, set next bit
	com  cbit            ; mask to negate current bit
	and  res_lo, cbit    ; clear current bit in the guess
	com  cbit            ; revert current bit back
1:	lsr  cbit            ; shift bit for the next iteration
	breq .Lexit          ; if all bits done, break the cycle
	rjmp .Lnextbit
.Lexit:
	mov  arg_lo, res_lo
	clr  arg_hi          ; msb of the result is always zero
	clr  __zero_reg__
	ret
ENDFUNC
