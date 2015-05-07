#                                               -*- Autoconf -*-
#
# Copyright (c) 2004,  Theodore A. Roth
# Copyright (c) 2005,2006,2007,2009  Anatoly Sokolov
# Copyright (c) 2005,2008  Joerg Wunsch
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

dnl library versioning -- modify these on releases
dnl        macro name           value            description
m4_define([avr_libc_major],    [1])dnl           major version
m4_define([avr_libc_minor],    [8])dnl           minor version
m4_define([avr_libc_revision], [1])dnl           revision (dot-dot version)
m4_define([avr_libc_revision_suffix], [svn])dnl  revision suffix (if any)
m4_define([avr_libc_reldate],  [20140812])dnl    release date
dnl end of library versioning data

m4_define([avr_libc_version],
          avr_libc_major.avr_libc_minor.avr_libc_revision()avr_libc_revision_suffix)dnl
m4_define([avr_libc_version_numeric],
          m4_eval(10000 * avr_libc_major + dnl
                    100 * avr_libc_minor + dnl
                          avr_libc_revision))dnl

AC_INIT(avr-libc, avr_libc_version, avr-libc-dev@nongnu.org)

AC_PREREQ(2.59)
AC_REVISION($Revision$)

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

dnl Minimum version of Automake is 1.8.
dnl We don't want the gzip distribution tarball anymore.
AM_INIT_AUTOMAKE([1.8 dist-bzip2 no-dist-gzip])

# We don't want touse the cflags from the environment since we need control
# of this when we're building the libs.
CFLAGS=""


dnl This fix is from Newlib in config/override.m4.
dnl Fix 2.64 cross compile detection for AVR by not trying to compile fopen.
m4_if(m4_defn([m4_PACKAGE_VERSION]), [2.64],
  [m4_foreach([_GCC_LANG], [C, C++, Fortran, Fortran 77],
     [m4_define([_AC_LANG_IO_PROGRAM(]_GCC_LANG[)], m4_defn([AC_LANG_PROGRAM(]_GCC_LANG[)]))])])


# Checks for programs.

AC_PROG_CC
AC_CHECK_TOOL(AS, as, as)
AM_PROG_AS
AC_PROG_RANLIB
AC_CHECK_TOOL(AR, ar, ar)

# Make sure that we found the right avr cross-compiler.

case "${CC}" in
   *gcc*)
       case "X`${CC} -dumpmachine`X" in
           XavrX) ;;
           *) AC_MSG_ERROR(Wrong C compiler found; check the PATH!) ;;
       esac
       ;;
   *) AC_MSG_ERROR(Wrong C compiler found; check the PATH!) ;;
esac
case "${AS}" in
   *avr*as*) ;;
   *) AC_MSG_ERROR(Wrong assembler found; check the PATH!) ;;
esac
case "${AR}" in
   *avr*ar*) ;;
   *) AC_MSG_ERROR(Wrong archiver found; check the PATH!) ;;
esac
case "${RANLIB}" in
   *avr*ranlib*) ;;
   *) AC_MSG_ERROR(Wrong ranlib found; check the PATH!) ;;
esac

AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

dnl Check if avr-gcc >= 5.1.0 as they expect device library
GCC_VER=`${CC} -dumpversion`
AS_VERSION_COMPARE(${GCC_VER},"5.1.0",[DEV_LIB="no"],[DEV_LIB="yes"],[DEV_LIB="yes"])
AM_CONDITIONAL(HAS_GCC_5_1, test "x${GCC_VER}" = "x5.1.0")

dnl Enable device library when specified. If not specified and
dnl gcc expects (e.g. >= 5) device lib then enable device library.
AC_ARG_ENABLE(device-lib,
[  --enable-device-lib     build separate device library],
[enable_device_lib=true],
[case "${DEV_LIB}" in
  yes) enable_device_lib=true
       AC_MSG_NOTICE(Enabled device library) ;;
  *) ;;
 esac])

dnl define HAS_DEV_LIB if device library enabled
AM_CONDITIONAL(HAS_DEV_LIB, [test x$enable_device_lib = xtrue])

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
AC_SUBST(TARGET_DOX_PDF)
AC_SUBST(TARGET_DOX_HTML)
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

dnl Let the user decide which debug information to generate.
dnl Default is nothing, suitable for binary distributions of the
dnl compiled library.  Alternative options include stabs, dwarf-2,
dnl or dwarf-4.
AC_ARG_ENABLE(debug-info,
[  --enable-debug-info=stabs|dwarf-2|dwarf-4  Enable generation of debugging information],
[case "${enableval}" in
  yes|dwarf2|dwarf-2) debuginfo=dwarf2 ;;
  no)                 debuginfo="" ;;
  stabs)              debuginfo=stabs ;;
  dwarf4|dwarf-4)     debuginfo=dwarf4 ;;
  *)                  AC_MSG_ERROR([bad value ${enableval} for --enable-debug-info option; should be either stabs, dwarf-2, or dwarf-4]) ;;
 esac], [debuginfo=""])

dnl Decide which debuginfo information to include
case "$debuginfo" in
"")      CDEBUG=""; ASDEBUG="" ;;
stabs)   CDEBUG="-gstabs"; ASDEBUG="-Wa,-gstabs" ;;
dwarf2)  CDEBUG="-gdwarf-2"; ASDEBUG="-Wa,-gdwarf-2" ;;
dwarf4)  CDEBUG="-gdwarf-4"; ASDEBUG="-Wa,-gdwarf-2" ;;
esac

AC_SUBST(CDEBUG)
AC_SUBST(ASDEBUG)

FNO_JUMP_TABLES=""
AC_SUBST(FNO_JUMP_TABLES)

HAS_DELAY_CYCLES=0
AC_SUBST(HAS_DELAY_CYCLES)

AC_DEFUN(
  CHECK_MNO_TABLEJUMP,
  [
    old_CC=${CC}
    old_CFLAGS=${CFLAGS}
    CFLAGS="-mno-tablejump"
    CC=`echo "${CC}" | sed 's/-mmcu=avr.//'`
    AC_MSG_CHECKING(whether ${CC} supports -mno-tablejump)
    AC_COMPILE_IFELSE(
      [AC_LANG_SOURCE([],[])],
      [has_mno_tablejump=yes],
      [has_mno_tablejump=no]
    )
    if test "x$has_mno_tablejump" = "xyes"
    then
      FNO_JUMP_TABLES="-mno-tablejump"
    fi
    AC_MSG_RESULT($has_mno_tablejump)
    CC=${old_CC}
    CFLAGS=${old_CFLAGS}
  ]
)

AC_DEFUN(
  CHECK_FNO_JUMP_TABLES,
  [
    old_CC=${CC}
    old_CFLAGS=${CFLAGS}
    CFLAGS="-fno-jump-tables"
    CC=`echo "${CC}" | sed 's/-mmcu=avr.//'`
    AC_MSG_CHECKING(whether ${CC} supports -fno-jump-tables)
    AC_COMPILE_IFELSE(
      [AC_LANG_SOURCE([],[])],
      [has_fno_jump_tables=yes],
      [has_fno_jump_tables=no]
    )
    if test "x$has_fno_jump_tables" = "xyes"
    then
      FNO_JUMP_TABLES="-fno-jump-tables"
    fi
    AC_MSG_RESULT($has_fno_jump_tables)
    CC=${old_CC}
    CFLAGS=${old_CFLAGS}
  ]
)

