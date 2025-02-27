#include "asmdef.h"

#if !defined(__AVR_TINY__)

#if defined(__USING_MINT8) && __USING_MINT8
#error "-mint8 option is not supported"
#endif

#define SIGNBIT 7

#define LFRACT_MAX 0x7fffffff
#define LFRACT_MIN 0x80000000

#define r_arg1HH r25
#define r_arg1HL r24
#define r_arg1H  r23
#define r_arg1L  r22

#define r_arg2HH r21
#define r_arg2HL r20
#define r_arg2H  r19
#define r_arg2L  r18

ENTRY lrdivi
	bst r_arg2HH, SIGNBIT
	mov __tmp_reg__, r_arg2HH
	;; If positive move on,
	brtc 0f
	; otherwise, negate r_arg2HH:r_arg2L.
	com r_arg2HH
	com r_arg2HL
	com r_arg2H
	neg r_arg2L
	sbci r_arg2H,  0xff
	sbci r_arg2HL, 0xff
	sbci r_arg2HH, 0xff
0:
	;; Store sign of the result in SIGNBIT.
	eor __tmp_reg__, r_arg1HH
	; If positive move on,
	sbrc r_arg1HH, SIGNBIT
	; otherwise, negate r_arg1HH:r_arg1L.
	rcall .Lnegate_arg1

	push __tmp_reg__
	XCALL _U(ulrdivi)
	pop __tmp_reg__
	; Shift right to get the value of fract from unsigned fract.
	lsr r_arg1HH
	ror r_arg1HL
	ror r_arg1H
	ror r_arg1L
	; If zero after the shift, then return.
	brne 1f
	sbiw r_arg1HL, 0
	sbci r_arg1H, 0
	breq .Llrdivi_exit
1:
	; Check the sign of the result.
	bst __tmp_reg__, SIGNBIT
	brtc .Llrdivi_exit
	; If negative, check for saturation because it is a special case.
	; Compare r_arg1 against LFRACT_MAX = 0x7fffffff.
	ldi r_arg2L,  hhi8(LFRACT_MAX)
	cpi r_arg1L,  lo8(LFRACT_MAX)
	cpc r_arg1H,  r_arg1L
	cpc r_arg1HL, r_arg1L
	cpc r_arg1HH, r_arg2L
	brne .Lnegate_arg1
	; Return negative saturated.
	ldi r_arg1HH, hhi8(LFRACT_MIN)
	ldi r_arg1HL, hlo8(LFRACT_MIN)
	ldi r_arg1H,   hi8(LFRACT_MIN)
	ldi r_arg1L,   lo8(LFRACT_MIN)
.Llrdivi_exit:
	ret
.Lnegate_arg1:
	; libgcc: Negate r_arg1HH:r_arg1L === R25:R22.
	XJMP _U(__negsi2)
ENDFUNC

#undef r_arg2L
#undef r_arg2H
#undef r_arg2HL
#undef r_arg2HH

#undef r_arg1L
#undef r_arg1H
#undef r_arg1HL
#undef r_arg1HH

#undef LFRACT_MIN
#undef LFRACT_MAX
#undef SIGNBIT

#endif /* !__AVR_TINY__ */
