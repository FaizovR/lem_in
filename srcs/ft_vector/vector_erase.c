#include "lem_in.h"
#include "ft_vector.h"

void *vector_erase(t_vector *v, size_t idx) {
	void *return_v;

	if (v->size == 0 || idx > v->size)
	{
		print_error(1);
	}
	return_v = v->data[idx];
	while (idx < v->size)
	{
		v->data[idx] = v->data[idx + 1];
		idx++;
	}
	v->size--;
	return return_v;
}
