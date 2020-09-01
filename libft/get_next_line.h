/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:30:07 by ycameron          #+#    #+#             */
/*   Updated: 2019/10/02 14:54:09 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define NEW_LINE '\n'
# define END_OF_STR 0
# define BUFF_SIZE 32
# define ERROR -1
# define COMPLETE 0
# define SUCCESS 1
# define ZERO 0
# define CHECKMEMORYSUCCESS(res) if (!res) return (ERROR)
# define CHECKINITIALS(input) if (input) return (ERROR)

int		get_next_line(const int fd, char **line);

#endif
