/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/16 17:01:46 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		deleter_of_competitors(t_head *head, int deepness, int position_choice)
{
	time_exe(__func__, cl(clock()));
	int the_competitor;
	int	position_review;
	int	the_one_in_the_champion;

	position_review = 0;
	the_one_in_the_champion = 0;
	head->config = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos - 1;
	while (++head->config <= find_piece(head, deepness)->tt_pos)
		if (find_sol(head, deepness)->y_all_pxnx[head->config] == 1)
		{
			if (position_review < position_choice)
				position_review++;
			else
			{
				while (the_one_in_the_champion < head->p + (head->sqsize * head->sqsize))
				{
					while (head->solution[head->config][the_one_in_the_champion] != 1 && the_one_in_the_champion < head->p + (head->sqsize * head->sqsize))
						the_one_in_the_champion++;
					the_competitor = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos - 1;
					while (++the_competitor < head->tt_pos_all)
						if (head->solution[the_competitor][the_one_in_the_champion] == 1 && the_competitor != head->config)
							find_sol(head, deepness)->y_all_pxnx[the_competitor] = 0;
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
	head->config = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos - 1;
	while (++head->config < find_piece(head, deepness)->tt_pos)
		if (deepness == 0)
		{
			if (head->y_all_pxnx[head->config] == 1)
				path++;
		}
		else
		{
			if (find_sol(head, deepness)->y_all_pxnx[head->config] == 1)
				path++;
		}
	return (path);
}

void	sol_turn_mem(t_head *head, int deepness)
{
	time_exe(__func__, cl(clock()));
	if (deepness == 1)
		ft_memcpy(find_sol(head, deepness)->y_all_pxnx, head->y_all_pxnx, head->tt_pos_all);
	else
		ft_memcpy(find_sol(head, deepness)->y_all_pxnx, find_sol(head, deepness-1)->y_all_pxnx, head->tt_pos_all);
	find_sol(head, deepness)->nb_of_paths = how_many_paths(head, deepness);
}

int		solve_solution(t_head *head, int deepness)
{
	time_exe(__func__, cl(clock()));
	if (deepness <= head->p)
	{
		find_sol(head, deepness)->current_path = -1;
		sol_turn_mem(head, deepness);
		while (++find_sol(head, deepness)->current_path < find_sol(head, deepness)->nb_of_paths)
		{
//			print_advance(head, deepness, 7);
//			print_soltion_link_debug(head, deepness, find_sol(head, deepness)->current_path);
			if(!(deleter_of_binaries(head, deepness, find_sol(head, deepness)->current_path)))
				return(0);
			if (solve_solution(head, deepness + 1))
				return (1);
			sol_turn_mem(head, deepness);

		}
		return (0);
	}
	return (1);
}
