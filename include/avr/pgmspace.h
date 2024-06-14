/* Copyright (c) 2002-2007  Marek Michalkiewicz
   Copyright (c) 2006, Carlos Lamas
   Copyright (c) 2009-2010, Jan Waclawek
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
   pgmspace.h

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
     Eric B. Weddington <eric@ecentral.com>
     Wolfgang Haidinger <wh@vmars.tuwien.ac.at> (pgm_read_dword())
     Ivanov Anton <anton@arc.com.ru> (pgm_read_float())
 */

/** \file */
/** \defgroup avr_pgmspace <avr/pgmspace.h>: Program Space Utilities
    \code
    #include <avr/io.h>
    #include <avr/pgmspace.h>
    \endcode

    The functions in this module provide interfaces for a program to access
    data stored in program space (flash memory) of the device.

    \note These functions are an attempt to provide some compatibility with
    header files that come with IAR C, to make porting applications between
    different compilers easier.  This is not 100% compatibility though (GCC
    does not have full support for multiple address spaces yet).

    \note If you are working with strings which are completely based in RAM,
    use the standard string functions described in \ref avr_string.

    \note If possible, put your constant tables in the lower 64 KB and use
    pgm_read_byte_near() or pgm_read_word_near() instead of
    pgm_read_byte_far() or pgm_read_word_far() since it is more efficient that
    way, and you can still use the upper 64K for executable code.
    All functions that are suffixed with a \c _P \e require their
    arguments to be in the lower 64 KB of the flash ROM, as they do
    not use ELPM instructions.  This is normally not a big concern as
    the linker setup arranges any program space constants declared
    using the macros from this header file so they are placed right after
    the interrupt vectors, and in front of any executable code.  However,
    it can become a problem if there are too many of these constants, or
    for bootloaders on devices with more than 64 KB of ROM.
    <em>All these functions will not work in that situation.</em>

    \note For <b>Xmega</b> devices, make sure the NVM controller
    command register (\c NVM.CMD or \c NVM_CMD) is set to 0x00 (NOP)
    before using any of these functions.
*/

#ifndef __PGMSPACE_H_
#define __PGMSPACE_H_ 1

#ifndef __DOXYGEN__
#define __need_size_t
#endif
#include <inttypes.h>
#include <stddef.h>
#include <avr/io.h>

#ifndef __DOXYGEN__
#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif

#ifndef __ATTR_PROGMEM__
#define __ATTR_PROGMEM__ __attribute__((__progmem__))
#endif

#ifndef __ATTR_PURE__
#define __ATTR_PURE__ __attribute__((__pure__))
#endif

#ifndef __ATTR_ALWAYS_INLINE__
#define __ATTR_ALWAYS_INLINE__ __inline__ __attribute__((__always_inline__))
#endif

#define PROGMEM __ATTR_PROGMEM__

#endif	/* !__DOXYGEN__ */

/**
   \ingroup avr_pgmspace
   \def PROGMEM_FAR

   Attribute to use in order to declare an object being located in
   far flash ROM.  This is similar to #PROGMEM, except that it puts
   the static storage object in section
   <tt>\ref sec_dot_progmemx ".progmemx.data"</tt>.
   In order to access the object,
   the <tt>pgm_read_*_far</tt> and \c _PF functions declare in this header
   can be used.  In order to get its address, see pgm_get_far_address().

   It only makes sense to put read-only objects in this section,
   though the compiler does not diagnose when this is not the case.  */
#define PROGMEM_FAR __attribute__((__section__(".progmemx.data")))

#ifdef __DOXYGEN__

/**
   \ingroup avr_pgmspace
   \def PROGMEM

   Attribute to use in order to declare an object being located in
   flash ROM.  */
#define PROGMEM __attribute__((__progmem__))

/** \ingroup avr_pgmspace
    \fn char pgm_read_char (const char *__addr)
    Read a <tt>char</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline char pgm_read_char (const char *__addr);

/** \ingroup avr_pgmspace
    \fn unsigned char pgm_read_unsigned_char (const unsigned char *__addr)
    Read an <tt>unsigned char</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline unsigned char pgm_read_unsigned_char (const unsigned char *__addr);

/** \ingroup avr_pgmspace
    \fn signed char pgm_read_signed_char (const signed char *__addr)
    Read a <tt>signed char</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline signed char pgm_read_signed_char (const signed char *__addr);

/** \ingroup avr_pgmspace
    \fn uint8_t pgm_read_u8 (const uint8_t *__addr)
    Read an <tt>uint8_t</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline uint8_t pgm_read_u8 (const uint8_t *__addr);

/** \ingroup avr_pgmspace
    \fn int8_t pgm_read_i8 (const int8_t *__addr)
    Read an <tt>int8_t</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline int8_t pgm_read_i8 (const int8_t *__addr);

/** \ingroup avr_pgmspace
    \fn short pgm_read_short (const short *__addr)
    Read a <tt>short</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline short pgm_read_short (const short *__addr);

/** \ingroup avr_pgmspace
    \fn unsigned short pgm_read_unsigned_short (const unsigned short *__addr)
    Read an <tt>unsigned short</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline unsigned short pgm_read_unsigned_short (const unsigned short *__addr);

/** \ingroup avr_pgmspace
    \fn uint16_t pgm_read_u16 (const uint16_t *__addr)
    Read an <tt>uint16_t</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline uint16_t pgm_read_u16 (const uint16_t *__addr);

/** \ingroup avr_pgmspace
    \fn int16_t pgm_read_i16 (const int16_t *__addr)
    Read an <tt>int16_t</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline int16_t pgm_read_i16 (const int16_t *__addr);

/** \ingroup avr_pgmspace
    \fn int pgm_read_int (const int *__addr)
    Read an <tt>int</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline int pgm_read_int (const int *__addr);

/** \ingroup avr_pgmspace
    \fn signed pgm_read_signed (const signed *__addr)
    Read a <tt>signed</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline signed pgm_read_signed (const signed *__addr);

/** \ingroup avr_pgmspace
    \fn unsigned pgm_read_unsigned (const unsigned *__addr)
    Read an <tt>unsigned</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline unsigned pgm_read_unsigned (const unsigned *__addr);

/** \ingroup avr_pgmspace
    \fn signed int pgm_read_signed_int (const signed int *__addr)
    Read a <tt>signed int</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline signed int pgm_read_signed_int (const signed int *__addr);

/** \ingroup avr_pgmspace
    \fn unsigned int pgm_read_unsigned_int (const unsigned int *__addr)
    Read an <tt>unsigned int</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline unsigned int pgm_read_unsigned_int (const unsigned int *__addr);

/** \ingroup avr_pgmspace
    \fn __int24 pgm_read_i24 (const __int24 *__addr)
    Read an <tt>__int24</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline __int24 pgm_read_i24 (const __int24 *__addr);

/** \ingroup avr_pgmspace
    \fn __uint24 pgm_read_u24 (const __uint24 *__addr)
    Read an <tt>__uint24</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline __uint24 pgm_read_u24 (const __uint24 *__addr);

/** \ingroup avr_pgmspace
    \fn uint32_t pgm_read_u32 (const uint32_t *__addr)
    Read an <tt>uint32_t</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline uint32_t pgm_read_u32 (const uint32_t *__addr);

/** \ingroup avr_pgmspace
    \fn int32_t pgm_read_i32 (const int32_t *__addr)
    Read an <tt>int32_t</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline int32_t pgm_read_i32 (const int32_t *__addr);

/** \ingroup avr_pgmspace
    \fn long pgm_read_long (const long *__addr)
    Read a <tt>long</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline long pgm_read_long (const long *__addr);

/** \ingroup avr_pgmspace
    \fn unsigned long pgm_read_unsigned_long (const unsigned long *__addr)
    Read an <tt>unsigned long</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline unsigned long pgm_read_unsigned_long (const unsigned long *__addr);

/** \ingroup avr_pgmspace
    \fn long long pgm_read_long_long (const long long *__addr)
    Read a <tt>long long</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline long long pgm_read_long_long (const long long *__addr);

/** \ingroup avr_pgmspace
    \fn unsigned long long pgm_read_unsigned_long_long (const unsigned long long *__addr)
    Read an <tt>unsigned long long</tt> from 16-bit (near) byte-address
    \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline unsigned long long pgm_read_unsigned_long_long (const unsigned long long *__addr);

/** \ingroup avr_pgmspace
    \fn uint64_t pgm_read_u64 (const uint64_t *__addr)
    Read an <tt>uint64_t</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline uint64_t pgm_read_u64 (const uint64_t *__addr);

/** \ingroup avr_pgmspace
    \fn int64_t pgm_read_i64 (const int64_t *__addr)
    Read an <tt>int64_t</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline int64_t pgm_read_i64 (const int64_t *__addr);

/** \ingroup avr_pgmspace
    \fn float pgm_read_float (const float *__addr)
    Read a <tt>float</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline float pgm_read_float (const float *__addr);

/** \ingroup avr_pgmspace
    \fn double pgm_read_double (const double *__addr)
    Read a <tt>double</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline double pgm_read_double (const double *__addr);

/** \ingroup avr_pgmspace
    \fn long double pgm_read_long_double (const long double *__addr)
    Read a <tt>long double</tt> from 16-bit (near) byte-address \p __addr.
    The address is in the lower 64 KiB of program memory. */
static inline long double pgm_read_long_double (const long double *__addr);

#else /* !DOXYGEN */
#if defined(__AVR_TINY__)
/* For Reduced Tiny devices, avr-gcc adds 0x4000 when it takes the address
   of a PROGMEM object.  This means we can use open coded C/C++ to read
   from progmem.  This assumes we have
   - GCC PR71948 - Make progmem work on Reduced Tiny (GCC v7 / 2016-08)  */
#define __LPM__1(res, addr)  res = *addr
#define __LPM__2(res, addr)  res = *addr
#define __LPM__3(res, addr)  res = *addr
#define __LPM__4(res, addr)  res = *addr
#define __LPM__8(res, addr)  res = *addr

#elif defined(__AVR_HAVE_LPMX__)
#define __LPM__1(res, addr)                             \
  __asm __volatile__ ("lpm %0,%a1"                      \
                      : "=r" (res) : "z" (addr))

