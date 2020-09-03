/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjenkins <gjenkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:24:59 by gjenkins          #+#    #+#             */
/*   Updated: 2020/09/03 19:09:34 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

int		ten_power(long long digit)
{
	int power;

	power = 1;
	while ((digit /= 10))
		++power;
	return (power);
}

int		handle_sign(t_flags *flags)
{
	if (flags->sign)
		flags->counter += write(1, "-", 1);
	else if (flags->flag_plus)
		flags->counter += write(1, "+", 1);
	else if (flags->flag_space)
		flags->counter += write(1, " ", 1);
	else
		return (0);
	flags->width--;
	return (1);
}

void	handle_image(t_flags *flags, int len)
{
	if (flags->flag_zero)
	{
		handle_sign(flags);
		while (flags->width-- > len)
			flags->counter += write(1, "0", 1);
	}
	else
	{
		while (flags->width-- > len + 1)
			flags->counter += write(1, " ", 1);
		if (!handle_sign(flags) && ++flags->width > len)
			flags->counter += write(1, " ", 1);
	}
}
