/* Copyright (c) 2002-2025 Joerg Wunsch
   All rights reserved.

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

#ifndef _AVR_FLASH_H_
#define _AVR_FLASH_H_

#if !defined(__AVR_TINY__) && !defined(__cplusplus)

#ifdef __DOXYGEN__
/** \file */
/** \defgroup avr_flash <avr/flash.h>: Utilities for named address-spaces __flash and __flashx

    \since AVR-LibC v2.3

    \code
    #include <avr/flash.h>
    \endcode

    The functions and macros in this module provide interfaces for a program
    to use data stored in program space (flash memory) by means of the
    #__flash and #__flashx named address-spaces
    supported by avr-gcc.

    <h3>Purpose</h3>
    The prototypes and macros provided by this header allow to write
    C programs that are address-space correct, i.e. they will compile
    without diagnostics due to <tt>-Waddr-space-convert</tt>.

    For example, you can call #printf_P with a format string located
    in RAM resulting in non-functional code, and the compiler won't complain.
    This is different with #printf_F which will trigger a diagnostic when
    <tt>-Waddr-space-convert</tt> is on, and you feed in a format string that
    does not carry the #__flash named address-space qualifier.

    <h3>Structure of this Header</h3>

    This header provides:

    - Functions from \c stdio.h, \c string.h resp. \c avr/pgmspace.h, but
    where one input string resides in the 16-bit address-space #__flash.
    For example, the #strlen_F function works the same like the "progmem"
    function #strlen_P but uses a prototype that describes the flash string
    as <tt>const __flash char*</tt>.

    - Functions from \c string.h resp. \c avr/pgmspace.h, but where one
    input string resides in 24-bit address-space #__flashx.
    For example, the #strlen_FX function works the same like the "far"
    function #strlen_PF but uses a prototype that describes the flash string
    as <tt>const __flashx char*</tt>.

    - Some macros for convenience.

    <h3>Examples</h3>

    \code
#include <stdbool.h>
#include <avr/flash.h>

// Array of string literals where the array
// and also the literals reside in __flash.
const __flash char* const __flash pets[] =
{
    FLIT("gnu"), FLIT("cat"), FLIT("bat"), FLIT("rat")
};

void test_pet (const char *pet, const __flash char *what)
{
    const __flash char *yesno;
    bool is_what = ! strcmp_F (pet, what);
    yesno = is_what ? FSTR("yes") : FSTR("no");

    // %S denotes a string in lower 64 KiB flash.
    printf_FSTR ("%s is a %S? %S!\n", pet, what, yesno);
}

int main (void)
{
    char pet[] = "cat";
    for (size_t i = 0; i < sizeof (pets) / sizeof (*pets); ++i)
    {
        pet[0] ^= 1;
        test_pet (pet, pets[i]);
    }
  return 0;
}
    \endcode
    It will print
\verbatim
bat is a gnu? no!
cat is a cat? yes!
bat is a bat? yes!
cat is a rat? no!
\endverbatim
    provided stdout has been set up appropriately.

    <h3>Efficiency</h3>

    The internal handling of 64-bit values in avr-gcc is such that it splits
    them into single byte operations for the purpose of moving them around.
    This can lead to quite some overhead when reading such values from
    named address-spaces.  To that end, <tt>avr/flash.h</tt> provides some
    inline functions like #flash_read_u64 and #flashx_read_double that
    work similar to the #pgm_read_u64 and #pgm_read_double_far functions,
    but are coming with proper address-space qualification.

    <h3>Limitations</h3>

    - Named address-spaces are supported by avr-gcc as part of GNU-C
    (e.g. <tt>-std=gnu99</tt>).  They are not available in Standard C,
    and are not supported in C++.

    - Address-spaces #__flash and #__memx are supported since
    avr-gcc v4.7 (Release 2012), whereas #__flashx is available
    since avr-gcc v15 (Release 2025).

    - Named address-spaces are not supported for Reduced Tiny (core AVRrc,
    <tt>-mmcu=avrtiny</tt>), like ATtiny10, ATtiny102 or ATtiny40.

    <h3>Further Reading</h3>

    - <a href="https://gcc.gnu.org/onlinedocs/gcc/Named-Address-Spaces.html#AVR-Named-Address-Spaces"
    >avr-gcc: Named Address-Spaces</a>
*/

/** \name Macros */

/** \ingroup avr_flash
    \def FSTR(str)

    Used to get a pointer to a static string in address-space #__flash.
    This macro can only be used in the context of a funcion, like in:

    \code
    #include <avr/flash.h>

    void say_hello (int x)
    {
        printf_F (FSTR ("Hello number %d\n"), x);

        // Same effect, but more convenient.
        printf_FSTR ("Hello number %d\n", x);
    }
    \endcode
    #FSTR works similar to the #PSTR macro but returns a pointer to the 16-bit
    named address-space #__flash, whereas #PSTR returns a 16-bit
    address in the generic address-space (but isn't).
*/
# define FSTR(str) ({ static const __flash char c[] = (str); &c[0]; })

/** \ingroup avr_flash
    Used to get a pointer to a static string in the 24-bit address-space
    #__flashx.
    This macro can only be used in the context of a funcion, like in:

    \code
    #include <stdbool.h>
    #include <avr/flash.h>

    bool text_contains_dog (const char *text)
    {
        return strstr_FX (text, FXSTR ("dog")) != NULL;
    }
    \endcode
    #FXSTR works similar to the #PSTR_FAR macro but returns a pointer to
    the 24-bit named address-space #__flashx, whereas #PSTR_FAR returns
    a 32-bit integer that represents an address in the generic address-space
    (but isn't).
*/
# define FXSTR(str) ({ static const __flashx char c[] = (str); &c[0]; })

/** \ingroup avr_flash
    Turn string literal \p str into a compound literal in address-space
    #__flash. This macro can be used to construct arrays of string pointers:
    Suppose the following 2-dimensional array of animal names:
    \code
    // Each string occupies 13 bytes, hence
    // animals[] occupies 9 * 13 = 117 bytes.
    const __flash char animals[][13] =
    {
        "hippopotamus",
        "cat", "pig", "gnu", "bat",
        "dog", "cow", "fox", "rat"
    };
    \endcode
    A more memory-friendly way to represent the strings is an
    array of string \e pointers, like in:
    \code
    // Occupies 9*2 + 13 + 8*4 = 63 bytes
    const char* const animals2[] =
    {
        "hippopotamus",
        "cat", "pig", "gnu", "bat",
        "dog", "cow", "fox", "rat"
    };
    \endcode
    \c animals2[] occupies only 63 bytes (9 * 2 bytes for the string
    addresses plus the lengths of the very strings).  However, all
    objects are located in the generic address-space.  When all objects
    should be put in a non-generic address-space like #__flash,
    then the type of the literals has to be forced to be
    <tt>const __flash char[]</tt>.  This can be accomplished with #FLIT:
    \code
    // Occupies 9*2 + 13 + 8*4 = 63 bytes
    const __flash char* const __flash animals3[] =
    {
        FLIT("hippopotamus"),
        FLIT("cat"), FLIT("pig"), FLIT("gnu"), FLIT("bat"),
        FLIT("dog"), FLIT("cow"), FLIT("fox"), FLIT("rat")
    };
    \endcode
    Notice the two #__flash's in the declarator: The left one says that the
    pointed-to strings are in #__flash, whereas the right one says that
    the \c animals3[] array itself resides in #__flash.

    Unfortunately, to date (avr-gcc v15), #FLIT can only be used at
    global scope.  Though what works in a function is using
    \c constexpr as introduced in C23:
    \code
    void func (int i)
    {
        static constexpr __flash char s_hip[] = "hippopotamus";
        static constexpr __flash char s_cat[] = "cat";
        // ...
        static const __flash char* const __flash animals4[] =
        {
            s_hip, s_cat, // ...
        };
        printf_FSTR ("Animal %d = %S\n", i, animals4[i]);
    }
    \endcode  */
