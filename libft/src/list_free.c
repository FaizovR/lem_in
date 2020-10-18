/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:52:31 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/12 10:01:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stddef.h>
#include <stdlib.h>

void	list_free(t_list *list)
{
	t_node	*node;
	t_node	*tmp;

	node = list->front;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	list->front = NULL;
	list->back = NULL;
	list->size = 0;
}

void	list_free_deep(t_list *list, void (*f)(void *))
{
	t_node	*node;
	t_node	*tmp;

	node = list->front;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		f(tmp->data);
		free(tmp);
	}
	list->front = NULL;
	list->back = NULL;
	list->size = 0;
}
