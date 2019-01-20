/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sols.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:38:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/20 20:30:16 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**********************************
**                              **
** functions used to free   	**
**  unvalid solutions   		**
**                              **
**********************************
*/

#include "./head.h"

void	*free_linked_sol(t_sol **sol)
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

void	*free_linked_sols(t_sol **sol)
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

void	*free_solsol(t_head *head)
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

void	*free_solsols(t_head *head)
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
