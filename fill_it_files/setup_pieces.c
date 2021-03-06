/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 01:20:28 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 21:01:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Functions used to setup and update our pieces.
**	___________________________________________________________________________
**		update_pieces : recalculates all values depending of size_square
**		p_yx	: stores y & x in piece->coord[]
**		size_pieces : for a size_square returns how many different times a
**					  piece can be placed
**		coord_setup : fills in every value in the coord struct of a piece
*/

#include "./head.h"

void	update_pieces(t_head *head)
{
	time_exe(__func__, clock());
	int i;

	i = 0;
	while (++i <= head->p)
	{
		find_piece(head, i)->pc_pos =
		size_pieces(find_piece(head, i)->name[0], head->sqsize);
		if (i == 1)
			find_piece(head, i)->tt_pos = find_piece(head, i)->pc_pos;
		else
			find_piece(head, i)->tt_pos =
			find_piece(head, i)->pc_pos + find_piece(head, i - 1)->tt_pos;
		head->tt_pos_all = find_piece(head, i)->tt_pos;
	}
}

void	p_yx(t_piece *piece, int y, int x)
{
	time_exe(__func__, clock());
	piece->y_size = y;
	piece->x_size = x;
}

int		size_pieces(char s, int size)
{
	time_exe(__func__, clock());
	if (s == 'O')
		return ((size - 1) * (size - 1));
	else if (s == 'I')
		return ((size - 3) * size);
	else
		return ((size - 1) * (size - 2));
}

void	pieces_yx(t_piece *tmp)
{
	time_exe(__func__, clock());
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
	time_exe(__func__, clock());
	int		i;

	i = -1;
	while (++i <= 3)
	{
		if (!(piece->coord[i] = (t_coord*)P_MALLOC(sizeof(t_coord))))
		{
			while (i >= 0)
			{
				ft_memdel((void**)&piece->coord[i]);
				piece->coord[i--] = NULL;
			}
			return (0);
		}
	}
	i = -1;
	while (++i <= 3)
	{
		piece->coord[i]->y = ft_nb_char_to_int(piece->name[2 + (i * 2)]);
		piece->coord[i]->x = ft_nb_char_to_int(piece->name[2 + (i * 2) + 1]);
		piece->coord[i]->j = yx_to_j(piece->coord[i]->y, piece->coord[i]->x);
	}
	return (1);
}
