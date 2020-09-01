/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycameron <ycameron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:28:52 by ycameron          #+#    #+#             */
/*   Updated: 2020/03/09 16:45:15 by ycameron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_new_line(t_list *node, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;
	char	**str;

	len = ZERO;
	str = (char**)&node->content;
	while ((*str)[len] != NEW_LINE && (*str)[len] != END_OF_STR)
		len++;
	if ((*str)[len] == NEW_LINE)
	{
		CHECKMEMORYSUCCESS((*line = ft_strsub(*str, 0, len)));
		CHECKMEMORYSUCCESS((tmp = ft_strdup(*str + len + 1)));
		ft_strdel(&*str);
		*str = tmp;
		if (**str == END_OF_STR)
			ft_strdel(str);
	}
	else if ((*str)[len] == END_OF_STR)
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		CHECKMEMORYSUCCESS((*line = ft_strdup(*str)));
		ft_strdel(str);
	}
	return (SUCCESS);
}

static t_list	*contains(t_list *list, const int fd)
{
	while (list)
	{
		if (list->content_size == (size_t)fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

static int		append(char *buf, const int fd, t_list **list, t_list **elem)
{
	t_list	*node;

	CHECKMEMORYSUCCESS((node = ft_lstnew((void*)buf, ft_strlen(buf) + 1)));
	node->content_size = (size_t)fd;
	ft_lstpush_back(list, node);
	*elem = node;
	return (SUCCESS);
}

static int		update_line(char *buf, t_list *node)
{
	char	*tmp;
	char	**str;

	str = (char**)&node->content;
	CHECKMEMORYSUCCESS((tmp = ft_strjoin(*str, buf)));
	ft_strdel(&*str);
	node->content = (void*)tmp;
	return (SUCCESS);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	char			buf[BUFF_SIZE + 1];
	int				cnt;
	t_list			*node;

	CHECKINITIALS(fd < ZERO || line == NULL);
	node = contains(list, fd);
	while ((cnt = read(fd, (void*)buf, BUFF_SIZE)) > ZERO)
	{
		buf[cnt] = END_OF_STR;
		if (node == NULL)
		{
			CHECKMEMORYSUCCESS((append(buf, fd, &list, &node)));
		}
		else
			CHECKMEMORYSUCCESS((update_line(buf, node)));
		if (ft_strchr(buf, NEW_LINE))
			break ;
	}
	if (cnt < ZERO)
		return (ERROR);
	else if (cnt == ZERO && (node == NULL ||
		(char*)node->content == NULL || *(char*)node->content == END_OF_STR))
		return (COMPLETE);
	return (ft_new_line(node, line, fd, cnt));
}
