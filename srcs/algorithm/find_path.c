#include "lem_in.h"

static void	check_distance(int *start, int *top, t_data *data, int u)
{
	if ((data->distance[u] == data->distance[*start] + 1)
		&& (data->visited[u] == '\0'))
	{
		*top += 1;
		data->queue_stack[*top] = u;
		*start = u;
		if (*start != data->end)
			data->visited[*start] = '1';
		data->vertex = 0;
	}
	else
		data->vertex++;
}

int find_path(int start, t_list *graph, t_data data) {
	int u;
	int top;

	data.vertex = 0;
	top = 0;
	data.queue_stack[top] = start;
	while (1)
	{
		while (data.vertex < get_room_from_id(graph, start)->edges_number)
		{
			u = *(int*)vector_get(get_room_from_id(graph, start)->edges, data.vertex);
			check_distance(&start, &top, &data, u);
			if (start == data.end)
				return (top);
		}
		if (data.vertex == get_room_from_id(graph, start)->edges_number)
			if (!stack_pop(&top, &start, &data))
				return (0);
	}
}
