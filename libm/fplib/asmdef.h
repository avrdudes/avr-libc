#ifndef	_ASMDEF_H
#define _ASMDEF_H

#ifndef __AVR_HAVE_MOVW__
# if  defined(__AVR_ENHANCED__) && __AVR_ENHANCED__
#  define __AVR_HAVE_MOVW__ 1
# endif
#endif

#ifndef __AVR_HAVE_LPMX__
# if  defined(__AVR_ENHANCED__) && __AVR_ENHANCED__
#  define __AVR_HAVE_LPMX__ 1
# endif
#endif

/* Historicaly, the _U() was intended to concatinate '_' prefix.
   Let us save it, as one is usefull to find externals quickly.	*/
#define	_U(name)	name

#define	XL	r26
#define	XH	r27
#define	YL	r28
#define	YH	r29
#define	ZL	r30
#define	ZH	r31

#define SPL_IO_ADDR	0x3D
#define SPH_IO_ADDR	0x3E

.macro	FUNCTION name
  .ifdef  .Lfunction
    .err    "FUNCTION is defined already"
  .endif
	.Lfunction = 1
#ifdef	FUNC_SEGNAME
	.section  FUNC_SEGNAME, "ax", @progbits
#else
	.text
#endif
	.type	_U(\name), "function"
  .ifdef   .LEND
    .err    ".LEND is defined already"
  .endif
	.size	_U(\name), .LEND - .
.endm
#define	FUNCTION  FUNCTION	/* for CPP conditional expressions	*/

.macro	ENTRY	name
  .ifndef .Lfunction
FUNCTION \name
  .endif
	.global	_U(\name)
_U(\name):
.endm

.macro	ENDFUNC
.LEND:
.endm

/* Macro 'X_movw' extends enhanced movw instruction for classic chips.
 */
.macro	X_movw	dst,src
#if  defined(__AVR_HAVE_MOVW__) && __AVR_HAVE_MOVW__
	movw	\dst,\src
#else
    .L_movw_dst = -1
    .L_movw_src = -1
    .L_movw_n = 0
    .irp  reg,   r0, r2, r4, r6, r8,	\
		r10,r12,r14,r16,r18,	\
		r20,r22,r24,r26,r28,r30
	.ifc  \reg,\dst
	    .L_movw_dst = .L_movw_n
	.endif
	.ifc  \reg,\src
	    .L_movw_src = .L_movw_n
	.endif
	.L_movw_n = .L_movw_n + 2
    .endr
    .if   .L_movw_dst < 0
	.L_movw_n = 0
	.rept   16
	    .if \dst == .L_movw_n
		.L_movw_dst = .L_movw_n
	    .endif
	    .L_movw_n = .L_movw_n + 2
	.endr
    .endif
    .if   .L_movw_src < 0
	.L_movw_n = 0
	.rept   16
	    .if \src == .L_movw_n
		.L_movw_src = .L_movw_n
	    .endif
	    .L_movw_n = .L_movw_n + 2
	.endr
    .endif
    .if   (.L_movw_dst < 0) || (.L_movw_src < 0)
	.err    "Invalid arg of the X_movw macro."
    .endif
	mov	\dst, \src
	mov	.L_movw_dst + 1, .L_movw_src + 1
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
  .L_lpm_dst = -1

  .L_lpm_n = 0
  .irp  reg,  r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, \
	     r10,r11,r12,r13,r14,r15,r16,r17,r18,r19, \
	     r20,r21,r22,r23,r24,r25,r26,r27,r28,r29, \
	     r30,r31
    .ifc  \reg,\dst
      .L_lpm_dst = .L_lpm_n
    .endif
    .L_lpm_n = .L_lpm_n + 1
  .endr

  .L_lpm_n = 0
  .irp  reg,  R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, \
	     R10,R11,R12,R13,R14,R15,R16,R17,R18,R19, \
	     R20,R21,R22,R23,R24,R25,R26,R27,R28,R29, \
	     R30,R31
    .ifc  \reg,\dst
      .L_lpm_dst = .L_lpm_n
    .endif
    .L_lpm_n = .L_lpm_n + 1
  .endr

  .if  .L_lpm_dst < 0
    .L_lpm_n = 0
    .rept 32
      .if  \dst == .L_lpm_n
	.L_lpm_dst = .L_lpm_n
      .endif
      .L_lpm_n = .L_lpm_n + 1
    .endr
  .endif

  .if  (.L_lpm_dst < 0)
    .err	"Invalid dst arg of 'X_lpm' macro."
  .endif

  /* src evaluation	*/    
  .L_lpm_src = -1
  .L_lpm_n = 0
  .irp  reg,  z,Z,z+,Z+
    .ifc  \reg,\src
      .L_lpm_src = .L_lpm_n
    .endif
    .L_lpm_n = .L_lpm_n + 1
  .endr

  .if  (.L_lpm_src < 0)
    .err	"Invalid src arg of 'X_lpm' macro."
  .endif

  /* instruction(s)	*/    
  .if  .L_lpm_src < 2
    .if  .L_lpm_dst == 0
	lpm
    .else
#if  defined(__AVR_HAVE_LPMX__) && __AVR_HAVE_LPMX__
	lpm	.L_lpm_dst, Z
#else
	lpm
	mov	.L_lpm_dst, r0
#endif
    .endif
  .else
    .if  (.L_lpm_dst >= 30)
      .err	"Registers 30 and 31 are inhibited as 'X_lpm *,Z+' dst."
    .endif
#if  defined(__AVR_HAVE_LPMX__) && __AVR_HAVE_LPMX__
	lpm	.L_lpm_dst, Z+
#else
	lpm
    .if  .L_lpm_dst
	mov	.L_lpm_dst, r0
    .endif
	adiw	r30, 1
#endif
  .endif
.endm

#endif	/* !_ASMDEF_H */
