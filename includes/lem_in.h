#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H

#include "libft.h"

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
	t_list		*edges;
}					t_room;

typedef struct		s_data_dinic
{
	int		*distance;
	int		*queue_stack;
	char		*visited;
	int		end;
	int		vertex;
}					t_data_dinic;

typedef struct		s_path
{
	int				*path;
	int				length;
	struct s_path	*next;
}					t_path;

/*
 * Utils
 * */

void	print_error(int id);

/*
 * Graph
 * */

t_room	*create_room(char *name, int id);
t_room	*get_room_from_id(t_list *rooms, int id);
void	add_link(t_list *graph, char *s, char *t);

/*
 * Parser
 * */


#endif