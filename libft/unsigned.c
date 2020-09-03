/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:22:56 by hbarrett          #+#    #+#             */
/*   Updated: 2020/02/08 19:22:56 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

static void			left_aligned(char *str, t_flags flags,\
					int sign, int *counter)
{
	int	n;

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

static void			right_aligned(char *str, t_flags flags,\
					int sign, int *counter)
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
	if (flags.flag_precision && (flags.precision > flags.arg_length))
		while (flags.precision-- > flags.arg_length)
			*counter += write(1, "0", 1);
	*counter += write(1, sign ? str + 1 : str, flags.arg_length);
}

int					ft_print_uns(char *str, t_flags flags,\
					unsigned long long num)
{
	int sign;
	int counter;

	if (flags.flag_precision && !flags.precision && num == 0)
		flags.arg_length = 0;
	counter = 0;
	sign = 0;
	if (flags.flag_minus)
		left_aligned(str, flags, sign, &counter);
	else
		right_aligned(str, flags, sign, &counter);
	return (counter);
}

unsigned long long	ft_caste_unsigned(va_list args_list,\
					t_flags *flags)
{
	if (flags->mod.hh)
		return ((unsigned char)(va_arg(args_list, void *)));
	else if (flags->mod.h)
		return ((unsigned short)(va_arg(args_list, void *)));
	else if (flags->mod.l)
		return ((unsigned long)(va_arg(args_list, long)));
	else if (flags->mod.ll)
		return ((unsigned long long)(va_arg(args_list, long long)));
	else if (flags->mod.j)
		return (va_arg(args_list, uintmax_t));
	else if (flags->mod.z)
		return ((va_arg(args_list, size_t)));
	return ((va_arg(args_list, unsigned int)));
}

int					ft_print_unsigned(va_list args_list,\
					t_flags *flags)
{
	char					*str;
	unsigned long long		num;
	int						counter;

	counter = 0;
	num = ft_caste_unsigned(args_list, flags);
	str = ft_ultoa(num);
	flags->arg_length = ft_strlen(str);
	if (flags->flag_precision)
		flags->flag_zero = 0;
	if (flags->flag_minus && flags->flag_width && num == 0)
		flags->flag_zero = 0;
	counter += ft_print_uns(str, *flags, num);
	free((void*)str);
	return (counter);
}