AC_DEFUN(
  CHECK_BUILTIN_DELAY_CYCLES,
  [
    CC=`echo "${CC}" | sed 's/-mmcu=avr.//'`
    AC_MSG_CHECKING(whether ${CC} supports __builtin_avr_delay_cycles)
    echo "extern void __builtin_avr_delay_cycles(unsigned long);\
    int main(void) { __builtin_avr_delay_cycles(42); return 0; }" |\
    ${CC} -S -xc -o - - |\
    grep __builtin_avr_delay_cycles >/dev/null
    if test "$?" != "0"
    then
      HAS_DELAY_CYCLES=1
      has_delay_cycles="yes"
    else
      has_delay_cycles="no"
    fi
    AC_MSG_RESULT($has_delay_cycles)
    CC=${old_CC}
  ]
)

CHECK_MNO_TABLEJUMP
CHECK_FNO_JUMP_TABLES
CHECK_BUILTIN_DELAY_CYCLES

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


# avr1
AM_CONDITIONAL(HAS_avr1, true)
AM_CONDITIONAL(HAS_at90s1200, true)
AM_CONDITIONAL(HAS_attiny11, true)
AM_CONDITIONAL(HAS_attiny12, true)
AM_CONDITIONAL(HAS_attiny15, true)
AM_CONDITIONAL(HAS_attiny28, true)


# avr2
AM_CONDITIONAL(HAS_avr2, true)
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
AM_CONDITIONAL(HAS_attiny22, true)
AM_CONDITIONAL(HAS_attiny26, true)


#avr25
CHECK_AVR_DEVICE(avr25)
AM_CONDITIONAL(HAS_avr25, test "x$HAS_avr25" = "xyes")

CHECK_AVR_DEVICE(ata5272)
AM_CONDITIONAL(HAS_ata5272, test "x$HAS_ata5272" = "xyes")

CHECK_AVR_DEVICE(attiny13)
AM_CONDITIONAL(HAS_attiny13, test "x$HAS_attiny13" = "xyes")

CHECK_AVR_DEVICE(attiny13a)
AM_CONDITIONAL(HAS_attiny13a, test "x$HAS_attiny13a" = "xyes")

CHECK_AVR_DEVICE(attiny2313)
AM_CONDITIONAL(HAS_attiny2313, test "x$HAS_attiny2313" = "xyes")

CHECK_AVR_DEVICE(attiny2313a)
AM_CONDITIONAL(HAS_attiny2313a, test "x$HAS_attiny2313a" = "xyes")

CHECK_AVR_DEVICE(attiny24)
AM_CONDITIONAL(HAS_attiny24, test "x$HAS_attiny24" = "xyes")

CHECK_AVR_DEVICE(attiny24a)
AM_CONDITIONAL(HAS_attiny24a, test "x$HAS_attiny24a" = "xyes")

CHECK_AVR_DEVICE(attiny25)
AM_CONDITIONAL(HAS_attiny25, test "x$HAS_attiny25" = "xyes")

CHECK_AVR_DEVICE(attiny261)
AM_CONDITIONAL(HAS_attiny261, test "x$HAS_attiny261" = "xyes")

CHECK_AVR_DEVICE(attiny261a)
AM_CONDITIONAL(HAS_attiny261a, test "x$HAS_attiny261a" = "xyes")

CHECK_AVR_DEVICE(attiny43u)
AM_CONDITIONAL(HAS_attiny43u, test "x$HAS_attiny43u" = "xyes")

CHECK_AVR_DEVICE(attiny4313)
AM_CONDITIONAL(HAS_attiny4313, test "x$HAS_attiny4313" = "xyes")

CHECK_AVR_DEVICE(attiny44)
AM_CONDITIONAL(HAS_attiny44, test "x$HAS_attiny44" = "xyes")

CHECK_AVR_DEVICE(attiny44a)
AM_CONDITIONAL(HAS_attiny44a, test "x$HAS_attiny44a" = "xyes")

CHECK_AVR_DEVICE(attiny45)
AM_CONDITIONAL(HAS_attiny45, test "x$HAS_attiny45" = "xyes")

CHECK_AVR_DEVICE(attiny461)
AM_CONDITIONAL(HAS_attiny461, test "x$HAS_attiny461" = "xyes")

CHECK_AVR_DEVICE(attiny461a)
AM_CONDITIONAL(HAS_attiny461a, test "x$HAS_attiny461a" = "xyes")

CHECK_AVR_DEVICE(attiny48)
AM_CONDITIONAL(HAS_attiny48, test "x$HAS_attiny48" = "xyes")

CHECK_AVR_DEVICE(attiny828)
AM_CONDITIONAL(HAS_attiny828, test "x$HAS_attiny828" = "xyes")

CHECK_AVR_DEVICE(attiny84)
AM_CONDITIONAL(HAS_attiny84, test "x$HAS_attiny84" = "xyes")

CHECK_AVR_DEVICE(attiny84a)
AM_CONDITIONAL(HAS_attiny84a, test "x$HAS_attiny84a" = "xyes")

CHECK_AVR_DEVICE(attiny85)
AM_CONDITIONAL(HAS_attiny85, test "x$HAS_attiny85" = "xyes")

CHECK_AVR_DEVICE(attiny861)
AM_CONDITIONAL(HAS_attiny861, test "x$HAS_attiny861" = "xyes")

CHECK_AVR_DEVICE(attiny861a)
AM_CONDITIONAL(HAS_attiny861a, test "x$HAS_attiny861a" = "xyes")

CHECK_AVR_DEVICE(attiny87)
AM_CONDITIONAL(HAS_attiny87, test "x$HAS_attiny87" = "xyes")

CHECK_AVR_DEVICE(attiny88)
AM_CONDITIONAL(HAS_attiny88, test "x$HAS_attiny88" = "xyes")

CHECK_AVR_DEVICE(at86rf401)
AM_CONDITIONAL(HAS_at86rf401, test "x$HAS_at86rf401" = "xyes")


# avr3
AM_CONDITIONAL(HAS_avr3, true)
AM_CONDITIONAL(HAS_at43usb320, true)
AM_CONDITIONAL(HAS_at43usb355, true)
AM_CONDITIONAL(HAS_at76c711, true)

#avr31
CHECK_AVR_DEVICE(avr31)
AM_CONDITIONAL(HAS_avr31, test "x$HAS_avr31" = "xyes")

AM_CONDITIONAL(HAS_atmega103, true)


#avr35
CHECK_AVR_DEVICE(avr35)
AM_CONDITIONAL(HAS_avr35, test "x$HAS_avr35" = "xyes")

CHECK_AVR_DEVICE(at90usb82)
AM_CONDITIONAL(HAS_at90usb82, test "x$HAS_at90usb82" = "xyes")

CHECK_AVR_DEVICE(at90usb162)
AM_CONDITIONAL(HAS_at90usb162, test "x$HAS_at90usb162" = "xyes")

CHECK_AVR_DEVICE(ata5505)
AM_CONDITIONAL(HAS_ata5505, test "x$HAS_ata5505" = "xyes")

CHECK_AVR_DEVICE(atmega8u2)
AM_CONDITIONAL(HAS_atmega8u2, test "x$HAS_atmega8u2" = "xyes")

CHECK_AVR_DEVICE(atmega16u2)
AM_CONDITIONAL(HAS_atmega16u2, test "x$HAS_atmega16u2" = "xyes")

CHECK_AVR_DEVICE(atmega32u2)
AM_CONDITIONAL(HAS_atmega32u2, test "x$HAS_atmega32u2" = "xyes")

CHECK_AVR_DEVICE(attiny167)
AM_CONDITIONAL(HAS_attiny167, test "x$HAS_attiny167" = "xyes")

CHECK_AVR_DEVICE(attiny1634)
AM_CONDITIONAL(HAS_attiny1634, test "x$HAS_attiny1634" = "xyes")


# avr4
AM_CONDITIONAL(HAS_avr4, true)
AM_CONDITIONAL(HAS_atmega8, true)
AM_CONDITIONAL(HAS_atmega8515, true)
AM_CONDITIONAL(HAS_atmega8535, true)

