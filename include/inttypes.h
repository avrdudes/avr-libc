/* Copyright (c) 2004,2005 Joerg Wunsch
   Copyright (c) 2005, Carlos Lamas
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

#ifndef __INTTYPES_H_
#define __INTTYPES_H_

#include <stdint.h>

/** \defgroup avr_inttypes <inttypes.h>: Integer Type conversions
    \code #include <inttypes.h> \endcode

    This header file includes the exact-width integer definitions from
    <tt><stdint.h></tt>, and extends them with additional facilities
    provided by the implementation.
*/

/** \name Far pointers for memory access >64K */

/*@{*/
/** \ingroup avr_inttypes
    signed integer type that can hold a pointer > 64 KB */
typedef int32_t int_farptr_t;

/** \ingroup avr_inttypes
    unsigned integer type that can hold a pointer > 64 KB */
typedef uint32_t uint_farptr_t;
/*@}*/

#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS)


/** \name macros for printf and scanf format specifiers

    For C++, these are only included if __STDC_LIMIT_MACROS
    is defined before including <inttypes.h>.
 */

/*@{*/
/** \ingroup avr_inttypes
    decimal printf format for int8_t */
#define		PRId8			"d"
/** \ingroup avr_inttypes
    decimal printf format for int_least8_t */
#define		PRIdLEAST8		"d"
/** \ingroup avr_inttypes
    decimal printf format for int_fast8_t */
#define		PRIdFAST8		"d"

/** \ingroup avr_inttypes
    integer printf format for int8_t */
#define		PRIi8			"i"
/** \ingroup avr_inttypes
    integer printf format for int_least8_t */
#define		PRIiLEAST8		"i"
/** \ingroup avr_inttypes
    integer printf format for int_fast8_t */
#define		PRIiFAST8		"i"


/** \ingroup avr_inttypes
    decimal printf format for int16_t */
#define		PRId16			"d"
/** \ingroup avr_inttypes
    decimal printf format for int_least16_t */
#define		PRIdLEAST16		"d"
/** \ingroup avr_inttypes
    decimal printf format for int_fast16_t */
#define		PRIdFAST16		"d"

/** \ingroup avr_inttypes
    integer printf format for int16_t */
#define		PRIi16			"i"
/** \ingroup avr_inttypes
    integer printf format for int_least16_t */
#define		PRIiLEAST16		"i"
/** \ingroup avr_inttypes
    integer printf format for int_fast16_t */
#define		PRIiFAST16		"i"


/** \ingroup avr_inttypes
    decimal printf format for int32_t */
#define		PRId32			"ld"
/** \ingroup avr_inttypes
    decimal printf format for int_least32_t */
#define		PRIdLEAST32		"ld"
/** \ingroup avr_inttypes
    decimal printf format for int_fast32_t */
#define		PRIdFAST32		"ld"

/** \ingroup avr_inttypes
    integer printf format for int32_t */
#define		PRIi32			"li"
/** \ingroup avr_inttypes
    integer printf format for int_least32_t */
#define		PRIiLEAST32		"li"
/** \ingroup avr_inttypes
    integer printf format for int_fast32_t */
#define		PRIiFAST32		"li"


#ifdef __avr_libc_does_not_implement_long_long_in_printf_or_scanf

#define		PRId64			"lld"
#define		PRIdLEAST64		"lld"
#define		PRIdFAST64		"lld"

#define		PRIi64			"lli"
#define		PRIiLEAST64		"lli"
#define		PRIiFAST64		"lli"


#define		PRIdMAX			"lld"
#define		PRIiMAX			"lli"

#endif

/** \ingroup avr_inttypes
    decimal printf format for int */
#define		PRIdPTR			PRId16
/** \ingroup avr_inttypes
    integer printf format for int */
#define		PRIiPTR			PRIi16

/** \ingroup avr_inttypes
    octal printf format for uint8_t */
#define		PRIo8			"o"
/** \ingroup avr_inttypes
    octal printf format for uint_least8_t */
#define		PRIoLEAST8		"o"
/** \ingroup avr_inttypes
    octal printf format for uint_fast8_t */
#define		PRIoFAST8		"o"

/** \ingroup avr_inttypes
    decimal printf format for uint8_t */
#define		PRIu8			"u"
/** \ingroup avr_inttypes
    decimal printf format for uint_least8_t */
#define		PRIuLEAST8		"u"
/** \ingroup avr_inttypes
    decimal printf format for uint_fast8_t */
#define		PRIuFAST8		"u"

/** \ingroup avr_inttypes
    hexadecimal printf format for uint8_t */
#define		PRIx8			"x"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_least8_t */
#define		PRIxLEAST8		"x"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_fast8_t */
#define		PRIxFAST8		"x"

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint8_t */
#define		PRIX8			"X"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_least8_t */
#define		PRIXLEAST8		"X"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_fast8_t */
#define		PRIXFAST8		"X"


/** \ingroup avr_inttypes
    octal printf format for uint8_t */
#define		PRIo16			"o"
/** \ingroup avr_inttypes
    octal printf format for uint_least8_t */
#define		PRIoLEAST16		"o"
/** \ingroup avr_inttypes
    octal printf format for uint_fast8_t */
#define		PRIoFAST16		"o"

#define		PRIu16			"u"
#define		PRIuLEAST16		"u"
#define		PRIuFAST16		"u"

#define		PRIx16			"x"
#define		PRIxLEAST16		"x"
#define		PRIxFAST16		"x"

#define		PRIX16			"X"
#define		PRIXLEAST16		"X"
#define		PRIXFAST16		"X"


#define		PRIo32			"lo"
#define		PRIoLEAST32		"lo"
#define		PRIoFAST32		"lo"

#define		PRIu32			"lu"
#define		PRIuLEAST32		"lu"
#define		PRIuFAST32		"lu"

#define		PRIx32			"lx"
#define		PRIxLEAST32		"lx"
#define		PRIxFAST32		"lx"

#define		PRIX32			"lX"
#define		PRIXLEAST32		"lX"
#define		PRIXFAST32		"lX"


#if __avr_libc_does_not_implement_long_long_in_printf_or_scanf

#define		PRIo64			"llo"
#define		PRIoLEAST64		"llo"
#define		PRIoFAST64		"llo"

#define		PRIu64			"llu"
#define		PRIuLEAST64		"llu"
#define		PRIuFAST64		"llu"

#define		PRIx64			"llx"
#define		PRIxLEAST64		"llx"
#define		PRIxFAST64		"llx"

#define		PRIX64			"llX"
#define		PRIXLEAST64		"llX"
#define		PRIXFAST64		"llX"

#define		PRIoMAX			"llo"
#define		PRIuMAX			"llu"
#define		PRIxMAX			"llx"
#define		PRIXMAX			"llX"

#endif

#define		PRIoPTR			PRIo16
#define		PRIuPTR			PRIu16
#define		PRIxPTR			PRIx16
#define		PRIXPTR			PRIX16



/* The fscanf macros for signed integers */


#define		SCNd8			"hhd"
#define		SCNdLEAST8		"hhd"
#define		SCNdFAST8		"hhd"

#define		SCNi8			"hhi"
#define		SCNiLEAST8		"hhi"
#define		SCNiFAST8		"hhi"


#define		SCNd16			"d"
#define		SCNdLEAST16		"d"
#define		SCNdFAST16		"d"

#define		SCNi16			"i"
#define		SCNiLEAST16		"i"
#define		SCNiFAST16		"i"


#define		SCNd32			"ld"
#define		SCNdLEAST32		"ld"
#define		SCNdFAST32		"ld"

#define		SCNi32			"li"
#define		SCNiLEAST32		"li"
#define		SCNiFAST32		"li"


#if __avr_libc_does_not_implement_long_long_in_printf_or_scanf

#define		SCNd64			"lld"
#define		SCNdLEAST64		"lld"
#define		SCNdFAST64		"lld"

#define		SCNi64			"lli"
#define		SCNiLEAST64		"lli"
#define		SCNiFAST64		"lli"

#define		SCNdMAX			"lld"
#define		SCNiMAX			"lli"

#endif

#define		SCNdPTR			SCNd16
#define		SCNiPTR			SCNi16


/* The fscanf macros for unsigned integers */


#define		SCNo8			"hho"
#define		SCNoLEAST8		"hho"
#define		SCNoFAST8		"hho"

#define		SCNu8			"hhu"
#define		SCNuLEAST8		"hhu"
#define		SCNuFAST8		"hhu"

#define		SCNx8			"hhx"
#define		SCNxLEAST8		"hhx"
#define		SCNxFAST8		"hhx"


#define		SCNo16			"o"
#define		SCNoLEAST16		"o"
#define		SCNoFAST16		"o"

#define		SCNu16			"u"
#define		SCNuLEAST16		"u"
#define		SCNuFAST16		"u"

#define		SCNx16			"x"
#define		SCNxLEAST16		"x"
#define		SCNxFAST16		"x"


#define		SCNo32			"lo"
#define		SCNoLEAST32		"lo"
#define		SCNoFAST32		"lo"

#define		SCNu32			"lu"
#define		SCNuLEAST32		"lu"
#define		SCNuFAST32		"lu"

#define		SCNx32			"lx"
#define		SCNxLEAST32		"lx"
#define		SCNxFAST32		"lx"


#if __avr_libc_does_not_implement_long_long_in_printf_or_scanf

#define		SCNo64			"llo"
#define		SCNoLEAST64		"llo"
#define		SCNoFAST64		"llo"

#define		SCNu64			"llu"
#define		SCNuLEAST64		"llu"
#define		SCNuFAST64		"llu"

#define		SCNx64			"llx"
#define		SCNxLEAST64		"llx"
#define		SCNxFAST64		"llx"

#define		SCNoMAX			"llo"
#define		SCNuMAX			"llu"
#define		SCNxMAX			"llx"


#define		SCNoPTR			SCNo16
#define		SCNuPTR			SCNu16
#define		SCNxPTR			SCNx16

#endif
/*@{*/


#endif	/* !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) */


#endif /* __INTTYPES_H_ */
