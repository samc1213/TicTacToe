cmake_minimum_required(VERSION 2.8.9)
project (tictactoe)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build )

add_executable(tictactoe ${SOURCES})
