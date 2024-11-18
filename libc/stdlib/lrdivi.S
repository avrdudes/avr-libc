#include "asmdef.h"

#if !defined(__AVR_TINY)

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

FUNCTION lrdivi
ENTRY lrdivi
	bst r_arg2HH, SIGNBIT
	mov __tmp_reg__, r_arg2HH
	brtc 0f    ; if positive move on
	; otherwise, negate r_arg2HH:r_arg2L
	com r_arg2HH
	com r_arg2HL
	com r_arg2H
	neg r_arg2L
	sbci r_arg2H , 0xff
	sbci r_arg2HL, 0xff
	sbci r_arg2HH, 0xff
0:
	eor __tmp_reg__, r_arg1HH    ; store sign of the result in SIGNBIT
	bst r_arg1HH, SIGNBIT
	brtc 1f    ; if positive move on
	; otherwise, negate r_arg1HH:r_arg1L
	com r_arg1HH
	com r_arg1HL
	com r_arg1H
	neg r_arg1L
	sbci r_arg1H , 0xff
	sbci r_arg1HL, 0xff
	sbci r_arg1HH, 0xff
1:
	push __tmp_reg__
	XCALL ulrdivi
	pop __tmp_reg__
	; shift right to get the value of fract from unsigned fract
	lsr r_arg1HH
	ror r_arg1HL
	ror r_arg1H
	ror r_arg1L
	; if zero after the shift, return
	tst r_arg1HH
	brne 2f
	tst r_arg1HL
	brne 2f
	tst r_arg1H
	brne 2f
	tst r_arg1L
	brne 2f
	ret
2:
	; check the sign of the result
	bst __tmp_reg__, SIGNBIT
	brtc .Llrdivi_exit
	; if negative, check for saturation
	; because it is a special case
	cpi r_arg1HH, hhi8(LFRACT_MAX)
	brne 3f
	cpi r_arg1HL, hlo8(LFRACT_MAX)
	brne 3f
	cpi r_arg1H ,  hi8(LFRACT_MAX)
	brne 3f
	cpi r_arg1L ,  lo8(LFRACT_MAX)
	; return negative saturated
	ldi r_arg1HH, hhi8(LFRACT_MIN)
	ldi r_arg1HL, hlo8(LFRACT_MIN)
	ldi r_arg1H ,  hi8(LFRACT_MIN)
	ldi r_arg1L ,  lo8(LFRACT_MIN)
	ret
3:
	; negate r_arg1HH:r_arg1L
	com r_arg1HH
	com r_arg1HL
	com r_arg1H
	neg r_arg1L
	sbci r_arg1H , 0xff
	sbci r_arg1HL, 0xff
	sbci r_arg1HH, 0xff
.Llrdivi_exit:
	ret
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

#endif /* !__AVR_TINY */