#define FLIT(str) ((const __flash char[]) { str })

/** \ingroup avr_flash
    Turn string literal \p str into a compound literal in address-space
    #__flashx. This macro can be used to construct arrays of string pointers.

    For example code and usage, see the #FLIT macro.  */
#define FXLIT(str) ((const __flashx char[]) { str })

/** \name Functions from string.h, but one argument is in address-space __flash */

/** \ingroup avr_flash
    \fn const __flash void * memchr_F(const __flash void *s, int val, size_t len)
    \brief Scan flash memory for a character.

    The #memchr_F function scans the first \p len bytes of the flash
    memory area pointed to by \p s for the character \p val.  The first
    byte to match \p val (interpreted as an unsigned character) stops
    the operation.

    \return The #memchr_F function returns a pointer to the matching
    byte or \c NULL if the character does not occur in the given memory
    area.  */
extern const __flash void * memchr_F(const __flash void *, int, size_t);

/** \ingroup avr_flash
    \fn int memcmp_F(const void *s1, const __flash void *s2, size_t len)
    \brief Compare memory areas

    The #memcmp_F function compares the first \p len bytes of the memory
    areas \p s1 and flash \p s2. The comparision is performed using unsigned
    char operations.

    \returns The #memcmp_F function returns an integer less than, equal
    to, or greater than zero if the first \p len bytes of \p s1 is found,
    respectively, to be less than, to match, or be greater than the first
    \p len bytes of \p s2.  */
extern int memcmp_F(const void *, const __flash void *, size_t);

/** \ingroup avr_flash
    \fn void *memccpy_F(void *dest, const __flash void *src, int val, size_t len)

    This function is similar to #memccpy except that \p src is pointer
    to a string in address-space #__flash.  */
extern void *memccpy_F(void *, const __flash void *, int val, size_t);

/** \ingroup avr_flash
    \fn void *memcpy_F(void *dest, const __flash void *src, size_t n)

    The #memcpy_F function is similar to #memcpy, except the src string
    resides in address-space __flash.

    \returns The #memcpy_F function returns a pointer to dest.  */
extern void *memcpy_F(void *, const __flash void *, size_t);

/** \ingroup avr_flash
    \fn void *memmem_F(const void *s1, size_t len1, const __flash void *s2, size_t len2)

    The #memmem_F function is similar to #memmem except that \p s2 is
    pointer to a string in address-space #__flash.  */
extern void *memmem_F(const void *, size_t, const __flash void *, size_t);

/** \ingroup avr_flash
    \fn const __flash void *memrchr_F(const __flash void *src, int val, size_t len)

    The #memrchr_F function is like the #memchr_F function, except
    that it searches backwards from the end of the \p len bytes pointed
    to by \p src instead of forwards from the front. (Glibc, GNU extension.)

    \return The #memrchr_F function returns a pointer to the matching
    byte or \c NULL if the character does not occur in the given memory
    area.  */
extern const __flash void * memrchr_F(const __flash void *, int val, size_t len);


/** \ingroup avr_flash
    \fn size_t strlen_F(const __flash char *src)

    The #strlen_F function is similar to #strlen, except that \p src is a
    pointer to a string in address-space #__flash.

    \returns The #strlen_F function returns the number of characters in \p src.

    \note #strlen_F is implemented as an inline function in the avr/flash.h
    header file, which will check if the length of the string is a constant
    and known at compile time. If it is not known at compile time, the macro
    will issue a call to a libc function which will then calculate the length
    of the string as usual.  */
static inline size_t strlen_F(const __flash char *src);

/** \ingroup avr_flash
    \fn char *strcat_F(char *dest, const __flash char *src)

    The #strcat_F function is similar to #strcat except that the \p src
    string must be located in address-space #__flash.

    \returns The #strcat function returns a pointer to the resulting string
    \p dest. */
extern char *strcat_F(char *, const __flash char *);

/** \ingroup avr_flash
    \fn const __flash char *strchr_F(const __flash char *s, int val)
    \brief Locate character in a string in address-space #__flash.

    The #strchr_F function locates the first occurrence of \p val
    (converted to a char) in the string pointed to by \p s in address-space
    #__flash. The terminating NULL character is considered to be part of
    the string.

    The #strchr_F function is similar to #strchr except that \p s is
    pointer to a string in address-space #__flash.

    \returns The #strchr_F function returns a pointer to the matched
    character or \c NULL if the character is not found. */
extern const __flash char * strchr_F(const __flash char *, int val);

/** \ingroup avr_flash
    \fn const __flash char *strchrnul_F(const __flash char *s, int c)

    The #strchrnul_F function is like #strchr_F except that if \p c is
    not found in \p s, then it returns a pointer to the NULL byte at the
    end of \p s, rather than \c NULL. (Glibc, GNU extension.)

    \return The #strchrnul_F function returns a pointer to the matched
    character, or a pointer to the NULL byte at the end of \p s (i.e.,
    \c s+strlen(s)) if the character is not found.  */
extern const __flash char * strchrnul_F(const __flash char *, int val);

/** \ingroup avr_flash
    \fn int strcmp_F(const char *s1, const __flash char *s2)

    The #strcmp_F function is similar to #strcmp except that \p s2 is
    pointer to a string in address-space #__flash.

    \returns The #strcmp_F function returns an integer less than, equal
    to, or greater than zero if \p s1 is found, respectively, to be less
    than, to match, or be greater than \p s2. A consequence of the
    ordering used by #strcmp_F is that if \p s1 is an initial substring
    of \p s2, then \p s1 is considered to be "less than" \p s2. */
extern inline int strcmp_F(const char *, const __flash char *);

/** \ingroup avr_flash
    \fn char *strcpy_F(char *dest, const __flash char *src)

    The #strcpy_F function is similar to #strcpy except that src is a
    pointer to a string in address-space #__flash.

    \returns The #strcpy_F function returns a pointer to the destination
    string dest. */
extern inline char *strcpy_F(char *, const __flash char *);

/** \ingroup avr_flash
    \fn char *stpcpy_F(char *dest, const __flash char *src)

    The #stpcpy_F function is similar to #stpcpy except that \p src is a
    pointer to a string in address-space #__flash.

    \returns #stpcpy_F returns a pointer to the <b>end</b> of
    the string \p dest (that is, the address of the terminating null byte)
    rather than the beginning.  */
extern inline char *stpcpy_F(char *, const __flash char *);

/** \ingroup avr_flash
    \fn int strcasecmp_F(const char *s1, const __flash char *s2)
    \brief Compare two strings ignoring case.

    The #strcasecmp_F function compares the two strings \p s1 and \p s2,
    ignoring the case of the characters.

    \param s1 A pointer to a string in SRAM.
    \param s2 A pointer to a string in address-space #__flash.

    \returns The #strcasecmp_F function returns an integer less than,
    equal to, or greater than zero if \p s1 is found, respectively, to
    be less than, to match, or be greater than \p s2. A consequence of
    the ordering used by #strcasecmp_F is that if \p s1 is an initial
    substring of \p s2, then \p s1 is considered to be "less than" \p s2. */
