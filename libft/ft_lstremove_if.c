/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listremove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:16:45 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/15 18:18:25 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove_if(t_list **list, void *content,
		size_t content_size, int (*cmp)(const void*, const void*, size_t))
{
	t_list **ptr;
	t_list *tmp;

	if (!list || !*list || !content || !content_size || !cmp)
		return ;
	ptr = list;
	while (*ptr)
	{
		if (content_size == (*ptr)->content_size &&
			!(*cmp)((*ptr)->content, content, content_size))
		{
			tmp = (*ptr)->next;
			ft_lstdelone(&*ptr, &ft_delcontent);
			*ptr = tmp;
		}
		else
			ptr = &(*ptr)->next;
	}
}
