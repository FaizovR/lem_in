/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:22:56 by hbarrett          #+#    #+#             */
/*   Updated: 2020/02/08 19:22:56 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

static void	f_minus(t_flags *flags, char *string)
{
	handle_sign(flags);
	while (*string)
	{
		if (*string == '.' && !*(string + 1) && !flags->flag_hash)
			break ;
		flags->counter += write(1, string, 1);
		string++;
		flags->width--;
	}
	while (flags->precision-- > 0)
	{
		flags->counter += write(1, "0", 1);
		flags->width--;
	}
	while (flags->width-- > 0)
		flags->counter += write(1, " ", 1);
}

static void	f_no_minus(t_flags *flags, char *string)
{
	int		len;

	len = (int)ft_strlen(string);
	if (!*(ft_strchr(string, '.') + 1) && !flags->flag_hash)
		len--;
	if (flags->precision > 0)
		len += flags->precision;
	handle_image(flags, len);
	while (*string)
	{
		if (*string == '.' && !*(string + 1) && !flags->flag_hash)
			break ;
		flags->counter += write(1, string, 1);
		string++;
	}
	while (flags->precision-- > 0)
		flags->counter += write(1, "0", 1);
}

void		f_string_solver(t_flags *flags, char *float_str)
{
	if (flags->flag_minus)
		f_minus(flags, float_str);
	else
		f_no_minus(flags, float_str);
}