CHECK_AVR_DEVICE(ata6285)
AM_CONDITIONAL(HAS_ata6285, test "x$HAS_ata6285" = "xyes")

CHECK_AVR_DEVICE(ata6286)
AM_CONDITIONAL(HAS_ata6286, test "x$HAS_ata6286" = "xyes")

CHECK_AVR_DEVICE(ata6289)
AM_CONDITIONAL(HAS_ata6289, test "x$HAS_ata6289" = "xyes")

CHECK_AVR_DEVICE(atmega8a)
AM_CONDITIONAL(HAS_atmega8a, test "x$HAS_atmega8a" = "xyes")

CHECK_AVR_DEVICE(atmega48)
AM_CONDITIONAL(HAS_atmega48, test "x$HAS_atmega48" = "xyes")

CHECK_AVR_DEVICE(atmega48a)
AM_CONDITIONAL(HAS_atmega48a, test "x$HAS_atmega48a" = "xyes")

CHECK_AVR_DEVICE(atmega48pa)
AM_CONDITIONAL(HAS_atmega48pa, test "x$HAS_atmega48pa" = "xyes")

CHECK_AVR_DEVICE(atmega48p)
AM_CONDITIONAL(HAS_atmega48p, test "x$HAS_atmega48p" = "xyes")

CHECK_AVR_DEVICE(atmega88)
AM_CONDITIONAL(HAS_atmega88, test "x$HAS_atmega88" = "xyes")

CHECK_AVR_DEVICE(atmega88a)
AM_CONDITIONAL(HAS_atmega88a, test "x$HAS_atmega88a" = "xyes")

CHECK_AVR_DEVICE(atmega88p)
AM_CONDITIONAL(HAS_atmega88p, test "x$HAS_atmega88p" = "xyes")

CHECK_AVR_DEVICE(atmega88pa)
AM_CONDITIONAL(HAS_atmega88pa, test "x$HAS_atmega88pa" = "xyes")

CHECK_AVR_DEVICE(atmega8hva)
AM_CONDITIONAL(HAS_atmega8hva, test "x$HAS_atmega8hva" = "xyes")

CHECK_AVR_DEVICE(at90pwm1)
AM_CONDITIONAL(HAS_at90pwm1, test "x$HAS_at90pwm1" = "xyes")

CHECK_AVR_DEVICE(at90pwm2)
AM_CONDITIONAL(HAS_at90pwm2, test "x$HAS_at90pwm2" = "xyes")

CHECK_AVR_DEVICE(at90pwm2b)
AM_CONDITIONAL(HAS_at90pwm2b, test "x$HAS_at90pwm2b" = "xyes")

CHECK_AVR_DEVICE(at90pwm3)
AM_CONDITIONAL(HAS_at90pwm3, test "x$HAS_at90pwm3" = "xyes")

CHECK_AVR_DEVICE(at90pwm3b)
AM_CONDITIONAL(HAS_at90pwm3b, test "x$HAS_at90pwm3b" = "xyes")

CHECK_AVR_DEVICE(at90pwm81)
AM_CONDITIONAL(HAS_at90pwm81, test "x$HAS_at90pwm81" = "xyes")


# avr5
AM_CONDITIONAL(HAS_avr5, true)

CHECK_AVR_DEVICE(at90can32)
AM_CONDITIONAL(HAS_at90can32, test "x$HAS_at90can32" = "xyes")

CHECK_AVR_DEVICE(at90can64)
AM_CONDITIONAL(HAS_at90can64, test "x$HAS_at90can64" = "xyes")

CHECK_AVR_DEVICE(at90scr100)
AM_CONDITIONAL(HAS_at90scr100, test "x$HAS_at90scr100" = "xyes")

CHECK_AVR_DEVICE(at90usb646)
AM_CONDITIONAL(HAS_at90usb646, test "x$HAS_at90usb646" = "xyes")

CHECK_AVR_DEVICE(at90usb647)
AM_CONDITIONAL(HAS_at90usb647, test "x$HAS_at90usb647" = "xyes")

CHECK_AVR_DEVICE(at90pwm316)
AM_CONDITIONAL(HAS_at90pwm316, test "x$HAS_at90pwm316" = "xyes")

CHECK_AVR_DEVICE(at90pwm216)
AM_CONDITIONAL(HAS_at90pwm216, test "x$HAS_at90pwm216" = "xyes")

CHECK_AVR_DEVICE(at90pwm161)
AM_CONDITIONAL(HAS_at90pwm161, test "x$HAS_at90pwm161" = "xyes")

CHECK_AVR_DEVICE(at94k)
AM_CONDITIONAL(HAS_at94k, test "x$HAS_at94k" = "xyes")

CHECK_AVR_DEVICE(ata5790)
AM_CONDITIONAL(HAS_ata5790, test "x$HAS_ata5790" = "xyes")

CHECK_AVR_DEVICE(ata5795)
AM_CONDITIONAL(HAS_ata5795, test "x$HAS_ata5795" = "xyes")

CHECK_AVR_DEVICE(atmega16)
AM_CONDITIONAL(HAS_atmega16, test "x$HAS_atmega16" = "xyes")

CHECK_AVR_DEVICE(atmega16a)
AM_CONDITIONAL(HAS_atmega16a, test "x$HAS_atmega16a" = "xyes")

CHECK_AVR_DEVICE(atmega161)
AM_CONDITIONAL(HAS_atmega161, test "x$HAS_atmega161" = "xyes")

CHECK_AVR_DEVICE(atmega162)
AM_CONDITIONAL(HAS_atmega162, test "x$HAS_atmega162" = "xyes")

CHECK_AVR_DEVICE(atmega163)
AM_CONDITIONAL(HAS_atmega163, test "x$HAS_atmega163" = "xyes")

CHECK_AVR_DEVICE(atmega164a)
AM_CONDITIONAL(HAS_atmega164a, test "x$HAS_atmega164a" = "xyes")

CHECK_AVR_DEVICE(atmega164p)
AM_CONDITIONAL(HAS_atmega164p, test "x$HAS_atmega164p" = "xyes")

CHECK_AVR_DEVICE(atmega164pa)
AM_CONDITIONAL(HAS_atmega164pa, test "x$HAS_atmega164pa" = "xyes")

CHECK_AVR_DEVICE(atmega165)
AM_CONDITIONAL(HAS_atmega165, test "x$HAS_atmega165" = "xyes")

CHECK_AVR_DEVICE(atmega165a)
AM_CONDITIONAL(HAS_atmega165a, test "x$HAS_atmega165a" = "xyes")

CHECK_AVR_DEVICE(atmega165p)
AM_CONDITIONAL(HAS_atmega165p, test "x$HAS_atmega165p" = "xyes")

CHECK_AVR_DEVICE(atmega165pa)
AM_CONDITIONAL(HAS_atmega165pa, test "x$HAS_atmega165pa" = "xyes")

CHECK_AVR_DEVICE(atmega168)
AM_CONDITIONAL(HAS_atmega168, test "x$HAS_atmega168" = "xyes")

CHECK_AVR_DEVICE(atmega168a)
AM_CONDITIONAL(HAS_atmega168a, test "x$HAS_atmega168a" = "xyes")

CHECK_AVR_DEVICE(atmega168p)
AM_CONDITIONAL(HAS_atmega168p, test "x$HAS_atmega168p" = "xyes")

CHECK_AVR_DEVICE(atmega168pa)
AM_CONDITIONAL(HAS_atmega168pa, test "x$HAS_atmega168pa" = "xyes")

CHECK_AVR_DEVICE(atmega169)
AM_CONDITIONAL(HAS_atmega169, test "x$HAS_atmega169" = "xyes")

CHECK_AVR_DEVICE(atmega169a)
AM_CONDITIONAL(HAS_atmega169a, test "x$HAS_atmega169a" = "xyes")

