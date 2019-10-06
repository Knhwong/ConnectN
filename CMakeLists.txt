cmake_minimum_required(VERSION 3.13)
project(NCursesConnectN.out C)
add_compile_options(-Wall -Werror)

set(CMAKE_C_STANDARD 11)

set(CURSES_USE_NCURSES TRUE)
set(CMAKE_CXX_FLAGS "-lncurses")
find_package(Curses REQUIRED)

add_executable(NCursesConnectN.out main.c Board.c Board.h Play.c Play.h View.c View.h Win.c Win.h move.c move.h)
target_link_libraries(NCursesConnectN.out PRIVATE ${CURSES_LIBRARIES})
target_include_directories(NCursesConnectN.out PRIVATE ${CURSES_INCLUDE_DIRS})