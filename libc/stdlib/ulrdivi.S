#include "asmdef.h"

#ifndef __AVR_TINY__

#ifndef ULFRACT_MAX
#define ULFRACT_MAX 0xffffffff
#endif

#define r_arg1HH r25
#define r_arg1HL r24
#define r_arg1H  r23
#define r_arg1L  r22

#define r_arg2HH r21
#define r_arg2HL r20
#define r_arg2H  r19
#define r_arg2L  r18

#define r_den0   r10
#define r_den1   r11
#define r_den2   r12
#define r_den3   r13
#define r_den4   r14
#define r_den5   r15
#define r_den6   r16
#define r_den7   r17

FUNCTION ulrdivi
ENTRY ulrdivi
	; Check if the numerator is less that the denominator.
	cp  r_arg1L , r_arg2L
	cpc r_arg1H , r_arg2H
	cpc r_arg1HL, r_arg2HL
	cpc r_arg1HH, r_arg2HH
	;; Branch if numerator < denominator
	brlo 0f
	;; ...otherwise, return saturated value.
	ldi r_arg1HH, hhi8(ULFRACT_MAX)
	ldi r_arg1HL, hlo8(ULFRACT_MAX)
	ldi r_arg1H ,  hi8(ULFRACT_MAX)
	ldi r_arg1L ,  lo8(ULFRACT_MAX)
	ret
0:
	; call-saved registers
	push r_den0
	push r_den1
	push r_den2
	push r_den3
	push r_den4
	push r_den5
	push r_den6
	push r_den7
	; Move in first arg for __udivdi3
	X_movw r_den0, r_arg2L
	X_movw r_den2, r_arg2HL
	clr r_den4
	clr r_den5
	clr r_den6
	clr r_den7
	; Prepare second arg for __udivdi3.
	; The hight bytes in r_arg1HH:r_arg1L are already set,
	; so just clear the low bytes.
	clr r_arg2L
	clr r_arg2H
	clr r_arg2HL
	clr r_arg2HH

	XCALL __udivdi3
	X_movw r_arg1L,  r_arg2L
	X_movw r_arg1HL, r_arg2HL

	pop r_den7
	pop r_den6
	pop r_den5
	pop r_den4
	pop r_den3
	pop r_den2
	pop r_den1
	pop r_den0
	ret
ENDFUNC

#undef r_den7
#undef r_den6
#undef r_den5
#undef r_den4
#undef r_den3
#undef r_den2
#undef r_den1
#undef r_den0

#undef r_arg2L
#undef r_arg2H
#undef r_arg2HL
#undef r_arg2HH

#undef r_arg1L
#undef r_arg1H
#undef r_arg1HL
#undef r_arg1HH

#undef ULFRACT_MAX

#endif /* !__AVR_TINY__ */
