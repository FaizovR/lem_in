/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:25:41 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/15 17:42:51 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **list)
{
	t_list *result;

	if (list)
	{
		if (!*list)
			return (NULL);
		else
		{
			result = *list;
			*list = (*list)->next;
		}
		return (result);
	}
	return (0);
}
