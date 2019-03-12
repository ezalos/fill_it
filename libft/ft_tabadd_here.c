/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd_here.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:32:58 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/07 12:27:24 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabadd_here(t_tab *alst, t_tab *new, size_t dir)
{
	t_tab		*tmp;

	if (alst && new)
	{
		tmp = alst->dir[dir];
		alst->dir[dir] = new;
		ft_tab_reach_end(new, dir)->dir[dir] = tmp;
		tmp->dir[ft_tab_dir_reverse(dir)] = new;
	}
}
