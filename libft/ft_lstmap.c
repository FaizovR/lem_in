/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:57:14 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/15 14:57:14 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*list;
	t_list		*prev;

	if (!lst || !f)
		return (0);
	list = 0;
	prev = 0;
	while (lst)
	{
		if (!(new = f(lst)))
		{
			ft_lstdel(&list, &ft_delcontent);
			return (0);
		}
		if (!prev)
		{
			list = new;
			prev = list;
		}
		prev->next = new;
		prev = prev->next;
		lst = lst->next;
	}
	return (list);
}
