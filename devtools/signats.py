#!/usr/bin/env python

# This script is run by and provided with inputs by signats.sh.

from __future__ import print_function

import sys, re

sig_txt = sys.argv[1] # Snips of avrdude.conf or atdf
loc_txt = sys.argv[2] # Snips of preprocessed <avr/io.h>
sed_txt = sys.argv[3] # Writing sec command to here.

"""
sig.txt look like:
   desc             = "AT90S2313";
   signature        = 0x1e 0x91 0x01;
or
   <property name="SIGNATURE*" value="*"/>

loc.txt looks like:
   1436:# 148 "/home/gnu/source/avr-libc/include/avr/io2313.h"
   1664:#define SIGNATURE_0 0x1E
   1665:#define SIGNATURE_1 0x91
   1666:#define SIGNATURE_2 0x01
"""

class Signature:
    def __init__(self, id, s_val, iloc = 0):
        self.id = id
        self.s_val = s_val
        self.val = int (s_val, base=0)
        self.loc_in_i = int(iloc)
        self.loc_in_h = 0
        print ("sig[%d] = 0x%02x @ %s" % (self.id, self.val, self.loc_in_i))

    def __eq__ (self, other):
        return self.val == other.val

    def __ne__ (self, other):
        return self.val != other.val

    def __repr__ (self):
        return self.s_val # "0x%02x" % self.val

def Error (msg):
    print ("%s: error: %s" % (sys.argv[0], msg), file=sys.stderr)
    sys.exit (1)

def CheckSane ():
    if not loc_in_h or not loc_in_i:
        Error ("failed to find offsets")

    if not h_file:
        Error ("failed to find file name of I/O header in loc_txt")

    for i in range(3):
        if not conf_sig[i]:
            Error ("failed to find signature %d in sig_txt" % i)
        if not h_sig[i]:
            Error ("failed to find signature %d in loc_txt" % i)
        if not h_sig[i].loc_in_h:
            Error ("failed to find loc of SIGNATURE_%d in loc_txt" % i)

# Write sed commands to FIL that patch signature A to signature B as needed.
# Each signature gets its own sed command.  The sed commands address the
# exact source line in io*.h and expect the exacrt macro name to be
# present.  If that's not the case then the command will be a no-op.
def WritePatchCommands (fil, a, b):
    for i in range(3):
        if a[i] != b[i]:
            print ("Must Patch %d from %s to 0x%02x"
                   % (i, a[i].s_val, b[i].val))
            cmd = r"sed -i -e '%ds:\(^.*SIGNATURE_%d\).*:\1 0x%02X:' " \
                % (a[i].loc_in_h, i, b[i].val) + h_file
            print (cmd, file=fil)

# Matches a C-ish hex number.
hexG = "([x0-9a-fA-F]+)"

# Harvest a  #define SIGNATUE_0 0x**  from an i file.
pat_define_sig \
    = re.compile (r"(\d+):\s*#define\s+SIGNATURE_([0-2])\s+"+ hexG +".*")

# Harvest a location  <i-line>:# <h-line> "<file">  note from an i file.
pat_loc_h \
    = re.compile (r'(\d+):#\s*(\d+)\s+"(.*)".*')

# Harvest a  signature = * * *;  line from avrdude.conf.
pat_conf_sig \
    = re.compile (r"\s*signature\s*=\s*"+ hexG +"\s*"+ hexG +"\s*"+ hexG +";.*")

# Harvest  <property name="SIGNATURE0" value="*"/>  from ATDF.
pat_atdf_sig \
    = re.compile (r'.*property\s+name\s*=\s*"SIGNATURE(\d)"\s+'
                  + r'value\s*=\s*"' + hexG + r'".*')

conf_sig = 3 * [ None ]
h_sig    = 3 * [ None ]

loc_in_i = 0
loc_in_h = 0
h_file = None

print ("reading %s..." % sig_txt)

with open (sig_txt) as file:
    for l in file:
        line = l.strip()
        print ("LINE=", line)
        m = pat_conf_sig.match (line)
        if m:
            print ("YA:", m.group (0))
            conf_sig[0] = Signature (0, m.group(1))
            conf_sig[1] = Signature (1, m.group(2))
            conf_sig[2] = Signature (2, m.group(3))

        m = pat_atdf_sig.match (line)
        if m:
            print ("YA:", m.group (0))
            id = int(m.group(1))
            conf_sig[id] = Signature (id, m.group(2))

print ("reading %s..." % loc_txt)

with open (loc_txt) as file:
    for l in file:
        line = l.strip()

        m = pat_loc_h.match (line)
        if m:
            print (line, "-->", m.group(1), m.group(2), m.group(3))
            loc_in_i = int (m.group(1))
            loc_in_h = int (m.group(2))
            h_file = m.group(3)

        # From  #define SIGNATUE_N lines from *.i
        # loc_in_i is the location in *.i
        m = pat_define_sig.match (line)
        if m:
            id = int(m.group(2))
            print (line, "-->", m.group(1), id, m.group(3))
            h_sig[id] = Signature (id, m.group(3), m.group(1))
            h_sig[id].loc_in_i = int(m.group(1))

# Done with reading thr inputs.  Endow the signature with the
# line number in the avr/io*.h file.
loc_offset = loc_in_h - loc_in_i - 1

for s in h_sig:
    s.loc_in_h = s.loc_in_i + loc_offset

print ("loc in .i = %d %d %d"
       % (h_sig[0].loc_in_i, h_sig[1].loc_in_i, h_sig[2].loc_in_i))

print ("loc in .h = %d %d %d # %s"
       % (h_sig[0].loc_in_h, h_sig[1].loc_in_h, h_sig[2].loc_in_h, h_file))

# Show signature avr/io.h vs. expected as of AVRDUDE / ATDF.
print ("h.sig    =", h_sig)
print ("conf.sig =", conf_sig)

CheckSane ()

with open (sed_txt, "a") as file:
    WritePatchCommands (file, h_sig, conf_sig)
