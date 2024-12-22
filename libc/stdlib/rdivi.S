#include "asmdef.h"

#if defined(__USING_MINT8) && __USING_MINT8
#error "-mint8 option is not supported"
#endif

#define SIGNBIT 7

#ifdef FRACT_MAX
#warning "FRACT_MAX already defined. Redefining..."
#undef FRACT_MAX
#endif
#define FRACT_MAX 0x7fff

#ifdef FRACT_MIN
#warning "FRACT_MIN already defined. Redefining..."
#undef FRACT_MIN
#endif
#define FRACT_MIN 0x8000

#define r_arg1H r25
#define r_arg1L r24
#define r_arg2H r23
#define r_arg2L r22

FUNCTION rdivi
ENTRY rdivi
	bst r_arg2H, SIGNBIT
	mov __tmp_reg__, r_arg2H
	brtc 0f                     ; if positive move on
	com r_arg2H                 ; otherwise, negate r_arg2H:r_arg2L
	neg r_arg2L
	sbci r_arg2H, 0xff
0:
	eor __tmp_reg__, r_arg1H    ; store sign of the result
	bst r_arg1H, SIGNBIT
	brtc 1f                     ; if positive move on
	com r_arg1H                 ; otherwise, negate r_arg1H:r_arg1L
	neg r_arg1L
	sbci r_arg1H, 0xff
1:
	push __tmp_reg__
	XCALL urdivi
	pop __tmp_reg__
	; values of fract type should be shifted
	; right w.r.t values of unsigned fract type
	lsr r_arg1H
	ror r_arg1L
	; if zero after shifting right -- return
	tst r_arg1H
	brne 2f
	tst r_arg1L
	brne 2f
	ret
2:
	; check sign of the result
	bst __tmp_reg__, SIGNBIT
	brtc .Lrdivi_exit
	; if negative, check for saturation
	; because it's a special case
	cpi r_arg1H, hi8(FRACT_MAX)
	brne 3f
	cpi r_arg1L, lo8(FRACT_MAX)
	brne 3f
	; return negative saturated
	ldi r_arg1H, hi8(FRACT_MIN)
	ldi r_arg1L, lo8(FRACT_MIN)
	ret
3:
	; negate r_arg1H:r_arg1L
	com r_arg1H
	neg r_arg1L
	sbci r_arg1H, 0xff
.Lrdivi_exit:
	ret
ENDFUNC

#undef r_arg2L
#undef r_arg2H
#undef r_arg1L
#undef r_arv1H

#undef FRACT_MIN
#undef FRACT_MAX
#undef SIGNBIT
