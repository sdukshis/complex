cmake_minimum_required(VERSION 2.8)

project(Complex CXX)

option(COVERALLS "Turn on coveralls support" OFF)
option(COVERALLS_UPLOAD "Upload the generated coveralls json" ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} 
    ${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake)

if (COVERALLS)
    include(Coveralls)
    coveralls_turn_on_coverage()
endif()


if (MSVC)
    add_definitions(/W4)
else()
    add_definitions(-Wall)
    add_definitions(-std=c++11)
endif()


if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if (COVERALLS)
        include(Coveralls)
        coveralls_turn_on_coverage()
    endif()

    if (COVERALLS)
        coveralls_setup(
            "include/complex.h" 
            ${COVERALLS_UPLOAD}                 
            "${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake")
    endif()
endif()

include_directories(Catch/include)
include_directories(include)

enable_testing()

add_executable(test_complex tests/test_complex.cpp)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(test_complex gcov)
endif()

add_test(NAME ${PROJECT_NAME} COMMAND test_complex)
