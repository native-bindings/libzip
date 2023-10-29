add_library(
    nodelibzip SHARED
    ${CMAKE_JS_SRC}
    main.cpp
    Archive.cpp
    Constants.cpp
    Archive.h
    Arguments.cpp
    Arguments.h
    File.cpp
    File.h
    Stat.cpp
    Stat.h
)
target_include_directories(nodelibzip PRIVATE ${CMAKE_JS_INC} $ENV{NVM_INC})
target_link_libraries(nodelibzip PRIVATE ${CMAKE_JS_LIB} zip)
if(CMAKE_JS_VERSION)
    set_target_properties(nodelibzip PROPERTIES PREFIX "" SUFFIX ".node")
endif()
target_compile_options(nodelibzip PRIVATE -Wall -Werror -Wfatal-errors)
