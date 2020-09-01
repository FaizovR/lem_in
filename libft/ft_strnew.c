/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:41:52 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/17 11:08:02 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	if (size == ((size_t)0) - 1)
		return (NULL);
	else
		return ((char*)ft_memalloc(sizeof(char) * (size + 1)));
}
