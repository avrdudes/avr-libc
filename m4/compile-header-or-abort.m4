# Copyright (c) 2004  Theodore A. Roth
# Copyright (c) 2005,2006,2007,2009  Anatoly Sokolov
# Copyright (c) 2005,2008  Joerg Wunsch
# Copyright (c) 2025  Georg-Johann Lay
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
# * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in
#   the documentation and/or other materials provided with the
#   distribution.
# * Neither the name of the copyright holders nor the names of
#   contributors may be used to endorse or promote products derived
#   from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

dnl Make sure we can compile some essential headers for -mmcu=$1.
dnl If not then abort configure due to a too ancient compiler.
dnl
AC_DEFUN([COMPILE_AVRIOH_OR_ABORT],[dnl
    AC_MSG_CHECKING([if $CC can compile <avr/io.h> for at least one device])
    CFLAGS="-mmcu=$1 -I${srcdir}/include"
    AC_COMPILE_IFELSE(
	[AC_LANG_SOURCE([[
		#define __CONFIGURING_AVR_LIBC__
		#include <avr/io.h>
		int main (void) { return 0; }
		]],[])],
	[AC_MSG_RESULT(yes)],
	[AC_MSG_RESULT(no)
	 AC_MSG_FAILURE([$CC cannot compile <avr/io.h> for $1]) ])
])

AC_DEFUN([COMPILE_MATHH_OR_ABORT],[dnl
    AC_MSG_CHECKING([if $CC can compile <math.h> for at least one device])
    CFLAGS="-mmcu=$1 -I${srcdir}/include"
    AC_COMPILE_IFELSE(
	[AC_LANG_SOURCE([[
		#define __CONFIGURING_AVR_LIBC__
		#include <math.h>
		]],[])],
	[AC_MSG_RESULT(yes)],
	[AC_MSG_RESULT(no)
	 AC_MSG_FAILURE([$CC cannot compile <math.h> for $1]) ])
])

dnl string.h is demanding due to its inlining requirements.
dnl Old compilers like v3.4.6 have https://gcc.gnu.org/PR54965 and
dnl fail due to that.  Bail out early in the build process.
dnl For now we prefer the provided optimizations in string.h
dnl over supporting antique compiler versions.	While factoring
dnl out such code is possible, string.h and friends are already
dnl complicated enough.	 PR54965 has been fixed in v4.7 / 2012.
AC_DEFUN([COMPILE_STRINGH_OR_ABORT],[dnl
    AC_MSG_CHECKING([if $CC can compile <string.h> for at least one device])
    CFLAGS="-mmcu=$1 -Os -I${srcdir}/include"
    AC_COMPILE_IFELSE(
	[AC_LANG_SOURCE([[
		#define __CONFIGURING_AVR_LIBC__
		#include <string.h>
		size_t len, (*pf)(const char*);
		const char *text = "Text";
		int main (void)
		{
		    len = strlen (text);
		    pf = strlen;
		    return 0;
		}
		]],[])],
	[AC_MSG_RESULT(yes)],
	[AC_MSG_RESULT(no)
	 AC_MSG_FAILURE([$CC cannot compile <string.h> for $1])])
])


AC_DEFUN([COMPILE_HEADER_OR_ABORT],[dnl
    old_compile_header_or_abort_CFLAGS=${CFLAGS}
    COMPILE_AVRIOH_OR_ABORT([$1])
    COMPILE_STRINGH_OR_ABORT([$1])
    COMPILE_MATHH_OR_ABORT([$1])
    CFLAGS=${old_compile_header_or_abort_CFLAGS}
])
dnl Local Variables:
dnl mode: autoconf
dnl End:
