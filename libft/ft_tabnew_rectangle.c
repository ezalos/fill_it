/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew_rectangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:31:05 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 20:31:29 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*ft_tabnew_rectangle(size_t x_axis, size_t y_axis, size_t x_dir)
{
	t_tab	*tab;
	t_tab	*tmp;
	t_tab	*tmp_old;
	size_t	i;

	if (!x_axis || x_dir > 3)
		return (NULL);
	if (!(tab = ft_tabnew_dir(y_axis, x_dir)))
		return (NULL);
	tmp = tab;
	tmp_old = NULL;
	i = 0;
	while (i < y_axis && x_axis > 1)
	{
		if(!(tmp->dir[ft_tab_dir_rclock(x_dir)] = ft_tabnew_dir(x_axis - 1, ft_tab_dir_rclock(x_dir))))
			return (NULL);
		tmp->dir[ft_tab_dir_rclock(x_dir)]->dir[ft_tab_dir_clock(x_dir)] = tmp;
		if (tmp_old && tmp)
			ft_tab_connect_dir(ft_tab_dir_rclock(x_dir), tmp_old, tmp, x_dir);
		tmp_old = tmp;
		tmp = tmp->dir[x_dir];
		i++;
	}
	return (tab);
}
