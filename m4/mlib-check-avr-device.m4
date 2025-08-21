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

dnl Some devices are only handled by newer version of gcc. This macro lets us
dnl probe whether the installed avr-gcc supports a device.
AC_DEFUN([CHECK_AVR_DEVICE],[dnl
    old_CC=${CC}
    old_CFLAGS=${CFLAGS}
    CFLAGS="-mmcu=$1"
    CC=`echo "${CC}" | sed 's/-mmcu=avr.//'`
    AC_MSG_CHECKING([if ${CC} supports $1])
    AC_COMPILE_IFELSE(
        [AC_LANG_SOURCE([],[])],
        [has_c_support=yes],
        [has_c_support=no])
    DO_IF_ASM_ONLY([$1],
	[has_dev_support=yes],
	[has_dev_support=${has_c_support}])
    if test "x$has_dev_support" = "xyes"
    then
      MULTIDIR_$1=`${CC} ${CFLAGS} -print-multi-directory`
      AC_MSG_RESULT([yes, in ${MULTIDIR_$1}])
      dnl Same replacements as performed by mlib-gen.py::to_ident().
      ident=`echo "${MULTIDIR_$1}" \
		| sed -e 's:^\.$:avr2:' \
		| sed -e 's:/:_:g' \
		| sed -e 's:-:_:g' \
		`
      eval "DEVLIST_${ident}=\"\${DEVLIST_${ident}} $1\""
      SUPPORTED_MCUS="${SUPPORTED_MCUS} $1"
      upper=$(echo "$1" | ${srcdir}/devtools/mcu-to-avr-name.sh)
      defd="defined(__AVR_${upper}__)"
      AS_CASE([$1],
	  [[avr*[0-9]d*]],  [COND_DEFINED_Dx="${COND_DEFINED_Dx} || ${defd}"],
	  [[avr*[0-9]e*]],  [COND_DEFINED_Ex="${COND_DEFINED_Ex} || ${defd}"],
	  [[avr*[0-9]sd*]], [COND_DEFINED_SD="${COND_DEFINED_SD} || ${defd}"],
	  [])
    else
      MULTIDIR_$1=
      AC_MSG_RESULT(no)
    fi
    dnl Make sure we can compile <avr/io.h> for at least one MCU.
    dnl If not, early abort configure.  Purpose is to detect very old
    dnl compiler versions early, which otherwise would produce confusing
    dnl configure results and cannot build the library.
    AS_IF([test $has_c_support = yes && test x$done_compile_avrioh = x],[
      done_compile_avrioh=yes
      AC_MSG_CHECKING([if $CC can compile <avr/io.h> for at least one device])
      CFLAGS="-mmcu=$1 -I${srcdir}/include -Werror"
      AC_COMPILE_IFELSE(
        [AC_LANG_SOURCE([[
		#define __CONFIGURING_AVR_LIBC__
		#include <avr/io.h>
		int main (void) { return 0; } ]],[])],
	[AC_MSG_RESULT(yes)],
	[AC_MSG_RESULT(no)
	 AC_MSG_FAILURE([$CC cannot compile <avr/io.h> for $1]) ])
    ],[])
    dnl Done compiling <avr/io.h> for at least one device.
    AC_SUBST(MULTIDIR_$1)
    CC=${old_CC}
    CFLAGS=${old_CFLAGS}
    AM_CONDITIONAL(HAS_$1, [test "x${MULTIDIR_$1}" != "x"])
])
dnl Local Variables:
dnl mode: autoconf
dnl End:
