/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:22:56 by hbarrett          #+#    #+#             */
/*   Updated: 2020/09/03 19:09:34 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"
int					handle_inf_nan(t_flags *flags, t_double *imagine)
{
	char	*string;

	string = NULL;
	if (imagine->notion.exp == 32767 && imagine->notion.mant << 1 == 0)
		string = "inf";
	else if (imagine->notion.exp == 32767 && imagine->notion.mant != 0)
	{
		string = "nan";
		flags->flag_plus = 1;
		flags->flag_minus = 0;
	}
	if (!string)
		return (0);
	if (flags->flag_zero)
		flags->flag_zero = 0;
	flags->counter += write(1, string, 3);
	return (1);
}

void				parse_sign_precision(t_flags *flags, t_double *imagine)
{
	if (imagine->notion.sign == 1)
		flags->sign = 1;
	if (flags->flag_precision)
		return ;
	flags->precision = 6;
}

void				float_handler(t_flags *flags, t_double *imagine)
{
	t_float_point	container;

	ft_bzero(container.full_number, sizeof(int) * BUF_LEN);
	container.index = 0;
	container.exp_10 = 0;
	container.exp_2 = imagine->notion.exp - 16383;
	imagine->notion.mant = imagine->notion.mant << 1;
	if (imagine->notion.exp != 0 && container.exp_2 < 0)
		handle_large_tail(imagine, &container);
	else if (container.exp_2 >= 0)
	{
		handle_entire(imagine, &container);
		handle_small_tail(imagine, &container);
	}
	if (ft_tolower(flags->spec_for_double))
		handle_f(flags, &container);
}

int					float_solver(va_list args_list, t_flags *flags)
{
	t_double		imagine;

	if (flags->mod.dl)
		imagine.value = va_arg(args_list, long double);
	else
		imagine.value = va_arg(args_list, double);
	parse_sign_precision(flags, &imagine);
	if (!handle_inf_nan(flags, &imagine))
		float_handler(flags, &imagine);
	return (flags->counter);
}
