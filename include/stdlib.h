/* Copyright (c) 2002, Marek Michalkiewicz
   Copyright (c) 2004,2007 Joerg Wunsch
   Copyright (c) 2025 Georg-Johann Lay

   Portions of documentation Copyright (c) 1990, 1991, 1993, 1994
   The Regents of the University of California.

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

#ifndef _STDLIB_H_
#define _STDLIB_H_ 1

#ifndef __ASSEMBLER__

#ifndef __DOXYGEN__
#define __need_NULL
#define __need_size_t
#define __need_wchar_t
#include <stddef.h>

#ifndef __ptr_t
#define __ptr_t void *
#endif
#endif /* !__DOXYGEN__ */

#ifdef __cplusplus
extern "C" {
#endif

/** \file */

/** \defgroup avr_stdlib <stdlib.h>: General utilities
    \code #include <stdlib.h> \endcode

    This file declares some basic C macros and functions as
    defined by the ISO standard, plus some AVR-specific extensions.

    For some functions, \ref bench_libc "benchmarks" are available.
*/

/** \ingroup avr_stdlib */
/**@{*/
/** Result type for function div(). */
typedef struct
{
    int quot;                   /**< The Quotient. */
    int rem;                    /**< The Remainder. */
} div_t;

/** Result type for function ldiv(). */
typedef struct
{
    long quot;                  /**< The Quotient. */
    long rem;                   /**< The Remainder. */
} ldiv_t;

/** Comparision function type for qsort() and bsearch(),
    just for convenience. */
typedef int (*__compar_fn_t)(const void *, const void *);

#ifndef __DOXYGEN__

#include <bits/attribs.h>

#endif

/** The abort() function causes abnormal program termination to occur.
    This realization disables interrupts and jumps to _exit() function
    with argument equal to 1. In the limited AVR environment, execution is
    effectively halted by entering an infinite loop. */
extern void abort(void) __ATTR_NORETURN__;


/** The abs() function computes the absolute value of the integer \c i.
   \note The abs() and labs() functions are builtins of gcc.  */
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
int abs (int __i)
{
    return __builtin_abs (__i);
}


/** The labs() function computes the absolute value of the long integer \c i.
   \note The abs() and labs() functions are builtins of gcc.  */
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
long labs(long __i)
{
    return __builtin_labs (__i);
}


/** The llabs() function computes the absolute value of the
    64-bit integer \c i.
    \since AVR-LibC v2.3 */
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
long long llabs (long long __i)
{
    if (__builtin_constant_p (__i))
    {
        return __builtin_llabs (__i);
    }
    else
    {
        register long long __r18 __asm("18") = __i;
        __asm (
#ifdef __AVR_ERRATA_SKIP_JMP_CALL__
            "tst %r0+7"       "\n\t"
            "brpl 1f"         "\n\t"
            "%~call __negdi2" "\n"
            "1:"
#else
            "sbrc %r0+7,7"    "\n\t"
            "%~call __negdi2"
#endif
            : "+r" (__r18));
        return __r18;
    }
}


/**
     The bsearch() function searches an array of \c nmemb objects, the
     initial member of which is pointed to by \c base, for a member
     that matches the object pointed to by \c key.  The size of each
     member of the array is specified by \c size.

     The contents of the array should be in ascending sorted order
     according to the comparison function referenced by \c compar.
     The \c compar routine is expected to have two arguments which
     point to the key object and to an array member, in that order,
     and should return an integer less than, equal to, or greater than
     zero if the key object is found, respectively, to be less than,
     to match, or be greater than the array member.

     The bsearch() function returns a pointer to a matching member of
     the array, or a null pointer if no match is found.  If two
     members compare as equal, which member is matched is unspecified.
*/
extern void *bsearch(const void *__key, const void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar);

/* __divmodhi4 and __divmodsi4 from libgcc.a */
/**
     The div() function computes the value \c num/denom and returns
     the quotient and remainder in a structure named \c div_t that
     contains two int members named \c quot and \c rem.
*/
extern div_t div(int __num, int __denom) __asm__("__divmodhi4") __ATTR_CONST__;
/**
     The ldiv() function computes the value \c num/denom and returns
     the quotient and remainder in a structure named \c ldiv_t that
     contains two long integer members named \c quot and \c rem.
*/
extern ldiv_t ldiv(long __num, long __denom) __asm__("__divmodsi4") __ATTR_CONST__;

/**
     The qsort() function is a modified partition-exchange sort, or
     quicksort.

     The qsort() function sorts an array of \c nmemb objects, the
     initial member of which is pointed to by \c base.  The size of
     each object is specified by \c size.  The contents of the array
     base are sorted in ascending order according to a comparison
     function pointed to by \c compar, which requires two arguments
     pointing to the objects being compared.

     The comparison function must return an integer less than, equal
     to, or greater than zero if the first argument is considered to
     be respectively less than, equal to, or greater than the second.
*/
extern void qsort(void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar);

/**
    The strtol() function converts the string in \c nptr to a long
    value.  The conversion is done according to the given base, which
    must be between 2 and 36 inclusive, or be the special value 0.

    The string may begin with an arbitrary amount of white space (as
    determined by isspace()) followed by a single optional \c '+' or \c '-'
    sign.  If \c base is zero or 16, the string may then include a
    \c "0x" or \c "0X" prefix, and the number will be read in base 16;
    otherwise, a zero base is taken as 10 (decimal) unless the next
    character is \c '0', in which case it is taken as 8 (octal).

    Similarly, prefixes \c "0b" and \c "0B" signify base 2,
    and \c "0o" and \c "0O" signify base 8.

    The remainder of the string is converted to a long value in the
    obvious manner, stopping at the first character which is not a
    valid digit in the given base.  (In bases above 10, the letter \c 'A'
    in either upper or lower case represents 10, \c 'B' represents 11,
    and so forth, with \c 'Z' representing 35.)

    If \c endptr is not NULL, strtol() stores the address of the first
    invalid character in \c *endptr.  If there were no digits at all,
    however, strtol() stores the original value of \c nptr in \c
    *endptr.  (Thus, if \c *nptr is not \c '\\0' but \c **endptr is \c '\\0'
    on return, the entire string was valid.)

    The strtol() function returns the result of the conversion, unless
    the value would underflow or overflow.  If no conversion could be
    performed, 0 is returned.  If an overflow or underflow occurs, \c
    errno is set to \ref avr_errno "ERANGE" and the function return value
    is clamped to \c LONG_MIN or \c LONG_MAX, respectively.
*/
extern long strtol(const char *__nptr, char **__endptr, int __base);

/**
    The strtoll() function converts the string in \c nptr to a long long
    value.  The conversion is done according to the given base, which
    must be between 2 and 36 inclusive, or be the special value 0.

    The string may begin with an arbitrary amount of white space (as
    determined by isspace()) followed by a single optional \c '+' or \c '-'
    sign.  If \c base is zero or 16, the string may then include a
    \c "0x" or \c "0X" prefix, and the number will be read in base 16;
    otherwise, a zero base is taken as 10 (decimal) unless the next
    character is \c '0', in which case it is taken as 8 (octal).

    Similarly, prefixes \c "0b" and \c "0B" signify base 2,
    and \c "0o" and \c "0O" signify base 8.

    The remainder of the string is converted to a long long value in the
    obvious manner, stopping at the first character which is not a
    valid digit in the given base.  (In bases above 10, the letter \c 'A'
    in either upper or lower case represents 10, \c 'B' represents 11,
    and so forth, with \c 'Z' representing 35.)

    If \c endptr is not NULL, strtoll() stores the address of the first
    invalid character in \c *endptr.  If there were no digits at all,
    however, strtoll() stores the original value of \c nptr in \c
    *endptr.  (Thus, if \c *nptr is not \c '\\0' but \c **endptr is \c '\\0'
    on return, the entire string was valid.)

    The strtoll() function returns the result of the conversion, unless
    the value would underflow or overflow.  If no conversion could be
    performed, 0 is returned.  If an overflow or underflow occurs, \c
    errno is set to \ref avr_errno "ERANGE" and the function return value
    is clamped to \c LLONG_MIN or \c LLONG_MAX, respectively.
    \since AVR-LibC v2.3
*/
extern long long strtoll(const char *__nptr, char **__endptr, int __base);

/**
    The strtoul() function converts the string in \c nptr to an
    unsigned long value.  The conversion is done according to the
    given base, which must be between 2 and 36 inclusive, or be the
    special value 0.

    The string may begin with an arbitrary amount of white space (as
    determined by isspace()) followed by a single optional \c '+' or \c '-'
    sign.  If \c base is zero or 16, the string may then include a
    \c "0x" or \c "0X" prefix, and the number will be read in base 16;
    otherwise, a zero base is taken as 10 (decimal) unless the next
    character is \c '0', in which case it is taken as 8 (octal).

    Similarly, prefixes \c "0b" and \c "0B" signify base 2,
    and \c "0o" and \c "0O" signify base 8.

    The remainder of the string is converted to an unsigned long value
    in the obvious manner, stopping at the first character which is
    not a valid digit in the given base.  (In bases above 10, the
    letter \c 'A' in either upper or lower case represents 10, \c 'B'
    represents 11, and so forth, with \c 'Z' representing 35.)

    If \c endptr is not NULL, strtoul() stores the address of the first
    invalid character in \c *endptr.  If there were no digits at all,
    however, strtoul() stores the original value of \c nptr in \c
    *endptr.  (Thus, if \c *nptr is not \c '\\0' but \c **endptr is \c '\\0'
    on return, the entire string was valid.)

    The strtoul() function returns either the result of the conversion
    or, if there was a leading minus sign, the negation of the result
    of the conversion, unless the original (non-negated) value would
    overflow; in the latter case, strtoul() returns ULONG_MAX, and \c
    errno is set to \ref avr_errno "ERANGE".  If no conversion could
    be performed, 0 is returned.
*/
extern unsigned long strtoul(const char *__nptr, char **__endptr, int __base);

/**
    The strtoull() function converts the string in \c nptr to an
    unsigned long long value.  The conversion is done according to the
    given base, which must be between 2 and 36 inclusive, or be the
    special value 0.

    The string may begin with an arbitrary amount of white space (as
    determined by isspace()) followed by a single optional \c '+' or \c '-'
    sign.  If \c base is zero or 16, the string may then include a
    \c "0x" or \c "0X" prefix, and the number will be read in base 16;
    otherwise, a zero base is taken as 10 (decimal) unless the next
    character is \c '0', in which case it is taken as 8 (octal).

    Similarly, prefixes \c "0b" and \c "0B" signify base 2,
    and \c "0o" and \c "0O" signify base 8.

    The remainder of the string is converted to an unsigned long long value
    in the obvious manner, stopping at the first character which is
    not a valid digit in the given base.  (In bases above 10, the
    letter \c 'A' in either upper or lower case represents 10, \c 'B'
    represents 11, and so forth, with \c 'Z' representing 35.)

    If \c endptr is not NULL, strtoull() stores the address of the first
    invalid character in \c *endptr.  If there were no digits at all,
    however, strtoull() stores the original value of \c nptr in \c
    *endptr.  (Thus, if \c *nptr is not \c '\\0' but \c **endptr is \c '\\0'
    on return, the entire string was valid.)

    The strtoull() function returns either the result of the conversion
    or, if there was a leading minus sign, the negation of the result
    of the conversion, unless the original (non-negated) value would
    overflow; in the latter case, strtoull() returns ULLONG_MAX, and \c
    errno is set to \ref avr_errno "ERANGE".  If no conversion could
    be performed, 0 is returned.
    \since AVR-LibC v2.3
*/
extern unsigned long long strtoull(const char *__nptr, char **__endptr, int __base);

/**
    The atol() function converts the initial portion of the string
    pointed to by \p s to long integer representation. In contrast to

        \code strtol(s, (char **)NULL, 10); \endcode

    this function does not detect overflow (\c errno is not changed and
    the result value is not predictable), uses smaller memory (flash and
    stack) and works more quickly.
*/
extern long atol(const char *__s) __ATTR_PURE__;

/**
    The atoi() function converts the initial portion of the string
    pointed to by \p s to integer representation. In contrast to

        \code (int)strtol(s, (char **)NULL, 10); \endcode

    this function does not detect overflow (\c errno is not changed and
    the result value is not predictable), uses smaller memory (flash and
    stack) and works more quickly.
*/
extern int atoi(const char *__s) __ATTR_PURE__;

/**
   The exit() function terminates the application.  Since there is no
   environment to return to, \c status is ignored, and code execution
   will eventually reach an infinite loop, thereby effectively halting
   all code processing.  Before entering the infinite loop, interrupts
   are globally disabled.

   Global destructors will be called before halting
   execution, see the \ref sec_dot_fini ".fini" sections.
*/
extern void exit(int __status) __ATTR_NORETURN__;

/**
   \anchor a_malloc
   \fn void *malloc(size_t size)
   The malloc() function allocates \c size bytes of memory.
   If malloc() fails, a NULL pointer is returned.

   Note that malloc() does \e not initialize the returned memory to
   zero bytes.  For that, see calloc().

   See the chapter about \ref malloc "malloc() usage" for implementation
   details.
*/
extern void *malloc(size_t __size) __ATTR_MALLOC__;

/**
   \anchor a_free
   The free() function makes the memory referenced by \c ptr
   available for future allocations.  The memory must have been
   allocated by a call to \ref a_malloc "malloc()",
   \ref a_realloc "realloc()", calloc() or other functions like strdup()
   or fdevopen() that allocate dynamic memory on the heap.
   If \c ptr is NULL, no action occurs.
*/
extern void free(void *__ptr);

/**
   \ref malloc_tunables "tunable" for \ref a_malloc "malloc()".
   Default value is 32 bytes.
*/
extern size_t __malloc_margin;

/**
   \ref malloc_tunables "tunable" for \ref a_malloc "malloc()".
   Default value is \ref __heap_start "__heap_start".
*/
extern char *__malloc_heap_start;

/**
   \ref malloc_tunables "tunable" for \ref a_malloc "malloc()".
   Default value is __heap_end, which is weakly defined to 0 in
   the startup code.
*/
extern char *__malloc_heap_end;

/**
   Allocate \c nele elements of \c size each.  Identical to calling
   \ref a_malloc "malloc()" using <tt>nele * size</tt> as argument
   (provided the product doesn't overflow),
   except the allocated memory will be cleared to zero.
*/
extern void *calloc(size_t __nele, size_t __size) __ATTR_MALLOC__;

/**
   \anchor a_realloc
   The realloc() function tries to change the size of the region
   allocated at \c ptr to the new \c size value.  It returns a
   pointer to the new region.  The returned pointer might be the
   same as the old pointer, or a pointer to a completely different
   region.

   The contents of the returned region up to either the old or the new
   size value (whatever is less) will be identical to the contents of
   the old region, even in case a new region had to be allocated.

   It is acceptable to pass \c ptr as NULL, in which case realloc()
   will behave identical to \ref a_malloc "malloc()".

   If the new memory cannot be allocated, realloc() returns NULL, and
   the region at \c ptr will not be changed.
*/
extern void *realloc(void *__ptr, size_t __size) __ATTR_MALLOC__;

extern float strtof(const char *__nptr, char **__endptr);

/** \ingroup avr_stdlib
    The strtod() function is similar to strtof(), except that the conversion
    result is of type \c double instead of \c float. */
extern double strtod(const char *__nptr, char **__endptr);

/** \ingroup avr_stdlib
    The strtold() function is similar to strtof(), except that the conversion
    result is of type \c long \c double instead of \c float. */
extern long double strtold(const char *__nptr, char **__endptr);

/**
   \ingroup avr_stdlib
   The atexit() function registers function \a func to be run as part of
   the \c exit() function during \ref sec_dot_fini ".fini8".
   atexit() calls \ref a_malloc "malloc()". */
extern int atexit(void (*func)(void));

/** \ingroup avr_stdlib
    \fn float atoff (const char *nptr)

    The atoff() function converts the initial portion of the string pointed
    to by \a nptr to \c float representation.

    It is equivalent to calling
    \code strtof(nptr, (char**) 0); \endcode */
extern float atoff(const char *__nptr);

/** \ingroup avr_stdlib
    \fn  double atof (const char *nptr)

    The atof() function converts the initial portion of the string pointed
    to by \a nptr to \c double representation.

    It is equivalent to calling
    \code strtod(nptr, (char**) 0); \endcode */
extern double atof(const char *__nptr);

/** \ingroup avr_stdlib
    \fn long double atofl (const char *nptr)

    The atofl() function converts the initial portion of the string pointed
    to by \a nptr to \c long \c double representation.

    It is equivalent to calling
    \code strtold(nptr, (char**) 0); \endcode */
extern long double atofl(const char *__nptr);

/**
   \ingroup avr_stdlib
    Successful termination for exit(); evaluates to 0.
*/
#define EXIT_SUCCESS 0

/**
   \ingroup avr_stdlib
    Unsuccessful termination for exit(); evaluates to a non-zero value.
*/
#define EXIT_FAILURE 1

/** Highest number that can be generated by rand(). */
#define RAND_MAX 0x7FFF

/**
     The rand() function computes a sequence of pseudo-random integers in the
     range of 0 to \c RAND_MAX (as defined by the header file <stdlib.h>).

     The srand() function sets its argument \c seed as the seed for a new
     sequence of pseudo-random numbers to be returned by rand().  These
     sequences are repeatable by calling srand() with the same seed value.

     If no seed value is provided, the functions are automatically seeded with
     a value of 1.

     In compliance with the C standard, these functions operate on
     \c int arguments.  Since the underlying algorithm already uses
     32-bit calculations, this causes a loss of precision.  See
     \c random() for an alternate set of functions that retains full
     32-bit precision.
*/
extern int rand(void);
/**
   Pseudo-random number generator seeding; see rand().
*/
extern void srand(unsigned int __seed);

/**
   Variant of rand() that stores the context in the user-supplied
   variable located at \c ctx instead of a static library variable
   so the function becomes re-entrant.
*/
extern int rand_r(unsigned long *__ctx);
/**@}*/

/**@{*/
/** \name Non-standard (i.e. non-ISO C) functions.
 \ingroup avr_stdlib
*/
/**
   \brief Convert an integer to a string.

   The function itoa() converts the integer value from \c val into an
   ASCII representation that will be stored under \c s.  The caller
   is responsible for providing sufficient storage in \c s.

   \note The minimal size of the buffer \c s depends on the choice of
   radix. For example, if the radix is 2 (binary), you need to supply a buffer
   with a minimal length of 8 * sizeof (int) + 1 characters, i.e. one
   character for each bit plus one for the string terminator. Using a larger
   radix will require a smaller minimal buffer size.

   \warning If the buffer is too small, you risk a buffer overflow.

   Conversion is done using the \c radix as base, which may be a
   number between 2 (binary conversion) and up to 36.  If \c radix
   is greater than 10, the next digit after \c '9' will be the letter
   \c 'a'.

    If radix is 10 and val is negative, a minus sign will be prepended.

   The itoa() function returns the pointer passed as \c s.

   \note Decimal conversions can be sped up by using the ktoa() function
   from \ref avr_stdfix "<stdfix.h>" that converts fixed-point values to
   decimal ASCII, like in <code>ktoa((accum) val, s, FXTOA_TRUNC)</code>
   that converts \c val to a decimal ASCII representation with zero
   fractional digits.  For example, converting 1000 using itoa() takes
   around 700 cycles whereas ktoa() does the job in less than 300 cycles.
*/
#ifdef  __DOXYGEN__
extern char *itoa(int val, char *s, int radix);
#else
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
char *itoa (int __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix))
    {
        extern char *__itoa (int, char *, int);
        return __itoa (__val, __s, __radix);
    }
    else if (__radix < 2 || __radix > 36)
    {
        *__s = 0;
        return __s;
    }
    else
    {
        extern char *__itoa_ncheck (int, char *, unsigned char);
        return __itoa_ncheck (__val, __s, __radix);
    }
}
#endif

