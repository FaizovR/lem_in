/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:41:27 by ycameron          #+#    #+#             */
/*   Updated: 2020/03/09 16:41:27 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

size_t		ft_putwchar_fd(wchar_t chr, int fd)
{
	size_t counter;

	counter = 0;
	if (chr <= 0x7F)
		counter += ft_putchar_fd(chr, fd);
	else if (chr <= 0x7FF)
	{
		counter += ft_putchar_fd((chr >> 6) + 0xC0, fd);
		counter += ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0xFFFF)
	{
		counter += ft_putchar_fd((chr >> 12) + 0xE0, fd);
		counter += ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		counter += ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0x10FFFF)
	{
		counter += ft_putchar_fd((chr >> 18) + 0xF0, fd);
		counter += ft_putchar_fd(((chr >> 12) & 0x3F) + 0x80, fd);
		counter += ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		counter += ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	return (counter);
}
