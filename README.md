# Concept

*arba* is a project embedding several independent C++ library projects:

- [`strn`](https://github.com/arapelle/strn) 0.1.3
- [`wgen`](https://github.com/arapelle/wgen) 0.1.6

See [task board](https://app.gitkraken.com/glo/board/X05bij2bBQARucHF) for future updates and features.

# Install

## Requirements

Binaries:

- A C++20 compiler (ex: g++-10)
- CMake 3.16 or later

Libraries:

- [Google Test](https://github.com/google/googletest) 1.10 or later (only for testing)

## Clone

```
git clone https://github.com/arapelle/arba --recurse-submodules
```

## Quick Install

There is a cmake script at the root of the project which builds the library in *Release* mode and install it (default options are used).

```
cd /path/to/arba
cmake -P cmake_quick_install.cmake
```

Each library (strn, wgen, ...) is installed independently.

Use the following to quickly install a different mode and specify the install directory.

```
cmake -P cmake_quick_install.cmake -- BUILD Debug DIR /tmp/local
```

## Uninstall

There is a uninstall cmake script created during installation. You can use it to uninstall properly arba libraries.

```
cd /path/to/installed-arba/
cmake -P cmake_uninstall.cmake
```

It will remove all arba libraries! So, if you want to uninstall only one of them, execute the `cmake_uninstall.cmake` script of the library you want to remove.

# License

[MIT License](https://github.com/arapelle/arba/blob/master/LICENSE.md) © arba
