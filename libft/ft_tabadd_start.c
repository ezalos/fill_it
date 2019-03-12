/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:32:24 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/06 13:33:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabadd_start(t_tab **alst, t_tab *new, size_t dir)
{
	if (alst && new)
	{
		if (*alst)
		{
			ft_tab_reach_end(new, dir)->dir[dir] = *alst;
			(*alst)->dir[ft_tab_dir_reverse(dir)] = new;
			*alst = new;
		}
		else
			*alst = new;
	}
}
