/* Copyright (c) 2002, Joerg Wunsch

   Portions of documentation Copyright (c) 1990, 1991, 1993
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
  POSSIBILITY OF SUCH DAMAGE.

  $Id$
*/

#ifndef _STDIO_H_
#define	_STDIO_H_ 1

#ifndef __ASSEMBLER__

#include <inttypes.h>
#include <stdarg.h>

#define __need_NULL
#define __need_size_t
#include <stddef.h>

/** \defgroup avr_stdio Standard IO facilities
    \code #include <stdio.h> \endcode

    \warning
    This implementation of the standard IO facilities is new to
    avr-libc.  It is not yet expected to remain stable, so some
    aspects of the API might change in a future release.

    This file declares the standard IO facilities that are implemented
    in \c avr-libc.  Due to the nature of the underlying hardware,
    only a limited subset of standard IO is implemented.  There's no
    actual file implementation available, so only device IO can be
    performed.  Since there's no operating system, the application
    needs to provide enough details about their devices in order to
    make them usable by the standard IO facilities.

    Due to space constraints, some functionality has not been
    implemented at all (like some of the \c printf conversions that
    have been left out).  Nevertheless, potential users of this
    implementation should be warned: the \c printf family, although
    usually associated with presumably simple things like the
    famous "Hello, world!" program, is actually a fairly complex
    one which causes quite some amount of code space to be taken,
    and it's not fast either due to the nature of interpreting the
    format string at run-time.  Whenever possible, resorting to the
    (non-standard) predetermined conversion facilities that are
    offered by avr-libc will usually cost much less in terms of speed
    and code size.

    The standard streams \c stdin, \c stdout, and \c stderr are
    provided, but contrary to the C standard, since avr-libc has no
    knowledge about applicable devices, these streams are not already
    pre-initialized at application startup.  Also, since there's no
    notion of "file" whatsoever to avr-libc, there's no function
    \c fopen() that could be used to associate a stream to some device.
    (See \ref stdio_note1 "note 1".)  Instead, function \c fdevopen()
    is provided to associate a stream to a device, where the device
    needs to provide a function to send a character, to receive a
    character, or both.  There's no differentiation between "text" and
    "binary" streams inside avr-libc.  Character \c \n is sent
    literally down to the device's \c put() function.  If the device
    requires a carriage return (\c \r) character to be sent before
    the linefeed, its \c put() routine must implement this (see
    \ref stdio_note2 "note 2").

    For convenience, the first call to \c fdevopen() that opens a
    stream for reading will cause the resulting stream to be aliased
    to \c stdin.  Likewise, the first call to \c fdevopen() that opens
    a stream for writing will cause the resulting stream to be aliased
    to both, \c stdout, and \c stderr.  (Thus, if the open was done
    with both, read and write intent, all three standard streams will
    be identical.)  Note that these aliases are indistinguishable from
    each other, thus calling \c fclose() on such a stream will
    effectively also close all of its aliases (\ref stdio_note3 "note 3").

    All the \c printf family functions come in two flavours: the
    standard name, where the format string is expected to be in
    SRAM, as well as a version with "_P" appended where the format
    string is expected to reside in the flash ROM.  The macro
    \c PSTR (explained in \ref avr_pgmspace) will become very handy
    to declare these format strings.

    \anchor stdio_note1 \par Note 1:
    It might have been possible to implement a device abstraction that
    is compatible with \c fopen() but since this would have required
    to parse a string, and to take all the information needed either
    out of this string, or out of an additional table that were to be
    provided by the application, this approach has not been taken.

    \anchor stdio_note2 \par Note 2:
    This basically follows the Unix approach: if a device such as a
    terminal needs special handling, it is in the domain of the
    terminal device driver to provide this functionality.  Thus, a
    simple function suitable as \c put() for \c fdevopen() that talks
    to a UART interface might look like this:

    \code
    int
    uart_putchar(char c)
    {

      if (c == '\n')
        uart_putchar('\r');
      loop_until_bit_is_set(UCSRA, UDRE);
      UDR = c;
      return 0;
    }
    \endcode

    \anchor stdio_note3 \par Note 3:
    This implementation has been chosen because the cost of maintaining
    an alias is considerably smaller than the cost of maintaining full
    copies of each stream.  Yet, providing an implementation that offers
    the complete set of standard streams was deemed to be useful.  Not
    only that writing \c printf() instead of <tt>fprintf(mystream, ...)</tt>
    saves typing work, but since avr-gcc needs to resort to pass all
    arguments of variadic functions on the stack (as opposed to passing
    them in registers for functions that take a fixed number of
    parameters), the ability to pass one parameter less by implying
    \c stdin will also save some execution time.
    
*/

struct __file;

/*@{*/
/**
   \c FILE is the opaque structure that is passed around between the
   various standard IO functions.
*/
#define FILE	struct __file

/**
   Stream that will be used as an input stream by the simplified
   functions that don't take a \c stream argument.

   The first stream opened with read intent using \c fdevopen()
   will be assigned to \c stdin.
*/
#define stdin (__iob[0])

/**
   Stream that will be used as an output stream by the simplified
   functions that don't take a \c stream argument.

   The first stream opened with write intent using \c fdevopen()
   will be assigned to both, \c stdin, and \c stderr.
*/
#define stdout (__iob[1])

/**
   Stream destined for error output.  Unless specifically assigned,
   identical to \c stdout.

   If \c stderr should point to another stream, the result of
   another \c fdevopen() must be explicitly assigned to it without
   closing the previous \c stderr (since this would also close
   \c stdout).
*/
#define stderr (__iob[2])

/**
   \c EOF declares the value that is returned by various standard IO
   functions in case of an error.  Since the AVR platform (currently)
   doesn't contain an abstraction for actual files, its origin as
   "end of file" is somewhat meaningless here.
*/
#define EOF	(-1)

#ifdef __cplusplus
extern "C" {
#endif

extern struct __file *__iob[];

/**
   This function is a replacement for \c fopen().

   It opens a stream for a device where the actual device
   implementation needs to be provided by the application.  If
   successful, a pointer to the structure for the opened stream is
   returned.  Reasons for a possible failure currently include that
   neither the \c put nor the \c get argument have been provided, thus
   attempting to open a stream with no IO intent at all, or that
   insufficient dynamic memory is available to establish a new stream.

   If the \c put function pointer is provided, the stream is opened
   with write intent.  The function passed as \c put shall take one
   character to write to the device as argument , and shall return 0
   if the output was successful, and a nonzero value if the character
   could not be sent to the device.

   If the \c get function pointer is provided, the stream is opened
   with read intent.  The function passed as \c get shall take no
   arguments, and return one character from the device, passed as an
   \c int type.  If an error occurs when trying to read from the
   device, it shall return \c -1.

   If both functions are provided, the stream is opened with read
   and write intent.

   The first stream opened with read intent is assigned to \c stdin,
   and the first one opened with write intent is assigned to both,
   \c stdout and \c stderr.

   The third parameter \c opts is currently unused, but reserved for
   future extensions.  */
extern FILE	*fdevopen(int (*__put)(char), int (*__get)(void), int __opts);

/**
   This function closes \c stream, and disallows and further
   IO to and from it.

   It currently always returns 0 (for success).
*/
extern int	fclose(FILE *__stream);

/**
   \c vfprintf is the central facility of the \c printf family of
   functions.  It outputs values to \c stream under control of a
   format string passed in \c fmt.  The actual values to print are
   passed as a variable argument list \c ap.

   \c vfprintf returns the number of characters written to \c stream,
   or \c EOF in case of an error.  Currently, this will only happen
   if \c stream has not been opened with write intent.

   The format string is composed of zero or more directives: ordinary
   characters (not \c %), which are copied unchanged to the output
   stream; and conversion specifications, each of which results in
   fetching zero or more subsequent arguments.  Each conversion
   specification is introduced by the \c % character.  The arguments must
   correspond properly (after type promotion) with the conversion
   specifier.  After the \c %, the following appear in sequence:

   - Zero or more of the following flags:
      <ul>
      <li> \c # The value should be converted to an "alternate form".  For
            c, d, i, s, and u conversions, this option has no effect.
            For o conversions, the precision of the number is
            increased to force the first character of the output
            string to a zero (except if a zero value is printed with
            an explicit precision of zero).  For x and X conversions,
            a non-zero result has the string `0x' (or `0X' for X
            conversions) prepended to it.</li>
      <li> \c 0 (zero) Zero padding.  For all conversions, the converted
            value is padded on the left with zeros rather than blanks.
            If a precision is given with a numeric conversion (d, i,
            o, u, i, x, and X), the 0 flag is ignored.</li>
      <li> \c - A negative field width flag; the converted value is to be
            left adjusted on the field boundary.  The converted value
            is padded on the right with blanks, rather than on the
            left with blanks or zeros.  A - overrides a 0 if both are
            given.</li>
      <li> ' ' (space) A blank should be left before a positive number
            produced by a signed conversion (d, or i).</li>
      <li> \c + A sign must always be placed before a number produced by a
            signed conversion.  A + overrides a space if both are
            used.</li>
      </ul>
   -   An optional decimal digit string specifying a minimum field width.
       If the converted value has fewer characters than the field width, it
       will be padded with spaces on the left (or right, if the left-adjust­
       ment flag has been given) to fill out the field width.
   -   An optional precision, in the form of a period . followed by an
       optional digit string.  If the digit string is omitted, the
       precision is taken as zero.  This gives the minimum number of
       digits to appear for d, i, o, u, x, and X conversions, or the
       maximum number of characters to be printed from a string for s
       con­ versions.
   -   An optional \c l length modifier, that specifies that the
       argument for the d, i, o, u, x, or X conversion is a \c "long int"
       rather than \c int.
   -   A character that specifies the type of conversion to be applied.

   The conversion specifiers and their meanings are:

   - \c diouxX The int (or appropriate variant) argument is converted
           to signed decimal (d and i), unsigned octal (o), unsigned
           decimal (u), or unsigned hexadecimal (x and X) notation.
           The letters "abcdef" are used for x conversions; the
           letters "ABCDEF" are used for X conversions.  The
           precision, if any, gives the minimum number of digits that
           must appear; if the converted value requires fewer digits,
           it is padded on the left with zeros.
   - \c c  The \c int argument is converted to an \c "unsigned char", and the
           resulting character is written.
   - \c s  The \c "char *" argument is expected to be a pointer to an array
           of character type (pointer to a string).  Characters from
           the array are written up to (but not including) a
           terminating NUL character; if a precision is specified, no
           more than the number specified are written.  If a precision
           is given, no null character need be present; if the
           precision is not specified, or is greater than the size of
           the array, the array must contain a terminating NUL
           character.
   - \c %  A \c % is written.  No argument is converted.  The complete
           conversion specification is "%%".

   In no case does a non-existent or small field width cause truncation of a
   numeric field; if the result of a conversion is wider than the field
   width, the field is expanded to contain the conversion result.

   \par Limitations:
   - Currently, no floating point conversions are supported.  Refer to
     \c dtostre() and \c dtostrf() for alternate functions that can be
     used to convert floating point numbers.
   - The specified width can be at most 127.
   - The specified precision will be limited to 8 in order to limit
     the internal buffer space required.  This also applies to the
     the maximal fill range in a zero-fill conversion (since this is
     actually implemented by using a precision value internally).

 */

extern int	vfprintf(FILE *__stream, const char *__fmt, va_list __ap);

/**
   The function \c fputc sends the character \c (though given as type
   \c int) to \c stream.  It returns the character, or \c EOF in case
   an error occurred.
*/
extern int	fputc(int __c, FILE *__stream);

/**
   The macro \c putc used to be a "fast" macro implementation with a
   functionality identical to \c fputc().  For space constraints, in
   \c avr-libc, it is just an alias for \c fputc.
*/
#define putc(__c, __stream) fputc(__c, __stream)

/**
   The function \c printf performs formatted output to stream
   \c stderr.  See \c vfprintf() for details.
*/
extern int	printf(const char *__fmt, ...);

/**
   Variant of \c printf() that uses a \c fmt string that resides
   in program memory.
*/
extern int	printf_P(const char *__fmt, ...);

/**
   Variant of \c printf() that sends the formatted characters
   to string \c s.
*/
extern int	sprintf(char *__s, const char *__fmt, ...);

/**
   Variant of \c sprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int	sprintf_P(char *__s, const char *__fmt, ...);

/**
   Like \c sprintf(), but instead of assuming \c s to be of infinite
   size, no more than \c n characters (including the trailing NUL
   character) will be converted to \c s.

   Returns the number of characters that would have been written to
   \c s if there were enough space.
*/
extern int	snprintf(char *__s, size_t __n, const char *__fmt, ...);

/**
   Variant of \c snprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int	snprintf_P(char *__s, size_t __n, const char *__fmt, ...);

/**
   The function \c fprintf performs formatted output to \c stream.
   See \c vfprintf() for details.
*/
extern int	fprintf(FILE *__stream, const char *__fmt, ...);

/**
   Variant of \c fprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int	fprintf_P(FILE *__stream, const char *__fmt, ...);


#ifdef __cplusplus
}
#endif

/*@}*/

#endif /* __ASSEMBLER */

#endif /* _STDLIB_H_ */
