/* Copyright (c) 2002,2007-2009 Michael Stumpf

   Portions of documentation Copyright (c) 1990 - 1994
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

/* $Id$ */

/*
   math.h - mathematical functions

   Author : Michael Stumpf
            Michael.Stumpf@t-online.de

   __ATTR_CONST__ added by marekm@linux.org.pl for functions
   that "do not examine any values except their arguments, and have
   no effects except the return value", for better optimization by gcc.
 */

#ifndef __MATH_H
#define __MATH_H

/** \file */
/** \defgroup avr_math <math.h>: Mathematics
    \code #include <math.h> \endcode

    This header file declares basic mathematics constants and
    functions.

    \par Notes:
    - In order to access the functions declared herein, it is usually
      also required to additionally link against the library \c libm.a.
      See also the related \ref faq_libm "FAQ entry".
    - Math functions do not raise exceptions and do not change the
      \c errno variable. Therefore the majority of them are declared
      with const attribute, for better optimization by GCC.	*/


/** \ingroup avr_math	*/
/*@{*/

/** The constant \a e.	*/
#define M_E		2.7182818284590452354

/** The logarithm of the \a e to base 2. */
#define M_LOG2E		1.4426950408889634074	/* log_2 e */

/** The logarithm of the \a e to base 10. */
#define M_LOG10E	0.43429448190325182765	/* log_10 e */

/** The natural logarithm of the 2.	*/
#define M_LN2		0.69314718055994530942	/* log_e 2 */

/** The natural logarithm of the 10.	*/
#define M_LN10		2.30258509299404568402	/* log_e 10 */

/** The constant \a pi.	*/
#define M_PI		3.14159265358979323846	/* pi */

/** The constant \a pi/2.	*/
#define M_PI_2		1.57079632679489661923	/* pi/2 */

/** The constant \a pi/4.	*/
#define M_PI_4		0.78539816339744830962	/* pi/4 */

/** The constant \a 1/pi.	*/
#define M_1_PI		0.31830988618379067154	/* 1/pi */

/** The constant \a 2/pi.	*/
#define M_2_PI		0.63661977236758134308	/* 2/pi */

/** The constant \a 2/sqrt(pi).	*/
#define M_2_SQRTPI	1.12837916709551257390	/* 2/sqrt(pi) */

/** The square root of 2.	*/
#define M_SQRT2		1.41421356237309504880	/* sqrt(2) */

/** The constant \a 1/sqrt(2).	*/
#define M_SQRT1_2	0.70710678118654752440	/* 1/sqrt(2) */

/** NAN constant.	*/
#define NAN	__builtin_nan("")

/** INFINITY constant.	*/
#define INFINITY	__builtin_inf()


#ifndef __ATTR_CONST__
# define __ATTR_CONST__ __attribute__((__const__))
#endif

#if __SIZEOF_DOUBLE__ == __SIZEOF_FLOAT__
/* In order to provide aliases for double functions in the case where
   double = float, use declarations with according assembler name.
   That way:
   1) We do *NOT* use macros like
         #define sin sinf
      because that would interfere with C++.  For example, if some class
      would implement a method 'sin', or if there was polymorthism for
      a function 'sin', then we would silently rename these to 'sinf'.
   2) We have proper prototypes, both for 'sin' and for 'sinf'.
   3) It is zero-overhead.  */
#define __ASM_ALIAS(x) __asm(#x)
#else
/* double != float: Provide double prototypes. */
#define __ASM_ALIAS(x) /* empty */
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
    The cosf() function returns the cosine of \a __x, measured in radians.
 */
__ATTR_CONST__ extern float cosf (float __x);
__ATTR_CONST__ extern double cos (double __x) __ASM_ALIAS(cosf);		/**< The alias for cosf().	*/

/**
    The sinf() function returns the sine of \a __x, measured in radians.
 */
__ATTR_CONST__ extern float sinf (float __x);
__ATTR_CONST__ extern double sin (double __x) __ASM_ALIAS(sinf);		/**< The alias for sinf().	*/

/**
    The tanf() function returns the tangent of \a __x, measured in radians.
 */
__ATTR_CONST__ extern float tanf (float __x);
__ATTR_CONST__ extern double tan (double __x) __ASM_ALIAS(tanf);		/**< The alias for tanf().	*/

/**
    The fabsf() function computes the absolute value of a floating-point
    number \a __x.
 */
static inline float fabsf (float __x)
{
    return __builtin_fabsf (__x);
}

static inline double fabs (double __x)
{
    return __builtin_fabs (__x);
}

/**
    The function fmodf() returns the floating-point remainder of <em>__x /
    __y</em>.
 */
