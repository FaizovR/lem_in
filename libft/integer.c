/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjenkins <gjenkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:25:16 by gjenkins          #+#    #+#             */
/*   Updated: 2020/09/03 19:09:34 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

static void	left_aligned(char *str, t_flags flags, int sign, int *counter)
{
	int	n;

	if (sign || flags.flag_space || flags.flag_plus)
	{
		if (sign)
		{
			*counter += write(1, "-", 1);
			flags.arg_length--;
		}
		else if (flags.flag_plus)
			*counter += write(1, "+", 1);
		else if (flags.flag_space)
			*counter += write(1, " ", 1);
		flags.width--;
	}
	if (flags.flag_precision && (flags.precision > flags.arg_length))
	{
		n = flags.precision;
		while (n-- > flags.arg_length)
			*counter += write(1, "0", 1);
	}
	*counter += write(1, sign ? str + 1 : str, flags.arg_length);
	if (flags.precision > flags.arg_length)
		flags.arg_length = flags.precision;
	*counter += ft_handle_width(flags);
}

void		right_aligned(char *str, t_flags flags, int sign, int *counter)
{
	if (flags.flag_zero && !flags.flag_precision)
	{
		flags.flag_width = 0;
		flags.flag_precision = 1;
		flags.precision = flags.width;
	}
	if (flags.flag_precision && flags.precision > flags.arg_length)
		flags.width -= flags.precision - flags.arg_length;
	*counter += ft_handle_width(flags);
	if (sign || flags.flag_space || flags.flag_plus)
	{
		if (sign)
			*counter += write(1, "-", 1);
		else
		{
			if (flags.flag_plus)
				*counter += write(1, "+", 1);
			else
				*counter += write(1, " ", 1);
		}
	}
	if (flags.flag_precision && (flags.precision > flags.arg_length))
		while (flags.precision-- > flags.arg_length)
			*counter += write(1, "0", 1);
	*counter += write(1, sign ? str + 1 : str, flags.arg_length);
}

int			ft_print_int(char *str, t_flags flags, long long num)
{
	int sign;
	int counter;

	if (flags.flag_precision && !flags.precision && num == 0)
		flags.arg_length = 0;
	counter = 0;
	sign = 0;
	if (num < 0)
		sign = 1;
	if (flags.flag_minus)
		left_aligned(str, flags, sign, &counter);
	else
	{
		if (sign || flags.flag_space || flags.flag_plus)
		{
			if (sign)
				flags.arg_length--;
			flags.width--;
		}
		right_aligned(str, flags, sign, &counter);
	}
	return (counter);
}

long long	ft_caste_int(va_list args_list, t_flags *flags)
{
	if (flags->mod.hh && flags->mod.l)
		return (va_arg(args_list, int));
	if (flags->mod.h && flags->mod.z)
		return (va_arg(args_list, long));
	else if (flags->mod.hh)
		return ((char)(va_arg(args_list, char *)));
	else if (flags->mod.h)
		return ((short int)(va_arg(args_list, char *)));
	else if (flags->mod.l)
		return (va_arg(args_list, long));
	else if (flags->mod.ll)
		return ((va_arg(args_list, long long)));
	else if (flags->mod.j)
		return (va_arg(args_list, intmax_t));
	else if (flags->mod.z)
		return ((va_arg(args_list, size_t)));
	return ((va_arg(args_list, int)));
}

int			ft_print_integer(va_list args_list, t_flags *flags)
{
	char			*str;
	long long		num;
	int				counter;

	counter = 0;
	num = ft_caste_int(args_list, flags);
	str = ft_ltoa(num);
	flags->arg_length = ft_strlen(str);
	if (flags->flag_precision)
		flags->flag_zero = 0;
	if (flags->flag_minus && flags->flag_width && num == 0)
		flags->flag_zero = 0;
	counter += ft_print_int(str, *flags, num);
	free((void*)str);
	return (counter);
}
