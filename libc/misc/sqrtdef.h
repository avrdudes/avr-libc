#ifndef SQRTDEF_H
#define SQRTDEF_H

#include "asmdef.h"

;; The following utility macros define basic multi-register
;; operations for the integer square root algorithm from
;; an unsigned integer.  They all accept `size` parameter
;; which is the number of *bytes* in the *result*.  Some
;; of them also have `flag`, which is used when the first
;; instruction is different from the rest of the instructions
;; (e.g. does not use the C-flag).

;; Set the initial value val to the register number rnum.
;; Also, use SUB instruction to set C=0, since this is a
;; precondition at the start.
.macro initval _rnum _size _val
.if \_size > 1
	sub \_rnum, \_rnum
	initval (\_rnum + 1), (\_size - 1), \_val
.else
	ldi \_rnum, \_val
.endif
.endm

;; Test next binary digit in developing square root.
;; If flag is set, the first instruction does not
;; use the carry flag.
.macro testdigit _rarg _rres _size _flag
.if \_flag
	cp  \_rarg + \_size, \_rres
.else
	cpc \_rarg + \_size, \_rres
.endif
.if \_size > 1
	testdigit (\_rarg + 2), (\_rres + 1), (\_size - 1), 0
.endif
.endm

;; Update Y_m (see notations below), if next binary
;; digit is set.  If flag is set, the first instruction
;; does not use carry.
.macro updatearg _rarg _rres _size _flag
.if \_flag
	sub  \_rarg + \_size, \_rres
.else
	sbc \_rarg + \_size, \_rres
.endif
.if \_size > 1
	updatearg (\_rarg + 2), (\_rres + 1), (\_size - 1), 0
.endif
.endm

;; Set binary digit in the result if X_m < Y_m is true.
.macro setdigit _rres _mask _size
	or \_rres, \_mask
.if \_size > 1
	setdigit (\_rres + 1), (\_mask + 1), (\_size - 1)
.endif
.endm

;; Shift the rotation mask right. If flag is set, the first
;; instruction does not use C-flag.
.macro shiftmask _mask _size _flag
.if \_flag
	lsr \_mask + \_size - 1
.else
	ror \_mask + \_size - 1
.endif
.if \_size > 1
	shiftmask \_mask, (\_size - 1), 0
.endif
.endm

;; Set the next test binary digit in the result that will be
;; tested in the next iteration of the main loop.
.macro shiftdigit _rres _mask _size
	eor \_rres + \_size - 1, \_mask + \_size - 1
.if \_size > 1
	shiftdigit \_rres, \_mask, (\_size - 1)
.endif
.endm

;; Argument is rolled left to keep relevant bits in the higher
;; (size / 2) bytes.  During the last iteration, this also rolls
;; carry bit into bit 0 of the LSB of the `rarg` registers.
.macro shiftarg _rarg _size
	rol \_rarg
.if \_size > 1
	shiftarg (\_rarg + 1), (\_size - 1)
.endif
.endm

;; Last bit requires special treatment. The following macro saves
;; the last bit into C-flag, which is added to the result at the
;; very end.
.macro setlast _rarg _rres _size
	cpc \_rres, \_rarg + \_size
.if \_size > 1
	setlast (\_rarg + 2), (\_rres + 1), (\_size - 1)
.endif
.endm

; Generic macro that generates an integer square root algorithm, where the
; result has 'size' bytes.  The argument provided in the registers starting
; with 'rarg' number and has twice the number of bytes than does
; the result.
;
; Based on the sqrt32_floor algorithm:
; https://www.mikrocontroller.net/articles/AVR_Arithmetik#avr-gcc-Implementierung_(32_Bit)
;
; The algorithm is built around the following inequality to test if
; c_{m-1} binary digit in the result is 0 or 1:
;         (P_m + 2^{m-1})^2 < N^2,
; where N^2 is the input, and P_m is the current developing square root that
; has m binary digits P_m = (c_n, c_{n-1}, ... c_m), where n is the number of
; bits in the result.
;
; This inequality can be rewritten as
;         X_m < Y_m,
; where
;         X_m = 2^m P_m + 2^{2m-2},
;         Y_m = N^2 - P_m^2,
; The recurrence relations to update X_m and Y_m are:
;         2X_m = X_{m + 1} + 2^{2m} + 2^{2m-1}, (n-bits) stored in rres,
;         Y_m = Y_{m + 1} - X_{m+1}           , (n-bits) stored in arg MSB,
; and the last two terms in 2X_m are kept in the rotation mask.
;
; For example, for 8-bit square root, starting values are:
; m = 8, P_8 = 0, X_8 = 2^14 = 0x4000, and Y_8 = N^2.
;
; Parameters:
;     rarg: Register number that contains LSB of the argument.
;     rres: Register number that contains LSB of the result.
;     mask: Register number that contains LSB of the mask.
;
; This macro neither saves any call-saved registers, nor sets it any registers
; in compliance with the AVR ABI.  These should be done separately.
.macro sqrtengine _rarg _rres _mask _size
	;; Set initial values and carry flag, C = 0.
	initval    \_mask, \_size, 0xc0      ; Rotation mask
.if \_size <= 2
	initval    \_rres, \_size, 0x40      ; Expanding square root
.else
	X_movw     \_rres, \_mask            ; Copy 0x0000 from _mask
	initval    \_rres+2, \_size-2, 0x40  ; Expanding square root
.endif
.if \_size == 1
	clc
.endif
	;; Precondition: C = 0.
.Lnext_bit:
	brcs 1f                              ; if C = 1, X_m < Y_m already
	testdigit  \_rarg, \_rres, \_size, 1
	brcs 2f                              ; if X_m < Y_m, update X_m and Y_m
1:
	updatearg  \_rarg, \_rres, \_size, 1 ; Update Y_m <- Y_m - X_m
	setdigit   \_rres, \_mask, \_size    ; Set next test digit in the result.
2:
	shiftmask  \_mask, \_size, 1         ; Shift mask, C = 1 --> end of loop.
	shiftdigit \_rres, \_mask, \_size
	shiftarg   \_rarg, (2 * \_size)      ; Shift right, and save C into bit 0.
	sbrs       \_rarg, 0                 ; Exit if bit 0 is set from the mask
	rjmp .Lnext_bit                      ; through the C-flag.

	brcs 3f                              ; C = 1 means last bit is 1.
	lsl        \_rarg + \_size - 1       ; Restore last bit in arg from C
	setlast    \_rarg, \_rres, \_size    ; after this, C is the last bit.
3:
	adc        \_rres, __zero_reg__      ; Add last bit from C to the result.
.endm

#endif /* SQRTDEF_H */
