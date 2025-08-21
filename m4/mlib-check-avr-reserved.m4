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

dnl avr/io.h may define BAUD, hence BAUD is reserved and should not be
dnl #defined by the user.
AC_DEFUN([CHECK_AVR_RESERVED],[dnl
    if test "x${MULTIDIR_$1}" != "x"
    then
      old_CFLAGS=${CFLAGS}
      CFLAGS="-mmcu=$1 -I${srcdir}/include -Werror"
      AC_MSG_CHECKING([if BAUD is reserved for $1])
      dnl #define __CONFIGURING_AVR_LIBC__ so that avr/io.h
      dnl doesn't #include <bits/devinfo.h>.
      AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
		#define BAUD 123
		#define __CONFIGURING_AVR_LIBC__
		#include <avr/io.h>
		int a[BAUD == 123 ? 1 : -1];  ]],[])],
        [has_$1_baud=no],
        [has_$1_baud=yes])
      DO_IF_ASM_ONLY([$1], [has_$1_baud=no], [])
      AC_MSG_RESULT([${has_$1_baud}])
    else
      has_$1_baud=no
    fi
    CFLAGS=${old_CFLAGS}
    upper=$(echo "$1" | ${srcdir}/devtools/mcu-to-avr-name.sh)
    defd="defined(__AVR_${upper}__)"
    AS_IF([test x${has_$1_baud} = xyes],
        [COND_BAUD_RESERVED="${COND_BAUD_RESERVED} || ${defd}"],
        [])
])
dnl Local Variables:
dnl mode: autoconf
dnl End:
