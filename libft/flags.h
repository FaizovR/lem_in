/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjenkins <gjenkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:22:46 by gjenkins          #+#    #+#             */
/*   Updated: 2020/02/08 19:22:46 by gjenkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include "mod.h"

typedef struct	s_flags {
	char		flag_space;
	char		flag_minus;
	char		flag_plus;
	char		flag_hash;
	char		flag_zero;
	char		flag_width;
	char		flag_precision;
	int			width;
	int			precision;
	int			arg_length;
	t_mod		mod;
	char		spec_for_double;
	char		sign;
	int			counter;
}				t_flags;

#endif
