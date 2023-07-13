cmake_minimum_required(VERSION 3.23)
project(ObjectPool)

set(cmake_cxx_standard 20)

include_directories(include)
aux_source_directory(include, INCLUDE_DIR)
aux_source_directory(src, SRC_DIR)

add_executable(ObjectPool ${INCLUDE_DIR} ${SRC_DIR} src/TestObj.cpp include/ObjectPool1.hpp include/ObjectPool2.hpp include/ObjectPool3.hpp)