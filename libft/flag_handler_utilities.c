/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler_utilities.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjenkins <gjenkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:24:33 by gjenkins          #+#    #+#             */
/*   Updated: 2020/09/03 19:09:34 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

void		ft_flags_init(t_flags *flags)
{
	flags->flag_space = 0;
	flags->flag_minus = 0;
	flags->flag_plus = 0;
	flags->flag_hash = 0;
	flags->flag_zero = 0;
	flags->flag_width = 0;
	flags->flag_precision = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->arg_length = 0;
	ft_mod_init(&flags->mod);
	flags->spec_for_double = 0;
	flags->sign = 0;
	flags->counter = 0;
}

void		ft_flag_parser(char *str, t_flags *flag)
{
	while (!ft_is_conversion(*str))
	{
		if (*str == ' ')
			flag->flag_space = 1;
		else if (*str == '-')
			flag->flag_minus = 1;
		else if (*str == '+')
			flag->flag_plus = 1;
		else if (*str == '#')
			flag->flag_hash = 1;
		else if ((*str == '0' && flag->flag_minus == 0 &&
		!ft_isdigit(*(str - 1)) && *(str - 1) != '.'))
			flag->flag_zero = 1;
		str++;
	}
}

static void	ft_flag_helper(t_flags *flag, char *str, int is_width)
{
	if (is_width)
	{
		while (ft_isdigit(*str))
			flag->width = flag->width * 10 + (*(str++) - '0');
	}
	else
	{
		while (ft_isdigit(*str))
			flag->precision = flag->precision * 10 + (*(str++) - '0');
	}
}

void		ft_flag_precision(char *s, t_flags *flag, va_list args_list)
{
	while (!ft_is_conversion(*s))
	{
		if (*s == '.')
			flag->flag_precision = 1;
		if (*s == '.' && (*(s + 1) == '*' || *(s + 1) == '-' \
			|| ft_isdigit(*(s + 1))))
		{
			s++;
			if (*s == '*')
			{
				flag->precision = va_arg(args_list, int);
				if (flag->precision < 0)
				{
					flag->precision = 0;
					flag->flag_precision = 0;
				}
			}
			else if (ft_isdigit(*s))
			{
				ft_flag_helper(flag, s, 0);
				return ;
			}
		}
		s++;
	}
}

void		ft_flag_width(char *s, t_flags *flag, va_list args_list)
{
	while (!ft_is_conversion(*s))
	{
		if (*s == '.')
			return ;
		if ((*s == '*' || (ft_isdigit(*s) && *s != '0')) && *(s - 1) != '.')
		{
			flag->flag_width = 1;
			if (*s == '*')
			{
				flag->width = va_arg(args_list, int);
				if (flag->width < 0)
				{
					flag->width *= -1;
					flag->flag_minus = 1;
				}
			}
			if (ft_isdigit(*s))
			{
				flag->width = 0;
				ft_flag_helper(flag, s, 1);
				return ;
			}
		}
		s++;
	}
}
