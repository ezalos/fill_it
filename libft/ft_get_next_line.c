/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:03:34 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/06 15:57:22 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		send_exceptions(char **line, t_list *gnl)
{
	if (gnl->content == NULL)
	{
		if (!(*line = ft_memalloc(1)))
			return (-1);
		return (0);
	}
	if (NULL == ft_strchr((char*)gnl->content, '\n'))
	{
		if (!(*(char*)gnl->content))
		{
			if (!(*line = ft_memalloc(1)))
				return (-1);
		}
		else
		{
			if (!(*line = ft_strsub((char*)gnl->content, 0,
			ft_strlen((char*)gnl->content))))
				return (-1);
		}
		ft_bzero(gnl->content, ft_strlen((char*)gnl->content));
		return (1);
	}
	return (1);
}

int		send_line(char **line, t_list *gnl)
{
	int		size_line;

	if (gnl->content == NULL || NULL == ft_strchr((char*)gnl->content, '\n'))
		return (send_exceptions(line, gnl));
	size_line = (int)(ft_strchr((char*)gnl->content, '\n')
	- (char*)gnl->content);
	if (!(*line = ft_strsub((char*)gnl->content, 0, size_line)))
		return (-1);
	ft_memmove((char*)gnl->content, (char*)gnl->content + size_line + 1,
			   ft_strlen((char*)gnl->content + size_line + 1) + 1);
	return (1);
}

int		save_file(t_list *gnl, char *buf, int read)
{
	char	*new;
	int		size_save;
	int		i;

	if (gnl->content != NULL)
		size_save = ft_strlen((char*)gnl->content);
	else
	{
		if (!(gnl->content = ft_memalloc(1)))
			return (-2);
		size_save = 0;
	}
	if (!(new = ft_strjoin(gnl->content, buf)))
		return (-2);
	ft_strdel((char**)&gnl->content);
	gnl->content = new;
	ft_bzero(buf, BUFF_SIZE + 1);
	if (read != BUFF_SIZE)
		return (1);
	i = -1;
	while (++i <= (read + size_save))
		if (((char*)gnl->content)[i] == '\n')
			return (i);
	return (-1);
}

int		get_line(t_list *gnl, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				v_read;
	int				v_save;

	ft_bzero(buf, BUFF_SIZE + 1);
	while (0 < (v_read = read(gnl->content_size, buf, BUFF_SIZE)))
	{
		if (-2 == (v_save = save_file(gnl, buf, v_read)))
			return (-1);
		if (v_save >= 0)
			return (send_line(line, gnl));
	}
	if (v_read == -1)
		return (-1);
	if (!(gnl->content) || 0 == ft_strlen(gnl->content))
		return (0);
	if (v_read == 0)
		return (send_line(line, gnl));
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	*gnl;
	t_list			*tmp;

	if (BUFF_SIZE < 1 || !line || fd > OPEN_MAX || fd < 0)
		return (-1);
	if (gnl == (t_list*)NULL)
	{
		if (!(gnl = ft_lstnew(0, fd)))
			return (-1);
		gnl->content_size = (size_t)fd;
		return (get_line(gnl, line));
	}
	tmp = gnl;
	if (tmp->content_size == (size_t)fd)
		return (get_line(tmp, line));
	while (tmp->next != NULL)
	{
		if (tmp->next->content_size == (size_t)fd)
			return (get_line(tmp->next, line));
		tmp = tmp->next;
	}
	if (!(tmp->next = ft_lstnew(0, fd)))
		return (-1);
	tmp->next->content_size = (size_t)fd;
	return (get_line(tmp->next, line));
}
