add_compile_options(-Wall -Wextra -pedantic -Werror -Wconversion -std=c++17 -Wshadow)
set(CURRENT_EXE_NAME cpp-project-template)
set(SOURCE_FILES main.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories("../includes")
include_directories("include")
include_directories("pal")
include_directories("Parser/pal_bridge")
include_directories("../lib/include")
add_executable(${CURRENT_EXE_NAME} ${SOURCE_FILES})
include_directories("/usr/include/c++/11")

# include logger library
add_subdirectory(Date/)
# include logger library
add_subdirectory(Log/)

# include parser library
add_subdirectory(Parser/)

# link against math date logger library.
target_link_directories(${CURRENT_EXE_NAME} PRIVATE /home/remi/Informatique/System/cpp-project-template/lib/build)
target_link_libraries(${CURRENT_EXE_NAME} m logger parser)
install(TARGETS ${CURRENT_EXE_NAME} DESTINATION bin)

if (CMAKE_BUILD_COMPILER MATCHES "clang")
    set (CMAKE_BUILD_COMPILER "/usr/bin/clang++")
elseif(CMAKE_BUILD_COMPILER MATCHES "gcc")
    set (CMAKE_BUILD_COMPILER "/usr/bin/g++")
endif()

# Set additional compiler flags specific to a build type
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fno-omit-frame-pointer" )
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
else()
    message(FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}")
endif()
