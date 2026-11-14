cmake_minimum_required(VERSION 3.20)

project(lol LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(engine STATIC ${ENGINE_SOURCES})

target_include_directories(engine PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/magic_enum-v0.9.8/include"
)

add_executable(game main.cpp)

target_link_libraries(game PRIVATE engine)

if(MSVC)
    target_compile_options(engine PRIVATE /W4 /EHsc)
    target_compile_options(game PRIVATE /W4 /EHsc)
else()
    target_compile_options(engine PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(game PRIVATE -Wall -Wextra -Wpedantic)
endif()
