/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_delete_row.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:29:54 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 20:30:06 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_tab_delete_row(t_tab *tab, size_t dir)
{
	t_tab	*tmp;
	t_tab	*next;
	size_t	i;

	tmp = tab;
	i = 0;
	ft_tab_connect_dir(dir, tab->dir[ft_tab_dir_clock(dir)], tab->dir[ft_tab_dir_rclock(dir)], ft_tab_dir_clock(dir));
	while (tmp)
	{
		tmp->dir[ft_tab_dir_reverse(dir)] = NULL;
		next = tmp->dir[dir];
		ft_memdel((void**)&tmp);
		tmp = next;
		i++;
	}
	return (i);
}
