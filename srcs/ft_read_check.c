/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:42:18 by aboitier          #+#    #+#             */
/*   Updated: 2018/12/13 22:09:51 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int ft_check_input(int fd, char *buf, t_head **head)
{
	int 	i;
	int		c_hash;
	char	p;

	while (read(fd, buf, 21) >= 21)
	{
		i = 0;
		c_hash = 0;
		while (i < 21)
		{
			if (((((i - 4) % 5) == 0) && i != 0) || i == 20)
			{
				if ((buf[i] != '\n' || (buf[i] == '\0' && i == 20)))
					return (0); // ft_display_error(int error);
				i++;
			}
			else if (buf[i] == '#')
			{
				c_hash++;
				i++;
			}
			else if (buf[i] == '.')
				i++;
			else
				return (0);	//	ft_display_error(int error)
		}
		if (c_hash != 4)
			return (0); // ft_display_error(int error);
		if (!(create_tetro(recognize(buf), head, ++(*head)->p + '1')))
			return (0);
	}
	return (1);
}

t_head	*ft_read_check(char *fillit)
{
	char 	*buf;
	t_head 	*head;
	int 	fd;

	if (!(buf = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	if (!(fd = open((const char*)fillit, O_RDONLY)))
		return (NULL);
	if (!(head = (t_head*)malloc(sizeof(t_head))))
		return (NULL);
	head->next = NULL;
	head->p = 0;
	if (ft_check_input(fd, buf, &head))
		return (head);
	return (NULL);
}
