cmake_minimum_required(VERSION 3.15)

project(parser VERSION 1.0.0)

add_library(parser STATIC
    Parser.cpp
)

# add the path to the external libraries
link_directories(../lib/build)
find_library(COMMON_LIB libcommon.a PATHS ../lib/build)

# check if the library was found
if (NOT COMMON_LIB)
    message(FATAL_ERROR "Could not find common library")
endif()

target_link_libraries(parser common)
# Set the include directories
target_include_directories(parser PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include
../../lib/include
)

# Set any additional compiler flags you need for your library
target_compile_options(parser PRIVATE
-Wall
-Wextra
-pedantic
-Werror
-Wconversion
-std=c++17
-Wshadow
)

# Set additional compiler flags specific to a build type
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fno-omit-frame-pointer" )
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
else()
    message(FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}")
endif()
