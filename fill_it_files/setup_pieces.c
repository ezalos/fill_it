/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 01:20:28 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/16 16:48:52 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	p_yx(t_piece *piece, int y, int x)//TO CHANGE
{
	time_exe(__func__, cl(clock()));
	piece->y_size = y;
	piece->x_size = x;
}

int		size_pieces(char s, int size)
{
	time_exe(__func__, cl(clock()));
	if (s == 'O')
		return ((size - 1) * (size - 1));
	else if (s == 'I')
		return ((size - 3) * size);
	else
		return ((size - 1) * (size - 2));
}

void	pieces_yx(t_piece *tmp)
{
	time_exe(__func__, cl(clock()));
	if (tmp->name[0] == 'O')
		p_yx(tmp, 2, 2);
	else if (tmp->name[0] == 'I')
	{
		if (tmp->name[1] == '0')
			p_yx(tmp, 4, 1);
		else
			p_yx(tmp, 1, 4);
	}
	else if (ft_char_srch(tmp->name[0], "JL"))
	{
		if ((tmp->name[1] - '0') % 2 == 0)
			p_yx(tmp, 3, 2);
		else
			p_yx(tmp, 2, 3);
	}
	else if (ft_char_srch(tmp->name[0], "SZT"))
	{
		if ((tmp->name[1] - '0') % 2 != 0)
			p_yx(tmp, 3, 2);
		else
			p_yx(tmp, 2, 3);
	}
}

int		coord_setup(t_piece *piece)
{
	time_exe(__func__, cl(clock()));
	int		rot;
	int		i;
	int		x;
	int		y;

	i = -1;
	while (++i <= 3)
	{
		if (!(piece->coord[i] = (t_coord*)malloc(sizeof(t_coord))))
		{
			while (i >= 0)
			{
				free(piece->coord[i]);
				piece->coord[i--] = NULL;
			}
			return (0);
		}
	}

	i = -1;
	while (++i <= 3)
	{
		piece->coord[i]->y = nb_char_to_int(piece->name[2 + (i * 2)]);
		piece->coord[i]->x = nb_char_to_int(piece->name[2 + (i * 2) + 1]);
		piece->coord[i]->j = yx_to_j(piece->coord[i]->y, piece->coord[i]->x);
	}
	return (1);
}
