/* Copyright (c) 2025  Georg-Johann Lay
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

#ifndef __BITS_ATTRIBS_H_
#define __BITS_ATTRIBS_H_

#define __ATTR_ALWAYS_INLINE__ __inline__ __attribute__((__always_inline__))

#ifdef  __GNUC_STDC_INLINE__
#define __ATTR_GNU_INLINE__   __attribute__((__gnu_inline__))
#else
#define __ATTR_GNU_INLINE__
#endif

#define __ATTR_CONST__ __attribute__((__const__))

#define __ATTR_PURE__ __attribute__((__pure__))

#define __ATTR_MALLOC__ __attribute__((__malloc__))

#define __ATTR_NORETURN__ __attribute__((__noreturn__))

#if __GNUC__ >= 8
#define __ATTR_NONSTRING__ __attribute__((__nonstring__))
#else
#define __ATTR_NONSTRING__
#endif

/* AVR specific */

#ifdef __clang__
#define __ATTR_PROGMEM__ __attribute__((__section__(".progmem.data")))
#else
#define __ATTR_PROGMEM__ __attribute__((__progmem__))
#endif

#endif /* __BITS_ATTRIBS_H_ */