#define __LPM__2(res, addr)                             \
  __asm __volatile__ ("lpm %A0,%a1+"            "\n\t"  \
                      "lpm %B0,%a1+"                    \
                      : "=r" (res), "+z" (addr))

#define __LPM__3(res, addr)                             \
  __asm __volatile__ ("lpm %A0,%a1+"            "\n\t"  \
                      "lpm %B0,%a1+"            "\n\t"  \
                      "lpm %C0,%a1+"                    \
                      : "=r" (res), "+z" (addr))

#define __LPM__4(res, addr)                             \
  __asm __volatile__ ("lpm %A0,%a1+"            "\n\t"  \
                      "lpm %B0,%a1+"            "\n\t"  \
                      "lpm %C0,%a1+"            "\n\t"  \
                      "lpm %D0,%a1+"                    \
                      : "=r" (res), "+z" (addr))

#define __LPM__8(res, addr)                             \
  __asm __volatile__ ("lpm %r0+0,%a1+"          "\n\t"  \
                      "lpm %r0+1,%a1+"          "\n\t"  \
                      "lpm %r0+2,%a1+"          "\n\t"  \
                      "lpm %r0+3,%a1+"          "\n\t"  \
                      "lpm %r0+4,%a1+"          "\n\t"  \
                      "lpm %r0+5,%a1+"          "\n\t"  \
                      "lpm %r0+6,%a1+"          "\n\t"  \
                      "lpm %r0+7,%a1+"                  \
                      : "=r" (res), "+z" (addr))
#else /* Has no LPMx and no Reduced Tiny => Has LPM.  */
#define __LPM__1(res, addr)                             \
  __asm __volatile__ ("lpm $ mov %A0,r0"                \
                      : "=r" (res) : "z" (addr) : "r0")

#define __LPM__2(res, addr)                                     \
  __asm __volatile__ ("lpm $ mov %A0,r0 $ adiw %1,1"  "\n\t"    \
                      "lpm $ mov %B0,r0"                        \
                      : "=r" (res), "+z" (addr) :: "r0")

#define __LPM__3(res, addr)                                     \
  __asm __volatile__ ("lpm $ mov %A0,r0 $ adiw %1,1"  "\n\t"    \
                      "lpm $ mov %B0,r0 $ adiw %1,1"  "\n\t"    \
                      "lpm $ mov %C0,r0"                        \
                      : "=r" (res), "+z" (addr) :: "r0")

#define __LPM__4(res, addr)                                     \
  __asm __volatile__ ("lpm $ mov %A0,r0 $ adiw %1,1"  "\n\t"    \
                      "lpm $ mov %B0,r0 $ adiw %1,1"  "\n\t"    \
                      "lpm $ mov %C0,r0 $ adiw %1,1"  "\n\t"    \
                      "lpm $ mov %D0,r0"                        \
                      : "=r" (res), "+z" (addr) :: "r0")

#define __LPM__8(res, addr)                                     \
  __asm __volatile__ ("lpm $ mov %r0+0,r0 $ adiw %1,1"  "\n\t"  \
                      "lpm $ mov %r0+1,r0 $ adiw %1,1"  "\n\t"  \
                      "lpm $ mov %r0+2,r0 $ adiw %1,1"  "\n\t"  \
                      "lpm $ mov %r0+3,r0 $ adiw %1,1"  "\n\t"  \
                      "lpm $ mov %r0+4,r0 $ adiw %1,1"  "\n\t"  \
                      "lpm $ mov %r0+5,r0 $ adiw %1,1"  "\n\t"  \
                      "lpm $ mov %r0+6,r0 $ adiw %1,1"  "\n\t"  \
                      "lpm $ mov %r0+7,r0"                      \
                      : "=r" (res), "+z" (addr) :: "r0")
#endif /* LPM cases */

#define _Avrlibc_Def_Pgm_1(Name, Typ)           \
  static __ATTR_ALWAYS_INLINE__                 \
  Typ pgm_read_##Name (const Typ *__addr)       \
  {                                             \
    Typ __res;                                  \
    __LPM__1 (__res, __addr);                   \
    return __res;                               \
  }

#define _Avrlibc_Def_Pgm_2(Name, Typ)           \
  static __ATTR_ALWAYS_INLINE__                 \
  Typ pgm_read_##Name (const Typ *__addr)       \
  {                                             \
    Typ __res;                                  \
    __LPM__2 (__res, __addr);                   \
    return __res;                               \
  }

#define _Avrlibc_Def_Pgm_3(Name, Typ)           \
  static __ATTR_ALWAYS_INLINE__                 \
  Typ pgm_read_##Name (const Typ *__addr)       \
  {                                             \
    Typ __res;                                  \
    __LPM__3 (__res, __addr);                   \
    return __res;                               \
  }

#define _Avrlibc_Def_Pgm_4(Name, Typ)           \
  static __ATTR_ALWAYS_INLINE__                 \
  Typ pgm_read_##Name (const Typ *__addr)       \
  {                                             \
    Typ __res;                                  \
    __LPM__4 (__res, __addr);                   \
    return __res;                               \
  }

#define _Avrlibc_Def_Pgm_8(Name, Typ)           \
  static __ATTR_ALWAYS_INLINE__                 \
  Typ pgm_read_##Name (const Typ *__addr)       \
  {                                             \
    Typ __res;                                  \
    __LPM__8 (__res, __addr);                   \
    return __res;                               \
  }

_Avrlibc_Def_Pgm_1 (char, char)
_Avrlibc_Def_Pgm_1 (unsigned_char, unsigned char)
_Avrlibc_Def_Pgm_1 (signed_char, signed char)
_Avrlibc_Def_Pgm_1 (u8, uint8_t)
_Avrlibc_Def_Pgm_1 (i8, int8_t)
#if __SIZEOF_INT__ == 1
_Avrlibc_Def_Pgm_1 (int, int)
_Avrlibc_Def_Pgm_1 (signed, signed)
_Avrlibc_Def_Pgm_1 (unsigned, unsigned)
_Avrlibc_Def_Pgm_1 (signed_int, signed int)
_Avrlibc_Def_Pgm_1 (unsigned_int, unsigned int)
#endif
#if __SIZEOF_SHORT__ == 1
_Avrlibc_Def_Pgm_1 (short, short)
_Avrlibc_Def_Pgm_1 (unsigned_short, unsigned short)
#endif

_Avrlibc_Def_Pgm_2 (u16, uint16_t)
_Avrlibc_Def_Pgm_2 (i16, int16_t)
#if __SIZEOF_INT__ == 2
_Avrlibc_Def_Pgm_2 (int, int)
_Avrlibc_Def_Pgm_2 (signed, signed)
_Avrlibc_Def_Pgm_2 (unsigned, unsigned)
_Avrlibc_Def_Pgm_2 (signed_int, signed int)
_Avrlibc_Def_Pgm_2 (unsigned_int, unsigned int)
#endif
#if __SIZEOF_SHORT__ == 2
_Avrlibc_Def_Pgm_2 (short, short)
_Avrlibc_Def_Pgm_2 (unsigned_short, unsigned short)
#endif
#if __SIZEOF_LONG__ == 2
_Avrlibc_Def_Pgm_2 (long, long)
_Avrlibc_Def_Pgm_2 (unsigned_long, unsigned long)
#endif

#if defined(__INT24_MAX__)
_Avrlibc_Def_Pgm_3 (i24, __int24)
_Avrlibc_Def_Pgm_3 (u24, __uint24)
#endif /* Have __int24 */

_Avrlibc_Def_Pgm_4 (u32, uint32_t)
_Avrlibc_Def_Pgm_4 (i32, int32_t)
_Avrlibc_Def_Pgm_4 (float, float)
#if __SIZEOF_LONG__ == 4
_Avrlibc_Def_Pgm_4 (long, long)
_Avrlibc_Def_Pgm_4 (unsigned_long, unsigned long)
#endif
#if __SIZEOF_LONG_LONG__ == 4
_Avrlibc_Def_Pgm_4 (long_long, long long)
_Avrlibc_Def_Pgm_4 (unsigned_long_long, unsigned long long)
#endif
#if __SIZEOF_DOUBLE__ == 4
_Avrlibc_Def_Pgm_4 (double, double)
#endif
#if __SIZEOF_LONG_DOUBLE__ == 4
_Avrlibc_Def_Pgm_4 (long_double, long double)
#endif

#if __SIZEOF_LONG_LONG__ == 8
_Avrlibc_Def_Pgm_8 (u64, uint64_t)
_Avrlibc_Def_Pgm_8 (i64, int64_t)
_Avrlibc_Def_Pgm_8 (long_long, long long)
_Avrlibc_Def_Pgm_8 (unsigned_long_long, unsigned long long)
#endif
#if __SIZEOF_DOUBLE__ == 8
_Avrlibc_Def_Pgm_8 (double, double)
#endif
#if __SIZEOF_LONG_DOUBLE__ == 8
_Avrlibc_Def_Pgm_8 (long_double, long double)
#endif

#endif /* DOXYGEN */

#ifdef __DOXYGEN__

