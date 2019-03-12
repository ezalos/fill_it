/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 04:53:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 21:01:59 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Set of functions for our structure which :
**	___________________________________________________________________________
**		init_head	: initializes variables in head structure's fields
**		next_solve_step	: allocates memory to manage the solution setup
**		setup_pieces	: computes each value of the pieces struct and
**						  fill them in
**		setup_	: calls every necessary function for the setup of all
**				  our structs
*/

#include "./head.h"

void	init_head(t_head *head)
{
	head->solution = NULL;
	head->y_all_pxnx = NULL;
	head->p = 0;
	head->sqsize = 0;
	head->tt_pos_all = 0;
	head->pos_sol = 0;
	head->config = 0;
	head->next = NULL;
	head->sol = NULL;
}

t_sol	*next_solve_step(t_head *head, int step)
{
	t_sol				*solution;
	t_sol				*tmp;

	if (head->sol == NULL)
	{
		if (!(solution = (t_sol*)P_MALLOC(sizeof(t_sol))))
			return (NULL);
		head->sol = solution;
		solution->sol = NULL;
		solution->y_all_pxnx = ft_strdup(head->y_all_pxnx);
		return (solution);
	}
	else
	{
		tmp = find_sol(head, step);
		if (!(solution = (t_sol*)P_MALLOC(sizeof(t_sol))))
			return (NULL);
		tmp->sol = solution;
		if (!(tmp->sol->y_all_pxnx = ft_memalloc((size_t)head->tt_pos_all)))
			return (NULL);
		ft_memcpy(tmp->sol->y_all_pxnx, tmp->y_all_pxnx,
			(size_t)head->tt_pos_all);
		tmp->sol->sol = NULL;
		return (solution);
	}
}

t_head	*setup_head_sol_part(t_head *head)
{
	int i;

	if (!(head->solution = malloc_binary(head)))
		return (NULL);
	if (!(head->y_all_pxnx = (char*)P_MALLOC(sizeof(char) *
	((size_t)head->tt_pos_all + 1))))
		return (free_tab_str(&head->solution, head->tt_pos_all));
	i = -1;
	while (++i < head->tt_pos_all)
		head->y_all_pxnx[i] = 1;
	head->y_all_pxnx[head->tt_pos_all] = 0;
	head->config = 1;
	write_binary(head);
	i = -1;
	while (++i < head->p)
		if (!(next_solve_step(head, i)))
			return (free_head(&head));
	return (head);
}

void	*setup_pieces(t_head *head)
{
	int			i;

	i = 0;
	while (++i <= head->p)
	{
		pieces_yx(find_piece(head, i));
		find_piece(head, i)->pc_pos =
		size_pieces(find_piece(head, i)->name[0], head->sqsize);
		if (i == 1)
			find_piece(head, i)->tt_pos = find_piece(head, i)->pc_pos;
		else
			find_piece(head, i)->tt_pos =
			find_piece(head, i)->pc_pos + find_piece(head, i - 1)->tt_pos;
		if (!coord_setup(find_piece(head, i)))
			return (free_linked_pieces(&head->next));
		if (i == 1)
			head->tt_pos_all = head->next->pc_pos;
		else
			head->tt_pos_all = find_piece(head, i)->tt_pos;
		find_piece(head, i)->i = i;
	}
	return (head);
}

t_head	*setup_(t_head *head)
{
	head->sqsize = (ft_round_upper(ft_fsqrt(head->p, 0) * 2));
	if (head->p == 1 && head->next->name[0] == 'I')
		head->sqsize += 2;
	if (head->p == 2 &&
		(head->next->name[0] == 'I' || head->next->next->name[0] == 'I'))
		head->sqsize++;
	if (!(setup_pieces(head)))
		return (NULL);
	if (!(setup_head_sol_part(head)))
		return (NULL);
	return (head);
}
