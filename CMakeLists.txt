cmake_minimum_required(VERSION 2.8.9)
project(sharedobjects)
find_package (Threads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(GLOB SOURCES "source/src/*.cpp" "source/include/*.hpp")
file(GLOB SOURCES_GTEST "source/src/*.cpp" "source/include/*.hpp" "test/*.cpp" "test/*.hpp")
list(REMOVE_ITEM SOURCES_GTEST ${CMAKE_CURRENT_SOURCE_DIR}/source/src/Main.cpp)

include_directories(
  ../deps/gtest-1.7.0/include
  ../deps/gtest-1.7.0)

link_directories(../deps/gtest-1.7.0/src)
ADD_LIBRARY(gtest ../deps/gtest-1.7.0/src/gtest-all.cc)
ADD_LIBRARY(gtest_main ../deps/gtest-1.7.0/src/gtest_main.cc)

add_executable(sharedobjects ${SOURCES})
add_executable(sharedobjects_test ${GTEST} ${SOURCES_GTEST})
target_link_libraries(sharedobjects_test gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})