__ATTR_CONST__ extern float fmodf (float __x, float __y);
__ATTR_CONST__ extern double fmod (double __x, double __y) __ASM_ALIAS(fmodf);		/**< The alias for fmodf().	*/

/**
    The modff() function breaks the argument \a __x into integral and
    fractional parts, each of which has the same sign as the argument. 
    It stores the integral part as a double in the object pointed to by
    \a __iptr.

    The modff() function returns the signed fractional part of \a __x.

    \note This implementation skips writing by zero pointer.  However,
    the GCC 4.3 can replace this function with inline code that does not
    permit to use NULL address for the avoiding of storing.
 */
extern float modff (float __x, float *__iptr);

/** An alias for modff(). */
extern double modf (double __x, double *__iptr) __ASM_ALIAS(modff);

/**
    The sqrtf() function returns the non-negative square root of \a __x.
 */
__ATTR_CONST__ extern float sqrtf (float __x);

/** An alias for sqrtf(). */
__ATTR_CONST__ extern double sqrt (double __x) __ASM_ALIAS(sqrtf);

/**
    The cbrt() function returns the cube root of \a __x.
 */
__ATTR_CONST__ extern float cbrtf (float __x);
__ATTR_CONST__ extern double cbrt (double __x) __ASM_ALIAS(cbrtf);		/**< The alias for cbrtf().	*/

/**
    The hypotf() function returns <em>sqrtf(__x*__x + __y*__y)</em>. This
    is the length of the hypotenuse of a right triangle with sides of
    length \a __x and \a __y, or the  distance of the point (\a __x, \a
    __y) from the origin. Using this function  instead of the direct
    formula is wise, since the error is much smaller. No underflow with
    small \a __x and \a __y. No overflow if result is in range.
 */
__ATTR_CONST__ extern float hypotf (float __x, float __y);
__ATTR_CONST__ extern double hypot (double __x, double __y) __ASM_ALIAS(hypotf);		/**< The alias for hypotf().	*/

/**
    The function squaref() returns <em>__x * __x</em>.

    \note This function does not belong to the C standard definition.
 */
__ATTR_CONST__ extern float squaref (float __x);
__ATTR_CONST__ extern double square (double __x) __ASM_ALIAS(squaref);		/**< The alias for squaref().	*/

/**
    The floorf() function returns the largest integral value less than or
    equal to \a __x, expressed as a floating-point number.
 */
__ATTR_CONST__ extern float floorf (float __x);
__ATTR_CONST__ extern double floor (double __x) __ASM_ALIAS(floorf);		/**< The alias for floorf().	*/

/**
    The ceilf() function returns the smallest integral value greater than
    or equal to \a __x, expressed as a floating-point number.
 */
__ATTR_CONST__ extern float ceilf (float __x);
__ATTR_CONST__ extern double ceil (double __x) __ASM_ALIAS(ceilf);		/**< The alias for ceilf().	*/

/**
    The frexpf() function breaks a floating-point number into a normalized
    fraction and an integral power of 2.  It stores the integer in the \c
    int object pointed to by \a __pexp.

    If \a __x is a normal float point number, the frexpf() function
    returns the value \c v, such that \c v has a magnitude in the
    interval [1/2, 1) or zero, and \a __x equals \c v times 2 raised to
    the power \a __pexp. If \a __x is zero, both parts of the result are
    zero. If \a __x is not a finite number, the frexpf() returns \a __x as
    is and stores 0 by \a __pexp.

    \note  This implementation permits a zero pointer as a directive to
    skip a storing the exponent.
 */
__ATTR_CONST__ extern float frexpf (float __x, int *__pexp);
__ATTR_CONST__ extern double frexp (double __x, int *__pexp) __ASM_ALIAS(frexpf);		/**< The alias for frexpf().	*/

/**
    The ldexpf() function multiplies a floating-point number by an integral
    power of 2. It returns the value of \a __x times 2 raised to the power
    \a __exp.
 */
__ATTR_CONST__ extern float ldexpf (float __x, int __exp);
__ATTR_CONST__ extern double ldexp (double __x, int __exp) __ASM_ALIAS(ldexpf);		/**< The alias for ldexpf().	*/

/**
    The expf() function returns the exponential value of \a __x.
 */
__ATTR_CONST__ extern float expf (float __x);
__ATTR_CONST__ extern double exp (double __x) __ASM_ALIAS(expf);		/**< The alias for expf().	*/

/**
    The coshf() function returns the hyperbolic cosine of \a __x.
 */
__ATTR_CONST__ extern float coshf (float __x);
__ATTR_CONST__ extern double cosh (double __x) __ASM_ALIAS(coshf);		/**< The alias for coshf().	*/

/**
    The sinhf() function returns the hyperbolic sine of \a __x.
 */
