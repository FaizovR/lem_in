#include "lem_in.h"
#include "ft_vector.h"

#include <stddef.h>
#include <stdlib.h>

void	vector_resize(t_vector *v, size_t new_size)
{
	void	**data_;

	if (new_size < v->capacity)
	{
		v->size = new_size;
	}
	else
	{
		data_ = (void **)malloc(sizeof(void *) * new_size);
		if (data_ == NULL)
			print_error(0);
		ft_memmove(data_, v->data, sizeof(void *) * v->size);
		free(v->data);
		v->data = data_;
		v->size = new_size;
		v->capacity = new_size;
	}
}