/** \ingroup avr_pgmspace
    \fn char pgm_read_char_far (uint_farptr_t __addr)
    Read a <tt>char</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline char pgm_read_char_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn unsigned char pgm_read_unsigned_char_far (uint_farptr_t __addr)
    Read an <tt>unsigned char</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline unsigned char pgm_read_unsigned_char_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn signed char pgm_read_signed_char_far (uint_farptr_t __addr)
    Read a <tt>signed char</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline signed char pgm_read_signed_char_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn uint8_t pgm_read_u8_far (uint_farptr_t __addr)
    Read an <tt>uint8_t</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline uint8_t pgm_read_u8_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn int8_t pgm_read_i8_far (uint_farptr_t __addr)
    Read an <tt>int8_t</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline int8_t pgm_read_i8_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn short pgm_read_short_far (uint_farptr_t __addr)
    Read a <tt>short</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline short pgm_read_short_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn unsigned short pgm_read_unsigned_short_far (uint_farptr_t __addr)
    Read an <tt>unsigned short</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline unsigned short pgm_read_unsigned_short_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn uint16_t pgm_read_u16_far (uint_farptr_t __addr)
    Read an <tt>uint16_t</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline uint16_t pgm_read_u16_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn int16_t pgm_read_i16_far (uint_farptr_t __addr)
    Read an <tt>int16_t</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline int16_t pgm_read_i16_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn int pgm_read_int_far (uint_farptr_t __addr)
    Read an <tt>int</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline int pgm_read_int_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn unsigned pgm_read_unsigned_far (uint_farptr_t __addr)
    Read an <tt>unsigned</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline unsigned pgm_read_unsigned_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn unsigned int pgm_read_unsigned_int_far (uint_farptr_t __addr)
    Read an <tt>unsigned int</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline unsigned int pgm_read_unsigned_int_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn signed pgm_read_signed_far (uint_farptr_t __addr)
    Read a <tt>signed</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline signed pgm_read_signed_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn signed int pgm_read_signed_int_far (uint_farptr_t __addr)
    Read a <tt>signed int</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline signed int pgm_read_signed_int_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn long pgm_read_long_far (uint_farptr_t __addr)
    Read a <tt>long</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline long pgm_read_long_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn unsigned long pgm_read_unsigned_long_far (uint_farptr_t __addr)
    Read an <tt>unsigned long</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline unsigned long pgm_read_unsigned_long_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn __int24 pgm_read_i24_far (uint_farptr_t __addr)
    Read an <tt>__int24</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline __int24 pgm_read_i24_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn __uint24 pgm_read_u24_far (uint_farptr_t __addr)
    Read an <tt>__uint24</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline __uint24 pgm_read_u24_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn uint32_t pgm_read_u32_far (uint_farptr_t __addr)
    Read an <tt>uint32_t</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline uint32_t pgm_read_u32_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn int32_t pgm_read_i32_far (uint_farptr_t __addr)
    Read an <tt>int32_t</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline int32_t pgm_read_i32_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn long long pgm_read_long_long_far (uint_farptr_t __addr)
    Read a <tt>long long</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline long long pgm_read_long_long_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn unsigned long long pgm_read_unsigned_long_long_far (uint_farptr_t __addr)
    Read an <tt>unsigned long long</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline unsigned long long pgm_read_unsigned_long_long_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn uint64_t pgm_read_u64_far (uint_farptr_t __addr)
    Read an <tt>uint64_t</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline uint64_t pgm_read_u64_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn int64_t pgm_read_i64_far (uint_farptr_t __addr)
    Read an <tt>int64_t</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline int64_t pgm_read_i64_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn float pgm_read_float_far (uint_farptr_t __addr)
    Read a <tt>float</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline float pgm_read_float_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn double pgm_read_double_far (uint_farptr_t __addr)
    Read a <tt>double</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline double pgm_read_double_far (uint_farptr_t __addr);

/** \ingroup avr_pgmspace
    \fn long double pgm_read_long_double_far (uint_farptr_t __addr)
    Read a <tt>long double</tt> from far byte-address \p __addr.
    The address is in the program memory. */
static inline long double pgm_read_long_double_far (uint_farptr_t __addr);

#else /* !DOXYGEN */

#if defined(__AVR_HAVE_ELPMX__)

#ifdef __AVR_HAVE_RAMPD__
/* For devices with EBI, reset RAMPZ to zero after.  */
#define __pgm_clr_RAMPZ_ "\n\t" "out  %i2,__zero_reg__"
#else
/* Devices without EBI: no need to reset RAMPZ.  */
#define __pgm_clr_RAMPZ_ /* empty */
#endif

#define __ELPM__1(res, addr, T)                         \
  __asm __volatile__ ("movw r30,%1"         "\n\t"      \
                      "out  %i2,%C1"        "\n\t"      \
                      "elpm %A0,Z"                      \
                      __pgm_clr_RAMPZ_                  \
                      : "=r" (res)                      \
                      : "r" (addr), "n" (& RAMPZ)       \
                      : "r30", "r31")

#define __ELPM__2(res, addr, T)                         \
  __asm __volatile__ ("movw r30,%1"         "\n\t"      \
                      "out  %i2,%C1"        "\n\t"      \
                      "elpm %A0,Z+"         "\n\t"      \
                      "elpm %B0,Z+"                     \
                      __pgm_clr_RAMPZ_                  \
                      : "=r" (res)                      \
                      : "r" (addr), "n" (& RAMPZ)       \
                      : "r30", "r31")

#define __ELPM__3(res, addr, T)                         \
  __asm __volatile__ ("movw r30,%1"         "\n\t"      \
                      "out  %i2,%C1"        "\n\t"      \
                      "elpm %A0,Z+"         "\n\t"      \
                      "elpm %B0,Z+"         "\n\t"      \
                      "elpm %C0,Z+"                     \
                      __pgm_clr_RAMPZ_                  \
                      : "=r" (res)                      \
                      : "r" (addr), "n" (& RAMPZ)       \
                      : "r30", "r31")

#define __ELPM__4(res, addr, T)                         \
  __asm __volatile__ ("movw r30,%1"         "\n\t"      \
                      "out  %i2,%C1"        "\n\t"      \
                      "elpm %A0,Z+"         "\n\t"      \
                      "elpm %B0,Z+"         "\n\t"      \
                      "elpm %C0,Z+"         "\n\t"      \
                      "elpm %D0,Z+"                     \
                      __pgm_clr_RAMPZ_                  \
                      : "=r" (res)                      \
                      : "r" (addr), "n" (& RAMPZ)       \
                      : "r30", "r31")

#define __ELPM__8(res, addr, T)                         \
  __asm __volatile__ ("movw r30,%1"         "\n\t"      \
                      "out  %i2,%C1"        "\n\t"      \
                      "elpm %r0+0,Z+"       "\n\t"      \
                      "elpm %r0+1,Z+"       "\n\t"      \
                      "elpm %r0+2,Z+"       "\n\t"      \
                      "elpm %r0+3,Z+"       "\n\t"      \
                      "elpm %r0+4,Z+"       "\n\t"      \
                      "elpm %r0+5,Z+"       "\n\t"      \
                      "elpm %r0+6,Z+"       "\n\t"      \
                      "elpm %r0+7,Z+"                   \
                      __pgm_clr_RAMPZ_                  \
                      : "=r" (res)                      \
                      : "r" (addr), "n" (& RAMPZ)       \
                      : "r30", "r31")

/* FIXME: AT43USB320 does not have RAMPZ but supports (external) program
   memory of 64 KiW, at least that's what the comments in io43usb32x.h are
   indicating.  A solution would be to put the device in a different
   multilib-set (see GCC PR78275), as io.h has  "#define FLASHEND 0x0FFFF".
   For now, just exclude AT43USB320 from code that uses RAMPZ. Also note
   that the manual asserts that the entire program memory can be accessed
   by LPM, implying only 64 KiB of program memory.  */
#elif defined(__AVR_HAVE_ELPM__) \
      && !defined(__AVR_AT43USB320__)
/* The poor devices without ELPMx: Do 24-bit addresses by hand... */
#define __ELPM__1(res, addr, T)                                         \
  __asm __volatile__ ("mov r30,%A1"    "\n\t"                           \
                      "mov r31,%B1"    "\n\t"                           \
                      "out %i2,%C1 $ elpm $ mov %A0,r0"                 \
                      : "=r" (res)                                      \
                      : "r" (addr), "n" (& RAMPZ)                       \
                      : "r30", "r31", "r0")

#define __ELPM__2(res, addr, T)                                         \
  __asm __volatile__                                                    \
  ("mov r30,%A1"    "\n\t"                                              \
   "mov r31,%B1"    "\n\t"                                              \
   "mov %B0,%C1"    "\n\t"                                              \
   "out %i2,%B0 $ elpm $ mov %A0,r0 $ adiw r30,1 $ adc %B0,r1" "\n\t"   \
   "out %i2,%B0 $ elpm $ mov %B0,r0"                                    \
   : "=r" (res)                                                         \
   : "r" (addr), "n" (& RAMPZ)                                          \
   : "r30", "r31", "r0")

#define __ELPM__3(res, addr, T)                                         \
  __asm __volatile__                                                    \
  ("mov r30,%A1"    "\n\t"                                              \
   "mov r31,%B1"    "\n\t"                                              \
   "mov %C0,%C1"    "\n\t"                                              \
   "out %i2,%C0 $ elpm $ mov %A0,r0 $ adiw r30,1 $ adc %C0,r1" "\n\t"   \
   "out %i2,%C0 $ elpm $ mov %B0,r0 $ adiw r30,1 $ adc %C0,r1" "\n\t"   \
   "out %i2,%C0 $ elpm $ mov %C0,r0"                                    \
   : "=r" (res)                                                         \
   : "r" (addr), "n" (& RAMPZ)                                          \
   : "r30", "r31", "r0")

#define __ELPM__4(res, addr, T)                                         \
  __asm __volatile__                                                    \
  ("mov r30,%A1"    "\n\t"                                              \
   "mov r31,%B1"    "\n\t"                                              \
   "mov %D0,%C1"    "\n\t"                                              \
   "out %i2,%D0 $ elpm $ mov %A0,r0 $ adiw r30,1 $ adc %D0,r1" "\n\t"   \
   "out %i2,%D0 $ elpm $ mov %B0,r0 $ adiw r30,1 $ adc %D0,r1" "\n\t"   \
   "out %i2,%D0 $ elpm $ mov %C0,r0 $ adiw r30,1 $ adc %D0,r1" "\n\t"   \
   "out %i2,%D0 $ elpm $ mov %D0,r0"                                    \
   : "=r" (res)                                                         \
   : "r" (addr), "n" (& RAMPZ)                                          \
   : "r30", "r31", "r0")

