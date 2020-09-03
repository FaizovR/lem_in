#include "ft_vector.h"
#include "lem_in.h"

void *vector_erase_if(t_vector *v, int value) {
	size_t idx;

	idx = 0;
	if (v->size == 0)
	{
		print_error(1);
	}
	while (idx < v->size)
	{
		if (*(int*) v->data[idx] == value)
			break;
		idx++;
	}
	if (idx < v->size && *(int*) v->data[idx] == value)
		return vector_erase(v, idx);
	else
		return NULL;
}
