#include "lem_in.h"

t_path *create_path(int *path, int length_path) {
	t_path	*node;

	node = (t_path *)malloc(sizeof(t_path));
	if (!node)
		return (NULL);
	if (!(node->ants = (int *)malloc(sizeof(int) * length_path)))
		return (NULL);
	ft_memset(node->ants,0, length_path);
	node->path = path;
	node->length = length_path;
	node->prior = 0;
	node->last_ant = -1;
	return (node);
}

int *set_path(int len, int *stack_path, t_list *graph, int end) {
	int	i;
	int j;
	int	*path;

	i = 0;
	j = 1;
	if (!(path = (int *)malloc(sizeof(int) * len)))
		return (0);
	while (j < len)
	{
		path[i] = stack_path[j];
		delete_vertex(graph, stack_path[j]);
		i++;
		j++;
	}
	path[i] = end;
	return (path);
}
