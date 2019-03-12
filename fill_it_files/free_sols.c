/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sols.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:38:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 20:56:50 by ldevelle         ###   ########.fr       */
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
		ft_memdel((void**)&(*sol)->y_all_pxnx);
		(*sol)->y_all_pxnx = NULL;
		ft_memdel((void**)&(*sol));
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
			ft_memdel((void**)&head->solution[y]);
			head->solution[y] = NULL;
		}
		ft_memdel((void**)&head->solution);
		head->solution = NULL;
	}
	if (head->y_all_pxnx)
	{
		ft_memdel((void**)&head->y_all_pxnx);
		head->y_all_pxnx = NULL;
	}
	free_linked_sols(&(head->sol));
	head->sol = NULL;
	return (NULL);
}
