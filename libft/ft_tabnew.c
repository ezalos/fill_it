/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:15:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/05 17:44:32 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**	dir[0] : up;
**	dir[1] : right;
**	dir[2] : down;
**	dir[3] : left;
*/

#include "libft.h"

t_tab	*ft_tab_cutone(t_tab *to_cut)
{
	size_t dir;

	dir = 0;
	if (!to_cut)
		return (NULL);
	if (to_cut->dir[ft_tab_dir_reverse(dir)] && to_cut->dir[dir])
		ft_tab_connect_structs(to_cut->dir[ft_tab_dir_reverse(dir)], to_cut->dir[dir], dir);
	dir = ft_tab_dir_clock(dir);
	if (to_cut->dir[ft_tab_dir_reverse(dir)] && to_cut->dir[dir])
		ft_tab_connect_structs(to_cut->dir[ft_tab_dir_reverse(dir)], to_cut->dir[dir], dir);
	ft_bzero(to_cut->dir, sizeof(to_cut->dir));
	return (to_cut);
}

int		main(int ac, char **av)
{
	t_tab	*tab;

	if (ac == 1)
	{
//		if (!ft_tab_parser(&tab, 0))
			return (-1);
	}
	else if (ac > 3)
		return (0);
//	tab = ft_tabnew_dir(ft_atoi(av[1]), 2);
//	ft_tab_square_it(tab, 2);

	tab = ft_tabnew_rectangle(ft_atoi(av[1]), ft_atoi(av[2]), 2);
	ft_rgb_bcolor(20, 20, 20);
	ft_tabiter(tab, 2, &ft_tab_print_dir, 1);
	return (0);
}
