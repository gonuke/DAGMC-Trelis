Purpose
==========

This example adds a command to Trelis named `mbconvert`.  This command currently attempts to read an input file into MOAB and write an output file from MOAB.

This example also adds a menu to Trelis with an entry to invoke `mbconvert`.

Architecutre Notes
=====================

Rather than sending a (newly added) Cubit command to the parser, the action on this menu item calls identical code to the new command.  This is accomplished by including the code in multiple places.

Rather than invoking the menu addition from within the component directly, the
`MenuManager` class is useful because it inherits from different Qt base
classes.

Dependencies
=============

This plugin/extension requires a licensed installation of Trelis 15.1.x and
the Trelis 15.1.x SDK.  The SDK should be untarred in the Trelis install
directory.

This plugin also depends on:
* libqt4-dev
* swig
* python2.7-dev
* MOAB (and thus HDF5)

Build
======

```
mkdir bld
cd bld
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Trelis-15.1/bin -DMOAB_DIR=/path/to/MOAB/lib
make
```

Install
=======

Installation of the additional command is as simple as copying the generated
shared object library (`my_plugin.so`) to the Trelis plugin driectory:
`/path/to/Trelis-15.1/bin/plugins`.

Installation of a component requires that it be manually loaded in the Components dialog accessible from the Trelis Tools menu.  When loading the component, you will asked for the case-sensitive C++ class name `MyComp`.

It doesn't matter what directory the component is in, but proper installation is probably best in a subirectory of `/path/to/Trelis15.1/bin/plugins`.

