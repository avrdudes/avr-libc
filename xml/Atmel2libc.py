#! /usr/bin/env python
#
# Copyright (c) 2004,2005  Theodore A. Roth
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

import string
import re
from xml.parsers import expat

class Element:
    'A parsed XML element'

    def __init__(self,name,attributes,depth=0):
        'Element constructor'
        # The element's tag name
        self.name = name
        # The element's attribute dictionary
        self.attributes = attributes
        # The element's cdata
        self.cdata = ''
        # The element's child element list (sequence)
        self.children = []

        self.depth = depth
        
    def AddChild(self, element, depth=0):
        'Add a reference to a child element'
        element.depth = depth
        self.children.append(element)
        
    def getAttribute(self,key):
        'Get an attribute value'
        return self.attributes.get(key)
    
    def getData(self):
        'Get the cdata'
        return self.cdata
        
    def getElements(self,name=''):
        'Get a list of child elements'
        #If no tag name is specified, return the all children
        if not name:
            return self.children
        else:
            # else return only those children with a matching tag name
            elements = []
            for element in self.children:
                if element.name == name:
                    elements.append(element)
            return elements

    def getSubTree (self, path):
        '''Path is a list of element names.
        The last element of the path is returned or None if the element is
        not found. The first name in path, should match self.name.

        This does not work if there are many children with the same name.
        '''
        if self.name != path[0]:
            return None

        if len (path) == 1:
            # We're are the last element in the path.
            return self

        for child in self.children:
            if child.name == path[1]:
                return child.getSubTree (path[1:])

        return None

    def __repr__(self):
        indent = '  ' * self.depth
        s ='%s[ %s, %s, "%s", {' % (indent, self.name, self.attributes,
                                      self.cdata)
        cs = ''
        for c in self.children:
            cs += '\n%s' % (c)

        if len (cs):
            s += '%s\n%s}]' % (cs,indent)
        else:
            s += '}]'

        return s

class Xml2Obj:
    'XML to Object'

    encoding = 'utf-8'
    
    def __init__(self):
        self.root = None
        self.nodeStack = []
        
    def StartElement(self,name,attributes):
        'SAX start element even handler'
        # Instantiate an Element object
        element = Element(name.encode(Xml2Obj.encoding),attributes)
        
        # Push element onto the stack and make it a child of parent
        if len(self.nodeStack) > 0:
            parent = self.nodeStack[-1]
            parent.AddChild(element, parent.depth+1)
        else:
            self.root = element
        self.nodeStack.append(element)
        
    def EndElement(self,name):
        'SAX end element event handler'
        self.nodeStack = self.nodeStack[:-1]

    def CharacterData(self,data):
        'SAX character data event handler'
        if string.strip(data):
            data = data.replace('&', '&amp;')
            data = data.encode(Xml2Obj.encoding)
            element = self.nodeStack[-1]
            element.cdata += data
            return

    def Parse(self,filename):
        # Create a SAX parser
        Parser = expat.ParserCreate()

        # SAX event handlers
        Parser.StartElementHandler = self.StartElement
        Parser.EndElementHandler = self.EndElement
        Parser.CharacterDataHandler = self.CharacterData

        # Parse the XML File
        ParserStatus = Parser.Parse(open(filename,'r').read(), 1)
        
        return self.root

def convert_vect_addr (addr):
    """Atmel defines vector addresses as 16-bits wide words in the atmel files
    while avr-libc defines them as byte addresses.

    The incoming addr is a string that looks like this: '$0034'

    We will convert that into a number and store it internally as such.
    """
    if addr[0] != '$':
        raise NotHexNumberErr, addr

    return int (addr[1:], 16) * 2

