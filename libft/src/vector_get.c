/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:14:08 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/12 10:01:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_vector.h"

#include <stddef.h>

void	*vector_get(t_vector *vector, size_t idx)
{
	if (idx < vector->size)
	{
		return (vector->data[idx]);
	}
	else
	{
		ft_throw(VECTOR_INDEX_MSG, E_VECTOR_INDEX);
	}
	return (NULL);
}
