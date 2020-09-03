/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjenkins <gjenkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:25:07 by gjenkins          #+#    #+#             */
/*   Updated: 2020/09/03 19:09:34 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

unsigned long long	ft_caste_hex(va_list args_list, t_flags *flags)
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

static void			left_aligned_hex(t_flags *flags, int *counter, \
	char *str, const unsigned long long *val)
{
	int i;

	if (flags->flag_hash && val)
		flags->width -= 2;
	*counter += write(1, "0x", 2);
	if (flags->flag_precision && (flags->precision > flags->arg_length))
	{
		i = flags->precision;
		while (i-- > flags->arg_length)
			counter += write(1, "0", 1);
	}
	*counter += write(1, str, flags->arg_length);
	if (flags->precision > flags->arg_length)
		flags->arg_length = flags->precision;
	*counter += ft_handle_width(*flags);
}

static void			left_aligned_hex_help(t_flags *flags, \
	int *counter, char *str)
{
	int i;

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

static void			right_aligned_hex(t_flags *flags, int *counter, \
		char *result_str, const unsigned long long *value)
{
	if (flags->flag_hash && *value)
		flags->width -= 2;
	if (flags->flag_zero && !flags->flag_precision)
	{
		flags->flag_width = 0;
		flags->flag_precision = 1;
		flags->precision = flags->width;
	}
	if (flags->flag_precision && flags->precision > flags->arg_length)
		flags->width -= flags->precision - flags->arg_length;
	*counter += ft_handle_width(*flags);
	if (flags->flag_hash && *value != 0)
		*counter += write(1, "0x", 2);
	if (flags->flag_precision && (flags->precision > flags->arg_length))
		while (flags->precision-- > flags->arg_length)
			*counter += write(1, "0", 1);
	*counter += write(1, result_str, flags->arg_length);
}

int					ft_write_hex_low(va_list args_list, t_flags *flags)
{
	unsigned long long	value;
	char				*result_str;
	int					counter;

	counter = 0;
	value = ft_caste_hex(args_list, flags);
	result_str = ft_ltoa_base(value, 16, 0);
	flags->arg_length = ft_strlen(result_str);
	if (flags->flag_precision && !flags->precision && value == 0)
		flags->arg_length = 0;
	if (flags->flag_precision)
		flags->flag_zero = 0;
	if (flags->flag_minus)
	{
		if (flags->flag_hash && value)
			left_aligned_hex(flags, &counter, result_str, &value);
		else
			left_aligned_hex_help(flags, &counter, result_str);
	}
	else
		right_aligned_hex(flags, &counter, result_str, &value);
	free((void*)result_str);
	return (counter);
}
