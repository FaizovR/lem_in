#include "lem_in.h"

t_room *create_room(char *name, int id)
{
	t_room	*new_room;

	new_room = NULL;
	if (!(new_room = (t_room*)malloc(sizeof(t_room))))
		print_error(1);
	new_room->name = ft_strdup(name);
	new_room->edges_number = 0;
	new_room->id = id;
	new_room->edges = NULL;
	return (new_room);
}
