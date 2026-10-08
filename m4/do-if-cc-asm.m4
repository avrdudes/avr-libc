# Copyright (c) 2026  Georg-Johann Lay
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
dnl Compile C source $2 with extra options $3.
dnl When pattern $4 is found in the generated asm then run $5, else run $6.
AC_DEFUN([DO_IF_CC_ASM],[dnl
  AC_MSG_CHECKING([$1])
  rm -f conftest.c conftest.s
  cat > conftest.c <<EOF
$2
EOF
  AC_TRY_COMMAND([$CC conftest.c $3 -S -o conftest.s])
  AS_IF([$GREP $4 conftest.s > /dev/null], [has_pat=yes], [has_pat=no])
  AC_MSG_RESULT([$has_pat])
  AS_IF([test "x$has_pat" = "xyes"], [$5], [$6])
  rm -f conftest.c conftest.s
])
dnl Local Variables:
dnl mode: autoconf
dnl End:
