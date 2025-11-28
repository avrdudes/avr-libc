#ifndef _SQRTDEF_H
#define _SQRTDEF_H

#ifndef __zero_reg__
#ifndef __AVR_TINY__
	#define __zero_reg__ r1
#else
	#define __zero_reg__ r17
#endif /* __AVR_TINY__ */
#endif /* __zero_reg__ */

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
.macro initval rnum size val
.if \size - 1
	sub \rnum, \rnum
	initval (\rnum + 1), (\size - 1), \val
.else
	ldi \rnum, \val
.endif
.endm

;; Test next binary digit in developing square root.
;; If flag is set, the first instruction does not 
;; use the carry flag.
.macro testdigit rarg rres size flag
.if \flag
	cp  \rarg + \size, \rres
.else
	cpc \rarg + \size, \rres
.endif
.if \size - 1
	testdigit (\rarg + 2), (\rres + 1), (\size - 1), 0
.endif
.endm

;; Update Y_m (see notations below), if next binary
;; digit is set.  If flag is set, the first instruction
;; does not use carry.
.macro updatearg rarg rres size flag
.if \flag
	sub  \rarg + \size, \rres
.else
	sbc \rarg + \size, \rres
.endif
.if \size - 1
	updatearg (\rarg + 2), (\rres + 1), (\size - 1), 0
.endif
.endm 

;; Set binary digit in the result if X_m < Y_m is true.
.macro setdigit rres mask size
	or \rres, \mask
.if \size - 1
	setdigit (\rres + 1), (\mask + 1), (\size - 1)
.endif
.endm

;; Shift the rotation mask right. If flag is set, the first
;; instruction does not use C-flag.
.macro shiftmask mask size flag
.if \flag
	lsr \mask + \size - 1
.else
	ror \mask + \size - 1
.endif
.if \size - 1
	shiftmask \mask, (\size - 1), 0
.endif
.endm

;; Set the next test binary digit in the result that will be
;; tested in the next iteration of the main loop.
.macro shiftdigit rres mask size
	eor \rres + \size - 1, \mask + \size - 1
.if \size - 1
	shiftdigit \rres, \mask, (\size - 1)
.endif
.endm

;; Argument is rolled left to keep relevant bits in the higher
;; (size / 2) bytes.  During the last iteration, this also rolls
;; carry bit into bit 0 of the LSB of the `rarg` registers.
.macro shiftarg rarg size
	rol \rarg
.if \size - 1
	shiftarg (\rarg + 1), (\size - 1)
.endif
.endm

;; Last bit requires special treatment. The following macro saves
;; the last bit into C-flag, which is added to the result at the
;; very end.
.macro setlast rarg rres size
	cpc \rres, \rarg + \size
.if \size - 1
	setlast (\rarg + 2), (\rres + 1), (\size - 1)
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
;     rarg    -register number that contains LSB of the argument
;     rres    -register number that contains LSB of the result
;     mask    -register number that contains LSB of the mask
;
; This macro neither saves any call-saved registers, nor it sets any registers
; in compliance with AVR ABI.  These should be done separately.
.macro sqrtengine rarg rres mask size
	; Set initial values and carry flag, C = 0.
	initval    \mask, \size, 0xc0     ; rotation mask
	initval    \rres, \size, 0x40     ; developing square root
	; Precondition: C = 0.
.Lnext:
	brcs 1f                           ; if C = 1, X_m < Y_m already
	testdigit  \rarg, \rres, \size, 1
	brcs 2f                           ; if X_m < Y_m, update X_m and Y_m
1:
	updatearg  \rarg, \rres, \size, 1 ; update Y_m <- Y_m - X_m
	setdigit   \rres, \mask, \size    ; set next test digit in the result
2:
	shiftmask  \mask, \size, 1        ; shift mask, C = 1 --> end of loop
	shiftdigit \rres, \mask, \size
	shiftarg   \rarg, (2 * \size)     ; shift right, and save C into bit 0
	sbrs       \rarg, 0               ; exit if bit 0 is set from the mask
	rjmp .Lnext                       ; through the C-flag
	
	brcs 3f                           ; C = 1 means last bit is 1
	lsl        \rarg + \size - 1      ; restore last bit in arg from C
	setlast    \rarg, \rres, \size    ; after this, C is the last bit
3:
	adc        \rres, __zero_reg__    ; add last bit from C to the result
.endm

#endif /* _SQRTDEF_H */
