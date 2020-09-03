#include "ft_vector.h"

#include <stddef.h>
#include <stdlib.h>

void	vector_free(t_vector *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}