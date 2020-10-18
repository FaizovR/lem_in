/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:17:37 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/12 10:01:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

#include <stddef.h>
#include <stdlib.h>

void	vector_free(t_vector *vector)
{
	free(vector->data);
	vector->data = NULL;
	vector->size = 0;
	vector->capacity = 0;
}

void	vector_free_deep(t_vector *vector, void (*f)(void *))
{
	size_t	i;

	i = 0;
	while (i < vector->size)
	{
		f(vector->data[i]);
		++i;
	}
	free(vector->data);
	vector->data = NULL;
	vector->size = 0;
	vector->capacity = 0;
}
