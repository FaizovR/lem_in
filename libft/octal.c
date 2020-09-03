/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:22:56 by hbarrett          #+#    #+#             */
/*   Updated: 2020/02/08 19:22:56 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

unsigned long long	ft_caste_octal(va_list args_list, t_flags *flags)
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

static void			left_aligned_octal(t_flags *flags, int *counter, \
					char *str)
{
	int i;

	if (flags->flag_hash)
		*counter += write(1, "0", 1);
	if (flags->flag_precision && (flags->precision > flags->arg_length))
	{
		i = flags->precision;
		while (i-- > flags->arg_length)
			*counter += write(1, "0", 1);
	}
	*counter += write(1, str, flags->arg_length);
	if (flags->precision > flags->arg_length)
		flags->arg_length = flags->precision;
	*counter += ft_handle_width(*flags);
}

static void			right_aligned_octal(t_flags *flags, int *counter,\
					char *result_str)
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
	if (flags->flag_hash)
		*counter += write(1, "0", 1);
	if (flags->flag_precision && (flags->precision > flags->arg_length))
		while (flags->precision-- > flags->arg_length)
			*counter += write(1, "0", 1);
	*counter += write(1, result_str, flags->arg_length);
}

static void			ft_octal_help(t_flags *flags)
{
	if (flags->flag_hash)
	{
		if (flags->flag_precision && !flags->flag_width)
			flags->precision--;
		else if (!flags->flag_precision && flags->flag_width)
			flags->width--;
		else if (flags->flag_width && flags->flag_precision)
		{
			flags->precision--;
			flags->width--;
		}
	}
}

int					ft_print_octal(va_list args_list, t_flags *flags)
{
	unsigned long long	value;
	char				*result_str;
	int					counter;

	counter = 0;
	value = ft_caste_octal(args_list, flags);
	result_str = ft_ltoa_base(value, 8, 0);
	flags->arg_length = ft_strlen(result_str);
	if (flags->flag_precision && !flags->precision && value == 0)
		flags->arg_length = 0;
	if (!value && !flags->flag_precision)
		flags->flag_hash = 0;
	ft_octal_help(flags);
	if (flags->flag_precision)
		flags->flag_zero = 0;
	if (flags->flag_minus)
		left_aligned_octal(flags, &counter, result_str);
	else
		right_aligned_octal(flags, &counter, result_str);
	free((void*)result_str);
	return (counter);
}
