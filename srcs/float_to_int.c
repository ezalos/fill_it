/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:41:09 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/29 06:25:20 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		float_to_int(float i)
{
	int sol;

	if (i % 1 > 0)
		sol = ((int)i / 1) + 1;
	else
		sol = (int)i / 1;
	return (sol);
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

int		yx_to_j(int y_end, int x_end)
{
	int	j;
	int y_;
	int x_;
	int y;
	int x;

	j = 0;
	y_ = -1;
	x_ = -1;
	while (++y_ <= y_end || ++x_ <= x_end)
	{
		x = -1;
		while (++x < y_)
			j++;
		y = -1;
		while (++y <= x_)
			j++;
	}
	return (j);

/*	int		place;

	if (y <= x)
		place = ((y + 1) * (y + 1)) + ((y + 1) * (x - y));
	else
		place = ((x + 1) * (x + 1)) + ((x + 1) * (y - x));
//	place += p;
	return (place);*/
}
