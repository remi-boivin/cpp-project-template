# C++ project's  template

A short description of my project.

## Prerequisites

1. [CMake](https://cmake.org/)
2. [Clang](https://clang.llvm.org/) or [gcc](https://gcc.gnu.org/)

## Directory's structure

The structure of the project

```
├── CMakeLists.txt
├── docs
├── includes
│   └── my.hpp
├── LICENSE
├── README.md
├── src
    ├── CMakeLists.txt
    └── main.cpp
```

## Building the project on Linux

There is some basic step to follow if you want to build the project on your computer.

First type:

**```cmake -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_BUILD_TOOL=clang```**

You should have something like this:
```
-- The C compiler identification is GNU 11.3.0
-- The CXX compiler identification is Clang 12.0.1
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/clang++-12 - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/remiboivin/Informatique/cpp-project-template/build
```

then you can type: 

**```cd build && make ```**

You should have something like this: 
```
~/cpp-project-template/build (master)$ make
Scanning dependencies of target CppUTest
...
...
...
-- Configuring done
-- Generating done
-- Build files have been written to: /home/remiboivin/Informatique/cpp-project-template/build
[  5%] Building C object src/CMakeFiles/cpputest_exasple_pythagorean.dir/main.c.o
[ 11%] Building C object src/CMakeFiles/cpputest_exasple_pythagorean.dir/pythagorean.c.o
[ 17%] Building C object src/CMakeFiles/cpputest_exasple_pythagorean.dir/square_root.c.o
[ 23%] Linking C executable cpputest_exasple_pythagorean
[ 23%] Built target cpputest_exasple_pythagorean
[...]
[ 80%] Building CXX object tests/Log/CMakeFiles/logger.dir/main.cpp.o
[ 86%] Building CXX object tests/Log/CMakeFiles/logger.dir/LogTest.cpp.o
[ 93%] Building CXX object tests/Log/CMakeFiles/logger.dir/__/__/src/Log/Logger.cpp.o
[100%] Linking CXX executable logger
[100%] Built target logger
```

## Running the project

Finaly you can run eigher the project

```./src/cpp-project-template```

----

$\color{#008dff}{\Large Credits}$

Author: [@remi-boivin](https://github.com/remi-boivin)

$\color{#008080}{ Special}$ $\color{#008080}{ \quad thanks}$ $\color{#008080}{ \quad to}$
-