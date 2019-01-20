/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:04:26 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/20 20:26:55 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*************************************************
**												**
**  set of functions used to free,   			**
**  in case we previously allocated				**
**	memory for pieces until we found a			**
**	wrong input or if we need to expand			**
**	our solution table             				**
**                                 				**
**************************************************
*/

#include "./head.h"

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
	return (head);
}
