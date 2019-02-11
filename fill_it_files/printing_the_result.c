/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_the_result.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:18:38 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/23 01:37:31 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Functions to print the result.
**	__________________________________________________________________________
**		print_pieces	: prints every line of the final square
**		pos_one_binary	: allows to know the position of the umpteenth 1
**						  in a binary stored in a string
**		show_pieces_bin	: translates the solution stored in binary string
**						  using J coord into the final square for impression
**		print_result	: calls all the necessary functions to print the result
*/

#include "./head.h"

void	print_pieces(t_head *head, char **tab_result)
{
	time_exe(__func__, clock());
	int i;
	int j;

	i = -1;
	while (++i < head->sqsize)
	{
		j = -1;
		while (++j < head->sqsize)
			ft_putchar(tab_result[i][j]);
		ft_putchar('\n');
	}
}

int		pos_one_binary(char *str, size_t length, size_t umpteenth)
{
	time_exe(__func__, clock());
	int				i;
	int				j;
	unsigned char	nb;

	i = -1;
	while (++i <= (int)(length / 8))
		if (str[i] != 0)
		{
			nb = (unsigned char)str[i];
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

void	show_pieces_binary(t_head *head, char **tab_result)
{
	time_exe(__func__, clock());
	int		line;
	int		j_piece;
	int		block;
	size_t	i;

	line = -1;
	j_piece = 0;
	while (++line < head->tt_pos_all && j_piece < head->p)
	{
		while (find_sol(head, head->p)->y_all_pxnx[line] != 1)
			line++;
		i = 0;
		while (++i <= 4)
		{
			block = pos_one_binary(head->solution[line], (size_t)head->p +
				((size_t)head->sqsize * (size_t)head->sqsize), i) - head->p;
			tab_result[j_to_yx(head, block, 0)][j_to_yx(head, block, 1)] =
			(char)j_piece + 'A';
		}
		j_piece++;
	}
	print_pieces_color(head, tab_result);
}

int		print_result(t_head *head)
{
	time_exe(__func__, clock());
	char	**tab_result;
	int		i;

	if (!(tab_result = (char**)malloc(((size_t)head->sqsize) * sizeof(char*))))
		return (0);
	i = -1;
	while (++i < head->sqsize)
	{
		if (!(tab_result[i] = ft_memalloc(((size_t)head->sqsize + 1))))
		{
			free_tab_str(&tab_result, i);
			return (0);
		}
		ft_memset(tab_result[i], 46, (size_t)head->sqsize);
		tab_result[i][head->sqsize] = '\0';
	}
	show_pieces_binary(head, tab_result);
	free_tab_str(&tab_result, head->sqsize);
	free_head(&head);
	return (1);
}
