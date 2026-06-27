cmake_minimum_required(VERSION 3.21...3.31)

project(mcpelauncherpaneltest)

if(NOT CMAKE_ANDROID_ARCH_ABI MATCHES "^(x86_64|arm64-v8a)$")
    message(FATAL_ERROR "Unsupported ABI")
endif()

set(CMAKE_CXX_STANDARD 23)

add_library(mcpelauncherpaneltest SHARED
    src/main.cpp
    src/menu.hpp
)

target_compile_options(mcpelauncherpaneltest PRIVATE -Wall -Wextra -Wpedantic -fdeclspec)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(mcpelauncherpaneltest PRIVATE -flto)
    target_link_options(mcpelauncherpaneltest PRIVATE
        -flto -Wl,--version-script,${PROJECT_SOURCE_DIR}/map.txt -Wl,--no-undefined-version)
    set_target_properties(mcpelauncherpaneltest PROPERTIES
        LINK_DEPENDS ${PROJECT_SOURCE_DIR}/map.txt)
endif()

install(TARGETS mcpelauncherpaneltest LIBRARY DESTINATION mods)
