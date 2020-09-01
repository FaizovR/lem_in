/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:34:45 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/15 15:02:01 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char symb;

	symb = (char)c;
	while (*s)
		if (*s++ == symb)
			return ((char*)(s - 1));
	return (*s == symb ? (char*)s : 0);
}
