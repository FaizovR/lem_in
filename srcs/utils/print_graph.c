#include "lem_in.h"

void print_graph(t_list *graph, int v_size) {
	t_room	*room;
	t_room	*sub_room;
	int i;
	size_t j;

	j = 0;
	i = 0;
	while (i < v_size)
	{
		room = get_room_from_index(graph, i);
		printf("---------------head------------------\n");
		printf("room->id == %d\n", room->id);
		printf("room->name == %s\n", room->name);
		printf("room->edges_number == %d\n", room->edges_number);
		j = 0;
		while (j < room->edges->size)
		{
			sub_room = vector_get(room->edges, j);
			printf("\n\tedge index == %zu\n", j);
			printf("\tedge sub_room->id == %d\n", sub_room->id);
			printf("\tedge sub_room->name == %s\n\n", sub_room->name);
			j++;
		}
		i++;
		printf("\n\n\n");
	}

}
