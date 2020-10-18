/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:06:24 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/12 10:01:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_string.h"
#include "ft_vector.h"

#include <stdlib.h>

void	vector_push_back(t_vector *vector, void *item)
{
	void	**data_;
	size_t	new_capacity;

	if (vector->size == vector->capacity)
	{
		new_capacity = vector->capacity * VECTOR_GROWTH_SCALE;
		data_ = (void **)malloc(sizeof(void *) * new_capacity);
		if (data_ == NULL)
			ft_throw(VECTOR_ALLOC_MSG, E_VECTOR_ALLOC);
		ft_memmove(data_, vector->data, sizeof(void *) * vector->capacity);
		free(vector->data);
		vector->data = data_;
		vector->capacity = new_capacity;
	}
	vector->data[vector->size++] = item;
}
