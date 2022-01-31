cmake_minimum_required(VERSION 3.20)
project(last C)

set(CMAKE_C_STANDARD 99)

add_executable(last main.c libs/data_structures/bitset/bitset.c libs/data_structures/bitset/bitset.h)

add_subdirectory(libs)
target_link_libraries(last data_structures)
target_link_libraries(last algorithms)