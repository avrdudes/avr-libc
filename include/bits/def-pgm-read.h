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

#ifndef __BITS_DEF_PGM_READ_H_
#define __BITS_DEF_PGM_READ_H_

#define _Avrlibc_Def_Pgm_1(Name, Typ)           \
  static __ATTR_ALWAYS_INLINE__                 \
  Typ pgm_read_##Name (const Typ *__addr)       \
  {                                             \
    Typ __res;                                  \
    __LPM__1 (__res, __addr);                   \
    return __res;                               \
  }

#define _Avrlibc_Def_Pgm_2(Name, Typ)           \
  static __ATTR_ALWAYS_INLINE__                 \
  Typ pgm_read_##Name (const Typ *__addr)       \
  {                                             \
    Typ __res;                                  \
    __LPM__2 (__res, __addr);                   \
    return __res;                               \
  }

#define _Avrlibc_Def_Pgm_3(Name, Typ)           \
  static __ATTR_ALWAYS_INLINE__                 \
  Typ pgm_read_##Name (const Typ *__addr)       \
  {                                             \
    Typ __res;                                  \
    __LPM__3 (__res, __addr);                   \
    return __res;                               \
  }

#define _Avrlibc_Def_Pgm_4(Name, Typ)           \
  static __ATTR_ALWAYS_INLINE__                 \
  Typ pgm_read_##Name (const Typ *__addr)       \
  {                                             \
    Typ __res;                                  \
    __LPM__4 (__res, __addr);                   \
    return __res;                               \
  }

#define _Avrlibc_Def_Pgm_8(Name, Typ)           \
  static __ATTR_ALWAYS_INLINE__                 \
  Typ pgm_read_##Name (const Typ *__addr)       \
  {                                             \
    Typ __res;                                  \
    __LPM__8 (__res, __addr);                   \
    return __res;                               \
  }

#endif /* __BITS_DEF_PGM_READ_H_ */
