#                                               -*- Autoconf -*-
#
# Copyright (c) 2004,  Theodore A. Roth
# Copyright (c) 2005,  Anatoly Sokolov
# Copyright (c) 2005,  Joerg Wunsch
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
#
# $Id$
#
# Process this file with autoconf to produce a configure script.
#

AC_PREREQ(2.57)
AC_REVISION($Revision$)
AC_INIT(avr-libc, 1.3.0.20050810, avr-libc-dev@nongnu.org)
AC_CONFIG_SRCDIR([doc/examples/demo/demo.c])
AC_CONFIG_HEADER([config.h])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST

# See if the user specified '--build=`../config.guess` --host=avr' when
# running ../configure.

AC_MSG_CHECKING([if configuring for cross compile])
if test "x${build_alias}" = "x${host_alias}"; then
	if test "x${build_alias}" = "x" ; then
		build_alias='`./config.guess`'
	fi
	AC_MSG_RESULT(no)
	AC_MSG_WARN()
	AC_MSG_WARN(AVR-LIBC must be built using an avr cross-compiler.)
	AC_MSG_WARN(Try configuring with:)
	AC_MSG_WARN(\"$0 --build=$build_alias --host=avr\")
	AC_MSG_WARN()
	AC_MSG_ERROR(aborting configure)
else
	AC_MSG_RESULT([yes])
fi

AC_MSG_CHECKING([if target host is avr])
case "$host" in
	avr* )
		AC_MSG_RESULT([yes])
		;;
	* )
		AC_MSG_RESULT(no)
		AC_MSG_WARN()
		AC_MSG_WARN(Avr-libc must be built using an avr cross-compiler.)
		AC_MSG_WARN(Try configuring with:)
		AC_MSG_WARN(\"$0 --build=$build --host=avr\")
		AC_MSG_WARN()
		AC_MSG_ERROR(aborting configure)
		;;
esac

## TODO: Write a check for GNU Make

AM_INIT_AUTOMAKE

# We don't want touse the cflags from the environment since we need control
# of this when we're building the libs.
CFLAGS=""

# Checks for programs.

AC_PROG_CC
AC_CHECK_TOOL(AS, as, as)
AM_PROG_AS
AC_PROG_RANLIB
AC_CHECK_TOOL(AR, ar, ar)

# Make sure that we found the right avr cross-compiler.

case "${CC}" in
   *avr-gcc*) ;;
   *) AC_MSG_ERROR(Wrong C compiler found; check the PATH!) ;;
esac
case "${AS}" in
   *avr-as*) ;;
   *) AC_MSG_ERROR(Wrong assembler found; check the PATH!) ;;
esac
case "${AR}" in
   *avr-ar*) ;;
   *) AC_MSG_ERROR(Wrong archiver found; check the PATH!) ;;
esac
case "${RANLIB}" in
   *avr-ranlib*) ;;
   *) AC_MSG_ERROR(Wrong ranlib found; check the PATH!) ;;
esac

AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

# Define this here so all files agree on the name of the manual.
# This also centralizes the name so it's easier to change.
AVR_LIBC_USER_MANUAL="avr-libc-user-manual-${VERSION}"
AC_SUBST(AVR_LIBC_USER_MANUAL)

# Temp hack to ignore DOCSDIR.
DOCSDIR=""
AC_SUBST(DOCSDIR)

dnl Some devices are only handled by newer version of gcc. This macro lets us
dnl probe to see if the installed avr-gcc supports a questionable device.
AC_DEFUN(
  CHECK_AVR_DEVICE,
  [
    old_CC=${CC}
    old_CFLAGS=${CFLAGS}
    CFLAGS="-mmcu=$1"
    CC=`echo "${CC}" | sed 's/-mmcu=avr.//'`
    AC_MSG_CHECKING(if ${CC} has support for $1)
    AC_TRY_COMPILE(
      [],
      [],
      [has_dev_support=yes],
      [has_dev_support=no]
    )
    if test "x$has_dev_support" = "xyes"
    then
      HAS_$1=yes
    fi
    AC_MSG_RESULT($has_dev_support)
    CC=${old_CC}
    CFLAGS=${old_CFLAGS}
  ]
)
dnl For those directories which are not supported by this version of gcc,
dnl drop a dummy Makefile so the hierarchy traversal will work.
AC_DEFUN(
  DUMMY_MAKEFILE,
  [
    AC_MSG_NOTICE([Creating dummy $1])
    echo all distdir install installdirs clean distclean uninstall check: > $1
  ]
)

# Generate all files from *.in sources.

AC_CONFIG_FILES([
	Makefile
	avr-libc.spec
	avr/Makefile
	avr/lib/Makefile
	common/Makefile
	crt1/Makefile
	doc/Makefile
	doc/api/Makefile
	doc/examples/Makefile
	include/Makefile
	include/avr/Makefile
	include/compat/Makefile
	libc/Makefile
	libc/misc/Makefile
	libc/pmstring/Makefile
	libc/stdio/Makefile
	libc/stdlib/Makefile
	libc/string/Makefile
	libm/Makefile
	libm/fplib/Makefile
	scripts/Makefile
])

#avr1 and avr2
AC_CONFIG_FILES([
	avr/lib/avr2/Makefile
	avr/lib/avr2/at90s1200/Makefile
	avr/lib/avr2/at90s2313/Makefile
	avr/lib/avr2/at90s2323/Makefile
	avr/lib/avr2/at90s2333/Makefile
	avr/lib/avr2/at90s2343/Makefile
	avr/lib/avr2/at90s4433/Makefile
	avr/lib/avr2/at90s4414/Makefile
	avr/lib/avr2/at90s4434/Makefile
	avr/lib/avr2/at90s8515/Makefile
	avr/lib/avr2/at90s8535/Makefile
	avr/lib/avr2/at90c8534/Makefile
	avr/lib/avr2/attiny11/Makefile
	avr/lib/avr2/attiny12/Makefile
	avr/lib/avr2/attiny15/Makefile
	avr/lib/avr2/attiny22/Makefile
	avr/lib/avr2/attiny26/Makefile
	avr/lib/avr2/attiny28/Makefile
	avr/lib/avr2/at86rf401/Makefile
])

CHECK_AVR_DEVICE(attiny13)
AS_IF([test "x$HAS_attiny13" = "xyes"],
      [AC_CONFIG_FILES([avr/lib/avr2/attiny13/Makefile])],
      [DUMMY_MAKEFILE([avr/lib/avr2/attiny13/Makefile])])

CHECK_AVR_DEVICE(attiny2313)
AS_IF([test "x$HAS_attiny2313" = "xyes"],
      [AC_CONFIG_FILES([avr/lib/avr2/attiny2313/Makefile])],
      [DUMMY_MAKEFILE([avr/lib/avr2/attiny2313/Makefile])])

#avr3
AC_CONFIG_FILES([
	avr/lib/avr3/Makefile
	avr/lib/avr3/atmega103/Makefile
	avr/lib/avr3/at43usb320/Makefile
	avr/lib/avr3/at43usb355/Makefile
	avr/lib/avr3/at76c711/Makefile
])

#avr4
AC_CONFIG_FILES([
	avr/lib/avr4/Makefile
	avr/lib/avr4/atmega8/Makefile
	avr/lib/avr4/atmega8515/Makefile
	avr/lib/avr4/atmega8535/Makefile
])

CHECK_AVR_DEVICE(atmega48)
AS_IF([test "x$HAS_atmega48" = "xyes"],
      [AC_CONFIG_FILES([avr/lib/avr4/atmega48/Makefile])],
      [DUMMY_MAKEFILE([avr/lib/avr4/atmega48/Makefile])])

CHECK_AVR_DEVICE(atmega88)
AS_IF([test "x$HAS_atmega88" = "xyes"],
      [AC_CONFIG_FILES([avr/lib/avr4/atmega88/Makefile])],
      [DUMMY_MAKEFILE([avr/lib/avr4/atmega88/Makefile])])

#avr5
AC_CONFIG_FILES([
	avr/lib/avr5/Makefile
	avr/lib/avr5/atmega16/Makefile
	avr/lib/avr5/atmega161/Makefile
	avr/lib/avr5/atmega162/Makefile
	avr/lib/avr5/atmega163/Makefile
	avr/lib/avr5/atmega169/Makefile
	avr/lib/avr5/atmega32/Makefile
	avr/lib/avr5/atmega323/Makefile
	avr/lib/avr5/atmega64/Makefile
	avr/lib/avr5/atmega128/Makefile
	avr/lib/avr5/at94k/Makefile
])

CHECK_AVR_DEVICE(atmega165)
AS_IF([test "x$HAS_atmega165" = "xyes"],
      [AC_CONFIG_FILES([avr/lib/avr5/atmega165/Makefile])],
      [DUMMY_MAKEFILE([avr/lib/avr5/atmega165/Makefile])])

CHECK_AVR_DEVICE(atmega168)
AS_IF([test "x$HAS_atmega168" = "xyes"],
      [AC_CONFIG_FILES([avr/lib/avr5/atmega168/Makefile])],
      [DUMMY_MAKEFILE([avr/lib/avr5/atmega168/Makefile])])

CHECK_AVR_DEVICE(atmega325)
AS_IF([test "x$HAS_atmega325" = "xyes"],
      [AC_CONFIG_FILES([avr/lib/avr5/atmega325/Makefile])],
      [DUMMY_MAKEFILE([avr/lib/avr5/atmega325/Makefile])])

CHECK_AVR_DEVICE(atmega3250)
AS_IF([test "x$HAS_atmega3250" = "xyes"],
      [AC_CONFIG_FILES([avr/lib/avr5/atmega3250/Makefile])],
      [DUMMY_MAKEFILE([avr/lib/avr5/atmega3250/Makefile])])

CHECK_AVR_DEVICE(atmega645)
AS_IF([test "x$HAS_atmega645" = "xyes"],
      [AC_CONFIG_FILES([avr/lib/avr5/atmega645/Makefile])],
      [DUMMY_MAKEFILE([avr/lib/avr5/atmega645/Makefile])])

CHECK_AVR_DEVICE(atmega6450)
AS_IF([test "x$HAS_atmega6450" = "xyes"],
      [AC_CONFIG_FILES([avr/lib/avr5/atmega6450/Makefile])],
      [DUMMY_MAKEFILE([avr/lib/avr5/atmega6450/Makefile])])

CHECK_AVR_DEVICE(at90can128)
AS_IF([test "x$HAS_at90can128" = "xyes"],
      [AC_CONFIG_FILES([avr/lib/avr5/at90can128/Makefile])],
      [DUMMY_MAKEFILE([avr/lib/avr5/at90can128/Makefile])])

AC_OUTPUT
