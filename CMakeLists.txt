cmake_minimum_required(VERSION 3.17)
project(j3de_native)

set(CMAKE_CXX_STANDARD 20)

find_package(Java REQUIRED)
find_package(JNI REQUIRED)

if (NOT JNI_FOUND)
    message(FATAL_ERROR "JNI not found")
endif()

# generate jni header files command target
set(JAVAH j3de_generate_header)
set(CMAKE_STUB_DIR ${PROJECT_SOURCE_DIR}/cmake-stub)
set(JNI_SOURCE_PROJECT ${PROJECT_SOURCE_DIR}/../zx-j3de)
set(JNI_SOURCE_DIR ${JNI_SOURCE_PROJECT}/src/main/java/ch/zxseitz/j3de/math/*.java)
add_custom_target(${JAVAH}
        COMMAND ${Java_JAVAC_EXECUTABLE} -h ${PROJECT_SOURCE_DIR}/header ${JNI_SOURCE_DIR} -d ${CMAKE_STUB_DIR}
)

# build shared library
include_directories(${JNI_INCLUDE_DIRS})
file(GLOB SOURCE_FILES source/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

add_dependencies(${PROJECT_NAME} ${JAVAH})