#include "lem_in.h"

int		bfs(t_list *graph, t_data_dinic *data, int v_size)
{
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
		u = queue[head++];
		j = 0;
		while (j < graph[u].ed_num)
		{
			v = graph[u].edges[j++];
			if (distance[v] == 0 && v != 0)
			{
				distance[v] = distance[u] + 1;
				queue[end] = v;
				end++;
			}
		}
	}
	return (distance[count_v - 1]);
}