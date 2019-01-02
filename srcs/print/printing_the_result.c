/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_the_result.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:18:38 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/02 19:08:10 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/head.h"

void	ft_putchar_color(char c)
{
	time_exe(__func__, cl(clock()));
	int l;

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
	time_exe(__func__, cl(clock()));
	int i;
	int j;

	//printf("Print Pieces\n");
	i = -1;
	ft_putchar('\n');
	ft_putchar('\n');
	while (++i < head->size_square)
	{
		j = -1;
		ft_putstr("\t\t\t");
		while (++j < head->size_square)
			ft_putchar_color(tab_result[i][j]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
	ft_putchar('\n');
	//printf("End of print color\n");
}

int		pos_one_binary(char *str, size_t length, size_t umpteenth)
{
	int				i;
	int				j;
	unsigned char	nb;

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
	time_exe(__func__, cl(clock()));
	int line;
	int j_piece;
	int block;
	int i;

	line = 0;
	j_piece = 0;
//	printf("Show pieces\n");
	while (line < head->tt_pos_all && j_piece < head->p)
	{
//		printf("BIG %d<%d && j_piece < head->p\n", line, head->tt_pos_all, j_piece, head->p);
		while (find_sol(head, head->p)->y_all_PxNx[line] != 1)
			line++;
//		printf("\t%d\n", line);
		i = 0;
		while (++i <= 4)
		{
			block = pos_one_binary(head->solution[line], head->p + (head->size_square * head->size_square), i) - head->p;
//			printf("\t\tBlock[%d]=%d\n", i, block);
			tab_result[j_to_yx(head, block, 0)][j_to_yx(head, block, 1)] = j_piece + 'A';
		}
//		print_pieces(head, tab_result);
		line++;
		j_piece++;
	}
//	printf("Finish\n");
	print_time(time_exe(__func__, cl(clock())));
	print_pieces(head, tab_result);
}

void		show_pieces(t_head *head, char **tab_result)
{
	time_exe(__func__, cl(clock()));
	int line;
	int j_piece;
	int block;
	int quatre;

	//printf(_GREEN "Show Pieces\n");
	line = 0;
	j_piece = 0;
	while (line < head->tt_pos_all && j_piece < head->p)
	{
//		//printf("\tBig While\n");
		while (find_sol(head, head->p)->y_all_PxNx[line] != 1)
			line++;
		//printf("\tSolution line %d found\n", line);
		while (head->solution[line][j_piece] != 1)
			j_piece++;
		//printf("\tPiece %d has been identified!\n", j_piece);
		block = 0;
//		quatre = 0;
		while (block + 1 < (head->size_square * head->size_square)) //&& quatre < 4)
		{
//			//printf("\t\tWhile block\n");
			while (block + 1 < (head->size_square * head->size_square) && head->solution[line][head->p + block] != 1)
				block++;
			//printf("\t\tNow on block % d\n", block);
			if (block + 1 < (head->size_square * head->size_square))
			{
				//printf("\t\t\tLetter %c | y:%d\tx:%d\t| j:%d\n",find_piece(head, j_piece + 1)->letter, j_to_yx(head, block, 0), j_to_yx(head, block, 1), block);
				//printf("\t\t\t\tWrite pbm ?\n");
				tab_result[j_to_yx(head, block, 0)][j_to_yx(head, block, 1)] = find_piece(head, j_piece + 1)->letter;
				//write(1, "@", 1);
				//printf("\t\t\t\tNop.\n");
			}
//			//printf("\t\tLETTER WRITEN\n");
//			quatre++;
			block++;
		}
		line++;
		j_piece++;
	}
	//printf("End of putting pieces in print\n");
	print_pieces(head, tab_result);
}

void	free_print_result(t_head *head, char ***tab_result)
{
	time_exe(__func__, cl(clock()));
	int		i;

	i = -1;
	while (++i < head->size_square)
	{
		free((*tab_result)[i]);
		(*tab_result)[i] = NULL;
	}
	free(*tab_result);
	*tab_result = NULL;
}

int		print_result(t_head *head)
{
	time_exe(__func__, cl(clock()));
	char	**tab_result;
	int		i;

//	//printf("Print Result\n");
	if (!(tab_result = (char**)malloc((head->size_square) * sizeof(char*))))
		return (0);
		i = -1;
	while (++i < head->size_square)
	{
		if (!(tab_result[i] = ft_memalloc((head->size_square + 1))))
			return (0);
		ft_memset(tab_result[i], 46, (size_t) head->size_square);
		tab_result[i][head->size_square] = '\0';
	}
	//printf("tab_result[%d][%d + 1] created !\n", head->size_square, head->size_square);
	show_pieces_binary(head, tab_result);
	free_print_result(head, &tab_result);
	return (1);
}
