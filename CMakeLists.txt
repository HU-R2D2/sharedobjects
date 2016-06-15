cmake_minimum_required(VERSION 2.8.9)
project(sharedobjects)
find_package (Threads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -W -O3 -lpthread -Wall -Wno-comment -Wno-missing-field-initializers  -pedantic -pthread ")

file(GLOB SOURCES "source/include/*.hpp"  "example/*.cpp")
file(GLOB SOURCES_GTEST "source/include/*.hpp" "test/*.cpp" "test/*.hpp")

include_directories(
  ../deps/gtest-1.7.0/include
  ../deps/gtest-1.7.0)

link_directories(../deps/gtest-1.7.0/src)
ADD_LIBRARY(gtest ../deps/gtest-1.7.0/src/gtest-all.cc)
ADD_LIBRARY(gtest_main ../deps/gtest-1.7.0/src/gtest_main.cc)

add_executable(sharedobjects_test ${GTEST} ${SOURCES_GTEST})
add_executable(sharedobjects_example ${SOURCES})
target_link_libraries(sharedobjects_test gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
