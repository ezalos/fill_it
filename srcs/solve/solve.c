/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/02 19:28:27 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/head.h"

int		deleter_of_competitors(t_head *head, int deepness, int position_choice)
{
	time_exe(__func__, cl(clock()));
	int the_competitor;
	int	position_review;
	int	the_one_in_the_champion;

	position_review = 0;
	the_one_in_the_champion = 0;
//	if (deepness > head->p)
//		return (1);
	head->the_choosen_configuration = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos - 1;
	while (++head->the_choosen_configuration <= find_piece(head, deepness)->tt_pos)
		if (find_sol(head, deepness)->y_all_PxNx[head->the_choosen_configuration] == 1)
		{
			if (position_review < position_choice)
				position_review++;
			else
			{
				while (the_one_in_the_champion < head->p + (head->size_square * head->size_square))
				{
					while (head->solution[head->the_choosen_configuration][the_one_in_the_champion] != 1 && the_one_in_the_champion < head->p + (head->size_square * head->size_square))
						the_one_in_the_champion++;
					the_competitor = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos - 1;
					while (++the_competitor < head->tt_pos_all)
						if (head->solution[the_competitor][the_one_in_the_champion] == 1 && the_competitor != head->the_choosen_configuration)
							find_sol(head, deepness)->y_all_PxNx[the_competitor] = 0;
					the_one_in_the_champion++;
				}
				return (1);
			}
		}
	return (0);
}

int		how_many_paths(t_head *head, int deepness)
{
	time_exe(__func__, cl(clock()));
	int path;

	path = 0;
	head->the_choosen_configuration = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos - 1;
	while (++head->the_choosen_configuration < find_piece(head, deepness)->tt_pos)
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
	return (path);
}

void	sol_turn_mem(t_head *head, int deepness)
{
	time_exe(__func__, cl(clock()));
	if (deepness == 1)
		ft_memcpy(find_sol(head, deepness)->y_all_PxNx, head->y_all_PxNx, head->tt_pos_all);
	else
		ft_memcpy(find_sol(head, deepness)->y_all_PxNx, find_sol(head, deepness-1)->y_all_PxNx, head->tt_pos_all);
	find_sol(head, deepness)->nb_of_paths = how_many_paths(head, deepness);
}

void	print_advance(t_head *head, int deepness, int threshold)
{
	time_exe(__func__, cl(clock()));
	int		i;

	i = 0;
	if (head->p - deepness < threshold)
		return ;
//	while (++i < 10)
//		printf("\n\n\n\n\n\n\n\n\n\n");
	while (++i <= head->p)
		printf("%d %d/%d\n", i, find_sol(head, i)->current_path, find_sol(head, i)->nb_of_paths);
}

int		solve_solution(t_head *head, int deepness)
{
	time_exe(__func__, cl(clock()));
//	int	position_choice;

//	position_choice = -1;
//	printf("\n\ndeepness %d\n", deepness);
	if (deepness <= head->p)
	{
		find_sol(head, deepness)->current_path = -1;
		sol_turn_mem(head, deepness);
		while (++find_sol(head, deepness)->current_path < find_sol(head, deepness)->nb_of_paths)
		{
//			print_advance(head, deepness, -1);
//			printf("%d %d/%d\n", deepness, find_sol(head, deepness)->current_path, find_sol(head, deepness)->nb_of_paths);
//			print_soltion_link_debug(head, deepness, find_sol(head, deepness)->current_path);
			if(!(deleter_of_binaries(head, deepness, find_sol(head, deepness)->current_path)))
				return(0);
//			printf("deleter done\n");
//			print_soltion_link_debug(head, deepness, find_sol(head, deepness)->current_path);
//			printf("ALMOST DONE %d/%d\n", deepness, head->p);
			if (solve_solution(head, deepness + 1))//NEED TO QUIT WHEN ALL IS SOLVED
				return (1);
			sol_turn_mem(head, deepness);

		}
		return (0); //NO SOLUTION
	}
	return (1); //SOLVED
}