extern int strcasecmp_F(const char *, const __flash char *);

/** \ingroup avr_flash
    \fn char *strcasestr_F(const char *s1, const __flash char *s2)

    This function is similar to #strcasestr except that \p s2 is pointer
    to a string in address-space #__flash.  */
extern char *strcasestr_F(const char *, const __flash char *);

/** \ingroup avr_flash
    \fn size_t strcspn_F(const char *s, const __flash char *reject)

    The #strcspn_F function calculates the length of the initial segment
    of \p s which consists entirely of characters not in \p reject. This
    function is similar to #strcspn except that \p reject is a pointer
    to a string in address-space #__flash.

    \return The #strcspn_F function returns the number of characters in
    the initial segment of \p s which are not in the string \p reject.
    The terminating zero is not considered as a part of string.  */
extern size_t strcspn_F(const char *s, const __flash char *reject);

/** \ingroup avr_flash
    \fn size_t strlcat_F(char *dst, const __flash char *src, size_t siz)
    \brief Concatenate two strings.

    The #strlcat_F function is similar to #strlcat, except that the \p src
    string must be located in address-space #__flash.

    Appends \p src to string \p dst of size \p siz (unlike #strncat,
    \p siz is the full size of \p dst, not space left).  At most \p siz-1
    characters will be copied.  Always NULL terminates (unless \p siz <=
    \p strlen(dst)).

    \returns The #strlcat_F function returns strlen(src) + MIN(siz,
    strlen(initial dst)).  If retval >= siz, truncation occurred.  */
extern size_t strlcat_F(char *, const __flash char *, size_t);

/** \ingroup avr_flash
    \fn size_t strlcpy_F(char *dst, const __flash char *src, size_t siz)
    \brief Copy a string from address-space #__flash to RAM.

    Copy \p src to string \p dst of size \p siz.  At most \p siz-1
    characters will be copied.  Always NULL terminates (unless \p siz == 0).
    The #strlcpy_F function is similar to #strlcpy except that the
    \p src is pointer to a string in address-space #__flash.

    \returns The #strlcpy_F function returns strlen(src). If
    retval >= siz, truncation occurred.  */
extern size_t strlcpy_F(char *, const __flash char *, size_t);

/** \ingroup avr_flash
    \fn size_t strnlen_F(const __flash char *src, size_t len)
    \brief Determine the length of a fixed-size string.

    The #strnlen_F function is similar to #strnlen, except that \c src is a
    pointer to a string in address-space #__flash.

    \returns The #strnlen_F function returns strlen_F(src), if that is less than
    \c len, or \c len if there is no '\\0' character among the first \c len
    characters pointed to by \c src. */
extern size_t strnlen_F(const __flash char *, size_t);

/** \ingroup avr_flash
    \fn int strncmp_F(const char *s1, const __flash char *s2, size_t n)

    The #strncmp_F function is similar to #strcmp_F except it only compares
    the first (at most) n characters of s1 and s2.

    \returns The #strncmp_F function returns an integer less than, equal to,
    or greater than zero if s1 (or the first n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than s2.  */
extern int strncmp_F(const char *, const __flash char *, size_t);

/** \ingroup avr_flash
    \fn int strncasecmp_F(const char *s1, const __flash char *s2, size_t n)
    \brief Compare two strings ignoring case.

    The #strncasecmp_F function is similar to #strcasecmp_F, except it
    only compares the first \p n characters of \p s1.

    \param s1 A pointer to a string in SRAM.
    \param s2 A pointer to a string in address-space #__flash.
    \param n The maximum number of bytes to compare.

    \returns The #strncasecmp_F function returns an integer less than,
    equal to, or greater than zero if \p s1 (or the first \p n bytes
    thereof) is found, respectively, to be less than, to match, or be
    greater than \p s2. A consequence of the ordering used by
    #strncasecmp_F is that if \p s1 is an initial substring of \p s2,
    then \p s1 is considered to be "less than" \p s2.  */
extern int strncasecmp_F(const char *, const __flash char *, size_t);

/** \ingroup avr_flash
    \fn char *strncat_F(char *dest, const __flash char *src, size_t len)
    \brief Concatenate two strings.

    The #strncat_F function is similar to #strncat, except that the \p src
    string must be located in address-space #__flash.

    \returns The #strncat_F function returns a pointer to the resulting string
    dest.  */
extern char *strncat_F(char *, const __flash char *, size_t);

/** \ingroup avr_flash
    \fn char *strncpy_F(char *dest, const __flash char *src, size_t n)

    The #strncpy_F function is similar to #strcpy_F except that not more
    than \p n bytes of src are copied.  Thus, if there is no null byte among
    the first \p n bytes of \p src, the result will not be null-terminated.

    In the case where the length of \p src is less than that of \p n,
    the remainder of \p dest will be padded with nulls.

    \returns The #strncpy_F function returns a pointer to the destination
    string dest.  */
extern char *strncpy_F(char *, const __flash char *, size_t);

/** \ingroup avr_flash
    \fn char *strpbrk_F(const char *s, const __flash char *accept)

    The #strpbrk_F function locates the first occurrence in the string
    \p s of any of the characters in the #__flash string \p accept. This
    function is similar to #strpbrk except that \p accept is a pointer
    to a string in address-space #__flash.

    \return  The #strpbrk_F function returns a pointer to the character
    in \p s that matches one of the characters in \p accept, or \c NULL
    if no such character is found. The terminating zero is not considered
    as a part of string: If one or both args are empty, the result will
    \c NULL. */
extern char *strpbrk_F(const char *, const __flash char * accept);

/** \ingroup avr_flash
    \fn const __flash char *strrchr_F(const __flash char *s, int val)
    \brief Locate character in string.

    The #strrchr_F function returns a pointer to the last occurrence of
    the character \p val in the #__flash string \p s.

    \return The #strrchr_F function returns a pointer to the matched
    character or \c NULL if the character is not found. */
extern const __flash char * strrchr_F(const __flash char *, int val);

/** \ingroup avr_flash
    \fn char *strsep_F(char **sp, const __flash char *delim)
    \brief Parse a string into tokens.

    The #strsep_F function locates, in the string referenced by \p *sp,
    the first occurrence of any character in the string \p delim (or the
    terminating '\\0' character) and replaces it with a '\\0'.  The
    location of the next character after the delimiter character (or \c
    NULL, if the end of the string was reached) is stored in \p *sp. An
    ``empty'' field, i.e. one caused by two adjacent delimiter
    characters, can be detected by comparing the location referenced by
    the pointer returned in \p *sp to '\\0'. This function is similar to
    #strsep except that \p delim is a pointer to a string in address-space
    #__flash.

    \return The #strsep_F function returns a pointer to the original
    value of \p *sp. If \p *sp is initially \c NULL, #strsep_F returns
    \c NULL. */
extern char *strsep_F(char **sp, const __flash char * delim);

/** \ingroup avr_flash
    \fn size_t strspn_F(const char *s, const __flash char *accept)

    The #strspn_F function calculates the length of the initial segment
    of \p s which consists entirely of characters in \p accept. This
    function is similar to #strspn except that \p accept is a pointer
    to a string in address-space #__flash.

    \return  The #strspn_F function returns the number of characters in
    the initial segment of \p s which consist only of characters from \p
    accept. The terminating zero is not considered as a part of string.  */
