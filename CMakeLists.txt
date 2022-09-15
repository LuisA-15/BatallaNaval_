cmake_minimum_required(VERSION 3.21)
project(BatallaNaval_ C)

set(CMAKE_C_STANDARD 99)

include_directories(Header)
add_executable(BatallaNaval_ main.c Header/Board.h Header/Structs.h)