CHECK_AVR_DEVICE(atmega169p)
AM_CONDITIONAL(HAS_atmega169p, test "x$HAS_atmega169p" = "xyes")

CHECK_AVR_DEVICE(atmega169pa)
AM_CONDITIONAL(HAS_atmega169pa, test "x$HAS_atmega169pa" = "xyes")

CHECK_AVR_DEVICE(atmega16hva)
AM_CONDITIONAL(HAS_atmega16hva, test "x$HAS_atmega16hva" = "xyes")

CHECK_AVR_DEVICE(atmega16hva2)
AM_CONDITIONAL(HAS_atmega16hva2, test "x$HAS_atmega16hva2" = "xyes")

CHECK_AVR_DEVICE(atmega16hvb)
AM_CONDITIONAL(HAS_atmega16hvb, test "x$HAS_atmega16hvb" = "xyes")

CHECK_AVR_DEVICE(atmega16hvbrevb)
AM_CONDITIONAL(HAS_atmega16hvbrevb, test "x$HAS_atmega16hvbrevb" = "xyes")

CHECK_AVR_DEVICE(atmega16m1)
AM_CONDITIONAL(HAS_atmega16m1, test "x$HAS_atmega16m1" = "xyes")

CHECK_AVR_DEVICE(atmega16u4)
AM_CONDITIONAL(HAS_atmega16u4, test "x$HAS_atmega16u4" = "xyes")

CHECK_AVR_DEVICE(atmega32)
AM_CONDITIONAL(HAS_atmega32, test "x$HAS_atmega32" = "xyes")

CHECK_AVR_DEVICE(atmega32a)
AM_CONDITIONAL(HAS_atmega32a, test "x$HAS_atmega32a" = "xyes")

CHECK_AVR_DEVICE(atmega323)
AM_CONDITIONAL(HAS_atmega323, test "x$HAS_atmega323" = "xyes")

CHECK_AVR_DEVICE(atmega324a)
AM_CONDITIONAL(HAS_atmega324a, test "x$HAS_atmega324a" = "xyes")

CHECK_AVR_DEVICE(atmega324p)
AM_CONDITIONAL(HAS_atmega324p, test "x$HAS_atmega324p" = "xyes")

CHECK_AVR_DEVICE(atmega324pa)
AM_CONDITIONAL(HAS_atmega324pa, test "x$HAS_atmega324pa" = "xyes")

CHECK_AVR_DEVICE(atmega325)
AM_CONDITIONAL(HAS_atmega325, test "x$HAS_atmega325" = "xyes")

CHECK_AVR_DEVICE(atmega325a)
AM_CONDITIONAL(HAS_atmega325a, test "x$HAS_atmega325a" = "xyes")

CHECK_AVR_DEVICE(atmega325p)
AM_CONDITIONAL(HAS_atmega325p, test "x$HAS_atmega325p" = "xyes")

CHECK_AVR_DEVICE(atmega325pa)
AM_CONDITIONAL(HAS_atmega325pa, test "x$HAS_atmega325pa" = "xyes")

CHECK_AVR_DEVICE(atmega3250)
AM_CONDITIONAL(HAS_atmega3250, test "x$HAS_atmega3250" = "xyes")

CHECK_AVR_DEVICE(atmega3250a)
AM_CONDITIONAL(HAS_atmega3250a, test "x$HAS_atmega3250a" = "xyes")

CHECK_AVR_DEVICE(atmega3250p)
AM_CONDITIONAL(HAS_atmega3250p, test "x$HAS_atmega3250p" = "xyes")

CHECK_AVR_DEVICE(atmega3250pa)
AM_CONDITIONAL(HAS_atmega3250pa, test "x$HAS_atmega3250pa" = "xyes")

CHECK_AVR_DEVICE(atmega328)
AM_CONDITIONAL(HAS_atmega328, test "x$HAS_atmega328" = "xyes")

CHECK_AVR_DEVICE(atmega328p)
AM_CONDITIONAL(HAS_atmega328p, test "x$HAS_atmega328p" = "xyes")

CHECK_AVR_DEVICE(atmega329)
AM_CONDITIONAL(HAS_atmega329, test "x$HAS_atmega329" = "xyes")

CHECK_AVR_DEVICE(atmega329a)
AM_CONDITIONAL(HAS_atmega329a, test "x$HAS_atmega329a" = "xyes")

CHECK_AVR_DEVICE(atmega329p)
AM_CONDITIONAL(HAS_atmega329p, test "x$HAS_atmega329p" = "xyes")

CHECK_AVR_DEVICE(atmega329pa)
AM_CONDITIONAL(HAS_atmega329pa, test "x$HAS_atmega329pa" = "xyes")

CHECK_AVR_DEVICE(atmega3290)
AM_CONDITIONAL(HAS_atmega3290, test "x$HAS_atmega3290" = "xyes")

CHECK_AVR_DEVICE(atmega3290a)
AM_CONDITIONAL(HAS_atmega3290a, test "x$HAS_atmega3290a" = "xyes")

CHECK_AVR_DEVICE(atmega3290p)
AM_CONDITIONAL(HAS_atmega3290p, test "x$HAS_atmega3290p" = "xyes")

CHECK_AVR_DEVICE(atmega3290pa)
AM_CONDITIONAL(HAS_atmega3290pa, test "x$HAS_atmega3290pa" = "xyes")

CHECK_AVR_DEVICE(atmega32c1)
AM_CONDITIONAL(HAS_atmega32c1, test "x$HAS_atmega32c1" = "xyes")

CHECK_AVR_DEVICE(atmega32hvb)
AM_CONDITIONAL(HAS_atmega32hvb, test "x$HAS_atmega32hvb" = "xyes")

CHECK_AVR_DEVICE(atmega32hvbrevb)
AM_CONDITIONAL(HAS_atmega32hvbrevb, test "x$HAS_atmega32hvbrevb" = "xyes")

CHECK_AVR_DEVICE(atmega32m1)
AM_CONDITIONAL(HAS_atmega32m1, test "x$HAS_atmega32m1" = "xyes")

CHECK_AVR_DEVICE(atmega32u4)
AM_CONDITIONAL(HAS_atmega32u4, test "x$HAS_atmega32u4" = "xyes")

CHECK_AVR_DEVICE(atmega32u6)
AM_CONDITIONAL(HAS_atmega32u6, test "x$HAS_atmega32u6" = "xyes")

CHECK_AVR_DEVICE(atmega406)
AM_CONDITIONAL(HAS_atmega406, test "x$HAS_atmega406" = "xyes")

CHECK_AVR_DEVICE(atmega644rfr2)
AM_CONDITIONAL(HAS_atmega644rfr2, test "x$HAS_atmega644rfr2" = "xyes")

CHECK_AVR_DEVICE(atmega64rfr2)
AM_CONDITIONAL(HAS_atmega64rfr2, test "x$HAS_atmega64rfr2" = "xyes")

CHECK_AVR_DEVICE(atmega64)
AM_CONDITIONAL(HAS_atmega64, test "x$HAS_atmega64" = "xyes")

CHECK_AVR_DEVICE(atmega64a)
AM_CONDITIONAL(HAS_atmega64a, test "x$HAS_atmega64a" = "xyes")

CHECK_AVR_DEVICE(atmega640)
AM_CONDITIONAL(HAS_atmega640, test "x$HAS_atmega640" = "xyes")

CHECK_AVR_DEVICE(atmega644)
AM_CONDITIONAL(HAS_atmega644, test "x$HAS_atmega644" = "xyes")

CHECK_AVR_DEVICE(atmega644a)
AM_CONDITIONAL(HAS_atmega644a, test "x$HAS_atmega644a" = "xyes")

CHECK_AVR_DEVICE(atmega644p)
AM_CONDITIONAL(HAS_atmega644p, test "x$HAS_atmega644p" = "xyes")

