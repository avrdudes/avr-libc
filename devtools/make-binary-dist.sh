#! /bin/sh
#
# Copyright (c) 2005,  Joerg Wunsch
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
#
# $Id$
#
# Build a binary distribution archive.
#
# Assumes a bootstrapped source tree to be present in ${topdir}.

#set -x

# Optional argument to script $1: top-level source directory to
# compile from.
builddir=$(pwd)
topdir=${1:-.}
topdir=$( (cd $topdir && pwd) )

# If ${MAKE} is not set, and a gmake program is available, use gmake
# (GNU make).  Otherwise, use make.
if [ "x" = "x${MAKE}" ] ; then
    if type gmake >/dev/null 2>&1 ; then
	MAKE=gmake
    else
	MAKE=make
    fi
fi

# 'out/' is where we are going to temporarily install our stuff
# into.
mkdir ${builddir}/out || {\
    echo "cannot create 'out/' directory"; \
    exit 1;\
}

${topdir}/configure \
    --disable-doc \
    --prefix=${builddir}/out \
    --build=$(${topdir}/config.guess) \
    --host=avr || {\
    echo "configure failed"; \
    exit 1; \
}

# Examine our version ID, and record it (for the final archive name).
set -- $(grep '^#define VERSION' ${builddir}/config.h | tr -d '"') || {\
    echo "Cannot find VERSION in config.h"; \
    exit 1; \
}
version=$3

# Now, build and install everything.
${MAKE} -C ${builddir} all install || {\
    echo "make failed"; \
    exit 1; \
}

cd ${builddir}/out || {\
    echo "Cannot chdir to 'out/'."; \
    exit 1; \
}

# Remove all debugging symbols so debuggers don't get confused about
# the different location of source files.
find . -name '*.[ao]' | xargs avr-strip -g

# Package things up.
zip -r ${builddir}/avr-libc-bin-${version}.zip * || {\
    echo "archive creation failed"; \
    exit 1; \
}

cd ${builddir} || {\
    echo "Huh, cannot chdir back to ${builddir}?!"; \
    exit 1; \
}

rm -rf ${builddir}/out || {\
    echo "Cannot cleanup 'out/' directory"; \
    exit 1; \
}

${MAKE} clean

echo "All done.  Check out ${topdir}/avr-libc-bin-${version}.zip"
