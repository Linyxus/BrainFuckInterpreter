cmake_minimum_required(VERSION 3.8)
project(bf_interpreter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp sources/Parse.h Parse.cpp sources/Controller.h Controller.cpp Run.cpp sources/Run.h)
add_executable(bf_interpreter ${SOURCE_FILES})