# cmake_minimum_required(VERSION 3.10)

# set(This HelloWorld)

# # set the project name
# project(${This})

# # set the project name and version
# project(${This} VERSION 1.0)

# # specify the C++ standard
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure_file(HelloWorld.h.in HelloWorld.h)

# # add the executable
# add_executable(${This} HelloWorld.cpp)

# target_include_directories(${This} PUBLIC "${PROJECT_BINARY_DIR}")

cmake_minimum_required(VERSION 3.10)
option(USE_MYMATH "Use tutorial provided math implementation" ON)

set(This HelloWorld)

# set the project name
project(${This})

# set the project name and version
project(${This} VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# configure a header file to pass some of the CMake settings
# to the source code
configure_file(HelloWorldConfig.h.in HelloWorldConfig.h)



configure_file(HelloWorld.h.in HelloWorld.h)

if(USE_MYMATH)
  add_subdirectory(MathsFunctions)
  list(APPEND EXTRA_LIBS MathsFunctions)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathsFunctions")
endif()

# add the executable
add_executable(${This} HelloWorld.cpp)

target_link_libraries(${This} PUBLIC ${EXTRA_LIBS})

target_include_directories(
    ${This}
    PUBLIC
    "${PROJECT_BINARY_DIR}"
    ${EXTRA_INCLUDES}
)