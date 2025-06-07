cmake_minimum_required(VERSION 3.15)

project(macos_ui_plugin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Путь к OBS SDK должен быть передан в obs_DIR
find_package(obs REQUIRED)

set(SOURCES
    src/macos_ui_plugin.cpp
    # добавь остальные .cpp если есть
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${obs_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${obs_LIBRARIES})

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE "OBS_PLUGIN_EXPORTS")

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()
