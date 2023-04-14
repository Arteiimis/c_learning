cmake_minimum_required(VERSION 3.10)

project(time)
set(CMAKE_CXX_STANDARD 11)
add_executable(time exp_104.cpp htime.cpp htime.h)

target_compile_definitions(time PRIVATE -DDEBUG)