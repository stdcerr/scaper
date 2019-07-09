# scaper
static code analysis project which supports multiple SCA tools with Qt GUI

INSTALLATION
clone git repo
in source directory create a directory build/
cd build/
cmake ..
make

POSSIBLE PROBLEMS
during cmake:
----
By not providing "FindQt5.cmake" in CMAKE_MODULE_PATH this project has
  asked CMake to find a package configuration file provided by "Qt5", but
  CMake did not find one.
---
resolution:
on Debian: sudo apt install qt5-default
retry