#define __ELPM__8(res, addr, T)                                         \
  __asm __volatile__                                                    \
  ("mov r30,%A1"    "\n\t"                                              \
   "mov r31,%B1"    "\n\t"                                              \
   "mov %r0+7,%C1"  "\n\t"                                              \
   "out %i2,%r0+7 $ elpm $ mov %r0+0,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+1,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+2,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+3,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+4,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+5,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+6,r0 $ adiw r30,1 $ adc %r0+7,r1" "\n\t" \
   "out %i2,%r0+7 $ elpm $ mov %r0+7,r0"                                \
   : "=r" (res)                                                         \
   : "r" (addr), "n" (& RAMPZ)                                          \
   : "r30", "r31", "r0")
#else
/* No ELPM: Fall back to __LPM__<N>.  */
#define __ELPM__1(r,a,T) const T *__a = (const T*)(uint16_t) a; __LPM__1(r,__a)
#define __ELPM__2(r,a,T) const T *__a = (const T*)(uint16_t) a; __LPM__2(r,__a)
#define __ELPM__3(r,a,T) const T *__a = (const T*)(uint16_t) a; __LPM__3(r,__a)
#define __ELPM__4(r,a,T) const T *__a = (const T*)(uint16_t) a; __LPM__4(r,__a)
#define __ELPM__8(r,a,T) const T *__a = (const T*)(uint16_t) a; __LPM__8(r,__a)
#endif /* ELPM cases */

#define _Avrlibc_Def_Pgm_Far_1(Name, Typ)          \
  static __ATTR_ALWAYS_INLINE__                    \
  Typ pgm_read_##Name##_far (uint_farptr_t __addr) \
  {                                                \
    Typ __res;                                     \
    __ELPM__1 (__res, __addr, Typ);                \
    return __res;                                  \
  }

#define _Avrlibc_Def_Pgm_Far_2(Name, Typ)          \
  static __ATTR_ALWAYS_INLINE__                    \
  Typ pgm_read_##Name##_far (uint_farptr_t __addr) \
  {                                                \
    Typ __res;                                     \
    __ELPM__2 (__res, __addr, Typ);                \
    return __res;                                  \
  }

#define _Avrlibc_Def_Pgm_Far_3(Name, Typ)          \
  static __ATTR_ALWAYS_INLINE__                    \
  Typ pgm_read_##Name##_far (uint_farptr_t __addr) \
  {                                                \
    Typ __res;                                     \
    __ELPM__3 (__res, __addr, Typ);                \
    return __res;                                  \
  }

#define _Avrlibc_Def_Pgm_Far_4(Name, Typ)          \
  static __ATTR_ALWAYS_INLINE__                    \
  Typ pgm_read_##Name##_far (uint_farptr_t __addr) \
  {                                                \
    Typ __res;                                     \
    __ELPM__4 (__res, __addr, Typ);                \
    return __res;                                  \
  }

#define _Avrlibc_Def_Pgm_Far_8(Name, Typ)          \
  static __ATTR_ALWAYS_INLINE__                    \
  Typ pgm_read_##Name##_far (uint_farptr_t __addr) \
  {                                                \
    Typ __res;                                     \
    __ELPM__8 (__res, __addr, Typ);                \
    return __res;                                  \
  }

_Avrlibc_Def_Pgm_Far_1 (char, char)
_Avrlibc_Def_Pgm_Far_1 (unsigned_char, unsigned char)
_Avrlibc_Def_Pgm_Far_1 (signed_char, signed char)
_Avrlibc_Def_Pgm_Far_1 (u8, uint8_t)
_Avrlibc_Def_Pgm_Far_1 (i8, int8_t)
#if __SIZEOF_INT__ == 1
_Avrlibc_Def_Pgm_Far_1 (int, int)
_Avrlibc_Def_Pgm_Far_1 (unsigned, unsigned)
_Avrlibc_Def_Pgm_Far_1 (unsigned_int, unsigned int)
_Avrlibc_Def_Pgm_Far_1 (signed, signed)
_Avrlibc_Def_Pgm_Far_1 (signed_int, signed int)
#endif
#if __SIZEOF_SHORT__ == 1
_Avrlibc_Def_Pgm_Far_1 (short, short)
_Avrlibc_Def_Pgm_Far_1 (unsigned_short, unsigned short)
#endif

_Avrlibc_Def_Pgm_Far_2 (u16, uint16_t)
_Avrlibc_Def_Pgm_Far_2 (i16, int16_t)
#if __SIZEOF_INT__ == 2
_Avrlibc_Def_Pgm_Far_2 (int, int)
_Avrlibc_Def_Pgm_Far_2 (unsigned, unsigned)
_Avrlibc_Def_Pgm_Far_2 (unsigned_int, unsigned int)
_Avrlibc_Def_Pgm_Far_2 (signed, signed)
_Avrlibc_Def_Pgm_Far_2 (signed_int, signed int)
#endif
#if __SIZEOF_SHORT__ == 2
_Avrlibc_Def_Pgm_Far_2 (short, short)
_Avrlibc_Def_Pgm_Far_2 (unsigned_short, unsigned short)
#endif
#if __SIZEOF_LONG__ == 2
_Avrlibc_Def_Pgm_Far_2 (long, long)
_Avrlibc_Def_Pgm_Far_2 (unsigned_long, unsigned long)
#endif

#if defined(__INT24_MAX__)
_Avrlibc_Def_Pgm_Far_3 (i24, __int24)
_Avrlibc_Def_Pgm_Far_3 (u24, __uint24)
#endif /* Have __int24 */

_Avrlibc_Def_Pgm_Far_4 (u32, uint32_t)
_Avrlibc_Def_Pgm_Far_4 (i32, int32_t)
_Avrlibc_Def_Pgm_Far_4 (float, float)
#if __SIZEOF_LONG__ == 4
_Avrlibc_Def_Pgm_Far_4 (long, long)
_Avrlibc_Def_Pgm_Far_4 (unsigned_long, unsigned long)
#endif
#if __SIZEOF_LONG_LONG__ == 4
_Avrlibc_Def_Pgm_Far_4 (long_long, long long)
_Avrlibc_Def_Pgm_Far_4 (unsigned_long_long, unsigned long long)
#endif
#if __SIZEOF_DOUBLE__ == 4
_Avrlibc_Def_Pgm_Far_4 (double, double)
#endif
#if __SIZEOF_LONG_DOUBLE__ == 4
_Avrlibc_Def_Pgm_Far_4 (long_double, long double)
#endif

#if __SIZEOF_LONG_LONG__ == 8
_Avrlibc_Def_Pgm_Far_8 (u64, uint64_t)
_Avrlibc_Def_Pgm_Far_8 (i64, int64_t)
_Avrlibc_Def_Pgm_Far_8 (long_long, long long)
_Avrlibc_Def_Pgm_Far_8 (unsigned_long_long, unsigned long long)
#endif
#if __SIZEOF_DOUBLE__ == 8
_Avrlibc_Def_Pgm_Far_8 (double, double)
#endif
#if __SIZEOF_LONG_DOUBLE__ == 8
_Avrlibc_Def_Pgm_Far_8 (long_double, long double)
#endif

#endif /* DOXYGEN */

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__DOXYGEN__)
/* No documentation for the deprecated stuff.  */
#elif defined(__PROG_TYPES_COMPAT__)  /* !DOXYGEN */

typedef void prog_void __attribute__((__progmem__,__deprecated__("prog_void type is deprecated.")));
typedef char prog_char __attribute__((__progmem__,__deprecated__("prog_char type is deprecated.")));
typedef unsigned char prog_uchar __attribute__((__progmem__,__deprecated__("prog_uchar type is deprecated.")));
typedef int8_t    prog_int8_t   __attribute__((__progmem__,__deprecated__("prog_int8_t type is deprecated.")));
typedef uint8_t   prog_uint8_t  __attribute__((__progmem__,__deprecated__("prog_uint8_t type is deprecated.")));
typedef int16_t   prog_int16_t  __attribute__((__progmem__,__deprecated__("prog_int16_t type is deprecated.")));
typedef uint16_t  prog_uint16_t __attribute__((__progmem__,__deprecated__("prog_uint16_t type is deprecated.")));
typedef int32_t   prog_int32_t  __attribute__((__progmem__,__deprecated__("prog_int32_t type is deprecated.")));
typedef uint32_t  prog_uint32_t __attribute__((__progmem__,__deprecated__("prog_uint32_t type is deprecated.")));
#if !__USING_MINT8
typedef int64_t   prog_int64_t  __attribute__((__progmem__,__deprecated__("prog_int64_t type is deprecated.")));
typedef uint64_t  prog_uint64_t __attribute__((__progmem__,__deprecated__("prog_uint64_t type is deprecated.")));
#endif

#ifndef PGM_P
#define PGM_P const prog_char *
#endif

#ifndef PGM_VOID_P
#define PGM_VOID_P const prog_void *
#endif

#else /* !defined(__DOXYGEN__), !defined(__PROG_TYPES_COMPAT__) */

#ifndef PGM_P
#define PGM_P const char *
#endif

#ifndef PGM_VOID_P
#define PGM_VOID_P const void *
#endif
#endif /* defined(__DOXYGEN__), defined(__PROG_TYPES_COMPAT__) */

/* Although in C, we can get away with just using __c, it does not work in
   C++. We need to use &__c[0] to avoid the compiler puking. Dave Hylands
   explaned it thusly,

     Let's suppose that we use PSTR("Test"). In this case, the type returned
     by __c is a prog_char[5] and not a prog_char *. While these are
     compatible, they aren't the same thing (especially in C++). The type
     returned by &__c[0] is a prog_char *, which explains why it works
     fine. */

#if defined(__DOXYGEN__)
/*
 * The #define below is just a dummy that serves documentation
 * purposes only.
 */
/** \ingroup avr_pgmspace
    \def PSTR(str)

    Used to declare a static pointer to a string in program space. */
# define PSTR(str) ({ static const PROGMEM char c[] = (str); &c[0]; })
#else  /* !DOXYGEN */
/* The real thing. */
# define PSTR(s) (__extension__({static const char __c[] PROGMEM = (s); &__c[0];}))
#endif /* DOXYGEN */

#if defined(__DOXYGEN__)
/** \ingroup avr_pgmspace
    \def PSTR_FAR(str)

    Used to define a string literal in far program space, and to return its
    address of type #uint_farptr_t. */