extern size_t strspn_F(const char *s, const __flash char * accept);

/** \ingroup avr_flash
    \fn char *strstr_F(const char *s1, const __flash char *s2)
    \brief Locate a substring.

    The #strstr_F function finds the first occurrence of the substring
    \p s2 in the string \p s1.  The terminating '\\0' characters are not
    compared. The #strstr_F function is similar to #strstr except that
    \p s2 is pointer to a string in address-space #__flash.

    \returns The #strstr_F function returns a pointer to the beginning
    of the substring, or NULL if the substring is not found. If \p s2
    points to a string of zero length, the function returns \p s1. */
extern char *strstr_F(const char *, const __flash char *);

/** \ingroup avr_flash
    \fn char *strtok_F(char *s, const __flash char * delim)
    \brief Parses the string into tokens.

    #strtok_F parses the string \p s into tokens. The first call to
    #strtok_F should have \p s as its first argument. Subsequent calls
    should have the first argument set to NULL. If a token ends with a
    delimiter, this delimiting character is overwritten with a '\\0' and a
    pointer to the next character is saved for the next call to #strtok_F.
    The delimiter string \p delim may be different for each call.

    The #strtok_F function is similar to #strtok except that \p delim
    is pointer to a string in address-space #__flash.

    \returns The #strtok_F function returns a pointer to the next token or
    NULL when no more tokens are found.

    \note #strtok_F is NOT reentrant. For a reentrant version of this
    function see #strtok_rF.
 */
extern char *strtok_F(char *s, const __flash char * delim);

/** \ingroup avr_flash
    \fn char *strtok_rF(char *string, const __flash char *delim, char **last)
    \brief Parses string into tokens.

    The #strtok_rF function parses \p string into tokens. The first call to
    #strtok_rF should have \p string as its first argument. Subsequent calls
    should have the first argument set to NULL. If a token ends with a
    delimiter, this delimiting character is overwritten with a '\\0' and a
    pointer to the next character is saved for the next call to #strtok_rF.
    The delimiter string \p delim may be different for each call. \p last is
    a user allocated <tt>char*</tt> pointer. It must be the same while
    parsing the same string. #strtok_rF is a reentrant version of #strtok_F.

    The #strtok_rF function is similar to #strtok_r except that \p delim
    is pointer to a string in address-space #__flash.

    \returns The #strtok_rF function returns a pointer to the next token or
    NULL when no more tokens are found. */
extern char *strtok_rF(char *s, const __flash char * delim, char **last);


/** \name Functions from string.h, but one argument is in 24-bit address-space __flashx */

/** \ingroup avr_flash
    \fn void *memcpy_FX(void *dest, const __flashx void *src, size_t n)
    \brief Copy a memory block from address-space __flashx to SRAM

    The #memcpy_FX function is similar to #memcpy, except the data
    is copied from address-space #__flashx and is addressed using an
    according pointer.

    \param dest A pointer to the destination buffer.
    \param src A pointer to the origin of data in #__flashx.
    \param n The number of bytes to be copied.

    \returns The #memcpy_FX function returns a pointer to \e dst. */
extern void *memcpy_FX(void *dest, const __flashx void *src, size_t len);

/** \ingroup avr_flash
    \fn int memcmp_FX(const void *s1, const __flashx void *s2, size_t len)
    \brief Compare memory areas

    The #memcmp_FX function compares the first \p len bytes of the memory
    areas \p s1 and __flashx \p s2. The comparision is performed using unsigned
    char operations. It is an equivalent of #memcmp_F function, except
    that it is capable working on all Flash including the extended area
    above 64 KiB.

    \returns The #memcmp_FX function returns an integer less than, equal
    to, or greater than zero if the first \p len bytes of \p s1 is found,
    respectively, to be less than, to match, or be greater than the first
    \p len bytes of \p s2.  */
extern int memcmp_FX(const void *s1, const __flashx void *s2, size_t);

/** \ingroup avr_flash
    \fn size_t strlen_FX(const __flashx char *s)
    \brief Obtain the length of a string located in address-space #__flashx

    The #strlen_FX function is similar to #strlen, except that \e s is a
    pointer to a string in address-space #__flashx.

    \returns The #strlen_FX function returns the number of characters in
    \e s. */
extern size_t strlen_FX(const __flashx char *src);

/** \ingroup avr_flash
    \fn size_t strnlen_FX(const __flashx char *s, size_t len)
    \brief Determine the length of a fixed-size string in address-space __flashx

    The #strnlen_FX function is similar to #strnlen, except that \e s is a
    pointer to a string in address-space #__flashx.

    \param s The address of a string in #__flashx.
    \param len The maximum number of length to return.

    \returns The #strnlen_FX function returns strlen_FX(\e s), if that is less
    than \e len, or \e len if there is no '\\0' character among the first \e
    len characters pointed to by \e s.  */
extern size_t strnlen_FX(const __flashx char *src, size_t len);

/** \ingroup avr_flash
    \fn char *strcpy_FX(char *dst, const __flashx char *src)
    \brief Duplicate a string from address-space __flashx

    The #strcpy_FX function is similar to #strcpy except that \e src is a
    string located in address-space #__flashx.

    \param dst A pointer to the destination string in SRAM.
    \param src A pointer to the source string in #__flashx.

    \returns The #strcpy_FX function returns a pointer to the destination
    string \e dst. */
extern char *strcpy_FX(char *dest, const __flashx char *src);

/** \ingroup avr_flash
    \fn char *stpcpy_FX(char *dst, const __flashx char *src)
    \brief Duplicate a string from address-space __flashx

    The #stpcpy_FX function is similar to #stpcpy except that \e src
    is a string located in address-space #__flashx.

    \param dst A pointer to the destination string in SRAM.
    \param src A pointer to the source string in #__flashx.

    \returns The stpcpy_PF() function returns a pointer to the
    terminating '\\0' character of the destination string \e dst.  */
extern char *stpcpy_FX(char *dest, const __flashx char *src);

/** \ingroup avr_flash
    \fn char *strncpy_FX(char *dst, const __flashx char *src, size_t n)
    \brief Duplicate a string from address-space __flashx until a limited length

    The #strncpy_FX function is similar to #strcpy_FX except that not more
    than \e n bytes of \e src are copied.  Thus, if there is no null byte among
    the first \e n bytes of \e src, the result will not be null-terminated.

    In the case where the length of \e src is less than that of \e n, the
    remainder of \e dst will be padded with nulls.

    \param dst A pointer to the destination string in SRAM.
    \param src A far pointer to the source string in address-space #__flashx.
    \param n The maximum number of bytes to copy.

    \returns The #strncpy_FX function returns a pointer to the destination
    string \e dst. */
extern char *strncpy_FX(char *dest, const __flashx char *src, size_t len);

/** \ingroup avr_flash
    \fn char *strcat_FX(char *dst, const __flashx char *src)
    \brief Concatenates two strings

    The #strcat_FX function is similar to #strcat except that the \e src
    string must be located in address-space #__flashx.

    \param dst A pointer to the destination string in SRAM.
    \param src A pointer to the string located in #__flashx to be appended.

    \returns The #strcat_FX function returns a pointer to the resulting
    string \e dst. */
extern char *strcat_FX(char *dest, const __flashx char *src);

