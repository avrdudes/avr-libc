/* Copyright (c) 2007, Dmitry Xmelkov
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

/* $Id$	*/

#ifndef	_ASMDEF_H
#define _ASMDEF_H

#include "sectionname.h"

/* Macros in this header use local symbols with `.L__' prefix. */

#ifndef __AVR_HAVE_MOVW__
# if  defined(__AVR_ENHANCED__) && __AVR_ENHANCED__
#  define __AVR_HAVE_MOVW__ 1
# else
#  define __AVR_HAVE_MOVW__ 0
# endif
#endif

#ifndef __AVR_HAVE_LPMX__
# if  defined(__AVR_ENHANCED__) && __AVR_ENHANCED__
#  define __AVR_HAVE_LPMX__ 1
# else
#  define __AVR_HAVE_LPMX__ 0
# endif
#endif

/* Historicaly, the _U() was intended to concatinate '_' prefix.
   Let us save it, as one is usefull to find externals quickly.	*/
#define	_U(name)	name

#if !defined(__tmp_reg__)
    #if defined(__AVR_TINY__)
        #define __tmp_reg__ r16
    #else
        #define __tmp_reg__ r0
    #endif
#endif

#if !defined(__zero_reg__)
    #if defined(__AVR_TINY__)
        #define __zero_reg__ r17
    #else
        #define __zero_reg__ r1
    #endif
#endif


#define	XL	r26
#define	XH	r27
#define	YL	r28
#define	YH	r29
#define	ZL	r30
#define	ZH	r31

#define SPL_IO_ADDR	0x3D
#define SPH_IO_ADDR	0x3E

#if	defined(__AVR_MEGA__) && __AVR_MEGA__
# define XJMP	jmp
# define XCALL	call
#else
# define XJMP	rjmp
# define XCALL	rcall
#endif

/* Macro FUNCTION is intended to start a function body without an entry.
   It is needed where an entry is at the middle of function. After this,
   you can to use an ENTRY macro below, one time or more.
   
   TODO: make a possibility to define a few of blocks FUNCTION..ENDFUNC
   in a one source file.
 */
.macro	FUNCTION name
  .ifdef  .L__function
    .err	; FUNCTION is defined already.
  .endif
	.L__function = 1
#ifdef	FUNC_SEGNAME
	.section  FUNC_SEGNAME, "ax", @progbits
#else
	ASSEMBLY_CLIB_SECTION
#endif
	.type	_U(\name), "function"
  .ifdef   .L__END
    .err	; .L__END is defined already.
  .endif
	.size	_U(\name), .L__END - .
.endm
#define	FUNCTION  FUNCTION	/* for CPP conditional expressions	*/

/* Macro ENTRY is intended to start a function with entry point at the
   head of body. It is not needed to use a FUNCTION macro in this case.
   It is possible to place additional ENTRY-s below.
 */
.macro	ENTRY	name
  .ifndef .L__function
FUNCTION \name
  .endif
	.global	_U(\name)
_U(\name):
.endm

/* This macro must used at the end of function body to calculate size.
 */
.macro	ENDFUNC
.L__END:
.endm

/* Macro REGNO set the symbol name 'name' to integer which is a 'reg'
   number (0..31). If 'reg' is not a valid register, compilation error.
   Valid regs are: r0..r31, R0..R31 and 0..31
 */
.macro	REGNO	name, reg
  \name = -1

  .L__regno = 0
  .irp  sym,  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, \
	     r10,r11,r12,r13,r14,r15,r16,r17,r18,r19, \
	     r20,r21,r22,r23,r24,r25,r26,r27,r28,r29, \
	     r30,r31
    .ifc  \sym,\reg
      \name = .L__regno
    .endif
    .L__regno = .L__regno + 1
  .endr

  .L__regno = 0
  .irp  sym,  R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, \
	     R10,R11,R12,R13,R14,R15,R16,R17,R18,R19, \
	     R20,R21,R22,R23,R24,R25,R26,R27,R28,R29, \
	     R30,R31
    .ifc  \sym,\reg
      \name = .L__regno
    .endif
    .L__regno = .L__regno + 1
  .endr

  .if  \name < 0
    .L__regno = 0
    .rept 32
      .if  \reg == .L__regno
	\name = .L__regno
      .endif
      .L__regno = .L__regno + 1
    .endr
  .endif

  .if  \name < 0
    .err	; Invalid dst arg of 'X_lpm' macro.
  .endif

.endm	/* REGNO */

/* Macro 'X_movw' extends enhanced movw instruction for classic chips.
 */
.macro	X_movw	dst,src
#if  __AVR_HAVE_MOVW__
	movw	\dst,\src
#else
  REGNO	.L__movw_dst, \dst
  .if	.L__movw_dst < 0
    .exitm
  .endif
  .if	.L__movw_dst % 1
    .err	; Invalid dst arg in X_movw macro.
    .exitm
  .endif

  REGNO	.L__movw_src, \src
  .if	.L__movw_src < 0
    .exitm
  .endif
  .if	.L__movw_src % 1
    .err	; Invalid src arg in X_movw macro.
    .exitm
  .endif
	mov	.L__movw_dst, .L__movw_src
	mov	.L__movw_dst + 1, .L__movw_src + 1
#endif
.endm

/* Macro 'X_lpm' extends enhanced lpm instruction for classic chips.
   Usage:
	X_lpm	reg, dst
   where
	reg	is 0..31, r0..r31 or R0..R31
	dst	is z, Z, z+ or Z+
   It is possible to omit both arguments.

   Possible results for classic chips:
	lpm
	lpm / mov Rd,r0
	lpm / adiw ZL,1
	lpm / mov Rd,r0 / adiw ZL,1
	
   For enhanced chips it is one instruction always.

   ATTENTION:  unlike enhanced chips SREG (S,V,N,Z,C) flags are
   changed in case of 'Z+' dst.  R0 is scratch.
 */
.macro	X_lpm	dst=r0, src=Z

  /* dst evaluation	*/
  REGNO	.L__lpm_dst, \dst
  .if .L__lpm_dst < 0
    .exitm	; do not multiply errors
  .endif

  /* src evaluation	*/    
  .L__lpm_src = -1
  .L__lpm_n = 0
  .irp  reg,  z,Z,z+,Z+
    .ifc  \reg,\src
      .L__lpm_src = .L__lpm_n
    .endif
    .L__lpm_n = .L__lpm_n + 1
  .endr

  .if  (.L__lpm_src < 0)
    .err	; Invalid src arg of 'X_lpm' macro.
  .endif

  /* instruction(s)	*/    
  .if  .L__lpm_src < 2
    .if  .L__lpm_dst == 0
	lpm
    .else
#if  __AVR_HAVE_LPMX__
	lpm	.L__lpm_dst, Z
#else
	lpm
	mov	.L__lpm_dst, r0
#endif
    .endif
  .else
    .if  (.L__lpm_dst >= 30)
      .err	; Registers 30 and 31 are inhibited as 'X_lpm *,Z+' dst.
    .endif
#if  __AVR_HAVE_LPMX__
	lpm	.L__lpm_dst, Z+
#else
	lpm
    .if  .L__lpm_dst
	mov	.L__lpm_dst, r0
    .endif
	adiw	r30, 1
#endif
  .endif
.endm

#endif	/* !_ASMDEF_H */
