#include "lem_in.h"

/*static void		handle_link(t_list *rooms, char *line)
{
	t_list	*tmp;
	char	**words;
	t_room	*room1;
	t_room	*room2;

	words = ft_strsplit(line, '-');
	if (count_words(words) != 2)
		ft_throw(LINK_MSG, E_INPUT);
	room1 = get_room(rooms, words[0]);
	room2 = get_room_from_id(rooms, words[1]);
	if (room1 == NULL || room2 == NULL)
		ft_throw(LINK_MSG, E_INPUT);
	tmp = ft_lstnew(room2, sizeof(t_room));
	if (tmp == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	ft_lstadd(&room1->neighbors, tmp);
	tmp = ft_lstnew(room1, sizeof(t_room));
	if (tmp == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	ft_lstadd(&room2->neighbors, tmp);
	free(line);
}*/

void	add_link(t_list *graph, char *s, char *t)
{
	t_room		*room1;
	t_room		*room2;

	room1 = get_room_from_name(graph, s);
	room2 = get_room_from_name(graph, t);
	if (!room1 || !room2)
		print_error(7);
	room1->edges_number++;
	room2->edges_number++;
	room1->edges->push_back(room1->edges, (void *)&room2->id);
	room2->edges->push_back(room2->edges, (void *)&room1->id);
}
