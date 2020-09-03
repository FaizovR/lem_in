/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:22:56 by hbarrett          #+#    #+#             */
/*   Updated: 2020/02/08 19:22:56 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

/*
** ************************************************************************** **
**                                                                            **
** Handlers array stack                                                       **
**                                                                            **
** ************************************************************************** **
*/

typedef int		(*t_hand) (va_list args_list, t_flags* flags);

typedef struct		s_handler
{
	char			specifier;
	t_hand			handler;
}					t_handler;

int					ft_handle_char(va_list args_list, t_flags *flags);
int					ft_write_hex_low(va_list args_list, t_flags *flags);
int					ft_print_string(va_list args_list, t_flags *flags);
int					ft_print_integer(va_list args_list, t_flags *flags);
int					ft_print_pointers(va_list args_list, t_flags *flags);
int					ft_handle_percent(va_list args_list, t_flags *flags);
size_t				ft_handle_wchar(va_list args_list, t_flags *flags);
int					ft_print_octal(va_list args_list, t_flags *flags);
int					ft_print_unsigned(va_list args_list, t_flags *flags);
int					ft_write_hex_up(va_list args_list, t_flags *flags);
int					ft_print_binary(va_list args_list, t_flags *flags);
int					float_solver(va_list arg, t_flags *flags);
#endif
