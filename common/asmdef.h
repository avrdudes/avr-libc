/* Copyright (c) 2002, 2005, 2006, 2007 Marek Michalkiewicz
   Copyright (c) 2006-2007 Dmitry Xmelkov
   Copyright (c) 2025 Georg-Johann Lay
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

/*
   Provided C #defines
   ===================

   _U                         ; Doesn't do anything but is nice to find
                              ; global symbols in the asm sources.
   __tmp_reg__
   __zero_reg__
   XJMP
   XCALL
   XIJMP
   XICALL
   do_prologue_saves
   do_epilogue_restores
   XL, XH                     ; Via avr/common.h
   YL, YH                     ; Via avr/common.h
   ZL, ZH                     ; Via avr/common.h

   FUNCTION                   ; Just for #ifdef

   PGMX_SECTION               ; formerly in libm/fplib/fp32def.h

   Provided asm .macros
   ====================

   FUNCTION
   ENTRY
   ENTRY_FLOAT
   ENDFUNC
   OBJECT
   ENDOBJ

   REGNO                      ; Helper for the X_ macros.
   X_movw
   X_sbiw
   X_adiw
   X_lpm

   LPM_R0_ZPLUS_INIT          ; Formerly in macros.inc
   LPM_R0_ZPLUS_NEXT          ; Formerly in macros.inc
   LPM_R0_ZPLUS_FINI          ; Formerly in macros.inc

   TINY_WEAK_ALIAS
*/

#ifndef _ASMDEF_H
#define _ASMDEF_H

#ifndef __ASSEMBLER__
#define __ASSEMBLER__
#endif

/* Defines such as SPL, SPH, XL, XH,
   SREG, EIND, RAMPZ, ...  */
#include <avr/common.h>

#include "sectionname.h"


/* Put constant tables in .progmemx in program memory, so they
   don't nibble on the lower 64K PROGMEM.  */
#define PGMX_SECTION(x)	.section .progmemx.gcc_##x, "a", "progbits"


/* Macros in this header use local symbols with `.L__' prefix. */

/* Historically, the _U() was intended to concatenate '_' prefix.
   Let us save it, as one is useful to find externals quickly.	*/
#define	_U(name)	name

#if defined(__AVR_TINY__)
    #define __tmp_reg__  r16
    #define __zero_reg__ r17
#else
    #define __tmp_reg__  r0
    #define __zero_reg__ r1
#endif

#if	defined(__AVR_HAVE_JMP_CALL__)
# define XJMP	jmp
# define XCALL	call
#else
# define XJMP	rjmp
# define XCALL	rcall
#endif

#if defined(__AVR_HAVE_EIJMP_EICALL__)
# define XIJMP  eijmp
# define XICALL eicall
#else
# define XIJMP  ijmp
# define XICALL icall
#endif

#ifndef __AVR_TINY__

;; Prologue stuff
;; do_prologue_saves  costs 12 bytes.
;; __prologue_saves__ costs 56 bytes.
.macro do_prologue_saves n_pushed n_frame=0
    ldi r26, lo8(\n_frame)
    ldi r27, hi8(\n_frame)
    ldi r30, lo8(gs(.L_prologue_saves.\@))
    ldi r31, hi8(gs(.L_prologue_saves.\@))
    XJMP __prologue_saves__ + ((18 - (\n_pushed)) * 2)
.L_prologue_saves.\@:
.endm

;; Epilogue stuff
;; do_epilogue_restores  costs 12 bytes.
;; __epilogue_restores__ costs 54 bytes.
.macro do_epilogue_restores n_pushed n_frame=0
    in      r28, SPL_IO_ADDR
#ifdef SPH
    in      r29, SPH_IO_ADDR
.if \n_frame > 63
    subi    r28, lo8(-\n_frame)
    sbci    r29, hi8(-\n_frame)
.elseif \n_frame > 0
    adiw    r28, \n_frame
.endif
#else
    clr     r29
.if \n_frame > 0
    subi    r28, lo8(-\n_frame)
.endif
#endif /* HAVE SPH */
    ldi     r30, \n_pushed
    XJMP __epilogue_restores__ + ((18 - (\n_pushed)) * 2)
.endm

#endif /* AVR_TINY */


/* Macro FUNCTION is intended to start a function body without an entry.
   It is needed where an entry is at the middle of function, like in
   libc/pmstring/_memcpy_P.S.  After this, you can use the ENTRY macro
   below multiple times.

   TODO: make a possibility to define a few of blocks FUNCTION..ENDFUNC
   in a one source file, see libc/stdlib/setjmp.S for a use case.
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
   It is possible to place additional ENTRY-s below.  */
.macro	ENTRY	name
  .ifndef .L__function
FUNCTION \name
  .else
	.type	_U(\name), "function"
  .endif
	.global	_U(\name)
_U(\name):
.endm

/* If the layout of the double type is the same like the float layout,
   provide a weak alias of the float symbol for double, same for long double.
   While we could also provide aliases in header files using
   __asm__ in the declaration to specify the symbol to reference,
   it is preferable to provide actual symbols in the library, so
   that code that expects to be able to use them directly -
   like gcc/testsuite/gcc.dg/pr41963.c using sqrtf - will work.  */

.macro	ENTRY_FLOAT  fname  dname  lname
ENTRY \fname
#if (__SIZEOF_DOUBLE__ == __SIZEOF_FLOAT__)
	.weak	_U(\dname)
	.type	_U(\dname), "function"
