#include "lem_in.h"

int stack_pop(int *top, int *start, t_data *data) {
	*top -= 1;
	if (*top == -1) {
		return (0);
	}
	*start = data->queue_stack[*top];
	data->vertex = 0;
	return (1);
}