CHECK_AVR_DEVICE(atmega644pa)
AM_CONDITIONAL(HAS_atmega644pa, test "x$HAS_atmega644pa" = "xyes")

CHECK_AVR_DEVICE(atmega645)
AM_CONDITIONAL(HAS_atmega645, test "x$HAS_atmega645" = "xyes")

CHECK_AVR_DEVICE(atmega645a)
AM_CONDITIONAL(HAS_atmega645a, test "x$HAS_atmega645a" = "xyes")

CHECK_AVR_DEVICE(atmega645p)
AM_CONDITIONAL(HAS_atmega645p, test "x$HAS_atmega645p" = "xyes")

CHECK_AVR_DEVICE(atmega6450)
AM_CONDITIONAL(HAS_atmega6450, test "x$HAS_atmega6450" = "xyes")

CHECK_AVR_DEVICE(atmega6450a)
AM_CONDITIONAL(HAS_atmega6450a, test "x$HAS_atmega6450a" = "xyes")

CHECK_AVR_DEVICE(atmega6450p)
AM_CONDITIONAL(HAS_atmega6450p, test "x$HAS_atmega6450p" = "xyes")

CHECK_AVR_DEVICE(atmega649)
AM_CONDITIONAL(HAS_atmega649, test "x$HAS_atmega649" = "xyes")

CHECK_AVR_DEVICE(atmega649a)
AM_CONDITIONAL(HAS_atmega649a, test "x$HAS_atmega649a" = "xyes")

CHECK_AVR_DEVICE(atmega649p)
AM_CONDITIONAL(HAS_atmega649p, test "x$HAS_atmega649p" = "xyes")

CHECK_AVR_DEVICE(atmega6490)
AM_CONDITIONAL(HAS_atmega6490, test "x$HAS_atmega6490" = "xyes")

CHECK_AVR_DEVICE(atmega6490a)
AM_CONDITIONAL(HAS_atmega6490a, test "x$HAS_atmega6490a" = "xyes")

CHECK_AVR_DEVICE(atmega6490p)
AM_CONDITIONAL(HAS_atmega6490p, test "x$HAS_atmega6490p" = "xyes")

CHECK_AVR_DEVICE(atmega64c1)
AM_CONDITIONAL(HAS_atmega64c1, test "x$HAS_atmega64c1" = "xyes")

CHECK_AVR_DEVICE(atmega64hve)
AM_CONDITIONAL(HAS_atmega64hve, test "x$HAS_atmega64hve" = "xyes")

CHECK_AVR_DEVICE(atmega64m1)
AM_CONDITIONAL(HAS_atmega64m1, test "x$HAS_atmega64m1" = "xyes")

CHECK_AVR_DEVICE(atmega128rfa1)
AM_CONDITIONAL(HAS_atmega128rfa1, test "x$HAS_atmega128rfa1" = "xyes")

CHECK_AVR_DEVICE(m3000)
AM_CONDITIONAL(HAS_m3000, test "x$HAS_m3000" = "xyes")



#avr51
CHECK_AVR_DEVICE(avr51)
AM_CONDITIONAL(HAS_avr51, test "x$HAS_avr51" = "xyes")

AM_CONDITIONAL(HAS_atmega128, true)

CHECK_AVR_DEVICE(atmega128a)
AM_CONDITIONAL(HAS_atmega128a, test "x$HAS_atmega128a" = "xyes")

CHECK_AVR_DEVICE(atmega1280)
AM_CONDITIONAL(HAS_atmega1280, test "x$HAS_atmega1280" = "xyes")

CHECK_AVR_DEVICE(atmega1281)
AM_CONDITIONAL(HAS_atmega1281, test "x$HAS_atmega1281" = "xyes")

CHECK_AVR_DEVICE(atmega1284)
AM_CONDITIONAL(HAS_atmega1284, test "x$HAS_atmega1284" = "xyes")

CHECK_AVR_DEVICE(atmega1284p)
AM_CONDITIONAL(HAS_atmega1284p, test "x$HAS_atmega1284p" = "xyes")

CHECK_AVR_DEVICE(at90can128)
AM_CONDITIONAL(HAS_at90can128, test "x$HAS_at90can128" = "xyes")

CHECK_AVR_DEVICE(at90usb1286)
AM_CONDITIONAL(HAS_at90usb1286, test "x$HAS_at90usb1286" = "xyes")

CHECK_AVR_DEVICE(at90usb1287)
AM_CONDITIONAL(HAS_at90usb1287, test "x$HAS_at90usb1287" = "xyes")

CHECK_AVR_DEVICE(atmega1284rfr2)
AM_CONDITIONAL(HAS_atmega1284rfr2, test "x$HAS_atmega1284rfr2" = "xyes")

CHECK_AVR_DEVICE(atmega128rfr2)
AM_CONDITIONAL(HAS_atmega128rfr2, test "x$HAS_atmega128rfr2" = "xyes")


# avr6
CHECK_AVR_DEVICE(avr6)
AM_CONDITIONAL(HAS_avr6, test "x$HAS_avr6" = "xyes")

CHECK_AVR_DEVICE(atmega2560)
AM_CONDITIONAL(HAS_atmega2560, test "x$HAS_atmega2560" = "xyes")

CHECK_AVR_DEVICE(atmega2561)
AM_CONDITIONAL(HAS_atmega2561, test "x$HAS_atmega2561" = "xyes")

CHECK_AVR_DEVICE(atmega2564rfr2)
AM_CONDITIONAL(HAS_atmega2564rfr2, test "x$HAS_atmega2564rfr2" = "xyes")

CHECK_AVR_DEVICE(atmega256rfr2)
AM_CONDITIONAL(HAS_atmega256rfr2, test "x$HAS_atmega256rfr2" = "xyes")


# avrxmega2
CHECK_AVR_DEVICE(avrxmega2)
AM_CONDITIONAL(HAS_avrxmega2, test "x$HAS_avrxmega2" = "xyes")

CHECK_AVR_DEVICE(atxmega16a4)
AM_CONDITIONAL(HAS_atxmega16a4, test "x$HAS_atxmega16a4" = "xyes")

CHECK_AVR_DEVICE(atxmega16a4u)
AM_CONDITIONAL(HAS_atxmega16a4u, test "x$HAS_atxmega16a4u" = "xyes")

CHECK_AVR_DEVICE(atxmega16c4)
AM_CONDITIONAL(HAS_atxmega16c4, test "x$HAS_atxmega16c4" = "xyes")

CHECK_AVR_DEVICE(atxmega16d4)
AM_CONDITIONAL(HAS_atxmega16d4, test "x$HAS_atxmega16d4" = "xyes")

CHECK_AVR_DEVICE(atxmega32a4)
AM_CONDITIONAL(HAS_atxmega32a4, test "x$HAS_atxmega32a4" = "xyes")

CHECK_AVR_DEVICE(atxmega32a4u)
AM_CONDITIONAL(HAS_atxmega32a4u, test "x$HAS_atxmega32a4u" = "xyes")

CHECK_AVR_DEVICE(atxmega32c4)
AM_CONDITIONAL(HAS_atxmega32c4, test "x$HAS_atxmega32c4" = "xyes")

CHECK_AVR_DEVICE(atxmega32d4)
AM_CONDITIONAL(HAS_atxmega32d4, test "x$HAS_atxmega32d4" = "xyes")


# avrxmega4
CHECK_AVR_DEVICE(avrxmega4)
AM_CONDITIONAL(HAS_avrxmega4, test "x$HAS_avrxmega4" = "xyes")

CHECK_AVR_DEVICE(atxmega64a3)
AM_CONDITIONAL(HAS_atxmega64a3, test "x$HAS_atxmega64a3" = "xyes")

