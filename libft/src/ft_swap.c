/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:42:45 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/12 10:01:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_swap(void *a, void *b, size_t size)
{
	unsigned char	*ua;
	unsigned char	*ub;
	unsigned char	tmp;

	if (size == 0)
		return ;
	ua = (unsigned char *)a;
	ub = (unsigned char *)b;
	while (size-- > 0)
	{
		tmp = *ua;
		*ua++ = *ub;
		*ub++ = tmp;
	}
}
