/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:21 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/20 12:45:38 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		deleter_of_competitors(t_head *head, int deepness, int position_choice)
{
	int the_competitor;
	int	position_review;
	int	choice_of_path_made;
	int	the_deleter_of_configuration;
	int	the_one_in_the_champion;
	int save;

	//printf(_MAGENTA "DELETER OF COMPETITORS, with choice n*%d\n", position_choice);
	choice_of_path_made = 0;
	position_review = 0;
	the_one_in_the_champion = -1;
	head->the_choosen_configuration = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos;
	//printf("\tthe_choosen_configuration start with %d/%d\n", head->the_choosen_configuration, find_piece(head, deepness)->tt_pos);
	//if (head->the_choosen_configuration != 0)
	//	head->the_choosen_configuration++;
	while (head->the_choosen_configuration <= find_piece(head, deepness)->tt_pos && !choice_of_path_made)//need to be active until one is choosen && cant work for last piece && need to change head for current piece and setup for "1st"choice
	{
		if (find_sol(head, deepness)->y_all_PxNx[head->the_choosen_configuration] == 1)//we are choosing the 1st option here, we need to have the choice
		{
			////printf("\t\tWe found a line that exist: %d\t%d/%d\n", head->the_choosen_configuration, position_review, position_choice);
			if (position_review < position_choice)
				position_review++;
			else
			{
				//printf("\t\t\tWE HAVE CHOOSED A CONFIGURATION: %d\n", head->the_choosen_configuration);
				save = head->the_choosen_configuration;
				while (the_one_in_the_champion < head->p + (head->size_square * head->size_square))
				{
					the_one_in_the_champion++;
					while (head->solution[head->the_choosen_configuration][the_one_in_the_champion] != 1 && the_one_in_the_champion < head->p + (head->size_square * head->size_square))
						the_one_in_the_champion++;
					////printf("\t\t\t\tWe focus on on the %dth char of the line %d\n", the_one_in_the_champion, head->the_choosen_configuration);
					choice_of_path_made = 1;
					the_competitor = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos;
					head->the_choosen_configuration = save;
					//////printf("Starting the deleter of configuration\n");
					//write(1, "\t\t\t\t", 4);
					while (the_competitor < head->tt_pos_all)
					{
		//				while (find_sol(head, deepness)->y_all_PxNx[the_deleter_of_configuration] == 0) //might speed up the process or not
		//					the_deleter_of_configuration++;
						if (head->solution[the_competitor][the_one_in_the_champion] == 1 && the_competitor != save)
						{
							//ft_putnbr(the_competitor - 1);
							//write(1, "|", 1);
							the_deleter_of_configuration = -1; //head->the_choosen_configuration; maybe an amelioration
					//		while (++the_deleter_of_configuration < head->p + (head->size_square * head->size_square))
					//				if (head->solution[the_deleter_of_configuration][the_competitor] == 1)
										find_sol(head, deepness)->y_all_PxNx[the_competitor] = 0;
						}
						the_competitor++;
					}
					//write(1, "\n", 1);
				}//all competitors of the choosen one have been destroy
				//printf("GOOD END OF DELETER OF COMPETITORS.\tthe_choosen_configuration: %d/%d\n" _RESET, save, find_piece(head, deepness)->tt_pos);
				time_exe(__func__, cl(clock()));
				return (1);
			}
		}
		head->the_choosen_configuration++;//in case it's not the 1st time the function is run
	}//we now need to repeat all of this for the second line which exist (and if all the pieces still exists)
	//printf("BAD END OF DELETER OF COMPETITORS.\tthe_choosen_configuration: %d/%d\n" _RESET, save, find_piece(head, deepness)->tt_pos);
	time_exe(__func__, cl(clock()));
	return (0);
	/*if (head->the_choosen_configuration == find_piece(head, deepness)->tt_pos)//if no possibility, might be unecessary
		return (0);
	return (head->the_choosen_configuration);*/
}

int		how_many_paths(t_head *head, int deepness)//need to be values that only live in the function
{
	int path;

	path = 0;
	////printf("how_many_paths. Deepness: %d\n", deepness);
	head->the_choosen_configuration = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos;
	while (head->the_choosen_configuration < find_piece(head, deepness)->tt_pos)
	{
//		////printf("Segmentation Fault ?\n");
		if (deepness == 0)
		{
			if (head->y_all_PxNx[head->the_choosen_configuration] == 1)
				path++;
		}
		else
		{
			if (find_sol(head, deepness)->y_all_PxNx[head->the_choosen_configuration] == 1)
				path++;
		}
//		////printf("Prout\n");
		head->the_choosen_configuration++;
	}
	////printf("Nb of paths = %d\n", path);
	return (path);
}

int		solve_solution(t_head *head, int deepness)
{
	int	position_choice;
	int r_val;
	char c;

//	deepness = -1; //need to be setup before
	position_choice = -1;
	//printf("ENTER Solve_Solution. Deepness: %d\n", deepness);
	if (deepness <= head->p)
	{
		if (deepness == 1)
			ft_memcpy(find_sol(head, deepness)->y_all_PxNx, head->y_all_PxNx, head->tt_pos_all);
		else
			ft_memcpy(find_sol(head, deepness)->y_all_PxNx, find_sol(head, deepness-1)->y_all_PxNx, head->tt_pos_all);
		//print_soltion_link_debug(head, deepness);
		find_sol(head, deepness)->nb_of_paths = how_many_paths(head, deepness);
//		while (++position_choice < find_piece(head, deepness)->pc_pos)
		while (++position_choice < find_sol(head, deepness)->nb_of_paths)
		{
			find_sol(head, deepness)->current_path = position_choice;
			//printf(_CYAN "BEF\tPlacement of\t%d/%d piece\n\t\tCurrent try\t%d/%d\n" _RESET, deepness, head->p, position_choice, find_sol(head, deepness)->nb_of_paths);
			//find_sol(head, deepness)->current_path = position_choice;
			if(!(deleter_of_competitors(head, deepness, position_choice)))
				return(1);
//			print_soltion_link_debug(head, deepness);
			//printf(_CYAN "AFT\tPlacement of\t%d/%d piece\n\t\tCurrent try\t%d/%d\n" _RESET, deepness, head->p, position_choice, find_sol(head, deepness)->nb_of_paths);
			if (solve_solution(head, deepness + 1) == -1)//NEED TO QUIT WHEN ALL IS SOLVED
				return (-1);
			find_sol(head, deepness)->nb_of_paths = how_many_paths(head, deepness);
	//		scanf("%c\n", &c);
			if (deepness == 1)
				ft_memcpy(find_sol(head, deepness)->y_all_PxNx, head->y_all_PxNx, head->tt_pos_all);
			else
				ft_memcpy(find_sol(head, deepness)->y_all_PxNx, find_sol(head, deepness-1)->y_all_PxNx, head->tt_pos_all);
			find_sol(head, deepness)->nb_of_paths = how_many_paths(head, deepness);

		}
		return (1); //NO SOLUTION
	}
	return (-1); //SOLVED
}
