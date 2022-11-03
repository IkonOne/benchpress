cmake_minimum_required(VERSION 3.18)

file(GLOB BENCHPRESS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp)
file(GLOB BENCHPRESS_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/**/*.h)

# https://youtu.be/nXaxk27zwlk?t=964
add_compile_options(-std=c++17 -O3)
add_compile_options(-march=x86-64)
# add_compile_options(-stdlib=libc++) # -lc++abi)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)
add_compile_options(-fno-exceptions -fno-rtti)
add_compile_options(-fno-omit-frame-pointer)

add_executable(benchpress src/main.cpp ${BENCHPRESS_SOURCES})
target_link_libraries(benchpress benchmark::benchmark)