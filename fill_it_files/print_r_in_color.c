/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_r_in_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:35:37 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/17 12:35:42 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_putchar_color(char c)
{
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
	write(1, " ", 1);
	write(1, "\x1b[0m", 5);
}

void	print_pieces_color(t_head *head, char **tab_result)
{
	int i;
	int j;

	i = -1;
	ft_putchar('\n');
	ft_putchar('\n');
	while (++i < head->sqsize)
	{
		j = -1;
		ft_putstr("\t\t\t");
		while (++j < head->sqsize)
			ft_putchar_color(tab_result[i][j]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
	ft_putchar('\n');
}
