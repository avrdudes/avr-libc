/* Copyright (c) 2002, Michael Stumpf
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
  POSSIBILITY OF SUCH DAMAGE. */

/*
   ctype.h - character conversion macros and ctype macros

  Author : Michael Stumpf
           Michael.Stumpf@t-online.de
*/

#ifndef __CTYPE_H_
#define __CTYPE_H_ 1

#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern int isalnum(int __c) __ATTR_CONST__;
extern int isalpha(int __c) __ATTR_CONST__;
extern int isascii(int __c) __ATTR_CONST__;
extern int iscntrl(int __c) __ATTR_CONST__;
extern int isdigit(int __c) __ATTR_CONST__;
extern int isgraph(int __c) __ATTR_CONST__;
extern int islower(int __c) __ATTR_CONST__;
extern int isprint(int __c) __ATTR_CONST__;
extern int ispunct(int __c) __ATTR_CONST__;
extern int isspace(int __c) __ATTR_CONST__;
extern int isupper(int __c) __ATTR_CONST__;
extern int isxdigit(int __c) __ATTR_CONST__;
extern int isblank(int __c) __ATTR_CONST__;
extern int toascii(int __c) __ATTR_CONST__;
extern int tolower(int __c) __ATTR_CONST__;
extern int toupper(int __c) __ATTR_CONST__;

#ifdef __cplusplus
}
#endif

#endif