/**
 \ingroup avr_stdlib

   \brief Convert a long integer to a string.

   The function ltoa() converts the long integer value from \c val into an
   ASCII representation that will be stored under \c s.  The caller
   is responsible for providing sufficient storage in \c s.

   \note The minimal size of the buffer \c s depends on the choice of
   radix. For example, if the radix is 2 (binary), you need to supply a buffer
   with a minimal length of 8 * sizeof (long int) + 1 characters, i.e. one
   character for each bit plus one for the string terminator. Using a larger
   radix will require a smaller minimal buffer size.

   \warning If the buffer is too small, you risk a buffer overflow.

   Conversion is done using the \c radix as base, which may be a
   number between 2 (binary conversion) and up to 36.  If \c radix
   is greater than 10, the next digit after \c '9' will be the letter
   \c 'a'.

   If radix is 10 and val is negative, a minus sign will be prepended.

   The ltoa() function returns the pointer passed as \c s.
*/
#ifdef  __DOXYGEN__
extern char *ltoa(long val, char *s, int radix);
#else
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
char *ltoa (long __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix))
    {
        extern char *__ltoa (long, char *, int);
        return __ltoa (__val, __s, __radix);
    }
    else if (__radix < 2 || __radix > 36)
    {
        *__s = 0;
        return __s;
    }
    else
    {
        extern char *__ltoa_ncheck (long, char *, unsigned char);
        return __ltoa_ncheck (__val, __s, __radix);
    }
}
#endif

