cmake_minimum_required(VERSION 3.24)
project(Labs C)

set(CMAKE_C_STANDARD 23)

add_executable(Labs main.c)


add_subdirectory(libs)
target_link_libraries(Labs data_structures)
target_link_libraries(Labs algorithms)
target_link_libraries(Labs string_)
