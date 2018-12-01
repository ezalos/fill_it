/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:21 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/01 03:29:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	write_solutions(t_head *head)
{
	t_piece *piece;
	int	i;
	int p;
	int y;
	int x;

	p = 0;
	piece = head->next;
	while (piece->next != NULL) //for each piece convert y and x of possibilty to j, and write 1 to the 4 coord of piece
	{
		y = 0;
		while (piece->coord[0]->y + ++y < head->size_square + 1)
		{
			x = 0;
			while (piece->coord[0]->x + ++x < head->size_square + 1)// <= || < ?
			{
				head->solution[piece->pc_pos + 1][0] = 1;//to say that every line currently exist
				head->solution[piece->pc_pos + 1][p] = 1;//need to write which piece is currently writen +1 & -1 as down
				i = -1;
				while (++i < 4)
					head->solution[piece->pc_pos + 1]
					[head->p + yx_to_j(piece->coord[i]->y + y, piece->coord[i]->x + x) + 1 - 1] //+1 for follow up of solution    -1 bc it's a tab
					= 1;  //Maxwell idea to implement here
			}
		}
		piece = piece->next;
		p++;
	}
}

int		deleter_of_competitors(t_head *head, int deepness, int position_choice)
{
	int the_1_of_the_chosen_configuration;
	int	position_review;
	int	choice_of_path_made;
	int	the_deleter_of_configuration;

	choice_of_path_made = 0;
	position_review = 0;
	head->the_choosen_configuration = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos;
	while (head->the_choosen_configuration < find_piece(head, deepness)->tt_pos && !choice_of_path_made)//need to be active until one is choosen && cant work for last piece && need to change head for current piece and setup for "1st"choice
	{
		if (find_sol(head, deepness)->y_all_PxNx[head->the_choosen_configuration] == 1)//we are choosing the 1st option here, we need to have the choice
		{
			if (position_review <= position_choice)
				position_review++;
			else
			{
				choice_of_path_made = 1;
				the_1_of_the_chosen_configuration = 0;
				while (++the_1_of_the_chosen_configuration < head->tt_pos_all + 1)
				{
					if (head->solution[the_1_of_the_chosen_configuration][head->the_choosen_configuration] == 1)
					{
						the_deleter_of_configuration = 0; //head->the_choosen_configuration; maybe an amelioration
						while (++the_deleter_of_configuration < 1 + head->p + (head->size_square * head->size_square))
								if (head->solution[the_1_of_the_chosen_configuration][the_deleter_of_configuration] == 1)
									find_sol(head, deepness)->y_all_PxNx[the_deleter_of_configuration] = 0;
					}
				}//all competitors of the choosen one have been destroy
			}
		}
		head->the_choosen_configuration++;//in case it's not the 1st time the function is run
	}//we now need to repeat all of this for the second line which exist (and if all the pieces still exists)
	if (head->the_choosen_configuration == find_piece(head, deepness)->tt_pos)//if no possibility, might be unecessary
		return (0);
	return (head->the_choosen_configuration);
}

int		how_many_paths(t_head *head, int deepness)//need to be values that only live in the function
{
	int path;

	path = 0;
	head->the_choosen_configuration = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos;
	while (head->the_choosen_configuration < find_piece(head, deepness)->tt_pos + 1)
	{
		if (find_sol(head, deepness)->y_all_PxNx[head->the_choosen_configuration] == 1)
			path++;
		head->the_choosen_configuration++;
	}
	return (path);
}

int		solve_solution(t_head *head, int deepness)
{
	int	position_choice;

//	deepness = -1; //need to be setup before
	position_choice = -1;
	next_solve_step(head);
	find_sol(head, deepness + 1)->nb_of_paths = how_many_paths(head, deepness + 1);
	while (++deepness < head->p)
	{
		while (++position_choice <= find_sol(head, deepness)->nb_of_paths)
		{
			find_sol(head, deepness)->current_path = position_choice;
			if(!(deleter_of_competitors(head, deepness, position_choice)))
				return(1);
			if (-1 == solve_solution(head, deepness + 1))//NEED TO QUIT WHEN ALL IS SOLVED
				return (-1);
//			delete_last_sol(deepness + 1); //NEED
		}
	}
	return (-1);
}
