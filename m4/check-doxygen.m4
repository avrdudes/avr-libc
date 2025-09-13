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

dnl troth/2002-07-12: The CHECK_DOXYGEN macro should be moved to a config
dnl dir. I put it here until I figure out how to integrate the config dir.

dnl
dnl @synopsis CHECK_DOXYGEN
dnl
dnl This macro checks if doxygen is installed on the build system.
dnl The doxygen command can be set with configure --with-doxygen=[doxygen].
dnl
dnl @version Id: check_doxygen.m4,v 1.2 2002/02/10 23:22:40 troth Exp
dnl @author Theodore A. Roth <troth@openavr.org>
dnl
AC_DEFUN([CHECK_DOXYGEN],[dnl
dnl
AC_MSG_CHECKING([for doxygen])

AC_ARG_WITH([doxygen],
  [AS_HELP_STRING([--with-doxygen=],[set Doxygen command (default: doxygen)])],
  [DOXYGEN=$withval],
  [DOXYGEN=doxygen])

dox_ver=`$DOXYGEN --version 2>/dev/null`
if test "x$dox_ver" = "x"; then
	AC_MSG_RESULT(no: $DOXYGEN not found)
else
	# FIXME: should also check for dox_ver >= 1.4.1
	AC_MSG_RESULT(yes: $DOXYGEN)
	SHOW_VERSION([$DOXYGEN], [Doxygen])
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
AC_SUBST(DOXYGEN)
AC_SUBST(TARGET_DOX_PDF)
AC_SUBST(TARGET_DOX_HTML)
AC_SUBST(INSTALL_DOX_PDF)
AC_SUBST(INSTALL_DOX_HTML)
AC_SUBST(INSTALL_DOX_MAN)
])dnl
dnl Local Variables:
dnl mode: autoconf
dnl End:
