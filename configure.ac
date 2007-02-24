#                                               -*- Autoconf -*-
#
# Copyright (c) 2004,  Theodore A. Roth
# Copyright (c) 2005,2006,2007  Anatoly Sokolov
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
#
# $Id$
#
# Process this file with autoconf to produce a configure script.
#

AC_PREREQ(2.57)
AC_REVISION($Revision$)

dnl library versioning -- modify these on releases
dnl        macro name           value            description
m4_define([avr_libc_major],    [1])dnl           major version
m4_define([avr_libc_minor],    [5])dnl           minor version
m4_define([avr_libc_revision], [0])dnl           revision (dot-dot version)
m4_define([avr_libc_reldate],  [20051227])dnl    release date
dnl end of library versioning data

dnl odd minor number marks a development branch, append date to version there
m4_if(m4_eval(avr_libc_minor % 2 == 1), [0], [dnl
  m4_define([avr_libc_version],
            avr_libc_major.avr_libc_minor.avr_libc_revision)dnl
  ],[dnl
  m4_define([avr_libc_version],
            avr_libc_major.avr_libc_minor.avr_libc_revision.avr_libc_reldate)dnl
  ])dnl
m4_define([avr_libc_version_numeric],
          m4_eval(10000 * avr_libc_major + dnl
                    100 * avr_libc_minor + dnl
                          avr_libc_revision))dnl

AC_INIT(avr-libc, avr_libc_version, avr-libc-dev@nongnu.org)
AC_CONFIG_SRCDIR([doc/examples/demo/demo.c])
AC_CONFIG_HEADER([config.h])

dnl substitute M4 macros into shell variables
AVR_LIBC_MAJOR=avr_libc_major
AVR_LIBC_MINOR=avr_libc_minor
AVR_LIBC_REVISION=avr_libc_revision
AVR_LIBC_RELDATE=avr_libc_reldate
AVR_LIBC_VERSION=avr_libc_version
AVR_LIBC_VERSION_NUMERIC=avr_libc_version_numeric
dnl ...and trigger Makefile.in substitutions
AC_SUBST(AVR_LIBC_MAJOR)
AC_SUBST(AVR_LIBC_MINOR)
AC_SUBST(AVR_LIBC_REVISION)
AC_SUBST(AVR_LIBC_RELDATE)
AC_SUBST(AVR_LIBC_VERSION)
AC_SUBST(AVR_LIBC_VERSION_NUMERIC)

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
	AC_MSG_WARN("$0 --build=$build_alias --host=avr")
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
		AC_MSG_WARN("$0 --build=$build --host=avr")
		AC_MSG_WARN()
		AC_MSG_ERROR(aborting configure)
		;;
esac

## TODO: Write a check for GNU Make

dnl The default check whether the C compiler can create an executable
dnl is inappropriate for us as it requires an existing library.
AC_NO_EXECUTABLES

dnl We don't want the gzip distribution tarball anymore.
AM_INIT_AUTOMAKE([dist-bzip2 no-dist-gzip])

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

dnl TODO: Check for various tools used to build the documentation. If anything
dnl is missing, don't build the docs by default.

dnl Disable building of dox by default since it they may not build properly on
dnl all systems. This isn't optimal, but how do we work around the user not
dnl having fig2dev and still build all the formats?

AC_ARG_ENABLE(doc,
[  --enable-doc            build all doc formats (disabled is default)],
[case "${enableval}" in
  yes) enable_doc=yes ;;
  no)  enable_doc=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for global doc option) ;;
 esac], [enable_doc=no])dnl
dnl Various documentation options.  By default, we enable all of them,
dnl i. e. HTML, Postscript, PDF, and Unix-style man pages.
AC_ARG_ENABLE(html-doc,
[  --enable-html-doc       build HTML documentation (default)],
[case "${enableval}" in
  yes) html_doc=yes ;;
  no)  html_doc=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for html-doc option) ;;
 esac], [html_doc=yes])dnl

AC_ARG_ENABLE(ps-doc,
[  --enable-ps-doc         build Postscript documentation (default)],
[case "${enableval}" in
  yes) ps_doc=yes ;;
  no)  ps_doc=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for ps-doc option) ;;
 esac], [ps_doc=yes])dnl

