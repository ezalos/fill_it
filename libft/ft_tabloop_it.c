/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabloop_it.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:01:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/05 19:39:16 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_tabloop_it(t_tab *tab, size_t dir)
{
	t_tab	*tmp;
	size_t	i;

	i = ft_tabloop_lendir(tab, dir);
	tmp = ft_tab_reach_end(tab, dir);
	ft_tab_connect_structs(tab, tmp, ft_tab_dir_reverse(dir));
	return (i);
}
