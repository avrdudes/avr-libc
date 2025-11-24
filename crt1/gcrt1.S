/* Copyright (c) 2002, Marek Michalkiewicz <marekm@amelek.gda.pl>
   Copyright (c) 2007, 2008 Eric B. Weddington
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

/* Introduction to the Startup Code
   ================================

   The startup-code has been designed to provide maximal flexibility,
   and to reduce overhead when possible.  To that end, the startup code
   is being stiched together by the linker from a multitude of parts.
   A part is pulled in when the respective symbol is undefined.

   Notice that when a part is not available for some reason, e.g. you
   are linking with -nodefaultlibs, then the linker WILL NOT complain
   about an undefined reference, since these symbols are usually
   referenced like  .global __init_sp   or  -Wl,-u,__do_flmap_init.

   The startup code is composed of the following parts:

   - Code in this file.

   - Code hosted by GCC's libgcc:
       o  __do_copy_data          Initialize .[ro]data from flash    [1]
       o  __do_clear_bss          Clear .bss                         [1]
       o  __do_global_ctors       Run static constructors            [1]
       o  __do_global_dtors       Run static destructors             [1]

   - Code hosted by AVR-LibC's lib<mcu>.a
       o  __init_sp               Initialize SP with symbol __stack  [2]
       o  __init_cvt              Activate a Compact Vector Table    [3]
       o  __do_flmap_init         Set FLMAP according to __flmap     [4]
       o  __call_main             Call main() and jump to exit().    [5]

   [1] The compiler will pull in that code only when it is needed.
       See  https://gcc.gnu.org/PR18145
   [2] Always[6] pulled in by the code below.  The user may satisfy the
       symbol when SP is initialized by hardware, and SP=RAMEND is fine.
   [3] Always[6] pulled in by the USE_COMPACT_VECTOR_TABLE variant.
   [4] Pulled in by the compiler (the device-specs file actually) when
       the code is compiled for a device with FLMAP (AVR64, AVR128)
       and -mrodata-in-ram is NOT selected (the default).  This part of
       the startup code is the most complicated of all:
       - With -mrodata-in-ram, the avrxmega2/4 emulation is selected.
       - With rodata in flash (default) the avrxmega2/4_flmap emulation
         is selected.
       The default linker script for the respective emulation defines
       symbols to augment the __do_flmap_init code, for example it
       selects a label to (not) skip the initialization of FLMAP.
       The NVMCTRL_CTRLB.FLMAP selects which 32 KiB portion of the
       program flash memory is visible in the RAM address space, and
       can be chosen by defining symbol __flmap.
          For more technical details see  https://sourceware.org/PR31124
       https://gcc.gnu.org/PR112944  and also libc/misc/flmap.init.S
       which implements __do_flmap_init.
   [5] Always[6] pulled in by the code below.  Calls main() and then
       jumps to exit().  With -mno-call-main, the compiler will put
       main itself into .init9 any satisfy __call_main.
   [6] When CRT_SELF_CONTAINED if off, the respective parts will be pulled in.
       When CRT_SELF_CONTAINED is on, the code is inserted inline below.

   Customizing the Startup Code using C Macros
   ===========================================

   CRT_SELF_CONTAINED
      If defined, include code that otherwise will be outsourced to the
      device library lib<mcu>.a.  This is a choice when you are building
      the startup code on your own, without the burden of also having to
      build the device library.  AVR-LibC doesn't use CRT_SELF_CONTAINED.

      If not defined (default), outsourced code will be pulled in from
      the device library lib<mcu>.a.  The compiler can pull in respective
      parts of the startup code as needed.  When some part of the code
      is not needed or desired, the respective symbol can be satisfied
      by the compiler or the user:

      Pulling in can be achieved by asm code like  .global <symbol>
      or by means of linking with  -Wl,-u,<symbol>

      Defining a symbol so the respective code is not pulled in can be
      achieved by asm code like
          .global <symbol>
          <symbol> = 0
      or by means of linking with  -Wl,--defsym,<symbol>=0

      The following parts are affected by CRT_SELF_CONTAINED:

      - Initialize SP to the value of symbol __stack.
        Section: .init2    Symbol: __init_sp

      - Set bit CPUINT_CTRLA.CPUINT_CVT provided the build variant for a
        compact vector table has been selected (USE_COMPACT_VECTOR_TABLE).
        Section: .init3    Symbol: __init_cvt

      - Call main() and jump to exit().
        Section: .init9    Symbol: __call_main

   USE_COMPACT_VECTOR_TABLE
      Some devices support a CVT with only 4 entries: 0=Reset, 1=NMI,
      2=Prio1 IRQ, 3=Prio0 IRQs.  This macro activates a build variant
      with a CVT, and that adds code to .init3 which activates the CVT.

   HAVE_LDSCRIPT_PR29741
   HAVE_LDSCRIPT_PR31177
      Defined if respective features from GNU Binutils are available.
      You can:
      - Goto https://sourceware.org/PR29741 and https://sourceware.org/PR31177
        and find out whether your version of Binutils is supporting them.
      - Reproduce how the toplevel configure.ac is determining them.
      - Don't define them.  Drawback will be less precise diagnostics
        from the linker when you are running out of RAM or Flash, and
        less precise size reports.
 */

