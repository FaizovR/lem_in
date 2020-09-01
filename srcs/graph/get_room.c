#include "lem_in.h"

t_room *get_room_from_id(t_list *rooms, int id) {
	t_room	*room;

	while (rooms != NULL)
	{
		room = (t_room *)rooms->content;
		if (room->id == id)
			return (room);
		rooms = rooms->next;
	}
	return (NULL);
}
