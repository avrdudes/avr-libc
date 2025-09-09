/* Copyright (c) 2002,2004,2005 Marek Michalkiewicz
   Copyright (c) 2005, Carlos Lamas
   Copyright (c) 2005,2007 Joerg Wunsch
   Copyright (c) 2013 Embecosm
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
 * ISO/IEC 9899:1999  7.18 Integer types <stdint.h>
 */

#ifndef __STDINT_H_
#define __STDINT_H_

/** \file */
/** \defgroup avr_stdint <stdint.h>: Standard Integer Types
    \code #include <stdint.h> \endcode

    Use [u]intN_t if you need exactly N bits.

    Since these typedefs are mandated by the C99 standard, they are preferred
    over rolling your own typedefs.

\anchor int24
    \note The 24-bit types and constants are supported since AVR-LibC v2.3.
    In older versions, they can still be used by means of the compiler
    built-in types and macros \c __int24, \c __uint24, \c __INT24_MIN__,
    \c __INT24_MAX__ and \c __UINT24_MAX__ supported since
    <a href="https://gcc.gnu.org/gcc-4.7/changes.html#avr">GCC v4.7</a>.
*/


#ifndef __DOXYGEN__
/*
 * __USING_MINT8 is defined to 1 if the -mint8 option is in effect.
 */
#if __INT_MAX__ == 127
# define __USING_MINT8 1
#else
# define __USING_MINT8 0
#endif

#endif /* !__DOXYGEN__ */

/* Integer types */

#if defined(__DOXYGEN__)

/* doxygen gets confused by the __attribute__ stuff */

/** \name Exact-width integer types
    Integer types having exactly the specified width. */

/**@{*/

/** \ingroup avr_stdint
    8-Bit signed integer type. */
typedef signed char int8_t;

/** \ingroup avr_stdint
    8-Bit unsigned integer type. */
typedef unsigned char uint8_t;

/** \ingroup avr_stdint
    16-Bit signed integer type. */
typedef signed int int16_t;

/** \ingroup avr_stdint
    16-Bit unsigned integer type. */
typedef unsigned int uint16_t;

/** \ingroup avr_stdint
    24-Bit signed integer type.
    \since AVR-LibC v2.3, \ref int24 */
typedef __int24 int24_t;

/** \ingroup avr_stdint
    24-Bit unsigned integer type.
    \since AVR-LibC v2.3, \ref int24 */
typedef __uint24 uint24_t;

/** \ingroup avr_stdint
    32-Bit signed integer type. */
typedef signed long int int32_t;

/** \ingroup avr_stdint
    32-Bit unsigned integer type. */
typedef unsigned long int uint32_t;

/** \ingroup avr_stdint
    64-Bit signed integer type.
    \note This type is not available when the compiler
    option \c \-mint8 is in effect. */
typedef signed long long int int64_t;

/** \ingroup avr_stdint
    64-Bit unsigned integer type.
    \note This type is not available when the compiler
    option \c \-mint8 is in effect. */
typedef unsigned long long int uint64_t;

/**@}*/

#else /* !defined(__DOXYGEN__) */

/* Actual implementation goes here.  Define to what built-ins
   like __UINT32_TYPE__ would resolve to.  */

typedef signed char int8_t;
typedef unsigned char uint8_t;

#if !__USING_MINT8

typedef int int16_t;
typedef unsigned int uint16_t;
typedef long int int32_t;
typedef long unsigned int uint32_t;
typedef long long int int64_t;
typedef long long unsigned int uint64_t;

#else /* __USING_MINT8 */

typedef long int int16_t;
typedef long unsigned int uint16_t;
typedef long long int int32_t;
typedef long long unsigned int uint32_t;

#endif /* __USING_MINT8 */