# define PSTR_FAR(str) ({ static const PROGMEM_FAR char c[] = (str); pgm_get_far_address(c[0]); })
#else  /* !DOXYGEN */
/* The real thing. */
# define PSTR_FAR(s) (__extension__({static const char __c[] PROGMEM_FAR = (s); pgm_get_far_address(__c[0]);}))
#endif /* DOXYGEN */

#ifndef __DOXYGEN__

/* These are used down the line for pgm_read_byte[_near] etc. */

#if defined (__AVR_TINY__)
/* Attribute __progmem__ on Reduced Tiny works different than for
   all the other devices:  When taking the address of a symbol that's
   attributed as progmem, then the compiler adds an offset of 0x4000
   to the value of the symbol.  This means that accessing data in
   progmem can be performed by vanilla C/C++ code.  This requires
   - GCC PR71948 - Make progmem work on Reduced Tiny (GCC v7 / 2016-08)  */
#define __LPM(addr)         (* (const uint8_t*)(addr))
#define __LPM_word(addr)    (* (const uint16_t*)(addr))
#define __LPM_dword(addr)   (* (const uint32_t*)(addr))
#  if __SIZEOF_LONG_LONG__ == 8
#  define __LPM_qword(addr)   (* (const uint64_t*)(addr))
#  endif
#else
#define __LPM(addr)                             \
  (__extension__({                              \
      uint16_t __addr16 = (uint16_t) (addr);    \
      uint8_t __result;                         \
      __LPM__1 (__result, __addr16);            \
      __result;                                 \
}))

#define __LPM_word(addr)                        \
  (__extension__({                              \
      uint16_t __addr16 = (uint16_t) (addr);    \
      uint16_t __result;                        \
      __LPM__2 (__result, __addr16);            \
      __result;                                 \
}))

#define __LPM_dword(addr)                       \
  (__extension__({                              \
      uint16_t __addr16 = (uint16_t) (addr);    \
      uint32_t __result;                        \
      __LPM__4 (__result, __addr16);            \
      __result;                                 \
}))

#if __SIZEOF_LONG_LONG__ == 8
#define __LPM_qword(addr)                       \
  (__extension__({                              \
      uint16_t __addr16 = (uint16_t) (addr);    \
      uint64_t __result;                        \
      __LPM__8 (__result, __addr16);            \
      __result;                                 \
}))
#endif
#endif /* AVR_TINY */


#define __ELPM(addr)                                    \
  (__extension__({                                      \
      uint_farptr_t __addr32 = (addr);                  \
      uint8_t __result;                                 \
      __ELPM__1 (__result, __addr32, uint8_t);          \
      __result;                                         \
}))

#define __ELPM_word(addr)                               \
  (__extension__({                                      \
      uint_farptr_t __addr32 = (addr);                  \
      uint16_t __result;                                \
      __ELPM__2 (__result, __addr32, uint16_t);         \
      __result;                                         \
}))

#define __ELPM_dword(addr)                              \
  (__extension__({                                      \
      uint_farptr_t __addr32 = (addr);                  \
      uint32_t __result;                                \
      __ELPM__4 (__result, __addr32, uint32_t);         \
      __result;                                         \
}))

#if __SIZEOF_LONG_LONG__ == 8
#define __ELPM_qword(addr)                              \
  (__extension__({                                      \
      uint_farptr_t __addr32 = (addr);                  \
      uint64_t __result;                                \
      __ELPM__8 (__result, __addr32, uint64_t);         \
      __result;                                         \
}))
#endif

#endif  /* !__DOXYGEN__ */

/** \ingroup avr_pgmspace
    \def pgm_read_byte_near(__addr)
    Read a byte from the program space with a 16-bit (near) byte-address. */

#define pgm_read_byte_near(__addr) __LPM ((uint16_t)(__addr))

/** \ingroup avr_pgmspace
    \def pgm_read_word_near(__addr)
    Read a word from the program space with a 16-bit (near) byte-address. */

#define pgm_read_word_near(__addr) __LPM_word ((uint16_t)(__addr))

/** \ingroup avr_pgmspace
    \def pgm_read_dword_near(__addr)
    Read a double word from the program space with a 16-bit (near)
    byte-address.  */

#define pgm_read_dword_near(__addr) \
    __LPM_dword ((uint16_t)(__addr))

/** \ingroup avr_pgmspace
    \def pgm_read_qword_near(__addr)
    Read a quad-word from the program space with a 16-bit (near)
    byte-address.  */

#define pgm_read_qword_near(__addr) __LPM_qword ((uint16_t)(__addr))

/** \ingroup avr_pgmspace
    \def pgm_read_float_near (const float *address)
    Read a \c float from the program space with a 16-bit (near) byte-address.*/

#define pgm_read_float_near(addr)  pgm_read_float (addr)

/** \ingroup avr_pgmspace
    \def pgm_read_ptr_near(__addr)
    Read a pointer from the program space with a 16-bit (near) byte-address. */

#define pgm_read_ptr_near(__addr) \
    ((void*) __LPM_word ((uint16_t)(__addr)))

/** \ingroup avr_pgmspace
    \def pgm_read_byte_far(__addr)
    Read a byte from the program space with a 32-bit (far) byte-address. */

#define pgm_read_byte_far(__addr)  __ELPM (__addr)

/** \ingroup avr_pgmspace
    \def pgm_read_word_far(__addr)
    Read a word from the program space with a 32-bit (far) byte-address. */

#define pgm_read_word_far(__addr)  __ELPM_word (__addr)

/** \ingroup avr_pgmspace
    \def pgm_read_dword_far(__addr)
    Read a double word from the program space with a 32-bit (far)
    byte-address. */

#define pgm_read_dword_far(__addr) __ELPM_dword (__addr)

/** \ingroup avr_pgmspace
    \def pgm_read_qword_far(__addr)
    Read a quad-word from the program space with a 32-bit (far)
    byte-address. */

#define pgm_read_qword_far(__addr) __ELPM_qword (__addr)

/** \ingroup avr_pgmspace
    \def pgm_read_ptr_far(__addr)
    Read a pointer from the program space with a 32-bit (far) byte-address. */

#define pgm_read_ptr_far(__addr) ((void*) __ELPM_word (__addr))

/** \ingroup avr_pgmspace
    \def pgm_read_byte(__addr)
    Read a byte from the program space with a 16-bit (near) nyte-address. */

#define pgm_read_byte(__addr)    pgm_read_byte_near(__addr)

/** \ingroup avr_pgmspace
    \def pgm_read_word(__addr)
    Read a word from the program space with a 16-bit (near) byte-address. */

#define pgm_read_word(__addr)    pgm_read_word_near(__addr)

/** \ingroup avr_pgmspace
    \def pgm_read_dword(__addr)
    Read a double word from the program space with a 16-bit (near)
    byte-address. */

#define pgm_read_dword(__addr)   pgm_read_dword_near(__addr)

/** \ingroup avr_pgmspace
    \def pgm_read_qword(__addr)
    Read a quad-word from the program space with a 16-bit (near)
    byte-address. */

#define pgm_read_qword(__addr)   pgm_read_qword_near(__addr)

/** \ingroup avr_pgmspace
    \def pgm_read_ptr(__addr)
    Read a pointer from the program space with a 16-bit (near) byte-address. */

#define pgm_read_ptr(__addr)     pgm_read_ptr_near(__addr)

/** \ingroup avr_pgmspace
    \def pgm_get_far_address(var)

   This macro evaluates to a ::uint_farptr_t 32-bit "far" pointer (only
   24 bits used) to data even beyond the 64 KiB limit for the 16-bit ordinary
   pointer.  It is similar to the '&' operator, with some limitations.
   Example:
   \code
   #include <avr/pgmspace.h>

   // Section .progmemx.data is located after all the code sections.
   PROGMEM_FAR
   const int data[] = { 2, 3, 5, 7, 9, 11 };

   int get_data (uint8_t idx)
   {
       uint_farptr_t pdata = pgm_get_far_address (data[0]);
       return pgm_read_int_far (pdata + idx * sizeof(int));
   }
   \endcode

   Comments:

   - The overhead is minimal and it's mainly due to the 32-bit size operation.

   - 24 bit sizes guarantees the code compatibility for use in future devices.

   - \p var has to be resolved at link-time as an existing symbol,
     i.e. a simple variable name, an array name, or an array or structure
     element provided the offset is known at compile-time, and \p var is
     located in static storage, etc.
*/
#ifdef __DOXYGEN__
#define pgm_get_far_address(var)
#else
#ifndef __AVR_TINY__
#define pgm_get_far_address(var)                      \
(__extension__({                                      \
    uint_farptr_t __tmp;                              \
                                                      \
    __asm__ __volatile__ (                            \
        "ldi    %A0, lo8(%1)"           "\n\t"        \
        "ldi    %B0, hi8(%1)"           "\n\t"        \
        "ldi    %C0, hh8(%1)"           "\n\t"        \
        "clr    %D0"                                  \
        :   "=d" (__tmp)                              \
        :   "i"  (&(var))                             \
    );                                                \
    __tmp;                                            \
}))
#else
/* The working of the pgm_read_far() functions and macros is such
   that they decay to pgm_read() for devices without ELPM.
   Since GCC v7 PR71948, the compiler adds an offset of 0x4000 on
   Reduced Tiny when it takes the address of an object in PROGMEM,
   which means we have to add 0x4000 here, too.  */
#define pgm_get_far_address(var)                      \
(__extension__({                                      \
    uint_farptr_t __tmp;                              \
                                                      \
    __asm__ __volatile__ (                            \
        "ldi    %A0, lo8(0x4000+(%1))"  "\n\t"        \
        "ldi    %B0, hi8(0x4000+(%1))"  "\n\t"        \
        "ldi    %C0, hh8(0x4000+(%1))"  "\n\t"        \
        "clr    %D0"                                  \
        :   "=d" (__tmp)                              \
        :   "i"  (&(var))                             \
    );                                                \
    __tmp;                                            \
}))
#endif /* AVR TINY */
#endif /* DOXYGEN */


