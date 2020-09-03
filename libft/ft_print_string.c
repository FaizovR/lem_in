/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjenkins <gjenkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:24:50 by gjenkins          #+#    #+#             */
/*   Updated: 2020/09/03 19:09:34 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

int		ft_print_string(va_list args_list, t_flags *flags)
{
	char		*str;
	int			counter;

	counter = 0;
	str = va_arg(args_list, char*);
	if (str == NULL)
		str = "(null)";
	flags->arg_length = ft_strlen(str);
	if (flags->flag_precision && (flags->precision < flags->arg_length))
		flags->arg_length = flags->precision;
	if (flags->flag_minus)
	{
		counter += write(1, str, flags->arg_length);
		counter += ft_handle_width(*flags);
	}
	else
	{
		counter += ft_handle_width(*flags);
		counter += write(1, str, flags->arg_length);
	}
	return (counter);
}
