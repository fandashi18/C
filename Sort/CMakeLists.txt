cmake_minimum_required(VERSION 3.17)
project(Sort)

set(CMAKE_CXX_STANDARD 11)

add_executable(Sort main.cpp insert/Straight.h insert/Straight.cpp insert/Bin.cpp insert/Bin.h insert/Shell.cpp insert/Shell.h swap/Bubble.cpp swap/Bubble.h)