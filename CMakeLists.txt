cmake_minimum_required(VERSION 3.9)
project(MinesWeeper)

set(CMAKE_CXX_STANDARD 11)

add_executable(MinesWeeper main.cpp Board.cpp Board.h Game.cpp Game.h MineBox.cpp MineBox.h EmptyBox.cpp EmptyBox.h Box.cpp Box.h)