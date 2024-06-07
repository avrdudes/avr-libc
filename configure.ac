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
m4_define([avr_libc_major],    [2])dnl           major version
m4_define([avr_libc_minor],    [2])dnl           minor version
m4_define([avr_libc_revision], [0])dnl           revision (dot-dot version)
m4_define([avr_libc_revision_suffix], [git])dnl  revision suffix (if any)
m4_define([avr_libc_reldate],  [20220701])dnl    release date
dnl end of library versioning data

m4_define([avr_libc_version],
          avr_libc_major.avr_libc_minor.avr_libc_revision()avr_libc_revision_suffix)dnl
m4_define([avr_libc_version_numeric],
          m4_eval(10000 * avr_libc_major + dnl
                    100 * avr_libc_minor + dnl
                          avr_libc_revision))dnl

AC_INIT(avr-libc, avr_libc_version, https://github.com/avrdudes/avr-libc/issues)

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
	AC_MSG_WARN(AVR-LibC must be built using an avr cross-compiler.)
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

# We don't want to use the cflags from the environment since we need control
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


dnl Substitute $1 with the basenames of all files in glob $2.
dnl We use this to avoid $(echo $(basename -a $2)) which is not POSIX,
dnl hence we need a loop over all files in $2.
AC_DEFUN([SUBST_BASENAME_FILES],[dnl
fils=
for fil in $2; do
    fils="$fils $(basename $fil)"
done
AC_SUBST($1,[$fils])
])

dnl Build a list of all .h files in  $srcdir/include/avr.
dnl Used by include/avr/Makefile.am::avr_HEADERS.
SUBST_BASENAME_FILES(AVRLIBC_INCLUDE_HFILES, [$srcdir/include/avr/*.h])

dnl Build a list of all .S files in  $srcdir/crt1/iosym.
dnl Used by crt1/iosym/Makefile.am::EXTRA_DIST.
SUBST_BASENAME_FILES(AVRLIBC_IOSYM_SFILES, [$srcdir/crt1/iosym/*.S])


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
dnl dwarf-4 or [compiler's default version] dwarf.
AC_ARG_ENABLE(debug-info,
[  --enable-debug-info=stabs|dwarf-2|dwarf-4  Enable generation of debugging information],
[case "${enableval}" in
  yes|dwarf2|dwarf-2) debuginfo=dwarf2 ;;
  no)                 debuginfo="" ;;
  stabs)              debuginfo=stabs ;;
  dwarf4|dwarf-4)     debuginfo=dwarf4 ;;
  dwarf)              debuginfo=dwarf ;;
  *)                  AC_MSG_ERROR([bad value ${enableval} for --enable-debug-info option; should be either stabs, dwarf-2, or dwarf-4]) ;;
 esac], [debuginfo=""])

dnl Decide which debuginfo information to include
case "$debuginfo" in
"")      CDEBUG=""; ASDEBUG="" ;;
stabs)   CDEBUG="-gstabs"; ASDEBUG="-Wa,-gstabs" ;;
dwarf2)  CDEBUG="-gdwarf-2"; ASDEBUG="-Wa,-gdwarf-2" ;;
dwarf4)  CDEBUG="-gdwarf-4"; ASDEBUG="-Wa,-gdwarf-2" ;;
dwarf)   CDEBUG="-gdwarf"; ASDEBUG="-Wa,-gdwarf-2" ;;
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

asm_only="at90s1200 attiny11 attiny12 attiny15 attiny28"

dnl Some devices are only handled by newer version of gcc. This macro lets us
dnl probe whether the installed avr-gcc supports a device.
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
    for d in ${asm_only}; do
        if test "$1" = "$d"; then
            has_dev_support=yes
        fi
    done
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
    else
      MULTIDIR_$1=
      AC_MSG_RESULT(no)
    fi
    AC_SUBST(MULTIDIR_$1)
    CC=${old_CC}
    CFLAGS=${old_CFLAGS}
    AM_CONDITIONAL(HAS_$1, test "x${MULTIDIR_$1}" != "x")
  ]
)


dnl Check whether options like -mdouble=64 act as a multilib selector,
dnl i.e. $CC will mention it like @mdouble64 with $CC -print-multi-lib.
dnl If so, set DIR_$2=$3 and DIR_$2=<empty>, otherwise.  $3 is the
dnl multi-subdirectory associated to option $1.  In addition, set automake
dnl variable HAS_MULTIOPT_$2 to 0 or 1 depending on the result.
dnl The only consumer of this test is Device.am which mlib-gen.py uses to
dnl produce ./avr/devices/<device>/Makefile.am.
AC_DEFUN(
  CHECK_MULTI_OPTION,
  [
    old_CC=${CC}
    CC=`echo "${CC}" | sed 's/-mmcu=avr.//'`
    AC_MSG_CHECKING(whether ${CC} supports $1 as a multilib selector)

    pml=`${CC} -print-multi-lib | sed 's/@/ -/g'`
    opt=`echo "$1" | sed 's/-/\\\\-/g'`
    if echo "$pml" | grep -e "$opt" > /dev/null 2>&1; then
       AC_MSG_RESULT([yes, in $3])
       DIR_$2=$3
    else
       AC_MSG_RESULT(no)
       DIR_$2=
    fi
    CC=${old_CC}
    AC_SUBST(DIR_$2)
    AM_CONDITIONAL(HAS_MULTIOPT_$2, test "x${DIR_$2}" != "x")
  ]
)

dnl Check whether multilib variant $1 is supported by $CC where $1 is
dnl a multilib directory like "." or "avr25/tiny-stack" as printed by
dnl $CC -print-multi-lib.  $2 is to be used both as part of a variable
dnl name and as part of a subdirectory name in avr/lib.  The checks are
dnl issued by multilib.m4 which is generated by mlib-gen.py.
AC_DEFUN(
  CHECK_MULTI_VARIANT,
  [
    old_CC=${CC}
    CC=`echo "${CC}" | sed 's/-mmcu=avr.//'`
    AC_MSG_CHECKING(whether ${CC} supports $1 as a multilib path)
    mdir=`echo "$1" | sed -e 's/\\./\\\\./g'`
    pml=`${CC} -print-multi-lib | grep -e "^${mdir};"`
    if test "x$pml" != "x"; then
       MULTIDIR_$2=$1
       MULTIOPT_$2=`echo "${pml}" | cut -d ';' -f 2 | sed 's/@/ -/g'`
       AC_MSG_RESULT([yes, with options:${MULTIOPT_$2}])
    else
       MULTIDIR_$2=
       MULTIOPT_$2=
       AC_MSG_RESULT(no)
    fi
    CC=${old_CC}
    AC_SUBST(MULTIDIR_$2)
    AC_SUBST(MULTIOPT_$2)
    AM_CONDITIONAL(HAS_MULTI_$2, test "x${MULTIDIR_$2}" != "x")
  ]
)

# Used by Device.am i.e. avr/devices/<device>/Makefile.am.
CHECK_MULTI_OPTION([-mdouble=32], [double32], [double32])
CHECK_MULTI_OPTION([-mdouble=64], [double64], [double64])
CHECK_MULTI_OPTION([-mlong-double=32], [long_double32], [long-double32])
CHECK_MULTI_OPTION([-mlong-double=64], [long_double64], [long-double64])

# avr1
AM_CONDITIONAL(HAS_avr1, true)
DIR_avr1=avr1
AC_SUBST(DIR_avr1)

m4_include([devices.m4])

dnl The following include must preceed multilib.m4 and is only
dnl needed with avr-gcc v4.9 or older, namely if !HAS_DEV_LIB.
m4_include([devlist.m4])

m4_include([multilib.m4])

# Generate all files from *.in sources.

AC_CONFIG_FILES([
	Makefile
	avr-libc.spec
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

m4_include([files.m4])

AC_OUTPUT
