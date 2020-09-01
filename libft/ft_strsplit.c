/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:53:40 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/30 12:11:23 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	word_cnt(char const *str, char sym)
{
	unsigned int	result;

	result = 0;
	while (*str)
	{
		if (*str != sym)
		{
			result++;
			while (*str && *str != sym)
				str++;
			continue;
		}
		str++;
	}
	return (result);
}

static unsigned int	word_len(char const **str, char sym)
{
	unsigned int	result;

	result = 0;
	while (**str && **str != sym)
	{
		result++;
		(*str)++;
	}
	return (result);
}

static char			**abort_it(char **result, unsigned int cnt)
{
	unsigned int		index;

	index = 0;
	while (index < cnt)
		ft_strdel(&result[index++]);
	free(result);
	result = NULL;
	return (result);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**result;
	char			**ptr;
	unsigned int	index;

	if (!s)
		return (NULL);
	if (!(result = (char**)ft_memalloc(sizeof(char*) * (word_cnt(s, c) + 1))))
		return (NULL);
	index = 0;
	ptr = result;
	while (*s)
	{
		if (*s != c)
		{
			index++;
			if (!(*result = ft_strsub(s, 0, word_len(&s, c))))
				return (abort_it(ptr, index));
			result++;
			continue;
		}
		s++;
	}
	*result = 0;
	return (ptr);
}