def print_wrapped (indent, line):
    ilen = len (indent)
    llen = len (line)
    print indent[:-1],
    if ilen + llen > 78:
        i = 78 - ilen
        while i:
            if line[i] == ' ':
                print line[:i]
                print_wrapped (indent+'  ', line[i+1:])
                break
            i -= 1
        else:
            # Couldn't find a place to wrap before col 78, try to find one
            # after.
            i = 79 - ilen
            while i < llen:
                if line[i] == ' ':
                    print line[:i]
                    print_wrapped (indent+'  ', line[i+1:])
                    break
                i += 1
            else:
                # Give up and just print the line.
                print line
    else:
        print line

def dump_header (root, depth=0):
    name = root.getSubTree (['AVRPART', 'ADMIN', 'PART_NAME']).getData()
    print '<?xml version="1.0"?>'
    print '<!DOCTYPE device SYSTEM "Device.dtd">'
    print '<device name="%s">' % (name)

    # Avoid CVS changing ID in python script.
    print '  <version>%s</version>' % ('$'+'Id$')
    print '  <description></description>'

def dump_footer (root):
    print '</device>'

def dump_memory_sizes (root):
    path = ['AVRPART', 'MEMORY']
    mem = root.getSubTree (path)

    flash_size = int (mem.getElements ('PROG_FLASH')[0].getData ())
    eep_size = int (mem.getElements ('EEPROM')[0].getData ())

    isram = mem.getSubTree (['MEMORY', 'INT_SRAM'])
    isram_size = int (isram.getElements ('SIZE')[0].getData ())
    isram_start = isram.getElements ('START_ADDR')[0].getData ()[1:]

    xsram = mem.getSubTree (['MEMORY', 'EXT_SRAM'])
    try:
        xsram_size = int (xsram.getElements ('SIZE')[0].getData ())
    except ValueError:
        # Some XSRAM entries come with just "NA" as the value
        xsram_size = 0
    xsram_start = xsram.getElements ('START_ADDR')[0].getData ()[1:]

    print '  <memory_sizes>'
    print '    <flash_size>0x%x</flash_size>' % (flash_size)
    print '    <eeprom_size>0x%x</eeprom_size>' % (eep_size)
    print '    <int_sram_size start_addr="0x%s">0x%x</int_sram_size>' % (
        isram_start, isram_size)
    print '    <ext_sram_size start_addr="0x%s">0x%x</ext_sram_size>' % (
        xsram_start, xsram_size)
    print '  </memory_sizes>'

def dump_vectors (root, tradnames):
    """Get the interupt vectors.
    """

    path = [ 'AVRPART', 'INTERRUPT_VECTOR' ]

    irqs = root.getSubTree (path)

    nvects = int (irqs.getElements ('NMB_VECTORS')[0].getData ())

    vectors = []
    for i in range (1, nvects+1):
        try:
            vect = irqs.getElements ('VECTOR%d' % (i))[0]
        except IndexError:
            # some devices have holes in the vector table =:-)
            vectors.append(())
            continue

        name = vect.getElements ('SOURCE')[0].getData ()
        saddr = vect.getElements ('PROGRAM_ADDRESS')[0].getData ()
        desc = vect.getElements ('DEFINITION')[0].getData ()

        addr = convert_vect_addr (saddr)

        vectors.append ((addr, name, desc))

    # Determine the size of the vector insn from the address of the 2nd vector.
    insn_size = vectors[1][0]

    print '  <interrupts insn_size="%d" num_vects="%d">' % (insn_size,
                                                            nvects)
    n = 0
    for v in vectors:
        # we are not really interested in the reset vector
        if n == 0:
            n += 1
            continue
        try:
            name = re.sub('[/-]', '', v[1].upper())
            name = re.sub(',', ' ', name)
            # The ATmega16HVA file has a silly SPI;STC vector name
            name = re.sub(';', '_', name)
            name = re.sub(r'\s+', '_', name)
            if re.match('^[A-Z0-9_]+$', name):
                pass
            else:
                raise 'Invalid characters in vector name even after substitution', name

            print '    <vector addr="0x%04x" num="%d" name="%s">' % (v[0], n, v[1])
            print_wrapped ('      ', '<description>%s</description>' % (v[2]))
            print '      <sig_name>%s_vect</sig_name>' % name
            for altname in tradnames.Vecname(n):
                print '      <alt_name>%s</alt_name>' % altname
            print '    </vector>'
        except IndexError:
            # this catches holes in the vector table
            pass
        n += 1
    print '  </interrupts>'

