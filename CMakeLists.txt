cmake_minimum_required(VERSION 3.25)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(SnakeGame Game.cpp Game.h Snake.cpp Snake.h Food.cpp Food.h main.cpp Point.cpp Point.h)
