/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_r_in_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:35:37 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/18 05:15:11 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../fill_it_files/head.h"

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

void	ft_put(const char *s, int separation)
{
	int n;
	int tab;
	int length;

	n = 4;
	tab = 0;
	length = ft_strlen(s);
	while (tab + length < separation * n)
	{
		write(1, " ", 1);
		tab++;
	}
}

void	print_pieces_color(t_head *head, char **tab_result)
{
	int i;
	int j;

	print_time(time_exe(__func__, clock()));
	i = -1;
	ft_putchar('\n');
	ft_putchar('\n');
	while (++i < head->sqsize)
	{
		j = -1;
		ft_put(tab_result[i], 9);
		while (++j < head->sqsize)
			ft_putchar_color(tab_result[i][j]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
	ft_putchar('\n');
}
