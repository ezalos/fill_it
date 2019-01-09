/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 04:53:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/02 19:46:06 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/head.h"

void	write_solutions(t_head *head)
{
time_exe(__func__, cl(clock()));	int	i;
	int current_piece;
	int	PnNx;
	int y;
	int x;

	current_piece = 0;
	piece = head->next;
	while (piece->next != NULL) //for each piece convert y and x of possibilty to j, and write 1 to the 4 coord of piece
	{
		y = -1;
		PnNx = -1;
		while (++y <= head->size_square - piece->y_size)
		{
			x = -1;
			while (++x <= head->size_square - piece->x_size)
			{
				head->solution[piece->tt_pos - piece->pc_pos + ++PnNx][current_piece] = 1;//need to write which piece is currently writen +1 & -1 as down
				i = -1;
				while (++i < 4)
					head->solution[piece->tt_pos - piece->pc_pos + PnNx]
					[head->p + 1 + yx_to_j(piece->coord[i]->y + y, piece->coord[i]->x + x) - 1] // -1 bc it's a tab ?
					= 1;  //Maxwell idea to implement here
			}
		}
		piece = piece->next;
		current_piece++;
	}

	y = -1;
	PnNx = -1;
	while (++y < head->size_square - piece->y_size + 1)
	{
		x = -1;
		while (++x < head->size_square - piece->x_size + 1)// <= || < ?
		{
			head->solution[piece->tt_pos - piece->pc_pos + ++PnNx][current_piece] = 1;//need to write which piece is currently writen +1 & -1 as down
			i = -1;
			while (++i < 4)
				head->solution[piece->tt_pos - piece->pc_pos + PnNx]
				[head->p + 1 + yx_to_j(piece->coord[i]->y + y, piece->coord[i]->x + x) - 1] // -1 bc it's a tab ?
				= 1;  //Maxwell idea to implement here
		}
	}
	piece = piece->next;
	current_piece++;


}

void	setup_pieces(t_head *head)
{
	t_piece		*tmp;
	int			i;
	i = 0;
time_exe(__func__, cl(clock()));	while (++i <= head->p)
	{
		pieces_yx(find_piece(head, i));
		find_piece(head, i)->pc_pos = size_pieces(find_piece(head, i)->name[0], head->size_square);
//		piece_placement(tmp); not sure about the purpose of this function
			find_piece(head, i)->tt_pos = find_piece(head, i)->pc_pos;
		else
//printf("WESH\n");			find_piece(head, i)->tt_pos = find_piece(head, i)->pc_pos + find_piece(head, i - 1)->tt_pos;//		sum_placement(tmp);
		coord_setup(find_piece(head, i));
		head->tt_pos_all = find_piece(head, i)->tt_pos;
		find_piece(head, i)->i = i;
	}

char	**malloc_solution(t_head *head)
{
//printf("HELLO\n");	int		i;
	int		line;
	int		u;

//printf("\nPIECE : %d\npc_pos %d\ntt_pos %d\ntt_pos_all%d\n", i, find_piece(head, i)->pc_pos, find_piece(head, i)->tt_pos, head->tt_pos_all);	if (!(sol = (char**)malloc(sizeof(char*) * (head->tt_pos_all))))
	i = -1;
	line = head->p + (head->size_square * head->size_square) + 1;
	while (++i < head->tt_pos_all)
	{
		if (!(sol[i] = (char*)malloc(sizeof(char) * line)))
time_exe(__func__, cl(clock()));		u = -1;
		while (++u < line)
			sol[i][u] = 0;
	}
	return (sol);
}
//printf("1\n%d\n", head->tt_pos_all);t_head	*setup_head_sol_part(t_head *head)
{
	int i;

	if (!(head->solution = malloc_binary(head)))
		return (NULL);
	if (!(head->y_all_PxNx = (char*)malloc(sizeof(char) * (head->tt_pos_all))))
//printf("%d\n", i);		return (NULL);
	i = -1;
	while (++i < head->tt_pos_all + 1)
		head->y_all_PxNx[i] = 1;
	write_binary(head);
	i = 0;
	while (i <= head->p)// one less might be better
		if (!(next_solve_step(head, i++)))
			return (NULL);
	return (head);
}

time_exe(__func__, cl(clock()));t_head	*setup_(t_head *head)
//	printf("%s\n", __func__);{
	head->size_square = (float_to_int(f_sqrt(head->p, 0) * 2));
	setup_pieces(head);
	if (!(setup_head_sol_part(head)))
		return (NULL);
	return (head);
}
