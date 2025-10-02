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

AC_DEFUN([CHECK_FIXED_POINT],[dnl
    AC_MSG_CHECKING([whether ${CC} supports fixed-point])
    AC_COMPILE_IFELSE(
	[ AC_LANG_SOURCE([[
		_Fract x1;
		_Accum x2;
		#include <stdfix.h>
		fract x3;
		accum x4;
		]],[])],
	[HAS_FIXED_POINT_yesno=yes],
	[HAS_FIXED_POINT_yesno=no])
    AC_MSG_RESULT([$HAS_FIXED_POINT_yesno])
    dnl
    AS_IF([test $HAS_FIXED_POINT_yesno = yes],[
	AC_MSG_CHECKING([whether $CC fixed-point is GNU compatible])
	AC_COMPILE_IFELSE(
	    [ AC_LANG_SOURCE([[
		  #if __ACCUM_FBIT__ != 15
		  int a[-1];
		  #endif
		  ]],[])],
	    [HAS_FIXED_POINT_yesno=yes],
	    [HAS_FIXED_POINT_yesno=non-GNU])
	AC_MSG_RESULT([$HAS_FIXED_POINT_yesno])],)
    dnl
    AM_CONDITIONAL(BUILD_FXLIB, [test $HAS_FIXED_POINT_yesno = yes])
    dnl
    old_check_fixed_point_CFLAGS=${CFLAGS}
    CFLAGS="-I${srcdir}/include"
    AS_IF([test $HAS_FIXED_POINT_yesno = yes],[
	AC_MSG_CHECKING([whether <stdfix.h> includes <stdfix-avrlibc.h>])
	AC_COMPILE_IFELSE(
	    [ AC_LANG_SOURCE([[
		  #define __CONFIGURING_AVR_LIBC__
		  #include <stdfix.h>
		  #ifndef _STDFIX_AVRLIBC_H
		  int a[-1];
		  #endif
		  ]],[])],
	    [ AC_MSG_RESULT([yes]) ],
	    [ AC_MSG_RESULT([no])
	      STDFIX_AVRLIBC_H_NOT_INCLUDED=STDFIX_AVRLIBC_H_NOT_INCLUDED
	      AC_MSG_WARN([users must include <stdfix-avrlibc.h> by])
	      AC_MSG_WARN([hand for full AVR-LibC fixed-point support])]
	)
    ])
    AC_SUBST([STDFIX_AVRLIBC_H_NOT_INCLUDED])
    AC_SUBST([HAS_FIXED_POINT_yesno])
    CFLAGS=${old_check_fixed_point_CFLAGS}
])
dnl Local Variables:
dnl mode: autoconf
dnl End:
