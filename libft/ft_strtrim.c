/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 23:16:22 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/15 15:02:01 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	whspcs(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	int		f;
	int		l;
	char	*str;

	if (!s)
		return (NULL);
	f = 0;
	while (s[f] && whspcs(s[f]))
		f++;
	l = ft_strlen(&s[f]) - 1;
	while (s[f] && whspcs(s[f + l]))
		l--;
	if (!(str = ft_strnew(l + 1)))
		return (NULL);
	return (ft_strncpy(str, (s + f), (l + 1)));
}
