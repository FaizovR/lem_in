#include "ft_vector.h"

void	vector_push_back(t_vector *v, void *item)
{
	if (v->size == v->capacity)
	{
		vector_resize(v, v->size * VECTOR_RESIZE_SCALE);
	}
	v->data[v->size++] = item;
}