cmake_minimum_required(VERSION 2.8)

project(Complex CXX)

add_definitions(-Wall -std=c++11)

include_directories(Catch/include)
include_directories(include)

enable_testing()

add_executable(test_complex tests/test_complex.cpp)

add_test(NAME ${PROJECT_NAME} COMMAND test_complex)
