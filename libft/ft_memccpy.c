/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 00:06:13 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/15 15:02:01 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_buf;
	unsigned char	*src_buf;
	unsigned char	sym;

	dst_buf = (unsigned char*)dst;
	src_buf = (unsigned char*)src;
	sym = (unsigned char)c;
	while (n--)
	{
		*dst_buf++ = *src_buf++;
		if (*(src_buf - 1) == sym)
			return ((void*)dst_buf);
	}
	return (0);
}