/**
 \ingroup avr_stdlib

   \brief Convert an unsigned integer to a string.

   The function utoa() converts the unsigned integer value from \c val into an
   ASCII representation that will be stored under \c s.  The caller
   is responsible for providing sufficient storage in \c s.

   \note The minimal size of the buffer \c s depends on the choice of
   radix. For example, if the radix is 2 (binary), you need to supply a buffer
   with a minimal length of 8 * sizeof (unsigned int) + 1 characters, i.e. one
   character for each bit plus one for the string terminator. Using a larger
   radix will require a smaller minimal buffer size.

   \warning If the buffer is too small, you risk a buffer overflow.

   Conversion is done using the \c radix as base, which may be a
   number between 2 (binary conversion) and up to 36.  If \c radix
   is greater than 10, the next digit after \c '9' will be the letter
   \c 'a'.

   The utoa() function returns the pointer passed as \c s.

   \note Decimal conversions can be sped up by using the uktoa() function from
   \ref avr_stdfix "<stdfix.h>" that converts fixed-point values to decimal
   ASCII, like in <code>uktoa((unsigned accum) val, s, FXTOA_TRUNC)</code>
   that converts \c val to a decimal ASCII representation with zero
   fractional digits.  For example, converting 1000 using utoa() takes
   around 700 cycles whereas uktoa() does the job in less than 300 cycles.
*/
#ifdef  __DOXYGEN__
extern char *utoa(unsigned int val, char *s, int radix);
#else
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
char *utoa (unsigned int __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix))
    {
        extern char *__utoa (unsigned int, char *, int);
        return __utoa (__val, __s, __radix);
    }
    else if (__radix < 2 || __radix > 36)
    {
        *__s = 0;
        return __s;
    }
    else
    {
        extern char *__utoa_ncheck (unsigned int, char *, unsigned char);
        return __utoa_ncheck (__val, __s, __radix);
    }
}
#endif

