/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:42:18 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/27 02:07:12 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "head.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_read_check(char **fillit)
{
	char *buf;
	int fd;
	int c_hash;
	int i;

	if (!(buf = (char *)malloc(sizeof(char) * 21)))
		return (0);
	if (!(fd = open(*fillit, O_RDONLY)))
		return (0);
	while (read(fd, buf, 21) == 21)
	{
		i = 0;
		c_hash = 0;
		while (i < 21)
		{
			if (((((i - 4) % 5) == 0) && i != 0) || i == 20)
			{
				if ((buf[i] != '\n' || (buf[i] == '\0' && i == 20)))
					return (0);
				i++;
			} 	// ft_display_error(int error);
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
	}
	return (buf);
}
