/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:57:31 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/15 14:57:31 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printelem(t_list *list)
{
	if (list)
	{
		if (list->content && list->content_size)
		{
			ft_putstr((char*)list->content);
			if (list->next)
				ft_putstr(" -> ");
		}
	}
}

void		ft_lstprint(t_list *list)
{
	ft_lstiter(list, &ft_printelem);
}
