/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 04:53:29 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/01 04:16:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	setup_pieces(t_head *head)
{
	t_piece		*tmp;
	int			i;

	i = -1;
	while (++i <= head->p)
	{
		pieces_yx(find_piece(head, i));
		find_piece(head, i)->pc_pos = size_pieces(find_piece(head, i)->name[0], head->size_square);
//		piece_placement(tmp); not sure about the purpose of this function
		find_piece(head, i)->tt_pos = find_piece(head, i)->pc_pos + find_piece(head, i - 1)->tt_pos;//		sum_placement(tmp);
		coord_setup(find_piece(head, i));
		head->tt_pos_all = find_piece(head, i)->tt_pos;
		find_piece(head, i)->i = i;
		printf("\nPIECE : %d\npc_pos %d\ntt_pos %d\ntt_pos_all%d\n", i, find_piece(head, i)->pc_pos, find_piece(head, i)->tt_pos, head->tt_pos_all);
	}
}

char	**malloc_solution(t_head *head)
{
	char	**sol;
	int		i;
	int		line;
	int		u;

	printf("1\n%d\n", head->tt_pos_all);
	if (!(sol = (char**)malloc(sizeof(char*) * (head->tt_pos_all + 1))))//one +1 for stocking values : best dead space
		return (NULL); //need to protect if malloc has a pbm during allocation
	i = -1;
	line = head->p + (head->size_square * head->size_square) + 1;// ((+ 1));//one +1 for stocking values : if possible solution the other +1 for ending null string, might not be necessary
	printf("2\n");
	while (++i < head->tt_pos_all)
	{
		printf("%d\n", i);
		if (!(sol[i] = (char*)malloc(sizeof(char) * line)))
			return (NULL); //need to protect if malloc has a pbm during allocation
		u = -1;
		while (++u < line)
			sol[i][u] = 0;
	}
	return (sol);
}

t_head	*setup_head(t_head *head)
{
	int i;

	printf("Nb of pieces = %d\n", head->p);
	head->size_square = (float_to_int(f_sqrt(head->p, 0) * 2));
	printf("size_square = %d\n", head->size_square);
	setup_pieces(head);
	if (!(head->solution = malloc_solution(head)))
		return (NULL);
	if (!(head->y_all_PxNx = (char*)malloc(sizeof(char) * (head->tt_pos_all + 1))))//one +1 for stocking values : best dead space
		return (NULL);
	i = -1;
	while (++i < head->tt_pos_all + 1)
		head->y_all_PxNx[i] = 1;
//	head->sol->possible_solutions = 0;
	head->the_choosen_configuration = 1;
	return (head);
}
