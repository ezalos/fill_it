/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:41:09 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/26 16:44:07 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		float_to_int(float i)
{
	time_exe(__func__, cl(clock()));
	return ((int)((i / 1) + 0.99999));
}

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
	while (++y <= head->size_square)
	{
		x = -1;
		while (++x <= head->size_square)
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

float	f_sqrt(int nb, int limite)
{
	time_exe(__func__, cl(clock()));
	float	x;
	float	n;
	int		i;

	n = (float)nb;
	if (nb <= 0)
		return (0);
	i = 0;
	x = n / 2;
	if (limite == 0)
		limite = 30;
	while (--limite)
		x = (x + (n / x)) / 2;
	return (x);
}
