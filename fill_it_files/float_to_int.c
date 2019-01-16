/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:41:09 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/16 14:00:59 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_char_srch(char src, char *dlt)
{
	time_exe(__func__, cl(clock()));
	while (*dlt)
	{
		if (src == *dlt)
			return (1);
		dlt++;
	}
	return (0);
}

int		yx_to_j(int y, int x)
{
	time_exe(__func__, cl(clock()));

	if (y >= x)
		return ((y * (y + 1)) + x);
	else
		return ((x * x) + y);
}

int		j_to_yx(t_head *head, int j, int o)
{
	time_exe(__func__, cl(clock()));
	int		x;
	int		y;

	y = -1;
	while (++y <= head->sqsize)
	{
		x = -1;
		while (++x <= head->sqsize)
		{
			if (j == yx_to_j(y, x))
			{
				if (o == 0)
					return (y);
				else
					return (x);
			}
		}
	}
	return (-1);
}

int		nb_char_to_int(char	c)
{
	time_exe(__func__, cl(clock()));
	if (c < '0' || c > '9')
		return (-1);
	return (c - '0');
}
