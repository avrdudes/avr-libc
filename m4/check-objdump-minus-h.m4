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

dnl $1 = MSG_CHECKING
dnl Assemble and link assembly source $2 with extra $AS options $3
dnl and extra $LD options $4.  When pattern $5 is found in `objdump -h`,
dnl then run $6, else run $7.
AC_DEFUN([CHECK_OBJDUMP_MINUS_H],[dnl
  AC_MSG_CHECKING([$1])
  rm -f conftest.s conftest.o conftest.elf conftest.lst
  cat > conftest.s <<EOF
$2
EOF
  AC_TRY_COMMAND([$AS conftest.s $3 -o conftest.o])
  AC_TRY_COMMAND([$LD conftest.o $4 -o conftest.elf])
  AC_TRY_COMMAND([$OBJDUMP -h conftest.elf > conftest.lst])
  AS_IF([$GREP $5 conftest.lst > /dev/null], [has_pat=yes], [has_pat=no])
  AC_MSG_RESULT([$has_pat])
  AS_IF([test "x$has_pat" = "xyes"], [$6], [$7])
  rm -f conftest.s conftest.o conftest.elf conftest.lst
])
dnl Local Variables:
dnl mode: autoconf
dnl End:
