/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_and_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:30:44 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/11 22:07:24 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  set of functions used to calculate J coordinates using X and Y.
**			J coord allows to name each case using only one number
**			The lower the J coord is, the better the piece placement will be
**	___________________________________________________________________________
**		yx_to_j : translates Y and X coordinates into a J coordinate
**		j_to_yx	: if o == 0	: translates J into Y
**				  if o == 1	: translates J into X
**
**	  +------ 0 - 1 - 2 - 3 -->	 X
**	  |
**	  |		|---+---+---+---+
**	  0		| 0	| 1	| 4	| 9 |
**	  |		|---+---+---+---+
**	  1		| 2	| 3	| 5	|10	|
**	  |		|---+---+---+---+
**	  3		| 6	| 7	| 8	|11	|
**	  |		|---+---+---+---+
**	  4		|12 |13	|14	|15	|
**	  |		|---+---+---+---+
**    V
**
**    Y
*/

#include "./head.h"

int		yx_to_j(int y, int x)
{
	time_exe(__func__, clock());
	if (y >= x)
		return ((y * (y + 1)) + x);
	else
		return ((x * x) + y);
}

int		j_to_yx(t_head *head, int j, int o)
{
	time_exe(__func__, clock());
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