#ifdef __INT24_MAX__
__extension__ typedef __int24 int24_t;
__extension__ typedef __uint24 uint24_t;
typedef int24_t  int_least24_t;
typedef uint24_t uint_least24_t;
typedef int24_t  int_fast24_t;
typedef uint24_t uint_fast24_t;
#else
typedef int32_t  int_least24_t;
typedef uint32_t uint_least24_t;
typedef int32_t  int_fast24_t;
typedef uint32_t uint_fast24_t;
#endif /* Have int24 */

#endif /* defined(__DOXYGEN__) */

/** \name Integer types capable of holding object pointers
    These allow you to declare variables of the same size as a pointer. */

/**@{*/

/** \ingroup avr_stdint
    Signed pointer compatible type. */
typedef int16_t intptr_t;

/** \ingroup avr_stdint
    Unsigned pointer compatible type. */
typedef uint16_t uintptr_t;

/** \ingroup avr_stdint
    Signed 24-bit pointer compatible type.
    \since AVR-LibC v2.3, \ref int24  */
typedef int_least24_t intptr24_t;

/** \ingroup avr_stdint
    Unsigned 24-bit pointer compatible type.
    \since AVR-LibC v2.3, \ref int24  */
typedef uint_least24_t uintptr24_t;

/**@}*/

/** \name Minimum-width integer types
   Integer types having at least the specified width. */

/**@{*/

/** \ingroup avr_stdint
    Signed integer type with at least 8 bits. */
typedef int8_t   int_least8_t;

/** \ingroup avr_stdint
    Unsigned integer type with at least 8 bits. */
typedef uint8_t  uint_least8_t;

/** \ingroup avr_stdint
    Signed integer type with at least 16 bits. */
typedef int16_t  int_least16_t;

/** \ingroup avr_stdint
    Unsigned integer type with at least 16 bits. */
typedef uint16_t uint_least16_t;

#ifdef __DOXYGEN__
/** \ingroup avr_stdint
    Signed integer type with at least 24 bits.
    \since AVR-LibC v2.3, \ref int24  */
typedef int24_t  int_least24_t;

/** \ingroup avr_stdint
    Unsigned integer type with at least 24 bits.
    \since AVR-LibC v2.3, \ref int24  */
typedef uint24_t uint_least24_t;
#endif /* Doxygen */

/** \ingroup avr_stdint
    Signed integer type with at least 32 bits. */
typedef int32_t  int_least32_t;

/** \ingroup avr_stdint
    Unsigned integer type with at least 32 bits. */
typedef uint32_t uint_least32_t;

#if !__USING_MINT8 || defined(__DOXYGEN__)
/** \ingroup avr_stdint
    Signed integer type with at least 64 bits.
    \note This type is not available when the compiler
    option \c \-mint8 is in effect. */
typedef int64_t  int_least64_t;

/** \ingroup avr_stdint
    Unsigned integer type with at least 64 bits.
    \note This type is not available when the compiler
    option \c \-mint8 is in effect. */
typedef uint64_t uint_least64_t;

#endif

/**@}*/


/** \name Fastest minimum-width integer types
   Integer types being usually fastest having at least the specified width. */

/**@{*/

/** \ingroup avr_stdint
    Fastest signed integer type with at least 8 bits. */
typedef int8_t int_fast8_t;

/** \ingroup avr_stdint
    Fastest unsigned integer type with at least 8 bits. */
typedef uint8_t uint_fast8_t;

/** \ingroup avr_stdint
    Fastest signed integer type with at least 16 bits. */
typedef int16_t int_fast16_t;

/** \ingroup avr_stdint
    Fastest unsigned integer type with at least 16 bits. */
typedef uint16_t uint_fast16_t;

#ifdef __DOXYGEN__
/** \ingroup avr_stdint
    Fastest signed integer type with at least 24 bits.
    \since AVR-LibC v2.3, \ref int24  */
typedef int24_t  int_fast24_t;

/** \ingroup avr_stdint
    Fastest unsigned integer type with at least 24 bits.
    \since AVR-LibC v2.3, \ref int24  */
typedef uint24_t uint_fast24_t;
#endif /* Doxygen */

/** \ingroup avr_stdint
    Fastest signed integer type with at least 32 bits. */
typedef int32_t int_fast32_t;

/** \ingroup avr_stdint
    Fastest unsigned integer type with at least 32 bits. */
typedef uint32_t uint_fast32_t;

#if !__USING_MINT8 || defined(__DOXYGEN__)
/** \ingroup avr_stdint
    Fastest signed integer type with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */
typedef int64_t int_fast64_t;

/** \ingroup avr_stdint
    Fastest unsigned integer type with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */
typedef uint64_t uint_fast64_t;
#endif

/**@}*/


/** \name Greatest-width integer types
   Types designating integer data capable of representing any value of
   any integer type in the corresponding signed or unsigned category. */

/**@{*/

#if __USING_MINT8

typedef int32_t intmax_t;
typedef uint32_t uintmax_t;

#else  /* !__USING_MINT8 */

/** \ingroup avr_stdint
    Largest signed integer available. */
typedef int64_t intmax_t;

/** \ingroup avr_stdint
    Largest unsigned integer available. */
typedef uint64_t uintmax_t;

#endif /* __USING_MINT8 */

/**@}*/

#ifndef __DOXYGEN__
/* Helping macro */
#ifndef __CONCAT
#define __CONCATenate(left, right) left ## right
#define __CONCAT(left, right) __CONCATenate(left, right)
#endif

#endif /* !__DOXYGEN__ */

#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS)

/** \name Limits of specified-width integer types
   C++ implementations should define these macros only when
   __STDC_LIMIT_MACROS is defined before <stdint.h> is included. */

/**@{*/

/** \ingroup avr_stdint
    Largest positive value an \c #int8_t can hold. */
#define INT8_MAX 0x7f

/** \ingroup avr_stdint
    Smallest negative value an \c #int8_t can hold. */
#define INT8_MIN (-INT8_MAX - 1)

#if __USING_MINT8

#define UINT8_MAX (__CONCAT(INT8_MAX, U) * 2U + 1U)

#define INT16_MAX 0x7fffL
#define INT16_MIN (-INT16_MAX - 1L)
#define UINT16_MAX (__CONCAT(INT16_MAX, U) * 2UL + 1UL)

#define INT32_MAX 0x7fffffffLL
#define INT32_MIN (-INT32_MAX - 1LL)
#define UINT32_MAX (__CONCAT(INT32_MAX, U) * 2ULL + 1ULL)

#else /* !__USING_MINT8 */

/** \ingroup avr_stdint
    Largest value an \c #uint8_t can hold. */
#define UINT8_MAX (__CONCAT(INT8_MAX, U) * 2U + 1U)

/** \ingroup avr_stdint
    Largest positive value an \c #int16_t can hold. */
#define INT16_MAX 0x7fff

/** \ingroup avr_stdint
    Smallest negative value an \c #int16_t can hold. */
#define INT16_MIN (-INT16_MAX - 1)

/** \ingroup avr_stdint
    Largest value an \c #uint16_t can hold. */
#define UINT16_MAX (__CONCAT(INT16_MAX, U) * 2U + 1U)

/** \ingroup avr_stdint
    Largest positive value an \c #int24_t can hold.
    \since AVR-LibC v2.3, \ref int24 */
#define INT24_MAX __INT24_MAX__

/** \ingroup avr_stdint
    Smallest negative value an \c #int24_t can hold.
    \since AVR-LibC v2.3, \ref int24 */
#define INT24_MIN __INT24_MIN__

/** \ingroup avr_stdint
    Largest value an \c #uint24_t can hold.
    \since AVR-LibC v2.3, \ref int24 */
#define UINT24_MAX __UINT24_MAX__

/** \ingroup avr_stdint
    Largest positive value an \c #int32_t can hold. */
#define INT32_MAX 0x7fffffffL

/** \ingroup avr_stdint
    Smallest negative value an \c #int32_t can hold. */
#define INT32_MIN (-INT32_MAX - 1L)

/** \ingroup avr_stdint
    Largest value an \c #uint32_t can hold. */
#define UINT32_MAX (__CONCAT(INT32_MAX, U) * 2UL + 1UL)

#endif /* __USING_MINT8 */

/** \ingroup avr_stdint
    Largest positive value an \c #int64_t can hold. */
#define INT64_MAX 0x7fffffffffffffffLL

/** \ingroup avr_stdint
    Smallest negative value an \c #int64_t can hold. */
#define INT64_MIN (-INT64_MAX - 1LL)

/** \ingroup avr_stdint
    Largest value an \c #uint64_t can hold. */
#define UINT64_MAX (__CONCAT(INT64_MAX, U) * 2ULL + 1ULL)

/**@}*/

/** \name Limits of minimum-width integer types */
/**@{*/

/** \ingroup avr_stdint
    Largest positive value an \c #int_least8_t can hold. */
#define INT_LEAST8_MAX INT8_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #int_least8_t can hold. */
#define INT_LEAST8_MIN INT8_MIN

/** \ingroup avr_stdint
    Largest value an \c #uint_least8_t can hold. */
#define UINT_LEAST8_MAX UINT8_MAX

/** \ingroup avr_stdint
    Largest positive value an \c #int_least16_t can hold. */
#define INT_LEAST16_MAX INT16_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #int_least16_t can hold. */
#define INT_LEAST16_MIN INT16_MIN

/** \ingroup avr_stdint
    Largest value an \c #uint_least16_t can hold. */
#define UINT_LEAST16_MAX UINT16_MAX

/** \ingroup avr_stdint
    Largest positive value an \c #int_least24_t can hold.
    \since AVR-LibC v2.3, \ref int24 */
#define INT_LEAST24_MAX INT24_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #int_least24_t can hold.
    \since AVR-LibC v2.3, \ref int24 */
#define INT_LEAST24_MIN INT24_MIN

/** \ingroup avr_stdint
    Largest value an \c #uint_least24_t can hold.
    \since AVR-LibC v2.3, \ref int24 */
#define UINT_LEAST24_MAX UINT24_MAX

/** \ingroup avr_stdint
    Largest positive value an \c #int_least32_t can hold. */
#define INT_LEAST32_MAX INT32_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #int_least32_t can hold. */
#define INT_LEAST32_MIN INT32_MIN

/** \ingroup avr_stdint
    Largest value an \c #uint_least32_t can hold. */
#define UINT_LEAST32_MAX UINT32_MAX

/** \ingroup avr_stdint
    Largest positive value an \c #int_least64_t can hold. */
#define INT_LEAST64_MAX INT64_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #int_least64_t can hold. */
#define INT_LEAST64_MIN INT64_MIN

/** \ingroup avr_stdint
    Largest value an \c #uint_least64_t can hold. */
#define UINT_LEAST64_MAX UINT64_MAX

/**@}*/

/** \name Limits of fastest minimum-width integer types */

/**@{*/

/** \ingroup avr_stdint
    Largest positive value an \c #int_fast8_t can hold. */
#define INT_FAST8_MAX INT8_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #int_fast8_t can hold. */
#define INT_FAST8_MIN INT8_MIN

/** \ingroup avr_stdint
    Largest value an \c #uint_fast8_t can hold. */
#define UINT_FAST8_MAX UINT8_MAX

/** \ingroup avr_stdint
    Largest positive value an \c #int_fast16_t can hold. */
#define INT_FAST16_MAX INT16_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #int_fast16_t can hold. */
#define INT_FAST16_MIN INT16_MIN

/** \ingroup avr_stdint
    Largest value an \c #uint_fast16_t can hold. */
#define UINT_FAST16_MAX UINT16_MAX

/** \ingroup avr_stdint
    Largest positive value an \c #int_fast24_t can hold.
    \since AVR-LibC v2.3, \ref int24 */
#define INT_FAST24_MAX INT24_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #int_fast24_t can hold.
    \since AVR-LibC v2.3, \ref int24 */
#define INT_FAST24_MIN INT24_MIN

/** \ingroup avr_stdint
    Largest value an \c #uint_fast24_t can hold.
    \since AVR-LibC v2.3, \ref int24 */
#define UINT_FAST24_MAX UINT24_MAX

/** \ingroup avr_stdint
    Largest positive value an \c #int_fast32_t can hold. */
#define INT_FAST32_MAX INT32_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #int_fast32_t can hold. */
#define INT_FAST32_MIN INT32_MIN

/** \ingroup avr_stdint
    Largest value an \c #uint_fast32_t can hold. */
#define UINT_FAST32_MAX UINT32_MAX

/** \ingroup avr_stdint
    Largest positive value an \c #int_fast64_t can hold. */
#define INT_FAST64_MAX INT64_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #int_fast64_t can hold. */
#define INT_FAST64_MIN INT64_MIN

/** \ingroup avr_stdint
    Largest value an \c #uint_fast64_t can hold. */
#define UINT_FAST64_MAX UINT64_MAX

/**@}*/

/** \name Limits of integer types capable of holding object pointers */

/**@{*/

/** \ingroup avr_stdint
    Largest positive value an \c #intptr_t can hold. */
#define INTPTR_MAX INT16_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #intptr_t can hold. */
#define INTPTR_MIN INT16_MIN

/** \ingroup avr_stdint
    Largest value an \c #uintptr_t can hold. */
#define UINTPTR_MAX UINT16_MAX

/** \ingroup avr_stdint
    Largest positive value an \c #intptr24_t can hold.
    \since AVR-LibC v2.3, \ref int24 */
#define INTPTR24_MAX INT24_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #intptr24_t can hold.
    \since AVR-LibC v2.3, \ref int24 */
#define INTPTR24_MIN INT24_MIN

/** \ingroup avr_stdint
    Largest value an \c #uintptr24_t can hold.
    \since AVR-LibC v2.3, \ref int24 */
#define UINTPTR24_MAX UINT24_MAX

/**@}*/

/** \name Limits of greatest-width integer types */

/**@{*/

/** \ingroup avr_stdint
    Largest positive value an \c #intmax_t can hold. */
#define INTMAX_MAX INT64_MAX

/** \ingroup avr_stdint
    Smallest negative value an \c #intmax_t can hold. */
#define INTMAX_MIN INT64_MIN

/** \ingroup avr_stdint
    Largest value an \c #uintmax_t can hold. */
#define UINTMAX_MAX UINT64_MAX

/**@}*/

/** \name Limits of other integer types
    C++ implementations should define these macros only when
    __STDC_LIMIT_MACROS is defined before <stdint.h> is included. */

/**@{*/

/** \ingroup avr_stdint
    Largest positive value a \c ptrdiff_t can hold. */
#define PTRDIFF_MAX INT16_MAX

/** \ingroup avr_stdint
    Smallest negative value a \c ptrdiff_t can hold. */
#define PTRDIFF_MIN INT16_MIN


/* Limits of sig_atomic_t */
/* signal.h is currently not implemented (not avr/signal.h) */

/** \ingroup avr_stdint
    Largest positive value a \c sig_atomic_t can hold. */
#define SIG_ATOMIC_MAX INT8_MAX

/** \ingroup avr_stdint
    Smallest negative value a \c sig_atomic_t can hold. */
#define SIG_ATOMIC_MIN INT8_MIN


/** \ingroup avr_stdint
    Largest value a \c size_t can hold. */
#define SIZE_MAX UINT16_MAX


#ifndef __DOXYGEN__
/* Limits of wchar_t */
/* wchar.h is currently not implemented */
#ifndef WCHAR_MAX
#define WCHAR_MAX __WCHAR_MAX__
#define WCHAR_MIN __WCHAR_MIN__
#endif

/* Limits of wint_t */
/* wchar.h is currently not implemented */
#ifndef WINT_MAX
#define WINT_MAX __WINT_MAX__
#define WINT_MIN __WINT_MIN__
#endif
#endif /* !__DOXYGEN__ */


#endif /* !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) */

#if (!defined __cplusplus || __cplusplus >= 201103L \
     || defined __STDC_CONSTANT_MACROS)

/** \name Macros for integer constants
    C++ implementations should define these macros only when
    __STDC_CONSTANT_MACROS is defined before <stdint.h> is included.

    These definitions are valid for integer constants without suffix and
    for macros defined as integer constant without suffix. */

/* The GNU C preprocessor defines special macros in the implementation
   namespace to allow a definition that works in #if expressions.  */
#ifdef __INT8_C
#define INT8_C(c) __INT8_C(c)
#define INT16_C(c) __INT16_C(c)
#define INT32_C(c) __INT32_C(c)
#define INT64_C(c) __INT64_C(c)
#define UINT8_C(c) __UINT8_C(c)
#define UINT16_C(c) __UINT16_C(c)
#define UINT32_C(c) __UINT32_C(c)
#define UINT64_C(c) __UINT64_C(c)
#define INTMAX_C(c) __INTMAX_C(c)
#define UINTMAX_C(c) __UINTMAX_C(c)

#if __USING_MINT8
#define INT24_C(value) ((int24_t) __CONCAT(value, LL))
#define UINT24_C(value) ((uint24_t) __CONCAT(value, ULL))
#else
#define INT24_C(value) ((int24_t) __CONCAT(value, L))
#define UINT24_C(value) ((uint24_t) __CONCAT(value, UL))
#endif

#else
/** \ingroup avr_stdint
    Define a constant of type \c #int8_t */

#define INT8_C(value) ((int8_t) value)

/** \ingroup avr_stdint
    Define a constant of type \c #uint8_t */

#define UINT8_C(value) ((uint8_t) __CONCAT(value, U))

#if __USING_MINT8

#define INT16_C(value) __CONCAT(value, L)
#define UINT16_C(value) __CONCAT(value, UL)

#define INT32_C(value) ((int32_t) __CONCAT(value, LL))
#define UINT32_C(value) ((uint32_t) __CONCAT(value, ULL))

#else /* !__USING_MINT8 */

/** \ingroup avr_stdint
    Define a constant of type \c #int16_t */
#define INT16_C(value) value

/** \ingroup avr_stdint
    Define a constant of type \c #uint16_t */
#define UINT16_C(value) __CONCAT(value, U)

/** \ingroup avr_stdint
    Define a constant of type \c #int24_t
    \since AVR-LibC v2.3, \ref int24 */
#define INT24_C(value) ((int24_t) __CONCAT(value, L))

/** \ingroup avr_stdint
    Define a constant of type \c #uint24_t
    \since AVR-LibC v2.3, \ref int24 */
#define UINT24_C(value) ((uint24_t) __CONCAT(value, UL))

/** \ingroup avr_stdint
    Define a constant of type \c #int32_t */
#define INT32_C(value) __CONCAT(value, L)

/** \ingroup avr_stdint
    Define a constant of type \c #uint32_t */
#define UINT32_C(value) __CONCAT(value, UL)

#endif /* __USING_MINT8 */

/** \ingroup avr_stdint
    Define a constant of type \c #int64_t */
#define INT64_C(value) __CONCAT(value, LL)

/** \ingroup avr_stdint
    Define a constant of type \c #uint64_t */
#define UINT64_C(value) __CONCAT(value, ULL)

/** \ingroup avr_stdint
    Define a constant of type \c #intmax_t */
#define INTMAX_C(value) __CONCAT(value, LL)

/** \ingroup avr_stdint
    Define a constant of type \c #uintmax_t */
#define UINTMAX_C(value) __CONCAT(value, ULL)

#endif /* !__INT8_C */

/**@}*/

#endif /* (!defined __cplusplus || __cplusplus >= 201103L \
           || defined __STDC_CONSTANT_MACROS) */


#endif /* _STDINT_H_ */
