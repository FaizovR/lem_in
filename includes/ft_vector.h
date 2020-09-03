#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>

# define VECTOR_INIT_CAPACITY	8
# define VECTOR_RESIZE_SCALE	2

typedef struct	s_vector
{
	void	**data;
	size_t	size;
	size_t	capacity;

	void	(*free)(struct s_vector *);
	void	*(*get)(struct s_vector *, size_t);
	void	*(*pop_back)(struct s_vector *v);
	void	(*push_back)(struct s_vector *, void *);
	void	(*resize)(struct s_vector *, size_t);
	void	*(*erase)(struct s_vector *, size_t);
	void	(*set)(struct s_vector *, size_t, void *);
}				t_vector;


void			*vector_erase_if(t_vector *v, int value);
void			*vector_erase(t_vector *v, size_t idx);
void			vector_free(t_vector *v);
void			*vector_get(t_vector *v, size_t idx);
void			vector_init(t_vector **v);
void			*vector_pop_back(t_vector *v);
void			vector_push_back(t_vector *v, void *item);
void 			vector_resize(t_vector *v, size_t new_size);
void			vector_set(t_vector *v, size_t idx, void *item);

#endif