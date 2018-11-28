/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:21 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/27 16:40:25 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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
	int		place;

	if (y <= x)
		place = ((y + 1) * (y + 1)) + ((y + 1) * (x - y));
	else
		place = ((x + 1) * (x + 1)) + ((x + 1) * (y - x));
	place += p;
	return (place);
}

void	p_yx(char **tab_sol, int y, int x, int i, int size_square)
{
	int actual;
	int	add_x;
	int	add_y;
	int	o;

	actual = -1;
	o = 0;
	while (x <= size_square && y <= size_square) //for a small rectangle that exactly contains the piece (i.e. : 2*3 for T0), y & x is the last square of this rectangle
	{
		++actual;
		tab_sol[i + actual][yx_to_j(y, x) + coord0] = 1;
		tab_sol[i + actual][yx_to_j(y, x) + coord(piece, 1, actual)] = 1;
		tab_sol[i + actual][yx_to_j(y, x) + coord2] = 1;
		tab_sol[i + actual][yx_to_j(y, x) + coord3] = 1;
		if (o == 0)
		{
			y++;
			if (y == small_size - 1)
			{
				x = y;
				o = 1;
			}
		}
		else if (o == 1)
		{
			x--;
			if (x == -1)
			{
				o = 2;
			}
		}
		else if (o == 2)
		{
			x--;
			o = 3;
		}
		else if (o == 1)
		{

		}

	}
}

void	all_positions(char **tab_sol, int p, list pieces, int size_square)
{
	int		i;

	i = -1;
	while (++i < p)
	{
		if (pieces[i][0] == 'O')
			p_yx(tab_sol, 2, 2, i, size_square);//write dimension in structure
		if (pieces[i][0] == 'I')
			if (pieces[i][1] == '0')
				p_yx(4, 1);
			else
				p_yx(1, 4);
		if (ft_char_srch(pieces[i][0], "JL"))
			if ((pieces[i][1] - '0') % 2 == 0)
				p_yx(3, 2);
			else
				p_yx(2, 3);
		if (ft_char_srch(pieces[i][0], "SZT"))
			if ((pieces[i][1] - '0') % 2 != 0)
				p_yx(3, 2);
			else
				p_yx(2, 3);
	}
}