/**
 \ingroup avr_stdlib
   \brief Convert an unsigned long integer to a string.

   The function ultoa() converts the unsigned long integer value from
   \c val into an ASCII representation that will be stored under \c s.
   The caller is responsible for providing sufficient storage in \c s.

   \note The minimal size of the buffer \c s depends on the choice of
   radix. For example, if the radix is 2 (binary), you need to supply a buffer
   with a minimal length of 8 * sizeof (unsigned long int) + 1 characters,
   i.e. one character for each bit plus one for the string terminator. Using a
   larger radix will require a smaller minimal buffer size.

   \warning If the buffer is too small, you risk a buffer overflow.

   Conversion is done using the \c radix as base, which may be a
   number between 2 (binary conversion) and up to 36.  If \c radix
   is greater than 10, the next digit after \c '9' will be the letter
   \c 'a'.

   The ultoa() function returns the pointer passed as \c s.
*/
#ifdef  __DOXYGEN__
extern char *ultoa(unsigned long val, char *s, int radix);
#else
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
char *ultoa (unsigned long __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix))
    {
        extern char *__ultoa (unsigned long, char *, int);
        return __ultoa (__val, __s, __radix);
    }
    else if (__radix < 2 || __radix > 36)
    {
        *__s = 0;
        return __s;
    }
    else
    {
        extern char *__ultoa_ncheck (unsigned long, char *, unsigned char);
        return __ultoa_ncheck (__val, __s, __radix);
    }
}
#endif