/** \ingroup avr_pgmspace
    \fn const void * memchr_P(const void *s, int val, size_t len)
    \brief Scan flash memory for a character.

    The memchr_P() function scans the first \p len bytes of the flash
    memory area pointed to by \p s for the character \p val.  The first
    byte to match \p val (interpreted as an unsigned character) stops
    the operation.

    \return The memchr_P() function returns a pointer to the matching
    byte or \c NULL if the character does not occur in the given memory
    area.	*/
extern const void * memchr_P(const void *, int __val, size_t __len) __ATTR_CONST__;

/** \ingroup avr_pgmspace
    \fn int memcmp_P(const void *s1, const void *s2, size_t len)
    \brief Compare memory areas

    The memcmp_P() function compares the first \p len bytes of the memory
    areas \p s1 and flash \p s2. The comparision is performed using unsigned
    char operations.

    \returns The memcmp_P() function returns an integer less than, equal
    to, or greater than zero if the first \p len bytes of \p s1 is found,
    respectively, to be less than, to match, or be greater than the first
    \p len bytes of \p s2.	*/
extern int memcmp_P(const void *, const void *, size_t) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn void *memccpy_P (void *dest, const void *src, int val, size_t len)

    This function is similar to memccpy() except that \p src is pointer
    to a string in program space.	*/
extern void *memccpy_P(void *, const void *, int __val, size_t);

/** \ingroup avr_pgmspace
    \fn void *memcpy_P(void *dest, const void *src, size_t n)

    The memcpy_P() function is similar to memcpy(), except the src string
    resides in program space.

    \returns The memcpy_P() function returns a pointer to dest.  */
extern void *memcpy_P(void *, const void *, size_t);

/** \ingroup avr_pgmspace
    \fn void *memmem_P(const void *s1, size_t len1, const void *s2, size_t len2)

    The memmem_P() function is similar to memmem() except that \p s2 is
    pointer to a string in program space.	*/
extern void *memmem_P(const void *, size_t, const void *, size_t) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn const void +memrchr_P(const void *src, int val, size_t len)

    The memrchr_P() function is like the memchr_P() function, except
    that it searches backwards from the end of the \p len bytes pointed
    to by \p src instead of forwards from the front. (Glibc, GNU extension.)

    \return The memrchr_P() function returns a pointer to the matching
    byte or \c NULL if the character does not occur in the given memory
    area.	*/
extern const void * memrchr_P(const void *, int __val, size_t __len) __ATTR_CONST__;

/** \ingroup avr_pgmspace
    \fn char *strcat_P(char *dest, const char *src)

    The strcat_P() function is similar to strcat() except that the \e src
    string must be located in program space (flash).

    \returns The strcat() function returns a pointer to the resulting string
    \e dest. */
extern char *strcat_P(char *, const char *);

/** \ingroup avr_pgmspace
    \fn const char *strchr_P(const char *s, int val)
    \brief Locate character in program space string.

    The strchr_P() function locates the first occurrence of \p val
    (converted to a char) in the string pointed to by \p s in program
    space. The terminating null character is considered to be part of
    the string.

    The strchr_P() function is similar to strchr() except that \p s is
    pointer to a string in program space.

    \returns The strchr_P() function returns a pointer to the matched
    character or \c NULL if the character is not found. */
extern const char * strchr_P(const char *, int __val) __ATTR_CONST__;

/** \ingroup avr_pgmspace
    \fn const char *strchrnul_P(const char *s, int c)

    The strchrnul_P() function is like strchr_P() except that if \p c is
    not found in \p s, then it returns a pointer to the null byte at the
    end of \p s, rather than \c NULL. (Glibc, GNU extension.)

    \return The strchrnul_P() function returns a pointer to the matched
    character, or a pointer to the null byte at the end of \p s (i.e.,
    \c s+strlen(s)) if the character is not found.	*/
extern const char * strchrnul_P(const char *, int __val) __ATTR_CONST__;

/** \ingroup avr_pgmspace
    \fn int strcmp_P(const char *s1, const char *s2)

    The strcmp_P() function is similar to strcmp() except that \p s2 is
    pointer to a string in program space.

    \returns The strcmp_P() function returns an integer less than, equal
    to, or greater than zero if \p s1 is found, respectively, to be less
    than, to match, or be greater than \p s2. A consequence of the
    ordering used by strcmp_P() is that if \p s1 is an initial substring
    of \p s2, then \p s1 is considered to be "less than" \p s2. */
extern int strcmp_P(const char *, const char *) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn char *strcpy_P(char *dest, const char *src)

    The strcpy_P() function is similar to strcpy() except that src is a
    pointer to a string in program space.

    \returns The strcpy_P() function returns a pointer to the destination
    string dest. */
extern char *strcpy_P(char *, const char *);

/** \ingroup avr_pgmspace
    \fn int strcasecmp_P(const char *s1, const char *s2)
    \brief Compare two strings ignoring case.

    The strcasecmp_P() function compares the two strings \p s1 and \p s2,
    ignoring the case of the characters.

    \param s1 A pointer to a string in the devices SRAM.
    \param s2 A pointer to a string in the devices Flash.

    \returns The strcasecmp_P() function returns an integer less than,
    equal to, or greater than zero if \p s1 is found, respectively, to
    be less than, to match, or be greater than \p s2. A consequence of
    the ordering used by strcasecmp_P() is that if \p s1 is an initial
    substring of \p s2, then \p s1 is considered to be "less than" \p s2. */
extern int strcasecmp_P(const char *, const char *) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn char *strcasestr_P(const char *s1, const char *s2)

    This funtion is similar to strcasestr() except that \p s2 is pointer
    to a string in program space.	*/
extern char *strcasestr_P(const char *, const char *) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn size_t strcspn_P(const char *s, const char *reject)

    The strcspn_P() function calculates the length of the initial segment
    of \p s which consists entirely of characters not in \p reject. This
    function is similar to strcspn() except that \p reject is a pointer
    to a string in program space.

    \return The strcspn_P() function returns the number of characters in
    the initial segment of \p s which are not in the string \p reject.
    The terminating zero is not considered as a part of string.	*/
extern size_t strcspn_P(const char *__s, const char * __reject) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn size_t strlcat_P(char *dst, const char *src, size_t siz)
    \brief Concatenate two strings.

    The strlcat_P() function is similar to strlcat(), except that the \p src
    string must be located in program space (flash).

    Appends \p src to string \p dst of size \p siz (unlike strncat(),
    \p siz is the full size of \p dst, not space left).  At most \p siz-1
    characters will be copied.  Always NULL terminates (unless \p siz <=
    \p strlen(dst)).

    \returns The strlcat_P() function returns strlen(src) + MIN(siz,
    strlen(initial dst)).  If retval >= siz, truncation occurred.	*/
extern size_t strlcat_P (char *, const char *, size_t );

/** \ingroup avr_pgmspace
    \fn size_t strlcpy_P(char *dst, const char *src, size_t siz)
    \brief Copy a string from progmem to RAM.

    Copy \p src to string \p dst of size \p siz.  At most \p siz-1
    characters will be copied.  Always NULL terminates (unless \p siz == 0).
    The strlcpy_P() function is similar to strlcpy() except that the
    \p src is pointer to a string in memory space.

    \returns The strlcpy_P() function returns strlen(src). If
    retval >= siz, truncation occurred.  */
extern size_t strlcpy_P (char *, const char *, size_t );

/** \ingroup avr_pgmspace
    \fn size_t strnlen_P(const char *src, size_t len)
    \brief Determine the length of a fixed-size string.

    The strnlen_P() function is similar to strnlen(), except that \c src is a
    pointer to a string in program space.

    \returns The strnlen_P function returns strlen_P(src), if that is less than
    \c len, or \c len if there is no '\\0' character among the first \c len
    characters pointed to by \c src. */
extern size_t strnlen_P(const char *, size_t) __ATTR_CONST__; /* program memory can't change */

/** \ingroup avr_pgmspace
    \fn int strncmp_P(const char *s1, const char *s2, size_t n)

    The strncmp_P() function is similar to strcmp_P() except it only compares
    the first (at most) n characters of s1 and s2.

    \returns The strncmp_P() function returns an integer less than, equal to,
    or greater than zero if s1 (or the first n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than s2.  */
extern int strncmp_P(const char *, const char *, size_t) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn int strncasecmp_P(const char *s1, const char *s2, size_t n)
    \brief Compare two strings ignoring case.

    The strncasecmp_P() function is similar to strcasecmp_P(), except it
    only compares the first \p n characters of \p s1.

    \param s1 A pointer to a string in the devices SRAM.
    \param s2 A pointer to a string in the devices Flash.
    \param n The maximum number of bytes to compare.

    \returns The strncasecmp_P() function returns an integer less than,
    equal to, or greater than zero if \p s1 (or the first \p n bytes
    thereof) is found, respectively, to be less than, to match, or be
    greater than \p s2. A consequence of the ordering used by
    strncasecmp_P() is that if \p s1 is an initial substring of \p s2,
    then \p s1 is considered to be "less than" \p s2.  */
extern int strncasecmp_P(const char *, const char *, size_t) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn char *strncat_P(char *dest, const char *src, size_t len)
    \brief Concatenate two strings.

    The strncat_P() function is similar to strncat(), except that the \e src
    string must be located in program space (flash).

    \returns The strncat_P() function returns a pointer to the resulting string
    dest.  */
extern char *strncat_P(char *, const char *, size_t);

/** \ingroup avr_pgmspace
    \fn char *strncpy_P(char *dest, const char *src, size_t n)

    The strncpy_P() function is similar to strcpy_P() except that not more
    than n bytes of src are copied.  Thus, if there is no null byte among the
    first n bytes of src, the result will not be null-terminated.

    In the case where the length of src is less than that of n, the remainder
    of dest will be padded with nulls.

    \returns The strncpy_P() function returns a pointer to the destination
    string dest.  */
extern char *strncpy_P(char *, const char *, size_t);

/** \ingroup avr_pgmspace
    \fn char *strpbrk_P(const char *s, const char *accept)

    The strpbrk_P() function locates the first occurrence in the string
    \p s of any of the characters in the flash string \p accept. This
    function is similar to strpbrk() except that \p accept is a pointer
    to a string in program space.

    \return  The strpbrk_P() function returns a pointer to the character
    in \p s that matches one of the characters in \p accept, or \c NULL
    if no such character is found. The terminating zero is not considered
    as a part of string: if one or both args are empty, the result will
    \c NULL. */
