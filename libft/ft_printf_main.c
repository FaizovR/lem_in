/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:22:56 by hbarrett          #+#    #+#             */
/*   Updated: 2020/09/03 19:09:34 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

t_handler g_handlers[FUNC_HANDLERS_CNT] = {{TYPE_CHAR, &ft_handle_char},
	{TYPE_STR, &ft_print_string}, {TYPE_INT_D, &ft_print_integer},
	{TYPE_PTR, &ft_print_pointers}, {PERCENT, &ft_handle_percent},
	{TYPE_INT_I, &ft_print_integer}, {TYPE_INT_HEX_LO, &ft_write_hex_low},
	{TYPE_INT_OCTO, &ft_print_octal}, {TYPE_INT_U, &ft_print_unsigned},
	{TYPE_INT_HEX_UP, &ft_write_hex_up}, {TYPE_BINARY, &ft_print_binary},
	{TYPE_FLOAT, &float_solver}};

void		ft_parse(char *str, t_flags *flags, va_list args_list)
{
	ft_flags_init(flags);
	ft_flag_parser(str, flags);
	ft_mod_parser(str, &flags->mod);
	ft_flag_width(str, flags, args_list);
	ft_flag_precision(str, flags, args_list);
}

int			ft_check_spec(char *str)
{
	while (*str)
	{
		if (ft_is_conversion(*str))
			return (1);
		str++;
	}
	return (0);
}

int			ft_type_handler(char **str, va_list args_list)
{
	t_flags		flags;
	int			index;
	int			counter;

	if (!ft_check_spec(*(str) + 1))
	{
		((*str)++);
		return (0);
	}
	counter = 0;
	(*str)++;
	ft_parse(*str, &flags, args_list);
	while (!ft_is_conversion(**str))
		(*str)++;
	index = 0;
	flags.spec_for_double = 'f';
	while (index < FUNC_HANDLERS_CNT)
	{
		if (g_handlers[index++].specifier == **str)
		{
			counter += g_handlers[index - 1].handler(args_list, &flags);
		}
	}
	(index <= FUNC_HANDLERS_CNT) ? (*str)++ : (void)0;
	return (counter);
}

int			ft_printf(const char *restrict format, ...)
{
	int		output_completed;
	va_list	args_list;
	char	*str_formated;

	str_formated = (char*)format;
	output_completed = 0;
	va_start(args_list, format);
	while (*str_formated)
	{
		if (*str_formated == PERCENT && !*(str_formated + 1))
			return (output_completed);
		else if (*str_formated == PERCENT)
			output_completed += ft_type_handler(&str_formated, args_list);
		else
			output_completed += ft_simple_output(&str_formated);
	}
	va_end(args_list);
	return (output_completed);
}
