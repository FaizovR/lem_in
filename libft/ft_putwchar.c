/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:41:23 by ycameron          #+#    #+#             */
/*   Updated: 2020/03/09 16:41:23 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

size_t	ft_putwchar(wchar_t chr)
{
	return (ft_putwchar_fd(chr, 1));
}
