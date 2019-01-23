/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/23 01:36:57 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Functions allowing us to solve fill_it using combinatorial optimization
**	algorithms
**	___________________________________________________________________________
**	fill_it belongs to the NP problems class. Therefore, we did use an
**	algorithm belonging to the NP-Complete class.
**	It operates on the domain of those optimization problems, in which the set
**	of feasible solutions is discrete or can be reduced to discrete,
**	and in which the goal is to find the best solution ; here the smallest
**	square with each piece in the most top-left corner.
**
**	deleter_of_binaries	: deletes every string in head->solution for which
**						  our 'binary_and' applied to the chosen path on
**						  the strings is != 0
**	how_many_paths	: computes for each step in 'solve' how many different
**					  choices can be made when choosing our path of 'solve'
**	sol_turn_mem	: restores the state of being of each string in our
**					  head->solution every time a wrong path has been chosen
**	solve_solution	: recursive part, calls every function in the optimal
**					  order at each step.
*/

#include "./head.h"

int		deleter_of_binaries(t_head *head, int depth, int pos_choy)
{
	int		comp;
	int		pos_rev;
	int		champ;

	pos_rev = 0;
	champ = 0;
	head->config = find_piece(head, depth)->tt_pos
	- find_piece(head, depth)->pc_pos - 1;
	while (++head->config <= find_piece(head, depth)->tt_pos)
		if (find_sol(head, depth)->y_all_pxnx[head->config] == 1)
		{
			if (pos_rev < pos_choy)
				pos_rev++;
			else
			{
				comp = -1;
				while (++comp < head->tt_pos_all)
					if (comp != head->config && binstrand(
						head->solution[head->config], head->solution[comp],
			(size_t)head->p + ((size_t)head->sqsize * (size_t)head->sqsize)))
						find_sol(head, depth)->y_all_pxnx[comp] = 0;
				return (1);
			}
		}
	return (0);
}

int		how_many_paths(t_head *head, int deepness)
{
	int path;

	path = 0;
	head->config = find_piece(head, deepness)->tt_pos -
	find_piece(head, deepness)->pc_pos - 1;
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
	if (deepness == 1)
		ft_memcpy(find_sol(head, deepness)->y_all_pxnx,
		head->y_all_pxnx, (size_t)head->tt_pos_all);
	else
		ft_memcpy(find_sol(head, deepness)->y_all_pxnx,
		find_sol(head, deepness - 1)->y_all_pxnx, (size_t)head->tt_pos_all);
	find_sol(head, deepness)->nb_of_paths = how_many_paths(head, deepness);
}

int		solve_solution(t_head *head, int deepness)
{
	if (deepness <= head->p)
	{
		find_sol(head, deepness)->current_path = -1;
		sol_turn_mem(head, deepness);
		while (++find_sol(head, deepness)->current_path
		< find_sol(head, deepness)->nb_of_paths)
		{
			if (!(deleter_of_binaries(head, deepness,
				find_sol(head, deepness)->current_path)))
				return (0);
			if (solve_solution(head, deepness + 1))
				return (1);
			sol_turn_mem(head, deepness);
		}
		return (0);
	}
	return (1);
}
