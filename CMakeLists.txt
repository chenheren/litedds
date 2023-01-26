cmake_minimum_required(VERSION 3.8)
project(litedds)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
add_library(litedds SHARED ${SRCS})
target_include_directories(litedds INTERFACE $<INSTALL_INTERFACE:include>)

OPTION(BUILD_EXAMPLES "enable examples" ON)
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

OPTION(BUILD_UNITTEST "enable unit tests" ON)
if(BUILD_UNITTEST)
    add_subdirectory(unit_test)
endif()

