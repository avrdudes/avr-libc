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

dnl Set FNO_JUMP_TABLES=-mno-tablejump when CC supports it.
dnl This macro is only used as needed by CHECK_JUMP_TABLES_ISSUE below.
AC_DEFUN([CHECK_MNO_TABLEJUMP],[dnl
    old_CC=${CC}
    old_CFLAGS=${CFLAGS}
    CFLAGS="-mno-tablejump"
    CC=`echo "${CC}" | sed 's/-mmcu=avr.//'`
    AC_MSG_CHECKING([whether ${CC} supports -mno-tablejump])
    AC_COMPILE_IFELSE([AC_LANG_SOURCE([],[])],
        [has_mno_tablejump=yes],
        [has_mno_tablejump=no])
    AS_IF([test "x$has_mno_tablejump" = "xyes"],
        [FNO_JUMP_TABLES=-mno-tablejump], [])
    AC_MSG_RESULT([$has_mno_tablejump])
    CC=${old_CC}
    CFLAGS=${old_CFLAGS}
])

dnl Set FNO_JUMP_TABLES=-fno-jump-tables when CC supports it.
dnl This macro is only used as needed by CHECK_JUMP_TABLES_ISSUE below.
AC_DEFUN([CHECK_FNO_JUMP_TABLES],[dnl
    old_CC=${CC}
    old_CFLAGS=${CFLAGS}
    CFLAGS="-fno-jump-tables"
    CC=`echo "${CC}" | sed 's/-mmcu=avr.//'`
    AC_MSG_CHECKING([whether ${CC} supports -fno-jump-tables])
    AC_COMPILE_IFELSE([AC_LANG_SOURCE([],[])],
        [has_fno_jump_tables=yes],
        [has_fno_jump_tables=no])
    AS_IF([test "x$has_fno_jump_tables" = "xyes"],
        [FNO_JUMP_TABLES=-fno-jump-tables], [])
    AC_MSG_RESULT([$has_fno_jump_tables])
    CC=${old_CC}
    CFLAGS=${old_CFLAGS}
])

dnl GCC PR63223: From avr-gcc v4.9.2 on, jump tables are accessed with
dnl ELPM so that moving .text around is not an issue anymore.
AC_DEFUN([CHECK_JUMP_TABLES_ISSUE],[dnl
    AC_MSG_CHECKING([whether ${CC} can use -Ttext with jump-tables])
    AS_VERSION_COMPARE([${GCC_VER}], [4.9.2],
        [no_jump_tables_issue=no],
        [no_jump_tables_issue=yes],
        [no_jump_tables_issue=yes])
    AC_MSG_RESULT([$no_jump_tables_issue])
    FNO_JUMP_TABLES=
    dnl Only work out how to turn off jump-tables when actually needed.
    AS_IF([test x$no_jump_tables_issue = xno], [
        CHECK_MNO_TABLEJUMP
        CHECK_FNO_JUMP_TABLES
        AS_IF([test "x$FNO_JUMP_TABLES" != "x"],
            [ AC_MSG_NOTICE([Using $FNO_JUMP_TABLES to turn off jump tables]) ],
            [ AC_MSG_NOTICE([Found no option to turn off jump tables]) ])
    ],[])
    AC_SUBST(FNO_JUMP_TABLES)
])
dnl Local Variables:
dnl mode: autoconf
dnl End:
