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
AC_INIT(avr-libc, 1.1.0.20040426-ac, avr-libc-dev@nongnu.org)
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
	AC_MSG_WARN(Avr-libc must be built using an avr cross-compiler.)
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

AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

AM_PROG_AS

# Setup AVR specific Makefile variables.

AVR_CRT_AT90=''
AC_SUBST(AVR_CRT_AT90)

AVR_CRT_TINY=''
AC_SUBST(AVR_CRT_TINY)

AVR_CRT_MEGA=''
AC_SUBST(AVR_CRT_MEGA)

AVR_CRT_OTHER=''
AC_SUBST(AVR_CRT_OTHER)

# Generate all files from *.in sources.

AC_CONFIG_FILES([Makefile
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
                 libm/fplib/Makefile])
AC_OUTPUT

AC_MSG_WARN()
AC_MSG_WARN(This is still a work in progress.)
AC_MSG_WARN(Do not expect it work correctly yet - if at all.)
AC_MSG_WARN()
