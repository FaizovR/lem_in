#include "lem_in.h"

void delete_links(t_list *edges) {
	t_list *temp;

	temp = edges;
	while (temp)
	{
		((t_room*)temp->content)->edges_number--;
		temp = temp->next;
	}
}

void delete_vertex(t_list *graph, int id) {
	t_room *room;

	t_room *temp_room;

	room = get_room_from_id(graph, id);
	int i = 0;
	while (i < room->edges_number) {
		temp_room = get_room_from_id(graph, *(int *)vector_get(room->edges,i));
		vector_erase_if(temp_room->edges, id);
		temp_room->edges_number--;
		i++;
	}
	room->edges_number = 0;
}