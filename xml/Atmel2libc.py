#! /usr/bin/env python
#
# $Id$
#

import string
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

    def __str__(self):
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
    xsram_size = int (xsram.getElements ('SIZE')[0].getData ())
    xsram_start = xsram.getElements ('START_ADDR')[0].getData ()[1:]

    print '  <memory_sizes>'
    print '    <flash_size>0x%x</flash_size>' % (flash_size)
    print '    <eeprom_size>0x%x</eeprom_size>' % (eep_size)
    print '    <int_sram_size start_addr="0x%s">0x%x</int_sram_size>' % (
        isram_start, isram_size)
    print '    <ext_sram_size start_addr="0x%s">0x%x</ext_sram_size>' % (
        xsram_start, xsram_size)
    print '  </memory_sizes>'

def dump_vectors (root):
    """Get the interupt vectors.
    """
    path = [ 'AVRPART', 'INTERRUPT_VECTOR' ]

    irqs = root.getSubTree (path)

    nvects = int (irqs.getElements ('NMB_VECTORS')[0].getData ())

    vectors = []
    for i in range (1, nvects+1):
        vect = irqs.getElements ('VECTOR%d' % (i))[0]

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
        print '    <vector addr="0x%04x" num="%d" name="%s">' % (v[0], n, v[1])
        print_wrapped ('      ', '<description>%s</description>' % (v[2]))
        print '      <sig_name></sig_name>'
        print '    </vector>'
        n += 1
    print '  </interrupts>'

def dump_ioregs (root):
    print '  <ioreg name="" addr="">'
    print '  </ioreg>'

if __name__ == '__main__':
    import sys

    parser = Xml2Obj()
    root = parser.Parse(sys.argv[1])

    dump_header (root)
    dump_memory_sizes (root)
    dump_vectors (root)
    dump_ioregs (root)
    dump_footer (root)
