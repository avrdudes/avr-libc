/* Copyright (c) 2002, Marek Michalkiewicz <marekm@amelek.gda.pl>
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
   POSSIBILITY OF SUCH DAMAGE.  */

/* avr/sfr_defs.h - macros for accessing AVR special function registers */

/* $Id$ */

#ifndef _AVR_SFR_DEFS_H_
#define _AVR_SFR_DEFS_H_ 1

/** \defgroup avr_sfr_notes Additional notes from <avr/sfr_defs.h>
    \ingroup avr_sfr

   The \c <avr/sfr_defs.h> file is included by all of the \c <avr/ioXXXX.h>
   files, which use macros defined here to make the special function register
   definitions look like C variables or simple constants, depending on the
   <tt>_SFR_ASM_COMPAT</tt> define.  Some examples from \c <avr/iom128.h> to
   show how to define such macros:

\code
#define PORTA _SFR_IO8(0x1b)
#define TCNT1 _SFR_IO16(0x2c)
#define PORTF _SFR_MEM8(0x61)
#define TCNT3 _SFR_MEM16(0x88)
\endcode

   If \c _SFR_ASM_COMPAT is not defined, C programs can use names like
   <tt>PORTA</tt> directly in C expressions (also on the left side of
   assignment operators) and GCC will do the right thing (use short I/O
   instructions if possible).  The \c __SFR_OFFSET definition is not used in
   any way in this case.

   Define \c _SFR_ASM_COMPAT as 1 to make these names work as simple constants
   (addresses of the I/O registers).  This is necessary when included in
   preprocessed assembler (*.S) source files, so it is done automatically if
   \c __ASSEMBLER__ is defined.  By default, all addresses are defined as if
   they were memory addresses (used in \c lds/sts instructions).  To use these
   addresses in \c in/out instructions, you must subtract 0x20 from them.

   For more backwards compatibility, insert the following at the start of your
   old assembler source file:

\code
#define __SFR_OFFSET 0
\endcode

   This automatically subtracts 0x20 from I/O space addresses, but it's a
   hack, so it is recommended to change your source: wrap such addresses in
   macros defined here, as shown below.  After this is done, the
   <tt>__SFR_OFFSET</tt> definition is no longer necessary and can be removed.

   Real example - this code could be used in a boot loader that is portable
   between devices with \c SPMCR at different addresses.

\verbatim
<avr/iom163.h>: #define SPMCR _SFR_IO8(0x37)
<avr/iom128.h>: #define SPMCR _SFR_MEM8(0x68)
\endverbatim

\code
#if _SFR_IO_REG_P(SPMCR)
	out	_SFR_IO_ADDR(SPMCR), r24
#else
	sts	_SFR_MEM_ADDR(SPMCR), r24
#endif
\endcode

   You can use the \c in/out/cbi/sbi/sbic/sbis instructions, without the
   <tt>_SFR_IO_REG_P</tt> test, if you know that the register is in the I/O
   space (as with \c SREG, for example).  If it isn't, the assembler will
   complain (I/O address out of range 0...0x3f), so this should be fairly
   safe.

   If you do not define \c __SFR_OFFSET (so it will be 0x20 by default), all
   special register addresses are defined as memory addresses (so \c SREG is
   0x5f), and (if code size and speed are not important, and you don't like
   the ugly #if above) you can always use lds/sts to access them.  But, this
   will not work if <tt>__SFR_OFFSET</tt> != 0x20, so use a different macro
   (defined only if <tt>__SFR_OFFSET</tt> == 0x20) for safety:

\code
	sts	_SFR_ADDR(SPMCR), r24
\endcode

   In C programs, all 3 combinations of \c _SFR_ASM_COMPAT and
   <tt>__SFR_OFFSET</tt> are supported - the \c _SFR_ADDR(SPMCR) macro can be
   used to get the address of the \c SPMCR register (0x57 or 0x68 depending on
   device).

   The old inp()/outp() macros are still supported, but not recommended to use
   in new code.  The order of outp() arguments is confusing. */

