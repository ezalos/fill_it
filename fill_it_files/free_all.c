/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:04:26 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/16 15:00:04 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void update_pieces(t_head *head)
{
	int i;

//	printf("update_pieces\n");
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

void free_linked_sol(t_sol **sol)
{
//	printf("free_linkedsol\n");
	if (sol && *sol)
	{
		free_linked_sol(&((*sol)->sol));
		(*sol)->sol = NULL;
		free((*sol)->y_all_pxnx);
		(*sol)->y_all_pxnx = NULL;
	}
}

void free_solsol(t_head *head)
{
	int y;

//	printf("free_solsol\n");
	y = -1;
	while (++y < head->sqsize)
	{
		free(head->solution[y]);
		head->solution[y] = NULL;
	}
	free(head->solution);
	head->solution = NULL;
	free(head->y_all_pxnx);
	head->y_all_pxnx = NULL;
	free_linked_sol(&(head->sol));
	head->sol = NULL;
}

void	free_head(t_head **head)
{
	
}

int		free_error_int(t_head **head, char **buf)
{
	ft_putendl("error\n");
	if (head && *head)
		free_head(head);
	if (buf && *buf)
		ft_strdel(buf);
	return (-1);
}

void	*free_error_ptr(t_head **head, char **buf)
{
	ft_putendl("error\n");
	return (NULL);
}

t_head	*restart_and_grow(t_head *head)
{
//	printf("restart_and_grow\n");
	free_solsol(head);
//	printf("FREE DONE !\n");
	head->sqsize++;
	update_pieces(head);
	if (!(setup_head_sol_part(head)))
		return (NULL);
	return(head);
}
