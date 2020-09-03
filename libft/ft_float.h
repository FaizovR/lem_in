/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:22:56 by hbarrett          #+#    #+#             */
/*   Updated: 2020/02/08 19:22:56 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_H
# define FT_FLOAT_H

# define BUF_LEN 1833
# define MAX_DOUBLE_LEN 16500
# define MAX_DIGIT 1000000000
# define DIGIT_COUNT 9

typedef struct		s_float
{
	long long		mant : 64;
	unsigned int	exp : 15;
	unsigned int	sign : 1;
}					t_float;

typedef union		u_double
{
	t_float			notion;
	long double		value;
}					t_double;

typedef struct		s_float_point
{
	int				full_number[BUF_LEN];
	int				index;
	int				exp_10;
	int				exp_2;
	int				last_exp;
}					t_float_point;

typedef struct		s_values
{
	int				i;
	int				j;
}					t_values;

/*
** ************************************************************************** **
**                                                                            **
** Float, Long Double                                                         **
**                                                                            **
** ************************************************************************** **
*/
void				handle_f(t_flags *flags, t_float_point *container);
void				handle_rounding(t_flags *flags, char *string);
void				handle_image(t_flags *flags, int len);
int					handle_sign(t_flags *flags);
void				f_string_solver(t_flags *flags, char *float_str);
void				ft_arithm_multiplication(int *box, int pow, int base, \
					t_float_point *container);
void				ft_arithm_division(int *box, int begin, int count);
void				ft_entire_sum(const int *box2, t_float_point *container, \
		int start);
void				ft_tail_sum(const int *box2, t_float_point *container, \
		int start);
int					find_start(int *box);
void				handle_large_tail(t_double *imagine, \
		t_float_point *container);
void				handle_small_tail(t_double *imagine, \
		t_float_point *container);
void				handle_entire(t_double *imagine, \
		t_float_point *container);
int					ten_power(long long digit);
void				e_string_solver(t_flags *flags, char *float_str);

#endif
