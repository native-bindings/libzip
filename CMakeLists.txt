cmake_minimum_required(VERSION 3.5.0)
project(nodelibzip CXX)

set(BUILD_TOOLS OFF)
set(BUILD_EXAMPLES OFF)
set(BUILD_DOC OFF)
set(BUILD_REGRESS OFF)

add_subdirectory(deps/libzip-1.10.1)

if(NOT CMAKE_JS_VERSION)
    set(CMAKE_JS_INC ${CMAKE_CURRENT_SOURCE_DIR}/node_modules/nan)
endif()

add_library(nodelibzip SHARED main.cpp ${CMAKE_JS_SRC})
target_include_directories(nodelibzip PRIVATE ${CMAKE_JS_INC} $ENV{NVM_INC})
target_link_libraries(nodelibzip PRIVATE ${CMAKE_JS_LIB} zip)
if(CMAKE_JS_VERSION)
    set_target_properties(nodelibzip PROPERTIES PREFIX "" SUFFIX ".node")
endif()
