/* Copyright (c) 2013 Joerg Wunsch
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

#ifndef _STDFIX_AVRLIBC_H
#define _STDFIX_AVRLIBC_H

/*
 * AVR-LibC addendum file for Embedded C Fixed-Point support
 *
 * See: ISO/IEC TR 18037
 * http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1169.pdf
 */

#ifndef _AVRGCC_STDFIX_H  /* Defined in stdfix.h from avr-gcc */
#warning please include <stdfix.h> directly rather than <stdfix-avrlibc.h>
#endif /* _AVRGCC_STDFIX_H */

#include <bits/attribs.h>

/** \file */
/** \defgroup avr_stdfix <stdfix.h>: ISO/IEC TR 18037 Fixed-Point Arithmetic
    \code #include <stdfix.h> \endcode

As an extension, GNU C supports fixed-point types as defined in the
N1169 draft of ISO/IEC DTR 18037.

\since <a href="https://gcc.gnu.org/gcc-4.8/changes.html#avr"
        >avr-gcc v4.8</a>

Two groups of fixed-point data types are added:
- The <em>fract types</em> and the <em>accum types</em>.
  The data value of a \e fract type has no integral part,
  hence values of a \e fract type are between &minus;1.0 and +1.0.
- The value range of an \e accum type depends on the number of integral bits
  in the data type.

<table>
<caption>Fixed-Point Type Layout</caption>
<tr><th>Const Suffix <th>Type <th>Size <th>Q-Format
<tr><td align="right"><tt>hr</tt>  <td align="right"><tt>short fract</tt> <td>1<td>s.7
<tr><td align="right"><tt>r</tt>   <td align="right"><tt>fract</tt>       <td>2<td>s.15
<tr><td align="right"><tt>lr</tt>  <td align="right"><tt>long fract</tt>  <td>4<td>s.31
<tr><td align="right"><tt>llr</tt> <td align="right"><tt>long long fract</tt> <td>8<td>s.63
<tr><td align="right"><tt>hk</tt>  <td align="right"><tt>short accum</tt> <td>2<td>s8.7
<tr><td align="right"><tt>k</tt>   <td align="right"><tt>accum</tt>       <td>4<td>s16.15
<tr><td align="right"><tt>lk</tt>  <td align="right"><tt>long accum</tt>  <td>8<td>s32.31
<tr><td align="right"><tt>llk</tt> <td align="right"><tt>long long accum</tt> <td>8<td>s16.47
<tr><td align="right"><tt>uhr</tt> <td align="right"><tt>unsigned short fract</tt> <td>1<td>0.8
<tr><td align="right"><tt>ur</tt>  <td align="right"><tt>unsigned fract</tt>       <td>2<td>0.16
<tr><td align="right"><tt>ulr</tt> <td align="right"><tt>unsigned long fract</tt>  <td>4<td>0.32
<tr><td align="right"><tt>ullr</tt><td align="right"><tt>unsigned long long fract</tt><td>8<td>0.64
<tr><td align="right"><tt>uhk</tt> <td align="right"><tt>unsigned short accum</tt> <td>2<td>8.8
<tr><td align="right"><tt>uk</tt>  <td align="right"><tt>unsigned accum</tt>       <td>4<td>16.16
<tr><td align="right"><tt>ulk</tt> <td align="right"><tt>unsigned long accum</tt>  <td>8<td>32.32
<tr><td align="right"><tt>ullk</tt><td align="right"><tt>unsigned long long accum</tt> <td>8<td>16.48
</table>
\remark
  - Upper case constant suffixes are also supported.
  - The \c long \c long fixed-point types are avr-gcc extensions.
*/


/* Room for AVR-LibC specific extensions */

/* 7.18a.6.1 The fixed-point arithmetic operation support functions */

#ifdef __cplusplus
extern "C" {
#endif


/** \name Absolute Value */

#ifdef __DOXYGEN__

/** \ingroup avr_stdfix
    Computes the absolute value of \p val.  When the result does not
    fit into the range of the return type, the result is saturated.  */
short fract abshr (short fract val);

/** \ingroup avr_stdfix
    Computes the absolute value of \p val.  When the result does not
    fit into the range of the return type, the result is saturated.  */
fract absr (fract val);

/** \ingroup avr_stdfix
    Computes the absolute value of \p val.  When the result does not
    fit into the range of the return type, the result is saturated.  */
long fract abslr (long fract val);

/** \ingroup avr_stdfix
    Computes the absolute value of \p val.  When the result does not
    fit into the range of the return type, the result is saturated.  */
long long fract absllr (long long fract val);

/** \ingroup avr_stdfix
    Computes the absolute value of \p val.  When the result does not
    fit into the range of the return type, the result is saturated.  */
short accum abshk (short accum val);

/** \ingroup avr_stdfix
    Computes the absolute value of \p val.  When the result does not
    fit into the range of the return type, the result is saturated.  */
accum absk (accum val);

/** \ingroup avr_stdfix
    Computes the absolute value of \p val.  When the result does not
    fit into the range of the return type, the result is saturated.  */
long accum abslk (long accum val);

/** \ingroup avr_stdfix
    Computes the absolute value of \p val.  When the result does not
    fit into the range of the return type, the result is saturated.  */
long long accum absllk (long long accum val);


/** \name Bit-Conversions to Integer */

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
signed char bitshr (short fract val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned char bitsuhr (unsigned short fract val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
int bitsr (fract val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned int bitsur (unsigned fract val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
long bitslr (long fract val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned long bitsulr (unsigned long fract val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
long long bitsllr (long long fract val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned long long bitsullr (unsigned long long fract val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
int bitshk (short accum val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned int bitsuhk (unsigned short accum val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
long bitsk (accum val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned long bitsuk (unsigned accum val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
long long bitslk (long accum val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned long long bitsulk (unsigned long accum val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
long long bitsllk (long long accum val);

/** \ingroup avr_stdfix
    Return an integer value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned long long bitsullk (unsigned long long accum val);


/** \name Bit-Conversions to Fixed-Point */

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
short fract hrbits (signed char val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned short fract uhrbits (unsigned char val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
fract rbits (int val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned fract urbits (unsigned int val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
long fract lrbits (long val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned long fract ulrbits (unsigned long val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
long long fract llrbits (long long val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned long long fract ullrbits (unsigned long long val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
short accum hkbits (int val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned short accum uhkbits (unsigned int val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
accum kbits (long val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned accum ukbits (unsigned long val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
long accum lkbits (long long val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned long accum ulkbits (unsigned long long val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
long long accum llkbits (long long val);

/** \ingroup avr_stdfix
    Return a fixed-point value of the same size and signedness,
    and with the same bit representation like \p val.  */
unsigned long long accum ullkbits (unsigned long long val);

/** \name Count Left-Shift */

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlshr (short fract val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsuhr (unsigned short fract val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsr (fract val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsur (unsigned fract val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlslr (long fract val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsulr (unsigned long fract val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsllr (long long fract val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsullr (unsigned long long fract val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlshk (short accum val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsuhk (unsigned short accum val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsk (accum val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsuk (unsigned accum val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlslk (long accum val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsulk (unsigned long accum val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsllk (long long accum val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsullk (unsigned long long accum val);

#endif /* Doxygen */

/*
 * The functions below compute the result of the multiplication or division
 * operation on the operands with the indicated types, and return a value with
 * the indicated type.  The return value is rounded towards zero, and is
 * saturated on overflow.  If the second operand of one of the divide
 * functions is zero, the behavior is undefined.
 */

/** \name Division */

/** \ingroup avr_stdfix
    The rdivi() function computes the value \c num/denom and returns the
    result of the \c fract type.
    The return value is rounded towards zero, and is saturated on overflow.
    If \c denom is zero, the behavior is undefined.
    \since AVR-LibC v2.3
*/
__ATTR_CONST__
extern fract rdivi (int num, int denom);

/** \ingroup avr_stdfix
    The lrdivi() function computes the value of \c num/denom and returns the
    result of the long fract type.
    The return value is rounded towards zero, and is saturated on overflow.
    If \c denom is zero, the behavior is undefined.
    \since AVR-LibC v2.3
*/
__ATTR_CONST__
extern long fract lrdivi (long int num, long int denom);

/** \ingroup avr_stdfix
    The urdivi() function computes the value \c num/denom and returns the
    result of the \c unsigned \c fract type.
    The return value is rounded towards zero, and is saturated on overflow.
    If \c denom is zero, the behavior is undefined.
    \since AVR-LibC v2.3
*/
__ATTR_CONST__
extern unsigned fract urdivi (unsigned int num, unsigned int denom);

/** \ingroup avr_stdfix
    The ulrdivi() function computes the value of \c num/denom and returns the
    result of the <tt>unsigned long fract</tt> type.
    The return value is rounded towards zero, and is saturated on overflow.
    If \c denom is zero, the behavior is undefined.
    \since AVR-LibC v2.3
*/
__ATTR_CONST__
extern unsigned long fract
ulrdivi (unsigned long int num, unsigned long int denom);


/* AVR-LibC extensions for mathematical functions on fixed-point numbers. */

/* Fixed-point square roots using integer arithmetics.
 * See "Fast Integer Square Root" by Ross M. Fosler, Microchip DS91040 (2000).
 */

#ifdef __DOXYGEN__
/** \name Rounding */

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.  */
short fract roundhr (short fract val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.  */
unsigned short fract rounduhr (unsigned short fract val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.  */
fract roundr (fract val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.  */
unsigned fract roundur (unsigned fract val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.  */
long fract roundlr (long fract val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.  */
unsigned long fract roundulr (unsigned long fract val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.  */
long long fract roundllr (long long fract val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.  */
unsigned long long fract roundullr (unsigned long long fract val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>&minus;IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = &minus;1</tt> rounds to an even value.  */
short accum roundhk (short accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>&minus;IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = &minus;1</tt> rounds to an even value.  */
unsigned short accum rounduhk (unsigned short accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>&minus;IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = &minus;1</tt> rounds to an even value.  */
accum roundk (accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>&minus;IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = &minus;1</tt> rounds to an even value.  */
unsigned accum rounduk (unsigned accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>&minus;IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = &minus;1</tt> rounds to an even value.  */
long accum roundlk (long accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>&minus;IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = &minus;1</tt> rounds to an even value.  */
unsigned long accum roundulk (unsigned long accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>&minus;IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = &minus;1</tt> rounds to an even value.  */
long long accum roundllk (long long accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>&minus;IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = &minus;1</tt> rounds to an even value.  */
unsigned long long accum roundullk (unsigned long long accum val, int bit);


/** \name Square Root and Transcendental Functions */

/** \ingroup avr_stdfix
    Logarithm to base 2 of the value \p x. The returned value for \p x = 0 is -32768.

    The absolute error is bounded by 3&middot;10<sup>&minus;5</sup>&nbsp;&asymp;&nbsp;2<sup>&minus;15</sup>.
    The worst case execution time (WCET) is around 700 cycles.
    \since AVR-LibC v2.3  */
accum log2uk(unsigned accum x);

/** \ingroup avr_stdfix
    Logarithm to base 2 of the value \p x. The returned value for \p x = 0 is -128.

    The absolute error is bounded by 5.3&middot;10<sup>&minus;3</sup>&nbsp;&asymp;&nbsp;2<sup>&minus;7.5</sup>.
    The worst case execution time (WCET) is around 210 cycles.
    \since AVR-LibC v2.3  */
short accum log2uhk(unsigned short accum x);

/** \ingroup avr_stdfix
    Sine of the angle \a deg where \a deg is specified in degrees, i.e.
    in the range [0&deg;, 256&deg;).
    The returned value is in the range (&minus;1, +1), i.e. is never &minus;1.

    The absolute error is bounded by 6.5&middot;10<sup>&minus;5</sup>&nbsp;&asymp;&nbsp;2<sup>&minus;13.9</sup>.
    The worst case execution time (WCET) is around 70 cycles.
    \since AVR-LibC v2.3  */
fract sinuhk_deg(unsigned short accum deg);

/** \ingroup avr_stdfix
    Cosine of the angle \a deg where \a deg is specified in degrees, i.e.
    in the range [0&deg;, 256&deg;).
    The returned value is in the range (&minus;1, +1), i.e. is never &minus;1.

    The absolute error is bounded by 6.5&middot;10<sup>&minus;5</sup>&nbsp;&asymp;&nbsp;2<sup>&minus;13.9</sup>.
    The worst case execution time (WCET) is around 90 cycles.
    \since AVR-LibC v2.3  */
fract cosuhk_deg(unsigned short accum deg);

/** \ingroup avr_stdfix
    Square root of the value \p radic rounded down.
    \since AVR-LibC v2.3  */
short fract sqrthr(short fract radic);

/** \ingroup avr_stdfix
    Square root of the value \p radic rounded down.
    \since AVR-LibC v2.3  */
unsigned short fract sqrtuhr(unsigned short fract radic);


/** \name Type-Generic Functions */

/** \ingroup avr_stdfix
    Computes the absolute value of fixed-point value \p val.
    When the result does not fit into the range of the return type,
    the result is saturated.  */
type absfx (type val);

/** \ingroup avr_stdfix
    - If \p val is non-zero, the return value is the largest integer
    \c k for which the expression <tt>val &lt;&lt; k</tt> does not overflow.
    - If \p val is zero, an integer value is returned that is at least
    as large as <tt>N - 1</tt>, where <tt>N</tt> is the total number
    of bits of the type of the argument. */
int countlsfx (type val);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>&minus;IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = &minus;1</tt> rounds to an even value.  */
type roundfx (type val, int bit);

#else /* Doxygen */
extern short fract sqrthr(short fract) __asm__("__sqrthr") __ATTR_CONST__;
extern unsigned short fract sqrtuhr(unsigned short fract) __asm__("__sqrtuhr") __ATTR_CONST__;
extern accum log2uk(unsigned accum x) __ATTR_CONST__;
extern short accum log2uhk(unsigned short accum x) __ATTR_CONST__;

extern fract sinuhk_deg(unsigned short accum x) __ATTR_CONST__;
extern fract cosuhk_deg(unsigned short accum x) __ATTR_CONST__;
#endif /* Doxygen */

#ifdef __cplusplus
}
#endif

#endif /* _STDFIX_AVRLIBC_H */
