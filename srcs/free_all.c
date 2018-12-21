/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:04:26 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/19 11:10:17 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void update_pieces(t_head *head)
{
	int i;

	printf("update_pieces\n");
	i = 0;
	while (++i <= head->p)
	{
		find_piece(head, i)->pc_pos = size_pieces(find_piece(head, i)->name[0], head->size_square);
		if (i == 1)
			find_piece(head, i)->tt_pos = find_piece(head, i)->pc_pos;
		else
			find_piece(head, i)->tt_pos = find_piece(head, i)->pc_pos + find_piece(head, i - 1)->tt_pos;
		coord_setup(find_piece(head, i));
		head->tt_pos_all = find_piece(head, i)->tt_pos;
	}
}

void free_linked_sol(t_sol **sol)
{
	printf("free_linkedsol\n");
	if (*sol)
	{
		free_linked_sol(&((*sol)->sol));
		free((*sol)->y_all_PxNx);
		(*sol)->sol = NULL;
	}
}

void free_solsol(t_head *head)
{
	int y;

	printf("free_solsol\n");
	y = -1;
	while (++y < head->size_square)
		free(head->solution[y]);
	free(head->solution);
	free(head->y_all_PxNx);
	free_linked_sol(&(head->sol));
}



t_head	*restart_and_grow(t_head *head)
{
	printf("restart_and_grow\n");
	free_solsol(head);
	printf("FREE DONE !\n");
	head->size_square++;
	update_pieces(head);
	if (!(setup_head_sol_part(head)))
		return (NULL);
	return(head);
}