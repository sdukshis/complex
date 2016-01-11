cmake_minimum_required(VERSION 2.8)

project(Complex CXX)

if (MSVC)
    add_definitions(/W4)
else()
    add_definitions(-Wall)
    add_definitions(-std=c++11)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_definitions(-fprofile-arcs)
    add_definitions(-ftest-coverage)
endif()

include_directories(Catch/include)
include_directories(include)

enable_testing()

add_executable(test_complex tests/test_complex.cpp)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(test_complex gcov)
endif()

add_test(NAME ${PROJECT_NAME} COMMAND test_complex)