CHECK_AVR_DEVICE(atxmega64a3u)
AM_CONDITIONAL(HAS_atxmega64a3u, test "x$HAS_atxmega64a3u" = "xyes")

CHECK_AVR_DEVICE(atxmega64a4u)
AM_CONDITIONAL(HAS_atxmega64a4u, test "x$HAS_atxmega64a4u" = "xyes")

CHECK_AVR_DEVICE(atxmega64b1)
AM_CONDITIONAL(HAS_atxmega64b1, test "x$HAS_atxmega64b1" = "xyes")

CHECK_AVR_DEVICE(atxmega64b3)
AM_CONDITIONAL(HAS_atxmega64b3, test "x$HAS_atxmega64b3" = "xyes")

CHECK_AVR_DEVICE(atxmega64c3)
AM_CONDITIONAL(HAS_atxmega64c3, test "x$HAS_atxmega64c3" = "xyes")

CHECK_AVR_DEVICE(atxmega64d3)
AM_CONDITIONAL(HAS_atxmega64d3, test "x$HAS_atxmega64d3" = "xyes")

CHECK_AVR_DEVICE(atxmega64d4)
AM_CONDITIONAL(HAS_atxmega64d4, test "x$HAS_atxmega64d4" = "xyes")


# avrxmega5
CHECK_AVR_DEVICE(avrxmega5)
AM_CONDITIONAL(HAS_avrxmega5, test "x$HAS_avrxmega5" = "xyes")

CHECK_AVR_DEVICE(atxmega64a1)
AM_CONDITIONAL(HAS_atxmega64a1, test "x$HAS_atxmega64a1" = "xyes")

CHECK_AVR_DEVICE(atxmega64a1u)
AM_CONDITIONAL(HAS_atxmega64a1u, test "x$HAS_atxmega64a1u" = "xyes")


# avrxmega6
CHECK_AVR_DEVICE(avrxmega6)
AM_CONDITIONAL(HAS_avrxmega6, test "x$HAS_avrxmega6" = "xyes")

CHECK_AVR_DEVICE(atxmega128a3)
AM_CONDITIONAL(HAS_atxmega128a3, test "x$HAS_atxmega128a3" = "xyes")

CHECK_AVR_DEVICE(atxmega128a3u)
AM_CONDITIONAL(HAS_atxmega128a3u, test "x$HAS_atxmega128a3u" = "xyes")

CHECK_AVR_DEVICE(atxmega128b1)
AM_CONDITIONAL(HAS_atxmega128b1, test "x$HAS_atxmega128b1" = "xyes")

CHECK_AVR_DEVICE(atxmega128b3)
AM_CONDITIONAL(HAS_atxmega128b3, test "x$HAS_atxmega128b3" = "xyes")

CHECK_AVR_DEVICE(atxmega128c3)
AM_CONDITIONAL(HAS_atxmega128c3, test "x$HAS_atxmega128c3" = "xyes")

CHECK_AVR_DEVICE(atxmega128d3)
AM_CONDITIONAL(HAS_atxmega128d3, test "x$HAS_atxmega128d3" = "xyes")

CHECK_AVR_DEVICE(atxmega128d4)
AM_CONDITIONAL(HAS_atxmega128d4, test "x$HAS_atxmega128d4" = "xyes")

CHECK_AVR_DEVICE(atxmega192a3)
AM_CONDITIONAL(HAS_atxmega192a3, test "x$HAS_atxmega192a3" = "xyes")

CHECK_AVR_DEVICE(atxmega192a3u)
AM_CONDITIONAL(HAS_atxmega192a3u, test "x$HAS_atxmega192a3u" = "xyes")

CHECK_AVR_DEVICE(atxmega192c3)
AM_CONDITIONAL(HAS_atxmega192c3, test "x$HAS_atxmega192c3" = "xyes")

CHECK_AVR_DEVICE(atxmega192d3)
AM_CONDITIONAL(HAS_atxmega192d3, test "x$HAS_atxmega192d3" = "xyes")

CHECK_AVR_DEVICE(atxmega256a3)
AM_CONDITIONAL(HAS_atxmega256a3, test "x$HAS_atxmega256a3" = "xyes")

CHECK_AVR_DEVICE(atxmega256a3u)
AM_CONDITIONAL(HAS_atxmega256a3u, test "x$HAS_atxmega256a3u" = "xyes")

CHECK_AVR_DEVICE(atxmega256a3b)
AM_CONDITIONAL(HAS_atxmega256a3b, test "x$HAS_atxmega256a3b" = "xyes")

CHECK_AVR_DEVICE(atxmega256a3bu)
AM_CONDITIONAL(HAS_atxmega256a3bu, test "x$HAS_atxmega256a3bu" = "xyes")

CHECK_AVR_DEVICE(atxmega256c3)
AM_CONDITIONAL(HAS_atxmega256c3, test "x$HAS_atxmega256c3" = "xyes")

CHECK_AVR_DEVICE(atxmega256d3)
AM_CONDITIONAL(HAS_atxmega256d3, test "x$HAS_atxmega256d3" = "xyes")

CHECK_AVR_DEVICE(atxmega384c3)
AM_CONDITIONAL(HAS_atxmega384c3, test "x$HAS_atxmega384c3" = "xyes")

CHECK_AVR_DEVICE(atxmega384d3)
AM_CONDITIONAL(HAS_atxmega384d3, test "x$HAS_atxmega384d3" = "xyes")

# avrxmega7
CHECK_AVR_DEVICE(avrxmega7)
AM_CONDITIONAL(HAS_avrxmega7, test "x$HAS_avrxmega7" = "xyes")

CHECK_AVR_DEVICE(atxmega128a1)
AM_CONDITIONAL(HAS_atxmega128a1, test "x$HAS_atxmega128a1" = "xyes")

CHECK_AVR_DEVICE(atxmega128a1u)
AM_CONDITIONAL(HAS_atxmega128a1u, test "x$HAS_atxmega128a1u" = "xyes")

CHECK_AVR_DEVICE(atxmega128a4u)
AM_CONDITIONAL(HAS_atxmega128a4u, test "x$HAS_atxmega128a4u" = "xyes")


# avrtiny
CHECK_AVR_DEVICE(avrtiny)
AM_CONDITIONAL(HAS_avrtiny, test "x$HAS_avrtiny" = "xyes")

CHECK_AVR_DEVICE(attiny4)
AM_CONDITIONAL(HAS_attiny4, test "x$HAS_attiny4" = "xyes")

CHECK_AVR_DEVICE(attiny5)
AM_CONDITIONAL(HAS_attiny5, test "x$HAS_attiny5" = "xyes")

CHECK_AVR_DEVICE(attiny9)
AM_CONDITIONAL(HAS_attiny9, test "x$HAS_attiny9" = "xyes")

CHECK_AVR_DEVICE(attiny10)
AM_CONDITIONAL(HAS_attiny10, test "x$HAS_attiny10" = "xyes")

CHECK_AVR_DEVICE(attiny20)
AM_CONDITIONAL(HAS_attiny20, test "x$HAS_attiny20" = "xyes")

CHECK_AVR_DEVICE(attiny40)
AM_CONDITIONAL(HAS_attiny40, test "x$HAS_attiny40" = "xyes")




# Generate all files from *.in sources.

AC_CONFIG_FILES([
	Makefile
	avr-libc.spec
	avr/Makefile
	avr/lib/Makefile
	common/Makefile
	crt1/Makefile
	crt1/iosym/Makefile
	doc/Makefile
	doc/api/Makefile
	doc/examples/Makefile
	include/Makefile
	include/avr/Makefile
	include/avr/builtins.h
	include/compat/Makefile
	include/util/Makefile
	include/util/delay.h
	include/sys/Makefile
	libc/Makefile
	libc/misc/Makefile
	libc/pmstring/Makefile
	libc/stdio/Makefile
	libc/stdlib/Makefile
	libc/string/Makefile
	libc/time/Makefile
	libm/Makefile
	libm/fplib/Makefile
	scripts/Makefile
	devtools/Makefile
])

