/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_handler_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjenkins <gjenkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:25:24 by gjenkins          #+#    #+#             */
/*   Updated: 2020/02/08 19:25:24 by gjenkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_main.h"

void	ft_mod_init(t_mod *mod)
{
	mod->hh = 0;
	mod->h = 0;
	mod->l = 0;
	mod->ll = 0;
	mod->j = 0;
	mod->z = 0;
	mod->dl = 0;
}

void	ft_mod_parser(char *str, t_mod *mod)
{
	while (!ft_is_conversion(*(str)))
	{
		if (*str == 'h' && *(str + 1) == 'h')
			mod->hh = 1;
		if (*str == 'l' && *(str + 1) == 'l')
			mod->ll = 1;
		else if (*str == 'h' || *str == 'l' || *str == 'j' \
			|| *str == 'z' || *str == 'L')
		{
			if (*str == 'h')
				mod->h = 1;
			if (*str == 'l')
				mod->l = 1;
			if (*str == 'j')
				mod->j = 1;
			if (*str == 'z')
				mod->z = 1;
			if (*str == 'L')
				mod->dl = 1;
		}
		str++;
	}
}
