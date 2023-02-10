# build the unit test executable.
set(CURRENT_EXE_NAME logger)
set(SOURCE_FILES
    main.cpp
    LogTest.cpp
    ../../src/Log/Logger.cpp
    )
add_executable(${CURRENT_EXE_NAME} ${SOURCE_FILES})
add_dependencies(${CURRENT_EXE_NAME} cpputest)
target_include_directories(${CURRENT_EXE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${CURRENT_EXE_NAME} CppUTest CppUTestExt)
include_directories("../../includes")
include_directories("../includes")

# Enable code coverage
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Enable code coverage
if(CMAKE_BUILD_TYPE MATCHES "Debug")
  if (CMAKE_CXX_COMPILER MATCHES "clang")
    set (CMAKE_CXX_COMPILER "/usr/bin/clang++-12")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")
  elseif(CMAKE_BUILD_TOOL MATCHES "gcc")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")
  endif()
endif()

# add the test to the project to be run by ctest.
add_test(logger_test ${CURRENT_EXE_NAME})