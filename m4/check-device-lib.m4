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

dnl Enable device library when specified. If not specified and
dnl gcc expects (e.g. >= 5) device lib then enable device library.

AC_DEFUN([CHECK_DEVICE_LIB],[dnl

AC_MSG_CHECKING([whether to build the libmcu.a device libraries])

dnl Check if avr-gcc >= 5.1.0 as they expect device library.
GCC_VER=`${CC} -dumpversion`
AS_VERSION_COMPARE([${GCC_VER}], [5.1.0],
    [HAS_DEV_LIB_yesno=no],
    [HAS_DEV_LIB_yesno=yes],
    [HAS_DEV_LIB_yesno=yes])
AM_CONDITIONAL(HAS_GCC_5_1, [test "x${GCC_VER}" = "x5.1.0"])

AC_ARG_ENABLE(device-lib,
    [  --enable-device-lib     build separate device library],
    [HAS_DEV_LIB_yesno=yes],)

AC_MSG_RESULT([$HAS_DEV_LIB_yesno])

dnl define HAS_DEV_LIB if device library enabled
AM_CONDITIONAL(HAS_DEV_LIB, [test x$HAS_DEV_LIB_yesno = xyes])
AC_SUBST(HAS_DEV_LIB_yesno)
])
dnl Local Variables:
dnl mode: autoconf
dnl End:
