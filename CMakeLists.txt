cmake_minimum_required(VERSION 3.15)
project(macos_ui_plugin)

set(CMAKE_CXX_STANDARD 17)

find_package(obs REQUIRED)

include_directories(
    ${OBS_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(macos_ui_plugin MODULE
    macos_ui_plugin.cpp
)

target_link_libraries(macos_ui_plugin
    ${OBS_LIBRARIES}
)
