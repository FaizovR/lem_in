/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:32:06 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/17 10:42:26 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len;

	dst = 0;
	if (!s1 && !s2)
		return (0);
	else
		len = (s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0);
	if ((dst = ft_strnew(len)))
	{
		dst = ft_strcpy(dst, (char*)(s1 ? s1 : s2));
		if (s1 && s2)
			dst = ft_strcat(dst, (char*)s2);
	}
	return (dst);
}
