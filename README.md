# Concept

*arba* is a project embedding several tiny C++ library projects:

| library                                    | version | library                                    | version | library                                    | version |
| ------------------------------------------ | ------- | ------------------------------------------ | ------- | ------------------------------------------ | ------- |
| [`core`](https://github.com/arapelle/core) | 0.8     | [`wgen`](https://github.com/arapelle/wgen) | 0.1.7   | [`vlfs`](https://github.com/arapelle/vlfs) | 0.1.0   |
| [`strn`](https://github.com/arapelle/strn) | 0.1.4   | [`dirn`](https://github.com/arapelle/dirn) | 0.1.0   | [`rsce`](https://github.com/arapelle/rsce) | 0.1.0   |
| [`math`](https://github.com/arapelle/math) | 0.3.1   | [`grid`](https://github.com/arapelle/grid) | 0.2     | [`evnt`](https://github.com/arapelle/evnt) | 0.2     |
| [`seri`](https://github.com/arapelle/seri) | 0.1.2   | [`inis`](https://github.com/arapelle/inis) | 0.1.0   | [`appt`](https://github.com/arapelle/appt) | 0.11    |
|                                            |         | [`cryp`](https://github.com/arapelle/cryp) | 0.2.4   |                                            |         |

<img src=".doc_rsc/graph.svg" style="zoom:75%;" />

See [task board](https://app.gitkraken.com/glo/board/X05bij2bBQARucHF) for future updates and features.

# Install

## Requirements

Binaries:

- A C++20 compiler (ex: g++-10)
- CMake 3.16 or later

Libraries:

- [spdlog](https://github.com/gabime/spdlog) 1.8 or later (for appt)
- [TBB](https://github.com/oneapi-src/oneTBB) 2017 or later (only for using cryp with parallelization)
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
