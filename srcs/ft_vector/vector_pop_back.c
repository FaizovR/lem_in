#include "lem_in.h"
#include "ft_vector.h"

void	*vector_pop_back(t_vector *v)
{
	if (v->size == 0)
	{
		print_error(1);
	}
	return (v->data[v->size-- - 1]);
}