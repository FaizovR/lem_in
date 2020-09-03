/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:22:56 by hbarrett          #+#    #+#             */
/*   Updated: 2020/02/08 19:22:56 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

static void		handle_f_integer_part(t_float_point *container, char *string, \
				t_values *index)
{
	int			count;

	string[index->i++] = '0';
	count = MAX_DIGIT / 10;
	while (count > 1 && \
		container->full_number[index->j] % count == \
		container->full_number[index->j])
		count /= 10;
	while (index->j <= container->index)
	{
		while (count > 0)
		{
			string[index->i++] = container->full_number[index->j] / count + 48;
			container->full_number[index->j] %= count;
			count /= 10;
		}
		count = MAX_DIGIT / 10;
		index->j++;
	}
}

static void		handle_f_fractional_part(t_flags *flags, \
				t_float_point *container, char *string, t_values *index)
{
	int			count;

	while (index->j < BUF_LEN - 1)
	{
		count = MAX_DIGIT / 10;
		while (count > 0 && flags->precision-- >= 0)
		{
			string[index->i++] = container->full_number[index->j] / count + 48;
			container->full_number[index->j] %= count;
			count /= 10;
		}
		if (flags->precision < 0)
			return ;
		index->j++;
	}
}

void			handle_f(t_flags *flags, t_float_point *container)
{
	char		string_f[MAX_DOUBLE_LEN];
	t_values	index;

	ft_bzero(string_f, MAX_DOUBLE_LEN);
	index.i = 0;
	index.j = 0;
	if (container->full_number[index.j] == 0 && container->exp_10 >= 0)
		++index.j;
	handle_f_integer_part(container, string_f, &index);
	string_f[index.i++] = '.';
	handle_f_fractional_part(flags, container, string_f, &index);
	handle_rounding(flags, string_f);
	if (string_f[0] == '0' && string_f[1] != '.')
		f_string_solver(flags, string_f + 1);
	else
		f_string_solver(flags, string_f);
}
