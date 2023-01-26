cmake_minimum_required(VERSION 3.8)
project(HelloWorld)

add_executable(talker talker.cpp)
target_link_libraries(talker litedds)

add_executable(listener listener.cpp)
target_link_libraries(listener litedds)