__ATTR_CONST__ extern float sinhf (float __x);
__ATTR_CONST__ extern double sinh (double __x) __ASM_ALIAS(sinhf);		/**< The alias for sinhf().	*/

/**
    The tanhf() function returns the hyperbolic tangent of \a __x.
 */
__ATTR_CONST__ extern float tanhf (float __x);
__ATTR_CONST__ extern double tanh (double __x) __ASM_ALIAS(tanhf);		/**< The alias for tanhf().	*/

/**
    The acosf() function computes the principal value of the arc cosine of
    \a __x.  The returned value is in the range [0, pi] radians. A domain
    error occurs for arguments not in the range [-1, +1].
 */
__ATTR_CONST__ extern float acosf (float __x);
__ATTR_CONST__ extern double acos (double __x) __ASM_ALIAS(acosf);		/**< The alias for acosf().	*/

/**
    The asinf() function computes the principal value of the arc sine of
    \a __x.  The returned value is in the range [-pi/2, pi/2] radians. A
    domain error occurs for arguments not in the range [-1, +1].
 */
__ATTR_CONST__ extern float asinf (float __x);
__ATTR_CONST__ extern double asin (double __x) __ASM_ALIAS(asinf);		/**< The alias for asinf().	*/

/**
    The atanf() function computes the principal value of the arc tangent
    of \a __x.  The returned value is in the range [-pi/2, pi/2] radians.
 */
__ATTR_CONST__ extern float atanf (float __x);
__ATTR_CONST__ extern double atan (double __x) __ASM_ALIAS(atanf);		/**< The alias for atanf().	*/

/**
    The atan2f() function computes the principal value of the arc tangent
    of <em>__y / __x</em>, using the signs of both arguments to determine
    the quadrant of the return value.  The returned value is in the range
    [-pi, +pi] radians.
 */
__ATTR_CONST__ extern float atan2f (float __y, float __x);
__ATTR_CONST__ extern double atan2 (double __y, double __x) __ASM_ALIAS(atan2f);		/**< The alias for atan2f().	*/

/**
    The logf() function returns the natural logarithm of argument \a __x.
 */
__ATTR_CONST__ extern float logf (float __x);
__ATTR_CONST__ extern double log (double __x) __ASM_ALIAS(logf);		/**< The alias for logf().	*/

/**
    The log10f() function returns the logarithm of argument \a __x to base 10.
 */
__ATTR_CONST__ extern float log10f (float __x);
__ATTR_CONST__ extern double log10 (double __x) __ASM_ALIAS(log10f);		/**< The alias for log10f().	*/

/**
    The function powf() returns the value of \a __x to the exponent \a __y.
 */
__ATTR_CONST__ extern float powf (float __x, float __y);
__ATTR_CONST__ extern double pow (double __x, double __y) __ASM_ALIAS(powf);		/**< The alias for powf().	*/

/**
    The function isnanf() returns 1 if the argument \a __x represents a
    "not-a-number" (NaN) object, otherwise 0.
 */
__ATTR_CONST__ extern int isnanf (float __x);
__ATTR_CONST__ extern int isnan (double __x) __ASM_ALIAS(isnanf);		/**< The alias for isnanf().	*/

/**
    The function isinff() returns 1 if the argument \a __x is positive
    infinity, -1 if \a __x is negative infinity, and 0 otherwise.

    \note The GCC 4.3 can replace this function with inline code that
    returns the 1 value for both infinities (gcc bug #35509).
 */
__ATTR_CONST__ extern int isinff (float __x);
__ATTR_CONST__ extern int isinf (double __x) __ASM_ALIAS(isinff);		/**< The alias for isinff().	*/

/**
    The isfinitef() function returns a nonzero value if \a __x is finite:
    not plus or minus infinity, and not NaN.
 */
__ATTR_CONST__ static inline int isfinitef (float __x)
{
    unsigned char __exp;
    __asm__ (
	"mov	%0, %C1		\n\t"
	"lsl	%0		\n\t"
	"mov	%0, %D1		\n\t"
	"rol	%0		"
	: "=r" (__exp)
	: "r" (__x)	);
    return __exp != 0xff;
}

#if __SIZEOF_DOUBLE__ == __SIZEOF_FLOAT__
static inline int isfinite (double __x) /**< The alias for isfinitef().	*/
{
    return isfinitef (__x);
}
#endif /* double = float */

/**
    The copysignf() function returns \a __x but with the sign of \a __y.
    They work even if \a __x or \a __y are NaN or zero.
*/
__ATTR_CONST__ static inline float copysignf (float __x, float __y)
{
    __asm__ (
	"bst	%D2, 7	\n\t"
	"bld	%D0, 7	"
	: "=r" (__x)
	: "0" (__x), "r" (__y) );
    return __x;
}

