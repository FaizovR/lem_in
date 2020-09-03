/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjenkins <gjenkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:25:50 by gjenkins          #+#    #+#             */
/*   Updated: 2020/02/08 19:25:50 by gjenkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

size_t		ft_handle_wchar(va_list args_list, t_flags *flags)
{
	wchar_t			chr;
	size_t			counter;

	chr = (wchar_t)va_arg(args_list, wint_t);
	flags->width--;
	counter = 0;
	if (flags->flag_minus)
	{
		counter += ft_putwchar_fd(chr, 1);
		counter += ft_handle_width(*flags);
	}
	else
	{
		counter += ft_handle_width(*flags);
		counter += ft_putwchar_fd(chr, 1);
	}
	return (counter);
}
