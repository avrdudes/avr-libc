#include "asmdef.h"

;;; Argument in R25:R22 compliant with avr-gcc ABI.
#define arg_hh r25
#define arg_hl r24
#define arg_hi r23
#define arg_lo r22
;;; Developing square root in R21:R20.
#define res_hi r21
#define res_lo r20
;;; Rotation mask in R27:R26.
#define msk_hi r27
#define msk_lo r26

/* sqrt32_floor: https://www.mikrocontroller.net/articles/AVR_Arithmetik */

;;; Integer part of the square root of a 32-bit unsigned integer.
;;; return (uint16_t) sqrtsi (uint32_t R22);
ENTRY   __sqrtsi
	sub res_lo, res_lo    ; clear and set C=0
	ldi res_hi, 0x40      ; developing square root
	clr msk_lo
	ldi msk_hi, 0xc0      ; set rotation mask
.L_next_bit:                  ; precondition: C=0
	brcs 1f               ; C --> Bit is always 1
	cp  arg_hl, res_lo
	cpc arg_hh, res_hi    ; does test value fit?
	brcs 2f
1:
	sub arg_hl, res_lo
	sbc arg_hh, res_hi    ; adjust argument for next bit
	or  res_lo, msk_lo
	or  res_hi, msk_hi    ; set bit 1
2:
	lsr msk_hi
	ror msk_lo            ; shift right mask, C --> end loop
	eor res_hi, msk_hi
	eor res_lo, msk_lo    ; shift right only test bit in result
	rol arg_lo
	rol arg_hi
	rol arg_hl
	rol arg_hh            ; shift left remaining argument (C used at 1:)
	sbrs arg_lo, 0        ; skip if 15 bits developed
	rjmp .L_next_bit      ; develop 15 bits of the sqrt

	brcs 3f               ; C --> Last bit always 1
	lsl  arg_hi           ; need bit 7 in C for cpc
	cpc res_lo, arg_hl
	cpc res_hi, arg_hh    ; after this C is last bit
3:
	adc res_lo, msk_hi    ; round up if C (msk_hi = 0)
	X_movw arg_hl, res_lo ; return in R25:R24 for avr-gcc ABI
	ret
ENDFUNC
