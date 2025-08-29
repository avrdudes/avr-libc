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

AC_DEFUN([CHECK_MULTI_VARIANT],[dnl
    AC_MSG_CHECKING([if ${CC} supports multilib $1])
    mdir=`echo "$1" | $SED -e 's/\\./\\\\./g'`
    pml=`${CC} -print-multi-lib | $GREP -e "^${mdir};"`
    if test "x$pml" != "x"; then
       MULTIDIR_$2=$1
       MULTIOPT_$2=`echo "${pml}" | cut -d ';' -f 2 | $SED 's/@/ -/g'`
       AC_MSG_RESULT([yes, with options:${MULTIOPT_$2}])
    else
       MULTIDIR_$2=
       MULTIOPT_$2=
       AC_MSG_RESULT(no)
    fi
    AC_SUBST(MULTIDIR_$2)
    AC_SUBST(MULTIOPT_$2)
    AM_CONDITIONAL(HAS_MULTI_$2, [test "x${MULTIDIR_$2}" != "x"])
])
dnl Local Variables:
dnl mode: autoconf
dnl End:
