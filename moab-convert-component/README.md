Dependencies
=============

This plugin/extension requires a licensed installation of Trelis 15.1.x and
the Trelis 15.1.x SDK.  The SDK should be untarred in the Trelis install
directory.

It also requires:
* swig
* libpython2.7-dev

Build
======

```
mkdir bld
cd bld
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Trelis-15.1/bin
make
```

Install
=======

Installation of a component requires that it be manually loaded in the Components dialog accessible from the Trelis Tools menu.  When loading the component, you will asked for the case-sensitive C++ class name `MyComp`.

It doesn't matter what directory the component is in, but proper installation is probably best in a subirectory of `/path/to/Trelis15.1/bin/plugins`.