_U(\dname):
#endif /* double = float */
#if (__SIZEOF_LONG_DOUBLE__ == __SIZEOF_FLOAT__)
	.weak	_U(\lname)
	.type	_U(\lname), "function"
_U(\lname):
#endif /* long double = float */
.endm

/* This macro must be used at the end of function body to calculate size.  */
.macro	ENDFUNC
.L__END:
.endm


/* Defines an object and sets .size, .type and the label.  Use like:
   OBJECT [.global] my_data
   ...
   ENDOBJ my_data  */
.macro OBJECT arg1 arg2
    .ifc \arg2,
        .type \arg1, "object"
        \arg1:
    .else
        \arg1 \arg2
        .type \arg2, "object"
        \arg2:
    .endif
.endm

.macro ENDOBJ name
    .size \name, . - \name
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
  .if	.L__movw_dst != .L__movw_src
#if  __AVR_HAVE_MOVW__
	movw	\dst,\src
#else
	mov	.L__movw_dst, .L__movw_src
	mov	.L__movw_dst + 1, .L__movw_src + 1
#endif
  .endif
.endm

/* Macro 'X_sbiw' extends SBIW instruction for AVR_TINY chips. */
.macro	X_sbiw	dst,val
#if !defined (__AVR_TINY__)
	sbiw	\dst,\val
#else
  REGNO	.L__sbiw_dst, \dst
  .if	.L__sbiw_dst < 0
    .exitm
  .endif
  .if	.L__sbiw_dst % 1
    .err	; Invalid register arg in X_sbiw macro.
    .exitm
  .endif

	subi	.L__sbiw_dst,     lo8(\val)
	sbci	.L__sbiw_dst + 1, hi8(\val)
#endif /* AVR_TINY */
.endm

/* Macro 'X_adiw' extends ADIW instruction for AVR_TINY chips
   except for the flags (only N and Z will be the same).  */
.macro	X_adiw	dst,val
#if !defined (__AVR_TINY__)
	adiw	\dst,\val
#else
  REGNO	.L__adiw_dst, \dst
  .if	.L__adiw_dst < 0
    .exitm
  .endif
  .if	.L__adiw_dst % 1
    .err	; Invalid register arg in X_adiw macro.
    .exitm
  .endif

	subi	.L__adiw_dst,     lo8(-(\val))
	sbci	.L__adiw_dst + 1, hi8(-(\val))
#endif /* AVR_TINY */
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


/*
   LPM_R0_ZPLUS_INIT is used before the loop to initialize RAMPZ
   for future devices with RAMPZ:Z auto-increment - [e]lpm r0, Z+.

   LPM_R0_ZPLUS_NEXT is used inside the loop to load a byte from
   the program memory at [RAMPZ:]Z to R0, and increment [RAMPZ:]Z.

   The argument in both macros is a register that contains the
   high byte (bits 23-16) of the address, bits 15-0 should be in
   the Z (r31:r30) register.  It can be any register except for:
   r0, r1 (__zero_reg__ - assumed to always contain 0), r30, r31.

   LPM_R0_ZPLUS_FINI is used atfer all reads to restore RAMPZ
   in the case a restoration is required.  */

.macro	LPM_R0_ZPLUS_INIT hhi
#if __AVR_ENHANCED__
  #if __AVR_HAVE_ELPM__
	out	RAMPZ_IO_ADDR, \hhi
  #endif
#endif
.endm

.macro	LPM_R0_ZPLUS_NEXT hhi, dst=r0
  REGNO	.L__elpm_dst, \dst
  .if .L__elpm_dst < 0
    .exitm	; do not multiply errors
  .endif

#if __AVR_ENHANCED__
  #if __AVR_HAVE_ELPM__
	;; ELPM with RAMPZ:Z post-increment, load RAMPZ only once.
	elpm	.L__elpm_dst, Z+
  #else
	;; LPM with Z+, max 64K, no RAMPZ (ATmega83/161/163/32).
	lpm	.L__elpm_dst, Z+
  #endif
#else
  #if __AVR_HAVE_ELPM__
	;; ELPM without post-increment, load RAMPZ each time (ATmega103).
	out	RAMPZ_IO_ADDR, \hhi
	elpm
	adiw	r30,1
	adc	\hhi, __zero_reg__
	.if .L__elpm_dst > 0
		mov	.L__elpm_dst, r0
	.endif
  #elif defined (__AVR_TINY__)
	;; AVRrc: Program is visible in the RAM address-space at offset 0x4000.
	ld	.L__elpm_dst, Z+
  #else
	;; LPM without post-increment, max 64K, no RAMPZ (AT90S*).
	lpm
	adiw	r30,1
	.if .L__elpm_dst > 0
		mov	.L__elpm_dst, r0
	.endif
  #endif
#endif
.endm

/* We only have to restore RAMPZ when the device has the RAMPD (sic!)
   register.  In that case, we have to restore RAMPZ to zero because
   RAMPZ is concatenated with Z to get 24-bit addresses for RAM access.
   When the device has no RAMPD, then the device has no RAMPZ, or RAMPZ
   is used exclusively with ELPM and need not to be restored.  */
.macro	LPM_R0_ZPLUS_FINI
#if defined(__AVR_HAVE_ELPM__) && defined(__AVR_HAVE_RAMPD__)
	out	RAMPZ_IO_ADDR, __zero_reg__
#endif
.endm


.macro TINY_WEAK_ALIAS new old
#ifdef __AVR_TINY__
    .weak \new
    .type \new, @function
    \new = \old
#endif /* __AVR_TINY__ */
.endm


#endif	/* !_ASMDEF_H */
