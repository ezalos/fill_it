/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 10:07:38 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/25 10:19:35 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "head.h"

void	write_binary(t_head *head)
{
	t_piece *piece;
	int	i;
	int current_piece;
	int	PnNx;
	int y;
	int x;

	current_piece = 0;
	piece = head->next;
	while (piece->next != NULL) //for each piece convert y and x of possibilty to j, and write 1 to the 4 coord of piece
	{
		y = -1;
		PnNx = -1;
		while (++y <= head->size_square - piece->y_size)
		{
			x = -1;
			while (++x <= head->size_square - piece->x_size)
			{
				head->solution[piece->tt_pos - piece->pc_pos + ++PnNx][current_piece] = 1;//need to write which piece is currently writen +1 & -1 as down
				i = -1;
				while (++i < 4)
					head->solution[piece->tt_pos - piece->pc_pos + PnNx]
					[head->p + 1 + yx_to_j(piece->coord[i]->y + y, piece->coord[i]->x + x) - 1] // -1 bc it's a tab ?
					= 1;  //Maxwell idea to implement here
			}
		}
		piece = piece->next;
		current_piece++;
	}

//we need to do it on last time for the last piece, it's just a copy/paste
	y = -1;
	PnNx = -1;
	while (++y < head->size_square - piece->y_size + 1)
	{
		x = -1;
		while (++x < head->size_square - piece->x_size + 1)// <= || < ?
		{
			head->solution[piece->tt_pos - piece->pc_pos + ++PnNx][current_piece] = 1;//need to write which piece is currently writen +1 & -1 as down
			i = -1;
			while (++i < 4)
				head->solution[piece->tt_pos - piece->pc_pos + PnNx]
				[head->p + 1 + yx_to_j(piece->coord[i]->y + y, piece->coord[i]->x + x) - 1] // -1 bc it's a tab ?
				= 1;  //Maxwell idea to implement here
		}
	}
	piece = piece->next;
	current_piece++;
}

int	ft_iterative_power(int nb, int power)
{
	int x;

	x = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 0)
	{
		x = x * nb;
		power--;
	}
	return (x);
}

void	binary_to_str(char *binary, int binary_position)
{
	binary[binary_position / 8] += ft_iterative_power(2, binary_position % 8);
}

int		binary_size(int length)
{
	if (length % 8 != 0)
		return ((length / 8) + 1 + 1);
	return ((length / 8) + 1);
}

char	**malloc_binary(t_head *head)
{

	char	**sol;
	int		i;
	int		line;
	int		u;

	//printf("1\n%d\n", head->tt_pos_all);
	if (!(sol = (char**)malloc(sizeof(char*) * head->tt_pos_all)))
		return (NULL); //need to protect if malloc has a pbm during allocation
	i = -1;
	line = binary_size(head->p + (head->size_square * head->size_square));
	while (++i < head->tt_pos_all)
	{
		if (!(sol[i] = (char*)malloc(sizeof(char) * line)))
			return (NULL); //need to protect if malloc has a pbm during allocation
		u = -1;
		while (++u < line)
			sol[i][u] = 0;
	}
	return (sol);
}
