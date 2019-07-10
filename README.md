# scaper
static code analysis project which supports multiple SCA tools with Qt GUI

INSTALLATION:
--
clone git repo<br>
in source directory create a directory 'build' (mkdir build)<br>
cd build/<br>
cmake ..<br>
make

---
possible issues:
--
By not providing "FindQt5.cmake" in CMAKE_MODULE_PATH this project has
  asked CMake to find a package configuration file provided by "Qt5", but
  CMake did not find one.

resolution:
on Debian: sudo apt install qt5-default
retry