extern char *strpbrk_P(const char *__s, const char * __accept) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn const char *strrchr_P(const char *s, int val)
    \brief Locate character in string.

    The strrchr_P() function returns a pointer to the last occurrence of
    the character \p val in the flash string \p s.

    \return The strrchr_P() function returns a pointer to the matched
    character or \c NULL if the character is not found. */
extern const char * strrchr_P(const char *, int __val) __ATTR_CONST__;

/** \ingroup avr_pgmspace
    \fn char *strsep_P(char **sp, const char *delim)
    \brief Parse a string into tokens.

    The strsep_P() function locates, in the string referenced by \p *sp,
    the first occurrence of any character in the string \p delim (or the
    terminating '\\0' character) and replaces it with a '\\0'.  The
    location of the next character after the delimiter character (or \c
    NULL, if the end of the string was reached) is stored in \p *sp. An
    ``empty'' field, i.e. one caused by two adjacent delimiter
    characters, can be detected by comparing the location referenced by
    the pointer returned in \p *sp to '\\0'. This function is similar to
    strsep() except that \p delim is a pointer to a string in program
    space.

    \return The strsep_P() function returns a pointer to the original
    value of \p *sp. If \p *sp is initially \c NULL, strsep_P() returns
    \c NULL. */
extern char *strsep_P(char **__sp, const char * __delim);

/** \ingroup avr_pgmspace
    \fn size_t strspn_P(const char *s, const char *accept)

    The strspn_P() function calculates the length of the initial segment
    of \p s which consists entirely of characters in \p accept. This
    function is similar to strspn() except that \p accept is a pointer
    to a string in program space.

    \return  The strspn_P() function returns the number of characters in
    the initial segment of \p s which consist only of characters from \p
    accept. The terminating zero is not considered as a part of string.	*/
extern size_t strspn_P(const char *__s, const char * __accept) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn char *strstr_P(const char *s1, const char *s2)
    \brief Locate a substring.

    The strstr_P() function finds the first occurrence of the substring
    \p s2 in the string \p s1.  The terminating '\\0' characters are not
    compared. The strstr_P() function is similar to strstr() except that
    \p s2 is pointer to a string in program space.

    \returns The strstr_P() function returns a pointer to the beginning
    of the substring, or NULL if the substring is not found. If \p s2
    points to a string of zero length, the function returns \p s1. */
extern char *strstr_P(const char *, const char *) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn char *strtok_P(char *s, const char * delim)
    \brief Parses the string into tokens.

    strtok_P() parses the string \p s into tokens. The first call to
    strtok_P() should have \p s as its first argument. Subsequent calls
    should have the first argument set to NULL. If a token ends with a
    delimiter, this delimiting character is overwritten with a '\\0' and a
    pointer to the next character is saved for the next call to strtok_P().
    The delimiter string \p delim may be different for each call.

    The strtok_P() function is similar to strtok() except that \p delim
    is pointer to a string in program space.

    \returns The strtok_P() function returns a pointer to the next token or
    NULL when no more tokens are found.

    \note strtok_P() is NOT reentrant. For a reentrant version of this
    function see strtok_rP().
 */
extern char *strtok_P(char *__s, const char * __delim);

/** \ingroup avr_pgmspace
    \fn char *strtok_rP (char *string, const char *delim, char **last)
    \brief Parses string into tokens.

    The strtok_rP() function parses \p string into tokens. The first call to
    strtok_rP() should have string as its first argument. Subsequent calls
    should have the first argument set to NULL. If a token ends with a
    delimiter, this delimiting character is overwritten with a '\\0' and a
    pointer to the next character is saved for the next call to strtok_rP().
    The delimiter string \p delim may be different for each call. \p last is
    a user allocated char* pointer. It must be the same while parsing the
    same string. strtok_rP() is a reentrant version of strtok_P().

    The strtok_rP() function is similar to strtok_r() except that \p delim
    is pointer to a string in program space.

    \returns The strtok_rP() function returns a pointer to the next token or
    NULL when no more tokens are found. */
extern char *strtok_rP(char *__s, const char * __delim, char **__last);

/** \ingroup avr_pgmspace
    \fn size_t strlen_PF(uint_farptr_t s)
    \brief Obtain the length of a string

    The strlen_PF() function is similar to strlen(), except that \e s is a
    far pointer to a string in program space.

    \param s A far pointer to the string in flash

    \returns The strlen_PF() function returns the number of characters in
    \e s. The contents of RAMPZ SFR are undefined when the function returns. */
extern size_t strlen_PF(uint_farptr_t src) __ATTR_CONST__; /* program memory can't change */

/** \ingroup avr_pgmspace
    \fn size_t strnlen_PF(uint_farptr_t s, size_t len)
    \brief Determine the length of a fixed-size string

    The strnlen_PF() function is similar to strnlen(), except that \e s is a
    far pointer to a string in program space.

    \param s A far pointer to the string in Flash
    \param len The maximum number of length to return

    \returns The strnlen_PF function returns strlen_P(\e s), if that is less
    than \e len, or \e len if there is no '\\0' character among the first \e
    len characters pointed to by \e s. The contents of RAMPZ SFR are
    undefined when the function returns. */
extern size_t strnlen_PF(uint_farptr_t src, size_t len) __ATTR_CONST__; /* program memory can't change */

/** \ingroup avr_pgmspace
    \fn void *memcpy_PF(void *dest, uint_farptr_t src, size_t n)
    \brief Copy a memory block from flash to SRAM

    The memcpy_PF() function is similar to memcpy(), except the data
    is copied from the program space and is addressed using a far pointer.

    \param dest A pointer to the destination buffer
    \param src A far pointer to the origin of data in flash memory
    \param n The number of bytes to be copied

    \returns The memcpy_PF() function returns a pointer to \e dst. The contents
    of RAMPZ SFR are undefined when the function returns. */
extern void *memcpy_PF(void *dest, uint_farptr_t src, size_t len);

/** \ingroup avr_pgmspace
    \fn char *strcpy_PF(char *dst, uint_farptr_t src)
    \brief Duplicate a string

    The strcpy_PF() function is similar to strcpy() except that \e src is a far
    pointer to a string in program space.

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the source string in Flash

    \returns The strcpy_PF() function returns a pointer to the destination
    string \e dst. The contents of RAMPZ SFR are undefined when the funcion
    returns. */
extern char *strcpy_PF(char *dest, uint_farptr_t src);

/** \ingroup avr_pgmspace
    \fn char *strncpy_PF(char *dst, uint_farptr_t src, size_t n)
    \brief Duplicate a string until a limited length

    The strncpy_PF() function is similar to strcpy_PF() except that not more
    than \e n bytes of \e src are copied.  Thus, if there is no null byte among
    the first \e n bytes of \e src, the result will not be null-terminated.

    In the case where the length of \e src is less than that of \e n, the
    remainder of \e dst will be padded with nulls.

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the source string in Flash
    \param n The maximum number of bytes to copy

    \returns The strncpy_PF() function returns a pointer to the destination
    string \e dst. The contents of RAMPZ SFR are undefined when the function
    returns. */
extern char *strncpy_PF(char *dest, uint_farptr_t src, size_t len);

/** \ingroup avr_pgmspace
    \fn char *strcat_PF(char *dst, uint_farptr_t src)
    \brief Concatenates two strings

    The strcat_PF() function is similar to strcat() except that the \e src
    string must be located in program space (flash) and is addressed using
    a far pointer

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the string to be appended in Flash

    \returns The strcat_PF() function returns a pointer to the resulting
    string \e dst. The contents of RAMPZ SFR are undefined when the function
    returns */
extern char *strcat_PF(char *dest, uint_farptr_t src);

/** \ingroup avr_pgmspace
    \fn size_t strlcat_PF(char *dst, uint_farptr_t src, size_t n)
    \brief Concatenate two strings

    The strlcat_PF() function is similar to strlcat(), except that the \e src
    string must be located in program space (flash) and is addressed using
    a far pointer.

    Appends src to string dst of size \e n (unlike strncat(), \e n is the
    full size of \e dst, not space left).  At most \e n-1 characters
    will be copied.  Always NULL terminates (unless \e n <= strlen(\e dst)).

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the source string in Flash
    \param n The total number of bytes allocated to the destination string

    \returns The strlcat_PF() function returns strlen(\e src) + MIN(\e n,
    strlen(initial \e dst)).  If retval >= \e n, truncation occurred. The
    contents of RAMPZ SFR are undefined when the funcion returns. */
extern size_t strlcat_PF(char *dst, uint_farptr_t src, size_t siz);

/** \ingroup avr_pgmspace
    \fn char *strncat_PF(char *dst, uint_farptr_t src, size_t n)
    \brief Concatenate two strings

    The strncat_PF() function is similar to strncat(), except that the \e src
    string must be located in program space (flash) and is addressed using a
    far pointer.

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the source string in Flash
    \param n The maximum number of bytes to append

    \returns The strncat_PF() function returns a pointer to the resulting
    string \e dst. The contents of RAMPZ SFR are undefined when the function
    returns. */
extern char *strncat_PF(char *dest, uint_farptr_t src, size_t len);

/** \ingroup avr_pgmspace
    \fn int strcmp_PF(const char *s1, uint_farptr_t s2)
    \brief Compares two strings

    The strcmp_PF() function is similar to strcmp() except that \e s2 is a far
    pointer to a string in program space.

    \param s1 A pointer to the first string in SRAM
    \param s2 A far pointer to the second string in Flash

    \returns The strcmp_PF() function returns an integer less than, equal to,
    or greater than zero if \e s1 is found, respectively, to be less than, to
    match, or be greater than \e s2. The contents of RAMPZ SFR are undefined
    when the function returns. */
