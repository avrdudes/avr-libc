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

dnl Check whether options like -mdouble=64 act as a multilib selector,
dnl i.e. $CC will mention it like @mdouble64 with $CC -print-multi-lib.
dnl If so, set DIR_$2=$3 and DIR_$2=<empty>, otherwise.  $3 is the
dnl multi-subdirectory associated to option $1.  In addition, set automake
dnl variable HAS_MULTIOPT_$2 to 0 or 1 depending on the result.
dnl The only consumer of this test is Device.am which mlib-gen.py uses to
dnl produce ./avr/devices/<device>/Makefile.am.
AC_DEFUN([CHECK_MULTI_OPTION],[dnl
    AC_MSG_CHECKING([if ${CC} supports multilib option $1])

    pml=`${CC} -print-multi-lib | sed 's/@/ -/g'`
    opt=`echo "$1" | sed 's/-/\\\\-/g'`
    if echo "$pml" | grep -e "$opt" > /dev/null 2>&1; then
       AC_MSG_RESULT([yes, in $3])
       DIR_$2=$3
       AS_IF([test "x$DOX_MULTI_OPT" = "x"],
         [DOX_MULTI_OPT=yes],)
       DOX_MULTI_OPT="${DOX_MULTI_OPT}, @c @$1"
    else
       AC_MSG_RESULT(no)
       DIR_$2=
    fi
    AC_SUBST(DIR_$2)
    AM_CONDITIONAL(HAS_MULTIOPT_$2, [test "x${DIR_$2}" != "x"])
])
dnl Local Variables:
dnl mode: autoconf
dnl End:
