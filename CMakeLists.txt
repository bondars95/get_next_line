cmake_minimum_required(VERSION 3.5)
project(get_next_line)

set(CMAKE_C_FLAGS "-std=c99")
set(SOURCE_FILES main.c get_next_line.h libft.h)
add_executable(get_next_line main.c)
target_link_libraries(get_next_line ${CMAKE_SOURCE_DIR}/libft/libft.a)
