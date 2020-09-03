/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:22:56 by hbarrett          #+#    #+#             */
/*   Updated: 2020/02/08 19:22:56 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

int		ft_handle_percent(va_list args_list, t_flags *flags)
{
	int counter;

	counter = 0;
	(void)args_list;
	flags->width -= 1;
	if (flags->flag_minus)
	{
		counter += write(1, "%", 1);
		if (flags->width)
			counter += ft_handle_width(*flags);
	}
	else
	{
		if (flags->width)
			counter += ft_handle_width(*flags);
		counter += write(1, "%", 1);
	}
	return (counter);
}
