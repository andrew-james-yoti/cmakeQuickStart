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
endif()

# add the executable
add_executable(${This} HelloWorld.cpp)

target_link_libraries(${This} PUBLIC ${EXTRA_LIBS})

target_include_directories(
    ${This}
    PUBLIC
    "${PROJECT_BINARY_DIR}"
)

install(TARGETS ${This} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/HelloWorldConfig.h" DESTINATION include)

enable_testing()

add_test(NAME Runs COMMAND ${This} 25)

# does the usage message work?
add_test(NAME Usage COMMAND ${This})
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
)

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
  )
endfunction(do_test)

# do a bunch of result based tests
do_test(${This} 4 "4 is 2")
do_test(${This} 9 "9 is 3")
do_test(${This} 5 "5 is 2.236")
do_test(${This} 7 "7 is 2.645")
do_test(${This} 25 "25 is 5")
do_test(${This} -25 "-25 is [-nan|nan|0]")
do_test(${This} 0.0001 "0.0001 is 0.01")
