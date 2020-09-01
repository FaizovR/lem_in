#include "lem_in.h"

void		init_data(t_data_dinic *data, int v_size, int t)
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

void		free_dinic(t_data_dinic *data)
{
	free(data->visited);
	free(data->distance);
	free(data->queue_stack);
}

t_path *dinic(t_list *graph, int v_size, int t)
{
	t_data_dinic	data;
	t_path			*paths;
	int				length;

	paths = NULL;
	init_data(&data, v_size, t);
//	while ()
//	{
//
//	}

	free_dinic(&data);
	return (paths);
}