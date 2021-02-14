# C++

## Cmake

- Install cmake
- Download and install https://cmake.org/
- Add cmake to path: `/Applications/CMake.app/Contents/bin`
- Check installation
```
cmake --version
```

### Tutorial

- [Tutorial Files](https://gitlab.kitware.com/cmake/cmake/-/tree/master/Help/guide/tutorial)
- [CMake Tutorial](https://cmake.org/cmake/help/v3.19/guide/tutorial/index.html)

---

## Setup

Create a folder ‘cmakeQuickStart’
Add a subfolder called ‘build’ - this is where the executable will go

Add file CMakeLists.txt

```
cmake_minimum_required(VERSION 3.10)

set(This HelloWorld)

# set the project name
project(${This})

# add the executable
add_executable(${This} HelloWorld.cpp)
```

Add HelloWorld.cpp

```
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World" << endl;
}
```

In CMake UI
Set ‘Where is Source Code’
Set ‘Where to build the binaries’

Click the configure button
Click the Generate button

~~Navigate to the build directory in terminal~~
~~Run the ‘make’ command~~

~~The executable will be generated in the build directory~~

```shell script
cmake . -DUSE_MYMATH=ON
```

```shell script
cmake --build .
```

```shell script
./HelloWorld
```



## Google test

```shell script
git clone https://github.com/google/googletest.git
```