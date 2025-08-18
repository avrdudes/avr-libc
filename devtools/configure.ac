AC_INIT(find-python, [0.1], avr-libc-dev@nongnu.org)

AC_CONFIG_SRCDIR([gen-avr-lib-tree.sh.in])

dnl When this file is changed, run autoconf and perhaps aclocal,
dnl and add the updated configure and aclocal.m4 scripts to the repo.

dnl Find Python so gen-avr-lib-tree.sh can execute mlib-gen.py.
dnl This makes us independent on shebang.
AM_PATH_PYTHON([2.6], [AC_MSG_NOTICE([using $PYTHON to run mlib-gen.py and update-news])])

AC_CONFIG_FILES([gen-avr-lib-tree.sh], [chmod +x gen-avr-lib-tree.sh])
AC_CONFIG_FILES([update-news], [chmod +x update-news])
AC_CONFIG_FILES([filter-mcus.py], [chmod +x filter-mcus.py])

AC_OUTPUT
