/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:37:50 by ycameron          #+#    #+#             */
/*   Updated: 2020/03/09 16:37:50 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(long value, int base, int uppercase)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		(base == 10) ? neg = 1 : (void)0;
		value *= -1;
	}
	while ((long)ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		if (!uppercase)
			nbr[i + neg] = value % base + (value % base > 9 ? 'a' - 10 : '0');
		else
			nbr[i + neg] = value % base + (value % base > 9 ? 'A' - 10 : '0');
		value /= base;
	}
	(neg) ? nbr[0] = '-' : (void)0;
	return (nbr);
}