/** \ingroup avr_stdlib
   \brief Convert an unsigned 64-bit integer to a string.

   The function ulltoa() writes the ASCII representation of
   the unsigned 64-bit integer \c val to a string starting at \c s.

   A very rough estimation of the execution time is

   {{{<i>Cycles</i> &asymp; 950 + 23*<i>N</i> + 8.3*<i>N</i><sup>2</sup>*log(<i>radix</i>) +/- 400}}}

   where <i>N</i> denotes the number of digits in the result,
   and \e log stands for the Natural Logarithm.
   This means a decimal conversion can take up to 9000 cycles,
   a hexadecimal conversions can take up to 7800 cycles,
   and a binary conversion can take more than 27000 cycles.

   \param val
   An unsigned 64-bit integral value for which the ASCII representation
   is computed.

   \param s
   The location to which the string representation should be stored.
   The caller is responsible for providing sufficient storage in \c s.
   The minimal size of the buffer \c s depends on the choice of the
   radix. For example, if the radix is 10 (decimal), the function will
   write at most 21 characters (including the terminating '\\0').

   \param radix
   The Conversion is done using the \c radix as base, which may be a number
   between 2 (binary conversion) and up to 36.  If \c radix is greater than 10,
   the next digit after \c '9' will be the letter \c 'a'.

   \return The ulltoa() function returns the pointer passed as \c s.

   \since AVR-LibC v2.3
*/
#ifdef  __DOXYGEN__
extern char* ulltoa(unsigned long long val, char *s, int radix);
#else
extern char* ulltoa(unsigned long long, char*, int) __asm("__ulltoa");
#endif /* Doxygen */

