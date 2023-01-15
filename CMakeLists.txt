cmake_minimum_required(VERSION 3.8)
project(litedds)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
add_library(litedds SHARED library.cpp library.h)
target_include_directories(litedds INTERFACE $<INSTALL_INTERFACE:include>)
target_link_directories(litedds INTERFACE $<INSTALL_INTERFACE:lib>)