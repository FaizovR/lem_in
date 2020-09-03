#include "lem_in.h"

int main() {
	t_list *graph;
	t_list *tmp;

	graph = NULL;
	tmp = ft_lstnew(create_room("1", 0), sizeof(t_room));
	ft_lstadd(&graph, tmp);
	tmp = ft_lstnew(create_room("2", 1), sizeof(t_room));
	ft_lstadd(&graph, tmp);
	tmp = ft_lstnew(create_room("3", 2), sizeof(t_room));
	ft_lstadd(&graph, tmp);
	tmp = ft_lstnew(create_room("4", 3), sizeof(t_room));
	ft_lstadd(&graph, tmp);
	tmp = ft_lstnew(create_room("5", 4), sizeof(t_room));
	ft_lstadd(&graph, tmp);
	tmp = ft_lstnew(create_room("6", 5), sizeof(t_room));
	ft_lstadd(&graph, tmp);
	tmp = ft_lstnew(create_room("7", 6), sizeof(t_room));
	ft_lstadd(&graph, tmp);

	add_link(graph, "1", "2");
	add_link(graph, "1", "3");
	add_link(graph, "2", "5");
	add_link(graph, "3", "4");
	add_link(graph, "4", "5");
	add_link(graph, "4", "6");
	add_link(graph, "5", "7");
	add_link(graph, "6", "7");
	ft_lstrev(&graph);

	dinic(graph, 7, 6);
	return 0;
}
