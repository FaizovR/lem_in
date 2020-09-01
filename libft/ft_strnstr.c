/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 23:14:23 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/15 15:02:01 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	size_t	j;
	size_t	i;
	size_t	n_len;

	ptr = (char *)haystack;
	if (!(n_len = ft_strlen(needle)))
		return (ptr);
	if (ft_strlen(haystack) < n_len || len < n_len)
		return (NULL);
	i = 0;
	while (ptr[i] && i <= len - n_len)
	{
		j = 0;
		while (needle[j] && needle[j] == ptr[i + j])
			j++;
		if (j == n_len)
			return (&ptr[i]);
		i++;
	}
	return (0);
}
