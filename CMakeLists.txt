cmake_minimum_required(VERSION 3.18)
project(benchpress VERSION 0.0.1)

add_compile_options(-std=c++17 -O3)
add_compile_options(-march=x86-64)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_subdirectory(thirdparty)
add_subdirectory(benchpress)
add_subdirectory(bplib)
add_subdirectory(test)