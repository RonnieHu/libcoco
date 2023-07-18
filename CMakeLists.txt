cmake_minimum_required(VERSION 2.8)
project(libcoco)

# Set lib version
set(LIBCOCO_VERSION 1.0)

# Use c and asm
enable_language(C ASM)

set(CMAKE_CXX_FLAGS "-lpthread -ldl -g")

aux_source_directory(${PROJECT_SOURCE_DIR}/libcoco src)

add_library(cocolib_shared SHARED ${src})
set_target_properties(cocolib_shared PROPERTIES OUTPUT_NAME coco)

set_target_properties(cocolib_shared PROPERTIES VERSION ${LIBCOCO_VERSION} SOVERSION ${LIBCOCO_VERSION})

option(JUST_TEST "test a demo" OFF)
if (JUST_TEST)
    add_executable("test" ${PROJECT_SOURCE_DIR}/test/test.cc)
    target_link_libraries("test" cocolib_shared pthread dl)
endif()