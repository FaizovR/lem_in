/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:42:50 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/17 10:16:36 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *result;
	char *ptr;

	if (!s || !f)
		return (NULL);
	if ((result = ft_strnew(ft_strlen(s))))
	{
		ptr = result;
		while (*s)
			*ptr++ = (*f)(*s++);
	}
	return (result);
}
