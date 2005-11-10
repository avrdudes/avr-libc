/* Copyright (c) 2002, Marek Michalkiewicz
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/*
   setjmp.S

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
 */

/*
   jmp_buf:
	offset	size	description
	 0	16	call-saved registers (r2-r17)
	16	 2	frame pointer (r29:r28)
	18	 2	stack pointer (SPH:SPL)
	20	 1	status register (SREG)
	21	 3	return address (PC) (2 bytes used for <=128K flash)
	24 = total size

int setjmp(jmp_buf __jmpb);
void longjmp(jmp_buf __jmpb, int __val) __attribute__((noreturn));
 */

#include "macros.inc"
#include "ctoasm.inc"

/* the same library is used for 2313 and 8515 for now -
   I hope writing 0 to non-existent SPH doesn't hurt... */
#ifndef SPH
#define SPH (SPL+1)
#endif

#define jmpb_hi	rP0
#define jmpb_lo	rP1
#define val_hi	rP2
#define val_lo	rP3

#define ret_lo rP1  /* r24 */
#define ret_hi rP0  /* r25 */

	.section .text

	.global _U(setjmp)
	.global _U(longjmp)

_U(setjmp):
	X_movw	ZL, jmpb_lo
	in	r26, _SFR_IO_ADDR(SPL)
	in	r27, _SFR_IO_ADDR(SPH)
	/* save program counter (return address) */
	/* return address on stack (pushed by "call") is big endian! */
	/* SP is post-decremented by "call" */
	adiw	r26, 1
#ifdef EIND  /* devices with >128K bytes of flash - none yet */
	ld	__tmp_reg__, X+
	std	Z+23, __tmp_reg__
#endif
	ld	__tmp_reg__, X+
	std	Z+22, __tmp_reg__
	ld	__tmp_reg__, X
	std	Z+21, __tmp_reg__
	/* save stack pointer (SP value before calling this function) */
	std	Z+18,r26
	std	Z+19,r27
	/* save status register (I flag) */
	in	__tmp_reg__, _SFR_IO_ADDR(SREG)
	std	Z+20, __tmp_reg__
	/* save call-saved registers */
	st	Z, r2
	std	Z+1, r3
	std	Z+2, r4
	std	Z+3, r5
	std	Z+4, r6
	std	Z+5, r7
	std	Z+6, r8
	std	Z+7, r9
	std	Z+8, r10
	std	Z+9, r11
	std	Z+10, r12
	std	Z+11, r13
	std	Z+12, r14
	std	Z+13, r15
	std	Z+14, r16
	std	Z+15, r17
	/* save frame pointer */
	std	Z+16,r28
	std	Z+17,r29
	/* return zero */
	clr	ret_lo
	clr	ret_hi
	ret

_U(longjmp):
	X_movw	XL, jmpb_lo
	/* return value */
	X_movw	ret_lo, val_lo
	/* if zero, change to 1 */
	cpi	ret_lo, 1
	cpc	ret_hi, __zero_reg__
	adc	ret_lo, __zero_reg__
	/* restore call-saved registers */
	ld	r2, X+
	ld	r3, X+
	ld	r4, X+
	ld	r5, X+
	ld	r6, X+
	ld	r7, X+
	ld	r8, X+
	ld	r9, X+
	ld	r10, X+
	ld	r11, X+
	ld	r12, X+
	ld	r13, X+
	ld	r14, X+
	ld	r15, X+
	ld	r16, X+
	ld	r17, X+
	/* restore frame pointer */
	ld	YL, X+
	ld	YH, X+
	/* restore stack pointer (SP value before the setjmp() call) */
	ld	r30,X+
	ld	r31,X+
	ld	__tmp_reg__, X+
	/* interrupts disabled for shortest possible time (3 cycles) */
	cli
	out	_SFR_IO_ADDR(SPH), r31
	/* Restore status register (including the interrupt enable flag).
	   Interrupts are re-enabled only after the next instruction.  */
	out	_SFR_IO_ADDR(SREG), __tmp_reg__
	out	_SFR_IO_ADDR(SPL), r30
	/* restore return address */
	ld	r30,X+
	ld	r31,X+
#ifdef EIND
	ld	__tmp_reg__, X
	out	_SFR_IO_ADDR(EIND), __tmp_reg__
	.word	0x9419  /* eijmp */
#else
	ijmp
#endif