#ifdef __ASSEMBLER__
#define _SFR_ASM_COMPAT 1
#endif

#ifndef __ASSEMBLER__
/* These only work in C programs.  */
#define _MMIO_BYTE(mem_addr) (*(volatile unsigned char *)(mem_addr))
#define _MMIO_WORD(mem_addr) (*(volatile unsigned int *)(mem_addr))
#endif

#if _SFR_ASM_COMPAT

#ifndef __SFR_OFFSET
/* Define as 0 before including this file for compatibility with old asm
   sources that don't subtract __SFR_OFFSET from symbolic I/O addresses.  */
#define __SFR_OFFSET 0x20
#endif

#if (__SFR_OFFSET != 0) && (__SFR_OFFSET != 0x20)
#error "__SFR_OFFSET must be 0 or 0x20"
#endif

#define _SFR_MEM8(mem_addr) (mem_addr)
#define _SFR_MEM16(mem_addr) (mem_addr)
#define _SFR_IO8(io_addr) ((io_addr) + __SFR_OFFSET)
#define _SFR_IO16(io_addr) ((io_addr) + __SFR_OFFSET)

#define _SFR_IO_ADDR(sfr) ((sfr) - __SFR_OFFSET)
#define _SFR_MEM_ADDR(sfr) (sfr)
#define _SFR_IO_REG_P(sfr) ((sfr) < 0x40 + __SFR_OFFSET)

#if (__SFR_OFFSET == 0x20)
/* No need to use ?: operator, so works in assembler too.  */
#define _SFR_ADDR(sfr) _SFR_MEM_ADDR(sfr)
#elif !defined(__ASSEMBLER__)
#define _SFR_ADDR(sfr) (_SFR_IO_REG_P(sfr) ? (_SFR_IO_ADDR(sfr) + 0x20) : _SFR_MEM_ADDR(sfr))
#endif

#else  /* !_SFR_ASM_COMPAT */

#define _SFR_MEM8(mem_addr) _MMIO_BYTE(mem_addr)
#define _SFR_MEM16(mem_addr) _MMIO_WORD(mem_addr)
#define _SFR_IO8(io_addr) _MMIO_BYTE((io_addr) + 0x20)
#define _SFR_IO16(io_addr) _MMIO_WORD((io_addr) + 0x20)

#define _SFR_MEM_ADDR(sfr) ((unsigned int) &(sfr))
#define _SFR_IO_ADDR(sfr) (_SFR_MEM_ADDR(sfr) - 0x20)
#define _SFR_IO_REG_P(sfr) (_SFR_MEM_ADDR(sfr) < 0x60)

#define _SFR_ADDR(sfr) _SFR_MEM_ADDR(sfr)

#endif /* !_SFR_ASM_COMPAT */

/** \name Bit manipulation */

/*@{*/
/** \def _BV
    \ingroup avr_sfr

    \code #include <avr/io.h>\endcode

    Converts a bit number into a byte value.

    \note The bit shift is performed by the compiler which then inserts the
    result into the code. Thus, there is no run-time overhead when using
    _BV(). */
    
#define _BV(bit) (1 << (bit))

/*@}*/

#ifndef _VECTOR
#define _VECTOR(N) __vector_ ## N
#endif

#ifndef __ASSEMBLER__


/** \name IO register bit manipulation */

/*@{*/



/** \def bit_is_set
    \ingroup avr_sfr

    \code #include <avr/io.h>\endcode

    Test whether bit \c bit in IO register \c sfr is set. 
    This will return a 0 if the bit is clear, and non-zero
    if the bit is set. */

#define bit_is_set(sfr, bit) (sfr & _BV(bit))

/** \def bit_is_clear
    \ingroup avr_sfr

    \code #include <avr/io.h>\endcode

    Test whether bit \c bit in IO register \c sfr is clear. 
    This will return non-zero if the bit is clear, and a 0
    if the bit is set. */

#define bit_is_clear(sfr, bit) (!(sfr & _BV(bit)))

