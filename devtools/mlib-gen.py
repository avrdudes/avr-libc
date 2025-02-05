#!/usr/bin/env python

from __future__ import print_function
import os, sys
import re, argparse

MMCU_DEFAULT = "avr2"

parser = argparse.ArgumentParser('Generate multilib tree for AVR-LibC')

parser.add_argument("-devices", dest="devices", required=True,
                    help="Text file with devices supported by AVR-LibC")

parser.add_argument("-cores", dest="cores", required=True,
                    help="Text file with cores supported by AVR-LibC")

args = parser.parse_args()

def leave(msg):
    """ Print message MSG to stderr and exit the program with exit code 1."""
    print (msg, file=sys.stderr)
    exit (1)


# The output of `avr-gcc -print-multi-lib | grep -v double`
# AND the union over all avr-gcc versions / configurations you can imagine.
#    The "double" variants are not mentioned here in order to keep
# the list easier to grasp; under the assumption that the double
# multilibs are orthogonal, i.e. for every non-double variant there are
# double variants provided avr-gcc supports -m[long-]double=32/64.
#    The @-encoded options right of ; are not used by this script except for
# removing potential multilib options from gen-avr-lib-tree.sh.  The very
# multilib options are determined by configure.ac's CHECK_MULTI_VARIANT
# (by gcc -print-multi-lib for the C libraries) and CHECK_AVR_DEVICE
# (by gcc -print-multi-directory -mmcu=<device> for the devices).

Print_Multi_Lib = """\
.;
avr25;@mmcu=avr25
avr3;@mmcu=avr3
avr31;@mmcu=avr31
avr35;@mmcu=avr35
avr4;@mmcu=avr4
avr5;@mmcu=avr5
avr51;@mmcu=avr51
avr6;@mmcu=avr6
avrxmega2;@mmcu=avrxmega2
avrxmega3;@mmcu=avrxmega3
avrxmega4;@mmcu=avrxmega4
avrxmega5;@mmcu=avrxmega5
avrxmega6;@mmcu=avrxmega6
avrxmega7;@mmcu=avrxmega7
avrtiny;@mmcu=avrtiny
tiny-stack;@msp8
avr25/tiny-stack;@mmcu=avr25@msp8
avrxmega3/short-calls;@mmcu=avrxmega3@mshort-calls
"""

def gcc_print_multi_lib ():
    """Return a string that represents a superset of all `gcc -print-multi-lib`
       which might be out there.  The assumption is that the [long] double
       variants are orthogonal to the non-double ones, and that we know
       how avr-gcc will compose the multilib sub-directories:  it will
       append them to the non-double path."""

    pml = Print_Multi_Lib.split()
    pml = filter (lambda x: not "double" in x, pml)

    # For each variant, add the 4 double variants.  Whether or
    # not the compiler actually supports one of them is determined,
    # like for any other variant, by configure.
    pml2 = [ ]
    for m in pml:
        pml2 += [ m ]
        (path,opt) = m.split(";")
        path = "" if path == "." else (path + "/")

        pml2 += [ path + "double32;" + opt + "@mdouble=32" ]
        pml2 += [ path + "double64;" + opt + "@mdouble=64" ]
        pml2 += [ path + "long-double32;" + opt + "@mlong-double=32" ]
        pml2 += [ path + "long-double64;" + opt + "@mlong-double=64" ]

    return "\n".join (pml2)


def Info (*args):
    print ("   " + " ".join (args))


class MLib (object):
    """One Multilib variant."""

    def __init__(self, line_print_multi_lib):
        """Set up multilib variant from one line of gcc -print-multi-lib."""

        self.line = line_print_multi_lib
        # A line from `gcc -print-multi-lib` looks like
        # "avr25/tiny-stack;@mmcu=avr25@msp8".
        # Left  of ";" is the relative path with "/" as path separator.
        # Right of ";" are the options leading to the multilib variant
        # where "@" stands for " -".
        (self.mdir, options) = self.line.split (";")

        self.ident = to_ident(self.mdir)

        # Work out the build directory name like avr25_tiny_stack which
        # will be an immediate subfolder of ./avr/lib.
        self.builddir = self.ident

        # The options for this variant, as a set.
        # Decode the options as retrieved from gcc_print_multi_lib().
        self.options = set(options.replace ("@", " -").strip().split())

        # The options for this variant but without -mmcu, as a set.
        self.options_no_mmcu = set(filter(lambda x: not x.startswith("-mmcu"),
                                          self.options))

        # The "architecture":  This is the portion after "-mmcu=" if
        # options contain -mmcu=, and "avr2" otherwise.
        self.arch = list(filter (lambda x: x.startswith("-mmcu="),
                                 self.options))
        if self.arch:
            self.arch = self.arch[0].replace ("-mmcu=", "")
        else:
            self.arch = MMCU_DEFAULT

        # The options will be added from the "cores" by .add_options().
        self.defs = set()
        self.cflags = set()
        self.asflags = set()

    def __repr__ (self):
        return "%s %s %s\n" % (self.mdir, self.options, self.options_no_mmcu)

    def add_options (self, core):
        """Add extra options specified in -cores=<file> for core family CORE
           provided that core is compatible with this multilib variant.
           Options might refer to Makefile variables like "$(var)"."""
        if core.mcu == self.arch:
            self.defs    |= core.defs
            self.cflags  |= core.cflags
            self.asflags |= core.asflags


class Device (object):
    """One AVR device represented by what follows -mmcu=*.  Each device
       originates from one line in -devices=<file>."""

    mcus_asm_only = ("at90s1200",
                     "attiny11", "attiny12", "attiny15", "attiny28")

    def __init__ (self, list5):
        # Pop a device from a list of 5 string elements as retrieved from
        # file args.device.  Each line looks like
        #     atxmega128a4u:crtx128a4u.o::-Os $(FNO_JUMP_TABLES):
        # and originates from dumping the AVR*_DEV_INFO variables
        # from gen-avr-lib-tree.sh.

        if not type(list5) is list or len(list5) != 5:
            raise ValueError("expecting list with 5 elements, got:", list5)
        self.mcu     = list5[0]
        self.crt_o   = list5[1] if list5[1] != "" else ("crt%s.o" % self.mcu)
        self.defs    = set(list5[2].split())
        self.cflags  = set(list5[3].split())
        self.asflags = set(list5[4].split())
        self.asm_only = (self.mcu in Device.mcus_asm_only)

    __hash__ = None
    # So that "in list" works as expected.
    def __cmp__(self, other):
        if not type(other) is Device:
            return -1
        return cmp (self.mcu, other.mcu)

    def __repr__ (self):
        return self.mcu


class Core (object):
    """Only a container for options as retrieved from -cores=<file>."""
    def __init__ (self, list5):
        if not type(list5) is list or len(list5) != 5:
            raise ValueError("expecting list with 5 elements, got:", list5)
        self.mcu = list5[0] if list5[0] != "" else MMCU_DEFAULT
        self.defs    = set(list5[2].split())
        self.cflags  = set(list5[3].split())
        self.asflags = set(list5[4].split())

    __hash__ = None

    # Implement __eq__ so that "in list" works as expected.
    def __eq__(self, other):
        return self.mcu == other.mcu if type(other) is Core else False

    def __repr__ (self):
        return self.mcu

class Makefile (object):
    files = [ ]

    def __init__(self, path):
        self.path = path

    def __cmp__(self, other):
        if not type(other) is Makefile:
            return -1
        return cmp (self.path, other.path)

    def __str__(self):
        return self.path

    @classmethod
    def add(clazz, dirs):
        """Register a Makefile (to be emit as AC_CONFIG_FILE to files.m4)
           and prepare an according Makefile.am for the parallel build.
           "parallel" means here that srcdir and builddir will have the same
           layout.  Return the OS-dependent path to Makefile.am and add the
           Makefile to .files."""

        path = "/".join(dirs) + "/Makefile"
        clazz.files += [ Makefile(path) ]

        # Try to mkdir the directory in in which Makefile.am will live.
        path = os.path.join(*dirs)
        try:
            os.mkdir (path)
        except OSError:
            # If we come here, the assumption is that path already existed.
            pass

        return os.path.join(path, "Makefile.am")


