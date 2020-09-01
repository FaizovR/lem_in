cmake_minimum_required(VERSION 3.17)
project(lem_in)

add_compile_options(-Wall -Wextra -Werror -g)
set(CMAKE_C_STANDARD 99)

include_directories(
        includes
        libft/
)

link_directories(lem_in
        libft)

add_executable(lem_in
        srcs/lem_in.c
        srcs/algorithm/dinic.c
        srcs/utils/handle_error.c
        srcs/graph/create_room.c
        srcs/graph/add_link.c
        srcs/graph/get_room.c srcs/graph/bfs.c)

target_link_libraries(lem_in
        "ft"
        )