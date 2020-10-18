/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:18:25 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/12 10:01:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>

# define VECTOR_INIT_CAPACITY	8
# define VECTOR_GROWTH_SCALE	2

# define VECTOR_ALLOC_MSG	"Memory allocation for vector data failed"
# define VECTOR_INDEX_MSG	"Vector index out of bounds"
# define VECTOR_EMPTY_MSG	"Can't perform the operation on an empty vector"

# define E_VECTOR_ALLOC		1
# define E_VECTOR_INDEX		2
# define E_VECTOR_EMPTY		3

typedef struct	s_vector
{
	void	**data;
	size_t	size;
	size_t	capacity;
}				t_vector;

void			vector_free(t_vector *vector);
void			vector_free_deep(t_vector *vector, void (*f)(void *));
void			*vector_get(t_vector *vector, size_t idx);
void			vector_init(t_vector *vector);
void			*vector_pop_back(t_vector *vector);
void			vector_push_back(t_vector *vector, void *item);
void			vector_resize(t_vector *vector, size_t new_size);
void			vector_set(t_vector *vector, size_t idx, void *item);

#endif
