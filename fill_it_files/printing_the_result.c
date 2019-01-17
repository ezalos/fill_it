/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_the_result.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:18:38 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/17 12:36:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	print_pieces(t_head *head, char **tab_result)
{
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

void	show_pieces_binary(t_head *head, char **tab_result)
{
	int	line;
	int	j_piece;
	int block;
	int i;

	line = 0;
	j_piece = 0;
	while (line < head->tt_pos_all && j_piece < head->p)
	{
		while (find_sol(head, head->p)->y_all_pxnx[line] != 1)
			line++;
		i = 0;
		while (++i <= 4)
		{
			block = pos_one_binary(head->solution[line], head->p +
				(head->sqsize * head->sqsize), i) - head->p;
			tab_result[j_to_yx(head, block, 0)][j_to_yx(head, block, 1)] =
			j_piece + 'A';
		}
		line++;
		j_piece++;
	}
	if (!OPTION)
		print_pieces(head, tab_result);
	else
	{
		print_pieces_color(head, tab_result);
	}
}

int		print_result(t_head *head)
{
	char	**tab_result;
	int		i;

	if (!(tab_result = (char**)malloc((head->sqsize) * sizeof(char*))))
		return (0);
	i = -1;
	while (++i < head->sqsize)
	{
		if (!(tab_result[i] = ft_memalloc((head->sqsize + 1))))
		{
			free_tab_str(&tab_result, i);
			return (0);
		}
		ft_memset(tab_result[i], 46, (size_t)head->sqsize);
		tab_result[i][head->sqsize] = '\0';
	}
	show_pieces_binary(head, tab_result);
	free_tab_str(&tab_result, head->sqsize);
	return (1);
}
