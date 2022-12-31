cmake_minimum_required(VERSION 3.10)

project(NUMBER_GUESSING_GAME CXX)

add_executable(guessnum guessnum.cpp)

add_compile_options(guessnum PUBLIC cxx_std_11 Wall)
