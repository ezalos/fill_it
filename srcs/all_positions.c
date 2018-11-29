/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:21 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/29 07:51:13 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	**tab_solution()

void	write_solutions(t_head *head)
{
	t_piece *piece;
	int p;

	p = 0;
	piece = head->next;
	while (piece->next != NULL) //for each piece convert y and x of possibilty to j, and write 1 to the 4 coord of piece
	{
		piece->y = 0;
		while (piece->coord[0]->y < head->y_grid - piece->y_size)
		{
			piece->coord[0]->x = 0;
			while (piece->coord[0]->x < head->x_grid - piece->x_size)// <= || < ?
			{
				head->solution[piece->pc_pos + 1][0] = 1;
				head->solution[piece->pc_pos + 1][p] = 1;//need to write which piece is currently writen +1 & -1 as down
				i = -1;
				while (++i < 4)
					head->solution[piece->pc_pos + 1]
					[head->p + yx_to_j(coord[i]->y, coord[i]->x) + 1 - 1] //+1 for follow up of solution    -1 bc it's a tab
					= 1;  //Maxwell idea to implement here
				piece->x++;
			}
		}
		piece = piece->next;
		p++;
	}
}

void	solve_solution(t_head *head)
{
	//which line have the less 1 ? choose the first of them
	//delete line (change 1 in 0) for each one meeting a 1 of the column
	//repeat the process on the new tab in a new function (recursive)
		//if good
			//save the coordinate of each piece and her dead space
		//else
			//choose the next line
}