#include IOSYMFILE

#include <avr/io.h>
#include <bits/devinfo.h>
#include "asmdef.h"
#include "config.h"

;; Use _VECTOR_SIZE from the I/O header which might be more reliable than
;; using asmdef.h's XJMP according to __AVR_HAVE_JMP_CALL__.  As an example,
;; take ATmega808 which avr-gcc lists as short-calls and thus with a vector
;; size of 2 bytes according to asmdef.h, but ATmega808 has _VECTOR_SIZE = 4.
#ifdef _VECTOR_SIZE
#undef XJMP
#if _VECTOR_SIZE == 2
#define XJMP rjmp
#elif _VECTOR_SIZE == 4
#define XJMP jmp
#else
#error _VECTOR_SIZE must be 2 or 4 bytes
#endif
#endif /* _VECTOR_SIZE */

;; Devices that support a CVT (Compact Vector Table) have only 4 vectors.
;; This is a build variant for crt<mcu>-cvt.o realized by Device.am.
#ifdef USE_COMPACT_VECTOR_TABLE
#undef  _VECTORS_SIZE
#define _VECTORS_SIZE (4 * _VECTOR_SIZE)

#ifdef CRT_SELF_CONTAINED
    .pushsection ".init3", "ax", @progbits
    /* Definitions in avr/io*.h are neglecting assembly, so...  */
#   ifndef CCP_IOREG_gc
#   define CCP_IOREG_gc    0xD8    /* IO Register Protection */
#   endif
    lds     r18, CPUINT_CTRLA
    ori     r18, CPUINT_CVT_bm
    ldi     r19, CCP_IOREG_gc   ; Load I/O reg change protection signature.
    out     CCP, r19
    sts     CPUINT_CTRLA, r18
    .popsection
#else
    ;; Pull in code from libmcu.a to set CPUINT_CTRLA.CPUINT_CVT in .init3.
    .global __init_cvt
#endif /* CRT self contained */
#endif /* Use Compact Vector Table */

	.macro	vector name
	.if (. - __vectors < _VECTORS_SIZE)
	.weak	\name
	.set	\name, __bad_interrupt
	XJMP	\name
	.endif
	.endm

	.section .vectors,"ax",@progbits
	.global	__vectors
	.func	__vectors
