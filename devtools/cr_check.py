#! /usr/bin/env python
#
# Copyright (c) 2004  Theodore A. Roth
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
#
# * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in
#   the documentation and/or other materials provided with the
#   distribution.
#
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

#
# Use this script from the toplevel of the avr-libc tree to find files with
# bogus carriage returns.
#

import os.path, fnmatch

def listFiles (root='.', match=['*'], ignore=[], recurse=1, return_folders=0):
    class Bunch:
        def __init__ (self, **kw):
            self.__dict__.update (kw)

    arg = Bunch (recurse=recurse, match_list=match, ignore_list=ignore,
                 return_folders=return_folders, results=[])

    def visit (arg, dirname, files):
        # Append to arg.results all relevant files (and perhaps folders)
        for name in files:
            fullname = os.path.normpath (os.path.join (dirname, name))
            if arg.return_folders or os.path.isfile (fullname):
                for match in arg.match_list:
                    if fnmatch.fnmatch (name, match):
                        add = 1
                        for ignore in arg.ignore_list:
                            if fnmatch.fnmatch (name, ignore):
                                add = 0
                        if add:
                            arg.results.append (fullname)
                            break
        # Block recursion if recursion was disallowed
        if not arg.recurse:
            files[:]=[]

    os.path.walk (root, visit, arg)

    return arg.results

def cr_check (file):
    ln = 1
    f = open (file).readlines ()

    for l in f:
        if '\r' in l:
            print '%s:%d: Found CR.' % (file, ln)
        ln += 1

def check_cvs_dir (entry):
    f = open (entry).readlines ()

    base_dir = os.path.dirname (os.path.dirname (entry))

    for l in f:
        if l[0] == 'D':
            continue
        else:
            file = l.split ('/')[1]
            if base_dir:
                file = base_dir+'/'+file

            cr_check (file)

if __name__ == '__main__':
    for file in listFiles (match=['*Entries*']):
        check_cvs_dir (file)
