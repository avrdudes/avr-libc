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
    implementation should be warned: the \c printf and \c scanf families, although
    usually associated with presumably simple things like the
    famous "Hello, world!" program, is actually a fairly complex
    one which causes quite some amount of code space to be taken,
    and it's not fast either due to the nature of interpreting the
    format string at run-time.  Whenever possible, resorting to the
    (sometimes non-standard) predetermined conversion facilities that are
    offered by avr-libc will usually cost much less in terms of speed
    and code size.

    In order to allow programmers a code size vs. functionality tradeoff,
    the function vfprintf() which is the heart of the printf family can be
    selected in different flavours using linker options.  See the
    documentation of vfprintf() for a detailed description.  The same
    applies to vfscanf() and the \c scanf family of functions.

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

    All the \c printf and \c scanf family functions come in two flavours: the
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
   - \c p  The <tt>void *</tt> argument is taken as an unsigned integer,
           and converted similarly as a <tt>%#x</tt> command would do.
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
   - \c eE The double argument is rounded and converted in the format
           \c "[-]d.ddde±dd" where there is one digit before the
           decimal-point character and the number of digits after it
           is equal to the precision; if the precision is missing, it
           is taken as 6; if the precision is zero, no decimal-point
           character appears.  An \e E conversion uses the letter \c 'E'
           (rather than \c 'e') to introduce the exponent.  The exponent
           always contains two digits; if the value is zero,
           the exponent is 00.
   - \c fF The double argument is rounded and converted to decimal notation
           in the format \c "[-]ddd.ddd", where the number of digits after the
           decimal-point character is equal to the precision specification.
           If the precision is missing, it is taken as 6; if the precision
           is explicitly zero, no decimal-point character appears.  If a
           decimal point appears, at least one digit appears before it.
   - \c gG The double argument is converted in style \c f or \c e (or
           \c F or \c E for \c G conversions).  The precision
           specifies the number of significant digits.  If the
           precision is missing, 6 digits are given; if the precision
           is zero, it is treated as 1.  Style \c e is used if the
           exponent from its conversion is less than -4 or greater
           than or equal to the precision.  Trailing zeros are removed
           from the fractional part of the result; a decimal point
           appears only if it is followed by at least one digit.

   In no case does a non-existent or small field width cause truncation of a
   numeric field; if the result of a conversion is wider than the field
   width, the field is expanded to contain the conversion result.

   Since the full implementation of all the mentioned features becomes
   fairly large, three different flavours of vfprintf() can be
   selected using linker options.  The default vfprintf() implements
   all the mentioned functionality except floating point conversions.
   A minimized version of vfprintf() is available that only implements
   the very basic integer and string conversion facilities, but none
   of the additional options that can be specified using conversion
   flags (these flags are parsed correctly from the format
   specification, but then simply ignored).  This version can be
   requested using the following \ref gcc_minusW "compiler options":

   \code
   -Wl,-u,vfprintf -lprintf_min
   \endcode

   If the full functionality including the floating point conversions
   is required, the following options should be used:

   \code
   -Wl,-u,vfprintf -lprintf_flt -lm
   \endcode

   \par Limitations:
   - The specified width and precision can be at most 127.
   - For floating-point conversions, trailing digits will be lost if
     a number close to DBL_MAX is converted with a precision > 0.

 */

extern int	vfprintf(FILE *__stream, const char *__fmt, va_list __ap);

/**
   The function \c fputc sends the character \c c (though given as type
   \c int) to \c stream.  It returns the character, or \c EOF in case
   an error occurred.
*/
extern int	fputc(int __c, FILE *__stream);

/* putc() function implementation, required by standard */
extern int	putc(int __c, FILE *__stream);

/* putchar() function implementation, required by standard */
extern int	putchar(int __c);

/**
   The macro \c putc used to be a "fast" macro implementation with a
   functionality identical to fputc().  For space constraints, in
   \c avr-libc, it is just an alias for \c fputc.
*/
#define putc(__c, __stream) fputc(__c, __stream)

/**
   The macro \c putchar sends character \c c to \c stdout.
*/
#define putchar(__c) fputc(__c, stdout)

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

/**
   Write the string pointed to by \c str to stream \c stream.

   Returns 0 on success and EOF on error.
*/
extern int	fputs(const char *__str, FILE *__stream);

/**
   Variant of fputs() where \c str resides in program memory.
*/
extern int	fputs_P(const char *__str, FILE *__stream);

/**
   Write the string pointed to by \c str, and a trailing newline
   character, to \c stdout.
*/
extern int	puts(const char *__str);

/**
   Variant of puts() where \c str resides in program memory.
*/
extern int	puts_P(const char *__str);

/**
   Write \c nmemb objects, \c size bytes each, to \c stream.
   The first byte of the first object is referenced by \c ptr.

   Returns the number of objects successfully written, i. e.
   \c nmemb unless an output error occured.
 */
extern size_t	fwrite(const void *__ptr, size_t __size, size_t __nmemb,
		       FILE *__stream);

/**
   The function \c fgetc reads a character from \c stream.  It returns
   the character, or \c EOF in case end-of-file was encountered or an
   error occurred.  The routines feof() or ferror() must be used to
   distinguish between both situations.
*/
extern int	fgetc(FILE *__stream);

/* getc() function implementation, required by standard */
extern int	getc(FILE *__stream);

/* getchar() function implementation, required by standard */
extern int	getchar(void);

/**
   The macro \c getc used to be a "fast" macro implementation with a
   functionality identical to fgetc().  For space constraints, in
   \c avr-libc, it is just an alias for \c fgetc.
*/
#define getc(__stream) fgetc(__stream)

/**
   The macro \c getchar reads a character from \c stdin.  Return
   values and error handling is identical to fgetc().
*/
#define getchar() fgetc(stdin)

/**
   The ungetc() function pushes the character \c c (converted to an
   unsigned char) back onto the input stream pointed to by \c stream.
   The pushed-back character will be returned by a subsequent read on
   the stream.

   Currently, only a single character can be pushed back onto the
   stream.
   
   The ungetc() function returns the character pushed back after the
   conversion, or \c EOF if the operation fails.  If the value of the
   argument \c c character equals \c EOF, the operation will fail and
   the stream will remain unchanged.
*/
extern int	ungetc(int __c, FILE *__stream);

/**
   Read at most <tt>size - 1</tt> bytes from \c stream, until a
   newline character was encountered, and store the characters in the
   buffer pointed to by \c str.  Unless an error was encountered while
   reading, the string will then be terminated with a \c NUL
   character.

   If an error was encountered, the function returns NULL and sets the
   error flag of \c stream, which can be tested using ferror().
   Otherwise, a pointer to the string will be returned.  */
extern char	*fgets(char *__str, int __size, FILE *__stream);

/**
   Similar to fgets() except that it will operate on stream \c stdin,
   and the trailing newline (if any) will not be stored in the string.
   It is the caller's responsibility to provide enough storage to hold
   the characters read.  */
extern char	*gets(char *__str);

/**
   Read \c nmemb objects, \c size bytes each, from \c stream,
   to the buffer pointed to by \c ptr.

   Returns the number of objects successfully read, i. e.
   \c nmemb unless an input error occured or end-of-file was
   encountered.  feof() and ferror() must be used to distinguish
   between these two conditions.
 */
extern size_t	fread(void *__ptr, size_t __size, size_t __nmemb,
		      FILE *__stream);

/**
   Clear the error and end-of-file flags of \c stream.
 */
extern void	clearerr(FILE *__stream);

/**
   Test the end-of-file flag of \c stream.  This flag can only be cleared
   by a call to clearerr().

   \note
   Since there is currently no notion for end-of-file on a device, this
   function will always return a false value.
 */
extern int	feof(FILE *__stream);

/**
   Test the error flag of \c stream.  This flag can only be cleared
   by a call to clearerr().
 */
extern int	ferror(FILE *__stream);

/**
   Formatted input.  This function is the heart of the \c scanf
   family of functions.

   Characters are read from \c stream and processed in a way
   described by \c fmt.  Conversion results will be assigned to the
   parameters passed via \c ap.

   The format string \c fmt is scanned for conversion specifications.
   Anything that doesn't comprise a conversion specification is taken
   as text that is matched literally against the input.  White space
   in the format string will match any white space in the data
   (including none), all other characters match only itself.
   Processing is aborted as soon as the data and format string no
   longer match, or there is an error or end-of-file condition on
   \c stream.

   Most conversions skip leading white space before starting the
   actual conversion.

   Conversions are introduced with the character \b %.  Possible
   options can follow the \b %:

   - a \c * indicating that the conversion should be performed but
     the conversion result is to be discarded; no parameters will
     be processed from \c ap,
   - the character \c h indicating that the argument is a pointer
     to <tt>short int</tt> (rather than <tt>int</tt>),
   - the character \c l indicating that the argument is a pointer
     to <tt>long int</tt> (rather than <tt>int</tt>, for integer
     type conversions), or a pointer to \c double (for floating
     point conversions).

   In addition, a maximal field width may be specified as a nonzero
   positive decimal integer, which will restrict the conversion to at
   most this many characters from the input stream.  This field width
   is limited to at most 127 characters which is also the default
   value (except for the <tt>%c</tt> conversion that defaults to 1).

   The following conversion flags are supported:

   - \c % Matches a literal \c % character.  This is not a conversion.
   - \c d Matches an optionally signed decimal integer; the next
     pointer must be a pointer to \c int.
   - \c i Matches an optionally signed integer; the next pointer must
     be a pointer to \c int.  The integer is read in base 16 if it
     begins with \b 0x or \b 0X, in base 8 if it begins with \b 0, and
     in base 10 otherwise.  Only characters that correspond to the
     base are used.
   - \c o Matches an octal integer; the next pointer must be a pointer to
     <tt>unsigned int</tt>.
   - \c u Matches an optionally signed decimal integer; the next
     pointer must be a pointer to <tt>unsigned int</tt>.
   - \c x Matches an optionally signed hexadecimal integer; the next
     pointer must be a pointer to <tt>unsigned int</tt>.
   - \c f Matches an optionally signed floating-point number; the next
     pointer must be a pointer to \c float.
   - <tt>e, g, E, G</tt> Equivalent to \c f.
   - \c s
     Matches a sequence of non-white-space characters; the next pointer
     must be a pointer to \c char, and the array must be large enough to
     accept all the sequence and the terminating \c NUL character.  The
     input string stops at white space or at the maximum field width,
     whichever occurs first.
   - \c c
     Matches a sequence of width count characters (default 1); the next
     pointer must be a pointer to \c char, and there must be enough room
     for all the characters (no terminating \c NUL is added).  The usual
     skip of leading white space is suppressed.  To skip white space
     first, use an explicit space in the format.
   - \c [
     Matches a nonempty sequence of characters from the specified set
     of accepted characters; the next pointer must be a pointer to \c
     char, and there must be enough room for all the characters in the
     string, plus a terminating \c NUL character.  The usual skip of
     leading white space is suppressed.  The string is to be made up
     of characters in (or not in) a particular set; the set is defined
     by the characters between the open bracket \c [ character and a
     close bracket \c ] character.  The set excludes those characters
     if the first character after the open bracket is a circumflex
     \c ^.  To include a close bracket in the set, make it the first
     character after the open bracket or the circumflex; any other
     position will end the set.  The hyphen character \c - is also
     special; when placed between two other characters, it adds all
     intervening characters to the set.  To include a hyphen, make it
     the last character before the final close bracket.  For instance,
     <tt>[^]0-9-]</tt> means the set <em>everything except close
     bracket, zero through nine, and hyphen</em>.  The string ends
     with the appearance of a character not in the (or, with a
     circumflex, in) set or when the field width runs out.
   - \c p
     Matches a pointer value (as printed by <tt>%p</tt> in printf()); the
     next pointer must be a pointer to \c void.
   - \c n
     Nothing is expected; instead, the number of characters consumed
     thus far from the input is stored through the next pointer, which
     must be a pointer to \c int.  This is not a conversion, although it
     can be suppressed with the \c * flag.

     These functions return the number of input items assigned, which
     can be fewer than provided for, or even zero, in the event of a
     matching failure.  Zero indicates that, while there was input
     available, no conver­ sions were assigned; typically this is due
     to an invalid input character, such as an alphabetic character
     for a <tt>%d</tt> conversion.  The value \c EOF is returned if an input
     failure occurs before any conversion such as an end-of-file
     occurs.  If an error or end-of-file occurs after conversion has
     begun, the number of conversions which were successfully
     completed is returned.

     By default, all the conversion described above are available
     except the floating-point conversions, and the <tt>%[</tt> conversion.
     These conversions will be available in the extended version
     provided by the library \c libscanf_flt.a.  Note that either of
     these conversions requires the availability of a buffer that
     needs to be obtained at run-time using malloc().  If this buffer
     cannot be obtained, the operation is aborted, returning the
     value \c EOF.  To link a program against the extended version,
     use the following compiler flags in the link stage:

     \code
     -Wl,-u,vfscanf -lscanf_flt -lm
     \endcode

     A third version is available for environments that are tight
     on space.  This version is provided in the library
     \c libscanf_min.a, and can be requested using the following
     options in the link stage:

     \code
     -Wl,-u,vfscanf -lscanf_min -lm
     \endcode

     In addition to the restrictions of the standard version, this
     version implements no field width specification, no conversion
     assignment suppression flag (\c *), no <tt>%n</tt> specification, and
     no general format character matching at all.  All characters in
     \c fmt that do not comprise a conversion specification will
     simply be ignored, including white space (that is normally used
     to consume \e any amount of white space in the input stream).
     However, the usual skip of initial white space in the formats
     that support it is implemented.
*/
extern int	vfscanf(FILE *__stream, const char *__fmt, va_list __ap);

/**
   The function \c fscanf performs formatted input, reading the
   input data from \c stream.

   See vfscanf() for details.
 */
extern int	fscanf(FILE *__stream, const char *__fmt, ...);

/**
   Variant of fscanf() using a \c fmt string in program memory.
 */
extern int	fscanf_P(FILE *__stream, const char *__fmt, ...);

/**
   The function \c scanf performs formatted input from stream \c stdin.

   See vfscanf() for details.
 */
extern int	scanf(const char *__fmt, ...);

/**
   Variant of scanf() where \c fmt resides in program memory.
 */
extern int	scanf_P(const char *__fmt, ...);

/**
   The function \c sscanf performs formatted input, reading the
   input data from the buffer pointed to by \c buf.

   See vfscanf() for details.
 */
extern int	sscanf(const char *__buf, const char *__fmt, ...);

/**
   Variant of sscanf() using a \c fmt string in program memory.
 */
extern int	sscanf_P(const char *__buf, const char *__fmt, ...);

#ifdef __cplusplus
}
#endif

/*@}*/

/*
 * The following constants are currently not used by avr-libc's
 * stdio subsystem.  They are defined here since the gcc build
 * environment expects them to be here.
 */
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#endif /* __ASSEMBLER */

#endif /* _STDLIB_H_ */