__vectors:
	XJMP	__init
	vector	__vector_1
	vector	__vector_2
	vector	__vector_3
	vector	__vector_4
	vector	__vector_5
	vector	__vector_6
	vector	__vector_7
	vector	__vector_8
	vector	__vector_9
	vector	__vector_10
	vector	__vector_11
	vector	__vector_12
	vector	__vector_13
	vector	__vector_14
	vector	__vector_15
	vector	__vector_16
	vector	__vector_17
	vector	__vector_18
	vector	__vector_19
	vector	__vector_20
	vector	__vector_21
	vector	__vector_22
	vector	__vector_23
	vector	__vector_24
	vector	__vector_25
	vector	__vector_26
	vector	__vector_27
	vector	__vector_28
	vector	__vector_29
	vector	__vector_30
	vector	__vector_31
	vector	__vector_32
	vector	__vector_33
	vector	__vector_34
	vector	__vector_35
	vector	__vector_36
	vector	__vector_37
	vector	__vector_38
	vector	__vector_39
	vector	__vector_40
	vector	__vector_41
	vector	__vector_42
	vector	__vector_43
	vector	__vector_44
	vector	__vector_45
	vector	__vector_46
	vector	__vector_47
	vector	__vector_48
	vector	__vector_49
	vector	__vector_50
	vector	__vector_51
	vector	__vector_52
	vector	__vector_53
	vector	__vector_54
	vector	__vector_55
	vector	__vector_56
	vector	__vector_57
	vector	__vector_58
	vector	__vector_59
	vector	__vector_60
	vector	__vector_61
	vector	__vector_62
	vector	__vector_63
	vector	__vector_64
	vector	__vector_65
	vector	__vector_66
	vector	__vector_67
	vector	__vector_68
	vector	__vector_69
	vector	__vector_70
	vector	__vector_71
	vector	__vector_72
	vector	__vector_73
	vector	__vector_74
	vector	__vector_75
	vector	__vector_76
	vector	__vector_77
	vector	__vector_78
	vector	__vector_79
	vector	__vector_80
	vector	__vector_81
	vector	__vector_82
	vector	__vector_83
	vector	__vector_84
	vector	__vector_85
	vector	__vector_86
	vector	__vector_87
	vector	__vector_88
	vector	__vector_89
	vector	__vector_90
	vector	__vector_91
	vector	__vector_92
	vector	__vector_93
	vector	__vector_94
	vector	__vector_95
	vector	__vector_96
	vector	__vector_97
	vector	__vector_98
	vector	__vector_99
	vector	__vector_100
	vector	__vector_101
	vector	__vector_102
	vector	__vector_103
	vector	__vector_104
	vector	__vector_105
	vector	__vector_106
	vector	__vector_107
	vector	__vector_108
	vector	__vector_109
	vector	__vector_110
	vector	__vector_111
	vector	__vector_112
	vector	__vector_113
	vector	__vector_114
	vector	__vector_115
	vector	__vector_116
	vector	__vector_117
	vector	__vector_118
	vector	__vector_119
	vector	__vector_120
	vector	__vector_121
	vector	__vector_122
	vector	__vector_123
	vector	__vector_124
	vector	__vector_125
	vector	__vector_126
	vector	__vector_127
#ifdef __AVR_SD__  /* From <bits/devinfo.h> */
	;; On the AVR-SD devices, instructions must not be followed by an
	;; illegal opcode.  This is since illegal opcode detection runs at
	;; instruction fetch of the NEXT instruction, which is being run while
	;; the 2-stage pipeline is executing the current instruction.
	;; Any valid opcode will do, so use CLH which disassembles more
	;; nicely than NOP = 0x0000.
	clh
#endif /* __AVR_SD__ */
	.endfunc

#ifdef __AVR_SD__
	;; For the same reason, put a valid opcode after the last location that
	;; holds valid code, which is the .hightext section of the default
	;; linker script.  Notice that .hightext is usually unused.
	;; We assume Binutils 2.36+ so that we have section flag "R"etain.
	.pushsection .hightext.zzz, "axR", @progbits
	clh
	.popsection
#endif /* __AVR_SD__ */

	/* Handle unexpected interrupts (enabled and no handler), which
	   usually indicate a bug.  Jump to the __vector_default function
	   if defined by the user, otherwise jump to the reset address.

	   This must be in a different section, otherwise the assembler
	   will resolve "rjmp" offsets and there will be no relocs.  */

	.text
	.global	__bad_interrupt
	.func	__bad_interrupt
__bad_interrupt:
	.weak	__vector_default
	.set	__vector_default, __vectors
	XJMP	__vector_default
	.endfunc

	.section .init0,"ax",@progbits
	.weak	__init
;	.func	__init
__init:

#ifndef __AVR_ASM_ONLY__
	.weak	__stack

	/* By default, malloc() uses the current value of the stack pointer
	   minus __malloc_margin as the highest available address.

	   In some applications with external SRAM, the stack can be below
	   the data section (in the internal SRAM - faster), and __heap_end
	   should be set to the highest address available for malloc().  */
	.weak	__heap_end
	.set	__heap_end, 0

	.section .init2,"ax",@progbits
	clr	__zero_reg__
	out	SREG_IO_ADDR, __zero_reg__

#ifdef CRT_SELF_CONTAINED
#if defined(CPU_SPLIM)
	;; Setting SPLIM is a bit tricky, since we don't know the value
	;; of __heap_start, and we don't know the current value of SP
	;; in the case of a soft reset.	 Hence, set SPLIM = 0 first.
	out _SFR_IO_ADDR(CPU_SPLIML), __zero_reg__
	out _SFR_IO_ADDR(CPU_SPLIMH), __zero_reg__
