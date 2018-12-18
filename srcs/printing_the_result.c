/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_the_result.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:18:38 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/18 18:23:24 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	print_pieces(t_head *head, char **tab_result)
{
	int i;

//	printf("Print Pieces\n");
	i = -1;
	ft_putchar('\n');
	ft_putchar('\n');
	while (++i < head->size_square)
	{
		ft_putstr(tab_result[i]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
	ft_putchar('\n');
}

void		show_pieces(t_head *head, char **tab_result)
{
	int line;
	int piece;
	int block;
	int quatre;
	int lettre;

//	printf("Show Pieces\n");
	line = 0;
	lettre = 1;
	while (line < head->tt_pos_all && lettre <= head->p)
	{
//		printf("\tBig While\n");
		while (find_sol(head, head->p)->y_all_PxNx[line] != 1)
			line++;
//		printf("\tSolution line found\n");
		piece = 0;
		while (head->solution[line][piece] != 1)
			piece++;
//		printf("\tPiece has been identified!\n");
		block = 0;
		quatre = 0;
		while (block < (head->p * head->p) && quatre < 4)
		{
//			printf("\t\tWhile block\n");
			while (head->solution[line][head->p + block] != 1)
				block++;
//			printf("\t\tNow on a block\n");
			tab_result[j_to_yx(head, block, 0)][j_to_yx(head, block, 1)] = find_piece(head, piece + 1)->letter;
//			printf("\t\tLETTER WRITEN\n");
			quatre++;
			block++;
		}
		line++;
		lettre++;
	}
	print_pieces(head, tab_result);
}

int		print_result(t_head *head)
{
	char	**tab_result;
	int		i;

//	printf("Print Result\n");
	if (!(tab_result = (char**)malloc((head->size_square) * sizeof(char*))))
		return (0);
		i = -1;
	while (++i < head->p)
	{
		if (!(tab_result[i] = ft_memalloc((head->size_square + 1))))
			return (0);
		ft_memset(tab_result[i], 46, (size_t) head->size_square);
		tab_result[i][head->size_square] = '\0';
	}
	show_pieces(head, tab_result);
	return (1);
}