#avr1 and avr2
AC_CONFIG_FILES([
	avr/lib/avr2/Makefile
	avr/lib/avr2/at90s1200/Makefile
	avr/lib/avr2/at90s4414/Makefile
	avr/lib/avr2/at90s4434/Makefile
	avr/lib/avr2/at90s8515/Makefile
	avr/lib/avr2/at90c8534/Makefile
	avr/lib/avr2/at90s8535/Makefile
	avr/lib/avr2/attiny11/Makefile
	avr/lib/avr2/attiny12/Makefile
	avr/lib/avr2/attiny15/Makefile
	avr/lib/avr2/attiny28/Makefile
])

#avr2/tiny-stack
AC_CONFIG_FILES([
	avr/lib/avr2/tiny-stack/Makefile
	avr/lib/avr2/tiny-stack/at90s2313/Makefile
	avr/lib/avr2/tiny-stack/at90s2323/Makefile
	avr/lib/avr2/tiny-stack/at90s2333/Makefile
	avr/lib/avr2/tiny-stack/at90s2343/Makefile
	avr/lib/avr2/tiny-stack/attiny22/Makefile
	avr/lib/avr2/tiny-stack/attiny26/Makefile
	avr/lib/avr2/tiny-stack/at90s4433/Makefile
])

#avr25
AC_CONFIG_FILES([
	avr/lib/avr25/Makefile
	avr/lib/avr25/at86rf401/Makefile
	avr/lib/avr25/ata5272/Makefile
	avr/lib/avr25/attiny4313/Makefile
	avr/lib/avr25/attiny43u/Makefile
	avr/lib/avr25/attiny44/Makefile
	avr/lib/avr25/attiny44a/Makefile
	avr/lib/avr25/attiny45/Makefile
	avr/lib/avr25/attiny461/Makefile
	avr/lib/avr25/attiny461a/Makefile
	avr/lib/avr25/attiny48/Makefile
	avr/lib/avr25/attiny828/Makefile
	avr/lib/avr25/attiny84/Makefile
	avr/lib/avr25/attiny84a/Makefile
	avr/lib/avr25/attiny85/Makefile
	avr/lib/avr25/attiny861/Makefile
	avr/lib/avr25/attiny861a/Makefile
	avr/lib/avr25/attiny87/Makefile
	avr/lib/avr25/attiny88/Makefile
])

#avr25/tiny-stack
AC_CONFIG_FILES([
	avr/lib/avr25/tiny-stack/Makefile
	avr/lib/avr25/tiny-stack/attiny13/Makefile
	avr/lib/avr25/tiny-stack/attiny13a/Makefile
	avr/lib/avr25/tiny-stack/attiny2313/Makefile
	avr/lib/avr25/tiny-stack/attiny2313a/Makefile
	avr/lib/avr25/tiny-stack/attiny24/Makefile
	avr/lib/avr25/tiny-stack/attiny24a/Makefile
	avr/lib/avr25/tiny-stack/attiny25/Makefile
	avr/lib/avr25/tiny-stack/attiny261/Makefile
	avr/lib/avr25/tiny-stack/attiny261a/Makefile
])

#avr3
AC_CONFIG_FILES([
	avr/lib/avr3/Makefile
	avr/lib/avr3/at43usb355/Makefile
	avr/lib/avr3/at76c711/Makefile
])

#avr31
AC_CONFIG_FILES([
	avr/lib/avr31/Makefile
	avr/lib/avr31/atmega103/Makefile
	avr/lib/avr31/at43usb320/Makefile
])

#avr35
AC_CONFIG_FILES([
	avr/lib/avr35/Makefile
	avr/lib/avr35/at90usb82/Makefile
	avr/lib/avr35/at90usb162/Makefile
	avr/lib/avr35/ata5505/Makefile
	avr/lib/avr35/atmega8u2/Makefile
	avr/lib/avr35/atmega16u2/Makefile
	avr/lib/avr35/atmega32u2/Makefile
	avr/lib/avr35/attiny167/Makefile
	avr/lib/avr35/attiny1634/Makefile
])

#avr4
AC_CONFIG_FILES([
	avr/lib/avr4/Makefile
	avr/lib/avr4/ata6285/Makefile
	avr/lib/avr4/ata6286/Makefile
	avr/lib/avr4/ata6289/Makefile
	avr/lib/avr4/atmega48/Makefile
	avr/lib/avr4/atmega48a/Makefile
	avr/lib/avr4/atmega48pa/Makefile
	avr/lib/avr4/atmega48p/Makefile
	avr/lib/avr4/atmega8/Makefile
	avr/lib/avr4/atmega8a/Makefile
	avr/lib/avr4/atmega88/Makefile
	avr/lib/avr4/atmega88a/Makefile
	avr/lib/avr4/atmega88p/Makefile
	avr/lib/avr4/atmega88pa/Makefile
	avr/lib/avr4/atmega8515/Makefile
	avr/lib/avr4/atmega8535/Makefile
	avr/lib/avr4/atmega8hva/Makefile
	avr/lib/avr4/at90pwm1/Makefile
	avr/lib/avr4/at90pwm2/Makefile
	avr/lib/avr4/at90pwm2b/Makefile
	avr/lib/avr4/at90pwm3/Makefile
	avr/lib/avr4/at90pwm3b/Makefile
	avr/lib/avr4/at90pwm81/Makefile
])

