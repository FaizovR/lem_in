#include "lem_in.h"

static void		init_data(t_data *data, int v_size, int t)
{
	data->end = t;
	data->vertex = 0;
	if (!(data->visited = ft_strnew(v_size)))
		print_error(1);
	if (!(data->distance = (int *)malloc(sizeof(int) * v_size)))
		print_error(1);
	if (!(data->queue_stack = (int *)malloc(sizeof(int) * v_size)))
		print_error(1);
	ft_memset(data->distance, 0, v_size);
	ft_memset(data->queue_stack, 0, v_size);
}

static void		free_data(t_data *data)
{
	free(data->visited);
	free(data->distance);
	free(data->queue_stack);
}

t_path *dinic(t_list *graph, int v_size, int t) {
	t_data	data;
	t_list			*paths;
	t_path			*old_paths;
	int				length;

	paths = NULL;
	old_paths = NULL;
	init_data(&data, v_size, t);
	while (bfs(graph, &data, v_size))
	{
		ft_memset(data.queue_stack, 0, v_size * sizeof(int ));
		while ((length = find_path(0, graph, data)))
		{
			printf("%d\n", length);
			ft_lstadd(&paths, ft_lstnew(create_path(set_path(length, data.queue_stack, graph, t), length), sizeof(t_path)));
			ft_memset(data.queue_stack, 0, v_size * sizeof(int));
		}
		ft_memset(data.distance, 0, v_size * sizeof(int));
		ft_memset(data.visited, 0, v_size);
	}
	free_data(&data);
	return (old_paths);
}
