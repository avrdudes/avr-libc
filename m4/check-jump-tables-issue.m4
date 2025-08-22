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

dnl GCC PR63223: From avr-gcc v4.9.2 on, jump tables are accessed with
dnl ELPM so that moving .text around is not an issue anymore.
AC_DEFUN([CHECK_JUMP_TABLES_ISSUE],[dnl
    AC_MSG_CHECKING([whether ${CC} can use -Ttext with jump-tables])
    FNO_JUMP_TABLES=
    dnl The relevant code is in libgcc's __tablejump2__, which on ATmega128...
    rm -f conftest.elf
    mcu="-mmcu=avr51"
    opt="-xassembler - -xnone -o conftest.elf -nostdlib -nostartfiles"
    echo ".global __tablejump2__" \
	| $CC $mcu $opt $($CC $mcu -print-libgcc-file-name) 2> /dev/null
    dnl ...should use ELPM to read from the jump table.
    AS_IF([$OBJDUMP -d conftest.elf 2> /dev/null | grep -i elpm > /dev/null],
	[ AC_MSG_RESULT([yes]) ],
	[ AC_MSG_RESULT([no])
	  dnl Only work out how to turn off jump-tables when actually needed.
	  opt=-mno-tablejump
	  AC_MSG_CHECKING([whether ${CC} supports $opt])
	  DO_IF_CC_OPTION([$opt],
	      [ AC_MSG_RESULT([yes])
		FNO_JUMP_TABLES=$opt ],
	      [ AC_MSG_RESULT([no]) ])
	  dnl
	  opt=-fno-jump-tables
	  AC_MSG_CHECKING([whether ${CC} supports $opt])
	  DO_IF_CC_OPTION([$opt],
	      [ AC_MSG_RESULT([yes])
		FNO_JUMP_TABLES=$opt ],
	      [ AC_MSG_RESULT([no]) ])
	  AS_IF([test "x$FNO_JUMP_TABLES" != "x"],
	      [AC_MSG_NOTICE([Using $FNO_JUMP_TABLES to turn off jump-tables])],
	      [AC_MSG_NOTICE([Found no option to turn off jump-tables])])
	]
    )
    rm -f conftest.elf
    AC_SUBST(FNO_JUMP_TABLES)
])
dnl Local Variables:
dnl mode: autoconf
dnl End:
