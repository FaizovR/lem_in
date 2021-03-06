/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digittoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:34:28 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/12 10:01:35 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_digittoint(int c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	else if ('a' <= c && c <= 'f')
		return (10 + c - 'a');
	else if ('A' <= c && c <= 'F')
		return (10 + c - 'A');
	else
		return (0);
}
