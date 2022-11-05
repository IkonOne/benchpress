cmake_minimum_required(VERSION 3.18)

file(GLOB_RECURSE BPLIB_SOURCE_FILES src/*.cpp)
file(GLOB_RECURSE BPLIB_INCLUDE_FILES include/*.h)

add_library(bplib INTERFACE)
target_include_directories(bplib INTERFACE include/)
# include_directories(bplib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)