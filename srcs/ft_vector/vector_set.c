#include "lem_in.h"
#include "ft_vector.h"

#include <stddef.h>

void	vector_set(t_vector *v, size_t idx, void *item)
{
	if (idx < v->size)
	{
		v->data[idx] = item;
	}
	else
	{
		print_error(0);
	}
}