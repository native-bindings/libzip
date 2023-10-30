cmake_minimum_required(VERSION 3.5.0)
project(nodelibzip CXX)

if(NOT CMAKE_JS_VERSION)
    set(CMAKE_JS_INC ${CMAKE_CURRENT_SOURCE_DIR}/node_modules/nan)
endif()

add_subdirectory(deps)
add_subdirectory(src)
