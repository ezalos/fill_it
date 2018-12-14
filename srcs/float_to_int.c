/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:41:09 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/14 17:54:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		float_to_int(float i)
{
	int sol;

//	if (i % 1 > 0)
//		sol = ((int)i / 1) + 1;
//	else
//		sol = (int)i / 1;
	return (((int)i / 1) + 0.9999);
}

int		ft_char_srch(char src, char *dlt)
{
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
	int nb;

	if (y >= x)
		return ((y * (y + 1)) + x);
	else
	{
		nb = 1;
//		if (y == 0 && x == 1)
//			return (1);
/*		while (x > y)
		{
			nb = nb + 2;
			x--;
		}
		return ((y * (y + 1)) + nb);*/
		return ((x * x) + y);
	}
}

int		nb_char_to_int(char	c)
{
	if (c < '0' || c > '9')
		return (-1);
	return (c - '0');
}

float	f_sqrt(int nb, int limite)
{
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
