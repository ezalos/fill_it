/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_access.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:30:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 20:30:55 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_tab_access_setup(size_t *down, size_t *right, int *dir_y, int *dir_x)
{
	if (*dir_x < 0)
	{
		*dir_x = -*dir_x;
		*right = ft_tab_dir_reverse(*right);
	}
	if (*dir_y < 0)
	{
		*dir_y = -*dir_y;
		*down = ft_tab_dir_reverse(*down);
	}
}

t_tab	*ft_tab_access(t_tab *tab, int dir_y, int dir_x, int rot)
{
	t_tab	*tmp;
	size_t	down;
	size_t	right;

	down = 2;
	right = 1;
	ft_tab_access_setup(&down, &right, &dir_y, &dir_x);
	if (rot)
	{
		down = ft_tab_dir_nclock(down, rot);
		right = ft_tab_dir_nclock(right, rot);
	}
	tmp = tab;
	if (tmp)
	{
		tmp = ft_tab_dirth(tmp, down, dir_y);
		tmp = ft_tab_dirth(tmp, right, dir_x);
	}
	return (tmp);
}