AC_ARG_ENABLE(pdf-doc,
[  --enable-pdf-doc        build PDF documentation (default)],
[case "${enableval}" in
  yes) pdf_doc=yes ;;
  no)  pdf_doc=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for pdf-doc option) ;;
 esac], [pdf_doc=yes])dnl

dnl Man pages are currently not tunable; they'll be built whenever
dnl the HTML documentation is built.  However, it can be configured
dnl whether the result is about to be installed or not.
AC_ARG_ENABLE(man-doc,
[  --enable-man-doc        build Unix-style manual pages (default)],
[case "${enableval}" in
  yes) man_doc=yes ;;
  no)  man_doc=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for man-doc option) ;;
 esac], [man_doc=yes])dnl

AC_ARG_ENABLE(versioned-doc,
[  --enable-versioned-doc  install docs in directory with version name (default)],
[case "${enableval}" in
  yes) versioned_doc=yes ;;
  no)  versioned_doc=no ;;
  *)   AC_MSG_ERROR(bad value ${enableval} for versioned-doc option) ;;
 esac], [versioned_doc=yes])dnl

dnl troth/2002-07-12: The CHECK_DOXYGEN macro should be moved to a config
dnl dir. I put it here until I figure out how to integrate the config dir.

dnl
dnl @synopsis CHECK_DOXYGEN
dnl
dnl This macro checks if doxygen is installed on the build system
dnl
dnl @version Id: check_doxygen.m4,v 1.2 2002/02/10 23:22:40 troth Exp
dnl @author Theodore A. Roth <troth@openavr.org>
dnl
AC_DEFUN([CHECK_DOXYGEN],[dnl
dnl
AC_MSG_CHECKING([for doxygen])
dox_ver=`doxygen --version 2>/dev/null`
if test "x$dox_ver" = "x"; then
	AC_MSG_RESULT(no)
else
	# FIXME: should also check for dox_ver >= 1.4.1
	AC_MSG_RESULT(yes)
	if test "$ps_doc" = "yes"; then
		AC_MSG_NOTICE([Enabling PS docs])
		TARGET_DOX_PS=dox-ps
		INSTALL_DOX_PS=install-dox-ps
	fi
	if test "$pdf_doc" = "yes"; then
		AC_MSG_NOTICE([Enabling PDF docs])
		TARGET_DOX_PDF=dox-pdf
		INSTALL_DOX_PDF=install-dox-pdf
	fi
	if test "$html_doc" = "yes"; then
		AC_MSG_NOTICE([Enabling HTML docs])
		TARGET_DOX_HTML=dox-html
		INSTALL_DOX_HTML=install-dox-html
	fi
dnl The creation of man pages is a side-effect of the HTML
dnl generation, so a different target is only needed for installation.
	if test "$man_doc" = "yes"; then
		AC_MSG_NOTICE([Enabling man pages])
		TARGET_DOX_HTML=dox-html
		INSTALL_DOX_MAN=install-dox-man
	fi
fi
dnl
AC_SUBST(TARGET_DOX_PS)
AC_SUBST(TARGET_DOX_PDF)
AC_SUBST(TARGET_DOX_HTML)
AC_SUBST(INSTALL_DOX_PS)
AC_SUBST(INSTALL_DOX_PDF)
AC_SUBST(INSTALL_DOX_HTML)
AC_SUBST(INSTALL_DOX_MAN)
])dnl

CHECK_DOXYGEN

dnl
dnl @synopsis CHECK_PNG_UTILS
dnl
dnl This macro checks if pngtopnm and pnmtopng are installed. If they are not
dnl installed we just fake it with "cat".
dnl
dnl We use these in the dox to insert transparency into the png images as such:
dnl
dnl   $ pngtopnm foo.png > tmp.pnm
dnl   $ pnmtopng -transparent white tmp.pnm > foo.png
dnl
dnl @version 
dnl @author Theodore A. Roth <troth@openavr.org> and Eric B. Weddington <eweddington@cso.atmel.com>
dnl
AC_DEFUN([CHECK_PNG_UTILS],[dnl
dnl
AC_MSG_CHECKING([for pngtopnm])
has_pngtopnm=`pngtopnm --version 2>&1 | grep -c -i Version`
if test "$has_pngtopnm" = "1"; then
	AC_MSG_RESULT(yes)
	PNGTOPNM="pngtopnm"
else
	AC_MSG_RESULT(no)
	PNGTOPNM="cat"
fi
dnl
AC_MSG_CHECKING([for pnmtopng])
has_pnmtopng=`pnmtopng --version 2>&1 | grep -c -i Version`
if test "$has_pnmtopng" = "1"; then
	AC_MSG_RESULT(yes)
	PNMTOPNG="pnmtopng"
else
	AC_MSG_RESULT(no)
	PNMTOPNG="cat"
    PNGTOPNM="cat"
fi
AC_SUBST(PNGTOPNM)
AC_SUBST(PNMTOPNG)
])dnl

