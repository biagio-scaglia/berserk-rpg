cmake_minimum_required(VERSION 3.20)
project(berserk C)

set(CMAKE_C_STANDARD 11)

add_executable(berserk
        main.c
        player.c
        personaggi.c
        combattimento.c
)

target_include_directories(berserk PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(UNIX OR MINGW)
    target_compile_definitions(berserk PRIVATE COLORI)
endif()