def to_ident(var):
    """Turn a string (usually a (sub)folder) into some canonical
       representation that can be used as (part of) an identifier
       or a file name."""

    # This are the same replacements that are performed by CHECK_AVR_DEVICE
    # to get to DEVLIST_<<ident>> used by Architecture.am.  DEVLIST_<<ident>>
    # is only needed if !HAS_DEV_LIB, i.e. with avr-gcc < v5.
    repls = ((".", "avr2"),
             ("-", "_"),
             ("/", "_"))
    for (a,b) in repls:
        var = var.replace (a, b)
    return var


mlibs = gcc_print_multi_lib()
mlibs = [ MLib (line) for line in mlibs.split() ]

Info ("Have %d potential multilibs." % len(mlibs))

multilib_options = set()
for mlib in mlibs:
    multilib_options |= set (mlib.options_no_mmcu)

# Retrieve cores and their extra options form -cores=<file>.

cores = [ ]

Info ("Reading %s..." % args.cores)
with open (args.cores, "r") as f:
    for line in f.readlines():
        m = line.strip().split(":")

        # Expect each line to be composed of 5 fields, separated by 4 ":"s.
        # Ignore empty lines (if any).
        # Field #1: Core as to be specified with -mmcu=*.  Notice that to
        #           identify a multilib variant, more options might be needed.
        # Field #2: Unused here.
        # Field #3: Options.
        # Field #4: Options for C.
        # Field #5: Options for Asm.
        if m:
            core = Core(m)
            if not core in cores:
                cores += [ core ]

# Retrieve devices and their options from -devices=<file>.

devices = [ ]

Info ("Reading %s..." % args.devices)
with open (args.devices, "r") as f:
    for line in f.readlines():
        m = line.strip().split(":")
        # Expect each line to be composed of 5 fields, separated by 4 ":"s.
        # Ignore empty lines (if any).
        # Field #1: Device name to be passed as -mmcu=*.
        # Field #2: File name of crt*.o (only used with old versions).
        # Field #3: Options.
        # Field #4: Options for C.
        # Field #5: Options for Asm.
        if m:
            device = Device(m)
            if device in devices:
                leave ("duplicate device: %s" % device)
            devices += [ device ]

Info ("Have %d devices." % len(devices))

for mlib in mlibs:
    """Add core-specific extra (non-multilib) options to our multilib-variants.
       A "core" is specified by what follows -mmcu=, and the options for
       "core" come from gen-avr-lib-tree.sh."""
    for core in cores:
        mlib.add_options (core)


# The Makefile.am template for ./avr/lib/<multilib-buildir>
Info ("Reading %s..." % "devtools/Architecture.am")
with open ("devtools/Architecture.am", "r") as f:
    Architecture_am = f.read()

# The Makefile.am templates for ./avr/devices/<device>
Info ("Reading %s..." % "devtools/Device.am")
with open ("devtools/Device.am", "r") as f:
    Device_am = f.read()

path_avr = "avr"
path_lib = "lib"
path_devices = "devices"


def makedir_avr():
    """Build ./avr"""

    Makefile_am = Makefile.add ([path_avr])

    Info ("Writing %s..." % Makefile_am)
    with open (Makefile_am, "w") as f:
        f.write ("SUBDIRS = lib devices\n")

def makedir_avr_lib():
    """Build ./avr/lib"""

    Makefile_am = Makefile.add ((path_avr, path_lib))

    dirs = map (lambda x: x.builddir, mlibs)

    Info ("Writing %s..." % Makefile_am)
    with open (Makefile_am, "w") as f:
        f.write ("SUBDIRS = %s\n" % " ".join (dirs))