__ATTR_CONST__ static inline double copysign (double __x, double __y)
{
    __asm__ (
	"bst	%r1+%2-1, 7" "\n\t"
	"bld	%r0+%2-1, 7"
	: "+r" (__x)
	: "r" (__y), "n" (__SIZEOF_DOUBLE__));
    return __x;
}

/**
    The signbitf() function returns a nonzero value if the value of \a __x
    has its sign bit set.  This is not the same as `\a __x < 0.0',
    because IEEE 754 floating point allows zero to be signed. The
    comparison `-0.0 < 0.0' is false, but `signbit (-0.0)' will return a
    nonzero value.
 */
__ATTR_CONST__ extern int signbitf (float __x);
__ATTR_CONST__ extern int signbit (double __x) __ASM_ALIAS(signbitf);	/**< The alias for signbitf().	*/

/**
    The fdimf() function returns <em>maxf(__x - __y, 0)</em>. If \a __x or
    \a __y or both are NaN, NaN is returned.
 */
__ATTR_CONST__ extern float fdimf (float __x, float __y);
__ATTR_CONST__ extern double fdim (double __x, double __y) __ASM_ALIAS(fdimf);		/**< The alias for fdimf().	*/

/**
    The fmaf() function performs floating-point multiply-add. This is the
    operation <em>(__x * __y) + __z</em>, but the intermediate result is
    not rounded to the destination type.  This can sometimes improve the
    precision of a calculation.
 */
__ATTR_CONST__ extern float fmaf (float __x, float __y, float __z);
__ATTR_CONST__ extern double fma (double __x, double __y, double __z) __ASM_ALIAS(fmaf);		/**< The alias for fmaf().	*/

/**
    The fmaxf() function returns the greater of the two values \a __x and
    \a __y. If an argument is NaN, the other argument is returned. If
    both arguments are NaN, NaN is returned.
 */
__ATTR_CONST__ extern float fmaxf (float __x, float __y);
__ATTR_CONST__ extern double fmax (double __x, double __y) __ASM_ALIAS(fmaxf);		/**< The alias for fmaxf().	*/

/**
    The fminf() function returns the lesser of the two values \a __x and
    \a __y. If an argument is NaN, the other argument is returned. If
    both arguments are NaN, NaN is returned.
 */
__ATTR_CONST__ extern float fminf (float __x, float __y);
__ATTR_CONST__ extern double fmin (double __x, double __y) __ASM_ALIAS(fminf);		/**< The alias for fminf().	*/

/**
    The truncf() function rounds \a __x to the nearest integer not larger
    in absolute value.
 */
__ATTR_CONST__ extern float truncf (float __x);
__ATTR_CONST__ extern double trunc (double __x) __ASM_ALIAS(truncf);		/**< The alias for truncf().	*/

/**
    The roundf() function rounds \a __x to the nearest integer, but rounds
    halfway cases away from zero (instead of to the nearest even integer).
    Overflow is impossible.

    \return The rounded value. If \a __x is an integral or infinite, \a
    __x itself is returned. If \a __x is \c NaN, then \c NaN is returned.
 */
__ATTR_CONST__ extern float roundf (float __x);
__ATTR_CONST__ extern double round (double __x) __ASM_ALIAS(roundf);		/**< The alias for roundf().	*/

/**
    The lroundf() function rounds \a __x to the nearest integer, but rounds
    halfway cases away from zero (instead of to the nearest even integer).
    This function is similar to roundf() function, but it differs in type of
    return value and in that an overflow is possible.

    \return The rounded long integer value. If \a __x is not a finite number
    or an overflow was, this realization returns the \c LONG_MIN value
    (0x80000000).
 */
__ATTR_CONST__ extern long lroundf (float __x);
__ATTR_CONST__ extern long lround (double __x) __ASM_ALIAS(lroundf);		/**< The alias for lroundf().	*/

/**
    The lrintf() function rounds \a __x to the nearest integer, rounding the
    halfway cases to the even integer direction. (That is both 1.5 and 2.5
    values are rounded to 2). This function is similar to rintf() function,
    but it differs in type of return value and in that an overflow is
    possible.

    \return The rounded long integer value. If \a __x is not a finite
    number or an overflow was, this realization returns the \c LONG_MIN
    value (0x80000000).
 */
__ATTR_CONST__ extern long lrintf (float __x);
__ATTR_CONST__ extern long lrint (double __x) __ASM_ALIAS(lrintf);		/**< The alias for lrintf().	*/

#ifdef __cplusplus
}
#endif

/*@}*/
#endif /* !__MATH_H */
