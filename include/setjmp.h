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

#ifndef __SETJMP_H_
#define __SETJMP_H_ 1

/*
   jmp_buf:
	offset	size	description
	 0	16	call-saved registers (r2-r17)
	16	 2	frame pointer (r29:r28)
	18	 2	stack pointer (SPH:SPL)
	20	 1	status register (SREG)
	21	 3	return address (PC) (2 bytes used for <=128K flash)
	24 = total size
 */

typedef struct {
	/* call-saved registers */
	unsigned char __j_r2;
	unsigned char __j_r3;
	unsigned char __j_r4;
	unsigned char __j_r5;
	unsigned char __j_r6;
	unsigned char __j_r7;
	unsigned char __j_r8;
	unsigned char __j_r9;
	unsigned char __j_r10;
	unsigned char __j_r11;
	unsigned char __j_r12;
	unsigned char __j_r13;
	unsigned char __j_r14;
	unsigned char __j_r15;
	unsigned char __j_r16;
	unsigned char __j_r17;
	/* frame pointer, stack pointer, status register, program counter */
	unsigned int __j_fp;  /* Y */
	unsigned int __j_sp;
	unsigned char __j_sreg;
	unsigned int __j_pc;
	unsigned char __j_pch;  /* only devices with >128K bytes of flash */
} jmp_buf[1];

#ifndef __ATTR_NORETURN__
#define __ATTR_NORETURN__ __attribute__((__noreturn__))
#endif

extern int setjmp(jmp_buf __jmpb);
extern void longjmp(jmp_buf __jmpb, int __ret) __ATTR_NORETURN__;

#endif  /* !__SETJMP_H_ */
