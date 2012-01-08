/* Copyright (c) 2012  Dmitry Xmelkov
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
   POSSIBILITY OF SUCH DAMAGE.
 */

/* Test of progmem types (this types are deprecated).
   $Id$	*/

#if	__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2)
# pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

#ifndef __AVR__

/* Omit the test.	*/
int main ()	{ return 0; }

#else

#define __PROG_TYPES_COMPAT__
#include <avr/pgmspace.h>

#define pgm_read_qword(addr)	({			\
    union {						\
	unsigned long __dw[2];				\
	unsigned long long __qw[1];			\
    } __u;						\
    __u.__dw[0] = pgm_read_dword (addr);		\
    __u.__dw[1] = pgm_read_dword ((void *)addr + 4);	\
    __u.__qw[0];					\
  })


#define DCLEXT(prefix, array) \
    const prog_char	prefix##_char   array;	\
    const prog_uchar	prefix##_uchar  array;	\
    const prog_int8_t	prefix##_int8	array;	\
    const prog_uint8_t	prefix##_uint8	array;	\
    const prog_int16_t	prefix##_int16	array;	\
    const prog_uint16_t	prefix##_uint16	array;	\
    const prog_int32_t	prefix##_int32	array;	\
    const prog_uint32_t	prefix##_uint32	array;	\
    const prog_int64_t	prefix##_int64	array;	\
    const prog_uint64_t	prefix##_uint64	array;


#define DCLVAR_SET(prefix, class, ch,uch, i8,u8, i16,u16, i32,u32, i64,u64) \
    class const prog_char	prefix##_char	= ch;	\
    class const prog_uchar	prefix##_uchar	= uch;	\
    class const prog_int8_t	prefix##_int8	= i8;	\
    class const prog_uint8_t	prefix##_uint8	= u8;	\
    class const prog_int16_t	prefix##_int16	= i16;	\
    class const prog_uint16_t	prefix##_uint16	= u16;	\
    class const prog_int32_t	prefix##_int32	= i32;	\
    class const prog_uint32_t	prefix##_uint32	= u32;	\
    class const prog_int64_t	prefix##_int64	= i64;	\
    class const prog_uint64_t	prefix##_uint64	= u64;

#define DCLVAR(prefix, class, set)	DCLVAR_SET (prefix, class, set)


#define DCLARR_SET(prefix, n, class, ch,uch, i8,u8, i16,u16, i32,u32, i64,u64)\
    class const prog_char	prefix##_char[n]   = { ch };	\
    class const prog_uchar	prefix##_uchar[n]  = { uch };	\
    class const prog_int8_t	prefix##_int8[n]   = { i8 };	\
    class const prog_uint8_t	prefix##_uint8[n]  = { u8 };	\
    class const prog_int16_t	prefix##_int16[n]  = { i16 };	\
    class const prog_uint16_t	prefix##_uint16[n] = { u16 };	\
    class const prog_int32_t	prefix##_int32[n]  = { i32 };	\
    class const prog_uint32_t	prefix##_uint32[n] = { u32 };	\
    class const prog_int64_t	prefix##_int64[n]  = { i64 };	\
    class const prog_uint64_t	prefix##_uint64[n] = { u64 };

#define DCLARR(prefix, nelems, class, set)	\
    DCLARR_SET(prefix, nelems, class, set)


