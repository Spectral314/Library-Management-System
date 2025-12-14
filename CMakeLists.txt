cmake_minimum_required(VERSION 3.10)
project(Library)

add_executable(program
    main.cpp
    src/ui/MainMenu.cpp
    src/core/UserManager.cpp
    src/core/BookManager.cpp
)