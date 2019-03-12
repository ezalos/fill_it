/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_print_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:00:14 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/25 22:00:22 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_print_dir(t_tab *tab, size_t dir, int lin)
{
	t_tab	*tmp;
	int		structh;
	int		col;

	if (!tab || dir > 3)
		return (-1);
	tmp = tab;
	structh = 0;
	col = 3;
	while (tmp)
	{
		ft_putstr("\n");
		ft_rgb_bcolor(255, 255, 255);
		ft_rgb_color(0, 0, 0);
		ft_putnbr(lin / 4);
		ft_putstr("->");
		C_RESET
		ft_tab_print_one_elmnt(tmp, lin, col, structh);
		tmp = tmp->dir[dir];
		structh++;
		col += (14 * 3) + 2;
	}
	return (1);
}