#define CHKSIZE(prefix, nelems)				\
    (sizeof (prefix##_char) == (nelems)			\
     && sizeof (prefix##_uchar) == (nelems)		\
     && sizeof (prefix##_int8)  == (nelems)		\
     && sizeof (prefix##_uint8) == (nelems)		\
     && sizeof (prefix##_int16) == 2 * (nelems)		\
     && sizeof (prefix##_uint16) == 2 * (nelems)	\
     && sizeof (prefix##_int32) == 4 * (nelems)		\
     && sizeof (prefix##_uint32) == 4 * (nelems)	\
     && sizeof (prefix##_int64) == 8 * (nelems)		\
     && sizeof (prefix##_uint64) == 8 * (nelems))


/* With 64-bit values onle the little 4 bytes are checked.	*/
#define CHKVAL_SET(prefix, ch, uch, i8, u8, i16, u16, i32, u32, i64, u64) \
    (pgm_read_byte (& prefix##_char) == (ch)		\
     && pgm_read_byte (& prefix##_uchar) == (uch)	\
     && pgm_read_byte (& prefix##_int8) == (i8)		\
     && pgm_read_byte (& prefix##_uint8) == (u8)	\
     && pgm_read_word (& prefix##_int16) == (i16)	\
     && pgm_read_word (& prefix##_uint16) == (u16)	\
     && pgm_read_dword (& prefix##_int32) == (i32)	\
     && pgm_read_dword (& prefix##_uint32) == (u32)	\
     && pgm_read_qword (& prefix##_int64) == (i64)	\
     && pgm_read_qword (& prefix##_uint64) == (u64))	\

#define CHKVAL(prefix, set)	CHKVAL_SET (prefix, set)


#define SET0	0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SET1	1, 2, 3, 4, 5, 6, 7, 8, 9, 10
#define SET2	2, 4, 6, 8, 10, 12, 14, 16, 18, 20
#define SET3	3, 6, 9, 12, 15, 18, 21, 24, 27, 30
#define SET4	4, 8, 12, 16, 20, 24, 28, 32, 36, 40
#define SET5	5, 10, 15, 20, 25, 30, 35, 40, 45, 50
#define SET6	6, 12, 18, 24, 30, 36, 42, 48, 54, 60
#define SET7	7, 14, 21, 28, 35, 42, 49, 56, 63, 70
#define SET8	8, 16, 24, 32, 40, 48, 56, 64, 72, 80


/* File visible progmem variables and arrays.	*/

DCLVAR (x0,, SET0)		/* const prog_char x0_char = 0;	...	*/
DCLVAR (x1,, SET1)		/* const prog_char x1_char = 1; ...	*/
DCLVAR (x2, static, SET2)	/* static const prog_char x2_char = 2; ... */
DCLARR (x3, 1,, SET3)		/* const prog_char x3_char[1] = {3}; ... */
DCLARR (x4, 2, static, SET4)	/* static const prog_char x4_char[2] = {4}; */

DCLEXT (x5,)		/* extern const prog_char x5_char; ...	*/
DCLVAR (x5,, SET5)	/* const prog_char x5_char = 5; ...	*/

DCLEXT (x6, [3])	/* extern const prog_char x6_char[3]; ...	*/
DCLARR (x6, 3,, SET6)	/* const prog_char x6_char[3] = { 6 }; ...	*/

int main ()
{
    /* Function visible progmem variables and arrays.	*/
    DCLVAR (x7, static, SET7)
    DCLARR (x8, 4, static, SET8)

    if (!CHKSIZE (x0, 1))
	return __LINE__;
    if (!CHKVAL (x0, SET0))
	return __LINE__;

    if (!CHKSIZE (x1, 1))
	return __LINE__;
    if (!CHKVAL (x1, SET1))
	return __LINE__;

    if (!CHKSIZE (x2, 1))
	return __LINE__;
    if (!CHKVAL (x2, SET2))
	return __LINE__;

    if (!CHKSIZE (x3, 1))
	return __LINE__;
    if (!CHKVAL (x3, SET3))
	return __LINE__;

    if (!CHKSIZE (x4, 2))
	return __LINE__;
    if (!CHKVAL (x4, SET4))
	return __LINE__;

    if (!CHKSIZE (x5, 1))
	return __LINE__;
    if (!CHKVAL (x5, SET5))
	return __LINE__;

    if (!CHKSIZE (x6, 3))
	return __LINE__;
    if (!CHKVAL (x6, SET6))
	return __LINE__;

    if (!CHKSIZE (x7, 1))
	return __LINE__;
    if (!CHKVAL (x7, SET7))
	return __LINE__;

    if (!CHKSIZE (x8, 4))
	return __LINE__;
    if (!CHKVAL (x8, SET8))
	return __LINE__;

    return 0;
}

#endif	/* __AVR__ */
