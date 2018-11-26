/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:42:18 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/26 22:56:27 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "head.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t len, int *c_backn)
{
	char	*new;
	size_t	i;

	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		new[i] = s[i];
		if (s[i] == '\n')
			c_backn++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_read_check(char **fillit)
{
	char *buf;
	int fd;
	int c_hash;
	int c_backn;
	int i;

	if (!(buf = (char *)malloc(sizeof(char) * 21)))
		return (0);
	if (!(fd = open(*fillit, O_RDONLY)))
		return (0);
	while ((c_backn = read(fd, buf, 21) == 21))
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
		printf("read size %d\n", c_backn);
		printf("hash %d\n", c_hash);
	if (c_hash != 4)
		return (0); // ft_display_error(int error);
	printf("%s", buf);
	printf("nb # %d \n", c_hash);
//	printf("%s\n", (const char)recognize(buf));
	}
	printf("fin read size %d\n", c_backn);
	return (buf);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_read_check(&av[1]);
	}
	return (0);
}