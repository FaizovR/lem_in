/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:11:16 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/12 10:01:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_list.h"

#include <stddef.h>
#include <stdlib.h>

void	*list_pop_front(t_list *list)
{
	t_node	*node;
	void	*data;

	if (list->size == 0)
		ft_throw(LIST_EMPTY_MSG, E_LIST_EMPTY);
	if (list->back == list->front)
		list->back = NULL;
	else if (list->back->prev == list->front)
		list->back->prev = NULL;
	node = list->front;
	list->front = node->next;
	if (list->front != NULL)
		list->front->prev = NULL;
	--list->size;
	data = node->data;
	free(node);
	return (data);
}
