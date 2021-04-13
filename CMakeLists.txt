cmake_minimum_required(VERSION 3.16)

project(tracing
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.h")

add_executable(tracing
    ${SRCS}
)

target_include_directories(tracing PUBLIC ${CMAKE_SOURCE_DIR}/src)
