#include "lem_in.h"

t_room *get_room_from_name(t_list *rooms, char *name) {
	t_room	*room;

	while (rooms != NULL)
	{
		room = (t_room *)rooms->content;
		if (ft_strequ(name, room->name))
			return (room);
		rooms = rooms->next;
	}
	return (NULL);
}


t_room *get_room_from_index(t_list *rooms, int index) {
	int		i;

	i = 0;
	while (i < index && rooms!= NULL)
	{
		rooms = rooms->next;
		if (rooms->content != NULL)
			i++;
	}
	if (i == index)
		return ((t_room *)rooms->content);
	else
		return (NULL);
}

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
