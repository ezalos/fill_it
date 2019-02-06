/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sols.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:38:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/22 03:16:57 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Allow to free	: the linked list created during the solve process
**					  part of the memory allocated in the head, used to solve
*/

#include "head.h"

void	*free_linked_sols(t_sol **sol)
{
	if (sol && *sol)
	{
		free_linked_sols(&((*sol)->sol));
		(*sol)->sol = NULL;
		free((*sol)->y_all_pxnx);
		(*sol)->y_all_pxnx = NULL;
		free((*sol));
		*sol = NULL;
	}
	return (NULL);
}

void	*free_solsols(t_head *head)
{
	int y;

	y = -1;
	if (head->solution)
	{
		while (++y < head->tt_pos_all)
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
