/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:21 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/29 06:15:45 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	**tab_solution()

void	all_solutions(t_head *head)
{
	t_piece *piece;

	piece = head->next;
	while (piece->next != NULL) //for each piece convert y and x of possibilty to j, and write 1 to the 4 coord of piece
	{
		piece->y = 0;
		while (piece->coord[0]->y < head->y_grid - piece->y_size)
		{
			piece->coord[0]->x = 0;
			while (piece->coord[0]->x < head->x_grid - piece->x_size)// <= || < ?
			{
				i = 0;
				while (i < 4)
				{
					head->solution[piece->pc_pos + 1]
					[head->p + yx_to_j(coord[i]->y, coord[i]->x) + 1] //+1 for follow up of solution
					= 1;  //amelioration of Maxwell to implement here
				}
				piece->x++;
			}
		}
		piece = piece->next;
	}
}
