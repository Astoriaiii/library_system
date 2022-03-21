cmake_minimum_required(VERSION 3.21)
project(library_system C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(library_system
        book_management.h
        librarian.c
        menu.c
        search_book.c
        user.c
        user_register.c)
