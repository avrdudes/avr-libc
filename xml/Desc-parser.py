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

import os, sys, types

from xml.sax import make_parser
from xml.sax.handler import ContentHandler

class XML_Mixin:
    children = {}
    def __init__ (self, attrs):
        self.xml_members = []
        for name in attrs.getNames ():
            if attrs.getType (name) == 'CDATA':
                self.xml_members.append (name)
                setattr (self, name, attrs.getValue (name))
        self.data = ''

    def create_child (self, name, attrs):
        return self.children[name] (attrs)

    def add_child (self, name, obj):
        self.xml_members.append (name)
        setattr (self, name, obj)

    def characters (self, ch):
        self.data += ch

    def __str__ (self):
        s = '[ data = "%s"; ' % (self.data)
        for member in self.xml_members:
            s += '%s = %s; ' % (member, str (getattr (self, member)))
        s += ']\n'
        return s

class PCData (XML_Mixin):
    def __repr__ (self):
        return '"%s"' % (self.data)

class MemorySizes (XML_Mixin):
    children = {
        'flash_size': PCData,
        'eeprom_size': PCData,
        'int_sram_size': PCData,
        'ext_sram_size': PCData
        }

class Vector (XML_Mixin):
    children = {
        'description': PCData,
        'sig_name': PCData,
        'alt_name': PCData
        }
    def add_child (self, name, obj):
        if name == "alt_name":
            try:
                x = getattr (self, name)
                x.data.append(obj.data)
                setattr (self, name, x)
            except AttributeError:
                x = obj.data
                obj.data = [x]
                self.xml_members.append (name)
                setattr (self, name, obj)
        else:
            self.xml_members.append (name)
            setattr (self, name, obj)


class Interrupts (dict, XML_Mixin):
    children = {
        'vector': Vector
        }

    def __init__ (self, attrs):
        dict.__init__ (self)
        XML_Mixin.__init__ (self, attrs)

    def add_child (self, name, obj):
        # Use the Vector 'num' attr as the key for the child object.
        if self.has_key (obj.num):
            raise 'Duplicate vector entry', obj
        self[obj.num] = obj

class BitField (XML_Mixin):
    children = {
        'description': PCData,
        'alt_name': PCData
        }

class IORegister (XML_Mixin):
    children = {
        'description': PCData,
        'alt_name': PCData,
        'bit_field': BitField,
        }

    def add_child (self, name, obj):
        if name == 'bit_field':
            if not hasattr (self, name):
                setattr (self, name, {})
            # Use the BitField 'bit' attr as the key for the child object.
            self.bit_field[obj.bit] = obj
        else:
            XML_Mixin.add_child (self, name, obj)

class IORegisterDict (dict, XML_Mixin):
    children = {
        'ioreg': IORegister
        }

    def __init__ (self, attrs):
        dict.__init__ (self)
        XML_Mixin.__init__ (self, attrs)

    def add_child (self, name, obj):
        # Use the IORegister 'name' attr as the key for the child object.
        if self.has_key (obj.name):
            raise 'Duplicate io register entry', obj
        self[obj.name] = obj

class BootMode (XML_Mixin):
    pass

class BootLoader (dict, XML_Mixin):
    children = {
        'mode': BootMode
        }

    def __init__ (self, attrs):
        dict.__init__ (self)
        XML_Mixin.__init__ (self, attrs)

    def add_child (self, name, obj):
        # Use the BootMode 'num' attr as the key for the child object.
        if self.has_key (obj.num):
            raise 'Duplicate boot mode entry', obj

        self[obj.num] = obj

class Device (XML_Mixin):
    children = {
        'version': PCData,
        'description': PCData,
        'memory_sizes': MemorySizes,
        'interrupts': Interrupts,
        'ioregisters': IORegisterDict,
        'bootloader': BootLoader
        }

class DescHandler (ContentHandler):
    """Content Handler for the device description xml files.
    """

    def __init__ (self):
        self.depth = 0
        self.stack = []

    def push (self, name, obj):
        self.stack.append ([name, obj])

    def pop (self):
        return self.stack.pop ()

    def get_curr_obj (self):
        return self.stack[-1][1]

    def startElement (self, name, attrs):
        if self.depth == 0:
            obj = Device (attrs)
            self.dev = obj
        else:
            # Look up the elements class in the parent's children dict.
            parent = self.get_curr_obj ()
            obj = parent.create_child (name, attrs)

        self.push (name, obj)
        self.depth += 1

    def endElement (self, name):
        self.depth -= 1

        # Pull the current element off the stack and add it to the parent.
        (cname, cobj) = self.pop ()

        cobj.data = ' '.join (cobj.data.split ())

        try:
            parent = self.get_curr_obj ()
            parent.add_child (cname, cobj)
        except IndexError:
            # We're back at the root element, so we're done.
            pass

        #print '%s%s %s' % ('  '*self.depth, cname, cobj)

    def characters (self, ch):
        self.get_curr_obj().characters (ch)

    def endDocument (self):
        #print self.dev
        pass

if __name__ == '__main__':
    parser = make_parser ()

    handler = DescHandler ()
    parser.setContentHandler (handler)

    if len(sys.argv) > 1:
        parser.parse (open (sys.argv[1]))
    else:
        parser.parse (open ('desc-90s1200.xml'))

    l = parser.getContentHandler().dev.interrupts.keys()
    l.sort(lambda x, y: cmp(int(x), int(y)))
    for key in l:
        ele = parser.getContentHandler().dev.interrupts[key]
        print "/* " + ele.description.data + " */"
        print "#define " + ele.sig_name.data + "\t_VECTOR(" + key + ")"
        for x in ele.alt_name.data:
            print "#define " + x + "\t_VECTOR(" + key + ")"
        print ""
