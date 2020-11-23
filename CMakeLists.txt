cmake_minimum_required(VERSION 3.17)
project(j3de_native)

set(CMAKE_CXX_STANDARD 20)

find_package(Java REQUIRED)
find_package(JNI REQUIRED)

include_directories(${JNI_INCLUDE_DIRS})
set(SOURCE_FILES ch_zxseitz_j3de_math_Matrix4.cpp)
add_library(j3de_native SHARED ${SOURCE_FILES})