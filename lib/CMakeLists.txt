cmake_minimum_required(VERSION 3.15)

project(common VERSION 1.0.0)

add_library(common STATIC
    src/array.cpp
)

# Set the include directories
target_include_directories(common PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set any additional compiler flags you need for your library
target_compile_options(common PRIVATE
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


# Install the library
install(TARGETS common
    DESTINATION bin
)

set_target_properties(common PROPERTIES ENABLE_EXPORTS ON)