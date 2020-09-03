#include "lem_in.h"

int bfs(t_list *graph, t_data *data, int v_size) {
	int j;
	int v;
	int u;
	int head;
	int end;

	head = 0;
	data->queue_stack[0] = 0;
	end = 1;
	while (head < v_size)
	{
		u = data->queue_stack[head++];
		j = 0;
		while (j < get_room_from_id(graph, u)->edges_number)
		{
			v = *(int *)vector_get(get_room_from_id(graph, u)->edges, j);
			j++;
			if (data->distance[v] == 0 && v != 0)
			{
				data->distance[v] = data->distance[u] + 1;
				data->queue_stack[end] = v;
				end++;
			}
		}
	}
	return (data->distance[v_size - 1]);
}