extern int strcmp_PF(const char *s1, uint_farptr_t s2) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn int strncmp_PF(const char *s1, uint_farptr_t s2, size_t n)
    \brief Compare two strings with limited length

    The strncmp_PF() function is similar to strcmp_PF() except it only
    compares the first (at most) \e n characters of \e s1 and \e s2.

    \param s1 A pointer to the first string in SRAM
    \param s2 A far pointer to the second string in Flash
    \param n The maximum number of bytes to compare

    \returns The strncmp_PF() function returns an integer less than, equal
    to, or greater than zero if \e s1 (or the first \e n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than \e s2. The
    contents of RAMPZ SFR are undefined when the function returns. */
extern int strncmp_PF(const char *s1, uint_farptr_t s2, size_t n) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn int strcasecmp_PF(const char *s1, uint_farptr_t s2)
    \brief Compare two strings ignoring case

    The strcasecmp_PF() function compares the two strings \e s1 and \e s2, ignoring
    the case of the characters.

    \param s1 A pointer to the first string in SRAM
    \param s2 A far pointer to the second string in Flash

    \returns The strcasecmp_PF() function returns an integer less than, equal
    to, or greater than zero if \e s1 is found, respectively, to be less than, to
    match, or be greater than \e s2. The contents of RAMPZ SFR are undefined
    when the function returns. */
extern int strcasecmp_PF(const char *s1, uint_farptr_t s2) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn int strncasecmp_PF(const char *s1, uint_farptr_t s2, size_t n)
    \brief Compare two strings ignoring case

    The strncasecmp_PF() function is similar to strcasecmp_PF(), except it
    only compares the first \e n characters of \e s1 and the string in flash is
    addressed using a far pointer.

    \param s1 A pointer to a string in SRAM
    \param s2 A far pointer to a string in Flash
    \param n The maximum number of bytes to compare

    \returns The strncasecmp_PF() function returns an integer less than, equal
    to, or greater than zero if \e s1 (or the first \e n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than \e s2. The
    contents of RAMPZ SFR are undefined when the function returns.  */
extern int strncasecmp_PF(const char *s1, uint_farptr_t s2, size_t n) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn uint_farptr_t strchr_PF(uint_farptr_t s, int val)
    \brief Locate character in far program space string.

    The strchr_PF() function locates the first occurrence of \p val
    (converted to a char) in the string pointed to by \p s in far program
    space. The terminating null character is considered to be part of
    the string.

    The strchr_PF() function is similar to strchr() except that \p s is
    a far pointer to a string in program space that's \e not \e required to be
    located in the lower 64 KiB block like it is the case  for strchr_P().

    \returns The strchr_PF() function returns a far pointer to the matched
    character or \c 0 if the character is not found. */
extern uint_farptr_t strchr_PF(uint_farptr_t, int __val) __ATTR_CONST__;

/** \ingroup avr_pgmspace
    \fn char *strstr_PF(const char *s1, uint_farptr_t s2)
    \brief Locate a substring.

    The strstr_PF() function finds the first occurrence of the substring \c s2
    in the string \c s1.  The terminating '\\0' characters are not
    compared.
    The strstr_PF() function is similar to strstr() except that \c s2 is a
    far pointer to a string in program space.

    \returns The strstr_PF() function returns a pointer to the beginning of the
    substring, or NULL if the substring is not found.
    If \c s2 points to a string of zero length, the function returns \c s1. The
    contents of RAMPZ SFR are undefined when the function returns. */
extern char *strstr_PF(const char *s1, uint_farptr_t s2);

/** \ingroup avr_pgmspace
    \fn size_t strlcpy_PF(char *dst, uint_farptr_t src, size_t siz)
    \brief Copy a string from progmem to RAM.

    Copy src to string dst of size siz.  At most siz-1 characters will be
    copied. Always NULL terminates (unless siz == 0).

    \returns The strlcpy_PF() function returns strlen(src). If retval >= siz,
    truncation occurred.  The contents of RAMPZ SFR are undefined when the
    function returns. */
extern size_t strlcpy_PF(char *dst, uint_farptr_t src, size_t siz);

/** \ingroup avr_pgmspace
    \fn int memcmp_PF(const void *s1, uint_farptr_t s2, size_t len)
    \brief Compare memory areas

    The memcmp_PF() function compares the first \p len bytes of the memory
    areas \p s1 and flash \p s2. The comparision is performed using unsigned
    char operations. It is an equivalent of memcmp_P() function, except
    that it is capable working on all FLASH including the exteded area
    above 64kB.

    \returns The memcmp_PF() function returns an integer less than, equal
    to, or greater than zero if the first \p len bytes of \p s1 is found,
    respectively, to be less than, to match, or be greater than the first
    \p len bytes of \p s2.  */
extern int memcmp_PF(const void *, uint_farptr_t, size_t) __ATTR_PURE__;

#ifdef __DOXYGEN__
/** \ingroup avr_pgmspace
    \fn size_t strlen_P(const char *src)

    The strlen_P() function is similar to strlen(), except that src is a
    pointer to a string in program space.

    \returns The strlen_P() function returns the number of characters in src.

    \note strlen_P() is implemented as an inline function in the avr/pgmspace.h
    header file, which will check if the length of the string is a constant
    and known at compile time. If it is not known at compile time, the macro
    will issue a call to __strlen_P() which will then calculate the length
    of the string as normal.
*/
static inline size_t strlen_P(const char * s);
#else /* !DOXYGEN */

#ifdef __AVR_TINY__
#define __strlen_P strlen
extern size_t strlen (const char*);
#else
extern size_t __strlen_P(const char *) __ATTR_CONST__;  /* internal helper function */
#endif

static __ATTR_ALWAYS_INLINE__ size_t strlen_P(const char * s);
size_t strlen_P(const char *s)
{
  return __builtin_constant_p(__builtin_strlen(s))
     ? __builtin_strlen(s) : __strlen_P(s);
}
#endif /* DOXYGEN */

#ifdef __cplusplus
} // extern "C"
#endif

#if defined(__cplusplus) && defined(__pgm_read_template__)

/* Caveat: When this file is found via -isystem <path>, then some older
   avr-g++ versions come up with

       error: template with C linkage

   because the target description did not define NO_IMPLICIT_EXTERN_C.  */

template<typename __T, size_t>
struct __pgm_read_impl
{
  // A default implementaton for T's with a size not in { 1, 2, 3, 4, 8 }.
  // While this works, the performance is absolute scrap because GCC does
  // not handle objects well that don't fit in a register (i.e. avr-gcc
  // has no respective machine_mode).
  __T operator() (const __T *__addr) const
  {
    __T __res;
    memcpy_P (&__res, __addr, sizeof(__T));
    return __res;
  }
};

template<typename __T>
struct __pgm_read_impl<__T, 1>
{
  __T operator() (const __T *__addr) const
  {
    __T __res; __LPM__1 (__res, __addr); return __res;
  }
};

template<typename __T>
struct __pgm_read_impl<__T, 2>
{
  __T operator() (const __T *__addr) const
  {
    __T __res; __LPM__2 (__res, __addr); return __res;
  }
};

template<typename __T>
struct __pgm_read_impl<__T, 3>
{
  __T operator() (const __T *__addr) const
  {
    __T __res; __LPM__3 (__res, __addr); return __res;
  }
};

template<typename __T>
struct __pgm_read_impl<__T, 4>
{
  __T operator() (const __T *__addr) const
  {
    __T __res; __LPM__4 (__res, __addr); return __res;
  }
};

template<typename __T>
struct __pgm_read_impl<__T, 8>
{
  __T operator() (const __T *__addr) const
  {
    __T __res; __LPM__8 (__res, __addr); return __res;
  }
};

template<typename __T>
__T pgm_read (const __T *__addr)
{
  return __pgm_read_impl<__T, sizeof(__T)>() (__addr);
}

//////////////////////////////////////////////////////////

template<typename __T, size_t>
struct __pgm_read_far_impl
{
  // A default implementaton for T's with a size not in { 1, 2, 3, 4, 8 }.
  // While this works, the performance is absolute scrap because GCC does
  // not handle objects well that don't fit in a register (i.e. avr-gcc
  // has no respective machine_mode).
  __T operator() (const __T *__addr) const
  {
    __T __res;
    memcpy_PF (&__res, __addr, sizeof(__T));
    return __res;
  }
};

template<typename __T>
struct __pgm_read_far_impl<__T, 1>
{
  __T operator() (uint_farptr_t __addr) const
  {
    __T __res; __ELPM__1 (__res, __addr, __T); return __res;
  }
};

template<typename __T>
struct __pgm_read_far_impl<__T, 2>
{
  __T operator() (uint_farptr_t __addr) const
  {
    __T __res; __ELPM__2 (__res, __addr, __T); return __res;
  }
};

template<typename __T>
struct __pgm_read_far_impl<__T, 3>
{
  __T operator() (uint_farptr_t __addr) const
  {
    __T __res; __ELPM__3 (__res, __addr, __T); return __res;
  }
};

template<typename __T>
struct __pgm_read_far_impl<__T, 4>
{
  __T operator() (uint_farptr_t __addr) const
  {
    __T __res; __ELPM__4 (__res, __addr, __T); return __res;
  }
};

template<typename __T>
struct __pgm_read_far_impl<__T, 8>
{
  __T operator() (uint_farptr_t __addr) const
  {
    __T __res; __ELPM__8 (__res, __addr, __T); return __res;
  }
};

template<typename __T>
__T pgm_read_far (uint_farptr_t __addr)
{
  return __pgm_read_far_impl<__T, sizeof(__T)>() (__addr);
}

#endif /* C++ */

#ifdef __DOXYGEN__
/** \ingroup avr_pgmspace
    \fn T pgm_read<T> (const T *addr)

    Read an object of type \c T from program memory address \p addr and
    return it.
    This template is only available when macro \c __pgm_read_template__
    is defined.  */
template<typename T>
T pgm_read<T> (const T *addr);

/** \ingroup avr_pgmspace
    \fn T pgm_read_far<T> (uint_farptr_t addr)

    Read an object of type \c T from program memory address \p addr and
    return it.
    This template is only available when macro \c __pgm_read_template__
    is defined.  */
template<typename T>
T pgm_read_far<T> (uint_farptr_t addr);
#endif /* DOXYGEN */

#endif /* __PGMSPACE_H_ */
