#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H

# include "libft.h"
# include <stdio.h>
# include <lem_in.h>
# include "ft_vector.h"

typedef struct		s_lemin
{
	int	ant_num;
	int	room_num;
	int	edges_num;
	int	start_num;
	int	end_num;
	int	lines_count;
}					t_lemin;

typedef struct		s_room
{
	int		id;
	char	*name;
	int		edges_number;
	t_vector	*edges;
}					t_room;

typedef struct		s_data
{
	int		*distance;
	int		*queue_stack;
	char	*visited;
	int		end;
	int		vertex;
}					t_data;

typedef struct		s_path
{
	int				*path;
	int				length;
	int				prior;
	int				*ants;
	int				last_ant;
}					t_path;

/*
 * Algorithm
 * */

int		bfs(t_list *graph, t_data *data, int v_size);
t_path	*dinic(t_list *graph, int v_size, int t);
int		find_path(int start, t_list *graph, t_data data);
int		*set_path(int len, int *stack_path, t_list *graph, int end);
t_path	*create_path(int *path, int length_path);

/*
 * Utils
 * */

void	print_graph(t_list *graph, int v_size);
void	print_error(int id);
int		stack_pop(int *top, int *start, t_data *data);
void	ft_lstrev(t_list **list);

/*
 * Graph
 * */

void	delete_vertex(t_list *graph, int id);
void	delete_links(t_list *edges);
t_room	*create_room(char *name, int id);
t_room	*get_room_from_id(t_list *rooms, int id);
t_room	*get_room_from_name(t_list *rooms, char *name);
t_room	*get_room_from_index(t_list *rooms, int index);
void	add_link(t_list *graph, char *s, char *t);

/*
 * Parser
 * */

#endif