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
        srcs/algorithm/bfs.c
        srcs/algorithm/find_path.c
        srcs/algorithm/path.c
        srcs/graph/create_room.c
        srcs/graph/add_link.c
        srcs/graph/get_room.c
        srcs/graph/delete_vertex.c
        srcs/ft_vector/vector_free.c
        srcs/ft_vector/vector_get.c
        srcs/ft_vector/vector_init.c
        srcs/ft_vector/vector_pop_back.c
        srcs/ft_vector/vector_push_back.c
        srcs/ft_vector/vector_resize.c
        srcs/ft_vector/vector_set.c
        srcs/ft_vector/vector_erase.c
        srcs/ft_vector/vector_erase_if.c
        srcs/utils/stack.c
        srcs/utils/handle_error.c
        srcs/utils/print_graph.c srcs/utils/ft_lstrev.c)

target_link_libraries(lem_in
        "ft"
        )