/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 04:53:29 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/29 20:35:46 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	p_yx(t_piece *piece, int y, int x)//TO CHANGE
{
	piece->y_size = y;
	piece->x_size = x;
}

int		size_pieces(char *s, int size)
{
	if (*s == 'O')
		return ((size - 1) * (size - 1));
	else if (*s == 'I')
		return ((size - 3) * size);
	else
		return ((size - 1) * (size - 2));
}

/*
void	piece_placement(t_piece *piece)//How can i calculate the nb of possibilities without square_size ? Not logic
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
}*/

void	sum_placement(t_piece *piece)
{
	piece->tt_pos = piece->pc_pos + piece->prev->tt_pos;
}

void	pieces_yx(t_piece tmp)
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

int		nb_char_to_int(char	*c)
{
	if (c < '0' || c > '9')
		return (-1);
	return (c - '0');
}

/*void 	coord_rot(t_piece *piece, int rot)//NEED TO BE DONE FROM PIECE MODEL
{
	int		i;
	int		tmp;

	i = -1;
//	while (++i < rot)
//	{
//		piece->coord[i]->y = x_model(piece->name, i); //need a function holding all values
//		piece->coord[i]->x = -y_model(piece->name, i); //y need to be negative
//	}
	while (++i < rot)
	{
		tmp = piece->coord[i]->y;
		piece->coord[i]->y = piece->coord[i]->x;
		piece->coord[i]->x = -tmp;
	}
}*/

void	coord_setup(t_piece *piece)
{
	int		rot;
	int		i;
	int		x;
	int		y;

	i = -1;
	while (++i <= 3)
	{
		coord[i]->x = nb_char_to_int(name[2 + (i * 2) + 1]);
		coord[i]->y = nb_char_to_int(name[2 + (i * 2)]);
	}
//	coord_rot(piece, nb_char_to_int(name[1]));
}

void	setup_pieces(t_head head)
{
	t_piece		tmp;

	tmp = head.next;
	while (tmp->next != NULL)
	{
		pieces_yx(*tmp);
		tmp->pc_pos = size_pieces(tmp->name[0], head->size_square);
//		piece_placement(tmp); not sure about the purpose of this function
		sum_placement(tmp);
		coord_setup(tmp);
		head->tt_pos_all = tmp->tt_pos;
		tmp = tmp->next.next;
	}
}

t_piece	*malloc_solution(t_head *head)
{
	char	**sol;
	int		i;
	int		line;
	int		u;

	if (!(sol = (char**)malloc(sizeof(char*) * (head->tt_pos_all + 1))))//one +1 for stocking values : best dead space
		return (NULL); //need to protect if malloc has a pbm during allocation
	i = -1;
	line = head->p + (head->size_square * head->size_square) + 1 ((+ 1));//one +1 for stocking values : if possible solution the other +1 for ending null string, might not be necessary
	while (++i < tt_pos_all)
	{
		if (!(sol[i] = (char*)malloc(sizeof(char) * line)))
			return (NULL); //need to protect if malloc has a pbm during allocation
		u = -1;
		while (++u < line)
			sol[i][u] = 0;
	}
	return (sol);
}

t_head	*setup_head(t_head *head)
{
	head->size_square = (float_to_int(f_sqrt(p, 0) * 2));
	setup_pieces(*head);
	if (!(head->solution = malloc_solution(head)))
		return (NULL);
}
