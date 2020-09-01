/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:39:58 by ycameron          #+#    #+#             */
/*   Updated: 2020/03/09 16:39:58 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ltoa_base(unsigned long long value, int base, int uppercase)
{
	size_t	i;
	char	*nbr;

	i = 1;
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		if (!uppercase)
			nbr[i] = value % base + (value % base > 9 ? 'a' - 10 : '0');
		else
			nbr[i] = value % base + (value % base > 9 ? 'A' - 10 : '0');
		value /= base;
	}
	return (nbr);
}