def gather_io_info (root):
    """
    The bit information may be spread across multiple IO_MODULES.

    Man that sucks. :-(

    Oh, and it gets worse. They have duplicate bit elements, but the
    duplicates are not quite complete (see SFIOR in the mega128 file). Now,
    why couldn't they just list all the register info in a single linear
    table, then in the modules, just list the registers used by the module and
    look up the register info in the linear table?

    So what we will do is walk all modules the extract register info and put
    that info into a dictionary so we can look it up later.
    """
    io_reg_info = {}

    path = ['AVRPART', 'IO_MODULE']
    io_module = root.getSubTree (path)

    # Get the list of all modules.
    mod_list = io_module.getElements ('MODULE_LIST')[0].getData ()
    mod_list = mod_list[1:-1].split (':')

    for mod in mod_list:
        # Get the list of registers for the module.
        path = ['IO_MODULE', mod, 'LIST']
        reg_list = io_module.getSubTree (path).getData ()
        reg_list = reg_list[1:-1].split (':')
        for reg in reg_list:
            path[2] = reg
            element = io_module.getSubTree (path)
            if io_reg_info.has_key (reg):
                # NOTE: The ATtiny2313.xml has a bug (There's 2 'ICR1H'
                # entries in the reg list) that causes the following for loop
                # to go infinite. Argh! Removing the extra entry seems to get
                # things working again.
                for child in element.getElements ():
                    io_reg_info[reg].AddChild (child, element.depth+1)
            else:
                io_reg_info[reg] = element

    return io_reg_info

def dump_ioregs (root):
    path = ['AVRPART', 'MEMORY', 'IO_MEMORY']
    io_mem = root.getSubTree (path)
    ioregs = io_mem.getElements ()

    ioreg_info_dict = gather_io_info (root)

    print '  <ioregisters>'

    # Skip the first 6 elements since they are just give start and stop
    # addresses.

    for ioreg in ioregs[6:]:
        name = ioreg.name
        try:
            reg_info = ioreg_info_dict[name]
            try:
                reg_desc = reg_info.getElements ('DESCRIPTION')[0].getData ()
            except IndexError:
                reg_desc = ''
        except KeyError:
            reg_info = None
            reg_desc = ''

        addr = ioreg.getElements ('IO_ADDR')[0].getData ()
        try:
            if addr[0] == '$':
                addr = '0x' + addr[1:]
            if addr == "NA":
                addr = ioreg.getElements ('MEM_ADDR')[0].getData ()
            else:
                # Add 0x20 so all addresses are memory mapped.
                addr = '0x%02x' % (int (addr, 16) + 0x20)

            print '    <ioreg name="%s" addr="%s">' % (name, addr)
            print_wrapped ('      ','<description>%s</description>' % (reg_desc))
            print '      <alt_name></alt_name>'
            for i in range (8):
                if reg_info is None:
                    continue
                bit = 'BIT%d' % (i)
                bit_el = reg_info.getSubTree ([name, bit])
                if bit_el is None:
                    continue
                bit_name = bit_el.getElements ('NAME')[0].getData ()
                try:
                    bit_desc = bit_el.getElements ('DESCRIPTION')[0].getData ()
                except IndexError:
                    bit_desc = ''
                try:
                    bit_access = bit_el.getElements ('ACCESS')[0].getData ()
                except IndexError:
                    bit_access = 'FIXME!'
                bit_init_val = bit_el.getElements ('INIT_VAL')[0].getData ()
                print '      <bit_field name="%s"' % (bit_name),
                print 'bit="%d"' % (i),
                print 'access="%s"' % (bit_access),
                print 'init="%s">' % (bit_init_val)
                if bit_desc:
                    print_wrapped ('        ',
                                   '<description>%s</description>' % (bit_desc))
                print '        <alt_name></alt_name>'
                print '      </bit_field>'
            print '    </ioreg>'
        except IndexError:  # empty register declaration
            pass

    print '  </ioregisters>'

