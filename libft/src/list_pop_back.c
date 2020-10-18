/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:11:20 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/12 10:01:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_list.h"

#include <stddef.h>
#include <stdlib.h>

void	*list_pop_back(t_list *list)
{
	t_node	*node;
	void	*data;

	if (list->size == 0)
		ft_throw(LIST_EMPTY_MSG, E_LIST_EMPTY);
	if (list->front == list->back)
		list->front = NULL;
	else if (list->front->next == list->back)
		list->front->next = NULL;
	node = list->back;
	list->back = node->prev;
	if (list->back != NULL)
		list->back->next = NULL;
	--list->size;
	data = node->data;
	free(node);
	return (data);
}
