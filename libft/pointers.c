/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjenkins <gjenkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:25:38 by gjenkins          #+#    #+#             */
/*   Updated: 2020/02/08 19:25:38 by gjenkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

static void		left_aligned(t_flags *flags, char *result_value, int *counter)
{
	int		i;

	*counter += write(1, "0x", 2);
	if (flags->flag_precision && (flags->precision > flags->arg_length))
	{
		i = flags->precision;
		while (i-- > flags->arg_length)
			*counter += write(1, "0", 1);
	}
	*counter += write(1, result_value, flags->arg_length);
	if (flags->precision > flags->arg_length)
		flags->arg_length = flags->precision;
	*counter += ft_handle_width(*flags);
}

static void		right_aligned(t_flags *flags, char *result_value, int *counter)
{
	if (flags->flag_zero && !flags->flag_precision)
	{
		flags->flag_width = 0;
		flags->flag_precision = 1;
		flags->precision = flags->width;
	}
	if (flags->flag_precision && flags->precision > flags->arg_length)
		flags->width -= flags->precision - flags->arg_length;
	*counter += ft_handle_width(*flags);
	*counter += write(1, "0x", 2);
	if (flags->flag_precision && (flags->precision > flags->arg_length))
		while (flags->precision-- > flags->arg_length)
			*counter += write(1, "0", 1);
	*counter += write(1, result_value, flags->arg_length);
}

int				ft_print_pointers(va_list args_list, t_flags *flags)
{
	char	*result_value;
	int		counter;
	long	pointer;

	pointer = va_arg(args_list, long);
	result_value = ft_itoa_base(pointer, 16, 0);
	counter = 0;
	flags->arg_length = (int)ft_strlen(result_value);
	flags->width -= 2;
	if (flags->flag_precision && !flags->precision && !pointer)
		flags->arg_length = 0;
	if (flags->flag_minus)
		left_aligned(flags, result_value, &counter);
	else
		right_aligned(flags, result_value, &counter);
	free((void*)result_value);
	return (counter);
}