CHECK_PNG_UTILS

if test "$versioned_doc" = "yes"; then
	DOC_INST_DIR='${DESTDIR}${datadir}/doc/avr-libc-$(VERSION)'
	AVR_LIBC_USER_MANUAL="avr-libc-user-manual-${VERSION}"
else
	DOC_INST_DIR='${DESTDIR}${datadir}/doc/avr-libc'
	AVR_LIBC_USER_MANUAL="avr-libc-user-manual"
fi

dnl We only want to build the docs if the user has passed
dnl "--enable-doc" to configure.
if test "$enable_doc" = "yes"; then
	DOCSDIR='api'
else
	DOCSDIR=''
fi

AC_SUBST(DOCSDIR)
AC_SUBST(AVR_LIBC_USER_MANUAL)
AC_SUBST(DOC_INST_DIR)

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
    AC_COMPILE_IFELSE(
      [AC_LANG_SOURCE([],[])],
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

# avr1 and avr2
AM_CONDITIONAL(HAS_avr2, true)
AM_CONDITIONAL(HAS_at90s1200, true)
AM_CONDITIONAL(HAS_at90s2313, true)
AM_CONDITIONAL(HAS_at90s2323, true)
AM_CONDITIONAL(HAS_at90s2333, true)
AM_CONDITIONAL(HAS_at90s2343, true)
AM_CONDITIONAL(HAS_at90s4414, true)
AM_CONDITIONAL(HAS_at90s4433, true)
AM_CONDITIONAL(HAS_at90s4434, true)
AM_CONDITIONAL(HAS_at90s8515, true)
AM_CONDITIONAL(HAS_at90c8534, true)
AM_CONDITIONAL(HAS_at90s8535, true)
AM_CONDITIONAL(HAS_attiny11, true)
AM_CONDITIONAL(HAS_attiny12, true)
AM_CONDITIONAL(HAS_attiny15, true)
AM_CONDITIONAL(HAS_attiny22, true)
AM_CONDITIONAL(HAS_attiny26, true)
AM_CONDITIONAL(HAS_attiny28, true)
AM_CONDITIONAL(HAS_at86rf401, true)

CHECK_AVR_DEVICE(attiny13)
AM_CONDITIONAL(HAS_attiny13, test "x$HAS_attiny13" = "xyes")

CHECK_AVR_DEVICE(attiny2313)
AM_CONDITIONAL(HAS_attiny2313, test "x$HAS_attiny2313" = "xyes")

CHECK_AVR_DEVICE(attiny25)
AM_CONDITIONAL(HAS_attiny25, test "x$HAS_attiny25" = "xyes")

CHECK_AVR_DEVICE(attiny45)
AM_CONDITIONAL(HAS_attiny45, test "x$HAS_attiny45" = "xyes")

CHECK_AVR_DEVICE(attiny85)
AM_CONDITIONAL(HAS_attiny85, test "x$HAS_attiny85" = "xyes")

CHECK_AVR_DEVICE(attiny24)
AM_CONDITIONAL(HAS_attiny24, test "x$HAS_attiny24" = "xyes")

CHECK_AVR_DEVICE(attiny44)
AM_CONDITIONAL(HAS_attiny44, test "x$HAS_attiny44" = "xyes")

CHECK_AVR_DEVICE(attiny84)
AM_CONDITIONAL(HAS_attiny84, test "x$HAS_attiny84" = "xyes")

CHECK_AVR_DEVICE(attiny261)
AM_CONDITIONAL(HAS_attiny261, test "x$HAS_attiny261" = "xyes")

CHECK_AVR_DEVICE(attiny461)
AM_CONDITIONAL(HAS_attiny461, test "x$HAS_attiny461" = "xyes")

CHECK_AVR_DEVICE(attiny861)
AM_CONDITIONAL(HAS_attiny861, test "x$HAS_attiny861" = "xyes")

# avr3
AM_CONDITIONAL(HAS_avr3, true)
AM_CONDITIONAL(HAS_atmega103, true)
AM_CONDITIONAL(HAS_at43usb320, true)
AM_CONDITIONAL(HAS_at43usb355, true)
AM_CONDITIONAL(HAS_at76c711, true)

# avr4
AM_CONDITIONAL(HAS_avr4, true)
AM_CONDITIONAL(HAS_atmega8, true)
AM_CONDITIONAL(HAS_atmega8515, true)
AM_CONDITIONAL(HAS_atmega8535, true)

CHECK_AVR_DEVICE(atmega48)
AM_CONDITIONAL(HAS_atmega48, test "x$HAS_atmega48" = "xyes")

CHECK_AVR_DEVICE(atmega88)
AM_CONDITIONAL(HAS_atmega88, test "x$HAS_atmega88" = "xyes")

CHECK_AVR_DEVICE(at90pwm1)
AM_CONDITIONAL(HAS_at90pwm1, test "x$HAS_at90pwm1" = "xyes")

CHECK_AVR_DEVICE(at90pwm2)
AM_CONDITIONAL(HAS_at90pwm2, test "x$HAS_at90pwm2" = "xyes")

CHECK_AVR_DEVICE(at90pwm3)
AM_CONDITIONAL(HAS_at90pwm3, test "x$HAS_at90pwm3" = "xyes")

# avr5
AM_CONDITIONAL(HAS_avr5, true)
AM_CONDITIONAL(HAS_atmega16, true)
AM_CONDITIONAL(HAS_atmega161, true)
AM_CONDITIONAL(HAS_atmega162, true)
AM_CONDITIONAL(HAS_atmega163, true)
AM_CONDITIONAL(HAS_atmega169, true)
AM_CONDITIONAL(HAS_atmega32, true)
AM_CONDITIONAL(HAS_atmega323, true)
AM_CONDITIONAL(HAS_atmega64, true)
AM_CONDITIONAL(HAS_atmega128, true)
AM_CONDITIONAL(HAS_at94k, true)

CHECK_AVR_DEVICE(atmega164p)
AM_CONDITIONAL(HAS_atmega164p, test "x$HAS_atmega164p" = "xyes")

CHECK_AVR_DEVICE(atmega165)
AM_CONDITIONAL(HAS_atmega165, test "x$HAS_atmega165" = "xyes")

CHECK_AVR_DEVICE(atmega165p)
AM_CONDITIONAL(HAS_atmega165p, test "x$HAS_atmega165p" = "xyes")

CHECK_AVR_DEVICE(atmega168)
AM_CONDITIONAL(HAS_atmega168, test "x$HAS_atmega168" = "xyes")

CHECK_AVR_DEVICE(atmega169p)
AM_CONDITIONAL(HAS_atmega169p, test "x$HAS_atmega169p" = "xyes")

CHECK_AVR_DEVICE(atmega324p)
AM_CONDITIONAL(HAS_atmega324p, test "x$HAS_atmega324p" = "xyes")

CHECK_AVR_DEVICE(atmega325)
AM_CONDITIONAL(HAS_atmega325, test "x$HAS_atmega325" = "xyes")

CHECK_AVR_DEVICE(atmega325p)
AM_CONDITIONAL(HAS_atmega325p, test "x$HAS_atmega325p" = "xyes")

CHECK_AVR_DEVICE(atmega3250)
AM_CONDITIONAL(HAS_atmega3250, test "x$HAS_atmega3250" = "xyes")

CHECK_AVR_DEVICE(atmega3250p)
AM_CONDITIONAL(HAS_atmega3250p, test "x$HAS_atmega3250p" = "xyes")

CHECK_AVR_DEVICE(atmega329)
AM_CONDITIONAL(HAS_atmega329, test "x$HAS_atmega329" = "xyes")

CHECK_AVR_DEVICE(atmega329p)
AM_CONDITIONAL(HAS_atmega329p, test "x$HAS_atmega329p" = "xyes")

CHECK_AVR_DEVICE(atmega3290)
AM_CONDITIONAL(HAS_atmega3290, test "x$HAS_atmega3290" = "xyes")

CHECK_AVR_DEVICE(atmega3290p)
AM_CONDITIONAL(HAS_atmega3290p, test "x$HAS_atmega3290p" = "xyes")

CHECK_AVR_DEVICE(atmega406)
AM_CONDITIONAL(HAS_atmega406, test "x$HAS_atmega406" = "xyes")

CHECK_AVR_DEVICE(atmega640)
AM_CONDITIONAL(HAS_atmega640, test "x$HAS_atmega640" = "xyes")

CHECK_AVR_DEVICE(atmega644)
AM_CONDITIONAL(HAS_atmega644, test "x$HAS_atmega644" = "xyes")

CHECK_AVR_DEVICE(atmega644p)
AM_CONDITIONAL(HAS_atmega644p, test "x$HAS_atmega644p" = "xyes")

CHECK_AVR_DEVICE(atmega645)
AM_CONDITIONAL(HAS_atmega645, test "x$HAS_atmega645" = "xyes")

CHECK_AVR_DEVICE(atmega6450)
AM_CONDITIONAL(HAS_atmega6450, test "x$HAS_atmega6450" = "xyes")

CHECK_AVR_DEVICE(atmega649)
AM_CONDITIONAL(HAS_atmega649, test "x$HAS_atmega649" = "xyes")

CHECK_AVR_DEVICE(atmega6490)
AM_CONDITIONAL(HAS_atmega6490, test "x$HAS_atmega6490" = "xyes")

CHECK_AVR_DEVICE(atmega1280)
AM_CONDITIONAL(HAS_atmega1280, test "x$HAS_atmega1280" = "xyes")

CHECK_AVR_DEVICE(atmega1281)
AM_CONDITIONAL(HAS_atmega1281, test "x$HAS_atmega1281" = "xyes")

CHECK_AVR_DEVICE(at90can32)
AM_CONDITIONAL(HAS_at90can32, test "x$HAS_at90can32" = "xyes")

CHECK_AVR_DEVICE(at90can64)
AM_CONDITIONAL(HAS_at90can64, test "x$HAS_at90can64" = "xyes")

CHECK_AVR_DEVICE(at90can128)
AM_CONDITIONAL(HAS_at90can128, test "x$HAS_at90can128" = "xyes")

CHECK_AVR_DEVICE(at90usb646)
AM_CONDITIONAL(HAS_at90usb646, test "x$HAS_at90usb646" = "xyes")

CHECK_AVR_DEVICE(at90usb647)
AM_CONDITIONAL(HAS_at90usb647, test "x$HAS_at90usb647" = "xyes")

CHECK_AVR_DEVICE(at90usb1286)
AM_CONDITIONAL(HAS_at90usb1286, test "x$HAS_at90usb1286" = "xyes")

CHECK_AVR_DEVICE(at90usb1287)
AM_CONDITIONAL(HAS_at90usb1287, test "x$HAS_at90usb1287" = "xyes")

# avr6
CHECK_AVR_DEVICE(avr6)
AM_CONDITIONAL(HAS_avr6, test "x$HAS_avr6" = "xyes")

CHECK_AVR_DEVICE(atmega2560)
AM_CONDITIONAL(HAS_atmega2560, test "x$HAS_atmega2560" = "xyes")

CHECK_AVR_DEVICE(atmega2561)
AM_CONDITIONAL(HAS_atmega2561, test "x$HAS_atmega2561" = "xyes")

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
	include/util/Makefile
	libc/Makefile
	libc/misc/Makefile
	libc/pmstring/Makefile
	libc/stdio/Makefile
	libc/stdlib/Makefile
	libc/string/Makefile
	libm/Makefile
	libm/fplib/Makefile
	scripts/Makefile
	devtools/Makefile
])

