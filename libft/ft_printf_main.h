/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjenkins <gjenkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:23:43 by gjenkins          #+#    #+#             */
/*   Updated: 2020/09/03 19:10:35 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_MAIN_H
# define FT_PRINTF_MAIN_H

/*
** ************************************************************************** **
**                                                                            **
** Libs                                                                       **
**                                                                            **
** ************************************************************************** **
*/

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

/*
** ************************************************************************** **
**                                                                            **
** Project headers                                                            **
**                                                                            **
** ************************************************************************** **
*/

# include "flags.h"
# include "types.h"
# include "handlers.h"
# include "mod.h"
# include "ft_float.h"

/*
** ************************************************************************** **
**                                                                            **
** Project macros                                                             **
**                                                                            **
** ************************************************************************** **
*/

# define PERCENT '%'
# define FUNC_HANDLERS_CNT 12

int				ft_printf(const char *restrict format, ...);

/*
** ************************************************************************** **
**                                                                            **
** Output                                                                     **
**                                                                            **
** ************************************************************************** **
*/

int				ft_simple_output(char **str);
int				ft_handle_width(t_flags flags);

/*
** ************************************************************************** **
**                                                                            **
** Type handlers                                                              **
**                                                                            **
** ************************************************************************** **
*/

int				ft_type_handler(char **str, va_list args_list);
int				ft_is_conversion(int c);
void			ft_flag_parser(char *str, t_flags *flag);
void			ft_flag_precision(char *str, t_flags *flag, va_list args_list);
void			ft_flags_init(t_flags *flags);
void			ft_flag_width(char *str, t_flags *flag, va_list args_list);
void			ft_parse(char *str, t_flags *flags, va_list args_list);
#endif
