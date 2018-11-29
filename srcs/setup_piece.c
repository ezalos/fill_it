/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 04:53:29 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/29 06:15:33 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	p_yx(s_piece *piece, int y, int x)//TO CHANGE
{
	piece->y_size = y;
	piece->x_size = x;
}

void 	coord_rot(s_piece *piece, int rot)//NEED TO BE DONE FROM PIECE MODEL
{
	int		i;

	i = -1;
	while (++i < rot)
	{
		piece->coord[i]->y = x_model(piece->name, i); //need a function holding all values
		piece->coord[i]->x = -y_model(piece->name, i); //y need to be negative
	}
}

void	piece_placement(s_piece *piece)
{
	if (piece->x_size <= piece->y_size) //not sur about the equal, might be < only
	{
		piece->pc_pos = ((piece->x_size + 1) * (piece->x_size + 1) +
					(piece->x_size * (piece->y_size - piece->x_size));
	}
	else
	{
		piece->pc_pos = ((piece->y_size + 1) * (piece->y_size + 1) +
					(piece->y_size * (piece->x_size - piece->y_size));
	}
}

void	sum_placement(s_piece *piece)
{
	piece->tt_pos = piece->pc_pos + piece->prev->tt_pos;
}

void	setup(s_head head)
{
	t_piece		tmp;

	tmp = head.next;
	while (tmp->next != NULL)
	{
		
		tmp = tmp->next.next;
	}
}

void	pieces_yx(s_piece tmp)
{
	if (tmp->name[0] == 'O')
		p_yx(tmp, 2, 2);
	else if (tmp->name[0] == 'I')
		if (tmp->name[1] == '0')
			p_yx(tmp, 4, 1);
		else
			p_yx(tmp, 1, 4);
	else if (ft_char_srch(tmp->name[0], "JL"))
		if ((tmp->name[1] - '0') % 2 == 0)
			p_yx(tmp, 3, 2);
		else
			p_yx(tmp, 2, 3);
	else if (ft_char_srch(tmp->name[0], "SZT"))
		if ((tmp->name[1] - '0') % 2 != 0)
			p_yx(tmp, 3, 2);
		else
			p_yx(tmp, 2, 3);
}