/** \ingroup avr_flash
    \fn size_t strlcat_FX(char *dst, const __flashx char *src, size_t n)
    \brief Concatenate two strings

    The #strlcat_FX function is similar to #strlcat, except that the \e src
    string must be located in address-space #__flashx.

    Appends src to string dst of size \e n (unlike #strncat, \e n is the
    full size of \e dst, not space left).  At most \e n-1 characters
    will be copied.  Always NULL terminates (unless \e n <= strlen(\e dst)).

    \param dst A pointer to the destination string in SRAM.
    \param src A pointer to the source string in __flashx.
    \param n The total number of bytes allocated to the destination string.

    \returns The #strlcat_FX function returns strlen(\e src) + MIN(\e n,
    strlen(initial \e dst)).  If retval >= \e n, truncation occurred. */
extern size_t strlcat_FX(char *dst, const __flashx char *src, size_t siz);

/** \ingroup avr_flash
    \fn char *strncat_FX(char *dst, const __flashx char *src, size_t n)
    \brief Concatenate two strings

    The #strncat_FX function is similar to #strncat, except that the \e src
    string must be located in address-space __flashx.

    \param dst A pointer to the destination string in SRAM.
    \param src A pointer to the source string in __flashx.
    \param n The maximum number of bytes to append.

    \returns The #strncat_FX function returns a pointer to the resulting
    string \e dst. */
extern char *strncat_FX(char *dest, const __flashx char *src, size_t len);

/** \ingroup avr_flash
    \fn int strcmp_FX(const char *s1, const __flashx char *s2)
    \brief Compares two strings

    The #strcmp_FX function is similar to #strcmp except that \e s2 is a
    pointer to a string in address-space #__flashx.

    \param s1 A pointer to the first string in SRAM.
    \param s2 A pointer to the second string in #__flashx.

    \returns The #strcmp_FX function returns an integer less than, equal to,
    or greater than zero if \e s1 is found, respectively, to be less than, to
    match, or be greater than \e s2. */
extern int strcmp_FX(const char *s1, const __flashx char *s2);

/** \ingroup avr_flash
    \fn int strncmp_FX(const char *s1, const __flashx char *s2, size_t n)
    \brief Compare two strings with limited length

    The #strncmp_FX function is similar to #strcmp_FX except it only
    compares the first (at most) \e n characters of \e s1 and \e s2.

    \param s1 A pointer to the first string in SRAM.
    \param s2 A pointer to the second string in address-space #__flashx.
    \param n The maximum number of bytes to compare.

    \returns The #strncmp_FX function returns an integer less than, equal
    to, or greater than zero if \e s1 (or the first \e n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than \e s2. */
extern int strncmp_FX(const char *s1, const __flashx char *s2, size_t n);

/** \ingroup avr_flash
    \fn int strcasecmp_FX(const char *s1, const __flashx char *s2)
    \brief Compare two strings ignoring case

    The #strcasecmp_FX function compares the two strings \e s1 and \e s2,
    ignoring the case of the characters.

    \param s1 A pointer to the first string in SRAM.
    \param s2 A pointer to the second string in address-space #__flashx.

    \returns The #strcasecmp_FX function returns an integer less than, equal
    to, or greater than zero if \e s1 is found, respectively, to be less than,
    to match, or be greater than \e s2. */
extern int strcasecmp_FX(const char *s1, const __flashx char *s2);

/** \ingroup avr_flash
    \fn int strncasecmp_FX(const char *s1, const __flashx char *s2, size_t n)
    \brief Compare two strings ignoring case

    The #strncasecmp_FX function is similar to #strcasecmp_FX, except it
    only compares the first \e n characters of \e s1, and the string \e s2
    is located in address-space #__flashx.

    \param s1 A pointer to a string in SRAM.
    \param s2 A pointer to a string in #__flashx.
    \param n The maximum number of bytes to compare.

    \returns The #strncasecmp_FX function returns an integer less than, equal
    to, or greater than zero if \e s1 (or the first \e n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than \e s2. */
extern int strncasecmp_FX(const char *s1, const __flashx char *s2, size_t n);

/** \ingroup avr_flash
    \fn const __flashx char *strchr_FX(const __flashx char *s, int val)
    \brief Locate a character in a string located in address-space #__flashx

    The #strchr_FX function locates the first occurrence of \p val
    (converted to a char) in the string pointed to by \p s in address-space
    #__flashx. The terminating null character is considered to be part of
    the string.

    The #strchr_FX function is similar to #strchr except that \p s is
    a pointer to a string in address-space #__flashx that's \e not
    \e required to be located in the lower 64 KiB block like it is
    the case  for #strchr_F.

    \returns The #strchr_FX function returns a far pointer to the matched
    character or \c 0 if the character is not found. */
extern const __flashx char *strchr_FX(const __flashx char *s, int val);

/** \ingroup avr_flash
    \fn char *strstr_FX(const char *s1, const __flashx char *s2)
    \brief Locate a substring.

    The #strstr_FX function finds the first occurrence of the substring \c s2
    in the string \c s1.  The terminating '\\0' characters are not
    compared.
    The #strstr_FX function is similar to #strstr except that \c s2 points
    to a string located in address-space #__flashx.

    \returns The #strstr_FX function returns a pointer to the beginning of the
    substring, or NULL if the substring is not found.
    If \c s2 points to a string of zero length, the function returns \c s1. */
extern char *strstr_FX(const char *s1, const __flashx char *s2);

/** \ingroup avr_flash
    \fn size_t strlcpy_FX(char *dst, const __flashx char *src, size_t len)
    \brief Copy a string from address-space #__flashx to RAM.

    Copy src to string dst of length len.  At most len-1 characters will be
    copied. Always NULL terminates (unless len == 0).

    \returns The #strlcpy_FX function returns strlen_FX(src).
    If retval >= len, truncation occurred.  */
extern size_t strlcpy_FX(char *, const __flashx char *, size_t);

/** \name AVR Named Address-Spaces */

/** \ingroup avr_flash
    A <b>named address-space</b> for data in the lower 64 KiB of program memory

    Pointers to #__flash are 16 bits wide.

    Objects in #__flash are located in section
    \ref sec_dot_progmem ".progmem.data",
    which is located \e prior to the code sections by the default linker
    description files.  Similar to #PROGMEM, the assertion is that all
    objects in that section will fit in the lower 64 KiB flash segment
    (flash byte addresses 0x0 ... 0xffff).

    The compiler defines the built-in macro \c __FLASH when this
    address-space is available.  It is supported as part of GNU-C
    (<tt>-std=gnu99</tt> etc.), and is not available on Reduced
    Tiny (core AVRrc).

    \since <a href="https://gcc.gnu.org/gcc-4.7/changes.html#avr">avr-gcc v4.7</a>
    (Release 2012)

    \see <a href="https://gcc.gnu.org/onlinedocs/gcc/Named-Address-Spaces.html#index-_005f_005fflash-AVR-Named-Address-Spaces"
    >avr-gcc: <tt>__flash</tt></a>.
*/
__flash;

/** \ingroup avr_flash
    A <b>named address-space</b> for data in program memory

    Pointers to #__flashx are 24 bits wide.

    Objects in #__flashx are located in section
    \ref sec_dot_progmemx ".progmemx.data",
    which is located \e after the code sections by the default linker
    description files.  There is no restriction on the address range
    occupied by objects in that section, and #__flashx supports
    reading across the 64 KiB segment boundaries.

    The compiler defines the built-in macro \c __FLASHX when this
    address-space is available.  It is supported as part of GNU-C
    (<tt>-std=gnu99</tt> etc.), and is not available on Reduced
    Tiny (core AVRrc).

    \since
    <a href="https://gcc.gnu.org/gcc-15/changes.html#avr">avr-gcc v15</a>
    (Release 2025)

    \see <a href="https://gcc.gnu.org/onlinedocs/gcc/Named-Address-Spaces.html#index-_005f_005fflashx-AVR-Named-Address-Spaces"
    >avr-gcc: <tt>__flashx</tt></a>.
*/
__flashx;


/** \ingroup avr_flash
    A <b>named address-space</b> for data in program memory or RAM

    Pointers to #__memx are 24 bits wide.

    Objects in #__memx are located in section
    \ref sec_dot_progmemx ".progmemx.data",
    which is located \e after the code sections by the default linker
    description files.  There is no restriction on the address range
    occupied by objects in that section, and #__memx supports
    reading across the 64 KiB flash segment boundaries.

    #__memx pointers can also hold RAM addresses, and reading from
    #__memx reads from RAM or from program memory depending on the
    most significant bit of the address.

    The compiler defines the built-in macro \c __MEMX when this
    address-space is available.  It is supported as part of GNU-C
    (<tt>-std=gnu99</tt> etc.), and is not available on Reduced
    Tiny (core AVRrc).
    To date, AVR-LibC does not have support for functions operating
    on #__memx.

    \since
    <a href="https://gcc.gnu.org/gcc-4.7/changes.html#avr">avr-gcc v4.7</a>
    (Release 2012)

    \see <a href="https://gcc.gnu.org/onlinedocs/gcc/Named-Address-Spaces.html#index-_005f_005fmemx-AVR-Named-Address-Spaces"
    >avr-gcc: <tt>__memx</tt></a>.
*/
__memx;


#endif /* __DOXYGEN__ */

/** \name Convenience macros for functions from stdio.h, that allocate the format string with FSTR */

/** \ingroup avr_flash
    A convenience macro that wraps #vfprintf_F's format string with #FSTR.
*/
#define vfprintf_FSTR(stream, fmt, ap) vfprintf_F(stream, FSTR(fmt), ap)

/** \ingroup avr_flash
    A convenience macro that wraps #printf_F's format string with #FSTR.
*/
#define printf_FSTR(fmt, ...) printf_F(FSTR(fmt), ##__VA_ARGS__)

/** \ingroup avr_flash
    A convenience macro that wraps #sprintf_F's format string with #FSTR.
*/
#define sprintf_FSTR(s, fmt, ...) sprintf_F(s, FSTR(fmt), ##__VA_ARGS__)

/** \ingroup avr_flash
    A convenience macro that wraps #snprintf_F's format string with #FSTR.
*/
#define snprintf_FSTR(s, n, fmt, ...) snprintf_F(s, n, FSTR(fmt), ##__VA_ARGS__)

/** \ingroup avr_flash
    A convenience macro that wraps #vsprintf_F's format string with #FSTR.
*/
#define vsprintf_FSTR(s, fmt, ap) vsprintf_F(s, FSTR(fmt), ap)

/** \ingroup avr_flash
    A convenience macro that wraps #vsnprintf_F's format string with #FSTR.
*/
#define vsnprintf_FSTR(s, n, fmt, ap) vsnprintf_F(s, n, FSTR(fmt), ap);

/** \ingroup avr_flash
    A convenience macro that wraps #fprintf_F's format string with #FSTR.
*/
#define fprintf_FSTR(stream, fmt, ...) fprintf_F(stream, FSTR(fmt), ##__VA_ARGS__)

/** \ingroup avr_flash
    A convenience macro that wraps #fputs_F's string with #FSTR.
*/
#define fputs_FSTR(str, stream) fputs_F(FSTR(str), stream);

/** \ingroup avr_flash
    A convenience macro that wraps #puts_F's string with #FSTR.
*/
#define puts_FSTR(str) puts_F(FSTR(str));

/** \ingroup avr_flash
    A convenience macro that wraps #vfscanf_F's format string with #FSTR.
*/
#define vfscanf_FSTR(stream, fmt, ap) vfscanf_F(stream, FSTR(fmt), ap);

/** \ingroup avr_flash
    A convenience macro that wraps #fscanf_F's format string with #FSTR.
*/
#define fscanf_FSTR(stream, fmt, ...) fscanf_F(stream, FSTR(fmt), ##__VA_ARGS__)

/** \ingroup avr_flash
    A convenience macro that wraps #scanf_F's format string with #FSTR.
*/
#define scanf_FSTR(fmt, ...) scanf_F(FSTR(fmt), ##__VA_ARGS__)

/** \ingroup avr_flash
    A convenience macro that wraps #sscanf_F's format string with #FSTR.
*/
#define sscanf_FSTR(buf, fmt, ...) sscanf_F(buf, FSTR(fmt), ##__VA_ARGS__)

#ifdef __DOXYGEN__

/** \name Functions from stdio.h, but with a format string in address-space __flash */

/** \ingroup avr_flash
    Variant of \c #vfprintf that uses a \c fmt string that resides
    in address-space #__flash.  See also #vfprintf_FSTR.
*/
extern int vfprintf_F(FILE *stream, const __flash char *fmt, va_list ap);

/** \ingroup avr_flash
    Variant of \c #printf that uses a \c fmt string that resides
    in address-space #__flash.  See also #printf_FSTR.
*/
extern int printf_F(const __flash char *fmt, ...);

/** \ingroup avr_flash
    Variant of \c #sprintf that uses a \c fmt string that resides
    in address-space #__flash.  See also #sprintf_FSTR.
*/
extern int sprintf_F(char *s, const __flash char *fmt, ...);

/** \ingroup avr_flash
    Variant of \c #snprintf that uses a \c fmt string that resides
    in address-space #__flash.  See also #snprintf_FSTR.
*/
extern int snprintf_F(char *s, size_t n, const __flash char *fmt, ...);

/** \ingroup avr_flash
    Variant of \c #vsprintf that uses a \c fmt string that resides
    in address-space #__flash.  See also #vsprintf_FSTR.
*/
extern int vsprintf_F(char *s, const __flash char *fmt, va_list ap);

/** \ingroup avr_flash
    Variant of \c #vsnprintf that uses a \c fmt string that resides
    in address-space #__flash.  See also #vsnprintf_FSTR.
*/
extern int vsnprintf_F(char *s, size_t n, const __flash char *fmt, va_list ap);

/** \ingroup avr_flash
    Variant of \c #fprintf that uses a \c fmt string that resides
    in address-space #__flash.  See also #fprintf_FSTR.
*/
extern int fprintf_F(FILE *stream, const __flash char *fmt, ...);

/** \ingroup avr_flash
    Variant of #fputs where \c str resides in address-space #__flash.
    See also #fputs_FSTR.
*/
extern int fputs_F(const __flash char *str, FILE *stream);

/** \ingroup avr_flash
    Variant of #puts where \c str resides in address-space #__flash.
    See also #puts_FSTR.
*/
extern int puts_F(const __flash char *str);

/** \ingroup avr_flash
    Variant of #vfscanf using a \c fmt string in address-space #__flash.
    See also #vfscanf_FSTR.
*/
extern int vfscanf_F(FILE *stream, const __flash char *fmt, va_list ap);

