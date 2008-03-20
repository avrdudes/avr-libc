#! /usr/bin/env python

# Copyright (c) 2008, Joerg Wunsch
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

# The ATmega128 simulations return an error code string in "external
# memory" at address 0x2000 upon failure.  If runtest.sh is run with
# option -s, it will abort the simulation, and leave the file
# core_avr_dump.core where this script can read the error code string
# from.  (The simulations on smaller AVRs don't generate this string
# in order to not bloat their code beyond the available ROM size by
# including sprintf().)

# If an argument is given to the script, it is used as the name of the
# simulavr core dump file to read.  Otherwise, the simulavr default
# name "core_avr_dump.core" is used.

# $Id$

# Enum implementation, from Python recipe:
# http://aspn.activestate.com/ASPN/Cookbook/Python/Recipe/413486
# Author: Zoran Isailovski
def Enum(*names):
   ##assert names, "Empty enums are not supported" # <- Don't like empty enums? Uncomment!

   class EnumClass(object):
      __slots__ = names
      def __iter__(self):        return iter(constants)
      def __len__(self):         return len(constants)
      def __getitem__(self, i):  return constants[i]
      def __repr__(self):        return 'Enum' + str(names)
      def __str__(self):         return 'enum ' + str(constants)

   class EnumValue(object):
      __slots__ = ('__value')
      def __init__(self, value): self.__value = value
      Value = property(lambda self: self.__value)
      EnumType = property(lambda self: EnumType)
      def __hash__(self):        return hash(self.__value)
      def __cmp__(self, other):
         # C fans might want to remove the following assertion
         # to make all enums comparable by ordinal value {;))
         assert self.EnumType is other.EnumType, "Only values from the same enum are comparable"
         return cmp(self.__value, other.__value)
      def __invert__(self):      return constants[maximum - self.__value]
      def __nonzero__(self):     return bool(self.__value)
      def __repr__(self):        return str(names[self.__value])

   maximum = len(names) - 1
   constants = [None] * len(names)
   for i, each in enumerate(names):
      val = EnumValue(i)
      setattr(EnumClass, each, val)
      constants[i] = val
   constants = tuple(constants)
   EnumType = EnumClass()
   return EnumType
# end Enum recipe

import re, sys

# Start of CPU register dump
regmagic = re.compile('^General Purpose Register Dump')

# Location of exit code is r24/r25
r24magic = re.compile('r24=(..) +r25=(..)')

# Start of external SRAM dump
srammagic = re.compile('^External SRAM Memory Dump:')

# Start of error code string at address 0x2000
startaddr = re.compile('^2000 :')

# Pattern to detect repeated lines
repline = re.compile('-- last line repeats --')

# Turn one line from the memory dump into an ASCII string.
# Stops processing upon encountering a NUL character.
# Returns a tuple consisting of the string and a condition
# code that is 1 when processing has been terminated by
# detecting NUL, 0 when reaching end of line without seeing
# NUL.
def asciiize(s):
    rv = ''
    a = s.split()
    for iascii in a[2:]:
        i = int(iascii, 16)
        if i == 0:
            return (rv, 1)
        if i == 10 or (i >= 32 and i < 127):
            rv += chr(i)
        else:
            # Non-printable character, not supposed to happen
            rv += '?'
    return (rv, 0)

# Calculate exitcode from r24/r25 hex values
def exitcode(r24, r25):
    i24 = int(r24, 16)
    i25 = int(r25, 16)
    return i25 * 256 + i24


# Start of main
try:
   corename = sys.argv[1]
except IndexError:
   corename = 'core_avr_dump.core'

core = open(corename)

# Our result string
s = ''

# Exit code
ec = -1

# Parser state.
pstateClass = Enum('Done', 'StartAddr', 'SRAMfound', 'GotExitCode',
                   'FoundCPUregs', 'Starting')
pstate = pstateClass.Starting

oline = ''

while pstate > pstateClass.Done:
    l = core.readline()
    if l == '':
        # EOF encountered
        break

    if pstate == pstateClass.Starting:
        if regmagic.match(l):
            pstate = pstateClass.FoundCPUregs
        continue
    elif pstate == pstateClass.FoundCPUregs:
        matchobj = r24magic.match(l)
        if matchobj != None:
            ec = exitcode(matchobj.group(1), matchobj.group(2))
            pstate = pstateClass.GotExitCode
        continue
    elif pstate == pstateClass.GotExitCode:
        if srammagic.match(l):
            pstate = pstateClass.SRAMfound
        continue
    elif pstate == pstateClass.SRAMfound or pstate == pstateClass.StartAddr:
        if repline.match(l):
            l = oline
        if pstate == pstateClass.SRAMfound:
            if startaddr.match(l):
                pstate = pstateClass.StartAddr
            else:
                continue
        (part, condcode) = asciiize(l)
        s += part
        if condcode == 1:
            pstate = pstateClass.Done
    oline = l

core.close()

print("Exit code: %d" % ec)

if s != '':
    print("Message string:")
    print(s)
else:
    print("No message string found.")
