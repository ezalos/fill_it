/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:04:26 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/16 16:41:08 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void update_pieces(t_head *head)
{
	int i;

	i = 0;
	while (++i <= head->p)
	{
		find_piece(head, i)->pc_pos = size_pieces(find_piece(head, i)->name[0], head->sqsize);
		if (i == 1)
			find_piece(head, i)->tt_pos = find_piece(head, i)->pc_pos;
		else
			find_piece(head, i)->tt_pos = find_piece(head, i)->pc_pos + find_piece(head, i - 1)->tt_pos;
		head->tt_pos_all = find_piece(head, i)->tt_pos;
	}
}

void *free_linked_sol(t_sol **sol)
{
	if (sol && *sol)
	{
		free_linked_sol(&((*sol)->sol));
		(*sol)->sol = NULL;
		free((*sol)->y_all_pxnx);
		(*sol)->y_all_pxnx = NULL;
	}
	return (NULL);
}

void *free_linked_sols(t_sol **sol)
{
	if (sol && *sol)
	{
		free_linked_sols(&((*sol)->sol));
		(*sol)->sol = NULL;
		free((*sol)->y_all_pxnx);
		(*sol)->y_all_pxnx = NULL;
		free((*sol)->sol);
		sol = NULL;
	}
	return (NULL);
}

void *free_linked_pieces(t_piece **next)
{
	int i;

	if (next && *next)
	{
		free_linked_pieces(&((*next)->next));
		(*next)->next = NULL;
		i = 0;
		while (i < 4)
		{
			free((*next)->coord[i++]);
			(*next)->coord[i] = NULL;
		}
		free((*next)->next);
		(*next)->next = NULL;
	}
	return (NULL);
}

void *free_solsol(t_head *head)
{
	int y;

	y = -1;
	if (head->solution)
	{
		while (++y < head->sqsize)
		{
			free(head->solution[y]);
			head->solution[y] = NULL;
		}
		free(head->solution);
		head->solution = NULL;
	}
	if (head->y_all_pxnx)
	{
		free(head->y_all_pxnx);
		head->y_all_pxnx = NULL;
	}
	free_linked_sol(&(head->sol));
	head->sol = NULL;
	return (NULL);
}

void *free_solsols(t_head *head)
{
	int y;

	y = -1;
	if (head->solution)
	{
		while (++y < head->sqsize)
		{
			free(head->solution[y]);
			head->solution[y] = NULL;
		}
		free(head->solution);
		head->solution = NULL;
	}
	if (head->y_all_pxnx)
	{
		free(head->y_all_pxnx);
		head->y_all_pxnx = NULL;
	}
	free_linked_sols(&(head->sol));
	head->sol = NULL;
	return (NULL);
}

void	*free_head(t_head **head)
{
	if (head && *head)
	{
		if ((*head)->next)
			free_linked_pieces(&(*head)->next);
		if ((*head)->sol)
			free_linked_sols(&(*head)->sol);
		free_solsols(*head);
		free(*head);
		*head = NULL;
	}
	return (NULL);
}

void	*free_tab_str(char ***ptr_on_tab, int lines)
{

	if (ptr_on_tab && *ptr_on_tab)
	{
		while (0 <= --lines)
			ft_strdel(&(*ptr_on_tab)[lines]);
		free(*ptr_on_tab);
		*ptr_on_tab = NULL;
	}
	return (NULL);
}

t_head	*restart_and_grow(t_head *head)
{
	free_solsol(head);
	head->sqsize++;
	update_pieces(head);
	if (!(setup_head_sol_part(head)))
		return (NULL);
	return(head);
}
