/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:47:38 by ycameron          #+#    #+#             */
/*   Updated: 2019/09/15 15:02:01 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int tmp;

	tmp = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp *= -1;
	}
	if (tmp > 9)
		ft_putnbr_fd((int)(tmp / 10), fd);
	ft_putchar_fd((char)(tmp % 10 + 48), fd);
}
