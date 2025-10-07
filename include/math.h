/* Copyright (c) 2002,2007-2009 Michael Stumpf
   Copyright (c) 2023-2025  Georg-Johann Lay

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

#ifndef __DOXYGEN__
/* If persue of old GCC versions... */
#ifndef __SIZEOF_FLOAT__
#define __SIZEOF_FLOAT__ 4
#endif
#ifndef __SIZEOF_DOUBLE__
#define __SIZEOF_DOUBLE__ 4
#endif
#ifndef __SIZEOF_LONG_DOUBLE__
#define __SIZEOF_LONG_DOUBLE__ 4
#endif
#endif /* !Doxygen */

#ifdef __cplusplus
extern "C" {
#endif

/** \file */
/** \defgroup avr_math <math.h>: Mathematics
    \code #include <math.h> \endcode

    This header file declares basic mathematics constants and
    functions.

    <b>Notes:</b>

    - Math functions do not raise exceptions and do not change the
      \c errno variable. Therefore the majority of them are declared
      with \c const attribute, for better optimization by GCC.
    - 64-bit floating-point arithmetic is only available in
      <a href="https://gcc.gnu.org/gcc-10/changes.html#avr">GCC v10</a>
      and up.
      The size of the \c double and \c long \c double type can be selected
      at compile-time with options like <tt>-mdouble=64</tt> and
      <tt>-mlong-double=32</tt>.  Whether such options are available,
      and their default values, depend on how the compiler has been configured.
    - The implementation of 64-bit floating-point arithmetic has some
      shortcomings and limitations, see the
      <a href="https://gcc.gnu.org/wiki/avr-gcc#Libf7">avr-gcc Wiki</a>
      for details.

  See also some benchmarks for \ref bench_libm "IEEE single"
  and \ref bench_libf7 "IEEE double".
*/


/** \ingroup avr_math */
/**@{*/

/** The constant Euler's number \a e. */
#define M_E 2.7182818284590452354

/** The constant logarithm of Euler's number \a e to base 2. */
#define M_LOG2E 1.4426950408889634074

/** The constant logarithm of Euler's number \a e to base 10. */
#define M_LOG10E	0.43429448190325182765

/** The constant natural logarithm of 2.	*/
#define M_LN2		0.69314718055994530942

/** The constant natural logarithm of 10.	*/
#define M_LN10		2.30258509299404568402

/** The constant &pi;.	*/
#define M_PI		3.14159265358979323846

/** The constant &pi;/2.	*/
#define M_PI_2		1.57079632679489661923

/** The constant &pi;/4.	*/
#define M_PI_4		0.78539816339744830962

/** The constant 1/&pi;.	*/
#define M_1_PI		0.31830988618379067154

/** The constant 2/&pi;.	*/
#define M_2_PI		0.63661977236758134308

/** The constant 2/sqrt(&pi;).	*/
#define M_2_SQRTPI	1.12837916709551257390

/** The square root of 2.	*/
#define M_SQRT2		1.41421356237309504880

/** The constant \a 1/sqrt(2).	*/
#define M_SQRT1_2	0.70710678118654752440

/** The \c double representation of a constant quiet NaN. */
#define NAN	__builtin_nan("")

/** The \c float representation of a constant quiet NaN.
    \p __tag is a string constant like \c "" or \c "123". */
#define nanf(__tag)	__builtin_nanf(__tag)

/** The \c double representation of a constant quiet NaN.
    \p __tag is a string constant like \c "" or \c "123". */
#define nan(__tag)	__builtin_nan(__tag)

/** The \c long \c double representation of a constant quiet NaN.
    \p __tag is a string constant like \c "" or \c "123". */
#define nanl(__tag)	__builtin_nanl(__tag)

/** \c float infinity constant.	*/
#define INFINITY __builtin_inff()

/** \c float infinity constant.	*/
#define HUGE_VALF __builtin_huge_valf()

/** \c double infinity constant.	*/
#define HUGE_VAL __builtin_huge_val()

/** \c long \c double infinity constant.	*/
#define HUGE_VALL __builtin_huge_vall()

#include <bits/attribs.h>

/** The cosf() function returns the cosine of \a x, measured in radians. */
__ATTR_CONST__ extern float cosf (float x);
/** The cos() function returns the cosine of \a x, measured in radians. */
__ATTR_CONST__ extern double cos (double x);
/** The cosl() function returns the cosine of \a x, measured in radians.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double cosl (long double x);

/** The sinf() function returns the sine of \a x, measured in radians. */
__ATTR_CONST__ extern float sinf (float x);
/** The sin() function returns the sine of \a x, measured in radians. */
__ATTR_CONST__ extern double sin (double x);
/** The sinl() function returns the sine of \a x, measured in radians.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double sinl (long double x);

/** The sincosf() function returns the sine of \a x in \c *psin, and
    the cosine of \a x in \c *pcos.  The angle \a x is measured in radians.
    A sincosf() call is a bit faster than calling sinf() and cosf()
    individually, but it consumes a bit more program memory.
    \since AVR-LibC v2.3 */
void sincosf (float x, float *psin, float *pcos);

/** The sincos() function returns the sine of \a x in \c *psin, and
    the cosine of \a x in \c *pcos.  The angle \a x is measured in radians.
    As an example, the performace gain of the IEEE double version of
    sincos() compared to a sin() plus a cos() call is around 5000 cycles
    for \a x = 2.0.
    \since GCC v15.3 (IEEE double), AVR-LibC v2.3 */
void sincos (double x, double *psin, double *pcos);

/** The sincosl() function returns the sine of \a x in \c *psin, and
    the cosine of \a x in \c *pcos.  The angle \a x is measured in radians.
    As an example, the performace gain of the IEEE double version of
    sincosl() compared to a sinl() plus a cosl() call is around 5000 cycles
    for \a x = 2.0.
    \since GCC v15.3 (IEEE double), AVR-LibC v2.3 */
void sincosl (long double x, long double *psin, long double *pcos);

/** The tanf() function returns the tangent of \a x, measured in radians. */
__ATTR_CONST__ extern float tanf (float x);
/** The tan() function returns the tangent of \a x, measured in radians. */
__ATTR_CONST__ extern double tan (double x);
/** The tanl() function returns the tangent of \a x, measured in radians.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double tanl (long double x);

/** The fabsf() function computes the absolute value of a floating-point
    number \a x. */
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
float fabsf (float __x)
{
    return __builtin_fabsf (__x);
}

/** The fabs() function computes the absolute value of a floating-point
    number \a x. */
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
double fabs (double __x)
{
    return __builtin_fabs (__x);
}

/** The fabsl() function computes the absolute value of a floating-point
    number \a x.
    \since AVR-LibC v2.2 */
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
long double fabsl (long double __x)
{
    return __builtin_fabsl (__x);
}

/** The function fmodf() returns the floating-point remainder of <em>x / y</em>. */
__ATTR_CONST__ extern float fmodf (float x, float y);
/** The function fmod() returns the floating-point remainder of <em>x / y</em>. */
__ATTR_CONST__ extern double fmod (double x, double y);
/** The function fmodl() returns the floating-point remainder of <em>x / y</em>.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double fmodl (long double x, long double y);

/** The modff() function breaks the argument \a x into integral and
    fractional parts, each of which has the same sign as the argument.
    It stores the integral part as a \c float in the object pointed to by
    \a iptr.

    The modff() function returns the signed fractional part of \a x.

    \note This implementation skips writing by zero pointer.  However,
    the GCC 4.3 can replace this function with inline code that does not
    permit to use NULL address for the avoiding of storing. */
extern float modff (float x, float *iptr);
/** The modf() function breaks the argument \a x into integral and
    fractional parts, each of which has the same sign as the argument.
    It stores the integral part as a \c double in the object pointed to by
    \a iptr.

    The modf() function returns the signed fractional part of \a x. */
extern double modf (double x, double *iptr);
/** The modfl() function breaks the argument \a x into integral and
    fractional parts, each of which has the same sign as the argument.
    It stores the integral part as a \c long \c double in the object pointed to by
    \a iptr.

    The modf() function returns the signed fractional part of \a x.
    \since AVR-LibC v2.2 */
extern long double modfl (long double x, long double *iptr);

/** The sqrtf() function returns the non-negative square root of \a x. */
__ATTR_CONST__ extern float sqrtf (float x);
/** The sqrt() function returns the non-negative square root of \a x. */
__ATTR_CONST__ extern double sqrt (double x);
/** The sqrtl() function returns the non-negative square root of \a x.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double sqrtl (long double x);

/** The cbrtf() function returns the cube root of \a x. */
__ATTR_CONST__ extern float cbrtf (float x);
/** The cbrt() function returns the cube root of \a x. */
__ATTR_CONST__ extern double cbrt (double x);
/** The cbrtl() function returns the cube root of \a x.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double cbrtl (long double x);

/** The hypotf() function returns <em>sqrtf(x*x + y*y)</em>. This
    is the length of the hypotenuse of a right triangle with sides of
    length \a x and \a y, or the  distance of the point (\a x, \a
    y) from the origin. Using this function  instead of the direct
    formula is wise, since the error is much smaller. No underflow with
    small \a x and \a y. No overflow if result is in range. */
__ATTR_CONST__ extern float hypotf (float x, float y);
/** The hypot() function returns <em>sqrt(x*x + y*y)</em>. This
    is the length of the hypotenuse of a right triangle with sides of
    length \a x and \a y, or the  distance of the point (\a x, \a
    y) from the origin. Using this function  instead of the direct
    formula is wise, since the error is much smaller. No underflow with
    small \a x and \a y. No overflow if result is in range. */
__ATTR_CONST__ extern double hypot (double x, double y);
/** The hypotl() function returns <em>sqrtl(x*x + y*y)</em>. This
    is the length of the hypotenuse of a right triangle with sides of
    length \a x and \a y, or the  distance of the point (\a x, \a
    y) from the origin. Using this function  instead of the direct
    formula is wise, since the error is much smaller. No underflow with
    small \a x and \a y. No overflow if result is in range.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double hypotl (long double x, long double y);

/** The floorf() function returns the largest integral value less than or
    equal to \a x, expressed as a floating-point number. */
__ATTR_CONST__ extern float floorf (float x);
/** The floor() function returns the largest integral value less than or
    equal to \a x, expressed as a floating-point number. */
__ATTR_CONST__ extern double floor (double x);
/** The floorl() function returns the largest integral value less than or
    equal to \a x, expressed as a floating-point number.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double floorl (long double x);

/** The ceilf() function returns the smallest integral value greater than
    or equal to \a x, expressed as a floating-point number. */
__ATTR_CONST__ extern float ceilf (float x);
/** The ceil() function returns the smallest integral value greater than
    or equal to \a x, expressed as a floating-point number. */
__ATTR_CONST__ extern double ceil (double x);
/** The ceill() function returns the smallest integral value greater than
    or equal to \a x, expressed as a floating-point number.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double ceill (long double x);

/** The frexpf() function breaks a floating-point number into a normalized
    fraction and an integral power of 2.  It stores the integer in the \c
    int object pointed to by \a pexp.

    If \a x is a normal float point number, the frexpf() function
    returns the value \c v, such that \c v has a magnitude in the
    interval [1/2, 1) or zero, and \a x equals \c v times 2 raised to
    the power \a pexp. If \a x is zero, both parts of the result are
    zero. If \a x is not a finite number, the frexpf() returns \a x as
    is and stores 0 by \a pexp.

    \note  This implementation permits a zero pointer as a directive to
    skip a storing the exponent.
 */
extern float frexpf (float x, int *pexp);
/** The frexp() function breaks a floating-point number into a normalized
    fraction and an integral power of 2.  It stores the integer in the \c
    int object pointed to by \a pexp.

    If \a x is a normal float point number, the frexp() function
    returns the value \c v, such that \c v has a magnitude in the
    interval [1/2, 1) or zero, and \a x equals \c v times 2 raised to
    the power \a pexp. If \a x is zero, both parts of the result are
    zero. If \a x is not a finite number, the frexp() returns \a x as
    is and stores 0 by \a pexp. */
extern double frexp (double x, int *pexp);
/** The frexpl() function breaks a floating-point number into a normalized
    fraction and an integral power of 2.  It stores the integer in the \c
    int object pointed to by \a pexp.

    If \a x is a normal float point number, the frexpl() function
    returns the value \c v, such that \c v has a magnitude in the
    interval [1/2, 1) or zero, and \a x equals \c v times 2 raised to
    the power \a pexp. If \a x is zero, both parts of the result are
    zero. If \a x is not a finite number, the frexpl() returns \a x as
    is and stores 0 by \a pexp.
    \since AVR-LibC v2.2 */
extern long double frexpl (long double x, int *pexp);

/** The ldexpf() function multiplies a floating-point number by an integral
    power of 2. It returns the value of \a x times 2 raised to the power
    \a iexp. */
__ATTR_CONST__ extern float ldexpf (float x, int iexp);
/** The ldexp() function multiplies a floating-point number by an integral
    power of 2. It returns the value of \a x times 2 raised to the power
    \a iexp. */
__ATTR_CONST__ extern double ldexp (double x, int iexp);
/** The ldexpl() function multiplies a floating-point number by an integral
    power of 2. It returns the value of \a x times 2 raised to the power
    \a iexp.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double ldexpl (long double x, int iexp);

/** The expf() function returns the exponential value of \a x. */
__ATTR_CONST__ extern float expf (float x);
/** The exp() function returns the exponential value of \a x. */
__ATTR_CONST__ extern double exp (double x);
/** The expl() function returns the exponential value of \a x.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double expl (long double x);

/** The coshf() function returns the hyperbolic cosine of \a x. */
__ATTR_CONST__ extern float coshf (float x);
/** The cosh() function returns the hyperbolic cosine of \a x. */
__ATTR_CONST__ extern double cosh (double x);
/** The coshl() function returns the hyperbolic cosine of \a x.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double coshl (long double x);

/** The sinhf() function returns the hyperbolic sine of \a x. */
__ATTR_CONST__ extern float sinhf (float x);
/** The sinh() function returns the hyperbolic sine of \a x. */
__ATTR_CONST__ extern double sinh (double x);
/** The sinhl() function returns the hyperbolic sine of \a x. */
__ATTR_CONST__ extern long double sinhl (long double x);

/** The tanhf() function returns the hyperbolic tangent of \a x. */
__ATTR_CONST__ extern float tanhf (float x);
/** The tanh() function returns the hyperbolic tangent of \a x. */
__ATTR_CONST__ extern double tanh (double x);
/** The tanhl() function returns the hyperbolic tangent of \a x.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double tanhl (long double x);

/** The acosf() function computes the principal value of the arc cosine of
    \a x.  The returned value is in the range [0, &pi;] radians. A domain
    error occurs for arguments not in the range [&minus;1, +1].
    The relative error is bounded by 1.9&middot;10<sup>&minus;7</sup>. */
__ATTR_CONST__ extern float acosf (float x);
/** The acos() function computes the principal value of the arc cosine of
    \a x.  The returned value is in the range [0, &pi;] radians or NaN. */
__ATTR_CONST__ extern double acos (double x);
/** The acosl() function computes the principal value of the arc cosine of
    \a x.  The returned value is in the range [0, &pi;] radians or NaN.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double acosl (long double x);

/** The asinf() function computes the principal value of the arc sine of \a x.
    The returned value is in the range [&minus;&pi;/2, &pi;/2] radians. A
    domain error occurs for arguments not in the range [&minus;1, +1].
    The relative error is bounded by 3.3&middot;10<sup>&minus;7</sup>. */
__ATTR_CONST__ extern float asinf (float x);
/** The asin() function computes the principal value of the arc sine of \a x.
    The returned value is in the range [&minus;&pi;/2, &pi;/2] radians or NaN.*/
__ATTR_CONST__ extern double asin (double x);
/** The asinl() function computes the principal value of the arc sine of \a x.
    The returned value is in the range [&minus;&pi;/2, &pi;/2] radians or NaN.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double asinl (long double x);

/** The atanf() function computes the principal value of the arc tangent
    of \a x.  The returned value is in the range [&minus;&pi;/2, &pi;/2] radians.
    The relative error is bounded by 1.3&middot;10<sup>&minus;7</sup>. */
__ATTR_CONST__ extern float atanf (float x);
/** The atan() function computes the principal value of the arc tangent of \a x.
    The returned value is in the range [&minus;&pi;/2, &pi;/2] radians. */
__ATTR_CONST__ extern double atan (double x);
/** The atanl() function computes the principal value of the arc tangent of
    \a x.  The returned value is in the range [&minus;&pi;/2, &pi;/2] radians.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double atanl (long double x);

/** The atan2f() function computes the principal value of the arc tangent
    of <em>y / x</em>, using the signs of both arguments to determine
    the quadrant of the return value.  The returned value is in the range
    [&minus;&pi;, +&pi;] radians. */
__ATTR_CONST__ extern float atan2f (float y, float x);
/** The atan2() function computes the principal value of the arc tangent
    of <em>y / x</em>, using the signs of both arguments to determine
    the quadrant of the return value.  The returned value is in the range
    [&minus;&pi;, +&pi;] radians. */
__ATTR_CONST__ extern double atan2 (double y, double x);
/** The atan2l() function computes the principal value of the arc tangent
    of <em>y / x</em>, using the signs of both arguments to determine
    the quadrant of the return value.  The returned value is in the range
    [&minus;&pi;, +&pi;] radians.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double atan2l (long double y, long double x);

/** The logf() function returns the natural logarithm of argument \a x.
    The relative error is bounded by 2.3&middot;10<sup>&minus;7</sup>. */
__ATTR_CONST__ extern float logf (float x);
/** The log() function returns the natural logarithm of argument \a x. */
__ATTR_CONST__ extern double log (double x);
/** The logl() function returns the natural logarithm of argument \a x.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double logl (long double x);

/** The log10f() function returns the logarithm of argument \a x to base 10.
    The relative error is bounded by 2.8&middot;10<sup>&minus;7</sup>. */
__ATTR_CONST__ extern float log10f (float x);
/** The log10() function returns the logarithm of argument \a x to base 10. */
__ATTR_CONST__ extern double log10 (double x);
/** The log10l() function returns the logarithm of argument \a x to base 10.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double log10l (long double x);

/** The log2f() function returns the logarithm of argument \a x to base 2.
    The relative error is bounded by 1.8&middot;10<sup>&minus;7</sup>.
    \since AVR-LibC v2.3 */
__ATTR_CONST__ extern float log2f (float x);
/** The log2() function returns the logarithm of argument \a x to base 2.
    \since AVR-LibC v2.3 */
__ATTR_CONST__ extern double log2 (double x);
/** The log2l() function returns the logarithm of argument \a x to base 2.
    \since AVR-LibC v2.3 */
__ATTR_CONST__ extern long double log2l (long double x);

/** The function powf() returns the value of \a x to the exponent \a y.
    \n Notice that for integer exponents, there is the more efficient
    <code>float __builtin_powif(float x, int y)</code>. */
__ATTR_CONST__ extern float powf (float x, float y);
/** The function pow() returns the value of \a x to the exponent \a y.
    \n Notice that for integer exponents, there is the more efficient
    <code>double __builtin_powi(double x, int y)</code>. */
__ATTR_CONST__ extern double pow (double x, double y);
/** The function powl() returns the value of \a x to the exponent \a y.
    \n Notice that for integer exponents, there is the more efficient
    <code>long double __builtin_powil(long double x, int y)</code>.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double powl (long double x, long double y);

/** The function isnanf() returns 1 if the argument \a x represents a
    "not-a-number" (NaN) object, otherwise 0. */
__ATTR_CONST__ extern int isnanf (float x);
/** The function isnan() returns 1 if the argument \a x represents a
    "not-a-number" (NaN) object, otherwise 0. */
__ATTR_CONST__ extern int isnan (double x);
/** The function isnanl() returns 1 if the argument \a x represents a
    "not-a-number" (NaN) object, otherwise 0.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern int isnanl (long double x);

/** The function isinff() returns 1 if the argument \a x is positive
    infinity, &minus;1 if \a x is negative infinity, and 0 otherwise. */
__ATTR_CONST__ extern int isinff (float x);
/** The function isinf() returns 1 if the argument \a x is positive
    infinity, &minus;1 if \a x is negative infinity, and 0 otherwise. */
__ATTR_CONST__ extern int isinf (double x);
/** The function isinfl() returns 1 if the argument \a x is positive
    infinity, &minus;1 if \a x is negative infinity, and 0 otherwise.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern int isinfl (long double x);

/** The isfinitef() function returns a nonzero value if \a __x is finite:
    not plus or minus infinity, and not NaN. */
__ATTR_CONST__ static __ATTR_ALWAYS_INLINE__ int isfinitef (float __x)
{
    unsigned char __exp;
    __asm__ (
        "mov    %0, %C1"     "\n\t"
        "lsl    %0"          "\n\t"
        "mov    %0, %D1"     "\n\t"
        "rol    %0"
        : "=&r" (__exp)
        : "r" (__x) );
    return __exp != 0xff;
}

/** The isfinite() function returns a nonzero value if \a __x is finite:
    not plus or minus infinity, and not NaN. */
#ifdef __DOXYGEN__
static __ATTR_ALWAYS_INLINE__ int isfinite (double __x);
#elif __SIZEOF_DOUBLE__ == __SIZEOF_FLOAT__
static __ATTR_ALWAYS_INLINE__ int isfinite (double __x)
{
    return isfinitef (__x);
}
#else
int isfinite (double __x);
#endif /* double = float */

/** The isfinitel() function returns a nonzero value if \a __x is finite:
    not plus or minus infinity, and not NaN.
    \since AVR-LibC v2.2 */
#ifdef __DOXYGEN__
static __ATTR_ALWAYS_INLINE__ int isfinitel (long double __x);
#elif __SIZEOF_LONG_DOUBLE__ == __SIZEOF_FLOAT__
static __ATTR_ALWAYS_INLINE__ int isfinitel (long double __x)
{
    return isfinitef (__x);
}
#else
int isfinitel (long double __x);
#endif /* long double = float */

/** The copysignf() function returns \a __x but with the sign of \a __y.
    They work even if \a __x or \a __y are NaN or zero. */
__ATTR_CONST__ static __ATTR_ALWAYS_INLINE__ float copysignf (float __x, float __y)
{
    __asm__ (
        "bst    %D2, 7"  "\n\t"
        "bld    %D0, 7"
        : "=r" (__x)
        : "0" (__x), "r" (__y));
    return __x;
}

/** The copysign() function returns \a __x but with the sign of \a __y.
    They work even if \a __x or \a __y are NaN or zero. */
__ATTR_CONST__ static __ATTR_ALWAYS_INLINE__ double copysign (double __x, double __y)
{
    __asm__ (
        "bst    %r1+%2-1, 7" "\n\t"
        "bld    %r0+%2-1, 7"
        : "+r" (__x)
        : "r" (__y), "n" (__SIZEOF_DOUBLE__));
    return __x;
}

/** The copysignl() function returns \a __x but with the sign of \a __y.
    They work even if \a __x or \a __y are NaN or zero.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ static __ATTR_ALWAYS_INLINE__ long double copysignl (long double __x, long double __y)
{
    __asm__ (
        "bst	%r1+%2-1, 7" "\n\t"
        "bld	%r0+%2-1, 7"
        : "+r" (__x)
        : "r" (__y), "n" (__SIZEOF_LONG_DOUBLE__));
    return __x;
}

/** The signbitf() function returns a nonzero value if the value of \a x
    has its sign bit set.  This is not the same as `\a x < 0.0',
    because IEEE 754 floating point allows zero to be signed. The
    comparison '&minus;0.0 < 0.0' is false, but `signbit (&minus;0.0)'
    will return a nonzero value. */
__ATTR_CONST__ extern int signbitf (float x);
/** The signbit() function returns a nonzero value if the value of \a x
    has its sign bit set.  This is not the same as `\a x < 0.0',
    because IEEE 754 floating point allows zero to be signed. The
    comparison '&minus;0.0 < 0.0' is false, but `signbit (&minus;0.0)'
    will return a nonzero value. */
__ATTR_CONST__ extern int signbit (double x);
/** The signbitl() function returns a nonzero value if the value of \a x
    has its sign bit set.  This is not the same as `\a x < 0.0',
    because IEEE 754 floating point allows zero to be signed. The
    comparison '&minus;0.0 < 0.0' is false, but `signbit (&minus;0.0)'
    will return a nonzero value.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern int signbitl (long double x);

/** The fdimf() function returns <em>max(x &minus; y, 0)</em>. If \a x or
    \a y or both are NaN, NaN is returned. */
__ATTR_CONST__ extern float fdimf (float x, float y);
/** The fdim() function returns <em>max(x &minus; y, 0)</em>. If \a x or
    \a y or both are NaN, NaN is returned. */
__ATTR_CONST__ extern double fdim (double x, double y);
/** The fdiml() function returns <em>max(x &minus; y, 0)</em>. If \a x or
    \a y or both are NaN, NaN is returned.
    \since AVR-LibC v2.2, GCC v15.2 */
__ATTR_CONST__ extern long double fdiml (long double x, long double y);

/** The fmaf() function performs floating-point multiply-add. This is the
    operation <em>(x * y) + z</em>, but the intermediate result is
    not rounded to the destination type.  This can sometimes improve the
    precision of a calculation. */
__ATTR_CONST__ extern float fmaf (float x, float y, float z);
/** The fma() function performs floating-point multiply-add. This is the
    operation <em>(x * y) + z</em>, but the intermediate result is
    not rounded to the destination type.  This can sometimes improve the
    precision of a calculation. */
__ATTR_CONST__ extern double fma (double x, double y, double z);
/** The fmal() function performs floating-point multiply-add. This is the
    operation <em>(x * y) + z</em>, but the intermediate result is
    not rounded to the destination type.  This can sometimes improve the
    precision of a calculation.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double fmal (long double x, long double y, long double z);

/** The fmaxf() function returns the greater of the two values \a x and
    \a y. If an argument is NaN, the other argument is returned. If
    both arguments are NaN, NaN is returned. */
__ATTR_CONST__ extern float fmaxf (float x, float y);
/** The fmax() function returns the greater of the two values \a x and
    \a y. If an argument is NaN, the other argument is returned. If
    both arguments are NaN, NaN is returned. */
__ATTR_CONST__ extern double fmax (double x, double y);
/** The fmaxl() function returns the greater of the two values \a x and
    \a y. If an argument is NaN, the other argument is returned. If
    both arguments are NaN, NaN is returned.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double fmaxl (long double x, long double y);

/** The fminf() function returns the lesser of the two values \a x and
    \a y. If an argument is NaN, the other argument is returned. If
    both arguments are NaN, NaN is returned. */
__ATTR_CONST__ extern float fminf (float x, float y);
/** The fmin() function returns the lesser of the two values \a x and
    \a y. If an argument is NaN, the other argument is returned. If
    both arguments are NaN, NaN is returned. */
__ATTR_CONST__ extern double fmin (double x, double y);
/** The fminl() function returns the lesser of the two values \a x and
    \a y. If an argument is NaN, the other argument is returned. If
    both arguments are NaN, NaN is returned.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double fminl (long double x, long double y);

/** The truncf() function rounds \a x to the nearest integer not larger
    in absolute value. */
__ATTR_CONST__ extern float truncf (float x);
/** The trunc() function rounds \a x to the nearest integer not larger
    in absolute value. */
__ATTR_CONST__ extern double trunc (double x);
/** The truncl() function rounds \a x to the nearest integer not larger
    in absolute value.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double truncl (long double x);

/** The roundf() function rounds \a x to the nearest integer, but rounds
    halfway cases away from zero (instead of to the nearest even integer).
    Overflow is impossible.

    \return The rounded value. If \a x is an integral or infinite, \a
    x itself is returned. If \a x is \c NaN, then \c NaN is returned. */
__ATTR_CONST__ extern float roundf (float x);
/** The round() function rounds \a x to the nearest integer, but rounds
    halfway cases away from zero (instead of to the nearest even integer).
    Overflow is impossible.

    \return The rounded value. If \a x is an integral or infinite, \a
    x itself is returned. If \a x is \c NaN, then \c NaN is returned. */
__ATTR_CONST__ extern double round (double x);
/** The roundl() function rounds \a x to the nearest integer, but rounds
    halfway cases away from zero (instead of to the nearest even integer).
    Overflow is impossible.

    \return The rounded value. If \a x is an integral or infinite, \a
    x itself is returned. If \a x is \c NaN, then \c NaN is returned.
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long double roundl (long double x);

/** The lroundf() function rounds \a x to the nearest integer, but rounds
    halfway cases away from zero (instead of to the nearest even integer).
    This function is similar to round() function, but it differs in type of
    return value and in that an overflow is possible.

    \return The rounded long integer value. If \a x is not a finite number
    or an overflow was, this realization returns the \c LONG_MIN value
    (0x80000000). */
__ATTR_CONST__ extern long lroundf (float x);
/** The lround() function rounds \a x to the nearest integer, but rounds
    halfway cases away from zero (instead of to the nearest even integer).
    This function is similar to round() function, but it differs in type of
    return value and in that an overflow is possible.

    \return The rounded long integer value. If \a x is not a finite number
    or an overflow was, this realization returns the \c LONG_MIN value
    (0x80000000). */
__ATTR_CONST__ extern long lround (double x);
/** The lroundl() function rounds \a x to the nearest integer, but rounds
    halfway cases away from zero (instead of to the nearest even integer).
    This function is similar to round() function, but it differs in type of
    return value and in that an overflow is possible.

    \return The rounded long integer value. If \a x is not a finite number
    or an overflow was, this realization returns the \c LONG_MIN value
    (0x80000000).
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long lroundl (long double x);

/** The lrintf() function rounds \a x to the nearest integer, rounding the
    halfway cases to the even integer direction. (That is both 1.5 and 2.5
    values are rounded to 2). This function is similar to rintf() function,
    but it differs in type of return value and in that an overflow is
    possible.

    \return The rounded long integer value. If \a x is not a finite
    number or an overflow was, this realization returns the \c LONG_MIN
    value (0x80000000). */
__ATTR_CONST__ extern long lrintf (float x);
/** The lrint() function rounds \a x to the nearest integer, rounding the
    halfway cases to the even integer direction. (That is both 1.5 and 2.5
    values are rounded to 2). This function is similar to rint() function,
    but it differs in type of return value and in that an overflow is
    possible.

    \return The rounded long integer value. If \a x is not a finite
    number or an overflow was, this realization returns the \c LONG_MIN
    value (0x80000000). */
__ATTR_CONST__ extern long lrint (double x);
/** The lrintl() function rounds \a x to the nearest integer, rounding the
    halfway cases to the even integer direction. (That is both 1.5 and 2.5
    values are rounded to 2). This function is similar to rintl() function,
    but it differs in type of return value and in that an overflow is
    possible.

    \return The rounded long integer value. If \a x is not a finite
    number or an overflow was, this realization returns the \c LONG_MIN
    value (0x80000000).
    \since AVR-LibC v2.2 */
__ATTR_CONST__ extern long lrintl (long double x);

/**@}*/

/**@{*/
/**
   \name Non-Standard Math Functions
*/

/** \ingroup avr_math
    The function squaref() returns <em>x * x</em>.
    \note This function does not belong to the C standard definition. */
__ATTR_CONST__ extern float squaref (float x);

/** The function square() returns <em>x * x</em>.
    \note This function does not belong to the C standard definition. */

#if defined(__DOXYGEN__) || __SIZEOF_DOUBLE__ == __SIZEOF_FLOAT__
__ATTR_CONST__ extern double square (double x);
#elif defined(__WITH_LIBF7_MATH__)
__ATTR_CONST__ extern double square (double x) __asm("__f7_square");
#endif

/** The function squarel() returns <em>x * x</em>.
    \note This function does not belong to the C standard definition.
    \since AVR-LibC v2.2 */
#if defined(__DOXYGEN__) || __SIZEOF_LONG_DOUBLE__ == __SIZEOF_FLOAT__
__ATTR_CONST__ extern long double squarel (long double x);
#elif defined(__WITH_LIBF7_MATH__)
__ATTR_CONST__ extern long double squarel (long double x) __asm("__f7_square");
#endif

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* !__MATH_H */
