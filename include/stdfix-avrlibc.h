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
/** \anchor stdfix_h
    \defgroup avr_stdfix <stdfix.h>: ISO/IEC TR 18037 Fixed-Point Arithmetic
\if STDFIX_AVRLIBC_H_NOT_INCLUDED
    \code
        #include <stdfix.h>
        #include <stdfix-avrlibc.h>
    \endcode
\else
    \code
        #include <stdfix.h>
    \endcode
\endif

As an extension, GNU C supports fixed-point types as defined in the
N1169 draft of ISO/IEC DTR 18037.

\since <a href="https://gcc.gnu.org/gcc-4.8/changes.html#avr"
        >avr-gcc v4.8</a>

Two groups of fixed-point data types are added:
- The <em>fract types</em> and the <em>accum types</em>.
  The data value of a \e fract type has no integral part,
  hence values of a \e fract type are between -1.0 and +1.0.
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

See also some \ref bench_fxlib "benchmarks".
*/


/* Room for AVR-LibC specific extensions */

/* 7.18a.6.1 The fixed-point arithmetic operation support functions */

#ifdef __cplusplus
extern "C" {
#endif

/** \ingroup avr_stdfix
    Include all significant digits in the result of a
    fixed-point to decimal ASCII conversion.
    The result has no trailing zeros.

    To be used in the \a mode parameter of such a conversion.
    For details and examples, see uktoa().
    \since AVR-LibC v2.3  */
#define FXTOA_ALL   0x1f

/** \ingroup avr_stdfix
    A flag to select rounding to nearest in a fixed-point to
    decimal ASCII conversion. Rounding mode is the default,
    i.e. FXTOA_ROUND can be omitted.

    To be used in the \a mode parameter of such a conversion.
    For details and examples, see uktoa().
    \since AVR-LibC v2.3  */
#define FXTOA_ROUND 0x00

/** \ingroup avr_stdfix
    A flag to select truncation (rounding to zero) in a fixed-point to
    decimal ASCII conversion.

    To be used in the \a mode parameter of such a conversion.
    For details and examples, see uktoa().
    \since AVR-LibC v2.3  */
#define FXTOA_TRUNC 0x80

/** \ingroup avr_stdfix
    A flag to select that the result of a fixed-point to
    decimal ASCII conversion has no trailing zeros.

    To be used in the \a mode parameter of such a conversion.
    For details and examples, see uktoa().
    \since AVR-LibC v2.3  */
#define FXTOA_NTZ 0x40

/** \ingroup avr_stdfix
    The fixed-point to decimal ASCII conversion routines use a
    dot (<tt>.</tt>) for the decimal point.  This is the default, i.e.
    FXTOA_DOT can be omitted.

    For details, and examples, see uktoa().
    \since AVR-LibC v2.3  */
#define FXTOA_DOT 0x00

/** \ingroup avr_stdfix
    The fixed-point to decimal ASCII conversion routines use a
    comma (<tt>,</tt>) for the decimal point.

    For details and examples, see uktoa().
    \since AVR-LibC v2.3  */
#define FXTOA_COMMA 0x20


#ifdef __DOXYGEN__

/** \name ASCII Conversions (not in ISO/IEC TR18037) */

/** \ingroup avr_stdfix
    Convert fixed-point value \p x to a decimal ASCII representation.
    The result is written to \p buf, and the user is responsible for
    providing enough memory in \p buf.  Returns \p buf.

    For the meaning of \p mode, and for the (maximal) number of
    character written by this function, see uktoa().
    \since AVR-LibC v2.3 */
char* hktoa (short accum x, char *buf, unsigned char mode);

/** \ingroup avr_stdfix
    Convert fixed-point value \p x to a decimal ASCII representation.
    The result is written to \p buf, and the user is responsible for
    providing enough memory in \p buf.  Returns \p buf.

    For the meaning of \p mode, and for the (maximal) number of
    character written by this function, see uktoa().
    \since AVR-LibC v2.3 */
char* hrtoa (short fract x, char *buf, unsigned char mode);

/** \ingroup avr_stdfix
    Convert fixed-point value \p x to a decimal ASCII representation.
    The result is written to \p buf, and the user is responsible for
    providing enough memory in \p buf.  Returns \p buf.

    For the meaning of \p mode, and for the (maximal) number of
    character written by this function, see uktoa().
    \since AVR-LibC v2.3 */
char* ktoa (accum x, char *buf, unsigned char mode);

/** \ingroup avr_stdfix
    Convert fixed-point value \p x to a decimal ASCII representation.
    The result is written to \p buf, and the user is responsible for
    providing enough memory in \p buf.  Returns \p buf.

    For the meaning of \p mode, and for the (maximal) number of
    character written by this function, see uktoa().
    \since AVR-LibC v2.3 */
char* rtoa (fract x, char *buf, unsigned char mode);

/** \ingroup avr_stdfix
    Convert fixed-point value \p x to a decimal ASCII representation.
    The result is written to \p buf, and the user is responsible for
    providing enough memory in \p buf.  Returns \p buf.

    For the meaning of \p mode, and for the (maximal) number of
    character written by this function, see uktoa().
    \since AVR-LibC v2.3 */
char* uhktoa (unsigned short accum x, char *buf, unsigned char mode);

/** \ingroup avr_stdfix
    Convert fixed-point value \p x to a decimal ASCII representation.
    The result is written to \p buf, and the user is responsible for
    providing enough memory in \p buf.  Returns \p buf.

    For the meaning of \p mode, and for the (maximal) number of
    character written by this function, see uktoa().
    \since AVR-LibC v2.3 */
char* uhrtoa (unsigned short fract x, char *buf, unsigned char mode);

/** \ingroup avr_stdfix
    Convert fixed-point value \p x to a decimal ASCII representation.
    The result is written to \p buf, and the user is responsible for
    providing enough memory in \p buf.  Returns \p buf.

    The format of the output is controlled by the \a mode parameter.
    It is composed from the format flags below together with \a Digs,
    the number of fractional digits.
    The \p mode is the ORed result from \a Digs and a combination of
    #FXTOA_ALL, #FXTOA_ROUND or #FXTOA_TRUNC, #FXTOA_DOT or #FXTOA_COMMA,
    and #FXTOA_NTZ, like in:
    \code
        uktoa (x, buf, FXTOA_ROUND | FXTOA_NTZ | Digs);
    \endcode

    - Supported values for \a Digs are in the range 0...30.

<dl>
  <dt>#FXTOA_ALL
  <dd>Include all significant digits. \a Digs will be ignored.

  <dt>#FXTOA_ROUND
  <dd>Round to nearest for \a Digs fractional digits.
    Rounding for \a Digs &ge; 5 has no effect, i.e. for such \a Digs values
    the rounded result will be the same like the truncated result.
    Rounding mode is the default, i.e. FXTOA_ROUND can be omitted.

  <dt>#FXTOA_TRUNC
  <dd>Like FXTOA_ALL, but truncate the result (round to zero)
      after \a Digs fractional digits.

  <dt>#FXTOA_NTZ
  <dd>
    &bull;&nbsp;With FXTOA_NTZ the result has
      <b>n</b>o <b>t</b>railing <b>z</b>eros.
      When the result represents an integral value,
      then no decimal point and no fractional digits are present.<br>
    &bull;&nbsp;Without FXTOA_NTZ and with FXTOA_ROUND or FXTOA_TRUNC,
      the result has the specified number of fractional digits.<br>
    &bull;&nbsp;FXTOA_NTZ has no effect with FXTOA_ALL.<br>
    &bull;&nbsp;FXTOA_NTZ has no effect on the required buffer size.
  <dt>#FXTOA_DOT
  <dd>The decimal point is a dot (<tt>.</tt>).
      This is the default, i.e. FXTOA_DOT can be omitted.

  <dt>#FXTOA_COMMA
  <dd>The decimal point is a comma (<tt>,</tt>).
</dl>

<table>
<caption>Examples</caption>
<tr>
  <th>Value
  <th>Mode
  <th>Result
</tr>
<tr><td>1.8uk<td><tt>0</tt><td><tt>"2"</tt></tr>
<tr><td>1.8uk<td><tt>1</tt><td><tt>"1.8"</tt></tr>
<tr><td>1.8uk<td><tt>2</tt><td><tt>"1.80"</tt></tr>
<tr><td>1.8uk<td><tt>3</tt><td><tt>"1.800"</tt></tr>
<tr><td>1.8uk<td><tt>FXTOA_NTZ | 0</tt><td><tt>"2"</tt></tr>
<tr><td>1.8uk<td><tt>FXTOA_NTZ | 1</tt><td><tt>"1.8"</tt></tr>
<tr><td>1.8uk<td><tt>FXTOA_NTZ | 2</tt><td><tt>"1.8"</tt></tr>
<tr><td>1.8uk<td><tt>FXTOA_NTZ | 3</tt><td><tt>"1.8"</tt></tr>
<tr><td>1.8uk<td><tt>FXTOA_TRUNC | FXTOA_COMMA | 0</tt><td><tt>"1"</tt></tr>
<tr><td>1.8uk<td><tt>FXTOA_TRUNC | FXTOA_COMMA | 1</tt><td><tt>"1,7"</tt></tr>
<tr><td>1.8uk<td><tt>FXTOA_TRUNC | FXTOA_COMMA | 2</tt><td><tt>"1,79"</tt></tr>
<tr><td>1.8uk<td><tt>FXTOA_TRUNC | FXTOA_COMMA | 3</tt><td><tt>"1,799"</tt></tr>
<tr><td>1.8uk<td><tt>FXTOA_ALL</tt> <td><tt>"1.79998779296875"</tt></tr>
</table>

The following table helps with providing enough memory in \a buf.

Notice that the required size of \a buf is independent of #FXTOA_NTZ.
This is the case since with #FXTOA_NTZ the required buffer size may
be larger that the size of the returned string.

<table>
  <caption>Maximum Number of Bytes written to buf</caption>
  <tr>
    <th>Type
    <th>Function
    <th>FXTOA_ALL
    <th>All other Modes
    <th colspan="2">Exact Maximal Value
  </tr>
  <tr>
    <td align="right"><tt>unsigned accum</tt>
    <td align="right">#uktoa
    <td align="center">23
    <td align="center">7 + \a Digs
    <td align="center">2<sup>16</sup>-2<sup>-16</sup>
    <td>65535.9999847412109375
  <tr>
    <td align="right"><tt>accum</tt>
    <td align="right">#ktoa
    <td align="center">23
    <td align="center">8 + \a Digs
    <td align="center">2<sup>16</sup>-2<sup>-15</sup>
    <td>65535.999969482421875
  <tr>
    <td align="right"><tt>unsigned short accum</tt>
    <td align="right">#uhktoa
    <td align="center">13
    <td align="center">5 + \a Digs
    <td align="center">2<sup>8</sup>-2<sup>-8</sup>
    <td>255.99609375
  <tr>
    <td align="right"><tt>short accum</tt>
    <td align="right">#hktoa
    <td align="center">13
    <td align="center">6 + \a Digs
    <td align="center">2<sup>8</sup>-2<sup>-7</sup>
    <td>255.9921875
  <tr>
    <td align="right"><tt>unsigned fract</tt>
    <td align="right">#urtoa
    <td align="center">19
    <td align="center">3 + \a Digs
    <td align="center">1-2<sup>-16</sup>
    <td>0.9999847412109375
  <tr>
    <td align="right"><tt>fract</tt>
    <td align="right">#rtoa
    <td align="center">19
    <td align="center">4 + \a Digs
    <td align="center">1-2<sup>-15</sup>
    <td>0.999969482421875
  <tr>
    <td align="right"><tt>unsigned short fract</tt>
    <td align="right">#uhrtoa
    <td align="center">11
    <td align="center">3 + \a Digs
    <td align="center">1-2<sup>-8</sup>
    <td>0.99609375
  <tr>
    <td align="right"><tt>short fract</tt>
    <td align="right">#hrtoa
    <td align="center">11
    <td align="center">4 + \a Digs
    <td align="center">1-2<sup>-7</sup>
    <td>0.9921875
  </tr>
</table>

    \since AVR-LibC v2.3 */
char* uktoa (unsigned accum x, char *buf, unsigned char mode);

/** \ingroup avr_stdfix
    Convert fixed-point value \p x to a decimal ASCII representation.
    The result is written to \p buf, and the user is responsible for
    providing enough memory in \p buf.  Returns \p buf.

    For the meaning of \p mode, and for the (maximal) number of
    character written by this function, see uktoa().
    \since AVR-LibC v2.3 */
char* urtoa (unsigned fract x, char *buf, unsigned char mode);


/** \name Absolute Value */

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
    <tt>-IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = -1</tt> rounds to an even value.  */
short accum roundhk (short accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>-IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = -1</tt> rounds to an even value.  */
unsigned short accum rounduhk (unsigned short accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>-IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = -1</tt> rounds to an even value.  */
accum roundk (accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>-IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = -1</tt> rounds to an even value.  */
unsigned accum rounduk (unsigned accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>-IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = -1</tt> rounds to an even value.  */
long accum roundlk (long accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>-IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = -1</tt> rounds to an even value.  */
unsigned long accum roundulk (unsigned long accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>-IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = -1</tt> rounds to an even value.  */
long long accum roundllk (long long accum val, int bit);

/** \ingroup avr_stdfix
    Round \p val to \p bit fractional bits.  When the result does not
    fit into the range of the return type, the result is saturated.

    As an extension, \p bit may be in the range
    <tt>-IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = -1</tt> rounds to an even value.  */
unsigned long long accum roundullk (unsigned long long accum val, int bit);


/** \name Square Root and Transcendental Functions */

/** \ingroup avr_stdfix
    Compute the arcus cosine of \p x.
    The returned value is in the range
    {{{[0, &pi;]}}}.
    For invalid values of \p x the returned value
    is -65536 = #kbits (0x80000000).

    The absolute error is bounded by
    {{{5.5&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-14.1</sup>}}}.

    \since AVR-LibC v2.3  */
accum acosk (accum x);

/** \ingroup avr_stdfix
    Compute the arcus cosine of \p x.
    The returned value is in the range
    {{{[0, &pi;/2]}}}.
    For invalid values of \p x the returned value
    is 32768 = #ukbits (0x80000000).

    The absolute error is bounded by
    {{{4.6&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-14.4</sup>}}}.

    \since AVR-LibC v2.3  */
unsigned accum acosuk (unsigned accum x);

/** \ingroup avr_stdfix
    Compute the arcus sine of \p x.
    The returned value is in the range
    {{{[-&pi;/2, &pi;/2]}}}.
    For invalid values of \p x the returned value
    is -65536 = #kbits (0x80000000).

    The absolute error is bounded by
    {{{5.1&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-14</sup>}}}.

    \since AVR-LibC v2.3  */
accum asink (accum x);

/** \ingroup avr_stdfix
    Compute the arcus sine of \p x.
    The returned value is in the range
    {{{[0, &pi;/2]}}}.
    For invalid values of \p x the returned value
    is 32768 = #ukbits (0x80000000).

    The absolute error is bounded by
    {{{4.5&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-14.4</sup>}}}.

    \since AVR-LibC v2.3  */
unsigned accum asinuk (unsigned accum x);

/** \ingroup avr_stdfix
    Compute the arcus tangent of \p x.
    The returned value is in the range
    {{{(-&pi;/2, &pi;/2&asymp;1.5708)}}}.

    \since AVR-LibC v2.3  */
accum atank (accum x);

/** \ingroup avr_stdfix
    Compute the arcus tangent of \p x.
    The returned value is in the range
    {{{[0, &pi;/2&asymp;1.5708)}}}.

    \since AVR-LibC v2.3  */
unsigned accum atanuk (unsigned accum x);

/** \ingroup avr_stdfix
    Compute the arcus tangent of \p x.
    The returned value is in the range
    {{{[0, &pi;/4&asymp;0.7854]}}}.

    The absolute error is bounded by
    {{{2.6&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-15</sup>}}}.
    The worst case execution time (WCET) is around 210 cycles when MUL is
    available, and around  1000 cycles when MUL is not available
    (measured with avr-gcc v15).
    \since AVR-LibC v2.3  */
unsigned fract atanur (unsigned fract x);

/** \ingroup avr_stdfix
    Compute
    {{{2<sup>x</sup>}}}
    with saturation.

    The WCET is at least the one of exp2m1ur().
    \since AVR-LibC v2.3  */
accum exp2k (accum x);

/** \ingroup avr_stdfix
    Compute
    {{{2<sup>x</sup>}}}
    with saturation.

    The WCET is at least the one of exp2m1ur().
    \since AVR-LibC v2.3  */
unsigned accum exp2uk (unsigned accum x);

/** \ingroup avr_stdfix
    Compute
    {{{2<sup>x</sup>&nbsp;-&nbsp;1}}}.
    The returned value is in the range [0, 1).

    The absolute error is bounded by
    {{{2.2&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-15.4</sup>}}}.
    The worst case execution time (WCET) is around 200 cycles when MUL is
    available, and around  1000 cycles when MUL is not available
    (measured with avr-gcc v15).
    \since AVR-LibC v2.3  */
unsigned fract exp2m1ur (unsigned fract x);

/** \ingroup avr_stdfix
    Returns
    {{{log<sub>2</sub>(x)}}},
    the logarithm to base 2 of the value \p x.
    The returned value for \p x = 0 is -32768.

    The absolute error is bounded by
    {{{4.5&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-14.5</sup>}}}.
    The worst case execution time (WCET) is around 150 cycles more
    than the WCET of log21pur().
    \since AVR-LibC v2.3  */
accum log2uk(unsigned accum x);

/** \ingroup avr_stdfix
    Return
    {{{log<sub>2</sub>(x)}}},
    the logarithm to base 2 of the value \p x.
    The returned value for \p x = 0 is -128.

    The absolute error is bounded by
    {{{8&middot;10<sup>-3</sup>&nbsp;&asymp;&nbsp;2<sup>-7</sup>}}}.
    The worst case execution time (WCET) is around 60 cycles plus
    the WCET of log21puhr().
    \since AVR-LibC v2.3  */
short accum log2uhk(unsigned short accum x);

/** \ingroup avr_stdfix
    Return
    {{{log<sub>2</sub>(1 + x)}}},
    the logarithm to base 2 of the value 1 + \p x.
    The result is in the range [0, 1).

    The absolute error is bounded by
    {{{4.3&middot;10<sup>-3</sup>&nbsp;&asymp;&nbsp;2<sup>-7.5</sup>}}}.
    The worst case execution time (WCET) is around 25 cycles when MUL is
    available, and around 340 cycles when MUL is not available.
    \since AVR-LibC v2.3  */
unsigned short fract log21puhr(unsigned short fract x);

/** \ingroup avr_stdfix
    Return
    {{{log<sub>2</sub>(1 + x)}}},
    the logarithm to base 2 of the value 1 + \p x.
    The result is in the range [0, 1).

    The absolute error is bounded by
    {{{3&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-15</sup>}}}.
    The worst case execution time (WCET) is around 250 cycles when MUL is
    available, and around 1300 cycles when MUL is not available.
    \since AVR-LibC v2.3  */
unsigned fract log21pur(unsigned fract x);

/** \ingroup avr_stdfix
    Cosine of
    {{{x&middot;&pi;/2}}}
    radians.

    The absolute error is bounded by
    {{{4.6&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-14.4</sup>}}}.
    The worst case execution time (WCET) is around 300 cycles when MUL is
    available, and around 1400 cycles when MUL is not available.
    \since AVR-LibC v2.3  */
accum cospi2k(accum deg);

/** \ingroup avr_stdfix
    Sine of
    {{{x&middot;&pi;/2}}}
    radians.

    The absolute error is bounded by
    {{{4.6&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-14.4</sup>}}}.
    The worst case execution time (WCET) is around 300 cycles when MUL is
    available, and around 1400 cycles when MUL is not available.
    \since AVR-LibC v2.3  */
accum sinpi2k(accum deg);

/** \ingroup avr_stdfix
    Sine of the angle \a deg where \a deg is specified in degrees, i.e.
    in the range
    {{{[0&deg;, 256&deg;)}}}.
    The returned value is in the range (-1, +1), i.e. is never -1.

    The absolute error is bounded by
    {{{6.5&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-13.9</sup>}}}.
    The worst case execution time (WCET) is around 70 cycles.
    \since AVR-LibC v2.3  */
fract sinuhk_deg(unsigned short accum deg);

/** \ingroup avr_stdfix
    Cosine of the angle \a deg where \a deg is specified in degrees, i.e.
    in the range
    {{{[0&deg;, 256&deg;)}}}.
    The returned value is in the range (-1, +1), i.e. is never -1.

    The absolute error is bounded by
    {{{6.5&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-13.9</sup>}}}.
    The worst case execution time (WCET) is around 90 cycles.
    \since AVR-LibC v2.3  */
fract cosuhk_deg(unsigned short accum deg);

/** \ingroup avr_stdfix
    Sine of
    {{{x&middot;&pi;/2}}}
    redians.
    The returned value is in the range [0, 1).

    The absolute error is bounded by
    {{{2.9&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-15</sup>}}}.
    The worst case execution time (WCET) is around 260 cycles when MUL is
    available, and around 1400 cycles when MUL is not available.
    \since AVR-LibC v2.3  */
unsigned fract sinpi2ur(unsigned fract x);

/** \ingroup avr_stdfix
    Square root of the value \p radic rounded down.
    \since AVR-LibC v2.3  */
short fract sqrthr(short fract radic);

/** \ingroup avr_stdfix
    Square root of the value \p radic rounded down.
    The result is in the range [0, 1).

    The absolute error is in the range
    {{{[-3.9&middot;10<sup>-3</sup>&nbsp;&asymp;&nbsp;2<sup>-8</sup>, 0]}}}.
    The worst case execution time (WCET) is around 120 cycles.
    \since AVR-LibC v2.3  */
unsigned short fract sqrtuhr(unsigned short fract radic);

/** \ingroup avr_stdfix
    Square root of the value \p radic.  The result is in the range [0, 1).

    The absolute error is in the range
    {{{[-1.5&middot;10<sup>-5</sup>&nbsp;&asymp;&nbsp;2<sup>-16</sup>, 0]}}}.
    The worst case execution time (WCET) is around 320 cycles.
    \since AVR-LibC v2.3  */
unsigned fract sqrtur(unsigned fract radic);


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
    <tt>-IBIT &lt; bit &lt; FBIT</tt>.
    For example, <tt>bit = -1</tt> rounds to an even value.  */
type roundfx (type val, int bit);

#else /* Doxygen */
extern unsigned accum acosuk(unsigned accum) __ATTR_CONST__;
extern unsigned accum asinuk(unsigned accum) __ATTR_CONST__;
extern unsigned accum atanuk(unsigned accum) __ATTR_CONST__;
extern accum acosk(accum) __ATTR_CONST__;
extern accum asink(accum) __ATTR_CONST__;
extern accum atank(accum) __ATTR_CONST__;
extern unsigned fract atanur(unsigned fract) __ATTR_CONST__;

extern short fract sqrthr(short fract) __asm__("__sqrthr") __ATTR_CONST__;
extern unsigned short fract sqrtuhr(unsigned short fract) __asm__("__sqrtuhr") __ATTR_CONST__;
unsigned fract sqrtur(unsigned fract) __ATTR_CONST__;

extern unsigned short fract log21puhr(unsigned short fract) __ATTR_CONST__;
extern unsigned fract log21pur(unsigned fract) __ATTR_CONST__;
extern accum log2uk(unsigned accum) __ATTR_CONST__;
extern short accum log2uhk(unsigned short accum) __ATTR_CONST__;

extern fract sinuhk_deg(unsigned short accum) __ATTR_CONST__;
extern fract cosuhk_deg(unsigned short accum) __ATTR_CONST__;
extern unsigned fract sinpi2ur(unsigned fract) __ATTR_CONST__;
extern accum sinpi2k(accum) __ATTR_CONST__;
extern accum cospi2k(accum) __ATTR_CONST__;

extern accum exp2k (accum) __ATTR_CONST__;
extern unsigned accum exp2uk (unsigned accum) __ATTR_CONST__;
extern unsigned fract exp2m1ur (unsigned fract) __ATTR_CONST__;

extern char* uktoa (unsigned accum, char*, unsigned char);
extern char* urtoa (unsigned fract, char*, unsigned char);
extern char* ktoa (accum, char*, unsigned char);
extern char* rtoa (fract, char*, unsigned char);
extern char* uhktoa (unsigned short accum, char*, unsigned char);
extern char* uhrtoa (unsigned short fract, char*, unsigned char);
extern char* hktoa (short accum, char*, unsigned char);
extern char* hrtoa (short fract, char*, unsigned char);
#endif /* Doxygen */

#ifdef __DOXYGEN__
/** \name Functions reading from PROGMEM */

/** \ingroup avr_stdfix
    Read a <tt>short fract</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline short fract pgm_read_hr (const short fract *addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned short fract</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline unsigned short fract pgm_read_uhr (const unsigned short fract *addr);

/** \ingroup avr_stdfix
    Read a <tt>fract</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline fract pgm_read_r (const fract *addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned fract</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline unsigned fract pgm_read_ur (const unsigned fract *addr);

/** \ingroup avr_stdfix
    Read a <tt>long fract</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline long fract pgm_read_lr (const long fract *addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned long fract</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline unsigned long fract pgm_read_ulr (const unsigned long fract *addr);

/** \ingroup avr_stdfix
    Read a <tt>long long fract</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline long long fract pgm_read_llr (const long long fract *addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned long long fract</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline unsigned long long fract pgm_read_ullr (const unsigned long long fract *addr);

/** \ingroup avr_stdfix
    Read a <tt>short accum</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline short accum pgm_read_hk (const short accum *addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned short accum</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline unsigned short accum pgm_read_uhk (const unsigned short accum *addr);

/** \ingroup avr_stdfix
    Read an <tt>accum</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline accum pgm_read_k (const accum *addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned accum</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline unsigned accum pgm_read_uk (const unsigned accum *addr);

/** \ingroup avr_stdfix
    Read a <tt>long accum</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline long accum pgm_read_lk (const long accum *addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned long accum</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline unsigned long accum pgm_read_ulk (const unsigned long accum *addr);

/** \ingroup avr_stdfix
    Read a <tt>long long accum</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline long long accum pgm_read_llk (const long long accum *addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned long long accum</tt> from 16-bit address \p addr.
    The address is in the lower 64 KiB of program memory.
    \since AVR-LibC v2.3 */
static inline unsigned long long accum pgm_read_ullk (const unsigned long long accum *addr);

#else /* Doxygen */

#include <avr/pgmspace.h>

_Avrlibc_Def_Pgm_1 (hr, short fract)
_Avrlibc_Def_Pgm_1 (uhr, unsigned short fract)
_Avrlibc_Def_Pgm_2 (r, fract)
_Avrlibc_Def_Pgm_2 (ur, unsigned fract)
_Avrlibc_Def_Pgm_4 (lr, long fract)
_Avrlibc_Def_Pgm_4 (ulr, unsigned long fract)
_Avrlibc_Def_Pgm_8 (llr, long long fract)
_Avrlibc_Def_Pgm_8 (ullr, unsigned long long fract)

_Avrlibc_Def_Pgm_2 (hk, short accum)
_Avrlibc_Def_Pgm_2 (uhk, unsigned short accum)
_Avrlibc_Def_Pgm_4 (k, accum)
_Avrlibc_Def_Pgm_4 (uk, unsigned accum)
_Avrlibc_Def_Pgm_8 (lk, long accum)
_Avrlibc_Def_Pgm_8 (ulk, unsigned long accum)
_Avrlibc_Def_Pgm_8 (llk, long long accum)
_Avrlibc_Def_Pgm_8 (ullk, unsigned long long accum)
#endif /* Doxygen */

#ifdef __DOXYGEN__
/** \name Functions reading from PROGMEM_FAR */

/** \ingroup avr_stdfix
    Read a <tt>short fract</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline short fract pgm_read_hr_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned short fract</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline unsigned short fract pgm_read_uhr_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read a <tt>fract</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline fract pgm_read_r_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned fract</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline unsigned fract pgm_read_ur_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read a <tt>long fract</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline long fract pgm_read_lr_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned long fract</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline unsigned long fract pgm_read_ulr_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read a <tt>long long fract</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline long long fract pgm_read_llr_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned long long fract</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline unsigned long long fract pgm_read_ullr_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read a <tt>short accum</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline short accum pgm_read_hk_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned short accum</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline unsigned short accum pgm_read_uhk_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read an <tt>accum</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline accum pgm_read_k_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned accum</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline unsigned accum pgm_read_uk_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read a <tt>long accum</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline long accum pgm_read_lk_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned long accum</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline unsigned long accum pgm_read_ulk_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read a <tt>long long accum</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline long long accum pgm_read_llk_far (uint_farptr_t addr);

/** \ingroup avr_stdfix
    Read an <tt>unsigned long long accum</tt> from far address \p addr.
    The address is in the program memory.
    \since AVR-LibC v2.3 */
static inline unsigned long long accum pgm_read_ullk_far (uint_farptr_t addr);

#else /* Doxygen */

_Avrlibc_Def_Pgm_Far_1 (hr, short fract)
_Avrlibc_Def_Pgm_Far_1 (uhr, unsigned short fract)
_Avrlibc_Def_Pgm_Far_2 (r, fract)
_Avrlibc_Def_Pgm_Far_2 (ur, unsigned fract)
_Avrlibc_Def_Pgm_Far_4 (lr, long fract)
_Avrlibc_Def_Pgm_Far_4 (ulr, unsigned long fract)
_Avrlibc_Def_Pgm_Far_8 (llr, long long fract)
_Avrlibc_Def_Pgm_Far_8 (ullr, unsigned long long fract)

_Avrlibc_Def_Pgm_Far_2 (hk, short accum)
_Avrlibc_Def_Pgm_Far_2 (uhk, unsigned short accum)
_Avrlibc_Def_Pgm_Far_4 (k, accum)
_Avrlibc_Def_Pgm_Far_4 (uk, unsigned accum)
_Avrlibc_Def_Pgm_Far_8 (lk, long accum)
_Avrlibc_Def_Pgm_Far_8 (ulk, unsigned long accum)
_Avrlibc_Def_Pgm_Far_8 (llk, long long accum)
_Avrlibc_Def_Pgm_Far_8 (ullk, unsigned long long accum)
#endif /* Doxygen */

/** \name EEPROM Read Functions */

/** \ingroup avr_stdfix
    Read a <tt>short fract</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
short fract eeprom_read_hr (const short fract *__p) __asm("eeprom_read_byte") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read an <tt>unsigned short fract</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
unsigned short fract eeprom_read_uhr (const unsigned short fract *__p) __asm("eeprom_read_byte") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read a <tt>fract</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
fract eeprom_read_r (const fract *__p) __asm("eeprom_read_word") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read an <tt>unsigned fract</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
unsigned fract eeprom_read_ur (const unsigned fract *__p) __asm("eeprom_read_word") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read a <tt>long fract</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
long fract eeprom_read_lr (const long fract *__p) __asm("eeprom_read_dword") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read an <tt>unsigned long fract</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
unsigned long fract eeprom_read_ulr (const unsigned long fract *__p) __asm("eeprom_read_dword") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read a <tt>long long fract</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
long long fract eeprom_read_llr (const long long fract *__p) __asm("eeprom_read_qword") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read an <tt>unsigned long long fract</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
unsigned long long fract eeprom_read_ullr (const unsigned long long fract *__p) __asm("eeprom_read_qword") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read a <tt>short accum</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
short accum eeprom_read_hk (const short accum *__p) __asm("eeprom_read_word") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read an <tt>unsigned short accum</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
unsigned short accum eeprom_read_uhk (const unsigned short accum *__p) __asm("eeprom_read_word") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read an <tt>accum</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
accum eeprom_read_k (const accum *__p) __asm("eeprom_read_dword") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read an <tt>unsigned accum</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
unsigned accum eeprom_read_uk (const unsigned accum *__p) __asm("eeprom_read_dword") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read a <tt>long accum</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
long accum eeprom_read_lk (const long accum *__p) __asm("eeprom_read_qword") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read an <tt>unsigned long accum</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
unsigned long accum eeprom_read_ulk (const unsigned long accum *__p) __asm("eeprom_read_qword") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read a <tt>long long accum</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
long long accum eeprom_read_llk (const long long accum *__p) __asm("eeprom_read_qword") __ATTR_PURE__;

/** \ingroup avr_stdfix
    Read an <tt>unsigned long long accum</tt> from EEPROM address \a __p.
    \since AVR-LibC v2.3 */
unsigned long long accum eeprom_read_ullk (const unsigned long long accum *__p) __asm("eeprom_read_qword") __ATTR_PURE__;


/** \name EEPROM Write Functions */

/** \ingroup avr_stdfix
    Write a <tt>short fract</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_hr (short fract *__p, short fract __value) __asm("eeprom_write_byte");

/** \ingroup avr_stdfix
    Write an <tt>unsigned short fract</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_uhr (unsigned short fract *__p, unsigned short fract __value) __asm("eeprom_write_byte");

/** \ingroup avr_stdfix
    Write a <tt>fract</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_r (fract *__p, fract __value) __asm("eeprom_write_word");

/** \ingroup avr_stdfix
    Write an <tt>unsigned fract</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_ur (unsigned fract *__p, unsigned fract __value) __asm("eeprom_write_word");

/** \ingroup avr_stdfix
    Write a <tt>long fract</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_lr (long fract *__p, long fract __value) __asm("eeprom_write_dword");

/** \ingroup avr_stdfix
    Write an <tt>unsigned long fract</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_ulr (unsigned long fract *__p, unsigned long fract __value) __asm("eeprom_write_dword");

/** \ingroup avr_stdfix
    Write a <tt>long long fract</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_llr (long long fract *__p, long long fract __value) __asm("eeprom_write_qword");

/** \ingroup avr_stdfix
    Write an <tt>unsigned long long fract</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_ullr (unsigned long long fract *__p, unsigned long long fract __value) __asm("eeprom_write_qword");

/** \ingroup avr_stdfix
    Write a <tt>short accum</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_hk (short accum *__p, short accum __value) __asm("eeprom_write_word");

/** \ingroup avr_stdfix
    Write an <tt>unsigned short accum</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_uhk (unsigned short accum *__p, unsigned short accum __value) __asm("eeprom_write_word");

/** \ingroup avr_stdfix
    Write an <tt>accum</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_k (accum *__p, accum __value) __asm("eeprom_write_dword");

/** \ingroup avr_stdfix
    Write an <tt>unsigned accum</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_uk (unsigned accum *__p, unsigned accum __value) __asm("eeprom_write_dword");

/** \ingroup avr_stdfix
    Write a <tt>long accum</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_lk (long accum *__p, long accum __value) __asm("eeprom_write_qword");

/** \ingroup avr_stdfix
    Write an <tt>unsigned long accum</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_ulk (unsigned long accum *__p, unsigned long accum __value) __asm("eeprom_write_qword");

/** \ingroup avr_stdfix
    Write a <tt>long long accum</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_llk (long long accum *__p, long long accum __value) __asm("eeprom_write_qword");

/** \ingroup avr_stdfix
    Write an <tt>unsigned long long accum</tt> to EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_write_ullk (unsigned long long accum *__p, unsigned long long accum __value) __asm("eeprom_write_qword");


/** \name EEPROM Update Functions */

/** \ingroup avr_stdfix
    Update a <tt>short fract</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_hr (short fract *__p, short fract __value) __asm("eeprom_update_byte");

/** \ingroup avr_stdfix
    Update an <tt>unsigned short fract</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_uhr (unsigned short fract *__p, unsigned short fract __value) __asm("eeprom_update_byte");

/** \ingroup avr_stdfix
    Update a <tt>fract</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_r (fract *__p, fract __value) __asm("eeprom_update_word");

/** \ingroup avr_stdfix
    Update an <tt>unsigned fract</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_ur (unsigned fract *__p, unsigned fract __value) __asm("eeprom_update_word");

/** \ingroup avr_stdfix
    Update a <tt>long fract</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_lr (long fract *__p, long fract __value) __asm("eeprom_update_dword");

/** \ingroup avr_stdfix
    Update an <tt>unsigned long fract</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_ulr (unsigned long fract *__p, unsigned long fract __value) __asm("eeprom_update_dword");

/** \ingroup avr_stdfix
    Update a <tt>long long fract</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_llr (long long fract *__p, long long fract __value) __asm("eeprom_update_qword");

/** \ingroup avr_stdfix
    Update an <tt>unsigned long long fract</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_ullr (unsigned long long fract *__p, unsigned long long fract __value) __asm("eeprom_update_qword");

/** \ingroup avr_stdfix
    Update a <tt>short accum</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_hk (short accum *__p, short accum __value) __asm("eeprom_update_word");

/** \ingroup avr_stdfix
    Update an <tt>unsigned short accum</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_uhk (unsigned short accum *__p, unsigned short accum __value) __asm("eeprom_update_word");

/** \ingroup avr_stdfix
    Update an <tt>accum</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_k (accum *__p, accum __value) __asm("eeprom_update_dword");

/** \ingroup avr_stdfix
    Update an <tt>unsigned accum</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_uk (unsigned accum *__p, unsigned accum __value) __asm("eeprom_update_dword");

/** \ingroup avr_stdfix
    Update a <tt>long accum</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_lk (long accum *__p, long accum __value) __asm("eeprom_update_qword");

/** \ingroup avr_stdfix
    Update an <tt>unsigned long accum</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_ulk (unsigned long accum *__p, unsigned long accum __value) __asm("eeprom_update_qword");

/** \ingroup avr_stdfix
    Update a <tt>long long accum</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_llk (long long accum *__p, long long accum __value) __asm("eeprom_update_qword");

/** \ingroup avr_stdfix
    Update an <tt>unsigned long long accum</tt> at EEPROM address \a __p.
    \since AVR-LibC v2.3 */
void eeprom_update_ullk (unsigned long long accum *__p, unsigned long long accum __value) __asm("eeprom_update_qword");

#ifdef __cplusplus
}
#endif

#endif /* _STDFIX_AVRLIBC_H */
