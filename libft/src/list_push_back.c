/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:11:02 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/12 10:01:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_list.h"

#include <stddef.h>
#include <stdlib.h>

void	list_push_back(t_list *list, void *item)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		ft_throw(LIST_ALLOC_MSG, E_LIST_ALLOC);
	node->data = item;
	node->prev = list->back;
	node->next = NULL;
	if (list->back != NULL)
		list->back->next = node;
	list->back = node;
	if (list->front == NULL)
		list->front = node;
	++list->size;
}
