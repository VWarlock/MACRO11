# MACRO11
MACRO11 is an PDP-11 cross assembler, written in C.
Projects files are included only for Win32 platform MS Visual Studio 2015, as it's been used as part of PDP11GUI.

This MACRO11 was forked from Richard Krebiehls version in 2008. Thanks!
[Richard's version is here.](http://www.dbit.com/pub/pdp11/macro11/).

Changes since then:
* restructured the sources
* bugfixes. For example "JMP Rn is illegal" on "jmp (rx)".
* added option "-listhex" to generate listings in hex instead of octal (helpful for work with modern logic analyzers).

Also see my [MACRO11 page](http://www.retrocmp.com/tools/macro-11-on-windows).

Apparently in 2009 my code was forked into github, without notifying me.
See github.com/shattered/macro11 !

The changes made there were also merged into this code in Nov 2016.







Files:
    macro11.c       This is the vast bulk of the code
    object.c        Functions for writing RT-11 compatible .OBJ files
    mlb.c           Classes (!) for reading RT-11 macro libraries
    stream2.c       Functions for managing input streams and buffers
    rad50.c         Functions for converting text to and from RAD50
    util.c          A few general utility fuctions

    macro11.h, object.h, mlb.h, stream2.h, rad50.h, util.h
                    types and symbols exported from the associated sources.

    dumpobj.c       A program I wrote to examine the output from
                    RT-11's MACRO.SAV program and compare it with my
                    own output.

    makefile, depends
                    A simple makfile for Linux; simple enough, it
                    should be convertible to any Unix.

    macro11.dsp, dumpobj.dsp, macro11.dsw
                    Visual Studio 6 projects

    README          This file

    LICENSE         The copyright notice and license

    CHANGES         A list of changes from previous versions

    TODO            A list of things that may need fixing


Notes:

Sorry, I am a believer in 4 column hardware tabs, for a number of
reasons, mostly regarding editing convenience.  (I did untabify this
README file though.)

The bulk of my development was done in Microsoft Visual Studio 6, but
I also have a Linux partition and the Cygnus Windows toolkit, so you
can send me "patches" and I will be able to apply them with the
"patch" utility.

The macro11 command line:

macro11 [options...] files...

Options:
    -v              Prints program version.

    -e opt          .ENABL option.  Implemented options are AMA, GBL,
                    and also .LIST options ME, BEX, and
                    MD, though the status of listing control is
                    presently very poor.

    -d opt          .DSABL option; same options as -e.

    -m macname      Gives a macro library name.
                    Up to 32 macro libraries may be specified, one per
                    -m option.
                    Note: unlike MACRO.SAV, SYSMAC.SML is not
                    automatically included; you must name it.

    -p macpath      For any .MCALL <macro> directive, macro11 will
                    first search -m macro libraries, then it will
                    search the MCALL path for a file named <macro>.MAC
                    to locate the body of the macro.  The MCALL path
                    is an environment variable containing directory
                    names separated by delimiters (":" for Unix-style
                    targets; ";" for Windows).  The -p command line
                    options appends a directory name to the MCALL
                    path.

    -o objname      Gives the name of the object file.  No extension
                    is assumed; if you want .OBJ you have to say it.
                    With no -o option, no object file is generated.

    -l lstname      Gives the name of a listing file.  The name "-"
                    may be given to write the listing to stdout.  No
                    extension is assumed; if you want .LST you have to
                    say it.  With no -l option, no listing file is
                    written.

    -x              Tells macro11 not to assemble anything, but rather
                    to simply extract all the macros in all the -m
                    macro libraries into individual .MAC files in the
                    current directory.  This should be the last option
                    given, as none following will be processed.

    files...        Any number of input files.  They will be assembled
                    as if they were concatenated together.


You may define the MCALL environment variable prior to invoking
macro11, as a path to directories containing macros.
