/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:42:18 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/29 00:46:36 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int ft_check_input(int fd, char *buf)
{
	while (read(fd, buf, 21) <= 20)
	{
		int i;
		int c_hash;

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
	ft_lstnew(recognize(buf), 2);
	}
	return (1);
}

char	*ft_read_check(char *fillit)
{
	char *buf;
	int fd;
	int c_hash;
	int i;

	if (!(buf = (char *)malloc(sizeof(char) * 21)))
		return (0);
	if (!(fd = open((const char*)fillit, O_RDONLY)))
		return (0);
	ft_check_input(fd, buf);
	return (NULL);
}
