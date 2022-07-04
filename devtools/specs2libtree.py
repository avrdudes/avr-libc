#!/usr/bin/env python3
#
# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42):
# <j@uriah.heep.sax.de> wrote this file.  As long as you retain this notice you
# can do whatever you want with this stuff. If we meet some day, and you think
# this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
# ----------------------------------------------------------------------------

# Tool to extract some data out of a bunch of GCC specs files,
# providing snippets for gen-avr-lib-tree.sh, and <avr/io.h>.
#
# Intended to run on specs files from Microchip "device packs", to
# ease integration of new devices.

import sys
import re

def usage():
    print('usage: spec2libtree.py <specfiles>', file = sys.stderr)
    sys.exit(64)

def parse_specs(name):
    mcuclass = ''
    flashsize = ''
    crtfile = ''
    devname = ''
    macro = ''
    header = ''
    # pre-compile regexps
    mcu_re = re.compile('.*-mmcu=([^ ]+) ')
    flash_re = re.compile('.*--pmem-wrap-around=([\d]+)')
    crt_re = re.compile('.*(crt[a-z0-9]+\.o)')
    devname_re = re.compile('.*-D(__AVR[^ ]+__).*-D__AVR_DEVICE_NAME__=([a-z0-9]+).*-D__AVR_DEV_LIB_NAME__=([A-Za-z0-9]+)')

    with open(name) as f:
        l = f.readlines()
        i = 0
        for line in l:
            x = line.find('self_spec')
            if x >= 0:
                # next line is supposed to have the MCU group
                m = mcu_re.match(l[i + 1])
                if m:
                    mcuclass = m.group(1)
            x = line.find('link_pmem_wrap')
            if x >= 0:
                # if next line has --pmem-wrap-around=64k this gets
                # us the flash size; if empty, assume 128k;
                # flash size is only used to distinguish between
                # ${CFLAGS_SPACE} and ${CFLAGS_BIG_MEMORY}
                m = flash_re.match(l[i + 1])
                if m:
                    flashsize = m.group(1)
                else:
                    flashsize = 128
            x = line.find('avrlibc_startfile')
            if x >= 0:
                m = crt_re.match(l[i + 1])
                if m:
                    crtfile = m.group(1)
            x = line.find('cpp')
            if x >= 0:
                # next line has CPP macros, among them the device name
                m = devname_re.match(l[i + 1])
                if m:
                    devname = m.group(2)
                    macro = m.group(1)
                    header = m.group(3)
            i = i + 1
        return (mcuclass, flashsize, crtfile, devname, macro, header)
    return None

classes = {}

if len(sys.argv) <= 1:
    usage()

# parse all input files
for arg in sys.argv[1:]:
    result = parse_specs(arg)
    if result != None:
        (mcuclass, flashsize, crtfile, devname, macro, header) = result
        key = mcuclass.upper() + '_DEV_INFO'
        data = devname + ':' + crtfile + ':${DEV_DEFS}:'
        if int(flashsize) >= 64:
            data += '${CFLAGS_BIG_MEMORY}:${DEV_ASFLAGS};\\'
        else:
            data += '${CFLAGS_SPACE}:${DEV_ASFLAGS};\\'
        try:
            classes[key].append((data, macro, header))
        except KeyError:
            classes[key] = [(data, macro, header)]

k = list(classes.keys())
k.sort()

# output #1: gen-avr-lib-tree.sh snippets
for key in k:
    d = classes[key]
    print(key + '="\\')
    i = 0
    for data in d:
        data = data[0] # remove macro and header
        if i == len(d) - 1:
            # drop semicolon
            print(data[:-2] + data[-1:])
        else:
            print(data)
        i += 1
    print('"')

# output #2: <avr/io.h> addition
for key in k:
    d = classes[key]
    for data in d:
        print('#elif defined (' + data[1] + ')')
        print('#  include <avr/io' + data[2] + '.h>')