/** \ingroup avr_stdlib
   \brief Convert an unsigned 64-bit integer to a decimal string.

   The function ulltoa_base10() writes the decimal ASCII representation of
   the unsigned 64-bit integer \c val to a string starting at \c s.
   The effect is the same like for <tt>ulltoa(val, s, 10)</tt>.

   This function can be used for decimal ASCII conversions when
   ulltoa() is not fast enough.  It consumes no more than 3300 cycles
   (no more than 2800 cycles with \c MUL),
   where ulltoa() may consume up to 9000 cycles for a decimal conversion.

   \param val
   An unsigned 64-bit integral value for which the decimal ASCII
   representation is computed.

   \param s
   The location to which the string representation should be stored.
   The caller is responsible for providing sufficient storage in \c s.
   The function will write at most 21 characters (including the
   terminating '\\0').

   \return The ulltoa_base10() function returns the pointer passed as \c s.

   \since AVR-LibC v2.3
*/
#ifdef  __DOXYGEN__
extern char* ulltoa_base10(unsigned long long val, char *s);
#else
extern char* ulltoa_base10(unsigned long long, char*) __asm("__ulltoa_base10");
#endif /* Doxygen */

/** \ingroup avr_stdlib
   \brief Convert a signed 64-bit integer to a string.

   The function lltoa() writes the ASCII representation of
   the signed 64-bit integer \c val to a string starting at \c s.
   Except for decimal conversions with a negative \p val,
   the effect is the same like with \c ulltoa().

   \param val
   A signed 64-bit integral value for which the ASCII representation
   is computed.

   \param s
   The location to which the string representation should be stored.
   The caller is responsible for providing sufficient storage in \c s.
   The minimal size of the buffer \c s depends on the choice of the
   radix. For example, if the radix is 10 (decimal), the function will
   write at most 21 characters (including the terminating '\\0').

   \param radix
   The Conversion is done using the \c radix as base, which may be a number
   between 2 (binary conversion) and up to 36.  If \c radix is greater than 10,
   the next digit after \c '9' will be the letter \c 'a'.

   \return The lltoa() function returns the pointer passed as \c s.

   \since AVR-LibC v2.3
*/
#ifdef  __DOXYGEN__
extern char* lltoa(long long val, char *s, int radix);
#else
extern char* lltoa(long long, char*, int) __asm("__lltoa");
#endif /* Doxygen */

/**  \ingroup avr_stdlib
Highest number that can be generated by random(). */
#define RANDOM_MAX 0x7FFFFFFF

/**
 \ingroup avr_stdlib
     The random() function computes a sequence of pseudo-random integers in the
     range of 0 to \c RANDOM_MAX (as defined by the header file <stdlib.h>).

     The srandom() function sets its argument \c seed as the seed for a new
     sequence of pseudo-random numbers to be returned by rand().  These
     sequences are repeatable by calling srandom() with the same seed value.

     If no seed value is provided, the functions are automatically seeded with
     a value of 1.
*/
extern long random(void);
/**
 \ingroup avr_stdlib
   Pseudo-random number generator seeding; see random().
*/
extern void srandom(unsigned long __seed);

/**
 \ingroup avr_stdlib
   Variant of random() that stores the context in the user-supplied
   variable located at \c ctx instead of a static library variable
   so the function becomes re-entrant.
*/
extern long random_r(unsigned long *__ctx);

/** \ingroup avr_stdlib
    \return Returns the square root of the 16-bit value \p radic,
    rounded down to the next integral value.
 */
#ifdef __DOXYGEN__
extern unsigned char sqrtu16_floor(unsigned int radic);
#else
extern unsigned char sqrtu16_floor(unsigned) __asm("__sqrthi");
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
unsigned char sqrtu16_floor(unsigned __r)
{
  if (__builtin_constant_p (__r))
    {
      return (unsigned char) __builtin_sqrtf ((float) __r);
    }
  else
    {
      extern unsigned char __sqrthi (unsigned);
      return __sqrthi (__r);
    }
}
#endif /* Doxygen */

/** \ingroup avr_stdlib
    \return Returns the square root of the 32-bit value \p radic,
    rounded down to the next integral value.
 */
