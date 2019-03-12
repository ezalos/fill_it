/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_delete_row_len.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:30:18 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 20:30:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_tab_delete_row_len(t_tab *tab, size_t dir, size_t len)
{
	t_tab	*tmp;
	t_tab	*next;
	size_t	i;

	tmp = tab;
	i = 0;
	if (!len)
		return (ft_tab_delete_row(tab, dir));
	while (tmp && i < len)
	{
		tmp->dir[ft_tab_dir_reverse(dir)] = NULL;
		ft_tab_connect_structs(tmp->dir[ft_tab_dir_clock(dir)], tmp->dir[ft_tab_dir_rclock(dir)], ft_tab_dir_rclock(dir));
		next = tmp->dir[dir];
		ft_memdel((void**)&tmp);
		tmp = next;
		i++;
	}
	return (i);
}
