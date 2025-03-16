#include "asmdef.h"

#define arg_hi r25
#define arg_lo r24
#define mask   r20
#define res    r22

;;; Integer part of the square root of a 16-bit unsigned integer.
;;; return (uint8_t) sqrt (uint16_t R24);
ENTRY   __sqrthi
	sub  res, res        ; set C = 0 for !__AVR_HAVE_MUL__
#ifdef __AVR_HAVE_MUL__

; "Fast Integer Square Root" algorithm by Ross M. Folsler,
; DS91040A, Microchip Technology (2000).
; https://ww1.microchip.com/downloads/en/AppNotes/91040a.pdf

#define prod_hi __zero_reg__
#define prod_lo __tmp_reg__

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

; 16-bit variant of the sqrt32_floor algorithm
; https://www.mikrocontroller.net/articles/AVR_Arithmetik#avr-gcc-Implementierung_(32_Bit)

; The algorithm is built around the following inequality
;         (P_m + 2^{m-1})^2 < N^2,
; where N^2 is the input, and P_m is the current developing square root.
; Starting values are: m = 8 for the 8-bit result, and P_8 = 0.
; This inequality can be rewritten as
;         X_m < Y_m,
; where
;         X_m = 2^m P_m + 2^{2m-2},
;         Y_m = N^2 - P_m^2,
; Starting values are: X_8 = 2^14 = 0x4000, Y_8 = N^2 (arg_hi:arg_lo).
; The recurrence relations to update X_m and Y_m are:
;         2X_m = X_{m + 1} + 2^{2m} + 2^{2m-1}, MSB stored in res,
;         Y_m = Y_{m + 1} - X_{m+1}           , MSB stored in arg_hi,
; and the last two terms in 2X_m are kept in the rotation mask.

	ldi  mask, 0xc0       ; MSB: 2^{2m} + 2^{2m-1} (m = 7)
	ldi  res,  0x40       ; MSB: X_m = 2^{2m-2} (m = 8)
	; Pre-condition: C = 0.
.Lnextbit:
	brcs 1f               ; if C = 1, X_m < Y_m already
	cp   arg_hi, res
	brcs 2f               ; if X_m > Y_m, update and start next bit
1:	sub  arg_hi, res      ; update Y_m -> Y_m - X_m
	or   res, mask        ; update 2X_m
2:	lsr  mask             ; shift mask right; C = 1 is the end of loop
	eor  res, mask        ; only shift test bit
	rol  arg_lo           ; save C from mask into bit 0
	rol  arg_hi           ; Y_m -> 2Y_m instead of shifting 2X_m right
	sbrs arg_lo, 0        ; exit if bit 0 is set
	rjmp .Lnextbit
	brcs 3f
	lsl  arg_lo
	cpc  res, arg_hi
3:	adc  res, __zero_reg__
#endif /* __AVR_HAVE_MUL__ */
	mov  arg_lo, res
	ret
ENDFUNC