/** \ingroup avr_flash
    Variant of #fscanf using a \c fmt string in address-space #__flash.
    See also #fscanf_FSTR.
*/
extern int fscanf_F(FILE *stream, const __flash char *fmt, ...);

/** \ingroup avr_flash
    Variant of #scanf where \c fmt resides in address-space #__flash.
    See also #scanf_FSTR.
*/
extern int scanf_F(const __flash char *fmt, ...);

/** \ingroup avr_flash
    Variant of #sscanf using a \c fmt string in address-space #__flash.
    See also #sscanf_FSTR.
*/
extern int sscanf_F(const char *buf, const __flash char *fmt, ...);


/** \name More efficient reading of 64-bit values from __flash and __flashx */

/** \ingroup avr_flash
    \fn uint64_t flash_read_u64 (const __flash uint64_t *addr)
    Read an <tt>uint64_t</tt> from 16-bit #__flash address \p addr. */
static inline uint64_t flash_read_u64 (const __flash uint64_t *addr);

/** \ingroup avr_flash
    \fn int64_t flash_read_i64 (const __flash int64_t *addr)
    Read an <tt>int64_t</tt> from 16-bit #__flash address \p addr. */
static inline int64_t flash_read_i64 (const __flash int64_t *addr);

/** \ingroup avr_flash
    \fn double flash_read_double (const __flash double *addr)
    Read a <tt>double</tt> from 16-bit __flash address \p addr. */
static inline double flash_read_double (const __flash double *addr);

/** \ingroup avr_flash
    \fn long double flash_read_long_double (const __flash long double *addr)
    Read a <tt>long double</tt> from 16-bit #__flash address \p addr. */
static inline long double flash_read_long_double (const __flash long double *addr);


/** \ingroup avr_flash
    \fn uint64_t flashx_read_u64 (const __flashx uint64_t *addr)
    Read an <tt>uint64_t</tt> from 24-bit #__flashx address \p addr. */
static inline uint64_t flashx_read_u64 (const __flashx uint64_t *addr);

/** \ingroup avr_flash
    \fn int64_t flashx_read_i64 (const __flashx int64_t *addr)
    Read an <tt>int64_t</tt> from 24-bit #__flashx address \p addr. */
static inline int64_t flashx_read_i64 (const __flashx int64_t *addr);

/** \ingroup avr_flash
    \fn double flashx_read_double (const __flashx double *addr)
    Read a <tt>double</tt> from 24-bit #__flashx address \p addr. */
static inline double flashx_read_double (const __flashx double *addr);

/** \ingroup avr_flash
    \fn long double flashx_read_long_double (const __flashx long double *addr)
    Read a <tt>long double</tt> from 24-bit #__flashx address \p addr. */
static inline long double flashx_read_long_double (const __flashx long double *addr);


/* ********************************************************************/


#else /* !__DOXYGEN__ */

#define __need_size_t
#include <stddef.h>
#include <bits/attribs.h>

#ifdef __FLASH

#define FSTR(s) (__extension__({static const __flash char __c[] = (s); &__c[0];}))
#define FLIT(lit) ((const __flash char[]) { lit })

extern const __flash void * memchr_F(const __flash void *, int __val, size_t __len) __asm("memchr_P") __ATTR_CONST__;
extern int memcmp_F(const void *, const __flash void *, size_t) __asm("memcmp_P") __ATTR_PURE__;
extern void *memccpy_F(void *, const __flash void *, int __val, size_t) __asm("memccpy_P");
extern void *memcpy_F(void *, const __flash void *, size_t) __asm("memcpy_P");
extern void *memmem_F(const void *, size_t, const __flash void *, size_t) __asm("memmem_P") __ATTR_PURE__;
extern const __flash void * memrchr_F(const __flash void *, int __val, size_t __len) __asm("memrchr_P") __ATTR_CONST__;

extern char *strcat_F(char *, const __flash char *) __asm("strcat_P");

extern const __flash char * strchr_F(const __flash char *, int __val) __asm("strchr_P") __ATTR_CONST__;
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
const __flash char * strchr_F(const __flash char *__hay, int __val)
{
  register const __flash char *__r24 __asm("24") = __hay;
  register int __r22 __asm("22") = __val;
  __asm ("%~call strchr_P"
         : "+r" (__r24) : "r" (__r22) : "0", "30", "31");
  return __r24;
}

extern const __flash char * strchrnul_F(const __flash char *, int __val) __asm("strchrnul_P") __ATTR_CONST__;
extern int strcasecmp_F(const char *, const __flash char *) __asm("strcasecmp_P") __ATTR_PURE__;
extern char *strcasestr_F(const char *, const __flash char *) __asm("strcasestr_P") __ATTR_PURE__;
extern size_t strcspn_F(const char *, const __flash char * __reject) __asm("strcspn_P") __ATTR_PURE__;
extern size_t strnlen_F(const __flash char *, size_t) __asm("strnlen_P") __ATTR_CONST__;
extern int strncmp_F(const char *, const __flash char *, size_t) __asm("strncmp_P") __ATTR_PURE__;
extern int strncasecmp_F(const char *, const __flash char *, size_t) __asm("strncasecmp_P") __ATTR_PURE__;
extern char *strncat_F(char *, const __flash char *, size_t) __asm("strncat_P");
extern char *strncpy_F(char *, const __flash char *, size_t) __asm("strncpy_P");
extern char *strpbrk_F(const char *__s, const __flash char * __accept) __asm("strpbrk_P") __ATTR_PURE__;
extern const __flash char * strrchr_F(const __flash char *, int __val) __asm("strrchr_P") __ATTR_CONST__;
extern char *strsep_F(char **__sp, const __flash char * __delim) __asm("strsep_P");
extern size_t strspn_F(const char *__s, const __flash char * __accept) __asm("strspn_P") __ATTR_PURE__;
extern char *strstr_F(const char *, const __flash char *) __asm("strstr_P") __ATTR_PURE__;
extern char *strtok_F(char *, const __flash char * __delim) __asm("strtok_P");
extern char *strtok_rF(char *, const __flash char * __delim, char **__last) __asm("strtok_rP");

/* memcpy_F is common so we model its GPR footprint.  */
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
void* memcpy_F(void *__x, const __flash void *__z, size_t __s)
{
  register size_t __r20 __asm("20") = __s;
  void *__ret = __x;
  __asm volatile ("%~call __memcpy_P" : "+x" (__x), "+z" (__z), "+r" (__r20)
                  :: "0", "memory");
  return __ret;
}

/* strcmp_F is common so we model strcmp_P's GPR footprint. */
extern int strcmp_F (const char*, const __flash char*) __asm ("strcmp_P");
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
int strcmp_F (const char *__x, const __flash char *__z)
{
  register int __ret __asm("24");
  __asm ("%~call __strcmp_P"
         : "=r" (__ret), "+x" (__x), "+z" (__z) :: "memory");
  return __ret;
}


/* strcpy_F is common so we model strcpy_P's GPR footprint. */
extern char* strcpy_F (char *__x, const __flash char *__z) __asm("strcpy_P");
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
char* strcpy_F (char *__x, const __flash char *__z)
{
  char *__ret = __x;
  __asm volatile ("%~call __strcpy_P"
                  : "+x" (__x), "+z" (__z) :: "0", "memory");
  return __ret;
}


extern char* stpcpy_F (char *__x, const __flash char *__z) __asm("stpcpy_P");
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
char* stpcpy_F (char *__x, const __flash char *__z)
{
  __asm volatile ("%~call __strcpy_P"
                  : "+x" (__x), "+z" (__z) :: "0", "memory");
  return __x - 1;
}


