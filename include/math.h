/* Copyright (c) 2002,2007 Michael Stumpf

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

    \note
    In order to access the functions delcared herein, it is usually
    also required to additionally link against the library \c libm.a.
    See also the related \ref faq_libm "FAQ entry".
*/

/**
   \ingroup avr_math

   The constant \c pi. */
#define M_PI 3.141592653589793238462643

/**
   \ingroup avr_math

   The square root of 2. */
#define M_SQRT2 1.4142135623730950488016887

/**
   \ingroup avr_math

   NAN constant. */
#define NAN	__builtin_nan("")

/**
   \ingroup avr_math

   INFINITY constant. */
#define INFINITY	__builtin_inf()

#ifndef __DOXYGEN__

#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif

#endif /* !DOXYGEN */

#ifdef __cplusplus
extern "C" {
#endif

  /**
     \ingroup avr_math

     The cos() function returns the cosine of \c x, measured in
     radians.
  */
extern double cos(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The fabs() function computes the absolute value of a
     floating-point number \c x.
  */
extern double fabs(double __x) __ATTR_CONST__;
#if 0
/* fabs seems to be built in already */
extern inline double fabs( double __x )
  { double __res;
    __asm__ __volatile__ ("andi %D0,0x7F \n\t"
		: "=d" (__res) : "0" (__x) );
    return __res;
  }
#endif

  /**
     \ingroup avr_math

     The function fmod() returns the floating-point
     remainder of <tt>x / y</tt>.
  */
extern double fmod(double __x, double __y) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The modf() function breaks the argument \c value into integral and
     fractional parts, each of which has the same sign as the
     argument.  It stores the integral part as a double in the object
     pointed to by \c iptr.

     The modf() function returns the signed fractional part of \c value.
     
     \note
     This implementation skips writing by zero pointer.
  */
extern double modf(double __value, double *__iptr);

  /**
     \ingroup avr_math

     The sin() function returns the sine of \c x, measured in
     radians.
  */
extern double sin(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The sqrt() function returns the non-negative square root of \c x.
  */
extern double sqrt(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The tan() function returns the tangent of \c x, measured in
     radians.
  */
extern double tan(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The floor() function returns the largest integral value
     less than or equal to \c x, expressed as a floating-point number.
  */
extern double floor(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The ceil() function returns the smallest integral value
     greater than or equal to \c x, expressed as a floating-point number.
  */
extern double ceil(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The frexp() function breaks a floating-point number into a normalized
     fraction and an integral power of 2.  It stores the integer in the \c int
     object pointed to by \c exp.

     The frexp() function returns the value \c x, such that \c x is a double with
     magnitude in the interval [1/2, 1) or zero, and \c value equals \c x times 2
     raised to the power \c *exp.  If value is zero, both parts of the result are
     zero.
  */
extern double frexp(double __value, int *__exp);

  /**
     \ingroup avr_math

     The ldexp() function multiplies a floating-point number by an integral
     power of 2.

     The ldexp() function returns the value of \c x times 2 raised to the power
     \c exp.
  */
extern double ldexp(double __x, int __exp) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The exp() function returns the exponential value of \c x.
  */
extern double exp(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The cosh() function returns the hyperbolic cosine of \c x.
  */
extern double cosh(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The sinh() function returns the hyperbolic sine of \c x.
  */
extern double sinh(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The tanh() function returns the hyperbolic tangent of \c x.
  */
extern double tanh(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The acos() function computes the principal value of the
     arc cosine of \c x.  The returned value is in the range
     [0, pi] radians.
     A domain error occurs for arguments not in the range
     [-1, +1].
  */
extern double acos(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The asin() function computes the principal value of the
     arc sine of \c x.  The returned value is in the range
     [-pi/2, pi/2] radians.
     A domain error occurs for arguments not in the range
     [-1, +1].
  */
extern double asin(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The atan() function computes the principal value of the
     arc tangent of \c x.  The returned value is in the range
     [0, pi] radians.
     A domain error occurs for arguments not in the range
     [-1, +1].
  */
extern double atan(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math
     The atan2() function computes the principal value of the
     arc tangent of <tt>y / x</tt>, using the signs of both arguments
     to determine the quadrant of the return value.  The returned
     value is in the range [-pi, +pi] radians.
  */
extern double atan2(double __y, double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The log() function returns the natural logarithm of argument \c x.

     If the argument is less than or equal 0, a domain error will occur.
   */
extern double log(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The log10() function returns the logarithm of argument \c x to base 10.

     If the argument is less than or equal 0, a domain error will occur.
   */
extern double log10(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The function pow() returns the value of \c x to the exponent \c y.
  */
extern double pow(double __x, double __y) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The function isnan() returns 1 if the argument \c x represents a
     "not-a-number" (NaN) object, otherwise 0.
  */
extern int isnan(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The function isinf() returns 1 if the argument \c x is either
     positive or negative infinity, otherwise 0.
  */
extern int isinf(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The function square() returns <tt>x * x</tt>.

     \note
     This function does not belong to the C standard definition.
  */
extern double square(double __x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The copysign() function returns \c x but with the sign of \c y.
     They work even if \c x or \c y are NaN or zero.
 */
__ATTR_CONST__ extern inline double copysign (double x, double y)
{
    asm (
	"bst	%D2, 7	\n\t"
	"bld	%D0, 7	"
	: "=r" (x)
	: "0" (x), "r" (y) );
    return x;
}

  /**
     \ingroup avr_math

     The fdim() function returns <tt>max(x-y,0)</tt>. If \c x or \c y
     or both are NaN, NaN is returned.
  */
extern double fdim (double x, double y) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The fma() function performs floating-point multiply-add. This is
     the operation (x * y) + z, but the intermediate result is not
     rounded to the destination type.  This can sometimes improve the
     precision of a calculation.
  */
extern double fma (double x, double y, double z) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The fmax() function returns the greater of the two values \c x
     and \c y. If an argument is NaN, the other argument is returned.
     If both arguments are NaN, NaN is returned.
  */
extern double fmax (double x, double y) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The fmin() function returns the lesser of the two values \c x
     and \c y. If an argument is NaN, the other argument is returned.
     If both arguments are NaN, NaN is returned.
  */
extern double fmin (double x, double y) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The signbit() function returns a nonzero value if the value of \c x
     has its sign bit set.  This is not the same as `\c x < 0.0',
     because IEEE 754 floating point allows zero to be signed. The
     comparison `-0.0 < 0.0' is false, but `signbit (-0.0)' will return
     a nonzero value.
     
     \note
     This implementation returns -1 if sign bit is set.
  */
extern int signbit (double x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The trunc() function rounds \c x to the nearest integer not larger in
     absolute value.
  */
extern double trunc (double x) __ATTR_CONST__;

  /**
     \ingroup avr_math

     The isfinite() function returns a nonzero value if \c x is finite:
     not plus or minus infinity, and not NaN.
  */
__ATTR_CONST__ extern inline int isfinite (double x)
{
    unsigned char exp;
    asm (
	"mov	%0, %C1		\n\t"
	"lsl	%0		\n\t"
	"mov	%0, %D1		\n\t"
	"rol	%0		"
	: "=r" (exp)
	: "r" (x)	);
    return exp != 0xff;
}

  /**
     \ingroup avr_math

     The hypot() function returns 'sqrt (x*x + y*y)'. This is the length of     
     the hypotenuse of a right triangle with sides of length x and y, or
     the  distance of the point (x, y) from the origin. Using this
     function  instead of the direct formula is wise, since the error is
     much smaller. No underflow with small x and y. No overflow if
     result is in range.
  */
double hypot (double x, double y) __ATTR_CONST__;

/** \ingroup avr_math

    The round() function rounds \p x to the nearest integer, but rounds
    halfway cases away from zero (instead of to the nearest even integer).
    Overflow is impossible.

    \return The rounded value. If \p x is an integral or infinite, \p x
    itself is returned. If \p x is \c NaN, then \c NaN is returned.
 */
double round (double x) __ATTR_CONST__;

/** \ingroup avr_math

    The lround() function rounds \p x to the nearest integer, but rounds
    halfway cases away from zero (instead of to the nearest even integer).
    This function is similar to round() function, but it differs in type of
    return value and in that an overflow is possible.

    \return The rounded long integer value. If \p x is not a finite number
    or an overflow was, this realization returns the \c LONG_MIN value
    (0x80000000).
 */
long lround (double x) __ATTR_CONST__;

/** \ingroup avr_math

    The lrint() function rounds \p x to the nearest integer, rounding the
    halfway cases to the even integer direction. (That is both 1.5 and 2.5
    values are rounded to 2). This function is similar to rint() function,
    but it differs in type of return value and in that an overflow is
    possible.

    \return The rounded long integer value. If \p x is not a finite number
    or an overflow was, this realization returns the \c LONG_MIN value
    (0x80000000).
 */
long lrint (double x) __ATTR_CONST__;

#ifdef __cplusplus
}
#endif

#endif /* _MATH_H */