#endif /* Have SPLIM */

	ldi	r28, lo8(__stack)
#ifdef __AVR_XMEGA__
	out	SPL_IO_ADDR, r28
#ifdef SPH_IO_ADDR
	ldi	r29, hi8(__stack)
	out	SPH_IO_ADDR, r29
#endif  /* Have SPH */
#else
#ifdef SPH_IO_ADDR
	ldi	r29, hi8(__stack)
	out	SPH_IO_ADDR, r29
#endif  /* Have SPH */
#ifdef SPL_IO_ADDR
	out	SPL_IO_ADDR, r28
#endif  /* Have SPL */
#endif  /* __AVR_XMEGA__ */

#if defined(CPU_SPLIM)
	ldi r24, lo8(__heap_start - 1)
	ldi r25, hi8(__heap_start - 1)
	out _SFR_IO_ADDR(CPU_SPLIML), r24
	out _SFR_IO_ADDR(CPU_SPLIMH), r25
#endif /* Have SPLIM */
#else
	;; Pull in __init_sp from the device lib to .init2
	.global __init_sp
#endif /* CRT self contained */

#ifdef __AVR_3_BYTE_PC__
	ldi	r16, hh8(pm(__vectors))
	out	EIND_IO_ADDR, r16
#endif	/* __AVR_3_BYTE_PC__ */

#ifdef __AVR_HAVE_RAMPD__
	out	RAMPD_IO_ADDR, __zero_reg__
	out	RAMPX_IO_ADDR, __zero_reg__
	out	RAMPY_IO_ADDR, __zero_reg__
	out	RAMPZ_IO_ADDR, __zero_reg__
#endif

	.set	__stack, RAMEND
#endif /* !__AVR_ASM_ONLY__ */

#ifdef CRT_SELF_CONTAINED
	.section .init9,"ax",@progbits
#ifdef __AVR_ASM_ONLY__
	XJMP	main
#else	/* !__AVR_ASM_ONLY__ */
	XCALL	main
	XJMP	exit
#endif	/* __AVR_ASM_ONLY__ */
#else
	;; Pull in __call_main from the device lib to .init9
	.global __call_main
#endif /* CRT self contained */

;	.endfunc

    .section .note.gnu.avr.deviceinfo, "", @note
#define NOTE_NAME "AVR"
#ifdef __AVR_DEVICE_NAME__
    #define DEVICE_NAME STR(__AVR_DEVICE_NAME__)
#else
    #define DEVICE_NAME ""
#endif

    .long .L__note_name_end - .L__note_name_start
    .long .L__desc_end - .L__desc_start
    .long 1 ; Type 1 - this is the only known note type for AVR.
.L__note_name_start:
    .asciz NOTE_NAME
    .balign 4
.L__note_name_end:
.L__desc_start:
#ifdef FLASHSTART
    .long FLASHSTART
#else
    .long 0
#endif
#ifdef PROGMEM_SIZE
    .long PROGMEM_SIZE
#elif FLASHEND > 0
    .long FLASHEND + 1
#else
    .long 0
#endif
    .long RAMSTART
#ifdef RAMSIZE
    .long RAMSIZE
#elif RAMEND > RAMSTART
    .long RAMEND - RAMSTART + 1
#else
    .long 0
#endif
#ifdef E2START
    .long E2START
#else
    .long 0
#endif
#ifdef EEPROM_SIZE
    .long EEPROM_SIZE
#elif E2END > 0
    .long E2END + 1
#else
    .long 0
#endif
    /* String offsets table.
    Index 0 - Size of offset table in bytes
    Index 1 - Device name byte offset
    */
.L__stroffsettab_start:
.long .L__stroffsettab_end - .L__stroffsettab_start /* Size of index table in bytes */
.long .L__device_name_start - .L__strtab_start /* Byte offset of device name */
.L__stroffsettab_end:
    /* String table for storing arbitrary strings.
    Offsets are stored in the string offset table above */
.L__strtab_start:
    .byte 0
.L__device_name_start:
    .asciz DEVICE_NAME
.L__device_name_end:
    .byte 0
.L__strtab_end:
.L__desc_end:
    .balign 4


