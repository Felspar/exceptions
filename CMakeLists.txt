cmake_minimum_required(VERSION 3.14...3.28)
project(felspar-exceptions LANGUAGES CXX)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    add_custom_target(felspar-check)
    include(requirements.cmake)
endif()

add_library(felspar-exceptions INTERFACE)
target_include_directories(felspar-exceptions INTERFACE include)
target_compile_features(felspar-exceptions INTERFACE cxx_std_20)
target_link_libraries(felspar-exceptions INTERFACE felspar-test)
install(DIRECTORY ./include/felspar TYPE INCLUDE)

if(TARGET felspar-check)
    set_property(TARGET felspar-check PROPERTY EXCLUDE_FROM_ALL TRUE)
    add_subdirectory(test)
endif()
