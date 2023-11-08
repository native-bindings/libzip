cmake_minimum_required(VERSION 3.5.0)
project(nodelibzip CXX)

set(BUILD_TOOLS OFF)
set(BUILD_EXAMPLES OFF)
set(BUILD_DOC OFF)
set(BUILD_REGRESS OFF)

if(NOT CMAKE_JS_VERSION)
    set(CMAKE_JS_INC ${CMAKE_CURRENT_SOURCE_DIR}/node_modules/nan)
endif()

add_subdirectory(deps/libzip-1.10.1)
add_subdirectory(core)
add_subdirectory(src)