def makedir_avr_devices_device(device):
    """Build ./avr/devices/<device.mcu>"""

    Makefile_am = Makefile.add ((path_avr, path_devices, device.mcu))

    replacements = {
        "<<dev>>" : device.mcu,
        "<<crt>>" : device.crt_o,
        # Remove any multilib options.  In order to pick the multilib "base",
        # option -mmcu=<device> is enough.  In the case where fancy variants
        # like "double64" are supported, the assumption is that no object for
        # any device depends on such options like -mdouble=64.  In that case,
        # the Makefile will just install the respective stuff like crt<mcu>.o
        # and lib<mcu>.a in multiple places, cf. Makefile.am.
        "<<crt_defs>>"    : " ".join(device.defs - multilib_options),
        "<<crt_cflags>>"  : " ".join(device.cflags - multilib_options),
        "<<crt_asflags>>" : " ".join(device.asflags - multilib_options)
    }

    if device.asm_only:
        replacements["$(eeprom_c_sources)"] = ""
        replacements["$(dev_c_sources)"] = ""

    device_am = Device_am
    for r in replacements:
        device_am = device_am.replace (r, replacements[r])

    Info ("Writing %s..." % Makefile_am)
    with open (Makefile_am, "w") as f:
        f.write (device_am)


def makedir_avr_devices():
    """Build ./avr/devices"""

    Makefile_am = Makefile.add ((path_avr, path_devices))

    # The SUBDIRs of ./avr/devices are the MCUs like "atmega8".
    dirs = map (lambda x: x.mcu, devices)

    Info ("Writing %s..." % Makefile_am)
    with open (Makefile_am, "w") as f:
        f.write ("SUBDIRS = %s\n" % " ".join(dirs))


def makedir_avr_lib_arch(mlib):
    """Build ./avr/lib/<mlib.builddir>"""

    Makefile_am = Makefile.add ((path_avr, path_lib, mlib.builddir))

    replacements = {
        "<<arh>>"   : mlib.arch,
        "<<ident>>" : mlib.ident,
        # Remove any multilib options, they are added by $(MULTIOPT_<<ident>>).
        "<<lib_defs>>"    : " ".join(mlib.defs - multilib_options),
        "<<lib_cflags>>"  : " ".join(mlib.cflags - multilib_options),
        "<<lib_asflags>>" : " ".join(mlib.asflags - multilib_options)
    }

    arch_am = Architecture_am
    for r in replacements:
        arch_am = arch_am.replace (r, replacements[r])

    Info ("Writing %s..." % Makefile_am)
    with open (Makefile_am, "w") as f:
        f.write (arch_am)


def make_lib_tree():
    makedir_avr()
    makedir_avr_lib()
    makedir_avr_devices()

    for mlib in mlibs:
        makedir_avr_lib_arch(mlib)

    for d in devices:
        makedir_avr_devices_device(d)

# devices.m4 will be lines of:
devices_m4 = ("CHECK_AVR_DEVICE(%s)\n",
              "CHECK_AVR_CVT(%s)\n")

# multilib.m4 will be lines of:
check_multi_variant = "CHECK_MULTI_VARIANT([%s], [%s])\n"

# files.m4 will be lines of:
ac_config_files = "AC_CONFIG_FILES([%s])\n"

# devlist.m4 will be lines of:
ac_subst_devlist = "AC_SUBST(DEVLIST_%s)\n"

def make_m4():
    """Auto-generated files to be included by configure.ac."""

    Info ("Writing devices.m4...")
    with open ("devices.m4", "w") as f:
        for line in devices_m4:
            for device in devices:
                f.write (line % device.mcu)

    Info ("Writing devlist.m4...")
    with open ("devlist.m4", "w") as f:
        for mlib in mlibs:
            f.write (ac_subst_devlist % mlib.ident)

    Info ("Writing multilib.m4...")
    with open ("multilib.m4", "w") as f:
        for mlib in mlibs:
            f.write (check_multi_variant % (mlib.mdir, mlib.ident))

    Info ("Writing files.m4...")
    with open ("files.m4", "w") as f:
        for mk in Makefile.files:
            f.write (ac_config_files % mk)

make_lib_tree()

Info ("Wrote %d Makefile.am's." % len(Makefile.files))

make_m4()

Info ("Done.")
