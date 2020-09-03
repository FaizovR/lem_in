/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:22:56 by hbarrett          #+#    #+#             */
/*   Updated: 2020/09/03 19:09:34 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

int		ft_handle_char(va_list args_list, t_flags *flags)
{
	char	symb;
	int		counter;

	counter = 0;
	if (flags->mod.l)
		return (ft_handle_wchar(args_list, flags));
	else
	{
		symb = va_arg(args_list, int);
		if (!flags->width)
			return (write(1, &symb, 1));
		flags->width--;
		if (flags->flag_minus)
		{
			counter += write(1, &symb, 1);
			counter += ft_handle_width(*flags);
		}
		else
		{
			counter += ft_handle_width(*flags);
			counter += write(1, &symb, 1);
		}
	}
	return (counter);
}
