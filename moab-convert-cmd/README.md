Dependencies
=============

This plugin/extension requires a licensed installation of Trelis 15.1.x and
the Trelis 15.1.x SDK.  The SDK should be untarred in the Trelis install
directory.

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

Installation is as simple as copying the generated shared object library
(`myplugin.so`) to the Trelis plugin driectory:
`/path/to/Trelis-15.1/bin/plugins`.


