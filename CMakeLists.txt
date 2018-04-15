cmake_minimum_required(VERSION 3.0)

project(nnants)
set(CMAKE_C_FLAGS -g)
include_directories(src)
# subdirs(src)
add_executable(app 
    src/main.c 
    src/colony.c
    src/ant.c
    src/kann.c
    src/kautodiff.c
)

target_link_libraries(app m SDLmain SDL)
