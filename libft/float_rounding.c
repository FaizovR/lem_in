/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_rounding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:22:56 by hbarrett          #+#    #+#             */
/*   Updated: 2020/09/03 19:09:34 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

static void	rounding(char *string, int i)
{
	int		rest;

	rest = 1;
	while (--i >= 0 && rest == 1 && string[i] != '.')
	{
		if (rest == 1)
			string[i] += 1;
		rest = (string[i] - 48) / 10;
		string[i] = (string[i] - 48) % 10 + 48;
	}
	if (string[i] == '.' && rest == 1)
		rounding(string, i);
}

static void	zero_clean(char *string, int i)
{
	while (--i >= 0 && string[i] == '0')
		string[i] = '\0';
}

void		handle_rounding(t_flags *flags, char *string)
{
	int		i;

	(void)flags;
	i = (int)ft_strlen(string) - 1;
	if (string[i] - 48 > 4)
		rounding(string, i);
	if (ft_isdigit(string[i]))
		string[i] = '\0';
	if (ft_tolower(flags->spec_for_double) == 'g')
		zero_clean(string, i);
}
