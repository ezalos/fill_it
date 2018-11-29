/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:21 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/29 23:45:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	**tab_solution()

void	write_solutions(t_head *head)
{
	t_piece *piece;
	int p;
	int y;
	int x;

	p = 0;
	piece = head->next;
	while (piece->next != NULL) //for each piece convert y and x of possibilty to j, and write 1 to the 4 coord of piece
	{
		y = 0;
		while (piece->coord[0]->y + ++y < head->square_size + 1)
		{
			piece->coord[0]->x = 0;//DEAD SPACE is stored here
			x = 0;
			while (piece->coord[0]->x + ++x < head->square_size + 1)// <= || < ?
			{
				head->solution[piece->pc_pos + 1][0] = 1;//to say that every line currently exist
				head->solution[piece->pc_pos + 1][p] = 1;//need to write which piece is currently writen +1 & -1 as down
				i = -1;
				while (++i < 4)
					head->solution[piece->pc_pos + 1]
					[head->p + yx_to_j(coord[i]->y + y, coord[i]->x + x) + 1 - 1] //+1 for follow up of solution    -1 bc it's a tab
					= 1;  //Maxwell idea to implement here
			}
		}
		piece = piece->next;
		p++;
	}
}

void	clean_solution(t_head *head)
{
	int y;
	int x;

	y = 0;
	while (piece->coord[0]->y + ++y < head->square_size + 1)
	{
		piece->coord[0]->x = 0;//DEAD SPACE is stored here
		x = 0;
		while (piece->coord[0]->x + ++x < head->square_size + 1)// <= || < ?
			head->solution[piece->pc_pos + 1][0] = 1;//to say that every line currently exist
	}
}

int		solve_solution(t_head *head)
{
	int sum_one_of_line;
	int best_line_of_sum_one;
	int duplication;

	head->possible_solutions = 0;//need to be setup before
	head->first_try = 1;//need to be setup before


	while (head->first_try < head->next->pc_pos + 1)
	{
		if (head->solution[0][head->first_try] == 1)
		{
			duplication = 0;
			while (++duplication < head->tt_pos_all + 1)
			{
				try = head->first_try;
				while (++try < 1 + head->p + (head->size_square * head->size_square))
					if (head->solution[duplication][head->first_try] == 1)
						if (head->solution[duplication][try] == 1)
							head->solution[0][try] == 0;
			}
		}
		else
			head->first_try++;
	}

	//which line have the less 1 ? choose the first of them
	//delete line (change 1 in 0) for each one meeting a 1 of the column
	//repeat the process on the new tab in a new function (recursive)
		//if good
			//save the coordinate of each piece and her dead space
		//else
			//choose the next line
}
