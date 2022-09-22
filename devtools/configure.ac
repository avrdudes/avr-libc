AC_INIT(find-python, [0.1], avr-libc-dev@nongnu.org)

AC_CONFIG_SRCDIR([gen-avr-lib-tree.sh.in])

dnl Find Python so gen-avr-lib-tree.sh can execute mlib-gen.py.
dnl This makes us independent on shebang.
AM_PATH_PYTHON([2.6], [AC_MSG_NOTICE([using $PYTHON to run mlib-gen.py])])

AC_CONFIG_FILES([gen-avr-lib-tree.sh], [chmod +x gen-avr-lib-tree.sh])

AC_OUTPUT