#avr1 and avr2
AC_CONFIG_FILES([
	avr/lib/avr2/Makefile
	avr/lib/avr2/at90s1200/Makefile
	avr/lib/avr2/at90s2313/Makefile
	avr/lib/avr2/at90s2323/Makefile
	avr/lib/avr2/at90s2333/Makefile
	avr/lib/avr2/at90s2343/Makefile
	avr/lib/avr2/at90s4414/Makefile
	avr/lib/avr2/at90s4433/Makefile
	avr/lib/avr2/at90s4434/Makefile
	avr/lib/avr2/at90s8515/Makefile
	avr/lib/avr2/at90c8534/Makefile
	avr/lib/avr2/at90s8535/Makefile
	avr/lib/avr2/attiny11/Makefile
	avr/lib/avr2/attiny12/Makefile
	avr/lib/avr2/attiny13/Makefile
	avr/lib/avr2/attiny15/Makefile
	avr/lib/avr2/attiny22/Makefile
	avr/lib/avr2/attiny24/Makefile
	avr/lib/avr2/attiny25/Makefile
	avr/lib/avr2/attiny26/Makefile
	avr/lib/avr2/attiny261/Makefile
	avr/lib/avr2/attiny28/Makefile
	avr/lib/avr2/attiny44/Makefile
	avr/lib/avr2/attiny45/Makefile
	avr/lib/avr2/attiny461/Makefile
	avr/lib/avr2/attiny84/Makefile
	avr/lib/avr2/attiny85/Makefile
	avr/lib/avr2/attiny861/Makefile
	avr/lib/avr2/attiny2313/Makefile
	avr/lib/avr2/at86rf401/Makefile
])

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
	avr/lib/avr4/atmega48/Makefile
	avr/lib/avr4/atmega8/Makefile
	avr/lib/avr4/atmega88/Makefile
	avr/lib/avr4/atmega8515/Makefile
	avr/lib/avr4/atmega8535/Makefile
	avr/lib/avr4/at90pwm1/Makefile
	avr/lib/avr4/at90pwm2/Makefile
	avr/lib/avr4/at90pwm3/Makefile
])

#avr5
AC_CONFIG_FILES([
	avr/lib/avr5/Makefile
	avr/lib/avr5/atmega16/Makefile
	avr/lib/avr5/atmega161/Makefile
	avr/lib/avr5/atmega162/Makefile
	avr/lib/avr5/atmega163/Makefile
	avr/lib/avr5/atmega164p/Makefile
	avr/lib/avr5/atmega165/Makefile
	avr/lib/avr5/atmega165p/Makefile
	avr/lib/avr5/atmega168/Makefile
	avr/lib/avr5/atmega169/Makefile
	avr/lib/avr5/atmega169p/Makefile
	avr/lib/avr5/atmega32/Makefile
	avr/lib/avr5/atmega323/Makefile
	avr/lib/avr5/atmega324p/Makefile
	avr/lib/avr5/atmega325/Makefile
	avr/lib/avr5/atmega325p/Makefile
	avr/lib/avr5/atmega3250/Makefile
	avr/lib/avr5/atmega3250p/Makefile
	avr/lib/avr5/atmega329/Makefile
	avr/lib/avr5/atmega329p/Makefile
	avr/lib/avr5/atmega3290/Makefile
	avr/lib/avr5/atmega3290p/Makefile
	avr/lib/avr5/atmega406/Makefile
	avr/lib/avr5/atmega64/Makefile
	avr/lib/avr5/atmega640/Makefile
	avr/lib/avr5/atmega644/Makefile
	avr/lib/avr5/atmega644p/Makefile
	avr/lib/avr5/atmega645/Makefile
	avr/lib/avr5/atmega6450/Makefile
	avr/lib/avr5/atmega649/Makefile
	avr/lib/avr5/atmega6490/Makefile
	avr/lib/avr5/atmega128/Makefile
	avr/lib/avr5/atmega1280/Makefile
	avr/lib/avr5/atmega1281/Makefile
	avr/lib/avr5/at90can32/Makefile
	avr/lib/avr5/at90can64/Makefile
	avr/lib/avr5/at90can128/Makefile
	avr/lib/avr5/at90usb646/Makefile
	avr/lib/avr5/at90usb647/Makefile
	avr/lib/avr5/at90usb1286/Makefile
	avr/lib/avr5/at90usb1287/Makefile
	avr/lib/avr5/at94k/Makefile
])

#avr6
AC_CONFIG_FILES([
	avr/lib/avr6/Makefile
	avr/lib/avr6/atmega2560/Makefile
	avr/lib/avr6/atmega2561/Makefile
])

AC_OUTPUT