/** \def loop_until_bit_is_set
    \ingroup avr_sfr

    \code #include <avr/io.h>\endcode

    Wait until bit \c bit in IO register \c sfr is set. */

#define loop_until_bit_is_set(sfr, bit) do { } while (bit_is_clear(sfr, bit))

/** \def loop_until_bit_is_clear
    \ingroup avr_sfr

    \code #include <avr/io.h>\endcode

    Wait until bit \c bit in IO register \c sfr is clear. */

#define loop_until_bit_is_clear(sfr, bit) do { } while (bit_is_set(sfr, bit))

/*@}*/

#endif /* !__ASSEMBLER__ */

/* Backwards compatibility, do not use in new programs.  */

/** \name Deprecated Macros */
/*@{*/


/** \def cbi
    \ingroup avr_sfr
    \deprecated
    \code #include <avr/io.h>\endcode
    For backwards compatibility only. This macro will eventually be removed.

    Clear bit \c bit in IO register \c sfr. */

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))

/** \def sbi
    \ingroup avr_sfr
    \deprecated
    \code #include <avr/io.h>\endcode
    For backwards compatibility only. This macro will eventually be removed.

    Set bit \c bit in IO register \c sfr. */

#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))



/** \def inb
    \ingroup avr_sfr
    \deprecated
    \code #include <avr/io.h>\endcode
    For backwards compatibility only. This macro will eventually be removed.

    \par
    <b>Use direct access in new programs</b>. */

#define inb(sfr) _SFR_BYTE(sfr)



/** \def outb
    \ingroup avr_sfr
    \deprecated
    \code #include <avr/io.h>\endcode

    For backwards compatibility only. This macro will eventually be removed.

    \par
    <b>Use direct access in new programs</b>.
    
    \note The order of the arguments was switched in older versions of
    avr-libc (versions <= 20020203). */


#define outb(sfr, val) (_SFR_BYTE(sfr) = (val))


#define _SFR_BYTE(sfr) _MMIO_BYTE(_SFR_ADDR(sfr))
#define _SFR_WORD(sfr) _MMIO_WORD(_SFR_ADDR(sfr))

/* The outb/outw macros now have the correct order of arguments.  */

/** \def inw
    \ingroup avr_sfr
    \deprecated
    \code #include <avr/io.h>\endcode
    For backwards compatibility only. This macro will eventually be removed.

    Read a 16-bit word from IO register pair \c sfr. 
    
    \par
    <b>Use direct access in new programs</b>. */

#define inw(sfr) _SFR_WORD(sfr)


/** \def outw
    \ingroup avr_sfr
    \deprecated
    \code #include <avr/io.h>\endcode
    For backwards compatibility only. This macro will eventually be removed.

    Write the 16-bit value \c val to IO register pair \c sfr.  Care
    will be taken to write the lower register first.  When used to
    update 16-bit registers where the timing is critical and the
    operation can be interrupted, the programmer is the responsible for
    disabling interrupts before accessing the register pair.

    \par
    <b>Use direct access in new programs</b>.

    \note The order of the arguments was switched in older versions of
    avr-libc (versions <= 20020203). */


#define outw(sfr, val) (_SFR_WORD(sfr) = (val))


/** \def outp
    \ingroup avr_sfr
    \deprecated
    For backwards compatibility only. This macro will eventually be removed.

    \par
    <b>Use direct access in new programs</b>. */

#define outp(val, sfr) outb(sfr, val)

/** \def inp
    \ingroup avr_sfr
    \deprecated
    For backwards compatibility only. This macro will eventually be removed.

    \par
    <b>Use direct access in new programs</b>. */

#define inp(sfr) inb(sfr)

/** \def BV
    \ingroup avr_sfr
    \deprecated
    For backwards compatibility only. This macro will eventually be removed.

    \par
    <b>Use _BV() in new programs</b>. */

#define BV(bit) _BV(bit)

/*@}*/

#endif  /* _SFR_DEFS_H_ */
