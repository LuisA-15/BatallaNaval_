cmake_minimum_required(VERSION 3.21)
project(BatallaNaval_ C)

set(CMAKE_C_STANDARD 99)

include_directories(headers)
add_executable(BatallaNaval_ src/main.c src/board.c src/mechanics.c)
