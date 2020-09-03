#include "lem_in.h"
#include "ft_vector.h"

#include <stddef.h>

void	*vector_get(t_vector *v, size_t idx)
{
	if (idx < v->size)
	{
		return (v->data[idx]);
	}
	else
	{
		print_error(1);
	}
	return (NULL);
}