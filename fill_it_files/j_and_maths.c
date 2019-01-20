/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_and_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:30:44 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/20 20:33:58 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
******************************************
**                                  	**
**  set of functions used to calculate	**
**	coordinates using x and y, also		**
**	contains power function    	 	 	**
**                                  	**
******************************************
*/

#include "./head.h"

int		yx_to_j(int y, int x)
{
	if (y >= x)
		return ((y * (y + 1)) + x);
	else
		return ((x * x) + y);
}

int		j_to_yx(t_head *head, int j, int o)
{
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

int		ft_iterative_power(int nb, int power)
{
	int x;

	x = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power-- > 0)
		x *= nb;
	return (x);
}
