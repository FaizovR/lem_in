/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:16:45 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/15 18:18:25 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_longlen(long n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

char		*ft_ltoa(long long nbr)
{
	char	*s;
	int		i;
	int		neg;
	long	div;

	if (nbr == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	div = 1;
	neg = nbr < 0 ? 1 : 0;
	nbr = nbr < 0 ? -nbr : nbr;
	i = ft_longlen(nbr);
	s = (char*)malloc(sizeof(char) * (i + neg + 1));
	s[i + neg] = '\0';
	while (--i >= 0)
	{
		s[i + neg] = (nbr / div % 10) + '0';
		div *= 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
