add_library(
    nodelibzip SHARED
    ${CMAKE_JS_SRC}
    main.cpp
    Archive.cpp
    Constants.cpp
    Archive.h
    File.cpp
    File.h
    Stat.cpp
    Stat.h
    Source.cpp
    Source.h
)
target_include_directories(nodelibzip PRIVATE $ENV{NVM_INC})
target_link_libraries(nodelibzip PRIVATE NodeNativeBindingsCore zip)
if(CMAKE_JS_VERSION)
    set_target_properties(nodelibzip PROPERTIES PREFIX "" SUFFIX ".node")
endif()
target_compile_options(nodelibzip PRIVATE -Wall -Werror -Wfatal-errors -Werror=sign-compare)