def dump_boot_info (root):
    path = ['AVRPART', 'MEMORY', 'BOOT_CONFIG']

    info = root.getSubTree (path)
    if info:
        # The device has bootloader support.
        try:
            data = info.getElements ('NRWW_START_ADDR')[0].getData ()
            if data[0] == '$':
                data = '0x' + data[1:]
            if data == 'x':
                nrww_start = ''
            else:
                nrww_start = ' nrww_start="0x%x"' % (int (data, 16))
        except IndexError:
            nrww_start = ''

        try:
            data = info.getElements ('NRWW_STOP_ADDR')[0].getData ()
            if data[0] == '$':
                data = '0x' + data[1:]
            if data == 'x':
                nrww_end = ''
            else:
                nrww_end = ' nrww_end="0x%x"' % (int (data, 16))
        except IndexError:
            nrww_end = ''

        try:
            data = info.getElements ('RWW_START_ADDR')[0].getData ()
            if data[0] == '$':
                data = '0x' + data[1:]
            try:
                rww_start = ' rww_start="0x%x"' % (int (data, 16))
            except ValueError:
                rww_start = ''
        except IndexError:
            rww_start = ''

        try:
            data = info.getElements ('RWW_STOP_ADDR')[0].getData ()
            if data[0] == '$':
                data = '0x' + data[1:]
            try:
                rww_end = ' rww_end="0x%x"' % (int (data, 16))
            except ValueError:
                rww_end = ''
        except IndexError:
            rww_end = ''

        # The Atmel files give the pagesize in words, we need it in bytes.

        pagesize = 'pagesize="%d"' % ( \
            2 * int (info.getElements ('PAGESIZE')[0].getData ()))

        rww = '%s%s' % (rww_start, rww_end)
        nrww = '%s%s' % (nrww_start, nrww_end)
        print '  <bootloader %s%s%s>' % (pagesize, rww, nrww)

        for i in range (8):
            try:
                mode = info.getElements ('BOOTSZMODE%d' % (i))[0]
            except IndexError:
                continue

            data = mode.getElements ('PAGES')[0].getData ()
            if data == 'x':
                data = 'FIXME!'
            pages = 'pages="%s"' % (data)

            data = mode.getElements ('BOOTSTART')[0].getData ()
            if data[0] == '$':
                data = '0x' + data[1:]
            if data == 'x':
                start = 'start="FIXME: Broken xml from Atmel!"'
            else:
                start = 'start="0x%x"' % (int (data,16))

            print '    <mode num="%d" %s %s />' % (i, pages, start)

        print '  </bootloader>'

class HeaderToVec:
    'Parse header file for traditional vector names'

    def __init__(self):
        self.vects = {}

    def Read(self, fname):
        'Read header file'
        f = open(fname)
        r = re.compile(r'#\s*define\s+(SIG_[A-Z0-9_]+)\s+_VECTOR[(](\d+)[)]')
        for line in f:
            m = r.match(line)
            if m != None:
                intno = int(m.group(2))
                try:
                    x = self.vects[intno]
                except KeyError:
                    x = []
                x.append(m.group(1))
                self.vects[intno] = x
        f.close()

    def Vecname(self, idx):
        try:
            return self.vects[idx]
        except KeyError:
            return ''


if __name__ == '__main__':
    import sys

    parser = Xml2Obj()
    root = parser.Parse(sys.argv[1])

    tradheader = HeaderToVec()
    tradheader.Read(sys.argv[2])

    dump_header (root)
    dump_memory_sizes (root)
    dump_vectors (root, tradheader)
    dump_ioregs (root)
    dump_boot_info (root)
    dump_footer (root)
