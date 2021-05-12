cmake_minimum_required(VERSION 3.19)
project(acronis)

set(CMAKE_CXX_STANDARD 20)

add_executable(acronis main.cpp tokenizer.h tokenizer.cpp derivative_calculator.h vector.h any.cpp types.h functions.h operators.h)