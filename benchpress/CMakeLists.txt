cmake_minimum_required(VERSION 3.18)

file(GLOB BENCHPRESS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp)
file(GLOB BENCHPRESS_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/**/*.h)

# https://youtu.be/nXaxk27zwlk?t=964
add_compile_options(-fno-exceptions -fno-rtti)
add_compile_options(-fno-omit-frame-pointer)

add_executable(benchpress src/main.cpp ${BENCHPRESS_SOURCES})
target_compile_options(benchpress PUBLIC -fno-exceptions)
target_compile_options(benchpress PUBLIC -fno-rtti)
target_compile_options(benchpress PUBLIC -fno-omit-frame-pointer)
target_link_libraries(benchpress benchmark::benchmark bplib)