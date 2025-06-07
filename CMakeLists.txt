cmake_minimum_required(VERSION 3.15)

project(macos_ui_plugin LANGUAGES CXX)

# Стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем исходник
add_library(macos_ui_plugin SHARED macos_ui_plugin.cpp)

# На windows назовём библиотеку .dll, на macOS .dylib, на Linux .so — CMake сделает сам

# Опционально: если нужны какие-то include пути, добавь сюда
# target_include_directories(macos_ui_plugin PRIVATE include)

# Опционально: добавь определения, зависящие от платформы
if(WIN32)
    target_compile_definitions(macos_ui_plugin PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(macos_ui_plugin PRIVATE PLATFORM_MACOS)
endif()
