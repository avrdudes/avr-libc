#                                               -*- Autoconf -*-
#
# Copyright (c) 2004,  Theodore A. Roth
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
AC_INIT(avr-libc, 1.1.0.20040429-ac, avr-libc-dev@nongnu.org)
AC_CONFIG_SRCDIR([doc/examples/avr-recv.c])
AC_CONFIG_HEADER([config.h])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST

# See if the user specified '--build=`../config.guess` --host=avr' when
# running ../configure.

AC_MSG_CHECKING([if configuring for cross compile])
if test "x${build}" = "x${host}"; then
	AC_MSG_RESULT(no)
	AC_MSG_WARN()
	AC_MSG_WARN(AVR-LIBC must be built using an avr cross-compiler.)
	AC_MSG_WARN(Try configuring with:)
	AC_MSG_WARN(\"$0 --build=$build --host=avr\")
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

AC_SUBST(AVR_CRT_AT90)
AC_SUBST(AVR_CRT_TINY)
AC_SUBST(AVR_CRT_MEGA)
AC_SUBST(AVR_CRT_OTHER)

# Define this here so all files agree on the name of the manual.
# This also centralizes the name so it's easier to change.
AVR_LIBC_USER_MANUAL="avr-libc-user-manual-${VERSION}"
AC_SUBST(AVR_LIBC_USER_MANUAL)

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
	libc/Makefile
	libc/misc/Makefile
	libc/pmstring/Makefile
	libc/stdio/Makefile
	libc/stdlib/Makefile
	libc/string/Makefile
	libm/Makefile
	libm/fplib/Makefile
])

AC_CONFIG_FILES([
	avr/lib/at90s1200/Makefile
	avr/lib/at90s2313/Makefile
	avr/lib/at90s2323/Makefile
	avr/lib/at90s2333/Makefile
	avr/lib/at90s2343/Makefile
	avr/lib/at90s4433/Makefile
	avr/lib/at90s4414/Makefile
	avr/lib/at90s4434/Makefile
	avr/lib/at90s8515/Makefile
	avr/lib/at90s8535/Makefile
	avr/lib/at90c8534/Makefile
	avr/lib/attiny11/Makefile
	avr/lib/attiny12/Makefile
	avr/lib/attiny15/Makefile
	avr/lib/attiny22/Makefile
	avr/lib/attiny26/Makefile
	avr/lib/attiny28/Makefile
	avr/lib/atmega103/Makefile
	avr/lib/atmega128/Makefile
	avr/lib/atmega16/Makefile
	avr/lib/atmega161/Makefile
	avr/lib/atmega162/Makefile
	avr/lib/atmega163/Makefile
	avr/lib/atmega169/Makefile
	avr/lib/atmega8/Makefile
	avr/lib/atmega8515/Makefile
	avr/lib/atmega8535/Makefile
	avr/lib/atmega32/Makefile
	avr/lib/atmega323/Makefile
	avr/lib/atmega64/Makefile
	avr/lib/at86rf401/Makefile
	avr/lib/at43usb320/Makefile
	avr/lib/at43usb355/Makefile
	avr/lib/at76c711/Makefile
	avr/lib/at94k/Makefile
])

## Skip the new deivces for now.
#AC_CONFIG_FILES([
#	avr/lib/attiny13/Makefile
#	avr/lib/attiny2313/Makefile
#	avr/lib/atmega168/Makefile
#	avr/lib/atmega48/Makefile
#	avr/lib/atmega88/Makefile
#])

AC_OUTPUT

AC_MSG_WARN()
AC_MSG_WARN(This is still a work in progress.)
AC_MSG_WARN(Do not expect it work correctly yet - if at all.)
AC_MSG_WARN()
