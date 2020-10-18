/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:30:17 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/12 10:01:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stddef.h>

# define LIST_ALLOC_MSG		"Memory allocation for list node failed"
# define LIST_EMPTY_MSG		"Can't perform the operation on an empty list"

# define E_LIST_ALLOC		1
# define E_LIST_EMPTY		2

typedef struct	s_node
{
	void			*data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_list
{
	t_node	*back;
	t_node	*front;
	size_t	size;
}				t_list;

void			list_free(t_list *list);
void			list_free_deep(t_list *list, void (*f)(void *));
void			list_init(t_list *list);
void			*list_pop_back(t_list *list);
void			*list_pop_front(t_list *list);
void			list_push_back(t_list *list, void *item);
void			list_push_front(t_list *list, void *item);

#endif