/* strlen_F is common so we model strlen_P's GPR footprint. */
extern size_t strlen_F (const __flash char *__s) __asm("strlen_P");
extern __ATTR_ALWAYS_INLINE__ __ATTR_GNU_INLINE__
size_t strlen_F (const __flash char *__s)
{
#ifdef __BUILTIN_AVR_STRLEN_FLASH
  if (__builtin_constant_p (__builtin_avr_strlen_flash (__s)))
    return __builtin_avr_strlen_flash (__s);
#endif
  {
    register const __flash char *__r24 __asm("24") = __s;
    register size_t __res __asm("24");
    __asm ("%~call strlen_P" : "=r" (__res) : "r" (__r24)
           : "0", "30", "31");
    return __res;
  }
}


#include <stdio.h> /* FILE */

extern int vfprintf_F(FILE *__stream, const __flash char *__fmt, va_list __ap) __asm("vfprintf_P");
extern int printf_F(const __flash char *__fmt, ...) __asm("printf_P");
extern int sprintf_F(char *__s, const __flash char *__fmt, ...) __asm("sprintf_P");
extern int snprintf_F(char *__s, size_t __n, const __flash char *__fmt, ...) __asm("snprintf_P");
extern int vsprintf_F(char *__s, const __flash char *__fmt, va_list ap) __asm("vsprintf_P");
extern int vsnprintf_F(char *__s, size_t __n, const __flash char *__fmt, va_list ap) __asm("vsnprintf_P");
extern int fprintf_F(FILE *__stream, const __flash char *__fmt, ...) __asm("fprintf_P");
extern int fputs_F(const __flash char *__str, FILE *__stream) __asm("fputs_P");
extern int puts_F(const __flash char *__str) __asm("puts_P");
extern int vfscanf_F(FILE *__stream, const __flash char *__fmt, va_list __ap) __asm("vfscanf_P");
extern int fscanf_F(FILE *__stream, const __flash char *__fmt, ...) __asm("fscanf_P");
extern int scanf_F(const __flash char *__fmt, ...) __asm("scanf_P");
extern int sscanf_F(const char *__buf, const __flash char *__fmt, ...) __asm("sscanf_P");
#endif /* Have __flash */

#ifdef __FLASHX

#define FXSTR(s) (__extension__({static const __flashx char __c[] = (s); &__c[0];}))
#define FXLIT(lit) ((const __flashx char[]) { lit })

extern size_t strnlen_FX(const __flashx char *, size_t) __asm("strnlen_PF") __ATTR_CONST__;
extern void *memcpy_FX(void *, const __flashx void *, size_t) __asm("memcpy_PF");
extern char *strcpy_FX(char *, const __flashx char *) __asm("strcpy_PF");
extern char *stpcpy_FX(char *, const __flashx char *) __asm("stpcpy_PF");
extern char *strncpy_FX(char *, const __flashx char *, size_t) __asm("strncpy_PF");
extern char *strcat_FX(char *, const __flashx char *) __asm("strcat_PF");
extern size_t strlcat_FX(char *, const __flashx char *, size_t) __asm("strlcat_PF");
extern char *strncat_FX(char *, const __flashx char *, size_t) __asm("strncat_PF");
extern int strcmp_FX(const char *, const __flashx char *) __asm("strcmp_PF") __ATTR_PURE__;
extern int strncmp_FX(const char *, const __flashx char *, size_t) __asm("strncmp_PF") __ATTR_PURE__;
extern int strcasecmp_FX(const char *, const __flashx char *) __asm("strcasecmp_PF") __ATTR_PURE__;
extern int strncasecmp_FX(const char *, const __flashx char *, size_t) __asm("strncasecmp_PF") __ATTR_PURE__;
extern const __flashx char *strchr_FX(const __flashx char *, int) __asm("strchr_PF") __ATTR_CONST__;
extern char *strstr_FX(const char *, const __flashx char *) __asm("strstr_PF");
extern size_t strlcpy_FX(char *, const __flashx char *, size_t) __asm("strlcpy_PF");
extern int memcmp_FX(const void *, const __flashx void *, size_t) __asm("memcmp_PF") __ATTR_PURE__;

#ifdef __BUILTIN_AVR_STRLEN_FLASHX
extern size_t __strlen_FX(const __flashx char*) __asm("strlen_PF") __ATTR_CONST__;

static inline __ATTR_ALWAYS_INLINE__ size_t
strlen_FX (const __flashx char *__s)
{
  return __builtin_constant_p (__builtin_avr_strlen_flashx (__s))
    ? __builtin_avr_strlen_flashx (__s)
    : __strlen_FX (__s);
}
#else
extern size_t strlen_FX(const __flashx char*) __asm("strlen_PF") __ATTR_CONST__;
#endif /* Have __builtin_avr_strlen_flashx */

#endif /* Have __flashx */


#ifdef __FLASH

#include <stdint.h>
#include <bits/lpm-elpm.h>
#include <bits/def-flash-read.h>

#if __SIZEOF_LONG_LONG__ == 8
_Avrlibc_Def_F_8 (u64, uint64_t)
_Avrlibc_Def_F_8 (i64, int64_t)
#endif

#if __SIZEOF_DOUBLE__ == 8
_Avrlibc_Def_F_8 (double, double)
#else
_Avrlibc_Def_F_4 (double, double)
#endif

#if __SIZEOF_LONG_DOUBLE__ == 8
_Avrlibc_Def_F_8 (long_double, long double)
#else
_Avrlibc_Def_F_4 (long_double, long double)
#endif

#endif /* Have __flash */

#ifdef __FLASHX

#include <bits/lpm-elpm.h>

#if defined(__AVR_HAVE_ELPM__)
#define __ELPM__8fx(r,a,T) __ELPM__8(r,a,T)
#else
#define __ELPM__8fx(r,a,T) uint16_t __a = (uint16_t)(__uint24) a; __LPM__8(r,__a)
#endif


#define _Avrlibc_Def_FX_4(Name, Typ)                    \
  static __ATTR_ALWAYS_INLINE__                         \
  Typ flashx_read_##Name (const __flashx Typ *__addr)   \
  {                                                     \
    return *__addr;                                     \
  }

#define _Avrlibc_Def_FX_8(Name, Typ)                    \
  static __ATTR_ALWAYS_INLINE__                         \
  Typ flashx_read_##Name (const __flashx Typ *__addr)   \
  {                                                     \
    Typ __res;                                          \
    __ELPM__8fx (__res, __addr, Typ);                   \
    return __res;                                       \
  }

#if __SIZEOF_LONG_LONG__ == 8
_Avrlibc_Def_FX_8 (u64, uint64_t)
_Avrlibc_Def_FX_8 (i64, int64_t)
#endif

#if __SIZEOF_DOUBLE__ == 8
_Avrlibc_Def_FX_8 (double, double)
#else
_Avrlibc_Def_FX_4 (double, double)
#endif

#if __SIZEOF_LONG_DOUBLE__ == 8
_Avrlibc_Def_FX_8 (long_double, long double)
#else
_Avrlibc_Def_FX_4 (long_double, long double)
#endif

#endif /* Have __flashx */

#endif /* !DOXYGEN */

#endif /* !__AVR_TINY__ && !C++ */

#endif /* _AVR_FLASH_H_ */
