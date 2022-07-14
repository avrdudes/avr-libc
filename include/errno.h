/* Copyright (c) 2002,2007 Marek Michalkiewicz
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

/* $Id$ */

#ifndef __ERRNO_H_
#define __ERRNO_H_ 1

/** \file */
/** \defgroup avr_errno <errno.h>: System Errors

    \code #include <errno.h>\endcode

    Some functions in the library set the global variable \c errno when an
    error occurs. The file, \c <errno.h>, provides symbolic names for various
    error codes. 
 */

#ifdef __cplusplus
extern "C" {
#endif

/** \ingroup avr_errno
    \brief Error code for last error encountered by library

    The variable \c errno holds the last error code encountered by
    a library function.  This variable must be cleared by the
    user prior to calling a library function.

    \warning The \c errno global variable is not safe to use in a threaded or
    multi-task system. A race condition can occur if a task is interrupted
    between the call which sets \c error and when the task examines \c
    errno. If another task changes \c errno during this time, the result will
    be incorrect for the interrupted task. */
extern int errno;

#ifdef __cplusplus
}
#endif

/** \ingroup avr_errno
    \def EDOM

    Domain error. */
#define EDOM       33

/** \ingroup avr_errno
    \def ERANGE

    Range error. */
#define ERANGE     34

#ifndef __DOXYGEN__

/* The following enums are generated using the following polinomial hash:
def hashStr(s: str) -> int:
    res = 0
    p = 1
    for c in reversed(s):
        res += (ord(c) - 64) * p
        p *= 26
    return res & 0x7fff

for nm in names:
    print("#define", nm , hex(hashStr(nm)))
*/

/* ((((('E'-64)*26+('N'-64))*26+('O'-64))*26+('S'-64))*26+('Y'-64))*26+'S'-64 */
#define ENOSYS ((int)(66081697 & 0x7fff))

/* (((('E'-64)*26+('I'-64))*26+('N'-64))*26+('T'-64))*26+('R'-64) */
#define EINTR ((int)(2453066 & 0x7fff))

#define E2BIG 0x2259
#define EACCES 0x49a9
#define EADDRINUSE 0x7367
#define EADDRNOTAVAIL 0x65a
#define EAFNOSUPPORT 0x7364
#define EAGAIN 0x5764
#define EALREADY 0x13cd
#define EBADF 0x69b2
#define EBUSY 0x201b
#define ECHILD 0x2390
#define ECONNABORTED 0x7196
#define ECONNREFUSED 0x707a
#define ECONNRESET 0x51ea
#define EDEADLK 0x438b
#define EDESTADDRREQ 0x43eb
#define EEXIST 0x60f6
#define EFAULT 0x4de8
#define EFBIG 0x7f79
#define EHOSTUNREACH 0x5e62
#define EILSEQ 0x264f
#define EINPROGRESS 0x3555
#define EINVAL 0x371e
#define EIO 0xe2d
#define EISCONN 0x31e
#define EISDIR 0x5fb4
#define ELOOP 0x3e62
#define EMFILE 0x54e1
#define EMLINK 0x710b
#define EMSGSIZE 0x74f5
#define ENAMETOOLONG 0x47bf
#define ENETDOWN 0x3000
#define ENETRESET 0x44ea
#define ENETUNREACH 0x262
#define ENFILE 0x4df1
#define ENOBUFS 0x6363
#define ENODEV 0x2a00
#define ENOENT 0x2d8c
#define ENOEXEC 0x391d
#define ENOLCK 0x3ee1
#define ENOMEM 0x41bb
#define ENOMSG 0x4321
#define ENOPROTOOPT 0xa48
#define ENOSPC 0x52a7
#define ENOTCONN 0x5eae
#define ENOTDIR 0xa9c
#define ENOTEMPTY 0xc79
#define ENOTSOCK 0x280d
#define ENOTTY 0x55c9
#define ENXIO 0x5ed9
#define EOPNOTSUPP 0x15bc
#define EPERM 0x36e5
#define EPIPE 0x4139
#define EPROTONOSUPPORT 0x3964
#define EPROTOTYPE 0x35f9
#define EROFS 0x596b
#define ESPIPE 0x5a39
#define ESRCH 0x25a6
#define ETIMEDOUT 0x2822
#define EWOULDBLOCK 0x8f5
#define EXDEV 0x5838

/* ((((('E'-64)*26+('N'-64))*26+('O'-64))*26+('E'-64))*26+('R'-64))*26+'R'-64 */
#define ENOERR ((int)(66072050 & 0x7fff))

#endif	/* !__DOXYGEN__ */

#endif
