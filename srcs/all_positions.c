/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:21 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/30 22:52:31 by ldevelle         ###   ########.fr       */
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

int		deleter_of_competitors(t_head *head, int position_choice, int deepness)
{
	int the_1_of_the_chosen_configuration;
	int	position_review;
	int	choice_of_path_made;

	choice_of_path_made = 0;
	position_review = 0;
	head->the_choosen_configuration = find_piece(deepness)->tt_pos - find_piece(deepness)->pc_pos
	while (head->the_choosen_configuration < head->next->pc_pos + 1 && !choice_of_path_made)//need to be active until one is choosen && cant work for last piece && need to change head for current piece and setup for "1st"choice
	{
		if (head->solution[0][head->the_choosen_configuration] == 1)//we are choosing the 1st option here, we need to have the choice
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
									head->solution[0][the_deleter_of_configuration] == 0;
					}
				}//all competitors of the choosen one have been destroy
			}
		}
		head->the_choosen_configuration++;//in case it's not the 1st time the function is run
	}//we now need to repeat all of this for the second line which exist (and if all the pieces still exists)
	if (head->the_choosen_configuration == head->next->pc_pos)//if no possibility, might be unecessary
		return (-1);
	return (head->the_choosen_configuration);
}

int		how_many_paths(int piece, int the_choosen_configuration)//need to be values that only live in the function
{
	int path;

	path = 0;
	while (the_choosen_configuration < find_piece(piece)->pc_pos + 1)
	{
		if (head->solution[0][the_choosen_configuration] == 1)
			path++;
		the_choosen_configuration++;
	}
	return (path);
}

void	save_solution(int the_choosen_configuration)
{

}

int		solve_solution(t_head *head)
{

}
/*
int		solve_solution(t_head *head)
{
	int	current_path;
	int	number_of_paths;
	int save;

	if (head->the_choosen_configuration == head->next->pc_pos)
		return (did_it_work());

	if (!(number_of_paths = how_many_paths(head->the_choosen_configuration))//IF no paths : no solutions
		return (NO SOLUTIONS);
	save = head->the_choosen_configuration;
	current_path = 0;
	while (is_unsolved())
	{
		while (current_path < number_of_paths))
		{
			head->the_choosen_configuration = save;
			//we also need to tweek back all the 0 and 1 that have been changed
			solve_solution(save_solution(deleter_of_competitors(&head, current_path)));
		}
	}
	clean_solution(&head);
	head->the_choosen_configuration++;
	return (solve_solution(&head));
}*/

	//if work, save config
	//then clean up mess and restart function with the choosen one + 1;

	//which line have the less 1 ? choose the first of them
	//delete line (change 1 in 0) for each one meeting a 1 of the column
	//repeat the process on the new tab in a new function (recursive)
		//if good
			//save the coordinate of each piece and her dead space
		//else
			//choose the next line