#avr5
AC_CONFIG_FILES([
	avr/lib/avr5/Makefile
	avr/lib/avr5/at90can32/Makefile
	avr/lib/avr5/at90can64/Makefile
	avr/lib/avr5/at90pwm216/Makefile
	avr/lib/avr5/at90pwm316/Makefile
	avr/lib/avr5/at90pwm161/Makefile
	avr/lib/avr5/at90scr100/Makefile
	avr/lib/avr5/at90usb646/Makefile
	avr/lib/avr5/at90usb647/Makefile
	avr/lib/avr5/at94k/Makefile 
	avr/lib/avr5/ata5790/Makefile 
	avr/lib/avr5/ata5795/Makefile 
	avr/lib/avr5/atmega16/Makefile
	avr/lib/avr5/atmega16a/Makefile
	avr/lib/avr5/atmega161/Makefile
	avr/lib/avr5/atmega162/Makefile
	avr/lib/avr5/atmega163/Makefile
	avr/lib/avr5/atmega164a/Makefile
	avr/lib/avr5/atmega164p/Makefile
	avr/lib/avr5/atmega164pa/Makefile
	avr/lib/avr5/atmega165/Makefile
	avr/lib/avr5/atmega165a/Makefile
	avr/lib/avr5/atmega165p/Makefile
	avr/lib/avr5/atmega165pa/Makefile
	avr/lib/avr5/atmega168/Makefile
	avr/lib/avr5/atmega168a/Makefile
	avr/lib/avr5/atmega168p/Makefile
	avr/lib/avr5/atmega168pa/Makefile
	avr/lib/avr5/atmega169/Makefile
	avr/lib/avr5/atmega169a/Makefile
	avr/lib/avr5/atmega169p/Makefile
	avr/lib/avr5/atmega169pa/Makefile
	avr/lib/avr5/atmega16hva/Makefile
	avr/lib/avr5/atmega16hva2/Makefile
	avr/lib/avr5/atmega16hvb/Makefile
	avr/lib/avr5/atmega16hvbrevb/Makefile
	avr/lib/avr5/atmega16m1/Makefile
	avr/lib/avr5/atmega16u4/Makefile
	avr/lib/avr5/atmega32/Makefile
	avr/lib/avr5/atmega32a/Makefile
	avr/lib/avr5/atmega323/Makefile
	avr/lib/avr5/atmega324a/Makefile
	avr/lib/avr5/atmega324p/Makefile
	avr/lib/avr5/atmega324pa/Makefile
	avr/lib/avr5/atmega325/Makefile
	avr/lib/avr5/atmega325a/Makefile
	avr/lib/avr5/atmega325p/Makefile
	avr/lib/avr5/atmega325pa/Makefile
	avr/lib/avr5/atmega3250/Makefile
	avr/lib/avr5/atmega3250a/Makefile
	avr/lib/avr5/atmega3250p/Makefile
	avr/lib/avr5/atmega3250pa/Makefile
	avr/lib/avr5/atmega328/Makefile
	avr/lib/avr5/atmega328p/Makefile
	avr/lib/avr5/atmega329/Makefile
	avr/lib/avr5/atmega329a/Makefile
	avr/lib/avr5/atmega329p/Makefile
	avr/lib/avr5/atmega329pa/Makefile
	avr/lib/avr5/atmega3290/Makefile
	avr/lib/avr5/atmega3290a/Makefile
	avr/lib/avr5/atmega3290p/Makefile
	avr/lib/avr5/atmega3290pa/Makefile
	avr/lib/avr5/atmega32c1/Makefile
	avr/lib/avr5/atmega32hvb/Makefile
	avr/lib/avr5/atmega32hvbrevb/Makefile
	avr/lib/avr5/atmega32m1/Makefile
	avr/lib/avr5/atmega32u4/Makefile
	avr/lib/avr5/atmega32u6/Makefile
	avr/lib/avr5/atmega406/Makefile
	avr/lib/avr5/atmega64rfr2/Makefile
	avr/lib/avr5/atmega644rfr2/Makefile
	avr/lib/avr5/atmega64/Makefile
	avr/lib/avr5/atmega64a/Makefile
	avr/lib/avr5/atmega640/Makefile
	avr/lib/avr5/atmega644/Makefile
	avr/lib/avr5/atmega644a/Makefile
	avr/lib/avr5/atmega644p/Makefile
	avr/lib/avr5/atmega644pa/Makefile
	avr/lib/avr5/atmega645/Makefile
	avr/lib/avr5/atmega645a/Makefile
	avr/lib/avr5/atmega645p/Makefile
	avr/lib/avr5/atmega6450/Makefile
	avr/lib/avr5/atmega6450a/Makefile
	avr/lib/avr5/atmega6450p/Makefile
	avr/lib/avr5/atmega649/Makefile
	avr/lib/avr5/atmega649a/Makefile
	avr/lib/avr5/atmega649p/Makefile
	avr/lib/avr5/atmega6490/Makefile
	avr/lib/avr5/atmega6490a/Makefile
	avr/lib/avr5/atmega6490p/Makefile
	avr/lib/avr5/atmega64c1/Makefile
	avr/lib/avr5/atmega64hve/Makefile
	avr/lib/avr5/atmega64m1/Makefile
	avr/lib/avr5/m3000/Makefile
])

#avr51
AC_CONFIG_FILES([
	avr/lib/avr51/Makefile
	avr/lib/avr51/atmega128/Makefile
	avr/lib/avr51/atmega128a/Makefile
	avr/lib/avr51/atmega1280/Makefile
	avr/lib/avr51/atmega1281/Makefile
	avr/lib/avr51/atmega1284/Makefile
	avr/lib/avr51/atmega1284p/Makefile
	avr/lib/avr51/atmega128rfa1/Makefile
	avr/lib/avr51/atmega128rfr2/Makefile
	avr/lib/avr51/atmega1284rfr2/Makefile
	avr/lib/avr51/at90can128/Makefile
	avr/lib/avr51/at90usb1286/Makefile
	avr/lib/avr51/at90usb1287/Makefile
])

#avr6
AC_CONFIG_FILES([
	avr/lib/avr6/Makefile
	avr/lib/avr6/atmega2560/Makefile
	avr/lib/avr6/atmega2561/Makefile
	avr/lib/avr6/atmega256rfr2/Makefile
	avr/lib/avr6/atmega2564rfr2/Makefile
])

# avrxmega2
AC_CONFIG_FILES([
	avr/lib/avrxmega2/Makefile
	avr/lib/avrxmega2/atxmega16a4/Makefile
	avr/lib/avrxmega2/atxmega16a4u/Makefile
	avr/lib/avrxmega2/atxmega16c4/Makefile
	avr/lib/avrxmega2/atxmega16d4/Makefile
	avr/lib/avrxmega2/atxmega32a4/Makefile
	avr/lib/avrxmega2/atxmega32a4u/Makefile
	avr/lib/avrxmega2/atxmega32c4/Makefile
	avr/lib/avrxmega2/atxmega32d4/Makefile
])

# avrxmega4
AC_CONFIG_FILES([
	avr/lib/avrxmega4/Makefile
	avr/lib/avrxmega4/atxmega64a3/Makefile
	avr/lib/avrxmega4/atxmega64a3u/Makefile
	avr/lib/avrxmega4/atxmega64a4u/Makefile
	avr/lib/avrxmega4/atxmega64b1/Makefile
	avr/lib/avrxmega4/atxmega64b3/Makefile
	avr/lib/avrxmega4/atxmega64c3/Makefile
	avr/lib/avrxmega4/atxmega64d3/Makefile
	avr/lib/avrxmega4/atxmega64d4/Makefile
])

# avrxmega5
AC_CONFIG_FILES([
	avr/lib/avrxmega5/Makefile
	avr/lib/avrxmega5/atxmega64a1/Makefile
	avr/lib/avrxmega5/atxmega64a1u/Makefile
])

# avrxmega6
AC_CONFIG_FILES([
	avr/lib/avrxmega6/Makefile
	avr/lib/avrxmega6/atxmega128a3/Makefile
	avr/lib/avrxmega6/atxmega128a3u/Makefile
	avr/lib/avrxmega6/atxmega128b1/Makefile
	avr/lib/avrxmega6/atxmega128b3/Makefile
	avr/lib/avrxmega6/atxmega128c3/Makefile
	avr/lib/avrxmega6/atxmega128d3/Makefile
	avr/lib/avrxmega6/atxmega128d4/Makefile
	avr/lib/avrxmega6/atxmega192a3/Makefile
	avr/lib/avrxmega6/atxmega192a3u/Makefile
	avr/lib/avrxmega6/atxmega192c3/Makefile
	avr/lib/avrxmega6/atxmega192d3/Makefile
	avr/lib/avrxmega6/atxmega256a3/Makefile
	avr/lib/avrxmega6/atxmega256a3u/Makefile
	avr/lib/avrxmega6/atxmega256a3b/Makefile
	avr/lib/avrxmega6/atxmega256a3bu/Makefile
	avr/lib/avrxmega6/atxmega256c3/Makefile
	avr/lib/avrxmega6/atxmega256d3/Makefile
	avr/lib/avrxmega6/atxmega384c3/Makefile
	avr/lib/avrxmega6/atxmega384d3/Makefile
])

# avrxmega7
AC_CONFIG_FILES([
	avr/lib/avrxmega7/Makefile
	avr/lib/avrxmega7/atxmega128a1/Makefile
	avr/lib/avrxmega7/atxmega128a1u/Makefile
	avr/lib/avrxmega7/atxmega128a4u/Makefile
])


# avrtiny
AC_CONFIG_FILES([
	avr/lib/avrtiny/Makefile
	avr/lib/avrtiny/attiny4/Makefile
	avr/lib/avrtiny/attiny5/Makefile
	avr/lib/avrtiny/attiny9/Makefile
	avr/lib/avrtiny/attiny10/Makefile
	avr/lib/avrtiny/attiny20/Makefile
	avr/lib/avrtiny/attiny40/Makefile
])


AC_OUTPUT
