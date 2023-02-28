cmake_minimum_required(VERSION 3.15)

project(logger VERSION 1.0.0)

add_library(logger STATIC
    Logger.cpp
    lal_bridge/lalfactory.cpp
)

target_include_directories(logger PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link the date library with logger
target_link_libraries(logger date)

target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/../date/include)

# Set any additional compiler flags you need for your library
target_compile_options(logger PRIVATE
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
