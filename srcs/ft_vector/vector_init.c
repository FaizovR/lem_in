#include "lem_in.h"
#include "ft_vector.h"

#include <stdlib.h>

void	vector_init(t_vector **v)
{
	t_vector *temp;

	temp = (t_vector*)malloc(sizeof(t_vector));
	temp->capacity = VECTOR_INIT_CAPACITY;
	temp->size = 0;
	temp->data = (void **)malloc(sizeof(void *) * temp->capacity);
	if (temp->data == NULL)
		print_error(1);
	temp->free = vector_free;
	temp->get = vector_get;
	temp->erase = vector_erase;
	temp->pop_back = vector_pop_back;
	temp->push_back = vector_push_back;
	temp->resize = vector_resize;
	temp->set = vector_set;
	*v = temp;
}