cmake_minimum_required(VERSION 3.8)

find_package(GTest REQUIRED)

file(GLOB SERVER_UNITTEST_SRCS ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
foreach (filename IN LISTS SERVER_UNITTEST_SRCS)
    get_filename_component(target ${filename} NAME_WE)
    add_executable(${target} ${filename})
    target_link_libraries(${target} PUBLIC GTest::Main litedds)
    gtest_add_tests(TARGET ${target})
endforeach ()
