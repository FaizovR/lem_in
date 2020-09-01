/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 00:02:21 by ycameron          #+#    #+#             */
/*   Updated: 2020/03/09 16:38:00 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nsize(int n)
{
	return (n ? (1 + nsize(n / 10)) : (0));
}

static char		*zero(void)
{
	char		*result;

	if ((result = ft_strnew(1)))
		*result = '0';
	return (result);
}

char			*ft_itoa(int n)
{
	char		*result;
	int			size;
	long int	tmp;

	if (n == 0)
		return (zero());
	size = ((n > 0) ? 0 : 1) + nsize(n);
	tmp = (long int)n;
	if ((result = ft_strnew(size)))
	{
		if (tmp < 0)
		{
			result[0] = '-';
			tmp *= -1;
		}
		while (tmp)
		{
			result[--size] = tmp % 10 + 48;
			tmp /= 10;
		}
	}
	return (result);
}