#ifdef __DOXYGEN__
extern unsigned int sqrtu32_floor(unsigned long radic);
#else
extern unsigned int sqrtu32_floor(unsigned long radic) __asm("__sqrtsi");
#endif /* Doxygen */


#endif /* __ASSEMBLER */
/**@}*/

/**@{*/
/** \name Conversion functions for double arguments. */
/** \ingroup avr_stdlib
    Bit value that can be passed in \c flags to ftostre(),
    dtostre() and ldtostre(). */
#define DTOSTR_ALWAYS_SIGN 0x01        /* put '+' or ' ' for positives */
/** \ingroup avr_stdlib
    Bit value that can be passed in \c flags to ftostre(),
    dtostre() and ldtostre(). */
#define DTOSTR_PLUS_SIGN   0x02        /* put '+' rather than ' ' */
/** \ingroup avr_stdlib
    Bit value that can be passed in \c flags to ftostre(),
    dtostre() and ldtostre(). */
#define DTOSTR_UPPERCASE   0x04        /* put 'E' rather 'e' */

#ifndef __ASSEMBLER__

/**
   \ingroup avr_stdlib
   The ftostre() function converts the \c float value passed in \c val into
   an ASCII representation that will be stored under \c s.  The caller
   is responsible for providing sufficient storage in \c s.

   Conversion is done in the format
   <tt>&quot;[-]d.ddde&plusmn;dd&quot;</tt> where there is
   one digit before the decimal-point character and the number of
   digits after it is equal to the precision \c prec; if the precision
   is zero, no decimal-point character appears.  If \c flags has the
   #DTOSTR_UPPERCASE bit set, the letter \c 'E' (rather than \c 'e' ) will be
   used to introduce the exponent.  The exponent always contains two
   digits; if the value is zero, the exponent is \c "00".

   If \c flags has the #DTOSTR_ALWAYS_SIGN bit set, a space character
   will be placed into the leading position for positive numbers.

   If \c flags has the #DTOSTR_PLUS_SIGN bit set, a plus sign will be
   used instead of a space character in this case.

   The ftostre() function returns the pointer to the converted string \c s.
*/
extern char *ftostre(float __val, char *__s, unsigned char __prec, unsigned char __flags);
/**
   \ingroup avr_stdlib
   The dtostre() function is similar to the ftostre() function, except that
   it converts a \c double value instead of a \c float value.

   dtostre() is currently only supported when \c double is a 32-bit type. */
extern char *dtostre(double __val, char *__s, unsigned char __prec, unsigned char __flags);
/**
   \ingroup avr_stdlib
   The ldtostre() function is similar to the ftostre() function, except that
   it converts a \c long \c double value instead of a \c float value.

   ldtostre() is currently only supported when \c long \c double is a
   32-bit type. */
extern char *ldtostre(long double __val, char *__s, unsigned char __prec, unsigned char __flags);

/**
   \ingroup avr_stdlib
   The ftostrf() function converts the \c float value passed in \c val into
   an ASCII representation that will be stored in \c s.  The caller
   is responsible for providing sufficient storage in \c s.

   Conversion is done in the format \c "[-]d.ddd".  The minimum field
   width of the output string (including the possible \c '.' and the possible
   sign for negative values) is given in \c width, and \c prec determines
   the number of digits after the decimal sign. \c width is signed value,
   negative for left adjustment.

   The ftostrf() function returns the pointer to the converted string \c s.
*/
extern char *ftostrf(float __val, signed char __width, unsigned char __prec, char *__s);
/**
   \ingroup avr_stdlib
   The dtostrf() function is similar to the ftostrf() function, except that
   converts a \c double value instead of a \c float value.

   ldtostre() is currently only supported when \c double is a 32-bit type. */
extern char *dtostrf(double __val, signed char __width, unsigned char __prec, char *__s);
/**
   \ingroup avr_stdlib
   The ldtostrf() function is similar to the ftostrf() function, except that
   converts a \c long \c double value instead of a \c float value.

   ldtostre() is currently only supported when \c long \c double is a
   32-bit type. */
extern char *ldtostrf(long double __val, signed char __width, unsigned char __prec, char *__s);

/**@}*/

#ifndef __DOXYGEN__
/* dummy declarations for libstdc++ compatibility */
extern int system (const char *);
extern char *getenv (const char *);
#endif /* __DOXYGEN__ */

#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLER */

#endif /* _STDLIB_H_ */
