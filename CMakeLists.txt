cmake_minimum_required(VERSION 3.24)
project(progress_bar)

set(CMAKE_CXX_STANDARD 20)

add_executable(progress_bar
        main.cpp pbar.cpp pbar.h)

