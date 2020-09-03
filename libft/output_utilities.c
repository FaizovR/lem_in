/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjenkins <gjenkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:25:31 by gjenkins          #+#    #+#             */
/*   Updated: 2020/02/08 19:25:31 by gjenkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

int		ft_simple_output(char **str)
{
	int	total;

	total = 0;
	while (**str != PERCENT && **str)
	{
		ft_putchar(**str);
		total++;
		(++*str);
	}
	return (total);
}

int		ft_handle_width(t_flags flags)
{
	int		counter;

	counter = 0;
	if (flags.flag_width)
	{
		if (flags.width > flags.arg_length)
		{
			flags.width -= flags.arg_length;
			while (flags.width > 0)
			{
				if (flags.flag_zero)
					counter += write(1, "0", 1);
				else
					counter += write(1, " ", 1);
				flags.width -= 1;
			}
		}
	}
	return (counter);
}
