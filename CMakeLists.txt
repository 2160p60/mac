cmake_minimum_required(VERSION 3.15)
project(macos_ui_plugin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Проверка obs_DIR
if(NOT obs_DIR)
    message(FATAL_ERROR "obs_DIR is not set. Please set it to your OBS SDK directory.")
endif()

find_package(obs REQUIRED)

add_library(macos_ui_plugin SHARED macos_ui_plugin.cpp)

target_include_directories(macos_ui_plugin PRIVATE ${obs_INCLUDE_DIRS})
target_link_libraries(macos_ui_plugin ${obs_LIBRARIES})

if(WIN32)
    target_compile_definitions(macos_ui_plugin PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(macos_ui_plugin PRIVATE PLATFORM_MACOS)
endif()
