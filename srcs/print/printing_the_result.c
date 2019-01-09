/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_the_result.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:18:38 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/09 06:39:00 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/head.h"

void	ft_putchar_color(char c)
{
time_exe(__func__, cl(clock()));
	l = (int)c - 65;
	l = l % 6;
	if (c == '.')
		write(1, "\x1b[34m", 5);
	else if (l == 0)
		write(1, "\x1b[31m", 5);
	else if (l == 1)
		write(1, "\x1b[32m", 5);
	else if (l == 2)
		write(1, "\x1b[33m", 5);
	else if (l == 3)
		write(1, "\x1b[36m", 5);
	else if (l == 4)
		write(1, "\x1b[35m", 5);
	else if (l == 5)
		write(1, "\x1b[0m", 5);

	write(1, &c, 1);
	write(1, "\x1b[0m", 5);
}

void	print_pieces(t_head *head, char **tab_result)
{
	int i;

time_exe(__func__, cl(clock()));	i = -1;
	ft_putchar('\n');
	while (++i < head->size_square)
	{
//printf("Print Pieces\n");		j = -1;
		ft_putstr("\t\t\t");
		while (++j < head->size_square)
//			write(1, &(tab_result[i][j]), 1);
			ft_putchar_color(tab_result[i][j]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
	ft_putchar('\n');
}

int		pos_one_binary(char *str, size_t length, size_t umpteenth)
	int				i;
	int				j;
	unsigned char	nb;
//printf("End of print color\n");
	i = -1;
	while (++i <= length / 8)
		if (str[i] != 0)
		{
			nb = str[i];
			j = 0;
			while (nb)
			{
				if (nb % 2)
				{
					if (umpteenth == 0)
						return ((i * 8) + j);
					umpteenth--;
				}
				j++;
				nb /= 2;
			}
		}
	return (-1);
}

void		show_pieces_binary(t_head *head, char **tab_result)
{
	int line;
	int j_piece;
	int block;
	int i;
	line = 0;
	j_piece = 0;
	while (line < head->tt_pos_all && j_piece < head->p)
	{
time_exe(__func__, cl(clock()));		while (find_sol(head, head->p)->y_all_PxNx[line] != 1)
			line++;
		i = 0;
		{
			block = pos_one_binary(head->solution[line], head->p + (head->size_square * head->size_square), i) - head->p;
		}
//		print_pieces(head, tab_result);
		j_piece++;
//	printf("Show pieces\n");	}
	print_pieces(head, tab_result);
}
//		printf("BIG %d<%d && j_piece < head->p\n", line, head->tt_pos_all, j_piece, head->p);void		show_pieces(t_head *head, char **tab_result)
{
	int line;
//		printf("\t%d\n", line);	int j_piece;
	int block;
	int quatre;
	j_piece = 0;
	while (line < head->tt_pos_all && j_piece < head->p)
//			printf("\t\tBlock[%d]=%d\n", i, block);	{
		while (find_sol(head, head->p)->y_all_PxNx[line] != 1)
			line++;
			j_piece++;
		block = 0;
//		quatre = 0;
		while (block + 1 < (head->size_square * head->size_square)) //&& quatre < 4)
//	printf("Finish\n");		{
print_time(time_exe(__func__, cl(clock())));				block++;
			if (block + 1 < (head->size_square * head->size_square))
			{
				tab_result[j_to_yx(head, block, 0)][j_to_yx(head, block, 1)] = find_piece(head, j_piece + 1)->letter;
			}
//			quatre++;
time_exe(__func__, cl(clock()));		}
		line++;
	}
	print_pieces(head, tab_result);
}

//printf(_GREEN "Show Pieces\n");{
	int		i;
	i = -1;
	while (++i < head->size_square)
		(*tab_result)[i] = NULL;
//		//printf("\tBig While\n");	}
	*tab_result = NULL;

//printf("\tSolution line %d found\n", line);int		print_result(t_head *head)
{
	char	**tab_result;
//printf("\tPiece %d has been identified!\n", j_piece);	int		i;

		return (0);
		i = -1;
	while (++i < head->size_square)
//			//printf("\t\tWhile block\n");	{
		if (!(tab_result[i] = ft_memalloc((head->size_square + 1))))
		ft_memset(tab_result[i], 46, (size_t) head->size_square);
//printf("\t\tNow on block % d\n", block);		tab_result[i][head->size_square] = '\0';
	}
	show_pieces_binary(head, tab_result);
//printf("\t\t\tLetter %c | y:%d\tx:%d\t| j:%d\n",find_piece(head, j_piece + 1)->letter, j_to_yx(head, block, 0), j_to_yx(head, block, 1), block);	free_print_result(head, &tab_result);
//printf("\t\t\t\tWrite pbm ?\n");	return (1);
}