/* Set REGION_LENGTH symbol values for well known memory regions.
   The default linker script uses these symbols to set MEMORY
   region lengths, and by defining these here, the linker can detect
   memory overflows accurately on a per device basis, since the
   values are picked up from the device header file.  */

#if defined (FLASHEND)
#if ! defined FLASHSTART
#define FLASHSTART 0
#endif
    ;; Some of the Automotive devices have Flash start at 0x8000,
    ;; but MEMORY region text starts at __TEXT_REGION_ORIGIN__ only
    ;; since Binutils PR31177 (v2.42 released 2024).  Older versions
    ;; of Binutils have text region start hard coded as 0x0.
    ;; Therefore, only provide strict text region layout for devices
    ;; where program memory starts at 0x0.
#if FLASHSTART == 0 || defined (HAVE_LDSCRIPT_PR31177)
    .weak __TEXT_REGION_ORIGIN__
    .set  __TEXT_REGION_ORIGIN__, (FLASHSTART)
    .weak __TEXT_REGION_LENGTH__
    .set  __TEXT_REGION_LENGTH__, 1 + (FLASHEND) - (FLASHSTART)
#endif /* FLASHSTART == 0 */
#endif /* FLASHEND */

;; The RAM virtual memory address used by Binutils to linearize memory.
#define RAM_VMA 0x800000

;; __DATA_REGION_ORIGIN__ is used since ld v2.40 / 2023-01-14 / PR29741.
;; Prior to that, a core specific default value $DATA_ORIGIN was used.
;; __DATA_REGION_LENGTH__ however is in use since 2015 / cb0728165e282b
;; which means that with Binutils older than v2.40, we may get a
;;    ld: address <X> of <FILE> section `.data' is not within region `data'
;; error from the linker when $DATA_ORIGIN is not __DATA_REGION_ORIGIN__.
#if defined (RAMSTART) && defined (RAMEND) && defined (HAVE_LDSCRIPT_PR29741)
    .weak __DATA_REGION_ORIGIN__
    .set  __DATA_REGION_ORIGIN__, (RAM_VMA) | (RAMSTART)
    .weak __DATA_REGION_LENGTH__
#if RAMEND > RAMSTART
    .set  __DATA_REGION_LENGTH__, 1 + (RAMEND) - (RAMSTART)
#else
    .set  __DATA_REGION_LENGTH__, 0
#endif
#endif /* have RAMSTART and RAMEND */

/* The VMA ORIGINs of other MEMORY regions are hard-coded in the ld scripts:
   eeprom:          0x810000
   fuse:            0x820000
   lock:            0x830000
   signature:       0x840000
   user_signatures: 0x850000
   rodata:          0xa00000  (only for the AVR64 and AVR128 devices)  */

#if defined (EEPROM_SIZE) && (EEPROM_SIZE) > 0
    .weak __EEPROM_REGION_LENGTH__
    .set  __EEPROM_REGION_LENGTH__, EEPROM_SIZE
#elif defined (E2END) && (E2END) > 0
    .weak __EEPROM_REGION_LENGTH__
    .set  __EEPROM_REGION_LENGTH__, 1 + (E2END)
#endif /* E2END > 0 */

#if defined (FUSES_SIZE) && (FUSES_SIZE) > 0
    .weak __FUSE_REGION_LENGTH__
    .set  __FUSE_REGION_LENGTH__, FUSES_SIZE
#elif defined (FUSE_MEMORY_SIZE) && (FUSE_MEMORY_SIZE) > 0
    .weak __FUSE_REGION_LENGTH__
    .set  __FUSE_REGION_LENGTH__, FUSE_MEMORY_SIZE
#endif

#if defined (LOCKBITS_SIZE) && (LOCKBITS_SIZE) > 0
    .weak __LOCK_REGION_LENGTH__
    .set  __LOCK_REGION_LENGTH__, LOCKBITS_SIZE
#endif

#if defined (USER_SIGNATURES_SIZE) && (USER_SIGNATURES_SIZE) > 0
    .weak __USER_SIGNATURE_REGION_LENGTH__
    .set  __USER_SIGNATURE_REGION_LENGTH__, USER_SIGNATURES_SIZE
#endif

#if defined (SIGNATURES_SIZE) && (SIGNATURES_SIZE) > 0
    .weak __SIGNATURE_REGION_LENGTH__
    .set  __SIGNATURE_REGION_LENGTH__, SIGNATURES_SIZE
#endif
